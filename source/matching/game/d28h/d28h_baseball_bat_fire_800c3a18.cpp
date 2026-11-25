// GWMP8P rev0 0x800c3a18. Fires a melee weapon. Names are inferred. Shows
// the weapon's message, plays its sound, works out the shot count from
// remaining ammo and the power percent, then either hands a melee-capable
// worm the attack directly or posts an attack message; the baseball bat adds
// a BatImpact effect. n stays unset when one round is left and power is not
// positive, as in the original.
extern "C" int strcmp(const char *, const char *);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Type { char u0[20]; Type *base; };
struct Thing;
struct ThingVt { char u0[20]; Type *(*GetType)(Thing *); };
struct Thing { ThingVt *vt; };
extern Type type_803600c0[];
inline bool IsA(Type *t) {
    Type *want = type_803600c0;
    if (t != want) {
        do {
            Type *next = t->base;
            if (t == next) return false;
            t = next;
        } while (t != want);
    }
    return true;
}
struct Ammo { char u0[164]; int used; char u168[2]; unsigned short total; };
struct Holder { char u0[584]; void *inventory; };
struct Worm { Vec pos; char u12[8]; int flags; int handle; };
struct Def {
    char u0[72]; const char *name;
    char u76[76]; unsigned char b152, b153;
    char u154[46]; float f200;
    char u204[4]; float power;
    char u212[8]; const char *sound;
    char u224[28]; int ammo;
};
struct Slot { char u[4]; };
struct Self {
    char u0[36]; void *h36;
    char u40[4]; Def *def;
    char u48[12]; Slot emitter;
};
struct Fx;
struct FxVt { char u0[96]; void (*Play)(Fx *, const char *, const Vec *); };
struct Fx { FxVt *vt; };
struct World { char u0[108]; Fx *fx; };
struct Arena;
extern unsigned short g_turn_804aa95e;
extern World *g_world_804b1788;
extern Arena *g_arena_804b1754;
extern "C" int show_800fdc80(int, int, Slot *, int, int, int);
extern "C" Worm *worm_8003f240(unsigned short);
extern "C" int sound_800e5ca4(Slot *, float, const char *, int);
extern "C" Holder *object_80164fc8(int);
extern "C" Ammo *ammo_800fc6dc(int);
extern "C" void *as_803426b4(void *);
extern "C" void *value_80178c48(void *);
extern "C" void melee_8004c2f0(Thing *, void *);
extern "C" void *alloc_801613f0(Arena *, unsigned);
extern "C" void *ctor_8004ee4c(void *, int, int, void *, float, int, int);
extern "C" int post_8016239c(void *);
extern "C" void d28h_baseball_bat_fire_800c3a18(Self *self) {
    Slot *em = &self->emitter;
    show_800fdc80(self->def->b153, self->def->b152, em, 500, -1, -1);
    int n;
    if (worm_8003f240(g_turn_804aa95e)->flags & 1) {
        if (((unsigned short *)self->def->sound)[-2] != 0)
            sound_800e5ca4(em, 0.0f, self->def->sound, 0);
        if (self->def->ammo != 0) {
            Ammo *a = ammo_800fc6dc((int)(object_80164fc8(worm_8003f240(g_turn_804aa95e)->handle)->inventory));
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
        Thing *o = (Thing *)object_80164fc8(worm_8003f240(g_turn_804aa95e)->handle);
        if (IsA(o->vt->GetType(o))) {
            melee_8004c2f0(o, value_80178c48(as_803426b4(self->h36)));
            return;
        }
    }
    void *m = alloc_801613f0(g_arena_804b1754, 36);
    post_8016239c(ctor_8004ee4c(m, worm_8003f240(g_turn_804aa95e)->handle, n, (char *)self + 48, self->def->f200, 0, self->def->ammo));
    if (strcmp(self->def->name, "BaseballBat") == 0) {
        Fx *fx = g_world_804b1788->fx;
        if (fx) {
            FxVt *vt = fx->vt;
            const Vec &w = worm_8003f240(g_turn_804aa95e)->pos;
            float px = w.x, py = w.y, pz = w.z;
            Vec p;
            p.x = px; p.y = py; p.z = pz;
            vt->Play(fx, "BatImpact", &p);
        }
    }
}
