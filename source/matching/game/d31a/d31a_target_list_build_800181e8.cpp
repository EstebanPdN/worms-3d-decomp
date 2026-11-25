// GWMP8P rev0 0x800181e8. Rebuilds the AI target list: runs the two list
// resets, then for a map naming detail objects adds each as a target with a
// description string, otherwise adds each live worm within range of the
// centre as a Friendly or Enemy target; finally computes the mean absolute
// target weight.
extern "C" void *w3d_handle_storage_allocate(unsigned int);
extern "C" void w3d_handle_storage_release(void *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int, ...);
extern "C" int strcmp(const char *, const char *);
struct String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
extern "C" int w3d_string_append(String *, const char *);
extern "C" void w3d_string_release_header(void *);
struct String {
    const char *text;
    String();
    String(const char *);
    String(const String &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &o) {
        ++*(unsigned short *)(o.text - 6);
        unsigned short *h = (unsigned short *)(text - 6);
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
    bool operator!=(const char *s) const { return strcmp(text, s) != 0; }
};
inline String operator+(const String &a, const char *b)
{
    String r = a;
    w3d_string_append(&r, b);
    return r;
}
inline String operator+(const String &a, const String &b)
{
    String r = a;
    w3d_string_append(&r, b.text);
    return r;
}
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
    T *start, *finish, *storage_end;
    ~Array() { if (start) w3d_handle_storage_release(start); }
    int size() const { return finish - start; }
    bool empty() const { return start == finish; }
    void grow() {
        unsigned int used = (char *)finish - (char *)start;
        int a = used + 1, b = used + (used >> 1);
        unsigned int bytes = Max(a, b) * 4;
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
struct Words { float x, y, z; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline float Dist2(const Vec &a, const Vec &b)
{
    float dy = a.y - b.y, dx = a.x - b.x, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
struct Item {
    int pad0;
    String name;
    int id;
    union { float power; int bits; };
    Vec pos;
    int team;
    float charge;
    int pad[3];
    Item() {}
};
struct Named { int pad; Vec pos; };
struct Game { char pad[28]; float range; char pad2[140]; String map; };
extern Game *w3d_game_804aa6d8;
extern Array<Item *> *g_blasts_804aa750;
extern int g_self_index_804aa6e8;
extern int g_self_804aa6c0;
extern int g_done_804aa76c;
extern int g_busy_804aa768;
extern float g_blast_scale_804aa764;
extern Vec g_centre_8041d3a0;
extern "C" void fn_8001977c();
extern "C" void w3d_auto_80018be0();
extern "C" Array<Named *> *w3d_d30a_collect_named_80015960(const String *);
extern "C" void w3d_actor_member_delete_backend(void *);
extern "C" void *w3d_auto_8001523c(unsigned int);
extern "C" void w3d_auto_80015264(void *);
extern "C" int w3d_auto_800153dc(int);
extern "C" int s19_check_pair_80015434(int);
extern "C" const char *w3d_auto_80015564(int);
extern "C" Vec *w3d_auto_80015588(int);
extern "C" int w3d_auto_800155ac(int);
extern "C" int w3d_d27a_plan_score_update_80017f0c(Item *);
extern "C" void w3d_d27a_entry_weight_pass_80018ce0();
extern "C" void w3d_f2a_update_water_80018ed0();
extern const float k_zero_8036a8bc[];
extern const char s_empty_8036a87c[], s_target_8036a880[], s_quote_8036a898[], s_friendly_8036a89c[], s_enemy_8036a8a8[], s_worm_8036a8b0[], s_quote2_8036a8b8[];
inline void *operator new(unsigned int, void *place) { return place; }
inline int Bits(float v) { return *(int *)&v; }
inline void AddAbs(float &s, float v) { int b = *(int *)&v & 0x7fffffff; s += *(float *)&b; }
extern "C" void w3d_d31a_target_list_build_800181e8()
{
    fn_8001977c();
    w3d_auto_80018be0();
    float range = w3d_game_804aa6d8->range;
    String name(w3d_game_804aa6d8->map);
    range *= range;
    if (name != s_empty_8036a87c) {
        Array<Named *> *found = w3d_d30a_collect_named_80015960(&name);
        if (found) {
            while (!found->empty()) {
                float zero = k_zero_8036a8bc[0], one = 1.0f;
                Named **top = found->finish;
                Named *o = *--top;
                found->finish = top;
                Item *e = new (w3d_auto_8001523c(48)) Item;
                e->id = -1;
                e->name = String(s_target_8036a880) + name + String(s_quote_8036a898);
                Vec p(o->pos);
                e->pos = p;
                e->team = 1;
                e->charge = zero;
                e->bits = Bits(one);
                g_blasts_804aa750->push_back(e);
            }
            if (found) { found->~Array(); w3d_actor_member_delete_backend(found); }
            return;
        }
    }
    g_self_index_804aa6e8 = -1;
    int enemy = 0;
    for (int i = 0; i <= 15; i++) {
        if (!w3d_auto_800153dc(i)) continue;
        String kind;
        if (!s19_check_pair_80015434(i))
            kind = String(s_friendly_8036a89c);
        else {
            kind = String(s_enemy_8036a8a8);
            enemy = 1;
        }
        String desc = kind + String(s_worm_8036a8b0) + w3d_auto_80015564(i) + String(s_quote2_8036a8b8);
        Vec p(*w3d_auto_80015588(i));
        if (Dist2(p, g_centre_8041d3a0) > range) continue;
        Item *w = new (w3d_auto_8001523c(48)) Item;
        w->id = i;
        w->name = desc;
        if (w3d_d27a_plan_score_update_80017f0c(w)) {
            if (i == g_self_804aa6c0) g_self_index_804aa6e8 = g_blasts_804aa750->size();
            w->pos = p;
            w->team = w3d_auto_800155ac(i);
            g_blasts_804aa750->push_back(w);
        } else {
            Item *d = w;
            if (d) {
                d->name.~String();
                w3d_auto_80015264(d);
            }
        }
    }
    if (!enemy && !g_done_804aa76c)
        g_done_804aa76c = 1;
    w3d_d27a_entry_weight_pass_80018ce0();
    w3d_f2a_update_water_80018ed0();
    g_blast_scale_804aa764 = k_zero_8036a8bc[0];
    int n = g_blasts_804aa750->size();
    Item **items = g_blasts_804aa750->start;
    for (int k = 0; k < n; k++)
        AddAbs(g_blast_scale_804aa764, items[k]->power);
    g_blast_scale_804aa764 /= (float)g_blasts_804aa750->size();
    if (g_blast_scale_804aa764 == k_zero_8036a8bc[0]) g_blast_scale_804aa764 = 1.0f;
    g_busy_804aa768 = 0;
}
