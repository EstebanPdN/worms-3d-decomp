// GWMP8P rev0 0x8000c14c. Clones a plan into follow-up plans for eleven
// weapons when available. Between groups it refreshes the predicted target
// and later restores the saved position with a height offset, for undecided
// plans. Class names and field meanings are inferred from the original
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
struct Aim327 : WeaponPlan { virtual void dispatch(); Aim327(const WeaponPlan &o) : WeaponPlan(o) { aim = 327; } };
struct Weapon15 : Aim327 { virtual void dispatch(); Weapon15(const WeaponPlan &o) : Aim327(o) { weapon = 15; } };
struct Weapon20 : Aim327 { virtual void dispatch(); Weapon20(const WeaponPlan &o) : Aim327(o) { weapon = 20; } };
struct Weapon21 : WeaponPlan { virtual void dispatch(); Weapon21(const WeaponPlan &o) : WeaponPlan(o) { weapon = 21; aim = 335; } };
struct Weapon0 : Aim327 { virtual void dispatch(); Weapon0(const WeaponPlan &o) : Aim327(o) { weapon = 0; } };
struct Weapon1 : WeaponPlan { virtual void dispatch(); Weapon1(const WeaponPlan &o) : WeaponPlan(o) { weapon = 1; aim = 335; } };
struct Weapon5 : Aim327 { virtual void dispatch(); Weapon5(const WeaponPlan &o) : Aim327(o) { weapon = 5; } };
struct Weapon6 : WeaponPlan { virtual void dispatch(); Weapon6(const WeaponPlan &o) : WeaponPlan(o) { weapon = 6; aim = 335; } };
struct Weapon34 : WeaponPlan { virtual void dispatch(); Weapon34(const WeaponPlan &o) : WeaponPlan(o) { weapon = 34; aim = 335; } };
struct Aim471 : WeaponPlan { virtual void dispatch(); Aim471(const WeaponPlan &o) : WeaponPlan(o) { aim = 471; } };
struct Weapon14 : Aim471 { virtual void dispatch(); Weapon14(const WeaponPlan &o) : Aim471(o) { weapon = 14; } };
struct Weapon16 : Aim471 { virtual void dispatch(); Weapon16(const WeaponPlan &o) : Aim471(o) { weapon = 16; } };
struct Weapon2 : WeaponPlan { virtual void dispatch(); Weapon2(const WeaponPlan &o) : WeaponPlan(o) { weapon = 2; aim = 335; } };
struct Body { char unknown00[32]; float energy; };
struct BodyList { Body **start; Body *&operator[](int i) { return start[i]; } };
extern BodyList *w3d_bodies_804aa750;
extern "C" Vec k5a_body_predict_position_800196dc(Body *, float);
struct Settings { char unknown00[32]; float climb; };
extern Settings *w3d_settings_804aa6d8;
extern "C" int w3d_d28a_weapon_plans_main_8000c14c(WeaponPlan *self)
{
    int any = 0;
    if (w3d_ai_weapon_available(15)) {
        Weapon15 *plan = new (w3d_auto_8001523c(104)) Weapon15(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }

    if (w3d_ai_weapon_available(20)) {
        Weapon20 *plan = new (w3d_auto_8001523c(104)) Weapon20(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(21)) {
        Weapon21 *plan = new (w3d_auto_8001523c(104)) Weapon21(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    Vec saved; const Vec &o = self->position; float ax = o.x, ay = o.y, az = o.z; saved.x = ax; saved.y = ay; saved.z = az;
    if (!self->Done()) {
        Body *b = (*w3d_bodies_804aa750)[self->index];
        float t = 0.0f;
        if (b->energy > t) self->position = k5a_body_predict_position_800196dc(b, t);
    }
    if (w3d_ai_weapon_available(0)) {
        Weapon0 *plan = new (w3d_auto_8001523c(104)) Weapon0(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(1)) {
        Weapon1 *plan = new (w3d_auto_8001523c(104)) Weapon1(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(5)) {
        Weapon5 *plan = new (w3d_auto_8001523c(104)) Weapon5(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(6)) {
        Weapon6 *plan = new (w3d_auto_8001523c(104)) Weapon6(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(34)) {
        Weapon34 *plan = new (w3d_auto_8001523c(104)) Weapon34(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(14)) {
        Weapon14 *plan = new (w3d_auto_8001523c(104)) Weapon14(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(16)) {
        Weapon16 *plan = new (w3d_auto_8001523c(104)) Weapon16(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (!self->Done()) {
        self->position = saved;
        self->position.y += w3d_settings_804aa6d8->climb;
    }
    if (w3d_ai_weapon_available(2)) {
        Weapon2 *plan = new (w3d_auto_8001523c(104)) Weapon2(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}
