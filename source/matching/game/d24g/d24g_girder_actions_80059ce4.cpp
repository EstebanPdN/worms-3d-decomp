/* Input action registration (Worms 3D GameCube PAL, 0x80059ce4). Appends, in order,
 * App.Pause (12, 0), Girder.Place (8, 1), Girder.Cancel (9, 1),
 * Girder.ChangeType.Pressed (4, 1), Girder.ChangeType.Released (4, 0),
 * Girder.Raise.Pressed (6, 1), Girder.Raise.Released (6, 0),
 * Girder.Lower.Pressed (5, 1), Girder.Lower.Released (5, 0),
 * Girder.Rotate.Forward.Pressed (3, 1), Girder.Rotate.Forward.Released (3,
 * 0), Girder.Rotate.Backward.Pressed (2, 1),
 * Girder.Rotate.Backward.Released (2, 0), Girder.Rotate.Left.Pressed (0,
 * 1), Girder.Rotate.Left.Released (0, 0), Girder.Rotate.Right.Pressed (1,
 * 1), Girder.Rotate.Right.Released (1, 0), Girder.Move.Forward.Pressed (1,
 * 1, axis 1), Girder.Move.Forward.Released (1, 0, axis 1),
 * Girder.Move.Backward.Pressed (1, 1, axis 2),
 * Girder.Move.Backward.Released (1, 0, axis 2), Girder.Move.Left.Pressed
 * (0, 1, axis 1), Girder.Move.Left.Released (0, 0, axis 1),
 * Girder.Move.Right.Pressed (0, 1, axis 2), Girder.Move.Right.Released (0,
 * 0, axis 2), Camera.RotateLeftPressed (3, 1, axis 1),
 * Camera.RotateLeftReleased (3, 0, axis 1), Camera.RotateRightPressed (3,
 * 1, axis 2), Camera.RotateRightReleased (3, 0, axis 2),
 * Camera.RotateDownPressed (4, 1, axis 1), Camera.RotateDownReleased (4,
 * 0, axis 1), Camera.RotateUpPressed (4, 1, axis 2),
 * Camera.RotateUpReleased (4, 0, axis 2), Input.OpenPanelPressed (10, 1).
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
extern const char action_name_8037835c[];  /* "App.Pause" */
extern const char action_name_803785a8[];  /* "Camera.RotateLeftPressed" */
extern const char action_name_803785c4[];  /* "Camera.RotateLeftReleased" */
extern const char action_name_803785e0[];  /* "Camera.RotateRightPressed" */
extern const char action_name_803785fc[];  /* "Camera.RotateRightReleased" */
extern const char action_name_80378618[];  /* "Camera.RotateDownPressed" */
extern const char action_name_80378634[];  /* "Camera.RotateDownReleased" */
extern const char action_name_80378650[];  /* "Camera.RotateUpPressed" */
extern const char action_name_80378668[];  /* "Camera.RotateUpReleased" */
extern const char action_name_80378868[];  /* "Input.OpenPanelPressed" */
extern const char action_name_80378a84[];  /* "Girder.Place" */
extern const char action_name_80378a94[];  /* "Girder.Cancel" */
extern const char action_name_80378aa4[];  /* "Girder.ChangeType.Pressed" */
extern const char action_name_80378ac0[];  /* "Girder.ChangeType.Released" */
extern const char action_name_80378adc[];  /* "Girder.Raise.Pressed" */
extern const char action_name_80378af4[];  /* "Girder.Raise.Released" */
extern const char action_name_80378b0c[];  /* "Girder.Lower.Pressed" */
extern const char action_name_80378b24[];  /* "Girder.Lower.Released" */
extern const char action_name_80378b3c[];  /* "Girder.Rotate.Forward.Pressed" */
extern const char action_name_80378b5c[];  /* "Girder.Rotate.Forward.Released" */
extern const char action_name_80378b7c[];  /* "Girder.Rotate.Backward.Pressed" */
extern const char action_name_80378b9c[];  /* "Girder.Rotate.Backward.Released" */
extern const char action_name_80378bbc[];  /* "Girder.Rotate.Left.Pressed" */
extern const char action_name_80378bd8[];  /* "Girder.Rotate.Left.Released" */
extern const char action_name_80378bf4[];  /* "Girder.Rotate.Right.Pressed" */
extern const char action_name_80378c10[];  /* "Girder.Rotate.Right.Released" */
extern const char action_name_80378c30[];  /* "Girder.Move.Forward.Pressed" */
extern const char action_name_80378c4c[];  /* "Girder.Move.Forward.Released" */
extern const char action_name_80378c6c[];  /* "Girder.Move.Backward.Pressed" */
extern const char action_name_80378c8c[];  /* "Girder.Move.Backward.Released" */
extern const char action_name_80378cac[];  /* "Girder.Move.Left.Pressed" */
extern const char action_name_80378cc8[];  /* "Girder.Move.Left.Released" */
extern const char action_name_80378ce4[];  /* "Girder.Move.Right.Pressed" */
extern const char action_name_80378d00[];  /* "Girder.Move.Right.Released" */
extern "C" void w3d_d24g_girder_actions_80059ce4(void *, Owner *self)
{
    self->storage.push((unsigned)new ButtonAction(action_name_8037835c, 0, 12, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378a84, 0, 8, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378a94, 0, 9, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378aa4, 0, 4, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378ac0, 0, 4, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378adc, 0, 6, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378af4, 0, 6, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378b0c, 0, 5, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378b24, 0, 5, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378b3c, 0, 3, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378b5c, 0, 3, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378b7c, 0, 2, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378b9c, 0, 2, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378bbc, 0, 0, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378bd8, 0, 0, 0));
    self->storage.push((unsigned)new ButtonAction(action_name_80378bf4, 0, 1, 1));
    self->storage.push((unsigned)new ButtonAction(action_name_80378c10, 0, 1, 0));
    self->storage.push((unsigned)new AxisAction(action_name_80378c30, 0, 1, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378c4c, 0, 1, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378c6c, 0, 1, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378c8c, 0, 1, 0, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378cac, 0, 0, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378cc8, 0, 0, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378ce4, 0, 0, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378d00, 0, 0, 0, 2));
    self->storage.push((unsigned)new AxisAction(action_name_803785a8, 0, 3, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_803785c4, 0, 3, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_803785e0, 0, 3, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_803785fc, 0, 3, 0, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378618, 0, 4, 1, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378634, 0, 4, 0, 1));
    self->storage.push((unsigned)new AxisAction(action_name_80378650, 0, 4, 1, 2));
    self->storage.push((unsigned)new AxisAction(action_name_80378668, 0, 4, 0, 2));
    self->storage.push((unsigned)new ButtonAction(action_name_80378868, 0, 10, 1));
}
