// GWMP8P rev0 0x8001977c. Collects every point returned by a handle query
// into the marks array, then, when the game has a name, collects the named
// objects. The array grows by half, as the engine's Array does. Names are
// inferred.
extern "C" void *malloc(unsigned);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int, ...);
extern "C" int strcmp(const char *, const char *);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *storage_end;
    void grow() {
        unsigned int used = (char *)finish - (char *)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * sizeof(T);
        T *p = (T *)malloc(bytes);
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
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec Copy(const Vec &o) { return Vec(o.x, o.y, o.z); }
struct Handle { int words[2]; Handle() {} Handle(const Handle &o); };
struct Named;
struct Game { char pad[244]; const char *name; };
extern Game *w3d_game_804aa6d8;
extern Array<Vec> *w3d_marks_804aa754;
extern unsigned short w3d_map_804aa95e;
extern Array<void *> *g_named_804aa75c;
extern char g_empty_8036a87c[];
extern "C" Handle *w3d_actor_handle_member_initialize(Handle *);
extern "C" void w3d_actor_handle_member_destroy(Handle *, int);
extern "C" void w3d_handle_member_query_801262c0(Handle *, const Vec *);
extern "C" void w3d_handle_member_query_8012629c(Handle *, float);
extern "C" void w3d_actor_handle_member_set_slot_word(Handle *, int);
extern "C" void w3d_actor_handle_member_set_word(Handle *, int);
extern "C" void w3d_handle_member_call_80126334(Handle *);
extern "C" int w3d_handle_clock_801264fc(Handle *);
extern "C" void w3d_handle_member_query_80126524(Handle *);
extern "C" const Vec *w3d_auto_8003f240(unsigned short);
extern "C" Array<void *> *w3d_d30a_collect_named_80015960(const char **);
extern "C" void w3d_d43a_map_marks_collect_8001977c(void)
{
    Handle h;
    w3d_actor_handle_member_initialize(&h);
    {
        Vec origin(0.0f, 0.0f, 0.0f);
        w3d_handle_member_query_801262c0(&h, &origin);
    }
    w3d_handle_member_query_8012629c(&h, 100000.0f);
    w3d_actor_handle_member_set_slot_word(&h, 0);
    w3d_actor_handle_member_set_word(&h, 8);
    w3d_handle_member_call_80126334(&h);
    int t = w3d_handle_clock_801264fc(&h);
    while (t != 0xffff) {
        w3d_auto_8003f240(w3d_map_804aa95e);
        Vec v = Copy(*w3d_auto_8003f240(w3d_map_804aa95e));
        w3d_marks_804aa754->push_back(v);
 t = w3d_handle_clock_801264fc(&h);
    }
    w3d_handle_member_query_80126524(&h);
    const char **name = &w3d_game_804aa6d8->name;
    bool some = strcmp(*name, g_empty_8036a87c) != 0;
    if (some) g_named_804aa75c = w3d_d30a_collect_named_80015960(name);
    w3d_actor_handle_member_destroy(&h, 2);
}
