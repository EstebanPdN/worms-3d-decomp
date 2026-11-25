#include "w3d_ptr.h"
#line 1 "d24g_menu_actions_800524d4.cpp"
/* Input action registration (Worms 3D GameCube PAL, 0x800524d4). Appends, in order,
 * App.Pause (12, 0), Input.StartButton (12, 1), Input.QuitMovie (8, 1),
 * Input.QuitMovie (12, 1), Input.QuitMovie (9, 1), Input.Menu.Left (0, 1),
 * Input.Menu.Right (1, 1), Input.Menu.Up (3, 1), Input.Menu.Down (2, 1),
 * Input.Menu.Left.Release (0, 0), Input.Menu.Right.Release (1, 0),
 * Input.Menu.Up.Release (3, 0), Input.Menu.Down.Release (2, 0),
 * Input.Menu.Left (0, 1, axis 1), Input.Menu.Right (0, 1, axis 2),
 * Input.Menu.Up (1, 1, axis 1), Input.Menu.Down (1, 1, axis 2),
 * Input.Menu.Left.Release (0, 0, axis 1), Input.Menu.Right.Release (0, 0,
 * axis 2), Input.Menu.Up.Release (1, 0, axis 1), Input.Menu.Down.Release
 * (1, 0, axis 2), Input.Menu.Select (8, 1), Input.Menu.SelectReleased (8,
 * 0), Input.Menu.Select (12, 0), FE.Backup (9, 1), Input.Menu.Cancel (9,
 * 1), Input.Menu.CancelReleased (9, 0), Input.ClosePanelPressed (10, 1).
 * Each entry is (action, enabled[, axis]); button actions have mode 2 and axis
 * actions mode 1. The vector grows with byte-range capacity arithmetic. Names are
 * original strings; axis actions use the 0.0f literal. Field meanings are inferred; same
 * vector shape as sol35a3_crate_append_8005e35c. */
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" Ptr32<unsigned char> w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> w3d_copy_802eee50(Ptr32<void>, Ptr32<const void>, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &smaller(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(const unsigned &value) {
        if (end == capacity) {
            unsigned used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned allocated = larger(next, grown) * 4;
            Ptr32<unsigned char> fresh = w3d_allocate_80212fd4(allocated);
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
extern "C" Ptr32<void> w3d_pool_allocate_802098d8(Ptr32<void>, unsigned);
extern "C" Ptr32<void> w3d_name_8015f518(Ptr32<void>, Ptr32<const char>);
struct CachedName {
    unsigned cache;
    Ptr32<const char> name;
    template <class W3dU> CachedName(Ptr32<W3dU> w3d_p) : CachedName((const char *)w3d_p.get()) {}
 CachedName(const char *n) { w3d_name_8015f518(this, n); }
};
struct ButtonAction {
    unsigned unknown;
    CachedName name;
    unsigned mode, flags, id, enabled, spare;
    void *operator new(__SIZE_TYPE__ size) { return w3d_pool_allocate_802098d8(&w3d_pool_804ae280, size); }
    ButtonAction(Ptr32<const char> n, unsigned e, unsigned i, unsigned en) : name(n)
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
    void *operator new(__SIZE_TYPE__ size) { return w3d_pool_allocate_802098d8(&w3d_pool_804ae280, size); }
    AxisAction(Ptr32<const char> n, unsigned e, unsigned i, unsigned en, unsigned ax) : name(n)
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
extern const char action_name_80378368[];  /* "Input.StartButton" */
extern const char action_name_8037837c[];  /* "Input.QuitMovie" */
extern const char action_name_8037838c[];  /* "Input.Menu.Left" */
extern const char action_name_8037839c[];  /* "Input.Menu.Right" */
extern const char action_name_803783b0[];  /* "Input.Menu.Up" */
extern const char action_name_803783c0[];  /* "Input.Menu.Down" */
extern const char action_name_803783d0[];  /* "Input.Menu.Left.Release" */
extern const char action_name_803783e8[];  /* "Input.Menu.Right.Release" */
extern const char action_name_80378404[];  /* "Input.Menu.Up.Release" */
extern const char action_name_8037841c[];  /* "Input.Menu.Down.Release" */
extern const char action_name_80378434[];  /* "Input.Menu.Select" */
extern const char action_name_80378448[];  /* "Input.Menu.SelectReleased" */
extern const char action_name_80378464[];  /* "FE.Backup" */
extern const char action_name_80378470[];  /* "Input.Menu.Cancel" */
extern const char action_name_80378484[];  /* "Input.Menu.CancelReleased" */
extern const char action_name_803784a0[];  /* "Input.ClosePanelPressed" */
extern "C" void w3d_d24g_menu_actions_800524d4(Ptr32<void>, Ptr32<Owner> self)
{
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037835c, 0, 12, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378368, 0, 12, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037837c, 0, 8, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037837c, 0, 12, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037837c, 0, 9, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037838c, 0, 0, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037839c, 0, 1, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803783b0, 0, 3, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803783c0, 0, 2, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803783d0, 0, 0, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803783e8, 0, 1, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378404, 0, 3, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037841c, 0, 2, 0)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_8037838c, 0, 0, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_8037839c, 0, 0, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803783b0, 0, 1, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803783c0, 0, 1, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803783d0, 0, 0, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803783e8, 0, 0, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378404, 0, 1, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_8037841c, 0, 1, 0, 2)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378434, 0, 8, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378448, 0, 8, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378434, 0, 12, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378464, 0, 9, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378470, 0, 9, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378484, 0, 9, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803784a0, 0, 10, 1)));
}


