// GWMP8P rev0 0x8000a2d0. Clones a plan into two follow-up plans of
// different classes and pushes both. Class names and field meanings are
// inferred from the original instructions.
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
        const Handle &a = o.first;
        if (a.object) { first.object = a.object; first.object->refs++; }
        const Handle &b = o.second;
        if (b.object) { second.object = b.object; second.object->refs++; }
    }
};
extern int w3d_flag_804aa594;
extern "C" int w3d_ai_weapon_available(int);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(CostBase *);
struct PlanA : WeaponPlan { virtual void dispatch(); PlanA(const WeaponPlan &o) : WeaponPlan(o) { } };
struct PlanB : WeaponPlan { virtual void dispatch(); PlanB(const WeaponPlan &o) : WeaponPlan(o) { } };
extern "C" int w3d_d28a_plan_clone_pair_8000a2d0(WeaponPlan *self)
{
    PlanA *a = new (w3d_auto_8001523c(104)) PlanA(*self);
    w3d_ai_push_plan_b(a);
    PlanB *b = new (w3d_auto_8001523c(104)) PlanB(*self);
    w3d_ai_push_plan_b(b);
    return 1;
}
