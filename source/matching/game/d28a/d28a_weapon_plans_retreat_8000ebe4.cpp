// GWMP8P rev0 0x8000ebe4. Refreshes the plan's predicted target, reads the
// DefaultRetreatTime property, then clones the plan into follow-up plans:
// weapons 10 to 13 for undecided plans, 7 and 33 when also late, and 4, 1,
// 2, 6 when late. Class names and field meanings are inferred from the
// original instructions.
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
struct Aim1092 : WeaponPlan { virtual void dispatch(); Aim1092(const WeaponPlan &o) : WeaponPlan(o) { aim = 1092; } };
struct Weapon10 : Aim1092 { virtual void dispatch(); Weapon10(const WeaponPlan &o) : Aim1092(o) { weapon = 10; } };
struct Weapon11 : Aim1092 { virtual void dispatch(); Weapon11(const WeaponPlan &o) : Aim1092(o) { weapon = 11; } };
struct Weapon12 : Aim1092 { virtual void dispatch(); Weapon12(const WeaponPlan &o) : Aim1092(o) { weapon = 12; } };
struct Weapon13 : Aim1092 { virtual void dispatch(); Weapon13(const WeaponPlan &o) : Aim1092(o) { weapon = 13; } };
struct Aim1345 : WeaponPlan { virtual void dispatch(); Aim1345(const WeaponPlan &o) : WeaponPlan(o) { aim = 1345; } };
struct Weapon7 : Aim1345 { virtual void dispatch(); Weapon7(const WeaponPlan &o) : Aim1345(o) { weapon = 7; } };
struct Weapon33 : Aim1345 { virtual void dispatch(); Weapon33(const WeaponPlan &o) : Aim1345(o) { weapon = 33; } };
struct Weapon4 : Aim1345 { virtual void dispatch(); Weapon4(const WeaponPlan &o) : Aim1345(o) { weapon = 4; } };
struct Aim1353 : WeaponPlan { virtual void dispatch(); Aim1353(const WeaponPlan &o) : WeaponPlan(o) { aim = 1353; } };
struct Weapon1 : Aim1353 { virtual void dispatch(); Weapon1(const WeaponPlan &o) : Aim1353(o) { weapon = 1; } };
struct Weapon2 : Aim1353 { virtual void dispatch(); Weapon2(const WeaponPlan &o) : Aim1353(o) { weapon = 2; } };
struct Weapon6 : Aim1353 { virtual void dispatch(); Weapon6(const WeaponPlan &o) : Aim1353(o) { weapon = 6; } };
struct Body { char unknown00[32]; float energy; };
struct BodyList { Body **start; Body *&operator[](int i) { return start[i]; } };
extern BodyList *w3d_bodies_804aa750;
extern "C" Vec k5a_body_predict_position_800196dc(Body *, float);
struct PropertyName { const char *text; };
extern "C" int w3d_auto_800fc1f0(PropertyName *, int *);
extern void *w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d28a_weapon_plans_retreat_8000ebe4(WeaponPlan *self)
{
    int any = 0;
    Body *b = (*w3d_bodies_804aa750)[self->index];
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
        Weapon10 *plan = new (w3d_auto_8001523c(104)) Weapon10(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(11)) {
        Weapon11 *plan = new (w3d_auto_8001523c(104)) Weapon11(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(12)) {
        Weapon12 *plan = new (w3d_auto_8001523c(104)) Weapon12(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(13)) {
        Weapon13 *plan = new (w3d_auto_8001523c(104)) Weapon13(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
        if (late) {
    if (w3d_ai_weapon_available(7)) {
        Weapon7 *plan = new (w3d_auto_8001523c(104)) Weapon7(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(33)) {
        Weapon33 *plan = new (w3d_auto_8001523c(104)) Weapon33(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
        }
    }
    if (late) {
    if (w3d_ai_weapon_available(4)) {
        Weapon4 *plan = new (w3d_auto_8001523c(104)) Weapon4(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(1)) {
        Weapon1 *plan = new (w3d_auto_8001523c(104)) Weapon1(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(2)) {
        Weapon2 *plan = new (w3d_auto_8001523c(104)) Weapon2(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(6)) {
        Weapon6 *plan = new (w3d_auto_8001523c(104)) Weapon6(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    }
    w3d_flag_804aa594 = 1;
    return any;
}
