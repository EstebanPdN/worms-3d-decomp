#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_u.c"
/* Cleanup, handler and pool helpers. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern void fn_801fe2e0(Ptr32<char>);
extern void fn_801fe1f8(Ptr32<char>);
extern int lbl_804b1894;

void w3d_s20_destroy_buffers_8016fa94(Ptr32<char> self, int flags) {
    int zero = 0;
    Ptr32<char> first = *(Ptr32<Ptr32<char>>)(self + 84);
    Ptr32<char> second;
    lbl_804b1894 = zero;
    if (first != 0)
        fn_801fe2e0(first);
    second = *(Ptr32<Ptr32<char>>)(self + 88);
    *(Ptr32<int>)(self + 84) = zero;
    if (second != 0)
        fn_801fe2e0(second);
    *(Ptr32<int>)(self + 88) = zero;
    *(Ptr32<int>)(self + 92) = zero;
    if (flags & 1)
        fn_801fe1f8(self);
}

void w3d_s20_destroy_owned_80178474(Ptr32<char> self, int flags) {
    Ptr32<S20Object> owned = *(Ptr32<Ptr32<S20Object>>)self;
    if (owned != 0) {
        ((Ptr32<void (Ptr32<S20Object>)>)owned->vtable[16])(owned);
        if (*(Ptr32<int>)self != 0) {
            *(Ptr32<int>)self = 0;
            *(Ptr32<int>)(self + 4) = 0;
        }
    }
    if (flags & 1)
        fn_801fe1f8(self);
}

}
