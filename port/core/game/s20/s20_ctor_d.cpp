#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_ctor_d.c"
/* Constructors that retain a shared global object. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern Ptr32<S20Object> lbl_804b05a8;

extern int fn_801bd510(Ptr32<char>, Ptr32<void>);
extern char lbl_80415190[];
extern float lbl_803abba0[];

Ptr32<char> w3d_s20_construct_scaled_801bd6b8(Ptr32<char> self, Ptr32<void> arg_r4) {
    Ptr32<S20Object> shared;
    float value;
    Ptr32<char> sub;
    fn_801bd510(self, arg_r4);
    value = lbl_803abba0[0];
    shared = lbl_804b05a8;
    *(Ptr32<Ptr32<char>>)self = lbl_80415190;
    sub = self + 28;
    *(Ptr32<float>)(self + 28) = value;
    *(Ptr32<volatile float>)(sub + 8) = value;
    *(Ptr32<volatile float>)(sub + 4) = value;
    *(Ptr32<Ptr32<S20Object>>)(self + 40) = shared;
    if (shared != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)shared->vtable[3])(shared);
    return self;
}

extern Ptr32<void> fn_801ea0ec(Ptr32<char>, int);
extern char lbl_80415ee8[];

Ptr32<char> w3d_s20_construct_flagged_801cdd48(Ptr32<char> self, Ptr32<void> arg_r4) {
    int zero = 0;
    Ptr32<S20Object> shared;
    fn_801ea0ec(self, w3d::H(arg_r4));
    shared = lbl_804b05a8;
    *(Ptr32<Ptr32<char>>)self = lbl_80415ee8;
    *(Ptr32<int>)(self + 20) = 1;
    *(Ptr32<int>)(self + 24) = zero;
    *(Ptr32<Ptr32<S20Object>>)(self + 28) = shared;
    if (shared != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)shared->vtable[3])(shared);
    *(Ptr32<unsigned char>)(self + 32) = zero;
    *(Ptr32<unsigned char>)(self + 33) = zero;
    return self;
}

}
