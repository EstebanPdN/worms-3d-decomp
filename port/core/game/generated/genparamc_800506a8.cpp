#include "w3d_ptr.h"
#line 1 "genparamc_800506a8.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Stack shared-string temporary: out-of-line constructor, inlined destructor. */
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
struct W3dString_803426b8 {
    Ptr32<char> text;
    W3dString_803426b8();
    ~W3dString_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
};
extern "C" void fn_802cd220(Ptr32<void>);
extern "C" void fn_802cd128(Ptr32<void>);
extern "C" void fn_802cbf2c(Ptr32<void>, Ptr32<const char>, int);
extern "C" void fn_802cbdf8(int, Ptr32<char>, int);
extern "C" char lbl_80377f70[];
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern "C" char lbl_8037ff74[];

extern "C" void w3d_show_placeholder_800506a8(Ptr32<void> self)
{
    W3dString_803426b8 text;
    fn_802cd220(&text);
    fn_802cd128(&text);
    fn_802cbf2c(&text, lbl_80377f70, 9);
    fn_802cbdf8((int)w3d::H((FIELD(self, void *, 28))), text.text, 9);
    FIELD(self, int, 36) = 2;
    FIELD(self, int, 32) = 0;
}

extern "C" void w3d_show_placeholder_80050730(Ptr32<void> self)
{
    W3dString_803426b8 text;
    fn_802cd220(&text);
    fn_802cd128(&text);
    fn_802cbf2c(&text, lbl_80377f70, 9);
    fn_802cbdf8((int)w3d::H((FIELD(self, void *, 28))), text.text, 9);
    FIELD(self, int, 36) = 3;
    FIELD(self, int, 32) = 0;
}

extern "C" void w3d_show_placeholder_80099a20(Ptr32<void> self)
{
    W3dString_803426b8 text;
    fn_802cd220(&text);
    fn_802cd128(&text);
    fn_802cbf2c(&text, lbl_8037ff74, 9);
    fn_802cbdf8((int)w3d::H((FIELD(self, void *, 32))), text.text, 9);
    FIELD(self, int, 40) = 2;
    FIELD(self, int, 36) = 0;
}


