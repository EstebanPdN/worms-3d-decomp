#include "w3d_ptr.h"
#line 1 "d44s_plan_scatter_push_80017044.cpp"
// GWMP8P rev0 0x80017044. Scatters five AI path plans around the map centre.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Grid;
struct Settings { char unknown00[228]; float spread; };
extern Ptr32<Settings> w3d_settings_804aa6d8;
extern int w3d_flag_804aa594;
extern Ptr32<void> w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
extern Ptr32<Grid> w3d_grid_804b1758;
extern Vec w3d_center_8041d3a0;
extern "C" float s19_random_unit_80015810();
// k2a_grid_position_8001f9f0 devuelve una estructura trivial de tres floats (K2aVec3): en ARM va en s0-s2. Declarada con
// este Vec (constructor de copia propio), el resultado iba por un puntero oculto en r0 y los argumentos se corrían:
// la rejilla llegaba como "celda" y 8001e328 leía basura de la pila (cuelgue de la rejilla de rutas de la IA, v18-v21).
struct GridPos { float x, y, z; };
extern "C" GridPos k2a_grid_position_8001f9f0(Ptr32<Grid>, const Vec &);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
struct CostBase {
    int unknown0;
    float distance;
    int state;
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8CostBase8dispatchEv"));
    CostBase();
 __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_CostBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_CostBase; };
struct PathPlan : CostBase {
    int selected __attribute__((aligned(__alignof__(CostBase))));     /* +16 */
    Vec position;     /* +20 */
    Ptr32<void> path;       /* +32 */
    int active;       /* +36 */
    int flag;         /* +40 */
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8PathPlan8dispatchEv"));
    PathPlan() : selected(-1), path(0), active(1), flag(0) { W3D_SET_VPTR(this->CostBase::w3d_vptr_CostBase, w3d_vt___vt_8PathPlan, "__vt_8PathPlan"); }
 __attribute__((always_inline)) inline void dispatch() { this->CostBase::dispatch(); } };
struct M1 : PathPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN2M18dispatchEv")); M1() { W3D_SET_VPTR(this->PathPlan::w3d_vptr_CostBase, w3d_vt___vt_2M1, "__vt_2M1"); }  __attribute__((always_inline)) inline void dispatch() { this->PathPlan::dispatch(); } };
struct M2 : M1 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN2M28dispatchEv")); M2() { W3D_SET_VPTR(this->M1::w3d_vptr_CostBase, w3d_vt___vt_2M2, "__vt_2M2"); }  __attribute__((always_inline)) inline void dispatch() { this->M1::dispatch(); } };
struct M3 : M2 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN2M38dispatchEv")); M3() { W3D_SET_VPTR(this->M2::w3d_vptr_CostBase, w3d_vt___vt_2M3, "__vt_2M3"); }  __attribute__((always_inline)) inline void dispatch() { this->M2::dispatch(); } };
struct Plan : M3 {
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN4Plan8dispatchEv"));
    Plan(const Vec &p) { W3D_SET_VPTR(this->M3::w3d_vptr_CostBase, w3d_vt___vt_4Plan, "__vt_4Plan");  position = p; }
 __attribute__((always_inline)) inline void dispatch() { this->M3::dispatch(); } };

extern "C" void w3d_ai_push_plan_b(Ptr32<Plan>);
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d44s_plan_scatter_push_80017044()
{
    w3d_flag_804aa594 = 1;
    if (Ready()) {
        for (int i = 0; i < 5; i++) {
            Vec p = w3d_center_8041d3a0;
            float s = w3d_settings_804aa6d8->spread;
            p.x += s19_random_unit_80015810() * (s + s) - s;
            p.z += s19_random_unit_80015810() * (s + s) - s;
            { GridPos g = k2a_grid_position_8001f9f0(w3d_grid_804b1758, p); p.x = g.x; p.y = g.y; p.z = g.z; }
            Ptr32<Plan> plan = (Ptr32<Plan>)w3d_auto_8001523c(44);
            new (plan) Plan(p);

            plan->active = 0;
            plan->selected = 100;
            w3d_ai_push_plan_b(plan);
        }
        return 1;
    }
    return 0;
}


