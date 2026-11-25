#include "w3d_ptr.h"
#line 1 "d27e_apply_attributes_801a2bf4.cpp"
// (Worms 3D GameCube PAL, 0x801a2bf4).
//
// Applies a list of render attributes: each enabled attribute whose slot
// differs from the current one, or which is dirty, has its dirty flag
// cleared, is passed to the visitor's handler for its kind and recorded as
// current; then every slot not in the list falls back to its default in the
// same way. Names are inferred from the data flow.

struct Flags {
    char pad[4];
    unsigned char flags; char w3d_tag_rest[3];
    bool Dirty() const { return (flags >> 1) & 1; }
    void Clean() { flags &= 253; }
};
struct Attr { char p0[4]; Flags f; char p1[8]; unsigned short index; };
struct Attr2 { char p0[6]; unsigned short slot; };
struct Visitor;
typedef Ptr32<int (Ptr32<Visitor>, Ptr32<Attr>)> Fn;
struct Visitor { char pad[24]; Ptr32<Fn> table; };
struct Self {
    char pad[24]; Ptr32<Visitor> visitor; char p2[8]; Ptr32<Ptr32<Attr>> defaults; char p3[20]; Ptr32<Ptr32<Attr>> current;
};
extern int count_804b18d8;
extern "C" int w3d_d27e_apply_attributes_801a2bf4(Ptr32<Self> self, Ptr32<Ptr32<Attr>> list, unsigned n) {
    Ptr32<Visitor> v = self->visitor;
    unsigned seen = 0;
    Ptr32<Fn> table = v->table;
    unsigned i = 0;
    if (seen < n) {
        Ptr32<Ptr32<Attr>> p = list;
        do {
            Ptr32<Attr> a = *p++;
            Flags &fl = a->f;
            unsigned b = fl.flags; unsigned u = b & 0xff;
            if ((u ^ 4) & 4) {
                unsigned index = a->index;
                unsigned d = u >> 1;
                unsigned offset = index << 2;
                unsigned mask = 1 << index;
                if (*(Ptr32<Ptr32<Attr>>)((Ptr32<char>)self->current + offset) != a || (d & 1)) {
                    if (d & 1) fl.flags = b & 253;
                    table[((Ptr32<Attr2>)a)->slot](v, a);
                    *(Ptr32<Ptr32<Attr>>)((Ptr32<char>)self->current + offset) = a;
                }
                seen |= mask;
            }
            ++i;
        } while (i < n);
    }
    unsigned limit = 1 << count_804b18d8;
    unsigned bit = 2;
    Ptr32<Ptr32<Attr>> cur = self->current + 1;
    Ptr32<Ptr32<Attr>> def = self->defaults + 1;
    for (; bit != limit; bit <<= 1, ++cur, ++def) {
        if (!(seen & bit)) {
            Ptr32<Attr> d = *def;
            if (*cur != d || d->f.Dirty()) {
                if (d->f.Dirty()) d->f.Clean();
                table[((Ptr32<Attr2>)d)->slot](v, d);
                *cur = d;
            }
        }
    }
    return 0;
}


