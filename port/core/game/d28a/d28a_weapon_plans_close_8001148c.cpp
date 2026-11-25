#include "w3d_ptr.h"
#line 1 "d28a_weapon_plans_close_8001148c.cpp"
// GWMP8P rev0 0x8001148c. Clones a plan into follow-up plans for weapons 2
// (when the game is ready), 17, 26 and 43 when available. Class names and
// field meanings are inferred from the original instructions.
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
struct Base2 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN5Base28dispatchEv")); Base2(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_5Base2, "__vt_5Base2");  aim = 1353; weapon = 2; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon2 : Base2 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon28dispatchEv")); Weapon2(const WeaponPlan &o) : Base2(o) { W3D_SET_VPTR(this->Base2::w3d_vptr_CostBase, w3d_vt___vt_7Weapon2, "__vt_7Weapon2");  }  __attribute__((always_inline)) inline void dispatch() { this->Base2::dispatch(); } };
struct Weapon17 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon178dispatchEv")); Weapon17(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_8Weapon17, "__vt_8Weapon17");  weapon = 17; aim = 64; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon26 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon268dispatchEv")); Weapon26(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_8Weapon26, "__vt_8Weapon26");  weapon = 26; aim = 64; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon43 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon438dispatchEv")); Weapon43(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_8Weapon43, "__vt_8Weapon43");  weapon = 43; aim = 64; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
extern Ptr32<void> w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d28a_weapon_plans_close_8001148c(Ptr32<WeaponPlan> self)
{
    int any = 0;
    if (Ready() && w3d_ai_weapon_available(2)) {
        Ptr32<Weapon2> plan = new (w3d_auto_8001523c(104)) Weapon2(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(17)) {
        Ptr32<Weapon17> plan = new (w3d_auto_8001523c(104)) Weapon17(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(26)) {
        Ptr32<Weapon26> plan = new (w3d_auto_8001523c(104)) Weapon26(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(43)) {
        Ptr32<Weapon43> plan = new (w3d_auto_8001523c(104)) Weapon43(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}


