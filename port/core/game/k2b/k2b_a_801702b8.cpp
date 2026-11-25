#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801702b8.c"
struct K2bSpec { Ptr32<const char> name; unsigned char kind; unsigned char sub; unsigned char pad06[2]; int value; unsigned short first; unsigned short second; unsigned short flags; };
struct K2bHeader { unsigned char pad[2]; unsigned char sub; unsigned char kind; };
struct K2bEntry {
    unsigned char pad0[24];
    union { struct K2bHeader header; unsigned int word; } u;
    unsigned char pad1[4];
    int value;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    unsigned short one_a;
    unsigned short one_b;
    unsigned short zero;
    unsigned short flags;
};
extern void w3d_string_assign(Ptr32<void> dest, Ptr32<const char> text);
int w3d_k2b_entry_init_801702b8(Ptr32<struct K2bEntry> self, Ptr32<struct K2bSpec> spec)
{
    unsigned short flags;
    w3d_string_assign((Ptr32<char>)self + 20, spec->name);
    self->u.header.kind = spec->kind;
    self->u.header.sub = spec->sub;
    self->value = spec->value;
    flags = spec->flags;
    self->flags = flags;
    self->one_a = 1;
    self->one_b = 1;
    if (flags & 32) {
        self->a = spec->first;
        self->b = spec->second;
        self->c = 0;
        self->d = 0;
    } else {
        self->a = flags & 32;
        self->b = flags & 32;
        self->c = spec->first;
        self->d = spec->second;
    }
    self->u.word &= ~0x8000;
    self->zero = 0;
    return 0;
}
// desc: Appears to initialize a table entry from a spec record: name, kind bytes, value, flags and a flag-dependent pair of ranges.

}
