// GWMP8P rev0 0x8001148c. Clones a plan into follow-up plans for weapons 2
// (when the game is ready), 17, 26 and 43 when available. Class names and
// field meanings are inferred from the original instructions.
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
struct Base2 : WeaponPlan { virtual void dispatch(); Base2(const WeaponPlan &o) : WeaponPlan(o) { aim = 1353; weapon = 2; } };
struct Weapon2 : Base2 { virtual void dispatch(); Weapon2(const WeaponPlan &o) : Base2(o) { } };
struct Weapon17 : WeaponPlan { virtual void dispatch(); Weapon17(const WeaponPlan &o) : WeaponPlan(o) { weapon = 17; aim = 64; } };
struct Weapon26 : WeaponPlan { virtual void dispatch(); Weapon26(const WeaponPlan &o) : WeaponPlan(o) { weapon = 26; aim = 64; } };
struct Weapon43 : WeaponPlan { virtual void dispatch(); Weapon43(const WeaponPlan &o) : WeaponPlan(o) { weapon = 43; aim = 64; } };
extern void *w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d28a_weapon_plans_close_8001148c(WeaponPlan *self)
{
    int any = 0;
    if (Ready() && w3d_ai_weapon_available(2)) {
        Weapon2 *plan = new (w3d_auto_8001523c(104)) Weapon2(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(17)) {
        Weapon17 *plan = new (w3d_auto_8001523c(104)) Weapon17(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(26)) {
        Weapon26 *plan = new (w3d_auto_8001523c(104)) Weapon26(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    if (w3d_ai_weapon_available(43)) {
        Weapon43 *plan = new (w3d_auto_8001523c(104)) Weapon43(*self);
        w3d_ai_push_plan_b(plan);
        any = 1;
    }
    w3d_flag_804aa594 = 1;
    return any;
}
