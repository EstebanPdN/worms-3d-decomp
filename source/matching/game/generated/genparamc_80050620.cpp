/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): temporary text string with padding calls
 * (see families_j.cpp for the sibling form). */
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
struct W3dString_803426b8 {
    char *text;
    W3dString_803426b8();
    ~W3dString_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
};
extern "C" void fn_802cd26c(void *, int, int);
extern "C" void fn_802cc0ac(void *, const char *, int);
extern "C" void fn_802cbdf8(int, char *, int);
extern "C" char lbl_803f3ff4[];
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern "C" char lbl_80435bbc[];

extern "C" void w3d_show_options_line_80050620(void *self)
{
    W3dString_803426b8 text;
    fn_802cd26c(&text, 0, 24);
    fn_802cc0ac(&text, lbl_803f3ff4, 9);
    fn_802cd26c(&text, 0, 24);
    fn_802cbdf8((int)(FIELD(self, void *, 28)), text.text, 9);
}

extern "C" void w3d_show_options_line_80099998(void *self)
{
    W3dString_803426b8 text;
    fn_802cd26c(&text, 0, 24);
    fn_802cc0ac(&text, lbl_80435bbc, 9);
    fn_802cd26c(&text, 0, 24);
    fn_802cbdf8((int)(FIELD(self, void *, 32)), text.text, 9);
}
