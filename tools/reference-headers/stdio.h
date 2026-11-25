#ifndef W3D_REFERENCE_STDIO_H
#define W3D_REFERENCE_STDIO_H
#include <stddef.h>
#include <stdarg.h>
typedef struct W3dReferenceFILE FILE;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
#define EOF (-1)
int printf(const char *, ...);
int fprintf(FILE *, const char *, ...);
int sprintf(char *, const char *, ...);
int vsprintf(char *, const char *, va_list);
int sscanf(const char *, const char *, ...);
int fputs(const char *, FILE *);
int fputc(int, FILE *);
FILE *fopen(const char *, const char *);
int fclose(FILE *);
size_t fread(void *, size_t, size_t, FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
#endif
