#include "w3d_ptr.h"
#line 1 "d29c_part_team_tint_800da4e4.cpp"
// d29c: 0x800da4e4. Part tint: reads the active index, gets the part resource by descriptor, locks its colour array and writes the entry's colour as floats (byte over 255), then starts the part's effect once. Names are inferred; classes are partial views.
struct Object;
struct ObjectVtable { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Header { char u0[4]; unsigned short kind; char u6[18]; int count; unsigned short locks; char u30[2]; char data[1]; };
struct ArrayRef {
    Ptr32<Header> header;
    Ptr32<void> lock();
};
extern "C" Ptr32<void> reserve_801ef048(Ptr32<ArrayRef>, int, int, int);
inline Ptr32<void> ArrayRef::lock() {
    Ptr32<Header> h = header;
    int kind = h->kind;
    if (kind == 1 && kind == h->count) {
        ++h->locks;
        return h->data;
    }
    return reserve_801ef048(this, 1, 12, 0);
}
struct Tint : Object { char u4[136] __attribute__((aligned(__alignof__(Object)))); ArrayRef colours; };
struct Held {
    Held(const Held &);
    Ptr32<Tint> value;
    Held() : value(0) {}
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Tint *)w3d_p.get()) {}
 Held(Tint *next) : value(next) { if (value) value->vtable->retain(value); }
    ~Held() { if (value) value->vtable->release(value); }
    void assign(Ptr32<Tint> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Key { Ptr32<const char> name; };
struct Vec { float x, y, z; };
struct Colour { unsigned char r, g, b, a; };
struct Part { char u0[32]; Ptr32<void> h32; Ptr32<void> effect; };
extern char active_8038976c[], part_8038977c[];
extern int group_804aae7c;
extern "C" int readInt_800fc1f0(Ptr32<Key>, Ptr32<unsigned int>);
extern "C" int query_800fc6dc(unsigned);
extern "C" int readRes_800fc1b0(Ptr32<Key>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<void> identity_80341584(Ptr32<Object>);
extern "C" Ptr32<Tint> cast_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<void> entry_800fd388(...);
extern "C" Ptr32<void> empty_80343584(Ptr32<void>);
extern "C" Ptr32<void> forward_800e5cf0(Ptr32<void>, int, Ptr32<const char>, int, int);
extern "C" void d29c_part_team_tint_800da4e4(Ptr32<Part> self) {
    unsigned count;
    {
        Key k;
        k.name = active_8038976c;
        readInt_800fc1f0(&k, &count);
    }
    if (count <= 15) {
        query_800fc6dc(count);
        {
            Descriptor_80178474 descriptor;
            Handle handle;
            handle.value = 0;
            {
                Key k;
                k.name = part_8038977c;
                readRes_800fc1b0(&k, &handle.value);
            }
            Held current;
            {
                Held acquired(cast_80179598(identity_80341584(handle.value), &descriptor));
                current.assign(acquired.value);
            }
            Ptr32<Vec> v = (Ptr32<Vec>)current.value->colours.lock();
            Colour c;
            entry_800fd388(w3d::VA(&c), count);
            float r = c.r / 255.0f;
            float g = c.g / 255.0f;
            float b = c.b / 255.0f;
            v->x = r;
            v->z = b;
            v->y = g;
        }
        if (self->effect == 0) self->effect = forward_800e5cf0(empty_80343584(self->h32), group_804aae7c, part_8038977c, -1, 0);
    }
}


