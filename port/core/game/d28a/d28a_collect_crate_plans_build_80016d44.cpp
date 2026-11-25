#include "w3d_ptr.h"
#line 1 "d28a_collect_crate_plans_build_80016d44.cpp"
// GWMP8P rev0 0x80016d44. Builds the collect-crate plans: one per crate on
// the map whose team allows it, then one per node of a named route list,
// popping the list and deleting it. Field names are inferred from the
// original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct CostBase {
    int unknown0;
    float distance;
    int state;
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8CostBase8dispatchEv"));
    CostBase();
 __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_CostBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_CostBase; };
struct PathPlan : CostBase {
    int selected __attribute__((aligned(__alignof__(CostBase))));     /* +16 */
    Vec position;     /* +20 */
    Ptr32<void> path;       /* +32 */
    int active;       /* +36 */
    int flag;         /* +40 */
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN8PathPlan8dispatchEv"));
    PathPlan() { W3D_SET_VPTR(this->CostBase::w3d_vptr_CostBase, w3d_vt___vt_8PathPlan, "__vt_8PathPlan");  path = 0; selected = -1; active = 1; flag = 0; }
 __attribute__((always_inline)) inline void dispatch() { this->CostBase::dispatch(); } };
struct Crate { char unknown00[40]; Vec position; char unknown34[84]; int team; };
struct CollectCrate : PathPlan {
    Ptr32<Crate> crate __attribute__((aligned(__alignof__(PathPlan))));     /* +44 */
    float weight;     /* +48 */
    void w3d_r_dispatch() __asm__(W3D_SYM("_ZN12CollectCrate8dispatchEv"));
    CollectCrate(const Vec &p, Ptr32<Crate> c, float w) { W3D_SET_VPTR(this->PathPlan::w3d_vptr_CostBase, w3d_vt___vt_12CollectCrate, "__vt_12CollectCrate");  position = p; crate = c; weight = w; }
 __attribute__((always_inline)) inline void dispatch() { this->PathPlan::dispatch(); } };
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct Worm { char unknown00[213]; unsigned char team; };
struct Node { int unknown0; Vec position; char unknown10[24]; Vec velocity; };
struct String { Ptr32<const char> text; };
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
inline bool operator!=(const String &a, const char *b) { return strcmp(a.text, b) != 0; }
struct NodeList {
    Ptr32<Ptr32<Node>> start; Ptr32<Ptr32<Node>> finish;
    bool empty() const { return start == finish; }
    Ptr32<Node> pop() { Ptr32<Ptr32<Node>> f = finish - 1; Ptr32<Node> n = *f; finish = f; return n; }
    ~NodeList();
    static void operator delete(void *p);
};
extern "C" void w3d_handle_storage_release(Ptr32<void>);
extern "C" void w3d_actor_member_delete_backend(Ptr32<void>);
inline void NodeList::operator delete(void *p) { w3d_actor_member_delete_backend(p); }
inline NodeList::~NodeList() { if (start) w3d_handle_storage_release(start); }
struct Settings { char unknown00[144]; String mode; char unknown94[340]; int crates; };
struct PlayerList;
extern Ptr32<Settings> w3d_settings_804aa6d8;
extern int w3d_flag_804aa594;
extern Ptr32<void> w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
extern Ptr32<PlayerList> w3d_players_804aab4c;
extern Vec w3d_center_8041d3a0;
extern "C" int w3d_player_list_team_count_8008c34c(Ptr32<PlayerList>);
extern "C" Ptr32<Crate> s19_lookup_slot_8008c360(Ptr32<PlayerList>, int);
extern "C" Ptr32<Worm> w3d_auto_80015540();
extern "C" Ptr32<NodeList> FUN_80015960(Ptr32<String>);
extern "C" Ptr32<void> w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(Ptr32<PathPlan>);
inline float DistSq(const Vec &a, const Vec &b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
inline void Push(const Vec &p, Ptr32<Crate> c, float w)
{
    Ptr32<CollectCrate> plan = new (w3d_auto_8001523c(52)) CollectCrate(p, c, w);
    w3d_ai_push_plan_b(plan);
}
extern "C" int w3d_d28a_collect_crate_plans_build_80016d44()
{
    w3d_flag_804aa594 = 1;
    if (Ready()) {
        int any = 0;
        int n = w3d_player_list_team_count_8008c34c(w3d_players_804aab4c);
        if (n > 0 && w3d_settings_804aa6d8->crates) {
            int team = w3d_auto_80015540()->team;
            for (int i = 0; i < n; i++) {
                Ptr32<Crate> c = s19_lookup_slot_8008c360(w3d_players_804aab4c, i);
                Vec p; const Vec &o = c->position; float ax = o.x, ay = o.y, az = o.z; p.x = ax; p.y = ay; p.z = az;
                const Vec &r = p;
                if (c->team == -1 || c->team == team) {
                    Push(r, c, 1.0f);
                }
            }
            any = 1;
        }
        String &mode = w3d_settings_804aa6d8->mode;
        if (mode != "") {
            Ptr32<NodeList> list = FUN_80015960(&mode);
            if (list) {
                while (!list->empty()) {
                    Ptr32<Node> node = list->pop();
                    Vec p; const Vec &o = node->position; float ax = o.x, ay = o.y, az = o.z; p.x = ax; p.y = ay; p.z = az;

 if (DistSq(p, w3d_center_8041d3a0) > 40.0f) {
   Vec v = node->velocity;
   float w = v.y * 7.5f;
   Push(p, 0, w);
   any = 1;
 }

                }
                delete list;
            }
        }
        return any;
    }
    return 0;
}


