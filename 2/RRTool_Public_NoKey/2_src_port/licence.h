#ifndef LICENCE_H
#define LICENCE_H

/* 0 = licence valide, code non nul = refus. */
int lic_check(void);

/* Empreinte machine en hexadecimal majuscule, 32 caracteres. */
int lic_fingerprint_hex(wchar_t* out, size_t cap);

/* A3: lie la cle a cette machine, quota de 3. */
int lic_bind(void);

/* Texte lisible associe a un code de refus. */
const wchar_t* lic_last_error(int code);

#endif

int lic_days_left(void);
