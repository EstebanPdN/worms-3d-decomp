#include "w3d_ptr.h"
#line 1 "d28a_capture_plan_execute_8000a800.cpp"
// GWMP8P rev0 0x8000a800. Advances the turn clock, optionally retargets at
// the plan's stored point, runs the capture trace, refreshes the step vector
// from the target body when the step is unchanged, and records the result.
// Field meanings are inferred from the original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float v) { x = v; y = v; z = v; }
    bool Same(const Vec &o) const {
        Ptr32<const int> p = (Ptr32<const int>)this; Ptr32<const int> q = (Ptr32<const int>)&o;
        return p[0] == q[0] && p[1] == q[1] && p[2] == q[2];
    }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
};
struct Body { char unknown00[16]; Vec position; };
struct BodyList { Ptr32<Ptr32<Body>> start; Ptr32<Body> & operator[](int i) { return start[i]; } };
struct Capture {
    char unknown00[16];
    int index;            /* +16 */
    int weapon;           /* +20 */
    Vec position;         /* +24 */
    char unknown30[40];
    int active;           /* +76 */
    char unknown50[8];
    Vec target;           /* +88 */
};
extern float g_time_804aa570;
extern int g_guard_804ac84c;
extern Ptr32<BodyList> w3d_bodies_804aa750;
struct VecWords { int x, y, z; };
extern VecWords w3d_center_8041d3a0[];
extern Vec g_prev_8041d394[];
extern Vec g_step_8041e850[];
extern "C" int FUN_8001b510(int, Ptr32<VecWords>, Ptr32<Vec>);
extern "C" int w3d_ai_capture_query_8000a68c(Ptr32<Capture>, int);
inline void SetStep(Vec v) { g_step_8041e850[0] = v; }
extern "C" int w3d_d28a_capture_plan_execute_8000a800(Ptr32<Capture> self)
{
    g_time_804aa570 += 100.0f;
    if (self->active) w3d_center_8041d3a0[0] = *(Ptr32<VecWords>)&self->target;
    Ptr32<VecWords> c = w3d_center_8041d3a0;
    int r = FUN_8001b510(self->weapon, c, &self->position);
    if (!g_guard_804ac84c) { g_guard_804ac84c = 1; g_prev_8041d394[0].Set(0.0f); }
    Vec cur; const Vec &o = g_step_8041e850[0]; float ax = o.x, ay = o.y, az = o.z; cur.x = ax; cur.y = ay; cur.z = az;
    if (g_prev_8041d394[0].Same(cur)) {
        SetStep((*w3d_bodies_804aa750)[self->index]->position - *(Ptr32<Vec>)w3d_center_8041d3a0);
    }
    w3d_ai_capture_query_8000a68c(self, r);
    return r;
}


