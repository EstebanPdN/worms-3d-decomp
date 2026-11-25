#include "w3d_ptr.h"
#line 1 "d26k_asset_open_8021d498.cpp"
// Asset open (Worms 3D GameCube PAL, 0x8021d498).
// 
// Stores the path as the shared name at +68 (temporary built by the string
// constructor 0x8020bb54), replaces the retained object at +36, sets the kind to
// 3 and probes the file: a missing file sets state 5, otherwise the extent and
// the value read through the first property field are stored and state becomes 0.
// The zero is a local kept in a saved register across the calls.

struct String_8020bb54;
extern "C" void string_init_8020c5c0(Ptr32<String_8020bb54>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String_8020bb54>);
extern "C" void string_finish_8020c5c4(Ptr32<String_8020bb54>);
extern "C" void string_release_80341588(Ptr32<String_8020bb54>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
struct String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *s);
    String_8020bb54(const String_8020bb54 &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~String_8020bb54() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    String_8020bb54 &operator=(const String_8020bb54 &other) {
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Interface;
struct InterfaceTable {
    Ptr32<void> reserved[3];
    Ptr32<int (Ptr32<Interface>)> retain;
    Ptr32<int (Ptr32<Interface>)> release;
};
struct Interface { Ptr32<InterfaceTable> table; };
struct Ref {
    Ptr32<Interface> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Interface *)w3d_p.get()) {}
 Ref(Interface *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};
struct Asset {
    char pad0[36]; Ptr32<Interface> object; int kind; char pad1[44 - 44]; int value; int state; char pad2[60 - 52];
    int zero; int size; String_8020bb54 name;
    void setObject(Ptr32<Interface> o) {
        Ptr32<Interface> old = object;
        object = o;
        if (o) o->table->retain(o);
        if (old) old->table->release(old);
    }
};
extern "C" int probe_8021d8b4(Ptr32<const char>);
extern "C" Ptr32<Ptr32<void>> field_80240700(Ptr32<Asset>);
extern "C" int extent_8021d830(Ptr32<void>);
extern "C" int read_8021d5c4(Ptr32<void>, int);
extern "C" void w3d_d26k_asset_open_8021d498(Ptr32<Asset> self, Ptr32<Interface> object, Ptr32<const char> path) {
    int zero;
    self->name = String_8020bb54(path);
    zero = 0;
    self->setObject(object);
    self->kind = 3;
    if (probe_8021d8b4(path) == 0) {
        self->state = 5;
    } else {
        int size = extent_8021d830(*field_80240700(self));
        self->zero = zero;
        self->size = size;
        int value = read_8021d5c4(*field_80240700(self), size);
        self->value = value;
        self->state = zero;
    }
}


