#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_j.c"
/* Releases, global forwarding and flag clearing. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_800df684(Ptr32<char>);

int w3d_s20_release_held_800e41d8(Ptr32<char> self) {
    Ptr32<S20Object> held = *(Ptr32<Ptr32<S20Object>>)(self + 348);
    if (held != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)held->vtable[4])(held);
    *(Ptr32<int>)(self + 348) = 0;
    return fn_800df684(self + 28);
}

extern int fn_800e61b8(Ptr32<void>, int, int, int, Ptr32<void>);
extern Ptr32<void> lbl_804aaecc;

int w3d_s20_forward_global4_800e5d4c(int a, int b, int c, int d) {
    if (lbl_804aaecc == 0)
        return 0;
    return fn_800e61b8(lbl_804aaecc, a, b, c, w3d::G(d));
}

extern int fn_800fddd8(Ptr32<void>, int, int, int, int);
extern Ptr32<void> lbl_804aaf64;

int w3d_s20_forward_global4_800fdd80(int a, int b, int c, int d) {
    if (lbl_804aaf64 == 0)
        return 0x80004005;
    return fn_800fddd8(lbl_804aaf64, a, b, c, d);
}

extern void fn_800b0824(Ptr32<char>, Ptr32<char>, Ptr32<char>, int, int);
extern int lbl_804b1764;

int w3d_s20_check_limit_800e6ec8(Ptr32<char> self) {
    fn_800b0824(self + 116, self + 12, self + 24, *(Ptr32<int>)(self + 92), 1);
    return lbl_804b1764 <= *(Ptr32<int>)(self + 92);
}

extern int fn_800fdf5c(Ptr32<char>, int, int, int);

int w3d_s20_clear_top_flags_800fdecc(Ptr32<char> self) {
    *(Ptr32<unsigned int>)(self + 92) &= 0x3fffffff;
    fn_800fdf5c(self, 0, 0, 0);
    return fn_800fdf5c(self, 1, 0, 0);
}

}
