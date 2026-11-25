#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_props_e.c"
/* Property registration functions made of shared registration blocks. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { Ptr32<char> text; } W3dString;
typedef struct S20Vec4 { float x; float y; float z; float w; } S20Vec4;
extern int lbl_804b06a0[];
Ptr32<void> fn_801ed24c(Ptr32<void> self, Ptr32<const char> name);
void fn_8020c5c0(Ptr32<W3dString> string);
Ptr32<unsigned short> fn_80341884(Ptr32<W3dString> string);
void fn_8020bb2c(Ptr32<W3dStringHeader> header);
void fn_8020c5c4(Ptr32<W3dString> string);
void fn_80341588(Ptr32<W3dString> string);
void fn_801e8d9c(Ptr32<void> self);
Ptr32<void> fn_801ebf38(Ptr32<void> self, Ptr32<char> name);
Ptr32<void> fn_801eb674(Ptr32<void> self, Ptr32<char> name);
Ptr32<void> fn_801ece2c(Ptr32<void> self, Ptr32<char> name);
extern Ptr32<char> fn_801f0b70(Ptr32<char>, Ptr32<char>);
extern char lbl_803ad7f0[];
extern char lbl_803ad820[];
extern char lbl_803ae4ac[];
extern char lbl_803ae4e0[];
extern char lbl_803ae514[];
extern char lbl_803ae548[];
extern char lbl_803ae580[];
extern float lbl_803ae5a4[];
extern float lbl_803ae5a8[];

int w3d_s20_register_string_after_entry_801c919c(Ptr32<void> self) {
    W3dString empty;
    Ptr32<char> property;
    Ptr32<int> empty_text = lbl_804b06a0;
    fn_801ebf38(self, lbl_803ad7f0);
    property = fn_801ed24c(self, lbl_803ad820);
    fn_8020c5c0(&empty);
    empty.text = (Ptr32<char>)w3d::G(empty_text[0]);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_s20_register_entries_vec4_801ccf38(Ptr32<char> self) {
    Ptr32<char> property;
    S20Vec4 value;
    Ptr32<volatile float> w;
    fn_801eb674(self, lbl_803ae4ac);
    fn_801eb674(self, lbl_803ae4e0);
    fn_801eb674(self, lbl_803ae514);
    fn_801ece2c(self, lbl_803ae548);
    property = fn_801f0b70(self, lbl_803ae580);
    w = (Ptr32<volatile float>)&value;
    w[0] = lbl_803ae5a4[0];
    w[2] = lbl_803ae5a4[0];
    w[3] = lbl_803ae5a8[0];
    w[1] = lbl_803ae5a4[0];
    *(Ptr32<S20Vec4>)(property + 8) = value;
    fn_801e8d9c(self);
    return 0;
}

}
