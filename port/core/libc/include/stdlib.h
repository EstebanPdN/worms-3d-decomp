#ifndef W3D_STDLIB_H
#define W3D_STDLIB_H
#include "w3d_libc_decl.h"
#include <stddef.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define RAND_MAX 2147483647
typedef struct { int quot; int rem; } div_t;
typedef struct { int quot; int rem; } ldiv_t;
extern "C" {
Ptr32<void> malloc(size_t) W3D_LIBC(malloc);
Ptr32<void> calloc(size_t, size_t) W3D_LIBC(calloc);
Ptr32<void> realloc(Ptr32<void>, size_t) W3D_LIBC(realloc);
void free(Ptr32<void>) W3D_LIBC(free);
void exit(int) W3D_LIBC(exit);
void abort(void) W3D_LIBC(abort);
int atoi(Ptr32<const char>) W3D_LIBC(atoi);
double atof(Ptr32<const char>) W3D_LIBC(atof);
double strtod(Ptr32<const char>, Ptr32<Ptr32<char> >) W3D_LIBC(strtod);
int strtol(Ptr32<const char>, Ptr32<Ptr32<char> >, int) W3D_LIBC(strtol);
unsigned int strtoul(Ptr32<const char>, Ptr32<Ptr32<char> >, int) W3D_LIBC(strtoul);
int rand(void) W3D_LIBC(rand);
void srand(unsigned int) W3D_LIBC(srand);
int abs(int) W3D_LIBC(abs);
int labs(int) W3D_LIBC(labs);
div_t div(int, int) W3D_LIBC(div);
ldiv_t ldiv(int, int) W3D_LIBC(ldiv);
Ptr32<char> getenv(Ptr32<const char>) W3D_LIBC(getenv);
int system(Ptr32<const char>) W3D_LIBC(system);
void qsort(Ptr32<void>, size_t, size_t, Ptr32<int (Ptr32<const void>, Ptr32<const void>)>) W3D_LIBC(qsort);
}
#endif
