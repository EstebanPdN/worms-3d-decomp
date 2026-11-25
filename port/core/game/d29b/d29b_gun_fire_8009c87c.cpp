#include "w3d_ptr.h"
#line 1 "d29b_gun_fire_8009c87c.cpp"
/* Gun fire body (0x8009c87c): under a guarded static forward vector (0, 0, 1), reads the shot source,
 * posts the launch message, reads Weapon.GraphicalLaunchLocation and binds the effect, builds the muzzle
 * position from the worm position, eye level and weapon offset, forms the spread aim from the weapon tilt
 * and random values (0x80162bc8) through 0x801a3eb0, then sweeps land (0x800b0824), water (0x800419cc) and
 * worm spheres (0x801263fc). The nearest of the three decides the arm: land plays the sound, adds land
 * damage and posts an explosion; a worm hit plays the sound, optionally deflects the direction, computes
 * damage (the health-reducing loop or damage times shots) and posts an explosion plus poison or a plain
 * damage message; water plays its sound. Field names are inferred from the original instructions; class
 * layouts are partial views. Owns the Worm.Poison.Default string and the literals at 0x80380250..0x803802a0;
 * the other strings are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<void> vtable; };
extern "C" char lbl_8040db38[];
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern Ptr32<void> lbl_804b1754;
extern MessageCache lbl_804ae030, lbl_804ae0a0;
static inline void Post(Ptr32<MessageCache> c) {
    Ptr32<Message> m = (Ptr32<Message>)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(c, 1);
    m->vtable = lbl_8040db38;
    w3d_message_post_8016239c(m);
}
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    void Scale(float f) { x *= f; y *= f; z *= f; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator*(const Vec &a, const Vec &b) { Vec r; r.x = a.x * b.x; r.y = a.y * b.y; r.z = a.z * b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Str { Ptr32<const char> p; unsigned short Length() const { return ((Ptr32<const unsigned short>)p)[-2]; } };
struct PropertyKey { Ptr32<const char> name; template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) : name(n) {} };
struct Weapon {
    char unknown00[152]; unsigned char b152, b153; char unknown154[10];
    Vec muzzle; Vec tilt; float inaccuracy; char unknown192[4]; int range; char unknown200[16]; float f216; float f220; float poison; float damage;
    char unknown232[16]; Str waterSound; Str landSound; Str hitSound; char unknown260[24];
    float offsetY; float f288; float f292; float f296; char unknown300[4];
    int randomPitch; int reduce; char unknown312[4]; int deflect; int bind; int landDamage;
};
struct Worm { char unknown00[72]; float yaw; char unknown76[4]; Vec pos; char unknown92[24]; float pitch; char unknown120[24]; float yawAdd; float pitchAdd;
    char unknown152[12]; int health; char unknown168[2]; unsigned short maxHealth; };
struct Holder { char unknown00[584]; int index; };
struct Active { char unknown00[20]; int flags; int handle; };
struct Gun { char unknown00[40]; Ptr32<void> weapon; char unknown44[28]; Vec hit; char unknown84[8]; Ptr32<void> spheres; char unknown96[20]; int cooldown; };
extern "C" Ptr32<void> w3d_empty_80342a74(Ptr32<void>);
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" int w3d_read_vec_800fc2f0(Ptr32<PropertyKey>, Ptr32<Vec>);
extern "C" int w3d_read_float_800fc270(Ptr32<PropertyKey>, Ptr32<float>);
extern "C" int w3d_write_int_800fc43c(Ptr32<PropertyKey>, int);
extern "C" void w3d_bind_effect_8009d6d4(Ptr32<Gun>, Ptr32<Weapon>, Ptr32<Vec>);
extern "C" int w3d_forward_800fdc80(int, int, Ptr32<const Vec>, int, int, int);
extern "C" float w3d_random_80162bc8();
extern "C" void w3d_euler_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
extern "C" void trace_800b0824(Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, int, int);
extern "C" int w3d_water_800419cc(Ptr32<float>, Ptr32<const Vec>, Ptr32<const Vec>, float, Ptr32<const Vec>);
extern "C" void w3d_query_801262c0(Ptr32<void>, Ptr32<const Vec>);
extern "C" int w3d_active_actor_80156f88(Ptr32<void>);
extern "C" int d19c_nearest_sphere_801263fc(Ptr32<void>, Ptr32<const Vec>, int, int);
extern "C" int effect_800e5ca4(Ptr32<const Vec>, Ptr32<const char>, int, float);
extern "C" int w3d_land_damage_add_8009d430(Ptr32<Gun>, float);
struct Explosion;
extern "C" Ptr32<Explosion> w3d_explosion_800666b4(Ptr32<void>, const Vec &, const Vec &, float, float, float, float, float);
extern "C" Ptr32<Active> w3d_active_8003f240(unsigned short);
extern "C" Ptr32<Holder> w3d_lookup_80164fc8(int);
extern "C" Ptr32<Worm> w3d_worm_800fc6dc(int);
extern "C" Ptr32<void> w3d_message_int_init_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" Ptr32<void> w3d_damage_8004ee4c(Ptr32<void>, int, int, Ptr32<const Vec>, int, int, float);
extern Ptr32<void> lbl_804ab400;
extern unsigned short lbl_804aa95e;
extern int lbl_804b1764, lbl_804b1790;
extern float lbl_804b17a4;
extern int lbl_804adfd8;
extern "C" Vec lbl_804364d0[];
extern "C" const Vec lbl_8043ae20[];
extern "C" char lbl_803800e8[], lbl_80380214[];
static inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
static inline const int &Min(const int &a, const int &b) { return a > b ? b : a; }
extern "C" void w3d_d29b_gun_fire_8009c87c(Ptr32<Gun> self, unsigned shots, Ptr32<Weapon> w, Ptr32<Worm> worm) {
    Vec ang, dir, normal, pos, effect;
    Mat mat;
    Vec tpos;
    int z = 0;
    if (lbl_804adfd8 == 0) {
        lbl_804364d0[0].x = 0.0f;
        lbl_804364d0[0].y = 0.0f;
        lbl_804364d0[0].z = 1.0f;
        lbl_804adfd8 = 1;
    }
    float one = 1.0f;
    float spread = (one - w->inaccuracy) * 0.2f;
    int land = z;
    int hitDist = z;
    int water = z;
    int best = z;
    Ptr32<Holder> target = 0;
    Ptr32<Worm> tw;
    float time = w3d_auto_80178df0(w3d_empty_80342a74(self->weapon));
    Post(&lbl_804ae030);
    PropertyKey where(lbl_803800e8);
    w3d_read_vec_800fc2f0(&where, &effect);
    if (w->bind) w3d_bind_effect_8009d6d4(self, w, &effect);
    pos = worm->pos;
    PropertyKey eyeKey(lbl_80380214);
    float eye;
    w3d_read_float_800fc270(&eyeKey, &eye);
    pos.y = pos.y + eye + w->offsetY;
    w3d_forward_800fdc80(w->b153, w->b152, &pos, 500, -1, -1);
    float lim = 10.0f;
    const Vec &tilt = w->tilt;
    ang.x = -(Max(lim, tilt.x) * 3.1415927f / 180.0f);
    ang.y = -(tilt.y * 3.1415927f / 180.0f);
    ang.z = -(tilt.z * 3.1415927f / 180.0f);
    if (w->randomPitch) {
        float r = w3d_random_80162bc8();
        float x0 = -worm->pitch - worm->pitchAdd; x0 += (r + r - one) * spread; ang.x = x0;
    }
    float r = w3d_random_80162bc8();
    float zero = 0.0f;
    Ptr32<Vec> np = &normal;
    float y0 = worm->yaw + worm->yawAdd; y0 += (r + r - one) * spread; ang.y = y0;
    ang.z = zero;
    w3d_euler_801a3eb0(&ang, 0, &mat);
    mat.rotate(dir, lbl_804364d0[0]);
    dir.Scale(one / dir.len());
    int range = w->range;
    const Vec &muz = w->muzzle;
    pos += dir * muz;
    normal.x = zero; np->y = zero; np->z = zero;
    trace_800b0824(&pos, &dir, &normal, range, 1);
    land = lbl_804b1764;
    float wd;
    if (w3d_water_800419cc(&wd, &pos, &dir, time, &normal)) water = (int)wd;
    else water = range;
    w3d_query_801262c0(self->spheres, &pos);
    int actor = w3d_active_actor_80156f88(lbl_804ab400);
    if (d19c_nearest_sphere_801263fc(self->spheres, &dir, range, actor) != 0xffff && lbl_804b1790 != 0) hitDist = lbl_804b1790;
    else hitDist = range;
    best = Min(hitDist, land);
    best = Min(best, water);
    self->hit.Set(0.0f, 0.0f, 0.0f);
    if (best == land && best != range) {
        self->hit = lbl_8043ae20[0];
        if (w->landSound.Length() != 0 && self->cooldown <= 0) {
            effect_800e5ca4(&self->hit, w->landSound.p, 0, 0.0f);
            self->cooldown = 125;
        }
        if (w->landDamage) {
            float n = (float)shots;
            w3d_land_damage_add_8009d430(self, w->f220 * n);
            Vec d = self->hit - dir;
            Ptr32<void> m = w3d_arena_alloc_801613f0(lbl_804b1754, 52);
            w3d_message_post_8016239c(w3d_explosion_800666b4(m, self->hit, d, w->damage * n, w->f216, w->f296, w->f292, w->f288));
        }
    }
    if (best == hitDist && best != range) {
        self->hit = pos + dir * lbl_804b17a4;
        if (w->hitSound.Length() != 0 && self->cooldown <= 0) {
            effect_800e5ca4(&self->hit, w->hitSound.p, 0, 0.0f);
            self->cooldown = 125;
        }
        if (w->deflect) {
            Vec up(0.0f, 1.0f, 0.0f);
            Vec v;
            Vec d = self->hit - worm->pos;
            float o = 1.0f;
            d.Scale(o / d.len());
            v.x = up.y * d.z - up.z * d.y;
            v.y = dir.y;
            v.z = up.x * d.y - up.y * d.x;
            v.Scale(o / v.len());
            dir = v;
        }
        if (w3d_active_8003f240(lbl_804aa95e)->flags & 1) {
            target = w3d_lookup_80164fc8(w3d_active_8003f240(lbl_804aa95e)->handle);
            tw = w3d_worm_800fc6dc(target->index);
            tpos = tw->pos;
        }
        int dmg;
        if (w->reduce) {
          if (w3d_active_8003f240(lbl_804aa95e)->flags & 1) {
            float left = (float)(tw->maxHealth - tw->health);
            for (unsigned i = 0; i < shots; i++) {
                if (left == 1.0f) { left = 0.0f; break; }
                dmg = (int)(left * w->damage / 100.0f);
                left -= (float)dmg;
            }
            dmg = tw->maxHealth - tw->health - (int)left;
          } else {
            dmg = (int)(w->damage * (float)shots);
          }
        } else {
            dmg = (int)(w->damage * (float)shots);
        }
        if (w3d_active_8003f240(lbl_804aa95e)->flags & 1) {
            Vec k;
            k.x = tpos.x - (dir.x + dir.x);
            k.z = tpos.z - (dir.z + dir.z);
            k.y = tpos.y - 2.0f;
            Ptr32<void> m = w3d_arena_alloc_801613f0(lbl_804b1754, 52);
            w3d_message_post_8016239c(w3d_explosion_800666b4(m, tpos, k, (float)dmg, w->f216, w->f296, 0.0f, w->f288));
            if (w->poison != 0.0f && (w3d_active_8003f240(lbl_804aa95e)->flags & 1) && target) {
                PropertyKey poison("Worm.Poison.Default");
                w3d_write_int_800fc43c(&poison, (unsigned)w->poison);
                Ptr32<void> pm = w3d_arena_alloc_801613f0(lbl_804b1754, 12);
                w3d_message_post_8016239c(w3d_message_int_init_800a82f0(pm, w3d_cached_message_id_8015f5a0(&lbl_804ae0a0, 1), target->index));
            }
        } else {
            Ptr32<void> m = w3d_arena_alloc_801613f0(lbl_804b1754, 36);
            w3d_message_post_8016239c(w3d_damage_8004ee4c(m, w3d_active_8003f240(lbl_804aa95e)->handle, dmg, &dir, 0, 0, w->f216));
        }
    }
    if (best == water && best != range) {
        self->hit = pos + dir * (float)best;
        if (w->waterSound.Length() != 0 && self->cooldown <= 0) {
            effect_800e5ca4(&self->hit, w->waterSound.p, 0, 0.0f);
            self->cooldown = 125;
        }
    }
}


