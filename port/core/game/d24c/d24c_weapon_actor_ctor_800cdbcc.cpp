#include "w3d_ptr.h"
#line 1 "d24c_weapon_actor_ctor_800cdbcc.cpp"
// d24c: 0x800cdbcc (412 bytes). Construct a weapon actor: base constructor,
// vtable 0x8040fc08, zero the word triple at +28 and the 32-word table at +128,
// construct the handle member at +308, then set its fields: +44 = 0, +48 = -1,
// the position triples +52, +64, +276, +296 from the shared origin, +116 = 1,
// +292 = -1, the float fields +96, +100, +108, +112, +268, +288 from the pool
// float, and clear +40, +88, +92, +120, +124. Returns this. Names are inferred;
// the order of the assignments was chosen to reproduce the original's store
// order. One-word String and handle classes with user copy constructors (d24r).
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

struct Words {
    int a, b, c;
    void set(int x, int y, int z) { c = z; b = y; a = x; }
};
struct Actor {
    Ptr32<const void> vtable;       // +0
    unsigned char u4[24];
    Words v28;                // +28
    int w40, w44, w48;        // +40
    Words p52, p64;           // +52, +64
    unsigned char u76[12];
    int w88, w92;             // +88
    float f96, f100;          // +96
    unsigned char u104[4];
    float f108, f112;         // +108
    int w116, w120, w124;     // +116
    int w[32];                // +128..+252
    unsigned char u256[12];
    float f268;               // +268
    unsigned char u272[4];
    Words p276;               // +276
    float f288;               // +288
    int w292;                 // +292
    Words p296;               // +296
    unsigned char member[4];  // +308
};
extern "C" int base_80161014(Ptr32<Actor>);
extern "C" Ptr32<void> member_80126184(Ptr32<void>);
extern const unsigned char vtable_8040fc08[];
extern const Words origin_8045e788[];
extern const float one_80387ef0[];
extern "C" Ptr32<Actor> d24c_weapon_actor_ctor_800cdbcc(Ptr32<Actor> self) {
    int zero = 0;
    base_80161014(self);
    self->vtable = vtable_8040fc08;
    self->v28.set(zero, zero, zero);
    self->w[0] = zero;
    self->w[1] = zero;
    self->w[2] = zero;
    self->w[3] = zero;
    self->w[4] = zero;
    self->w[5] = zero;
    self->w[6] = zero;
    self->w[7] = zero;
    self->w[8] = zero;
    self->w[9] = zero;
    self->w[10] = zero;
    self->w[11] = zero;
    self->w[12] = zero;
    self->w[13] = zero;
    self->w[14] = zero;
    self->w[15] = zero;
    self->w[16] = zero;
    self->w[17] = zero;
    self->w[18] = zero;
    self->w[19] = zero;
    self->w[20] = zero;
    self->w[21] = zero;
    self->w[22] = zero;
    self->w[23] = zero;
    self->w[24] = zero;
    self->w[25] = zero;
    self->w[26] = zero;
    self->w[27] = zero;
    self->w[28] = zero;
    self->w[29] = zero;
    self->w[30] = zero;
    self->w[31] = zero;
    member_80126184(self->member);
    int minus = -1;
    self->w44 = zero;
    self->w48 = minus;
    self->p52 = origin_8045e788[0];
    int one = 1;
    Ptr32<Words> p = &self->p296;
    self->p64 = origin_8045e788[0];
    float f = one_80387ef0[0];
    self->p276 = origin_8045e788[0];
    self->w116 = one;
    self->f96 = f;
    self->f100 = f;
    self->f108 = f;
    self->f112 = f;
    self->w88 = zero;
    self->w92 = zero;
    self->f268 = f;
    self->f288 = f;
    self->w292 = minus;
    self->w40 = zero;
    *p = origin_8045e788[0];
    self->w120 = zero;
    self->w124 = zero;
    return self;
}


