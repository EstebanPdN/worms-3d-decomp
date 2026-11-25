#include "w3d_ptr.h"
#line 1 "d24c_worm_pot_physics_800e58fc.cpp"
// d24c: 0x800e58fc (364 bytes). Apply the WormPot physics settings: read the
// bounce and slide settings and the WormPot record; unless the pot's mode +76 or
// +80 is 1, read the alternate bounce and slide settings, and when asked to
// scale them multiply slide by the pot's scale (+24) and bounce by 1/scale, then
// write both back to the original settings. The pot reference is released on
// every path. Names are inferred. One-word String and handle classes with user
// copy constructors (d24r).
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
struct Pot {
    unsigned char u0[24];
    float scale;      // +24
    unsigned char u28[48];
    int mode76;       // +76
    int mode80;       // +80
};
extern "C" Ptr32<void> identity_80341584(Ptr32<void>);
extern "C" Ptr32<Pot> as_pot_801797b4(Ptr32<void>);
extern "C" int read_float_800fc270(Ptr32<Key>, Ptr32<float>);
extern "C" int write_float_800fc4c8(Ptr32<Key>, float);
extern const char bounce_8038a52c[], slide_8038a544[], pot_8038a558[], bounce2_8038a560[], slide2_8038a580[];
extern const float one_8038a59c[];
extern "C" void d24c_worm_pot_physics_800e58fc(Ptr32<void> self, int scaled) {
    Ref ref;
    ref.value = 0;
    Ptr32<const char> bounce_name = bounce_8038a52c;
    float bounce;
    { Key k; k.text = bounce_name; read_float_800fc270(&k, &bounce); }
    Ptr32<Ref> out = &ref;
    Ptr32<const char> slide_name = slide_8038a544;
    float slide;
    { Key k; k.text = slide_name; read_float_800fc270(&k, &slide); }
    { Key k; k.text = pot_8038a558; read_800fc1b0(&k, out); }
    Ptr32<Pot> pot = as_pot_801797b4(identity_80341584(ref.value));
    if (pot->mode76 == 1 || pot->mode80 == 1) return;
    { Key k; k.text = bounce2_8038a560; read_float_800fc270(&k, &bounce); }
    { Key k; k.text = slide2_8038a580; read_float_800fc270(&k, &slide); }
    if (scaled) {
        slide = slide * pot->scale;
        bounce = bounce * (one_8038a59c[0] / pot->scale);
    }
    { Key k; k.text = bounce_name; write_float_800fc4c8(&k, bounce); }
    { Key k; k.text = slide_name; write_float_800fc4c8(&k, slide); }
}


