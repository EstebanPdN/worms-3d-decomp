#include "w3d_ptr.h"
#line 1 "d41a_stand_plan_spawn_8000b8f8.cpp"
// GWMP8P rev0 0x8000b8f8. Starts a stand plan for an AI worm: unless it has
// tried three times, optionally finds a best stand and builds the two move
// queues to it (keeping them on success and deleting them on failure), or
// falls back to the centre, then for every usable entry farther than 100
// units clones the plan into four concrete plans and pushes them. Sets the
// final cost from the score and releases the held queues. Names are
// inferred.
#pragma interface
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { x = o.x; y = o.y; z = o.z; } };
struct Words { unsigned w[3]; };
struct Grid;
struct QueueBase { char u00[16]; ~QueueBase();  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_QueueBase, 2))(w3d::h2g(this), w3d_in); }  Ptr32<void> w3d_vptr_QueueBase; };
struct Queue : QueueBase { char u14[24] __attribute__((aligned(__alignof__(QueueBase)))); int refs; };
extern "C" void w3d_move_queue_release(Ptr32<Queue>);
struct Slot { unsigned u00; Ptr32<Queue> q; Slot() { q = 0; }
    Ptr32<Queue> Get() const { return q; }
    void Release() { if (q) { w3d_move_queue_release(q); q = 0; } } };
struct Pos { unsigned short u00; unsigned short x; unsigned short z; unsigned char layer; };
struct Entry { unsigned char u00[12]; float cost; Words origin; bool usable(float t) { return cost > t; } };
struct Range { Ptr32<Ptr32<Entry>> begin; Ptr32<Ptr32<Entry>> end; int size() { return end - begin; } };
struct Settings { char u00[188]; float time; };
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned);
struct Base_80006360 {
    unsigned u00; float score; int active;
    void w3d_r_n0() __asm__(W3D_SYM("_ZN13Base_800063602n0Ev"));
    void SetScore(float s) { score = s; }
    static void *operator new(__SIZE_TYPE__ n) { return w3d_auto_8001523c(n); }
    Base_80006360();
 __attribute__((always_inline)) inline void n0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base_80006360, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Base_80006360; };
struct Plan_8040d7b8 : Base_80006360 {
    int index __attribute__((aligned(__alignof__(Base_80006360)))); unsigned duration; Words origin; unsigned char u24[24]; float cost; unsigned char flag40, tries; unsigned short u42; unsigned value;
    Slot held48, held50; Vec saved; float final;
    Plan_8040d7b8(const Plan_8040d7b8 &o) { W3D_SET_VPTR(this->Base_80006360::w3d_vptr_Base_80006360, w3d_vt___vt_13Plan_8040d7b8, "__vt_13Plan_8040d7b8"); 
        *this = o;
        SetScore(-1.0e20f);
        if (Ptr32<Queue> h = o.held48.Get()) { held48.q = h; h->refs++; }
        if (Ptr32<Queue> h = o.held50.Get()) { held50.q = h; h->refs++; }
    }
    void w3d_r_n0() __asm__(W3D_SYM("_ZN13Plan_8040d7b82n0Ev"));
 __attribute__((always_inline)) inline void n0() { this->Base_80006360::n0(); } };
struct Plan_8040d748 : Plan_8040d7b8 { Plan_8040d748(const Plan_8040d7b8 &o) : Plan_8040d7b8(o) { W3D_SET_VPTR(this->Plan_8040d7b8::w3d_vptr_Base_80006360, w3d_vt___vt_13Plan_8040d748, "__vt_13Plan_8040d748"); } void w3d_r_n0() __asm__(W3D_SYM("_ZN13Plan_8040d7482n0Ev"));  __attribute__((always_inline)) inline void n0() { this->Plan_8040d7b8::n0(); } };
struct Plan_8040d710 : Plan_8040d7b8 { Plan_8040d710(const Plan_8040d7b8 &o) : Plan_8040d7b8(o) { W3D_SET_VPTR(this->Plan_8040d7b8::w3d_vptr_Base_80006360, w3d_vt___vt_13Plan_8040d710, "__vt_13Plan_8040d710"); } void w3d_r_n0() __asm__(W3D_SYM("_ZN13Plan_8040d7102n0Ev"));  __attribute__((always_inline)) inline void n0() { this->Plan_8040d7b8::n0(); } };
struct Plan_8040d6d8 : Plan_8040d7b8 { Plan_8040d6d8(const Plan_8040d7b8 &o) : Plan_8040d7b8(o) { W3D_SET_VPTR(this->Plan_8040d7b8::w3d_vptr_Base_80006360, w3d_vt___vt_13Plan_8040d6d8, "__vt_13Plan_8040d6d8"); } void w3d_r_n0() __asm__(W3D_SYM("_ZN13Plan_8040d6d82n0Ev"));  __attribute__((always_inline)) inline void n0() { this->Plan_8040d7b8::n0(); } };
struct Plan_8040d668 : Plan_8040d7b8 { Plan_8040d668(const Plan_8040d7b8 &o) : Plan_8040d7b8(o) { W3D_SET_VPTR(this->Plan_8040d7b8::w3d_vptr_Base_80006360, w3d_vt___vt_13Plan_8040d668, "__vt_13Plan_8040d668"); } void w3d_r_n0() __asm__(W3D_SYM("_ZN13Plan_8040d6682n0Ev"));  __attribute__((always_inline)) inline void n0() { this->Plan_8040d7b8::n0(); } };
extern "C" bool w3d_d41a_best_stand_80019b34(Ptr32<Pos>, Ptr32<Pos>, Ptr32<float>);
extern "C" void cc25a_planner_clear_neighborhood_80019ea0(Ptr32<Pos>, int);
extern "C" Vec w3d_cx12a_sample_grid_8001e224(Ptr32<Grid>, int, int, int);
extern "C" int queue_build_80009674(Ptr32<Ptr32<Queue>>, Ptr32<const Vec>, Ptr32<const Vec>, int, float);
extern "C" void w3d_ai_push_plan_b(Ptr32<void>);
extern "C" float w3d_fn_802e8094(float);
extern "C" float w3d_libm_forward_802e83cc(float);
extern Ptr32<Grid> w3d_grid_804b1758;
extern Vec w3d_center_8041d3a0[];
extern int g_on_804aa6dc, g_off_804aa6e0, g_fallback_804aa594, g_status_804b175c;
extern Ptr32<Settings> g_settings_804aa6d8;
extern Ptr32<Range> g_list_804aa750;
extern "C" int w3d_d41a_stand_plan_spawn_8000b8f8(Ptr32<Plan_8040d7b8> self)
{
    Ptr32<const Vec> from = w3d_center_8041d3a0;
    Vec v(*from);
    if (self->tries <= 2) {
    int ready = 0;
    float score = 0.0f;
    bool wanted = false;
    if (g_on_804aa6dc) wanted = g_off_804aa6e0 == 0;
    Pos a, b;
    if (wanted && w3d_d41a_best_stand_80019b34(&a, &b, &score)) {
        Ptr32<Queue> q1 = 0;
        g_fallback_804aa594 = ready;
        v = w3d_cx12a_sample_grid_8001e224(w3d_grid_804b1758, (short)a.x, (short)a.z, a.layer);
        int ok1 = queue_build_80009674(&q1, from, &v, 200, g_settings_804aa6d8->time);
        Ptr32<Queue> q2 = 0;
        Vec to = w3d_cx12a_sample_grid_8001e224(w3d_grid_804b1758, (short)b.x, (short)b.z, b.layer);
        int ok2 = queue_build_80009674(&q2, &v, &to, 50, g_settings_804aa6d8->time);
        if (!ok2 && g_status_804b175c == 11) ok2 = 1;
        if (ok1 && ok2) {
            cc25a_planner_clear_neighborhood_80019ea0(&a, 4);
            ready = 1;
            cc25a_planner_clear_neighborhood_80019ea0(&b, 4);
            self->held48.q = q1;
            q1->refs++;
            if (q2) { self->held50.q = q2; q2->refs++; }
            self->saved = v;
        } else {
            if (q1) w3d::vdelete(q1);
            q1 = 0;
            if (q2) w3d::vdelete(q2);
            q2 = 0;
            if (!ok1) cc25a_planner_clear_neighborhood_80019ea0(&a, 4);
            if (!ok2) cc25a_planner_clear_neighborhood_80019ea0(&b, 4);
        }
    } else {
        g_fallback_804aa594 = 1;
        score = 0.0f;
        v = w3d_center_8041d3a0[0];
        ready = 1;
    }
    if (ready) {
        self->tries++;
        int count = g_list_804aa750->size();
        for (int i = 0; i < count; i++) {
            if ((*(Ptr32<Ptr32<Entry>>)((Ptr32<char>)g_list_804aa750->begin + (i << 2)))->usable(0.0f)) {
                self->index = i;
                self->origin = (*(Ptr32<Ptr32<Entry>>)((Ptr32<char>)g_list_804aa750->begin + (i << 2)))->origin;
                Ptr32<Vec> o = (Ptr32<Vec>)&self->origin;
                Ptr32<Vec> pv = &v;
                float dx = v.x - o->x;
                float dy = pv->y - o->y;
                float dz = pv->z - o->z;
                if (dz * dz + (dx * dx + dy * dy) > 10000.0f) {
                    w3d_ai_push_plan_b(new Plan_8040d748(*self));
                    w3d_ai_push_plan_b(new Plan_8040d710(*self));
                    w3d_ai_push_plan_b(new Plan_8040d6d8(*self));
                    w3d_ai_push_plan_b(new Plan_8040d668(*self));
                }
            }
        }
        self->index = -1;
        self->final = w3d_libm_forward_802e83cc(w3d_fn_802e8094(score) * 1.1f);
        self->held48.Release();
        self->held50.Release();
    }
    return 1;
    }
    return 0;
}

W3D_DT_THUNK("_ZN9QueueBaseD1Ev", 2, "_._9QueueBase");
W3D_DT_THUNK("_ZN9QueueBaseD2Ev", 0, "_._9QueueBase");
