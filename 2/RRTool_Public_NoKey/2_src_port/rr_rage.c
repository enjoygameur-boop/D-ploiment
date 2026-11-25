/* rr_rage.c - visée standard : AimTargetModel + rot + sensibilite a zero. */
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "rr_mem.h"
#include "rr_unity.h"
#include "rr_game.h"
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>

#define RAGE_LOG "C:\\Users\\ABC\\Desktop\\Cheats\\2\\RRTool_Public_NoKey\\1_run\\rage.log"
#define DEG2RAD 0.01745329f

static volatile LONG g_rage_started;
static FILE* g_lg;
static DWORD g_lastlog;
static RR_PLAYER g_pl[RR_MAX_PLAYERS];
static RR_CAMERA g_cam;
static int g_snap_n;
static DWORD g_snap_at;
static uint64_t g_game;
#define AIM_DROP 0.10f
static int g_fire, g_have, g_has, g_hasens, g_miss, g_camdump;
static float g_by, g_bp, g_ly, g_lp, g_sy, g_sp;
static int32_t g_lid;
static uint64_t g_sens;


static void lg_(const char* fmt, ...) {
    va_list a;
    if (!g_lg) return;
    va_start(a, fmt); vfprintf(g_lg, fmt, a); va_end(a);
    fputc('\n', g_lg); fflush(g_lg);
}
static int wrf(uint64_t a, float v) { return rr_write(a, &v, 4); }
static int rdf(uint64_t a, float* o) { return rr_read(a, o, 4); }
static void wri32(uint64_t a, int v) { rr_write(a, &v, 4); }

static void nospread(uint64_t ch) {
    uint64_t a = rr_u64(ch + 0x10u), s;
    if (!PL(a)) return;
    s = rr_u64(a + 0x220u);
    if (!PL(s)) return;
    wri32(s + 0x20u, 0);
    wri32(s + 0x24u, 0);
}

static int pick(uint64_t rot, float* oy, float* op, int32_t* oid) {
    float cy, cp, fx, fy, fz, best = 25.0f * DEG2RAD;
    int bi = -1, i;
    DWORD now = GetTickCount();
    if (!rdf(rot + 0x10u, &cy) || !rdf(rot + 0x14u, &cp)) return 0;
    if (cy != cy || cp != cp) return 0;
    fx = sinf(cy) * cosf(cp); fy = -sinf(cp); fz = cosf(cy) * cosf(cp);
    if ((DWORD)(now - g_snap_at) > 100) { g_snap_at = now; g_snap_n = game_snapshot(g_pl, RR_MAX_PLAYERS, &g_cam); }
    for (i = 0; i < g_snap_n; i++) {
        RR_PLAYER* p = &g_pl[i];
        float dx, dy, dz, ln, d;
        if (!(p->dist > 2.0f && p->dist < 300.0f)) continue;
        if (!p->id) continue;
        dx = p->head.x - g_cam.pos.x; dy = p->head.y - g_cam.pos.y; dz = p->head.z - g_cam.pos.z;
        ln = sqrtf(dx * dx + dy * dy + dz * dz);
        if (ln < 1.0f) continue;
        d = (dx * fx + dy * fy + dz * fz) / ln;
        if (d > 1.0f) d = 1.0f;
        if (d < -1.0f) d = -1.0f;
        d = acosf(d);
        if (d > best) continue;
        best = d; bi = i;
    }
    if (bi < 0) return 0;
    {
        RR_PLAYER* p = &g_pl[bi];
        float dx = p->head.x - g_cam.pos.x, dy = p->head.y - g_cam.pos.y - AIM_DROP, dz = p->head.z - g_cam.pos.z;
        float ln = sqrtf(dx * dx + dy * dy + dz * dz);
        if (ln < 1.0f) return 0;
        *oy = atan2f(dx, dz);
        *op = -asinf(dy / ln);
        if (*op > 1.4f) *op = 1.4f;
        if (*op < -1.4f) *op = -1.4f;
        if (*oy != *oy || *op != *op) return 0;
        *oid = p->id;
    }
    return 1;
}

static void tick(uint64_t ch, uint64_t battle) {
    uint64_t rot, aim, sens;
    float yaw = 0.0f, pitch = 0.0f;
    int32_t cid = 0;
    int fire, ok = 0, why = 0;
    DWORD now = GetTickCount();
    if (PL(ch)) nospread(ch);
    if (!PL(battle)) { g_fire = 0; return; }
    rot = rr_u64(battle + 0x40u);
    if (!PL(rot)) { g_fire = 0; return; }
    aim = rr_u64(battle + 0x198u);
    fire = (GetAsyncKeyState(0x01) & 0x8000) != 0;
    if (fire && !g_fire) {
        g_have = (rdf(rot + 0x10u, &g_by) && rdf(rot + 0x14u, &g_bp));
        g_has = 0; g_miss = 0; g_hasens = 0;
        sens = PL(g_game) ? rr_u64(g_game + 0x58u) : 0;
        if (PL(sens) && rdf(sens + 0x10u, &g_sy) && rdf(sens + 0x14u, &g_sp)) { g_sens = sens; g_hasens = 1; }
        lg_("PRESS by=%.4f bp=%.4f have=%d hasens=%d", g_by, g_bp, g_have, g_hasens);
    }
    if (fire) {
        if (g_hasens && PL(g_sens)) { wrf(g_sens + 0x10u, 0.0f); wrf(g_sens + 0x14u, 0.0f); }
        if (!PL(aim)) why = 1;
        else if (pick(rot, &yaw, &pitch, &cid)) { g_ly = yaw; g_lp = pitch; g_lid = cid; g_has = 1; g_miss = 0; }
        else { if (++g_miss > 15) g_has = 0; why = 2; }
        if (g_has && PL(aim)) {
            wri32(aim + 0x10u, g_lid);
            wri32(aim + 0x14u, 3);
            wrf(rot + 0x10u, g_ly);
            wrf(rot + 0x14u, g_lp);
            ok = 1;
        }
    }
    if (!fire && g_fire) {
        if (PL(aim)) { wri32(aim + 0x10u, -1); wri32(aim + 0x14u, 0); }
        if (g_have) { wrf(rot + 0x10u, g_by); wrf(rot + 0x14u, g_bp); g_have = 0; }
        if (g_hasens && PL(g_sens)) { wrf(g_sens + 0x10u, g_sy); wrf(g_sens + 0x14u, g_sp); g_hasens = 0; }
        g_has = 0; g_miss = 0;
    }
    if (!g_camdump && g_snap_n > 0) {
        uint32_t raw[16];
        int k;
        g_camdump = 1;
        memcpy(raw, &g_cam, sizeof g_cam < 64 ? sizeof g_cam : 64);
        lg_("CAMDUMP");
        for (k = 0; k < 16; k++) {
            float f;
            memcpy(&f, &raw[k], 4);
            lg_("  c+%02X %08X %.5f", k * 4, raw[k], f);
        }
    }
    if ((DWORD)(now - g_lastlog) > 250) {
        g_lastlog = now;
        lg_("ST cid=%d aim=%llX rot=%llX ok=%d fire=%d why=%d has=%d miss=%d yaw=%.4f pitch=%.4f", cid, (unsigned long long)aim, (unsigned long long)rot, ok, fire, why, g_has, g_miss, g_ly, g_lp);
    }
    g_fire = fire;
}

static DWORD WINAPI rage_thread(LPVOID unused) {
    uint64_t updater = 0, battle = 0, local = 0;
    DWORD resolved = 0;
    HANDLE proc = NULL;
    (void)unused;
    g_lg = fopen(RAGE_LOG, "w");
    lg_("thread start");
timeBeginPeriod(1);
    for (;;) {
        DWORD now;
        if (proc) {
            if (WaitForSingleObject(proc, 0) == WAIT_OBJECT_0) {
                CloseHandle(proc); proc = NULL; resolved = 0; battle = 0; local = 0;
                lg_("process gone, pause"); Sleep(600); continue;
            }
        } else if (g_rr_pid) {
            proc = OpenProcess(SYNCHRONIZE | PROCESS_QUERY_LIMITED_INFORMATION, FALSE, g_rr_pid);
            if (!proc) { Sleep(100); continue; }
            lg_("process attache");
        } else { Sleep(100); continue; }
        now = GetTickCount();
        if ((DWORD)(now - resolved) >= 2000) {
            int scanning = 0;
            resolved = now;
            g_game = 0;
            game_scene_debug(&g_game, &updater, &scanning);
            battle = PL(updater) ? rr_u64(updater + 0x70u) : 0;
            local = rr_local_player();
            lg_("res game=%llX bat=%llX loc=%llX", (unsigned long long)g_game, (unsigned long long)battle, (unsigned long long)local);
        }
        __try { tick(local, battle); } __except (EXCEPTION_EXECUTE_HANDLER) { lg_("tick fault"); battle = 0; }
        Sleep(g_fire ? 1 : 10);
    }
}

void rage_start(void) {
    HANDLE t;
    if (InterlockedCompareExchange(&g_rage_started, 1, 0) != 0) return;
    t = CreateThread(NULL, 0, rage_thread, NULL, 0, NULL);
    if (t) CloseHandle(t);
    else InterlockedExchange(&g_rage_started, 0);
}