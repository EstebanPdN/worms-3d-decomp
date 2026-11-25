// GWMP8P rev0 0x80017044. Scatters five AI path plans around the map centre.
inline void *operator new(unsigned int, void *place) { return place; }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Grid;
struct Settings { char unknown00[228]; float spread; };
extern Settings *w3d_settings_804aa6d8;
extern int w3d_flag_804aa594;
extern void *w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
extern Grid *w3d_grid_804b1758;
extern Vec w3d_center_8041d3a0;
extern "C" float s19_random_unit_80015810();
extern "C" Vec k2a_grid_position_8001f9f0(Grid *, const Vec &);
extern "C" void *w3d_auto_8001523c(unsigned int);
struct CostBase {
    int unknown0;
    float distance;
    int state;
    virtual void dispatch();
    CostBase();
};
struct PathPlan : CostBase {
    int selected;     /* +16 */
    Vec position;     /* +20 */
    void *path;       /* +32 */
    int active;       /* +36 */
    int flag;         /* +40 */
    virtual void dispatch();
    PathPlan() : selected(-1), path(0), active(1), flag(0) {}
};
struct M1 : PathPlan { virtual void dispatch(); M1() {} };
struct M2 : M1 { virtual void dispatch(); M2() {} };
struct M3 : M2 { virtual void dispatch(); M3() {} };
struct Plan : M3 {
    virtual void dispatch();
    Plan(const Vec &p) { position = p; }
};

extern "C" void w3d_ai_push_plan_b(Plan *);
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
extern "C" int w3d_d44s_plan_scatter_push_80017044()
{
    w3d_flag_804aa594 = 1;
    if (Ready()) {
        for (int i = 0; i < 5; i++) {
            Vec p = w3d_center_8041d3a0;
            float s = w3d_settings_804aa6d8->spread;
            p.x += s19_random_unit_80015810() * (s + s) - s;
            p.z += s19_random_unit_80015810() * (s + s) - s;
            p = k2a_grid_position_8001f9f0(w3d_grid_804b1758, p);
            Plan *plan = (Plan *)w3d_auto_8001523c(44);
            new (plan) Plan(p);

            plan->active = 0;
            plan->selected = 100;
            w3d_ai_push_plan_b(plan);
        }
        return 1;
    }
    return 0;
}
