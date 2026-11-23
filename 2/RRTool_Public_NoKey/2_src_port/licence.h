#ifndef LICENCE_H
#define LICENCE_H

/* 0 = licence valide, code non nul = refus. */
int lic_check(void);

/* Texte lisible associe a un code de refus. */
const wchar_t* lic_last_error(int code);

#endif