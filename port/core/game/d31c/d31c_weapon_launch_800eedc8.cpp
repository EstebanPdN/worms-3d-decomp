#include "w3d_ptr.h"
#line 1 "d31c_weapon_launch_800eedc8.cpp"
// d31c: 0x800eedc8. Weapon launch: creates the projectile class named by the weapon, sets aim (AI velocity or shot power through the launch euler), optional launch location offset from the worm, and adds it to the world. Names are inferred; classes are partial views.
// Weapon launch: creates the projectile class for the weapon, sets velocity, direction and launch location.
extern "C" float sqrt_802e82c0(float);
extern "C" float sinf_802e88ac(float);
extern "C" float cosf_802e86d4(float);
struct W { int a, b, c; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float d31c_weapon_launch_800eedc8 = 1.0f / len(); x *= d31c_weapon_launch_800eedc8; y *= d31c_weapon_launch_800eedc8; z *= d31c_weapon_launch_800eedc8; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    Vec &operator*=(float k) { x *= k; y *= k; z *= k; return *this; }
    bool operator==(const Vec &o) const { return *(Ptr32<int>)&x == *(Ptr32<int>)&o.x && *(Ptr32<int>)&y == *(Ptr32<int>)&o.y && *(Ptr32<int>)&z == *(Ptr32<int>)&o.z; }
};
inline Vec operator*(const Vec &a, float s) { Vec r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Row { float x, y, z; };
struct Mat { Row row[3]; const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    } };
struct Info { int w[4]; };
struct Object;
struct ObjectVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; Ptr32<void> u20[5]; Ptr32<void (Ptr32<Object>, Ptr32<const Vec>)> dir; };
struct Object { Ptr32<ObjectVt> vt; char u4[28]; int u32; char u36[76]; int u112; };
struct Own {
    Ptr32<Object> p;
    template <class W3dU> Own(Ptr32<W3dU> w3d_p) : Own((Object *)w3d_p.get()) {}
 Own(Object *q) { p = q; if (q) q->vt->retain(q); }
    Own(const Own &);
    ~Own() { if (p) p->vt->release(p); }
};
struct Weapon;
struct WeaponVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Weapon>)> retain; Ptr32<void> u16[4]; Ptr32<Ptr32<const char> (Ptr32<Weapon>)> name; };
struct Key { Ptr32<const char> name; };
struct Desc { char u0[184]; float f184, f188; char u192[88]; float f280; char u284[180]; int u464; char u468[28]; int u496; char u500[4]; int u504; char u508[24]; int u532; int u536; };
struct Worm { char u0[44]; Vec v44; char u56[16]; float f72; char u76[4]; Vec pos; char u92[20]; int u112; float f116; char u120[93]; unsigned char team; char u214[2]; int u216; };
struct Team { char u0[52]; int ai; };
struct Self { char u0[28]; Ptr32<Object> owner; };
struct Message { unsigned short id; Ptr32<void> text; };
struct Clock { char u0[20]; int now; };
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> cast_801797b4(Ptr32<void>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const Info>);
extern "C" void assign_800eb65c(Ptr32<Object>, Own);
extern "C" int read_int_800fc1f0(Ptr32<Key>, Ptr32<int>);
extern "C" Ptr32<Worm> worm_800fc6dc(int);
extern "C" Ptr32<Team> team_800fc7f8(int);
extern "C" int read_vec_800fc2f0(Ptr32<Key>, Ptr32<Vec>);
extern "C" int read_float_800fc270(Ptr32<Key>, Ptr32<float>);
extern "C" void euler_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
extern "C" void velocity_800eb8f0(Ptr32<Object>, Ptr32<const Vec>);
extern "C" void position_800eb8d0(Ptr32<Object>, Ptr32<const Vec>);
extern "C" void pending_800ecec0(Ptr32<Object>, Ptr32<const Vec>);
extern "C" Ptr32<Message> arena_801613f0(Ptr32<void>, int);
extern "C" short cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Message>);
extern "C" int add_80164514(Ptr32<void>, Ptr32<Object>, int);
extern Ptr32<void> arena_804b1754; extern Ptr32<void> world_804b178c;
extern Ptr32<Clock> clock_804aab4c;
extern char cache_804aefb4;
extern char empty_8040db38[];
extern Info i_8040ebf8[], i_8040f3e8[], i_8040ec68[], i_80410cc0[], i_8040f750[], i_8040fd78[];
extern const char s_donkey_8038b9cc[], s_missile_8038b8f8[], s_pidgeon_8038b920[], s_ball_8038bdb0[], s_cow_8038b9ac[], s_woman_8038b9bc[], s_sheep_8038b94c[], s_super_8038ba20[];
extern const char s_index_8038bd9c[], s_vel_8038bdc4[], s_power_8038be20[], s_eye_8038be2c[], s_loc_8038be40[];
extern Vec zero_8045e788[], forward_804494b0[];
struct OwnerV { Ptr32<void> u[8]; Ptr32<Ptr32<const char> (Ptr32<Object>)> name; };
static inline Ptr32<const char> owner_name(Ptr32<Object> o) { return ((Ptr32<OwnerV>)o->vt)->name(o); }
extern "C" void d31c_weapon_launch_800eedc8(Ptr32<Self> self) {
    Ptr32<Desc> d = cast_801797b4(empty_80341584(self->owner));
    Ptr32<const char> name = owner_name(self->owner);
    Info info;
    if (!strcmp_802ef234(name, s_donkey_8038b9cc)) info = i_8040ebf8[0];
    else if (!strcmp_802ef234(name, s_missile_8038b8f8) || !strcmp_802ef234(name, s_pidgeon_8038b920)) info = i_8040f3e8[0];
    else if (!strcmp_802ef234(name, s_ball_8038bdb0)) info = i_8040ec68[0];
    else if (!strcmp_802ef234(name, s_cow_8038b9ac) || !strcmp_802ef234(name, s_woman_8038b9bc)) info = i_80410cc0[0];
    else if (!strcmp_802ef234(name, s_sheep_8038b94c) || !strcmp_802ef234(name, s_super_8038ba20)) info = i_8040f750[0];
    else info = i_8040fd78[0];
    Own p(create_8020b680(&info));
    assign_800eb65c(p.p, Own(self->owner));
    Vec dir, vel, e;
    Ptr32<Vec> pe = &e;
    Key k1; k1.name = s_index_8038bd9c;
    int index;
    read_int_800fc1f0(&k1, &index);
    Ptr32<Worm> worm = worm_800fc6dc(index);
    *(Ptr32<W>)pe = *(Ptr32<W>)zero_8045e788;
    if (d->u504) e.x = -worm->f116;
    if (d->u496) e.y = worm->f72;
    Ptr32<Vec> pd; Ptr32<Vec> pv;
    if (team_800fc7f8(worm->team)->ai) {
        Key k; k.name = s_vel_8038bdc4;
        Ptr32<Vec> a = &vel;
        read_vec_800fc2f0(&k, a);
        Ptr32<Vec> q = &dir;
        *(Ptr32<W>)q = *(Ptr32<W>)a;
        pd = q;
        pv = a;
        float s = dir.lenSq();
        if (s == 0.0f) {
            owner_name(self->owner);
            dir.x = 0.0f; pd->z = 0.0f; pd->y = 1.0f;
        } else {
            float i = 1.0f / sqrt_802e82c0(s);
            dir.x *= i; dir.y *= i; dir.z *= i;
        }
    } else {
        float power = d->f188;
        if (d->u464) {
            Key k; k.name = s_power_8038be20;
            float v;
            read_float_800fc270(&k, &v);
            float scale = d->f184;
            power += v * scale;
        }
        Mat m;
        euler_801a3eb0(pe, 0, &m);
        m.rotate(dir, forward_804494b0[0]);
        pd = &dir;
        Ptr32<Vec> q = &vel;
        *(Ptr32<W>)q = *(Ptr32<W>)&(dir * power);
        pv = q;
    }
    Vec ofs(zero_8045e788[0]);
    if (d->u532) {
        *(Ptr32<W>)&ofs = *(Ptr32<W>)&worm->v44;
        vel += ofs;
    }
    velocity_800eb8f0(p.p, pv);
    p.p->vt->dir(p.p, pd);
    if (d->u532) {
        Key k; k.name = s_eye_8038be2c;
        Vec off;
        read_float_800fc270(&k, &off.y);
        off.z = d->f280;
        off.x = 0.0f;
        Vec rot;
        rot.x = off.z * sinf_802e88ac(e.y);
        rot.z = off.z * cosf_802e86d4(e.y);
        rot.y = off.y;
        Vec launch;
        Vec base(worm->pos);
        {
            Vec at = base + rot;
            launch = at;
        }
        if (!(ofs == zero_8045e788[0])) {
            Vec n(ofs);
            n.normalize();
            n *= 30.0f;
            launch += n;
        }
        position_800eb8d0(p.p, &launch);
        Ptr32<Message> m = arena_801613f0(arena_804b1754, 8);
        m->id = cached_id_8015f5a0(&cache_804aefb4, 1);
        m->text = empty_8040db38;
        post_8016239c(m);
        Key k2; k2.name = s_loc_8038be40;
        Vec at;
        read_vec_800fc2f0(&k2, &at);
        Vec g = at - launch;
        Ptr32<Vec> pg = &g;
        pg->x = 0.0f; pg->y = 0.0f; pg->z = 0.0f;
        pending_800ecec0(p.p, pg);
    }
    p.p->u112 = worm->u216;
    if (d->u536) p.p->u32 = worm->u112 * 1000;
    add_80164514(world_804b178c, p.p, clock_804aab4c->now);
}


