#ifndef W3D_REFERENCE_CTYPE_H
#define W3D_REFERENCE_CTYPE_H
#ifdef W3D_LUA_GAME_CONFIG
/* Native character classifier lookup observed throughout the Lua lexer.
 * Base address and contents must be independently checked at reference link. */
extern unsigned char w3d_ctype_table[];
#define isalnum(c) ((w3d_ctype_table+1)[(int)(c)] & 7)
#define isalpha(c) ((w3d_ctype_table+1)[(int)(c)] & 3)
#define isdigit(c) ((w3d_ctype_table+1)[(int)(c)] & 4)
#define isspace(c) ((w3d_ctype_table+1)[(int)(c)] & 8)
#else
int isalnum(int);
int isalpha(int);
int isdigit(int);
int isspace(int);
int iscntrl(int);
int ispunct(int);
int islower(int);
int isupper(int);
int isxdigit(int);
int tolower(int);
int toupper(int);
#endif
#endif
