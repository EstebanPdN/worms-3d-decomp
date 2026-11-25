#include "w3d_ptr.h"
#ifndef W3D_ERRNO_H
#define W3D_ERRNO_H
extern "C" int __w3d_errno __asm__(W3D_SYM("w3d_errno_"));
#define errno __w3d_errno
#endif
