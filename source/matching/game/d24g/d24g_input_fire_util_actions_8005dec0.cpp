/* Input action registration (Worms 3D GameCube PAL, 0x8005dec0). Appends, in order,
 * Input.FireUtilPressed (8, 1), Input.FireUtilReleased (8, 0),
 * Input.FirePressed (11, 1), Input.FireReleased (11, 0).
 * Each entry is (action, enabled[, axis]); button actions have mode 2 and axis
 * actions mode 1. The vector grows with byte-range capacity arithmetic. Names are
 * original strings; the unit owns no data. Field meanings are inferred; same
 * vector shape as sol35a3_crate_append_8005e35c. */
inline void *operator new(unsigned, void *place) { return place; }
extern "C" unsigned char *w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(void *);
extern "C" void *w3d_copy_802eee50(void *, const void *, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &smaller(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
struct Storage {
    unsigned char *begin, *end, *capacity;
    void push(const unsigned &value) {
        if (end == capacity) {
            unsigned used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned allocated = larger(next, grown) * 4;
            unsigned char *fresh = w3d_allocate_80212fd4(allocated);
            if (begin) {
                w3d_copy_802eee50(fresh, begin, smaller(allocated, used));
                w3d_release_802134fc(begin);
            }
            begin = fresh;
            end = fresh + used;
            capacity = fresh + allocated;
        }
        new (end) unsigned(value);
        end += 4;
    }
};
struct Pool { unsigned head; };
extern Pool w3d_pool_804ae280;
extern "C" void *w3d_pool_allocate_802098d8(void *, unsigned);
extern "C" void *w3d_name_8015f518(void *, const char *);
struct CachedName {
    unsigned cache;
    const char *name;
    CachedName(const char *n) { w3d_name_8015f518(this, n); }
};
struct ButtonAction {
    unsigned unknown;
    CachedName name;
    unsigned mode, flags, id, enabled, spare;
    void *operator new(unsigned size) { return w3d_pool_allocate_802098d8(&w3d_pool_804ae280, size); }
    ButtonAction(const char *n, unsigned e, unsigned i, unsigned en) : name(n)
    {
        flags = e;
        id = i;
        enabled = en;
        mode = 2;
        spare = e;
    }
};
struct Owner { char unknown[36]; Storage storage; };
extern const char action_name_803788e0[];  /* "Input.FirePressed" */
extern const char action_name_803788f4[];  /* "Input.FireReleased" */
extern const char action_name_80378eac[];  /* "Input.FireUtilPressed" */
extern const char action_name_80378ec4[];  /* "Input.FireUtilReleased" */
extern "C" void w3d_d24g_input_fire_util_actions_8005dec0(void *, Owner *self)
{
    self->storage.push((unsigned)new ButtonAction(action_name_80378eac, 0, 8, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378ec4, 0, 8, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_803788e0, 0, 11, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_803788f4, 0, 11, 0));
}
