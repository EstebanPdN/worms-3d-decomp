// GWMP8P rev0 0x800109b0. Clones a plan into follow-up plans for weapons 18,
// 29, 23 and 24 when available. Weapon 29's plan is 288 bytes with a method
// member at +104 and clears bit 8 of its aim flags. Class names and field
// meanings are inferred from the original instructions.
inline void *operator new(unsigned int, void *place) { return place; }
struct Vec { float x, y, z; };
struct Counted { char unknown00[44]; int refs; };
struct Handle {
    int kind;
    Counted *object;
    Handle() : object(0) {}
};
struct CostBase {
    int unknown0;
    float distance;
    int state;
    virtual void dispatch();
    CostBase();
};
struct WeaponPlan : CostBase {
    int index;            /* +16 */
    int weapon;           /* +20 */
    Vec position;         /* +24 */
    char unknown24[28];   /* +36 */
    unsigned char done;   /* +64 */
    int aim;              /* +68 */
    Handle first;         /* +72 */
    Handle second;        /* +80 */
    char unknown58[16];   /* +88 */
    virtual void dispatch();
    bool Done() const { return done != 0; }
    WeaponPlan(const WeaponPlan &o)
    {
        *this = o;
        distance = -1e20f;
        const Handle &a = o.first; const Handle &b = o.second;
        if (a.object) { first.object = a.object; first.object->refs++; }
        if (b.object) { second.object = b.object; second.object->refs++; }
    }
};
extern int w3d_flag_804aa594;
extern "C" int w3d_ai_weapon_available(int);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(CostBase *);
struct Weapon18 : WeaponPlan { virtual void dispatch(); Weapon18(const WeaponPlan &o) : WeaponPlan(o) { weapon = 18; aim = 3137; } };
struct Aim1345 : WeaponPlan { virtual void dispatch(); Aim1345(const WeaponPlan &o) : WeaponPlan(o) { aim = 1345; } };
struct Weapon23 : Aim1345 { virtual void dispatch(); Weapon23(const WeaponPlan &o) : Aim1345(o) { weapon = 23; } };
struct MethodMember { char unknown00[184]; MethodMember(); };
struct Weapon29 : Aim1345 {
    MethodMember method;
    virtual void dispatch();
    Weapon29(const WeaponPlan &o) : Aim1345(o) { weapon = 29; aim &= ~0x100; }
};
struct Weapon24 : Aim1345 { virtual void dispatch(); Weapon24(const WeaponPlan &o) : Aim1345(o) { weapon = 24; } };
extern "C" int w3d_d28a_weapon_plans_special_800109b0(WeaponPlan *self)
{
    int any = 0;
    if (w3d_ai_weapon_available(18)) {
        Weapon18 *plan = new (w3d_auto_8001523c(104)) Weapon18(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(29)) {
        Weapon29 *plan = new (w3d_auto_8001523c(288)) Weapon29(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(23)) {
        Weapon23 *plan = new (w3d_auto_8001523c(104)) Weapon23(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(24)) {
        Weapon24 *plan = new (w3d_auto_8001523c(104)) Weapon24(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}
