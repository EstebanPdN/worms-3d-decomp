#ifndef W3D_STDDEF_H
#define W3D_STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
#ifndef NULL
#define NULL 0
#endif
#define offsetof(t, m) __builtin_offsetof(t, m)
#endif
