#include "w3d_ptr.h"
#line 1 "d24c_payload_ctor_800ea180.cpp"
// d24c: 0x800ea180 (420 bytes). Construct a payload actor: base constructor,
// vtable 0x804101f8, clear the reference at +100 and the tables at +160..+212,
// zero the word triple at +260, construct the name string at +304, release the
// reference at +192, reset the position triples +48, +36, +72, +236, +224 from
// the shared origin, set +32 = -2, +84 = -1, +116 = 1, +300 = 1 and clear the
// remaining fields, releasing +100. Returns this. Names are inferred; statement
// order follows the original's stores. One-word String and handle classes with
// user copy constructors (d24r).
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[4]; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Words {
    int a, b, c;
    void set(int x, int y, int z) { c = z; b = y; a = x; }
};
struct StringD { Ptr32<char> text; StringD(); StringD(const StringD &); };
extern "C" Ptr32<void> string_default_803426b8(Ptr32<StringD>);
inline StringD::StringD() { string_default_803426b8(this); }
struct Payload {
    Ptr32<const void> vtable;       // +0
    unsigned char u4[28];
    int w32;                  // +32
    Words p36, p48;           // +36, +48
    unsigned char u60[12];
    Words p72;                // +72
    int w84;                  // +84
    unsigned char u88[4];
    int w92;                  // +92
    unsigned char u96[4];
    Ptr32<Object> held100;          // +100
    unsigned char u104[8];
    int w112, w116, w120;     // +112
    unsigned char u124[36];
    int t160[8];              // +160..+188
    Ptr32<Object> held192;          // +192
    int t196[5];              // +196..+212
    unsigned char u216[4];
    int w220;                 // +220
    Words p224, p236;         // +224, +236
    int w248, w252, w256;     // +248
    Words v260;               // +260
    int w272;                 // +272
    unsigned char u276[24];
    int w300;                 // +300
    StringD name;             // +304
};
extern "C" int base_80161014(Ptr32<Payload>);
extern const unsigned char vtable_804101f8[];
extern const Words origin_8045e788[];
extern "C" Ptr32<Payload> d24c_payload_ctor_800ea180(Ptr32<Payload> self) {
    int zero = 0;
    base_80161014(self);
    self->held100 = (Ptr32<Object>)w3d::G(zero);
    self->t160[0] = zero;
    self->vtable = vtable_804101f8;
    self->t160[1] = zero;
    self->t160[2] = zero;
    self->t160[3] = zero;
    self->t160[4] = zero;
    self->t160[5] = zero;
    self->t160[6] = zero;
    self->t160[7] = zero;
    self->held192 = (Ptr32<Object>)w3d::G(zero);
    self->t196[0] = zero;
    self->t196[1] = zero;
    self->t196[2] = zero;
    self->t196[3] = zero;
    self->t196[4] = zero;
    self->v260.set(zero, zero, zero);
    string_default_803426b8(&self->name);
    if (self->held192) self->held192->vtable->release(self->held192);
    self->held192 = (Ptr32<Object>)w3d::G(zero);
    self->p48 = origin_8045e788[0];
    int minus2 = -2;
    int one = 1;
    int minus1 = -1;
    self->p36 = origin_8045e788[0];
    self->p72 = origin_8045e788[0];
    self->p236 = origin_8045e788[0];
    self->p224 = origin_8045e788[0];
    self->w32 = minus2;
    self->w248 = zero;
    self->w92 = zero;
    self->w84 = minus1;
    self->w112 = zero;
    self->w116 = one;
    self->w120 = zero;
    self->w220 = zero;
    self->w256 = zero;
    self->w252 = zero;
    self->w272 = zero;
    if (self->held100) self->held100->vtable->release(self->held100);
    self->held100 = (Ptr32<Object>)w3d::G(zero);
    self->w300 = one;
    return self;
}


