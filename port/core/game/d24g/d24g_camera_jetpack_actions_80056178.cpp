#include "w3d_ptr.h"
#line 1 "d24g_camera_jetpack_actions_80056178.cpp"
/* Input action registration (Worms 3D GameCube PAL, 0x80056178). Appends, in order,
 * Camera.RotateLeftPressed (3, 1, axis 1), Camera.RotateLeftReleased (3,
 * 0, axis 1), Camera.RotateRightPressed (3, 1, axis 2),
 * Camera.RotateRightReleased (3, 0, axis 2), Camera.RotateDownPressed (4,
 * 1, axis 1), Camera.RotateDownReleased (4, 0, axis 1),
 * Camera.RotateUpPressed (4, 1, axis 2), Camera.RotateUpReleased (4, 0,
 * axis 2), Camera.ForwardPressed (1, 1, axis 2), Camera.ForwardReleased
 * (1, 0, axis 2), Camera.BackPressed (1, 1, axis 1), Camera.BackReleased
 * (1, 0, axis 1), Camera.LeftPressed (0, 1, axis 1), Camera.LeftReleased
 * (0, 0, axis 1), Camera.RightPressed (0, 1, axis 2), Camera.RightReleased
 * (0, 0, axis 2), Camera.ResetPressed (6, 1), Camera.ResetPressed (7, 1),
 * Input.WormSelectPressed (11, 1), Input.Jetpack.ForwardPressed (3, 1),
 * Input.Jetpack.ForwardReleased (3, 0), Input.Jetpack.BackPressed (2, 1),
 * Input.Jetpack.BackReleased (2, 0), Input.Jetpack.LeftPressed (0, 1),
 * Input.Jetpack.LeftReleased (0, 0), Input.Jetpack.RightPressed (1, 1),
 * Input.Jetpack.RightReleased (1, 0), App.Pause (12, 0), Input.FusePressed
 * (4, 1), Input.FuseReleased (4, 0), Input.OpenPanelPressed (10, 1),
 * Input.ToggleManualCamera (11, 1), Input.ManualCameraPitchPressed (6, 1),
 * Input.ManualCameraPitchReleased (6, 0).
 * The last three are added only when bit 0x01000000 of the context word at +188
 * (0x804b1788) is set. Each entry is (action, enabled[, axis]); button actions have mode 2 and axis
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
struct Context { char unknown[188]; unsigned flags; };
extern Ptr32<Context> w3d_context_804b1788;
extern const char action_name_8037835c[];  /* "App.Pause" */
extern const char action_name_803785a8[];  /* "Camera.RotateLeftPressed" */
extern const char action_name_803785c4[];  /* "Camera.RotateLeftReleased" */
extern const char action_name_803785e0[];  /* "Camera.RotateRightPressed" */
extern const char action_name_803785fc[];  /* "Camera.RotateRightReleased" */
extern const char action_name_80378618[];  /* "Camera.RotateDownPressed" */
extern const char action_name_80378634[];  /* "Camera.RotateDownReleased" */
extern const char action_name_80378650[];  /* "Camera.RotateUpPressed" */
extern const char action_name_80378668[];  /* "Camera.RotateUpReleased" */
extern const char action_name_80378680[];  /* "Camera.ForwardPressed" */
extern const char action_name_80378698[];  /* "Camera.ForwardReleased" */
extern const char action_name_803786b0[];  /* "Camera.BackPressed" */
extern const char action_name_803786c4[];  /* "Camera.BackReleased" */
extern const char action_name_803786d8[];  /* "Camera.LeftPressed" */
extern const char action_name_803786ec[];  /* "Camera.LeftReleased" */
extern const char action_name_80378700[];  /* "Camera.RightPressed" */
extern const char action_name_80378714[];  /* "Camera.RightReleased" */
extern const char action_name_8037872c[];  /* "Camera.ResetPressed" */
extern const char action_name_80378740[];  /* "Input.WormSelectPressed" */
extern const char action_name_80378758[];  /* "Input.Jetpack.ForwardPressed" */
extern const char action_name_80378778[];  /* "Input.Jetpack.ForwardReleased" */
extern const char action_name_80378798[];  /* "Input.Jetpack.BackPressed" */
extern const char action_name_803787b4[];  /* "Input.Jetpack.BackReleased" */
extern const char action_name_803787d0[];  /* "Input.Jetpack.LeftPressed" */
extern const char action_name_803787ec[];  /* "Input.Jetpack.LeftReleased" */
extern const char action_name_80378808[];  /* "Input.Jetpack.RightPressed" */
extern const char action_name_80378824[];  /* "Input.Jetpack.RightReleased" */
extern const char action_name_80378840[];  /* "Input.FusePressed" */
extern const char action_name_80378854[];  /* "Input.FuseReleased" */
extern const char action_name_80378868[];  /* "Input.OpenPanelPressed" */
extern const char action_name_80378880[];  /* "Input.ToggleManualCamera" */
extern const char action_name_8037889c[];  /* "Input.ManualCameraPitchPressed" */
extern const char action_name_803788bc[];  /* "Input.ManualCameraPitchReleased" */
extern "C" void w3d_d24g_camera_jetpack_actions_80056178(Ptr32<void>, Ptr32<Owner> self)
{
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803785a8, 0, 3, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803785c4, 0, 3, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803785e0, 0, 3, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803785fc, 0, 3, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378618, 0, 4, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378634, 0, 4, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378650, 0, 4, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378668, 0, 4, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378680, 0, 1, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378698, 0, 1, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803786b0, 0, 1, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803786c4, 0, 1, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803786d8, 0, 0, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803786ec, 0, 0, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378700, 0, 0, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378714, 0, 0, 0, 2)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037872c, 0, 6, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037872c, 0, 7, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378740, 0, 11, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378758, 0, 3, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378778, 0, 3, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378798, 0, 2, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803787b4, 0, 2, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803787d0, 0, 0, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803787ec, 0, 0, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378808, 0, 1, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378824, 0, 1, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037835c, 0, 12, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378840, 0, 4, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378854, 0, 4, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378868, 0, 10, 1)));
    if (w3d_context_804b1788->flags & 0x01000000) {
        self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378880, 0, 11, 1)));
        self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037889c, 0, 6, 1)));
        self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803788bc, 0, 6, 0)));
    }
}


