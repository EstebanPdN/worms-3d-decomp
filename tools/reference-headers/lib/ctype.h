#ifndef W3D_REFERENCE_LIBRARY_CTYPE_H
#define W3D_REFERENCE_LIBRARY_CTYPE_H
#include_next <ctype.h>
#ifdef W3D_LUA_GAME_CONFIG
/* Masks observed in original table at 803db448, with the EOF slot first. */
#define iscntrl(c) ((w3d_ctype_table+1)[(int)(c)] & 0x20)
#define ispunct(c) ((w3d_ctype_table+1)[(int)(c)] & 0x10)
#define islower(c) ((w3d_ctype_table+1)[(int)(c)] & 2)
#define isupper(c) ((w3d_ctype_table+1)[(int)(c)] & 1)
#define isxdigit(c) ((w3d_ctype_table+1)[(int)(c)] & 0x44)
#define isprint(c) ((w3d_ctype_table+1)[(int)(c)] & 0x97)
#define isgraph(c) ((w3d_ctype_table+1)[(int)(c)] & 0x17)
#endif
int tolower(int);
int toupper(int);
#endif
