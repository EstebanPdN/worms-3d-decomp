#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_adjust_p.c"
/* Render-state methods on the secondary base subobject (this - 4, null-checked). */
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20HandlerQ;
typedef struct S20Globals { char pad[5268]; unsigned int flags; } S20Globals;
extern Ptr32<S20Globals> lbl_804b1884;
extern int fn_801a2bf4(Ptr32<void>, Ptr32<char>, int);
extern void fn_8030ae60(int);
extern void fn_8016c014(Ptr32<char>, int);
extern void fn_801a3190(Ptr32<void>, int, Ptr32<char>);
extern void fn_803080a4(int);
extern void fn_8016803c(Ptr32<S20Globals>, int);
extern int fn_801a314c(Ptr32<void>, int);
extern void fn_801a3164(Ptr32<void>, int);
extern void fn_8016804c(Ptr32<S20Globals>, int);
extern void fn_8030ae84(int);
extern void fn_8030b648(int);

int w3d_s20_apply_texture_80168af0(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record;
    Ptr32<char> entry;
    Ptr32<char> texture;
    ((Ptr32<void (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)base)[17])(base, item);
    record = *(Ptr32<Ptr32<char>>)(item + 32);
    {
        int zero = 0;
        int device = *(Ptr32<int>)(base + 116);
        int count = *(Ptr32<int>)(record + 24);
        *(Ptr32<int>)(base + 216) = zero;
        fn_801a2bf4(w3d::G(device), record + 32, count);
    }
    {
        Ptr32<char> list = *(Ptr32<Ptr32<char>>)(item + 28) + 32;
        unsigned int slot = *(Ptr32<unsigned char>)(base + 212);
        entry = ((Ptr32<Ptr32<char>>)list)[slot];
    }
    texture = *(Ptr32<Ptr32<char>>)(entry + 36);
    if (texture != 0) {
        fn_8030ae60(0);
        fn_8016c014(base, 0);
        fn_801a3190(w3d::G(*(Ptr32<int>)(base + 116)), *(Ptr32<int>)(base + 216), texture);
        fn_803080a4(*(Ptr32<unsigned char>)(base + 216));
        fn_8016803c(lbl_804b1884, 32);
        lbl_804b1884->flags |= 0x20000000;
    } else {
        fn_801a314c(w3d::G(*(Ptr32<int>)(base + 116)), 0);
        fn_801a3164(w3d::G(*(Ptr32<int>)(base + 116)), 0);
        fn_8016804c(lbl_804b1884, 32);
    }
    fn_8030ae84(0);
    fn_8030b648(1);
    *(Ptr32<int>)(base + 216) = 0;
    return 0;
}

}
