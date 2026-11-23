/* licence.c - controle de licence hors ligne pour le launcher Dreww.
 * Un jeton fait 41 octets fixes suivis d une signature ECDSA P-256 de
 * 64 octets, le tout encode en base64. Disposition: magie RRL1, version,
 * empreinte machine, emission, expiration, serie. Aucun appel reseau.
 * L empreinte est le SHA-256 du MachineGuid tronque a 16 octets.
 * Anti-recul niveau 2: l horodatage maximal vu est garde sous HKLM et une
 * horloge en retard de plus de 24 h sur lui refuse le lancement.
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <bcrypt.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "licence.h"

#pragma comment(lib, "bcrypt.lib")

#define LIC_PAYLOAD 41
#define LIC_SIG     64
#define LIC_VER     1
#define LIC_SKEW    86400LL
#define LIC_REG     L"SOFTWARE\\Dreww"

static const unsigned char kPub[72] = {
    0x45,0x43,0x53,0x31,0x20,0x00,0x00,0x00,
    0x22,0xB9,0x74,0x70,0x11,0x71,0xC5,0x00,
    0xC1,0x85,0x6C,0xA2,0xB2,0xF7,0x5A,0x8B,
    0x12,0x50,0x83,0x55,0x48,0xD5,0xDF,0xD6,
    0x66,0xD4,0x30,0x95,0x76,0x6E,0x9C,0x45,
    0xAB,0x56,0xD4,0x2C,0x1F,0xC1,0x8F,0xAC,
    0xD8,0x64,0x32,0xC1,0xBC,0xDF,0x24,0x7C,
    0x9F,0x0A,0xB4,0xE1,0x49,0xC4,0xF9,0xAC,
    0x60,0xE2,0x5E,0xA6,0xE9,0x0A,0x99,0xD0
};

static const wchar_t* kMsg[] = {
    L"OK",
    L"licence.dat introuvable",
    L"licence.dat illisible",
    L"jeton mal forme",
    L"jeton inconnu",
    L"licence liee a une autre machine",
    L"licence expiree",
    L"horloge reculee",
    L"signature invalide",
    L"crypto indisponible"
};
const wchar_t* lic_last_error(int code) {
    if (code < 0 || code > 9) return L"erreur inconnue";
    return kMsg[code];
}

static long long lic_now(void) {
    FILETIME ft;
    ULARGE_INTEGER u;
    GetSystemTimeAsFileTime(&ft);
    u.LowPart = ft.dwLowDateTime;
    u.HighPart = ft.dwHighDateTime;
    return (long long)((u.QuadPart / 10000000ULL) - 11644473600ULL);
}

static int lic_path(wchar_t* out, size_t cap) {
    wchar_t base[MAX_PATH];
    DWORD n = GetEnvironmentVariableW(L"LOCALAPPDATA", base, (DWORD)(sizeof(base) / sizeof(base[0])));
    if (!n || n >= MAX_PATH) return 0;
    _snwprintf_s(out, cap, _TRUNCATE, L"%s\\Dreww\\licence.dat", base);
    return 1;
}
static int b64val(int c) {
    if (c >= 65 && c <= 90) return c - 65;
    if (c >= 97 && c <= 122) return c - 97 + 26;
    if (c >= 48 && c <= 57) return c - 48 + 52;
    if (c == 43) return 62;
    if (c == 47) return 63;
    return -1;
}

static int b64_decode(const char* in, int len, unsigned char* out, int cap) {
    int o = 0, acc = 0, bits = 0;
    for (int i = 0; i < len; ++i) {
        int v = b64val((unsigned char)in[i]);
        if (v < 0) { if (in[i] == 61) break; else continue; }
        acc = (acc << 6) | v;
        bits += 6;
        if (bits >= 8) {
            bits -= 8;
            if (o >= cap) return -1;
            out[o++] = (unsigned char)(acc >> bits);
        }
    }
    return o;
}
static int lic_fingerprint(unsigned char out[16]) {
    HKEY k;
    wchar_t guid[128];
    char narrow[128];
    DWORD cb = sizeof(guid), type = 0;
    BCRYPT_ALG_HANDLE alg = NULL;
    UCHAR digest[32];
    NTSTATUS st;
    int i = 0;

    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Cryptography", 0,
                      KEY_READ | KEY_WOW64_64KEY, &k) != ERROR_SUCCESS) return 0;
    LONG r = RegQueryValueExW(k, L"MachineGuid", NULL, &type, (BYTE*)guid, &cb);
    RegCloseKey(k);
    if (r != ERROR_SUCCESS || type != REG_SZ) return 0;
    guid[127] = 0;
    for (; guid[i] && i < 127; ++i) narrow[i] = (char)guid[i];
    if (i == 0) return 0;

    if (BCryptOpenAlgorithmProvider(&alg, BCRYPT_SHA256_ALGORITHM, NULL, 0) < 0) return 0;
    st = BCryptHash(alg, NULL, 0, (PUCHAR)narrow, (ULONG)i, digest, sizeof(digest));
    BCryptCloseAlgorithmProvider(alg, 0);
    if (st < 0) return 0;
    memcpy(out, digest, 16);
    return 1;
}
static int lic_verify(const unsigned char* msg, int len, const unsigned char* sig) {
    BCRYPT_ALG_HANDLE hash = NULL, ecdsa = NULL;
    BCRYPT_KEY_HANDLE key = NULL;
    UCHAR digest[32];
    int ok = 0;

    if (BCryptOpenAlgorithmProvider(&hash, BCRYPT_SHA256_ALGORITHM, NULL, 0) < 0) return 0;
    if (BCryptOpenAlgorithmProvider(&ecdsa, BCRYPT_ECDSA_P256_ALGORITHM, NULL, 0) < 0) {
        BCryptCloseAlgorithmProvider(hash, 0);
        return 0;
    }
    if (BCryptHash(hash, NULL, 0, (PUCHAR)msg, (ULONG)len, digest, sizeof(digest)) >= 0 &&
        BCryptImportKeyPair(ecdsa, NULL, BCRYPT_ECCPUBLIC_BLOB, &key,
                            (PUCHAR)kPub, sizeof(kPub), 0) >= 0 &&
        BCryptVerifySignature(key, NULL, digest, sizeof(digest),
                              (PUCHAR)sig, LIC_SIG, 0) >= 0)
        ok = 1;
    if (key) BCryptDestroyKey(key);
    BCryptCloseAlgorithmProvider(ecdsa, 0);
    BCryptCloseAlgorithmProvider(hash, 0);
    return ok;
}
static int lic_rollback(long long now) {
    HKEY k;
    DWORD disp = 0, type = 0, cb = sizeof(long long);
    long long seen = 0;
    LONG r = RegCreateKeyExW(HKEY_LOCAL_MACHINE, LIC_REG, 0, NULL, 0,
                             KEY_READ | KEY_WRITE | KEY_WOW64_64KEY, NULL, &k, &disp);
    if (r != ERROR_SUCCESS) return 1;
    if (disp != REG_CREATED_NEW_KEY &&
        RegQueryValueExW(k, L"Seen", NULL, &type, (BYTE*)&seen, &cb) == ERROR_SUCCESS &&
        type != REG_QWORD)
        seen = 0;
    if (seen > now + LIC_SKEW) {
        RegCloseKey(k);
        return 0;
    }
    if (now > seen)
        RegSetValueExW(k, L"Seen", 0, REG_QWORD, (BYTE*)&now, (DWORD)sizeof(now));
    RegCloseKey(k);
    return 1;
}
int lic_check(void) {
    wchar_t path[MAX_PATH];
    char raw[512];
    unsigned char tok[128];
    unsigned char fp[16];
    DWORD got = 0;
    int len = 0, tn = 0;
    long long now, issued, exp;
    HANDLE h;

    if (!lic_path(path, MAX_PATH)) return 1;
    h = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return 1;
    if (!ReadFile(h, raw, sizeof(raw) - 1, &got, NULL)) { CloseHandle(h); return 2; }
    CloseHandle(h);
    raw[got] = 0;
    while (len < (int)got && raw[len] != 32 && raw[len] != 13 && raw[len] != 10) ++len;
    if (len < LIC_PAYLOAD + LIC_SIG) return 3;
    tn = b64_decode(raw, len, tok, sizeof(tok));
    if (tn != LIC_PAYLOAD + LIC_SIG) return 3;
    if (tok[0] != 0x52 || tok[1] != 0x52 || tok[2] != 0x4C || tok[3] != 0x31) return 4;
    if (tok[4] != LIC_VER) return 4;
    if (!lic_fingerprint(fp)) return 9;
    if (memcmp(tok + 5, fp, 16) != 0) return 5;
    now = lic_now();
    issued = *(long long*)(tok + 21);
    exp = *(long long*)(tok + 29);
    if (exp <= issued) return 4;
    if (now > exp) return 6;
    if (!lic_verify(tok, LIC_PAYLOAD, tok + LIC_PAYLOAD)) return 8;
    if (!lic_rollback(now)) return 7;
    return 0;
}


