#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b27_utf_8018a864.c"
/* Converts a NUL-terminated byte string into 16-bit units through a
   per-character decoder; releases the buffer and returns 0 on decoder failure.
   The inline helper reproduces the original's copy of the string pointer. */
extern unsigned int strlen(Ptr32<const char>);
extern Ptr32<void> fn_801fe0b8(unsigned int);
extern unsigned int fn_8018b360(Ptr32<const char>, Ptr32<int>);
extern void fn_801fe160(Ptr32<void>);
static inline Ptr32<unsigned short> run(Ptr32<const char> s, Ptr32<unsigned short> result) {
    Ptr32<unsigned short> out = result;
    int length;
    while (*s) {
        *out++ = fn_8018b360(s, &length);
        if (length == 0) { fn_801fe160(result); return 0; }
        s += length;
    }
    *out = 0;
    return result;
}
Ptr32<unsigned short> tsonnet_b27_utf_8018a864(Ptr32<const char> s) {
    return run(s, (Ptr32<unsigned short>)fn_801fe0b8((strlen(s) + 1) * 2));
}

}
