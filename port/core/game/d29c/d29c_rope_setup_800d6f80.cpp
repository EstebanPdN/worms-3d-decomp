#include "w3d_ptr.h"
#line 1 "d29c_rope_setup_800d6f80.cpp"
// d29c: 0x800d6f80. Initial setup of a swinging object: places its two end points, looks up named overrides, derives span, rise and angle from them, then posts eight named animation messages. Names are inferred; classes are partial views.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e7c30(float);
struct V {
    float x, y, z;
    V() {}
    V(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    V operator-(const V &o) const { V r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
};
template <class T> inline const T &mn(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return mx(mn(hi, v), lo); }
struct Item;
struct Rope {
    char u0[4]; V b; V a; V c; char u40[40]; Ptr32<Item> h80; Ptr32<Item> h84; char u88[8]; float len; float rise; float angle;
};
extern Ptr32<void> heap_804b1754;
extern int idA_804aeab0, idB_804aeaa8;
extern char k1_803890ac[], k2_803890b8[];
extern char s1_803890c4[], s2_803890d0[], s3_803890dc[], s4_803890ec[], s5_803890f4[], s6_8038910c[], s7_8038911c[], s8_80389128[];
extern "C" float value_80178df0(Ptr32<Item>);
extern "C" int find_800d7318(Ptr32<Rope>, Ptr32<const char>, Ptr32<V>);
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> init_8010a8e0(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void d29c_rope_setup_800d6f80(Ptr32<Rope> self) {
    float zero = 0.0f;
    self->a.set(zero, zero, zero);
    self->len = value_80178df0(self->h80) + 1000.0f;
    float h = value_80178df0(self->h84);
    self->b.set(self->len, h, zero);
    find_800d7318(self, k1_803890ac, &self->a);
    find_800d7318(self, k2_803890b8, &self->b);
    V d = self->b - self->a;
    self->len = sqrt_802e82c0(d.x * d.x + d.z * d.z);
    self->rise = d.y;
    self->c.set(zero, 1.0f, zero);
    float v = (self->b.x - self->a.x) / self->len;
    self->angle = acos_802e7c30(clamp(v, -1.0f, 1.0f));
    if (self->b.z - self->a.z < zero) self->angle = 3.1415927f - self->angle;
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idA_804aeab0, 1), s1_803890c4));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idA_804aeab0, 1), s2_803890d0));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idA_804aeab0, 1), s3_803890dc));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idB_804aeaa8, 1), s4_803890ec));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idB_804aeaa8, 1), s5_803890f4));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idB_804aeaa8, 1), s6_8038910c));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idB_804aeaa8, 1), s7_8038911c));
    post_8016239c(init_8010a8e0(alloc_801613f0(heap_804b1754, 12), msg_id_8015f5a0(&idB_804aeaa8, 1), s8_80389128));
}


