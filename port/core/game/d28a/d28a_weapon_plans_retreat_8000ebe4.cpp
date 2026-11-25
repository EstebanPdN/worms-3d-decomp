#include "w3d_ptr.h"
#line 1 "d28a_weapon_plans_retreat_8000ebe4.cpp"
// GWMP8P rev0 0x8000ebe4. Refreshes the plan's predicted target, reads the
// DefaultRetreatTime property, then clones the plan into follow-up plans:
// weapons 10 to 13 for undecided plans, 7 and 33 when also late, and 4, 1,
// 2, 6 when late. Class names and field meanings are inferred from the
// original instructions.
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
struct Aim1092 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Aim10928dispatchEv")); Aim1092(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Aim1092, "__vt_7Aim1092");  aim = 1092; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon10 : Aim1092 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon108dispatchEv")); Weapon10(const WeaponPlan &o) : Aim1092(o) { W3D_SET_VPTR(this->Aim1092::w3d_vptr_CostBase, w3d_vt___vt_8Weapon10, "__vt_8Weapon10");  weapon = 10; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1092::dispatch(); } };
struct Weapon11 : Aim1092 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon118dispatchEv")); Weapon11(const WeaponPlan &o) : Aim1092(o) { W3D_SET_VPTR(this->Aim1092::w3d_vptr_CostBase, w3d_vt___vt_8Weapon11, "__vt_8Weapon11");  weapon = 11; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1092::dispatch(); } };
struct Weapon12 : Aim1092 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon128dispatchEv")); Weapon12(const WeaponPlan &o) : Aim1092(o) { W3D_SET_VPTR(this->Aim1092::w3d_vptr_CostBase, w3d_vt___vt_8Weapon12, "__vt_8Weapon12");  weapon = 12; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1092::dispatch(); } };
struct Weapon13 : Aim1092 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon138dispatchEv")); Weapon13(const WeaponPlan &o) : Aim1092(o) { W3D_SET_VPTR(this->Aim1092::w3d_vptr_CostBase, w3d_vt___vt_8Weapon13, "__vt_8Weapon13");  weapon = 13; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1092::dispatch(); } };
struct Aim1345 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Aim13458dispatchEv")); Aim1345(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Aim1345, "__vt_7Aim1345");  aim = 1345; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon7 : Aim1345 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon78dispatchEv")); Weapon7(const WeaponPlan &o) : Aim1345(o) { W3D_SET_VPTR(this->Aim1345::w3d_vptr_CostBase, w3d_vt___vt_7Weapon7, "__vt_7Weapon7");  weapon = 7; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1345::dispatch(); } };
struct Weapon33 : Aim1345 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8Weapon338dispatchEv")); Weapon33(const WeaponPlan &o) : Aim1345(o) { W3D_SET_VPTR(this->Aim1345::w3d_vptr_CostBase, w3d_vt___vt_8Weapon33, "__vt_8Weapon33");  weapon = 33; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1345::dispatch(); } };
struct Weapon4 : Aim1345 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon48dispatchEv")); Weapon4(const WeaponPlan &o) : Aim1345(o) { W3D_SET_VPTR(this->Aim1345::w3d_vptr_CostBase, w3d_vt___vt_7Weapon4, "__vt_7Weapon4");  weapon = 4; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1345::dispatch(); } };
struct Aim1353 : WeaponPlan { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Aim13538dispatchEv")); Aim1353(const WeaponPlan &o) : WeaponPlan(o) { W3D_SET_VPTR(this->WeaponPlan::w3d_vptr_CostBase, w3d_vt___vt_7Aim1353, "__vt_7Aim1353");  aim = 1353; }  __attribute__((always_inline)) inline void dispatch() { this->WeaponPlan::dispatch(); } };
struct Weapon1 : Aim1353 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon18dispatchEv")); Weapon1(const WeaponPlan &o) : Aim1353(o) { W3D_SET_VPTR(this->Aim1353::w3d_vptr_CostBase, w3d_vt___vt_7Weapon1, "__vt_7Weapon1");  weapon = 1; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1353::dispatch(); } };
struct Weapon2 : Aim1353 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon28dispatchEv")); Weapon2(const WeaponPlan &o) : Aim1353(o) { W3D_SET_VPTR(this->Aim1353::w3d_vptr_CostBase, w3d_vt___vt_7Weapon2, "__vt_7Weapon2");  weapon = 2; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1353::dispatch(); } };
struct Weapon6 : Aim1353 { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN7Weapon68dispatchEv")); Weapon6(const WeaponPlan &o) : Aim1353(o) { W3D_SET_VPTR(this->Aim1353::w3d_vptr_CostBase, w3d_vt___vt_7Weapon6, "__vt_7Weapon6");  weapon = 6; }  __attribute__((always_inline)) inline void dispatch() { this->Aim1353::dispatch(); } };
struct Body { char unknown00[32]; float energy; };
struct BodyList { Ptr32<Ptr32<Body>> start; Ptr32<Body> & operator[](int i) { return start[i]; } };
extern Ptr32<BodyList> w3d_bodies_804aa750;
extern "C" Vec k5a_body_predict_position_800196dc(Ptr32<Body>, float);
struct PropertyName { Ptr32<const char> text; };
extern "C" int w3d_auto_800fc1f0(Ptr32<PropertyName>, Ptr32<int>);
extern Ptr32<void> w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d28a_weapon_plans_retreat_8000ebe4(Ptr32<WeaponPlan> self)
{
    int any = 0;
    Ptr32<Body> b = (*w3d_bodies_804aa750)[self->index];
    float t = 0.0f;
    if (b->energy > t) self->position = k5a_body_predict_position_800196dc(b, t);
    PropertyName name;
    name.text = "DefaultRetreatTime";
    int value;
    w3d_auto_800fc1f0(&name, &value);
    bool late = value > 1999;
    if (!Ready()) late = false;
    if (!self->Done()) {
    if (w3d_ai_weapon_available(10)) {
        Ptr32<Weapon10> plan = new (w3d_auto_8001523c(104)) Weapon10(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(11)) {
        Ptr32<Weapon11> plan = new (w3d_auto_8001523c(104)) Weapon11(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(12)) {
        Ptr32<Weapon12> plan = new (w3d_auto_8001523c(104)) Weapon12(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(13)) {
        Ptr32<Weapon13> plan = new (w3d_auto_8001523c(104)) Weapon13(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
        if (late) {
    if (w3d_ai_weapon_available(7)) {
        Ptr32<Weapon7> plan = new (w3d_auto_8001523c(104)) Weapon7(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(33)) {
        Ptr32<Weapon33> plan = new (w3d_auto_8001523c(104)) Weapon33(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
        }
    }
    if (late) {
    if (w3d_ai_weapon_available(4)) {
        Ptr32<Weapon4> plan = new (w3d_auto_8001523c(104)) Weapon4(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(1)) {
        Ptr32<Weapon1> plan = new (w3d_auto_8001523c(104)) Weapon1(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(2)) {
        Ptr32<Weapon2> plan = new (w3d_auto_8001523c(104)) Weapon2(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(6)) {
        Ptr32<Weapon6> plan = new (w3d_auto_8001523c(104)) Weapon6(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    }
    w3d_flag_804aa594 = 1;
    return any;
}


