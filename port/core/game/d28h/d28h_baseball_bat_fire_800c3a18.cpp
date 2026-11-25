#include "w3d_ptr.h"
#line 1 "d28h_baseball_bat_fire_800c3a18.cpp"
// GWMP8P rev0 0x800c3a18. Fires a melee weapon. Names are inferred. Shows
// the weapon's message, plays its sound, works out the shot count from
// remaining ammo and the power percent, then either hands a melee-capable
// worm the attack directly or posts an attack message; the baseball bat adds
// a BatImpact effect. n stays unset when one round is left and power is not
// positive, as in the original.
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Type { char u0[20]; Ptr32<Type> base; };
struct Thing;
struct ThingVt { char u0[20]; Ptr32<Ptr32<Type> (Ptr32<Thing>)> GetType; };
struct Thing { Ptr32<ThingVt> vt; };
extern Type type_803600c0[];
inline bool IsA(Ptr32<Type> t) {
    Ptr32<Type> want = type_803600c0;
    if (t != want) {
        do {
            Ptr32<Type> next = t->base;
            if (t == next) return false;
            t = next;
        } while (t != want);
    }
    return true;
}
struct Ammo { char u0[164]; int used; char u168[2]; unsigned short total; };
struct Holder { char u0[584]; Ptr32<void> inventory; };
struct Worm { Vec pos; char u12[8]; int flags; int handle; };
struct Def {
    char u0[72]; Ptr32<const char> name;
    char u76[76]; unsigned char b152, b153;
    char u154[46]; float f200;
    char u204[4]; float power;
    char u212[8]; Ptr32<const char> sound;
    char u224[28]; int ammo;
};
struct Slot { char u[4]; };
struct Self {
    char u0[36]; Ptr32<void> h36;
    char u40[4]; Ptr32<Def> def;
    char u48[12]; Slot emitter;
};
struct Fx;
struct FxVt { char u0[96]; Ptr32<void (Ptr32<Fx>, Ptr32<const char>, Ptr32<const Vec>)> Play; };
struct Fx { Ptr32<FxVt> vt; };
struct World { char u0[108]; Ptr32<Fx> fx; };
struct Arena;
extern unsigned short g_turn_804aa95e;
extern Ptr32<World> g_world_804b1788;
extern Ptr32<Arena> g_arena_804b1754;
extern "C" int show_800fdc80(int, int, Ptr32<Slot>, int, int, int);
extern "C" Ptr32<Worm> worm_8003f240(unsigned short);
extern "C" int sound_800e5ca4(Ptr32<Slot>, float, Ptr32<const char>, int);
extern "C" Ptr32<Holder> object_80164fc8(int);
extern "C" Ptr32<Ammo> ammo_800fc6dc(int);
extern "C" Ptr32<void> as_803426b4(Ptr32<void>);
extern "C" Ptr32<void> value_80178c48(Ptr32<void>);
extern "C" void melee_8004c2f0(Ptr32<Thing>, Ptr32<void>);
extern "C" Ptr32<void> alloc_801613f0(Ptr32<Arena>, unsigned);
extern "C" Ptr32<void> ctor_8004ee4c(Ptr32<void>, int, int, Ptr32<void>, float, int, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void d28h_baseball_bat_fire_800c3a18(Ptr32<Self> self) {
    Ptr32<Slot> em = &self->emitter;
    show_800fdc80(self->def->b153, self->def->b152, em, 500, -1, -1);
    int n;
    if (worm_8003f240(g_turn_804aa95e)->flags & 1) {
        if (((Ptr32<unsigned short>)self->def->sound)[-2] != 0)
            sound_800e5ca4(em, 0.0f, self->def->sound, 0);
        if (self->def->ammo != 0) {
            Ptr32<Ammo> a = ammo_800fc6dc((int)w3d::H((object_80164fc8(worm_8003f240(g_turn_804aa95e)->handle)->inventory)));
            float left = (float)(a->total - a->used);
            if (left == 1.0f) {
                if (self->def->power > 0.0f) n = 1;
            } else {
                n = (int)(left * self->def->power / 100.0f);
                left -= (float)n;
                n = (-a->used + a->total) - (int)left;
            }
        } else {
            n = (int)self->def->power;
        }
    } else {
        n = (int)self->def->power;
    }
    if (worm_8003f240(g_turn_804aa95e)->flags & 6) {
        Ptr32<Thing> o = (Ptr32<Thing>)object_80164fc8(worm_8003f240(g_turn_804aa95e)->handle);
        if (IsA(o->vt->GetType(o))) {
            melee_8004c2f0(o, value_80178c48(as_803426b4(self->h36)));
            return;
        }
    }
    Ptr32<void> m = alloc_801613f0(g_arena_804b1754, 36);
    post_8016239c(ctor_8004ee4c(m, worm_8003f240(g_turn_804aa95e)->handle, n, (Ptr32<char>)self + 48, self->def->f200, 0, self->def->ammo));
    if (strcmp(self->def->name, "BaseballBat") == 0) {
        Ptr32<Fx> fx = g_world_804b1788->fx;
        if (fx) {
            Ptr32<FxVt> vt = fx->vt;
            const Vec &w = worm_8003f240(g_turn_804aa95e)->pos;
            float px = w.x, py = w.y, pz = w.z;
            Vec p;
            p.x = px; p.y = py; p.z = pz;
            vt->Play(fx, "BatImpact", &p);
        }
    }
}


