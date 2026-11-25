#include "w3d_ptr.h"
#line 1 "d41a_bazooka_queue_build_80009f08.cpp"
// GWMP8P rev0 0x80009f08. Builds a move queue with an aimed shot at the
// target when the weapon is available and the AI flags allow it: refuses
// targets nearer than 40 flat units or on blocked cells, searches an aim
// with gravity, then deletes the queue again if the flight time would leave
// less than the given time in the turn. Returns 1 when the queue is kept.
// Names are inferred.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Grid;
struct QueueBase { char u00[16]; ~QueueBase();  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_QueueBase, 2))(w3d::h2g(this), w3d_in); }  Ptr32<void> w3d_vptr_QueueBase; };
struct Queue : QueueBase { Queue(); };
struct Motion;
struct MotionBase { char u00[36]; void w3d_r_v0() __asm__(W3D_SYM("_ZN10MotionBase2v0Ev")); void w3d_r_set_step(Ptr32<const Vec>) __asm__(W3D_SYM("_ZN10MotionBase8set_stepEPK3Vec"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_MotionBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set_step(Ptr32<const Vec> w3d_a0) { ((void (*)(w3d_u32, Ptr32<const Vec>))w3d::vfn(this->w3d_vptr_MotionBase, 3))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_MotionBase; };
struct Motion : MotionBase { };
extern Motion g_motion_8041e780[];
extern Vec g_step_8041e850[];
extern Ptr32<Grid> w3d_grid_804b1758;
extern int g_on_804aa6dc, g_off_804aa6e0, g_busy_804aa6e4;
extern float g_clock_804aa570;
extern "C" int w3d_ai_weapon_available(int);
extern "C" int cc26a_grid_select_layer_8001e328(Ptr32<Grid>, Ptr32<const Vec>, Ptr32<short>, Ptr32<short>, Ptr32<int>);
extern "C" Ptr32<unsigned char> cc26a_grid_byte_cell_8001dff8(Ptr32<Grid>, int, int, int);
extern "C" void cc27a_planner_set_gravity_8001aa48(Ptr32<const Vec>);
extern "C" int aim_search_8001aaf8(Ptr32<const Vec>, float, float);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" Ptr32<Queue> w3d_move_queue_construct(Ptr32<void>);
extern "C" void w3d_d28a_method_command_append_80003558(Ptr32<Queue>, Ptr32<const Vec>, int, Ptr32<Motion>);
extern "C" float w3d_d24a_turn_time_remaining_800155d0();
extern "C" int w3d_d41a_bazooka_queue_build_80009f08(Ptr32<Ptr32<Queue>> out, Ptr32<const Vec> from, Ptr32<const Vec> to, float limit)
{
    if (w3d_ai_weapon_available(48)) {
        bool ok = false;
        if (g_on_804aa6dc && !g_off_804aa6e0) ok = g_busy_804aa6e4 == 0;
        if (ok) {
            float zero = 0.0f;
            Vec f(*to - *from);
            f.y = zero;
            if (sqrt_802e82c0(f.lenSq()) < 40.0f) return 0;
            short x, z;
            int layer;
            if (cc26a_grid_select_layer_8001e328(w3d_grid_804b1758, to, &x, &z, &layer)) {
                unsigned char kind = *cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, x, z, layer);
                if (!kind) {
                    g_clock_804aa570 += 100.0f;
                    cc27a_planner_set_gravity_8001aa48(from);
                    if (aim_search_8001aaf8(to, zero, 1.0f)) {
                        Ptr32<Motion> m = g_motion_8041e780;
                        {
                            Vec step(g_step_8041e850[0]);
                            m->set_step(&step);
                        }
                        *out = w3d_move_queue_construct(w3d_auto_8001523c(48));
                        w3d_d28a_method_command_append_80003558(*out, to, 7, m);
                        Vec e(*to - *from);
                        e.y = zero;
                        float t = sqrt_802e82c0(e.lenSq()) / 43.0f;
                        if (w3d_d24a_turn_time_remaining_800155d0() - t < limit) {
                            if (*out) w3d::vdelete(*out);
                            *out = 0;
                        } else return 1;
                    }
                }
            }
        }
    }
    return 0;
}

W3D_DT_THUNK("_ZN9QueueBaseD1Ev", 2, "_._9QueueBase");
W3D_DT_THUNK("_ZN9QueueBaseD2Ev", 0, "_._9QueueBase");
