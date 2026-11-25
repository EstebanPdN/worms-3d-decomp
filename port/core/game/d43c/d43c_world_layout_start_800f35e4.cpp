#include "w3d_ptr.h"
#line 1 "d43c_world_layout_start_800f35e4.cpp"
// d43c: 0x800f35e4. Starts a generated world from its configuration:
// replaces the handle at +888 with a new object, splits the total from the
// size table by the configured layout, sets the per-kind share table by the
// configured style, derives colour weights, clears the slots, picks a random
// enabled layer type with a nonzero share, creates and stores that first
// layer, sets its vectors and places it. Field names are inferred.
extern "C" Ptr32<void> memcpy_802eee50(...);
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
template <class T> inline const T &mn(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
struct V { float x, y, z; void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Object;
struct ObjectVtable { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Layer { char u0[28]; int type; char u32[4]; V a; V b; };
struct LayerType { char u0[56]; float f56; char u60[0]; int kind; char u64[24]; int enabled; };
struct LayerList {
    Ptr32<char> start; Ptr32<char> finish; Ptr32<char> eos;
    void push(Ptr32<Layer> const &e) {
        if (finish == eos) {
            unsigned used = finish - start;
            unsigned cap = eos - start;
            unsigned bytes = mx<int>(cap + 1, cap + cap / 2) * 4;
            Ptr32<char> mem = (Ptr32<char>)alloc_80212fd4(bytes);
            if (start != 0) {
                memcpy_802eee50(w3d::VA(mem), w3d::VA(start), mn(bytes, used));
                release_802134fc(start);
            }
            start = mem;
            finish = mem + used;
            eos = mem + bytes;
        }
        *(Ptr32<Ptr32<Layer>>)finish = e;
        finish += 4;
    }
};
struct IntList {
    Ptr32<char> start; Ptr32<char> finish; Ptr32<char> eos;
    int size() const { return (Ptr32<int>)finish - (Ptr32<int>)start; }
    int &operator[](int i) { return ((Ptr32<int>)start)[i]; }
};
struct Config { char u0[12]; unsigned u12; int u16, u20, u24; unsigned u28, u32, u36; int u40; };
struct Shares { int v[3][3]; int &operator[](int k) { return ((Ptr32<int>)this)[k]; } };
struct Self {
    char u0[44]; LayerList layers; char u56[12]; IntList slots; Ptr32<Ptr32<LayerType>> types; unsigned typeCount; char u88[800];
    Ptr32<Object> h888; char u892[96];
    Shares share; int extra[3]; int base[3]; int t1048, t1052, t1056; int bonus[3]; int u1072, u1076; char u1080[1980]; int u3060, u3064, u3068; Config cfg; char u3116[64]; int u3180, u3184, u3188;
};
extern "C" Ptr32<Object> forward_8020b680(Ptr32<const void>);
extern const unsigned char type_8041b5c8[];
extern unsigned table_8038c640[];
extern "C" void setup_800f34f8(Ptr32<Self>);
extern "C" unsigned random_800f2cec(Ptr32<Self>);
extern "C" Ptr32<Layer> create_800f55e8(Ptr32<Self>, unsigned, int);
extern "C" void place_800f5f44(Ptr32<Self>, Ptr32<Layer>);
inline Config &Cfg(Ptr32<Self> s) { return s->cfg; }
inline bool Lt(unsigned a, const unsigned &b) { return a < b; }
extern "C" void d43c_world_layout_start_800f35e4(Ptr32<Self> self) {
    int zero0 = 0;
    if (self->h888) self->h888->vtable->release(self->h888);
    self->h888 = (Ptr32<Object>)w3d::G(zero0);
    Ptr32<Object> n = forward_8020b680(type_8041b5c8);
    if (n) n->vtable->retain(n);
    if (self->h888) self->h888->vtable->release(self->h888);
    self->h888 = n;
    self->u3180 = zero0;
    setup_800f34f8(self);
    Config &c = self->cfg;
    unsigned total = table_8038c640[c.u24];
    unsigned a, b, d;
    switch (c.u32) {
    case 0: b = total / 2; d = 0; a = b; break;
    case 1: d = 0; a = total / 3; b = total * 8 / 12; break;
    case 2: b = total / 2; a = total / 3; d = total / 6; break;
    case 3: a = total / 4; b = total / 2; d = a; break;
    case 4: b = total / 2; a = total / 6; d = total / 3; break;
    case 5: a = total / 12; b = total / 3; d = total * 7 / 12; break;
    case 6: a = total / 12; d = total * 8 / 12; b = total / 4; break;
    }
    int t27, t18, t23;
    switch (Cfg(self).u36) {
    case 0:
        t23 = 0; t27 = 0; t18 = 0;
        self->extra[0] = a / 2; self->extra[1] = b / 2; self->extra[2] = d / 2;
        self->share.v[0][0] = a; self->share.v[1][0] = b; self->share.v[2][0] = d;
        self->share.v[0][1] = t23; self->share.v[0][2] = t23; self->share.v[1][1] = t23; self->share.v[1][2] = t23; self->share.v[2][1] = t23; self->share.v[2][2] = t23;
        break;
    case 1: {
        unsigned ha = a / 2, hb = b / 2, hd = d / 2;
        t23 = 0; t27 = 3; t18 = 1;
        self->extra[0] = ha; self->extra[1] = hb; self->extra[2] = hd;
        self->share.v[0][0] = ha; self->share.v[0][1] = ha; self->share.v[0][2] = t23;
        self->share.v[1][0] = hb; self->share.v[1][1] = hb; self->share.v[1][2] = t23;
        self->share.v[2][0] = hd; self->share.v[2][1] = hd; self->share.v[2][2] = t23;
        break;
    }
    case 2: {
        t27 = 3; t18 = 3; t23 = 1;
        unsigned ha = a / 3, hb = b / 3, hd = d / 3;
        self->extra[0] = ha; self->extra[1] = hb; self->extra[2] = hd;
        self->share.v[0][0] = ha; self->share.v[0][1] = ha; self->share.v[0][2] = ha;
        self->share.v[1][0] = hb; self->share.v[1][1] = hb; self->share.v[1][2] = hb;
        self->share.v[2][0] = hd; self->share.v[2][1] = hd; self->share.v[2][2] = hd;
        break;
    }
    case 3: {
        t27 = 0;
        unsigned ha = a / 2, hb = b / 2, hd = d / 2;
        self->extra[0] = a / 4; self->extra[1] = b / 4; self->extra[2] = d / 4;
        t18 = 6; t23 = 6;
        self->share.v[0][0] = t27; self->share.v[0][1] = ha; self->share.v[0][2] = ha;
        self->share.v[1][0] = t27; self->share.v[1][1] = hb; self->share.v[1][2] = hb;
        self->share.v[2][0] = t27; self->share.v[2][1] = hd; self->share.v[2][2] = hd;
        break;
    }
    case 4:
        t27 = 0;
        self->share.v[0][2] = a; self->share.v[1][2] = b; self->share.v[2][2] = d;
        t18 = 6;
        self->share.v[0][0] = t27; self->share.v[0][1] = t27;
        t23 = 10;
        self->extra[0] = a / 5; self->extra[1] = b / 5; self->extra[2] = d / 5; self->share.v[1][0] = t27; self->share.v[1][1] = t27; self->share.v[2][0] = t27; self->share.v[2][1] = t27;
        break;
    }
    self->t1048 = t27; self->t1052 = t18; self->t1056 = t23;
    int r, g, l;
    switch (Cfg(self).u28) {
    case 0: r = 200; g = 100; l = 0; break;
    case 1: r = 100; g = 100; l = 100; break;
    case 2: r = 0; g = 100; l = 200; break;
    }
    unsigned r1, g1, l1, r2, g2, l2;
    switch (Cfg(self).u12) {
    case 0: r1 = r; g1 = g; l1 = l; r2 = 0; g2 = 0; l2 = 0; break;
    case 1: r1 = (unsigned)(r * 3) / 5; g1 = (unsigned)(g * 3) / 5; l1 = (unsigned)(l * 3) / 5; r2 = (unsigned)(r * 2) / 5; g2 = (unsigned)(g * 2) / 5; l2 = (unsigned)(l * 2) / 5; break;
    case 2: r1 = (unsigned)(r * 2) / 5; g1 = (unsigned)(g * 2) / 5; l1 = (unsigned)(l * 2) / 5; r2 = (unsigned)(r * 3) / 5; g2 = (unsigned)(g * 3) / 5; l2 = (unsigned)(l * 3) / 5; break;
    case 3: r1 = (unsigned)r / 5; g1 = (unsigned)g / 5; l1 = (unsigned)l / 5; r2 = (unsigned)(r * 4) / 5; g2 = (unsigned)(g * 4) / 5; l2 = (unsigned)(l * 4) / 5; break;
    }
    self->base[0] = r1; self->base[1] = g1; self->base[2] = l1;
    self->bonus[0] = r2 + r2; self->bonus[1] = g2 + g2; self->bonus[2] = l2 + l2;
    self->u3184 = Cfg(self).u20 * 80;
    self->u3188 = Cfg(self).u16 * 20;
    self->u1076 = 0; self->u1072 = 0;
    unsigned i;
    for (i = 0; i < self->slots.size(); i++) self->slots[i] = 0;
    self->u3068 = Cfg(self).u40;
    unsigned count = 0;
    {
        unsigned n2 = self->typeCount;
        for (i = 0; Lt(i, n2); i++) {
            Ptr32<LayerType> t = self->types[i];
            if (t->enabled && self->share.v[0][t->kind] > 0) count++;
        }
    }
    i = 0;
    count = random_800f2cec(self) % count;
    Ptr32<Layer> layer;
    for (; i < self->typeCount; i++) {
        Ptr32<LayerType> t = self->types[i];
        if (t->enabled && self->share.v[0][t->kind] > 0) {
            if (count == 0) layer = create_800f55e8(self, i, 1);
            count--;
        }
    }
    self->layers.push(layer);
    float zero = 0.0f, tilt = 0.7853982f;
    layer->a.set(zero, self->types[layer->type]->f56, zero);
    layer->b.set(zero, tilt, zero);
    place_800f5f44(self, layer);
    self->u3060 = 20;
    self->u3064 = 0;
}


