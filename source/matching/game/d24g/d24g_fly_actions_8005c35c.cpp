/* Input action registration (Worms 3D GameCube PAL, 0x8005c35c). Appends, in order,
 * Fly.Pitch.Up.Pressed (3, 1), Fly.Pitch.Up.Released (3, 0),
 * Fly.Pitch.Down.Pressed (2, 1), Fly.Pitch.Down.Released (2, 0),
 * Fly.Yaw.Left.Pressed (0, 1), Fly.Yaw.Left.Released (0, 0),
 * Fly.Yaw.Right.Pressed (1, 1), Fly.Yaw.Right.Released (1, 0),
 * Fly.Roll.Left.Pressed (3, 1, axis 1), Fly.Roll.Left.Released (3, 0, axis
 * 1), Fly.Roll.Right.Pressed (3, 1, axis 2), Fly.Roll.Right.Released (3,
 * 0, axis 2), Fly.Yaw.Left.Pressed (0, 1, axis 1), Fly.Yaw.Left.Released
 * (0, 0, axis 1), Fly.Yaw.Right.Pressed (0, 1, axis 2),
 * Fly.Yaw.Right.Released (0, 0, axis 2), Fly.Pitch.Down.Pressed (1, 1,
 * axis 1), Fly.Pitch.Down.Released (1, 0, axis 1), Fly.Pitch.Up.Pressed
 * (1, 1, axis 2), Fly.Pitch.Up.Released (1, 0, axis 2).
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
extern const char action_name_80378d20[];  /* "Fly.Pitch.Up.Pressed" */
extern const char action_name_80378d38[];  /* "Fly.Pitch.Up.Released" */
extern const char action_name_80378d50[];  /* "Fly.Pitch.Down.Pressed" */
extern const char action_name_80378d68[];  /* "Fly.Pitch.Down.Released" */
extern const char action_name_80378d80[];  /* "Fly.Yaw.Left.Pressed" */
extern const char action_name_80378d98[];  /* "Fly.Yaw.Left.Released" */
extern const char action_name_80378db0[];  /* "Fly.Yaw.Right.Pressed" */
extern const char action_name_80378dc8[];  /* "Fly.Yaw.Right.Released" */
extern const char action_name_80378de0[];  /* "Fly.Roll.Left.Pressed" */
extern const char action_name_80378df8[];  /* "Fly.Roll.Left.Released" */
extern const char action_name_80378e10[];  /* "Fly.Roll.Right.Pressed" */
extern const char action_name_80378e28[];  /* "Fly.Roll.Right.Released" */
extern "C" void w3d_d24g_fly_actions_8005c35c(void *, Owner *self)
{
    self->storage.push((unsigned)new ButtonAction(action_name_80378d20, 0, 3, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378d38, 0, 3, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378d50, 0, 2, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378d68, 0, 2, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378d80, 0, 0, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378d98, 0, 0, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378db0, 0, 1, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378dc8, 0, 1, 0));
    self->storage.push((unsigned)new AxisAction(action_name_80378de0, 0, 3, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378df8, 0, 3, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378e10, 0, 3, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378e28, 0, 3, 0, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378d80, 0, 0, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378d98, 0, 0, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378db0, 0, 0, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378dc8, 0, 0, 0, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378d50, 0, 1, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378d68, 0, 1, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378d20, 0, 1, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378d38, 0, 1, 0, 2));
}
