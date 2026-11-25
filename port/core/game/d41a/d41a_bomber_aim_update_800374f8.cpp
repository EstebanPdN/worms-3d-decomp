#include "w3d_ptr.h"
#line 1 "d41a_bomber_aim_update_800374f8.cpp"
// GWMP8P rev0 0x800374f8. Updates a bomber aim marker from its actor: when
// the actor is dead clears the target; otherwise samples its position, reads
// the direction either from the Bomber.Direction property or the actor,
// flattens and normalises it to get the yaw, takes the pitch from the
// unflattened direction, and sends the target back to the actor. Names are
// inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Actor;
struct ActorVt { char u00[44]; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec>)> sample; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec>)> apply; Ptr32<void (Ptr32<Actor>, int, Ptr32<Vec>)> dir; };
struct Actor { Ptr32<ActorVt> vt; char u04[116]; int dead; };
struct Context { char u00[52]; int frame; };
struct Self { char u00[140]; Vec pos; float rx, ry, rz; Vec target; char u_b0[32]; int handle; };
extern "C" Ptr32<Actor> w3d_s20_lookup_handle_80164fc8(int);
extern "C" Ptr32<Context> w3d_engine_get_context_80165254();
extern "C" int w3d_auto_800edf7c(Ptr32<Actor>);
extern "C" int w3d_auto_800fc2f0(Ptr32<Ptr32<const char>>, Ptr32<Vec>);
extern "C" float w3d_fn_802e82c0(float);
extern "C" float acos_802e7c30(float);
extern Vec w3d_zero_8045e788[];
extern "C" void w3d_d41a_bomber_aim_update_800374f8(Ptr32<Self> self)
{
    Ptr32<Actor> a = w3d_s20_lookup_handle_80164fc8(self->handle);
    if (a) {
        int frame = w3d_engine_get_context_80165254()->frame;
        if (a->dead) {
            self->target = w3d_zero_8045e788[0];
        } else {
            a->vt->sample(a, frame, &self->pos);
            Vec dir;
            if (w3d_auto_800edf7c(a)) {
                Ptr32<const char> name = "Bomber.Direction";
                w3d_auto_800fc2f0(&name, &dir);
            } else {
                a->vt->dir(a, frame, &dir);
            }
            Vec d;
            d = dir;
            float zero = 0.0f;
            d.y = zero;
            float n = d.z * d.z + (d.x * d.x + zero);
            if (n > zero) {
                float inv = 1.0f / w3d_fn_802e82c0(n);
                d.x *= inv; d.y *= inv; d.z *= inv;
                float yaw = acos_802e7c30(d.x);
                if (dir.z < zero) yaw = 3.1415927f - yaw;
                self->ry = yaw;
            }
            self->rx = -acos_802e7c30(dir.y);
            self->rz = 0.0f;
            a->vt->apply(a, frame, &self->target);
        }
    }
}


