#include "w3d_ptr.h"
#line 1 "genparamc_80050620.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): temporary text string with padding calls
 * (see families_j.cpp for the sibling form). */
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
struct W3dString_803426b8 {
    Ptr32<char> text;
    W3dString_803426b8();
    ~W3dString_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
};
extern "C" void fn_802cd26c(Ptr32<void>, int, int);
extern "C" void fn_802cc0ac(Ptr32<void>, Ptr32<const char>, int);
extern "C" void fn_802cbdf8(int, Ptr32<char>, int);
extern "C" char lbl_803f3ff4[];
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern "C" char lbl_80435bbc[];

extern "C" void w3d_show_options_line_80050620(Ptr32<void> self)
{
    W3dString_803426b8 text;
    fn_802cd26c(&text, 0, 24);
    fn_802cc0ac(&text, lbl_803f3ff4, 9);
    fn_802cd26c(&text, 0, 24);
    fn_802cbdf8((int)w3d::H((FIELD(self, void *, 28))), text.text, 9);
}

extern "C" void w3d_show_options_line_80099998(Ptr32<void> self)
{
    W3dString_803426b8 text;
    fn_802cd26c(&text, 0, 24);
    fn_802cc0ac(&text, lbl_80435bbc, 9);
    fn_802cd26c(&text, 0, 24);
    fn_802cbdf8((int)w3d::H((FIELD(self, void *, 32))), text.text, 9);
}


