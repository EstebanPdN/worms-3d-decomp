#include "w3d_ptr.h"
#line 1 "d28g_spawner_pick_clear_spot_8004a408.cpp"
/* Worms 3D GameCube PAL 0x8004a408. Picks a spawn spot: settles a body with step 9, then repeats choosing a random x and z inside the ground bounds, sweeping down with velocity -10 for up to 1000 steps, rejecting no contact or a landing below the water height from +184, and rejecting spots whose radius probe finds an actor with flag 1; stores the accepted spot at +40. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Ground { char u[12548]; Vec lo; Vec hi; };
struct Actor { char u[20]; unsigned flags; };
struct Handle;
struct Spawner { char u0[40]; Vec pos; char u52[64 - 52]; float radius; char u68[184 - 68]; Ptr32<Handle> a184; };
/* Constructor 0x80126184, destructor 0x80126230. */
struct Probe {
    Ptr32<void> object;
    Probe();
    Probe(const Probe &);
    ~Probe();
    void set_radius_8012629c(float);
    void set_mask_8012632c(int);
    void set_position_801262c0(Ptr32<Vec>);
    void set_direction_80126384(Ptr32<Vec>, int);
    int next_801264fc();
    void finish_80126524();
};
extern "C" {
void w3d_fn_8004b3f0(float, Ptr32<void>);
float w3d_auto_801610a0(Ptr32<Spawner>);
void sweep_800b0824(Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, int, int);
float w3d_auto_80178df0(Ptr32<Handle>);
Ptr32<Actor> w3d_auto_8003f240(int);
}
extern Ptr32<Ground> ground_804b17e0;
extern unsigned hits_804b1764;
extern Vec rest_pos_8043ae20;
extern unsigned short id_804aa95e;
extern "C" void w3d_d28g_spawner_pick_clear_spot_8004a408(Ptr32<Spawner> self)
{
    w3d_fn_8004b3f0(9.0f, (Ptr32<void>)self);
    Ptr32<Ground> g = ground_804b17e0;
    Vec lo(g->lo);
    Vec hi(g->hi);
    Vec p;
    Vec down(0.0f, -10.0f, 0.0f);
    Vec zero(0.0f, 0.0f, 0.0f);
    bool ok;
    do {
        p.y = hi.y;
        p.x = lo.x + (hi.x - lo.x) * w3d_auto_801610a0(self);
        p.z = lo.z + (hi.z - lo.z) * w3d_auto_801610a0(self);
        sweep_800b0824(&p, &down, &zero, 1000, 1);
        ok = hits_804b1764 <= 1000;
        if (hits_804b1764) { if (rest_pos_8043ae20.y < w3d_auto_80178df0(self->a184)) ok = false; } else ok = false;
        if (ok) {
            Probe h;
            h.set_radius_8012629c(self->radius);
            h.set_mask_8012632c(63);
            h.set_position_801262c0(&p);
            h.set_direction_80126384(&down, 1000);
            int id = h.next_801264fc();
            while (id != 0xffff) {
                if (w3d_auto_8003f240(id_804aa95e)->flags & 1) { ok = false; break; }
                id = h.next_801264fc();
            }
            h.finish_80126524();
        }
    } while (!ok);
    self->pos = p;
}


