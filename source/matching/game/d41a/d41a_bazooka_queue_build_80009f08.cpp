// GWMP8P rev0 0x80009f08. Builds a move queue with an aimed shot at the
// target when the weapon is available and the AI flags allow it: refuses
// targets nearer than 40 flat units or on blocked cells, searches an aim
// with gravity, then deletes the queue again if the flight time would leave
// less than the given time in the turn. Returns 1 when the queue is kept.
// Names are inferred.
inline void *operator new(unsigned int, void *place) { return place; }
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float lenSq() const { return x * x + y * y + z * z; }
};
struct Grid;
struct QueueBase { char u00[16]; virtual ~QueueBase(); };
struct Queue : QueueBase { Queue(); };
struct Motion;
struct MotionBase { char u00[36]; virtual void v0(); virtual void set_step(const Vec *); };
struct Motion : MotionBase { };
extern Motion g_motion_8041e780[];
extern Vec g_step_8041e850[];
extern Grid *w3d_grid_804b1758;
extern int g_on_804aa6dc, g_off_804aa6e0, g_busy_804aa6e4;
extern float g_clock_804aa570;
extern "C" int w3d_ai_weapon_available(int);
extern "C" int cc26a_grid_select_layer_8001e328(Grid *, const Vec *, short *, short *, int *);
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(Grid *, int, int, int);
extern "C" void cc27a_planner_set_gravity_8001aa48(const Vec *);
extern "C" int aim_search_8001aaf8(const Vec *, float, float);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" Queue *w3d_move_queue_construct(void *);
extern "C" void w3d_d28a_method_command_append_80003558(Queue *, const Vec *, int, Motion *);
extern "C" float w3d_d24a_turn_time_remaining_800155d0();
extern "C" int w3d_d41a_bazooka_queue_build_80009f08(Queue **out, const Vec *from, const Vec *to, float limit)
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
                        Motion *m = g_motion_8041e780;
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
                            if (*out) delete *out;
                            *out = 0;
                        } else return 1;
                    }
                }
            }
        }
    }
    return 0;
}
