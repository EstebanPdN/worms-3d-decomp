#include "w3d_ptr.h"
#line 1 "d28a_weapon_plans_special_800109b0.cpp"
// GWMP8P rev0 0x800109b0. Clones a plan into follow-up plans for weapons 18,
// 29, 23 and 24 when available. Weapon 29's plan is 288 bytes with a method
// member at +104 and clears bit 8 of its aim flags. Class names and field
// meanings are inferred from the original instructions.
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
        const Handle &a = o.first; const Handle &b = o.second;
        if (a.object) { first.object = a.object; first.object->refs++; }
        if (b.object) { second.object = b.object; second.object->refs++; }
    }
 __attribute__((always_inline)) inline void dispatch() { this->CostBase::dispatch(); } };
extern int w3d_flag_804aa594;
extern "C" int w3d_ai_weapon_available(int);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(Ptr32<CostBase>);
struct Weapon18 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon188dispatchEv")); Weapon18(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_8Weapon18, "__vt_8Weapon18");  weapon = 18; aim = 3137; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Aim1345 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Aim13458dispatchEv")); Aim1345(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Aim1345, "__vt_7Aim1345");  aim = 1345; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon23 : Aim1345 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon238dispatchEv")); Weapon23(const WeaponPlan &o) : Aim1345(o) { W3D_SET_VPTR(this->Aim1345::w3d_vptr_CostBase, w3d_vt___vt_8Weapon23, "__vt_8Weapon23");  weapon = 23; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1345::dispatch(); } };
struct MethodMember { char unknown00[184]; MethodMember(); };
struct Weapon29 : Aim1345 {
    MethodMember method __attribute__((aligned(__alignof__(Aim1345))));
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon298dispatchEv"));
    Weapon29(const WeaponPlan &o) : Aim1345(o) { W3D_SET_VPTR(this->Aim1345::w3d_vptr_CostBase, w3d_vt___vt_8Weapon29, "__vt_8Weapon29");  weapon = 29; aim &= ~0x100; }
 __attribute__((always_inline)) inline void dispatch() { this->Aim1345::dispatch(); } };
struct Weapon24 : Aim1345 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon248dispatchEv")); Weapon24(const WeaponPlan &o) : Aim1345(o) { W3D_SET_VPTR(this->Aim1345::w3d_vptr_CostBase, w3d_vt___vt_8Weapon24, "__vt_8Weapon24");  weapon = 24; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1345::dispatch(); } };
extern "C" int w3d_d28a_weapon_plans_special_800109b0(Ptr32<WeaponPlan> self)
{
    int any = 0;
    if (w3d_ai_weapon_available(18)) {
        Ptr32<Weapon18> plan = new (w3d_auto_8001523c(104)) Weapon18(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(29)) {
        Ptr32<Weapon29> plan = new (w3d_auto_8001523c(288)) Weapon29(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(23)) {
        Ptr32<Weapon23> plan = new (w3d_auto_8001523c(104)) Weapon23(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(24)) {
        Ptr32<Weapon24> plan = new (w3d_auto_8001523c(104)) Weapon24(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}


