#include "w3d_ptr.h"
#line 1 "d32d_worm_spawn_place_80157c58.cpp"
// GWMP8P rev0 0x80157c58. Places a worm when the level asks for it. For the
// spawn action, takes a random stored spawn point when any is left, otherwise
// tries up to 100 random land cells until a collision probe stays clear,
// then falls back to a random spot around the land centre. Other actions post
// a message and copy the current camera vectors. Finally stores the position
// and the heading towards the given target. Names are inferred.
extern "C" void string_base_init_8020c5c0(Ptr32<void>);
extern "C" void string_finish_8020c5c4(Ptr32<void>);
extern "C" void string_release_80341588(Ptr32<void>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<void>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void memcpy_802eee50(...);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    ~String_803426b8() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String_803426b8(const String_803426b8 &);
};
typedef String_803426b8 String;
struct Str {
    Ptr32<char> text;
    Str(const Str &o) { string_base_init_8020c5c0(this); text = o.text; ++*string_header_80341884(this); }
    ~Str() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Plain { float x, y, z; };
struct Point : Plain {
    Point &operator=(const Plain &o) { Plain::operator=(o); return *this; }
    Point &operator=(const Point &o) { Plain::operator=(o); return *this; }
};
struct Vec : Plain {
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Row { float x, y, z; };
struct Mat {
    Row r[3]; Row pos;
    const Row &R(int i) const { return r[i]; }
    const Row &P() const { return pos; }
};
struct Mat36;
extern "C" Ptr32<const Row> record12_at_80343bb4(Ptr32<const Mat36>, int);
struct Mat36 { float v[9]; };
extern "C" void axis_801f7538(Ptr32<Mat>, float, float, float, float);
extern "C" void euler_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat36>);
struct Item { void w3d_r_s2() __asm__(W3D_SYM("_ZN4Item2s2Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN4Item6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN4Item7releaseEv"));  __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Item; };
struct Local {
    Ptr32<Item> p;
    template <class W3dU> Local(Ptr32<W3dU> w3d_p) : Local((Item *)w3d_p.get()) {}
 Local(Item *e) { p = e; if (e) e->retain(); }
    Local(const Local &);
    ~Local() { if (p) p->release(); }
};
struct Descriptor_80178474 {
    int a;
    int id;
    Descriptor_80178474() { a = 0; id = 0xe3a8; }
    ~Descriptor_80178474();
};
typedef Descriptor_80178474 Descriptor;
struct Key { Ptr32<const char> text; };
struct Actor : Item { char u4[64] __attribute__((aligned(__alignof__(Item)))); Point rot; Point pos; char u92[60]; Str action; };
extern "C" Ptr32<Item> handle_800fc710(int, Ptr32<Descriptor>);
extern "C" int read_float_800fc270(Ptr32<Key>, Ptr32<float>);
extern "C" int read_vec_800fc2f0(Ptr32<Key>, Ptr32<Vec>);
extern "C" unsigned random_80162ba8();
extern "C" float frandom_80162bc8();
/* Constructor 0x80126184, destructor 0x80126230. */
struct Handle {
    char u[8];
    Handle();
    ~Handle();
};
extern "C" void handle_mask_8012632c(Ptr32<Handle>, int);
extern "C" void handle_slot_801262e4(Ptr32<Handle>, int);
extern "C" void handle_radius_8012629c(Ptr32<Handle>, float);
extern "C" void handle_pos_801262c0(Ptr32<Handle>, Ptr32<Vec>);
extern "C" void handle_run_80126334(Ptr32<Handle>);
extern "C" int handle_next_801264fc(Ptr32<Handle>);
extern "C" void handle_reset_80126524(Ptr32<Handle>);
struct Grid;
extern "C" int next_8001dd28(Ptr32<Grid>, Ptr32<short>, Ptr32<short>, Ptr32<int>);
struct Cell { short x, y; ~Cell() {} };
inline int Next(Ptr32<Grid> g, Cell &c, int &l) { return next_8001dd28(g, &c.x, &c.y, &l); }
extern Ptr32<Grid> grid_804b1758;
extern "C" Vec sample_8001e224(Ptr32<Grid>, int, int, int);
struct Message;
extern Ptr32<void> heap_804b1754;
extern "C" Ptr32<Message> alloc_801613f0(Ptr32<void>, int);
extern int id_804afe90;
extern "C" int id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<Message> init_800683fc(Ptr32<Message>, unsigned short, Ptr32<char>, Ptr32<const char>);
extern "C" int post_8016239c(Ptr32<Message>);
extern "C" Ptr32<void> empty_80342fa4(Ptr32<void>);
extern "C" Ptr32<Vec> vec_80178ec4(Ptr32<void>);
extern "C" float atan2_802e7e5c(float, float);
struct List { Ptr32<Row> begin; Ptr32<Row> end; };
inline void erase(Ptr32<List> l, int off) {
    Ptr32<Row> pos = (Ptr32<Row>)w3d::G((off + (int)w3d::H(l->begin)));
    Ptr32<Row> next = pos + 1;
    if (next != l->end) { Ptr32<char> last = (Ptr32<char>)l->end - 12; memcpy_802eee50(w3d::VA(pos), w3d::VA(next), last - (Ptr32<char>)pos); };
    l->end--;
}
extern const char spawn_803a2c3c[], zoffset_803a2c44[], center_803a2c5c[];
struct Self { char u0[40]; Ptr32<void> a; Ptr32<void> b; };
inline float DotX(Ptr32<const Mat36> m, const Vec &s) {
    Ptr32<const Row> a = record12_at_80343bb4(m, 0);
    Ptr32<const Row> b = record12_at_80343bb4(m, 1);
    Ptr32<const Row> c = record12_at_80343bb4(m, 2);
    return s.x * a->x + s.y * b->x + s.z * c->x;
}
inline float DotY(Ptr32<const Mat36> m, const Vec &s) {
    Ptr32<const Row> a = record12_at_80343bb4(m, 0);
    Ptr32<const Row> b = record12_at_80343bb4(m, 1);
    Ptr32<const Row> c = record12_at_80343bb4(m, 2);
    return s.x * a->y + s.y * b->y + s.z * c->y;
}
inline float DotZ(Ptr32<const Mat36> m, const Vec &s) {
    Ptr32<const Row> a = record12_at_80343bb4(m, 0);
    Ptr32<const Row> b = record12_at_80343bb4(m, 1);
    Ptr32<const Row> c = record12_at_80343bb4(m, 2);
    return s.x * a->z + s.y * b->z + s.z * c->z;
}
extern "C" void w3d_d32d_worm_spawn_place_80157c58(Ptr32<Self> self, Ptr32<const char> name, Ptr32<List> la, Ptr32<List> lb) {
    String none;
    float zero = 0.0f;
    Vec spin;
    Ptr32<Vec> ps = &spin;
    spin.x = zero;
    ps->y = zero;
    ps->z = zero;
    Vec pos;
    Vec rot;
    Descriptor desc;
    Local actor(handle_800fc710((int)w3d::H(name), &desc));
    Str action = ((Ptr32<Actor>)actor.p)->action;
    int count = la->end - la->begin;
    if (strcmp(action.text, spawn_803a2c3c) == 0) {
        if (count == 0) {
            float angle = (float)(unsigned char)random_80162ba8() * 0.024543693f;
            Ptr32<Vec> pr = &rot;
            rot.x = zero;
            rot.y = angle;
            pr->z = zero;
            Vec local;
            local.x = zero;
            local.y = 10.0f;
            Key k1 = { zoffset_803a2c44 };
            read_float_800fc270(&k1, &local.z);
            Vec base;
            Mat m;
            axis_801f7538(&m, zero, 1.0f, zero, rot.y);
            const Row &x = m.R(0), &y = m.R(1), &z = m.R(2), &w = m.P();
            base.x = local.x * x.x + local.y * y.x + local.z * z.x + w.x;
            base.y = local.x * x.y + local.y * y.y + local.z * z.y + w.y;
            base.z = local.x * x.z + local.y * y.z + local.z * z.z + w.z;
            Handle h;
            handle_mask_8012632c(&h, -1);
            handle_slot_801262e4(&h, 0);
            handle_radius_8012629c(&h, 10.0f);
            Cell cell;
            int layer;
            unsigned tries = 0;
            int clear = 0;
            while (!clear && tries < 100 && next_8001dd28(grid_804b1758, &cell.x, &cell.y, &layer)) {
                tries++;
                pos = sample_8001e224(grid_804b1758, cell.x, cell.y, layer);
                pos.x += base.x;
                pos.y = pos.y + base.y + 10.0f;
                pos.z += base.z;
                handle_pos_801262c0(&h, &pos);
                handle_run_80126334(&h);
                clear = (handle_next_801264fc(&h) ^ 0xffff) == 0;
                handle_reset_80126524(&h);
            }
            if (!clear) {
            Key k2 = { center_803a2c5c };
            read_vec_800fc2f0(&k2, &pos);
            Key k3 = { "Land.MaxHeight" };
            read_float_800fc270(&k3, &pos.y);
            pos.x += (frandom_80162bc8() - 0.5f) * 100.0f;
            pos.z += (frandom_80162bc8() - 0.5f) * 100.0f;
            pos.y += 10.0f;
            }
        } else {
            int off = random_80162ba8() % count * 12;
            pos = *(Ptr32<Vec>)((Ptr32<char>)la->begin + off);
            rot = *(Ptr32<Vec>)((Ptr32<char>)lb->begin + off);
            erase(la, off);
            erase(lb, off);
        }
    } else {
        post_8016239c(init_800683fc(alloc_801613f0(heap_804b1754, 12), id_8015f5a0(&id_804afe90, 1), action.text, name));
        pos = *vec_80178ec4(empty_80342fa4(self->a));
        rot = *vec_80178ec4(empty_80342fa4(self->b));
    }
    ((Ptr32<Actor>)actor.p)->pos = pos;
    Mat36 m;
    euler_801a3eb0(&rot, 0, &m);
    float z2 = 0.0f;
    Vec fwd;
    Ptr32<Vec> pf = &fwd;
    fwd.x = 1.0f;
    pf->y = z2;
    pf->z = z2;
    Vec dir;
    dir.x = DotX(&m, fwd);
    dir.y = DotY(&m, fwd);
    dir.z = DotZ(&m, fwd);
    Vec heading;
    Ptr32<Vec> ph = &heading;
    heading.x = z2;
    ph->y = z2;
    ph->z = z2;
    heading.y = z2 - atan2_802e7e5c(dir.z, dir.x);
    ((Ptr32<Actor>)actor.p)->rot = heading;
}


