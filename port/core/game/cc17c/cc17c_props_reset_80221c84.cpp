#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17c_props_reset_80221c84.c"
/* Same source shape as the admitted property reset 0x80220f7c (genparam_80220f7c.c): resets the
 * ItemHighlightedMessage and ItemSelectedMessage string properties to the shared empty string, then
 * binds BorderColour. Observed string header: 16-bit reference count 6 bytes before the text. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { Ptr32<char> text; } W3dString;
extern int lbl_804b06a0[];
extern char lbl_803b6a78[];
extern char lbl_803b6ab0[];
extern char lbl_803b6ad4[];
Ptr32<void> fn_801ece2c(Ptr32<void> self, Ptr32<const char> name);
Ptr32<void> fn_801ed24c(Ptr32<void> self, Ptr32<const char> name);
void fn_8020c5c0(Ptr32<W3dString> string);
Ptr32<unsigned short> fn_80341884(Ptr32<W3dString> string);
void fn_8020bb2c(Ptr32<W3dStringHeader> header);
void fn_8020c5c4(Ptr32<W3dString> string);
void fn_80341588(Ptr32<W3dString> string);
void fn_801e8d9c(Ptr32<void> self);

int w3d_cc17c_props_reset_80221c84(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803b6a78);
    fn_8020c5c0(&empty);
    empty.text = (Ptr32<char>)w3d::G(lbl_804b06a0[0]);
    (*fn_80341884(&empty))++;
    ++((Ptr32<W3dStringHeader>)(empty.text - 6))->references;
    {
        Ptr32<W3dStringHeader> old = (Ptr32<W3dStringHeader>)(FIELD(property, char *, 8) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    FIELD(property, char *, 8) = empty.text;
    fn_8020c5c4(&empty);
    fn_80341588(&empty);
    second = fn_801ed24c(self, lbl_803b6ab0);
    fn_8020c5c0(&empty);
    empty.text = (Ptr32<char>)w3d::G(lbl_804b06a0[0]);
    (*fn_80341884(&empty))++;
    ++((Ptr32<W3dStringHeader>)(empty.text - 6))->references;
    {
        Ptr32<W3dStringHeader> old = (Ptr32<W3dStringHeader>)(FIELD(second, char *, 8) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    FIELD(second, char *, 8) = empty.text;
    fn_8020c5c4(&empty);
    fn_80341588(&empty);
    fn_801ece2c(self, lbl_803b6ad4);
    fn_801e8d9c(self);
    return 0;
}

}
