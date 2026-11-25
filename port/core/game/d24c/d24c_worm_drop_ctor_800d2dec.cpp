#include "w3d_ptr.h"
#line 1 "d24c_worm_drop_ctor_800d2dec.cpp"
// d24c: 0x800d2dec (376 bytes). Construct a worm-drop state: base constructor
// with the first and third arguments, vtable at +72, clear +136 and the
// reference at +204, zero the vectors at +140, +152, +164, set the block
// +176..+192 to (0, 0, 0, 1, 1), clear the flag +200, set the axis vectors at
// +76..+124 to zero, (k, 0, 0), (0, k, 0), zero, zero, then read the "Worm.Drop"
// setting into the reference. Returns this. Names are inferred. One-word String
// and handle classes with user copy constructors (d24r).
typedef unsigned int size_t;
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> text; };
extern "C" int read_800fc1b0(Ptr32<Key>, Ptr32<void>);

struct Ref {
    Ptr32<Object> value;
    Ref() {}
    Ref(const Ref &o) : value(o.value) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Drop {
    unsigned char u0[72];
    Ptr32<const void> vtable;  // +72
    Vec3 v76, v88, v100, v112, v124;
    int w136;            // +136
    Vec3 v140, v152, v164;
    float f176, f180, f184, f188, f192;
    unsigned char u196[4];
    unsigned char b200;  // +200
    Ptr32<Object> ref;         // +204
};
extern "C" int base_8015a0d4(Ptr32<Drop>, int, int);
extern "C" Ptr32<Object> as_a_80342a74(Ptr32<Object>);
extern const unsigned char vtable_8040fc90[];
extern const float z_80388cac[], one_80388cb0[], k_80388cb4[];
extern const char name_80388c94[];
extern "C" Ptr32<Drop> d24c_worm_drop_ctor_800d2dec(Ptr32<Drop> self, int a, int unused, int b) {
    base_8015a0d4(self, a, b);
    self->vtable = vtable_8040fc90;
    self->w136 = 0;
    self->ref = 0;
    float z = z_80388cac[0];
    self->v140.set(z, z, z);
    self->v152.set(z, z, z);
    self->v164.set(z, z, z);
    float one = one_80388cb0[0];
    self->f176 = z;
    self->f180 = z;
    self->f184 = z;
    self->f188 = one;
    self->f192 = one;
    self->b200 = 0;
    self->v76.set(z, z, z);
    float k = k_80388cb4[0];
    self->v88.set(k, z, z);
    self->v100.set(z, k, z);
    self->v112.set(z, z, z);
    self->v124.set(z, z, z);
    {
        Key key;
        key.text = name_80388c94;
        Ref r;
        r.value = 0;
        read_800fc1b0(&key, &r);
        Ptr32<Object> o = as_a_80342a74(r.value);
        if (o) o->vtable->retain(o);
        if (self->ref) self->ref->vtable->release(self->ref);
        self->ref = o;
    }
    return self;
}


