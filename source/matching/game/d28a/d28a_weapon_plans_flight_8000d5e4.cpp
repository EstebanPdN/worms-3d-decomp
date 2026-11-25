// GWMP8P rev0 0x8000d5e4. Advances a weapon plan's height by a random step,
// then clones it into follow-up plans for weapons 9, 8 and 30 when
// available. Class names and field meanings are inferred from the original
// instructions.
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
struct Weapon9 : WeaponPlan { virtual void dispatch(); Weapon9(const WeaponPlan &o) : WeaponPlan(o) { weapon = 9; aim = 4935; } };
struct Aim4423 : WeaponPlan { virtual void dispatch(); Aim4423(const WeaponPlan &o) : WeaponPlan(o) { aim = 4423; } };
struct Weapon8 : Aim4423 { virtual void dispatch(); Weapon8(const WeaponPlan &o) : Aim4423(o) { weapon = 8; } };
struct Weapon30 : Aim4423 { virtual void dispatch(); Weapon30(const WeaponPlan &o) : Aim4423(o) { weapon = 30; } };
extern "C" float w3d_auto_80015794();
extern "C" int w3d_d28a_weapon_plans_flight_8000d5e4(WeaponPlan *self)
{
    int any = 0;
    if (!self->Done()) self->position.y += w3d_auto_80015794() * 0.5f;
    if (w3d_ai_weapon_available(9)) {
        Weapon9 *plan = new (w3d_auto_8001523c(104)) Weapon9(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(8)) {
        Weapon8 *plan = new (w3d_auto_8001523c(104)) Weapon8(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(30)) {
        Weapon30 *plan = new (w3d_auto_8001523c(104)) Weapon30(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}
