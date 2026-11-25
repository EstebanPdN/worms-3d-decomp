// Libc del juego: nombres C habituales que enlazan con la implementación en
// core/libc/src. Los punteros son P<T>, y size_t mide 4 B como en GameCube.
#ifndef W3D_LIBC_DECL_H
#define W3D_LIBC_DECL_H
#include "w3d_ptr.h"
#if defined(__APPLE__)
#define W3D_LIBC(name) __asm__("_w3d_" #name)
#else
#define W3D_LIBC(name) __asm__("w3d_" #name)
#endif
#endif
