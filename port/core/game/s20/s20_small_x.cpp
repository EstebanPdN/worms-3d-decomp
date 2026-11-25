#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_x.c"
/* Constructor with a retained global and a find-or-create wrapper. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern Ptr32<void> fn_801ea0ec(Ptr32<char>, int);
extern Ptr32<S20Object> lbl_804b05a8;
extern char lbl_80413558[];

Ptr32<char> w3d_s20_construct_counted_8019b424(Ptr32<char> self, Ptr32<void> arg_r4) {
    int zero;
    int five;
    Ptr32<S20Object> shared;
    fn_801ea0ec(self, w3d::H(arg_r4));
    shared = lbl_804b05a8;
    *(Ptr32<Ptr32<char>>)self = lbl_80413558;
    *(Ptr32<Ptr32<S20Object>>)(self + 20) = shared;
    if (shared != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)shared->vtable[3])(shared);
    zero = 0;
    five = 5;
    *(Ptr32<int>)(self + 24) = five;
    *(Ptr32<int>)(self + 32) = zero;
    *(Ptr32<int>)(self + 28) = five;
    *(Ptr32<int>)(self + 36) = zero;
    *(Ptr32<int>)(self + 40) = zero;
    *(Ptr32<int>)(self + 44) = zero;
    return self;
}

extern Ptr32<char> fn_801a688c(Ptr32<char>, Ptr32<char>);
extern Ptr32<char> fn_801a6908(Ptr32<char>, Ptr32<char>);
extern int fn_801a6724(Ptr32<char>, Ptr32<char>, Ptr32<char>);
extern void fn_801a66c0(Ptr32<char>, Ptr32<char>);

int w3d_s20_find_or_create_801a692c(Ptr32<char> self, Ptr32<char> key) {
    Ptr32<char> entry = fn_801a688c(self, key);
    int result;
    if (entry == 0) {
        entry = fn_801a6908(self, key);
        fn_801a6724(self, key, entry);
        fn_801a66c0(self, entry);
        result = 0;
    } else {
        fn_801a66c0(self, entry);
        result = 1;
    }
    return result;
}

}
