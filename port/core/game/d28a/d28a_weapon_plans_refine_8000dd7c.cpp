#include "w3d_ptr.h"
#line 1 "d28a_weapon_plans_refine_8000dd7c.cpp"
// GWMP8P rev0 0x8000dd7c. Refreshes a weapon plan's predicted target, then
// clones it into two follow-up plans for weapons 3 and 25 when available.
// Clones share the counted handles at +76 and +84. Class names and field
// meanings are inferred from the original instructions.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct WeaponPlan;
struct Vec { float x, y, z; };
struct Counted { char unknown00[44]; int refs; };
struct Handle {
    int kind;
    Ptr32<Counted> object;
    Handle() : object(0) {}
};
struct CostBase {
    int unknown0;
    float distance;
    int state;
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8CostBase8dispatchEv"));
    CostBase();
 __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_CostBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_CostBase; };
struct WeaponPlan : CostBase {
    int index __attribute__((aligned(__alignof__(CostBase))));            /* +16 */
    int weapon;           /* +20 */
    Vec position;         /* +24 */
    char unknown24[28];   /* +36 */
    unsigned char done;   /* +64 */
    int aim;              /* +68 */
    Handle first;         /* +72 */
    Handle second;        /* +80 */
    char unknown58[16];   /* +88 */
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN10WeaponPlan8dispatchEv"));
    bool Done() const { return done != 0; }
    WeaponPlan(const WeaponPlan &o)
    { W3D_SET_VPTR(this->CostBase::w3d_vptr_CostBase, w3d_vt___vt_10WeaponPlan, "__vt_10WeaponPlan"); 

        *this = o;
        distance = -1e20f;
        const Handle &a = o.first; const Handle &b = o.second;
        if (a.object) { first.object = a.object; first.object->refs++; }
        if (b.object) { second.object = b.object; second.object->refs++; }

    }
 __attribute__((always_inline)) inline void dispatch() { this->CostBase::dispatch(); } };
struct Ranged : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN6Ranged8dispatchEv")); Ranged(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_6Ranged, "__vt_6Ranged");  aim = 368; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Bazooka : Ranged {
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Bazooka8dispatchEv"));
    Bazooka(const WeaponPlan &o) : Ranged(o) { W3D_SET_VPTR(this->Ranged::w3d_vptr_CostBase, w3d_vt___vt_7Bazooka, "__vt_7Bazooka");  weapon = 3; }
 __attribute__((always_inline)) inline void dispatch() { this->Ranged::dispatch(); } };
struct Grenade : Ranged {
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Grenade8dispatchEv"));
    Grenade(const WeaponPlan &o) : Ranged(o) { W3D_SET_VPTR(this->Ranged::w3d_vptr_CostBase, w3d_vt___vt_7Grenade, "__vt_7Grenade");  weapon = 25; }
 __attribute__((always_inline)) inline void dispatch() { this->Ranged::dispatch(); } };
struct Body { char unknown00[32]; float energy; };
struct BodyList { Ptr32<Ptr32<Body>> start; Ptr32<Body> & operator[](int i) { return start[i]; } };
extern Ptr32<BodyList> w3d_bodies_804aa750;
extern int w3d_flag_804aa594;
extern "C" Vec k5a_body_predict_position_800196dc(Ptr32<Body>, float);
extern "C" int w3d_ai_weapon_available(int);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(Ptr32<CostBase>);
extern "C" int w3d_d28a_weapon_plans_refine_8000dd7c(Ptr32<WeaponPlan> self)
{
    int any = 0;
    if (!self->Done()) {
        Ptr32<Body> b = (*w3d_bodies_804aa750)[self->index];
        float t = 0.0f;
        if (b->energy > t) self->position = k5a_body_predict_position_800196dc(b, t);
    }
    if (w3d_ai_weapon_available(3)) {
        Ptr32<Bazooka> plan = new (w3d_auto_8001523c(104)) Bazooka(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(25)) {
        Ptr32<Grenade> plan = new (w3d_auto_8001523c(104)) Grenade(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}


