/* Freestanding declaration surface for controlled historical compiler probes. */
#ifndef W3D_REFERENCE_STDLIB_H
#define W3D_REFERENCE_STDLIB_H
#include <stddef.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
void *malloc(size_t);
void *calloc(size_t, size_t);
void *realloc(void *, size_t);
void free(void *);
void abort(void);
void exit(int);
int abs(int);
long labs(long);
double strtod(const char *, char **);
long strtol(const char *, char **, int);
unsigned long strtoul(const char *, char **, int);
void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
#endif
