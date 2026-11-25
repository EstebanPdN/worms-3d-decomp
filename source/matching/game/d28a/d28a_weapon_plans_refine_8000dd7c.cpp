// GWMP8P rev0 0x8000dd7c. Refreshes a weapon plan's predicted target, then
// clones it into two follow-up plans for weapons 3 and 25 when available.
// Clones share the counted handles at +76 and +84. Class names and field
// meanings are inferred from the original instructions.
inline void *operator new(unsigned int, void *place) { return place; }
struct WeaponPlan;
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
struct Ranged : WeaponPlan { virtual void dispatch(); Ranged(const WeaponPlan &o) : WeaponPlan(o) { aim = 368; } };
struct Bazooka : Ranged {
    virtual void dispatch();
    Bazooka(const WeaponPlan &o) : Ranged(o) { weapon = 3; }
};
struct Grenade : Ranged {
    virtual void dispatch();
    Grenade(const WeaponPlan &o) : Ranged(o) { weapon = 25; }
};
struct Body { char unknown00[32]; float energy; };
struct BodyList { Body **start; Body *&operator[](int i) { return start[i]; } };
extern BodyList *w3d_bodies_804aa750;
extern int w3d_flag_804aa594;
extern "C" Vec k5a_body_predict_position_800196dc(Body *, float);
extern "C" int w3d_ai_weapon_available(int);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(CostBase *);
extern "C" int w3d_d28a_weapon_plans_refine_8000dd7c(WeaponPlan *self)
{
    int any = 0;
    if (!self->Done()) {
        Body *b = (*w3d_bodies_804aa750)[self->index];
        float t = 0.0f;
        if (b->energy > t) self->position = k5a_body_predict_position_800196dc(b, t);
    }
    if (w3d_ai_weapon_available(3)) {
        Bazooka *plan = new (w3d_auto_8001523c(104)) Bazooka(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(25)) {
        Grenade *plan = new (w3d_auto_8001523c(104)) Grenade(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}
