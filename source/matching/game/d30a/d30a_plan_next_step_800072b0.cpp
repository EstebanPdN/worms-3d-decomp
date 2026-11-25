// GWMP8P rev0 0x800072b0. Runs one step of the worm planner: with a plan
// active it runs a path cost query; otherwise it queues either a rope aim
// and a wait, a timed weapon release with a new item, or a fresh cost query,
// then resets the planner. Names are inferred from the original
// instructions.
extern "C" void *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int, ...);
inline void *operator new(unsigned int, void *place) { return place; }
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *storage_end;
    void grow() {
        unsigned int used = (char *)finish - (char *)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * sizeof(T);
        T *p = (T *)w3d_handle_storage_allocate(bytes);
        if (start) {
            memcpy_802eee50(p, start, Min(bytes, used));
            w3d_handle_storage_release(start);
        }
        start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
    }
    void push_back(const T &v) {
        if (finish == storage_end) grow();
        *finish = v;
        finish++;
    }
};
struct Vec { float x, y, z; Vec(float a, float b, float c) { x = a; y = b; z = c; } };
typedef void (*Run)(void *);
typedef void (*Kill)(void *, int);
extern void *g_cost_table_8040cb40[];
extern void *g_item_table_8040dc28[];
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_path_cost_construct(void *);
extern "C" void fn_80007080(void *);
struct Cost {
    char pad[12]; void **table;
    Cost() { w3d_path_cost_construct(this); table = g_cost_table_8040cb40; }
};
struct Item {
    int pad; int a, b; int kind; void **table;
    Item(int x) { table = g_item_table_8040dc28; a = x; b = x; kind = 13; }
};
extern void *g_plan_804aa598;
extern int g_append_804aa59c, g_state_804aa584, g_count_804aa588, g_flag_804aa5a0;
extern Array<void *> *g_items_804aa564;
extern void *g_storage_804aa5a4;
extern "C" void w3d_cx9a_plan_create_append_80016ad0(void);
extern "C" void w3d_command_create_19(void);
extern "C" void w3d_command_create_21(void);
extern "C" void w3d_d17a_command_create_800085fc(float);
extern "C" void w3d_d28a_aim_command_create_80007eac(const Vec *);
extern "C" void w3d_command_create_6(int);
extern "C" void w3d_command_create_3(int);
extern "C" void w3d_cx9a_storage_push_member_8002274c(void *, Item *);
extern "C" void w3d_ai_planner_reset(void);
extern "C" void w3d_d30a_plan_next_step_800072b0(void)
{
    void *plan = g_plan_804aa598;
    if (plan) {
        Cost *c = new (w3d_auto_8001523c(16)) Cost;
        fn_80007080(c);
        return;
    }
    if (g_append_804aa59c) w3d_cx9a_plan_create_append_80016ad0();
    if (g_state_804aa584 != 60) {
        if (g_count_804aa588 > 0) {
            w3d_command_create_19();
            w3d_d17a_command_create_800085fc(1.5707964f);
            Vec v(0.0f, 1.0f, 0.0f);
            w3d_d28a_aim_command_create_80007eac(&v);
            w3d_command_create_6(1000);
            w3d_command_create_3(1);
        } else {
            w3d_command_create_6(3000);
        }
    } else if (g_flag_804aa5a0) {
        w3d_command_create_6(1000);
        w3d_command_create_19();
        w3d_command_create_6(500);
        Item *it = new (w3d_auto_8001523c(20)) Item(0);
        g_items_804aa564->push_back(it);
        w3d_cx9a_storage_push_member_8002274c(g_storage_804aa5a4, it);
        w3d_command_create_6(1000);
        w3d_command_create_21();
    } else {
        Cost *c = new (w3d_auto_8001523c(16)) Cost;
        ((Run)c->table[7])(c);
        if (c) ((Kill)c->table[3])(c, 3);
    }
    w3d_ai_planner_reset();
}
