#ifndef W3D_REFERENCE_LIBRARY_STDIO_H
#define W3D_REFERENCE_LIBRARY_STDIO_H
#include_next <stdio.h>
/* Probe default only. Exact native body comparisons must establish buffer
 * configuration; this header does not establish a complete target libc. */
#define BUFSIZ 1024
int getc(FILE *);
int ungetc(int, FILE *);
int feof(FILE *);
int ferror(FILE *);
FILE *freopen(const char *, const char *, FILE *);
char *fgets(char *, int, FILE *);
#endif
