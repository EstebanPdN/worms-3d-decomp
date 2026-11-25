#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17c_locked_props_reset_80226684.c"
/* Same source shape as the admitted string-field reset 0x8018e348 (genparamc_8018e348.c), with an
 * extra leading binding: binds Locked, resets the LockedTitle string to the shared empty string
 * (16-bit reference count 6 bytes before the text, observed) and binds LockedIcon. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern char lbl_803b7fec[];
extern char lbl_803b8020[];
extern char lbl_803b8050[];
extern Ptr32<char> lbl_804b06a0[];
Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<const char>);
Ptr32<void> fn_801ed24c(Ptr32<void>, Ptr32<const char>);
void fn_8020c5c0(Ptr32<void>);
Ptr32<unsigned short> fn_80341884(Ptr32<void>);
void fn_8020bb2c(Ptr32<void>);
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
Ptr32<void> fn_801ece2c(Ptr32<void>, Ptr32<const char>);
void fn_801e8d9c(Ptr32<void>);
int w3d_cc17c_locked_props_reset_80226684(Ptr32<void> self)
{
    Ptr32<void> owner;
    Ptr32<Ptr32<char>> empty;
    Ptr32<char> text[1];
    Ptr32<unsigned short> header;
    fn_801eb674(self, lbl_803b7fec);
    owner = fn_801ed24c(self, lbl_803b8020);
    empty = lbl_804b06a0;
    fn_8020c5c0(text);
    text[0] = *empty;
    ++*fn_80341884(text);
    ++*(Ptr32<unsigned short>)(text[0] - 6);
    header = (Ptr32<unsigned short>)(FIELD(owner, char *, 8) - 6);
    if (--*header == 0)
        fn_8020bb2c(header);
    FIELD(owner, char *, 8) = text[0];
    fn_8020c5c4(text);
    fn_80341588(text);
    fn_801ece2c(self, lbl_803b8050);
    fn_801e8d9c(self);
    return 0;
}

}
