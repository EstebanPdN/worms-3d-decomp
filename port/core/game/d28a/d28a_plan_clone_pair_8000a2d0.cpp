#include "w3d_ptr.h"
#line 1 "d28a_plan_clone_pair_8000a2d0.cpp"
// GWMP8P rev0 0x8000a2d0. Clones a plan into two follow-up plans of
// different classes and pushes both. Class names and field meanings are
// inferred from the original instructions.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
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
        const Handle &a = o.first;
        if (a.object) { first.object = a.object; first.object->refs++; }
        const Handle &b = o.second;
        if (b.object) { second.object = b.object; second.object->refs++; }
    }
 __attribute__((always_inline)) inline void dispatch() { this->CostBase::dispatch(); } };
extern int w3d_flag_804aa594;
extern "C" int w3d_ai_weapon_available(int);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(Ptr32<CostBase>);
struct PlanA : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN5PlanA8dispatchEv")); PlanA(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_5PlanA, "__vt_5PlanA");  }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct PlanB : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN5PlanB8dispatchEv")); PlanB(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_5PlanB, "__vt_5PlanB");  }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
extern "C" int w3d_d28a_plan_clone_pair_8000a2d0(Ptr32<WeaponPlan> self)
{
    Ptr32<PlanA> a = new (w3d_auto_8001523c(104)) PlanA(*self);
    w3d_ai_push_plan_b(a);
    Ptr32<PlanB> b = new (w3d_auto_8001523c(104)) PlanB(*self);
    w3d_ai_push_plan_b(b);
    return 1;
}


