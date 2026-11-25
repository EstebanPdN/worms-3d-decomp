#include "w3d_ptr.h"
#line 1 "d28a_weapon_plans_main_8000c14c.cpp"
// GWMP8P rev0 0x8000c14c. Clones a plan into follow-up plans for eleven
// weapons when available. Between groups it refreshes the predicted target
// and later restores the saved position with a height offset, for undecided
// plans. Class names and field meanings are inferred from the original
// instructions.
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
struct Aim327 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN6Aim3278dispatchEv")); Aim327(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_6Aim327, "__vt_6Aim327");  aim = 327; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon15 : Aim327 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon158dispatchEv")); Weapon15(const WeaponPlan &o) : Aim327(o) { W3D_SET_VPTR(this->Aim327::w3d_vptr_CostBase, w3d_vt___vt_8Weapon15, "__vt_8Weapon15");  weapon = 15; }  __attribute__((always_inline)) inline void dispatch() { this->Aim327::dispatch(); } };
struct Weapon20 : Aim327 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon208dispatchEv")); Weapon20(const WeaponPlan &o) : Aim327(o) { W3D_SET_VPTR(this->Aim327::w3d_vptr_CostBase, w3d_vt___vt_8Weapon20, "__vt_8Weapon20");  weapon = 20; }  __attribute__((always_inline)) inline void dispatch() { this->Aim327::dispatch(); } };
struct Weapon21 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon218dispatchEv")); Weapon21(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_8Weapon21, "__vt_8Weapon21");  weapon = 21; aim = 335; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon0 : Aim327 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon08dispatchEv")); Weapon0(const WeaponPlan &o) : Aim327(o) { W3D_SET_VPTR(this->Aim327::w3d_vptr_CostBase, w3d_vt___vt_7Weapon0, "__vt_7Weapon0");  weapon = 0; }  __attribute__((always_inline)) inline void dispatch() { this->Aim327::dispatch(); } };
struct Weapon1 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon18dispatchEv")); Weapon1(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Weapon1, "__vt_7Weapon1");  weapon = 1; aim = 335; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon5 : Aim327 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon58dispatchEv")); Weapon5(const WeaponPlan &o) : Aim327(o) { W3D_SET_VPTR(this->Aim327::w3d_vptr_CostBase, w3d_vt___vt_7Weapon5, "__vt_7Weapon5");  weapon = 5; }  __attribute__((always_inline)) inline void dispatch() { this->Aim327::dispatch(); } };
struct Weapon6 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon68dispatchEv")); Weapon6(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Weapon6, "__vt_7Weapon6");  weapon = 6; aim = 335; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon34 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon348dispatchEv")); Weapon34(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_8Weapon34, "__vt_8Weapon34");  weapon = 34; aim = 335; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Aim471 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN6Aim4718dispatchEv")); Aim471(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_6Aim471, "__vt_6Aim471");  aim = 471; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon14 : Aim471 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon148dispatchEv")); Weapon14(const WeaponPlan &o) : Aim471(o) { W3D_SET_VPTR(this->Aim471::w3d_vptr_CostBase, w3d_vt___vt_8Weapon14, "__vt_8Weapon14");  weapon = 14; }  __attribute__((always_inline)) inline void dispatch() { this->Aim471::dispatch(); } };
struct Weapon16 : Aim471 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon168dispatchEv")); Weapon16(const WeaponPlan &o) : Aim471(o) { W3D_SET_VPTR(this->Aim471::w3d_vptr_CostBase, w3d_vt___vt_8Weapon16, "__vt_8Weapon16");  weapon = 16; }  __attribute__((always_inline)) inline void dispatch() { this->Aim471::dispatch(); } };
struct Weapon2 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon28dispatchEv")); Weapon2(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Weapon2, "__vt_7Weapon2");  weapon = 2; aim = 335; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Body { char unknown00[32]; float energy; };
struct BodyList { Ptr32<Ptr32<Body>> start; Ptr32<Body> & operator[](int i) { return start[i]; } };
extern Ptr32<BodyList> w3d_bodies_804aa750;
extern "C" Vec k5a_body_predict_position_800196dc(Ptr32<Body>, float);
struct Settings { char unknown00[32]; float climb; };
extern Ptr32<Settings> w3d_settings_804aa6d8;
extern "C" int w3d_d28a_weapon_plans_main_8000c14c(Ptr32<WeaponPlan> self)
{
    int any = 0;
    if (w3d_ai_weapon_available(15)) {
        Ptr32<Weapon15> plan = new (w3d_auto_8001523c(104)) Weapon15(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }

    if (w3d_ai_weapon_available(20)) {
        Ptr32<Weapon20> plan = new (w3d_auto_8001523c(104)) Weapon20(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(21)) {
        Ptr32<Weapon21> plan = new (w3d_auto_8001523c(104)) Weapon21(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    Vec saved; const Vec &o = self->position; float ax = o.x, ay = o.y, az = o.z; saved.x = ax; saved.y = ay; saved.z = az;
    if (!self->Done()) {
        Ptr32<Body> b = (*w3d_bodies_804aa750)[self->index];
        float t = 0.0f;
        if (b->energy > t) self->position = k5a_body_predict_position_800196dc(b, t);
    }
    if (w3d_ai_weapon_available(0)) {
        Ptr32<Weapon0> plan = new (w3d_auto_8001523c(104)) Weapon0(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(1)) {
        Ptr32<Weapon1> plan = new (w3d_auto_8001523c(104)) Weapon1(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(5)) {
        Ptr32<Weapon5> plan = new (w3d_auto_8001523c(104)) Weapon5(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(6)) {
        Ptr32<Weapon6> plan = new (w3d_auto_8001523c(104)) Weapon6(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(34)) {
        Ptr32<Weapon34> plan = new (w3d_auto_8001523c(104)) Weapon34(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(14)) {
        Ptr32<Weapon14> plan = new (w3d_auto_8001523c(104)) Weapon14(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(16)) {
        Ptr32<Weapon16> plan = new (w3d_auto_8001523c(104)) Weapon16(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (!self->Done()) {
        self->position = saved;
        self->position.y += w3d_settings_804aa6d8->climb;
    }
    if (w3d_ai_weapon_available(2)) {
        Ptr32<Weapon2> plan = new (w3d_auto_8001523c(104)) Weapon2(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}


