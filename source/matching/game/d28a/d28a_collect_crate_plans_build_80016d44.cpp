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
    PathPlan() { path = 0; selected = -1; active = 1; flag = 0; }
};
struct Crate { char unknown00[40]; Vec position; char unknown34[84]; int team; };
struct CollectCrate : PathPlan {
    Crate *crate;     /* +44 */
    float weight;     /* +48 */
    virtual void dispatch();
    CollectCrate(const Vec &p, Crate *c, float w) { position = p; crate = c; weight = w; }
};
inline void *operator new(unsigned int, void *place) { return place; }
struct Worm { char unknown00[213]; unsigned char team; };
struct Node { int unknown0; Vec position; char unknown10[24]; Vec velocity; };
struct String { const char *text; };
extern "C" int strcmp(const char *, const char *);
inline bool operator!=(const String &a, const char *b) { return strcmp(a.text, b) != 0; }
struct NodeList {
    Node **start, **finish;
    bool empty() const { return start == finish; }
    Node *pop() { Node **f = finish - 1; Node *n = *f; finish = f; return n; }
    ~NodeList();
    static void operator delete(void *p);
};
extern "C" void w3d_handle_storage_release(void *);
extern "C" void w3d_actor_member_delete_backend(void *);
inline void NodeList::operator delete(void *p) { w3d_actor_member_delete_backend(p); }
inline NodeList::~NodeList() { if (start) w3d_handle_storage_release(start); }
struct Settings { char unknown00[144]; String mode; char unknown94[340]; int crates; };
struct PlayerList;
extern Settings *w3d_settings_804aa6d8;
extern int w3d_flag_804aa594;
extern void *w3d_game_804aa6dc;
extern int w3d_busy_804aa6e0;
extern PlayerList *w3d_players_804aab4c;
extern Vec w3d_center_8041d3a0;
extern "C" int w3d_player_list_team_count_8008c34c(PlayerList *);
extern "C" Crate *s19_lookup_slot_8008c360(PlayerList *, int);
extern "C" Worm *w3d_auto_80015540();
extern "C" NodeList *FUN_80015960(String *);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_ai_push_plan_b(PathPlan *);
inline float DistSq(const Vec &a, const Vec &b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
inline bool Ready() { return w3d_game_804aa6dc != 0 && w3d_busy_804aa6e0 == 0; }
inline void Push(const Vec &p, Crate *c, float w)
{
    CollectCrate *plan = new (w3d_auto_8001523c(52)) CollectCrate(p, c, w);
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
                Crate *c = s19_lookup_slot_8008c360(w3d_players_804aab4c, i);
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
            NodeList *list = FUN_80015960(&mode);
            if (list) {
                while (!list->empty()) {
                    Node *node = list->pop();
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
