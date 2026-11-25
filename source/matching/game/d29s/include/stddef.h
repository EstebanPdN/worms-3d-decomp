/* Minimal C library declarations STLport reaches through <../include/x>. */
#ifndef D29S_STDDEF_H
#define D29S_STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef int wint_t;
#define NULL 0
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif
