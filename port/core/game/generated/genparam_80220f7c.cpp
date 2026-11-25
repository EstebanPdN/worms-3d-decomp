#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_80220f7c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { Ptr32<char> text; } W3dString;
extern int lbl_804b06a0[];
extern char lbl_803b67a4[];
extern char lbl_803b67d8[];
Ptr32<void> fn_801ed24c(Ptr32<void> self, Ptr32<const char> name);
void fn_8020c5c0(Ptr32<W3dString> string);
Ptr32<unsigned short> fn_80341884(Ptr32<W3dString> string);
void fn_8020bb2c(Ptr32<W3dStringHeader> header);
void fn_8020c5c4(Ptr32<W3dString> string);
void fn_80341588(Ptr32<W3dString> string);
void fn_801e8d9c(Ptr32<void> self);
extern char lbl_803bab44[];
extern char lbl_803bab70[];
extern char lbl_803bb050[];
extern char lbl_803bb07c[];
extern char lbl_803bb0bc[];
extern char lbl_803bb0e0[];
extern char lbl_803bc420[];
extern char lbl_803bc44c[];
extern char lbl_803bc48c[];
extern char lbl_803bc4b0[];
extern char lbl_803bc4e4[];
extern char lbl_803bc508[];

int w3d_props_reset_80220f7c(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803b67a4);
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
    second = fn_801ed24c(self, lbl_803b67d8);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_80235cd4(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803bab44);
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
    second = fn_801ed24c(self, lbl_803bab70);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023754c(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803bb050);
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
    second = fn_801ed24c(self, lbl_803bb07c);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_80237ab4(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803bb0bc);
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
    second = fn_801ed24c(self, lbl_803bb0e0);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023d7f0(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803bc420);
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
    second = fn_801ed24c(self, lbl_803bc44c);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023dc64(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803bc48c);
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
    second = fn_801ed24c(self, lbl_803bc4b0);
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
    fn_801e8d9c(self);
    return 0;
}

int w3d_props_reset_8023df70(Ptr32<void> self)
{
    W3dString empty;
    Ptr32<char> property;
    Ptr32<char> second;
    property = fn_801ed24c(self, lbl_803bc4e4);
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
    second = fn_801ed24c(self, lbl_803bc508);
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
    fn_801e8d9c(self);
    return 0;
}

}
