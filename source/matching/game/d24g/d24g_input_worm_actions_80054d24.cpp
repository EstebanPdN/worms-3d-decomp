/* Input action registration (Worms 3D GameCube PAL, 0x80054d24). Appends, in order,
 * Input.TurnLeftPressed (0, 1), Input.TurnLeftReleased (0, 0),
 * Input.TurnRightPressed (1, 1), Input.TurnRightReleased (1, 0),
 * Input.AimUpPressed (3, 1), Input.AimUpReleased (3, 0),
 * Input.AimDownPressed (2, 1), Input.AimDownReleased (2, 0),
 * Input.ZoomOutPressed (9, 1), Input.ZoomOutReleased (9, 0),
 * Input.TurnLeftPressed (0, 1, axis 1), Input.TurnLeftReleased (0, 0, axis
 * 1), Input.TurnRightPressed (0, 1, axis 2), Input.TurnRightReleased (0,
 * 0, axis 2), Input.AimUpPressed (1, 1, axis 1), Input.AimUpReleased (1,
 * 0, axis 1), Input.AimDownPressed (1, 1, axis 2), Input.AimDownReleased
 * (1, 0, axis 2).
 * Each entry is (action, enabled[, axis]); button actions have mode 2 and axis
 * actions mode 1. The vector grows with byte-range capacity arithmetic. Names are
 * original strings; axis actions use the 0.0f literal. Field meanings are inferred; same
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
struct AxisAction {
    unsigned unknown;
    CachedName name;
    unsigned mode, flags, id, enabled;
    float scale;
    unsigned axis, spare;
    void *operator new(unsigned size) { return w3d_pool_allocate_802098d8(&w3d_pool_804ae280, size); }
    AxisAction(const char *n, unsigned e, unsigned i, unsigned en, unsigned ax) : name(n)
    {
        flags = e;
        id = i;
        enabled = en;
        axis = ax;
        scale = 0.0f;
        mode = 1;
        spare = e;
    }
};
struct Owner { char unknown[36]; Storage storage; };
extern const char action_name_803784bc[];  /* "Input.TurnLeftPressed" */
extern const char action_name_803784d4[];  /* "Input.TurnLeftReleased" */
extern const char action_name_803784ec[];  /* "Input.TurnRightPressed" */
extern const char action_name_80378504[];  /* "Input.TurnRightReleased" */
extern const char action_name_8037851c[];  /* "Input.AimUpPressed" */
extern const char action_name_80378530[];  /* "Input.AimUpReleased" */
extern const char action_name_80378544[];  /* "Input.AimDownPressed" */
extern const char action_name_8037855c[];  /* "Input.AimDownReleased" */
extern const char action_name_80378574[];  /* "Input.ZoomOutPressed" */
extern const char action_name_8037858c[];  /* "Input.ZoomOutReleased" */
extern "C" void w3d_d24g_input_worm_actions_80054d24(void *, Owner *self)
{
    self->storage.push((unsigned)new ButtonAction(action_name_803784bc, 0, 0, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_803784d4, 0, 0, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_803784ec, 0, 1, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378504, 0, 1, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_8037851c, 0, 3, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378530, 0, 3, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378544, 0, 2, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_8037855c, 0, 2, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378574, 0, 9, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_8037858c, 0, 9, 0));
    self->storage.push((unsigned)new AxisAction(action_name_803784bc, 0, 0, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_803784d4, 0, 0, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_803784ec, 0, 0, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378504, 0, 0, 0, 2));
    self->storage.push((unsigned)new AxisAction(action_name_8037851c, 0, 1, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378530, 0, 1, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378544, 0, 1, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_8037855c, 0, 1, 0, 2));
}
