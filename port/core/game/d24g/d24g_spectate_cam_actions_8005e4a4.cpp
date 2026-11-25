#include "w3d_ptr.h"
#line 1 "d24g_spectate_cam_actions_8005e4a4.cpp"
/* Input action registration (Worms 3D GameCube PAL, 0x8005e4a4). Appends, in order,
 * SpectateCam.RotateLeftPressed (3, 1, axis 1),
 * SpectateCam.RotateLeftReleased (3, 0, axis 1),
 * SpectateCam.RotateRightPressed (3, 1, axis 2),
 * SpectateCam.RotateRightReleased (3, 0, axis 2),
 * SpectateCam.RotateDownPressed (4, 1, axis 1),
 * SpectateCam.RotateDownReleased (4, 0, axis 1),
 * SpectateCam.RotateUpPressed (4, 1, axis 2), SpectateCam.RotateUpReleased
 * (4, 0, axis 2), SpectateCam.ForwardPressed (1, 1, axis 2),
 * SpectateCam.ForwardReleased (1, 0, axis 2), SpectateCam.BackPressed (1,
 * 1, axis 1), SpectateCam.BackReleased (1, 0, axis 1),
 * SpectateCam.LeftPressed (0, 1, axis 1), SpectateCam.LeftReleased (0, 0,
 * axis 1), SpectateCam.RightPressed (0, 1, axis 2),
 * SpectateCam.RightReleased (0, 0, axis 2), SpectateCam.BlimpViewPressed
 * (6, 1), SpectateCam.BlimpViewReleased (6, 0), Crate.LooseChute (8, 1),
 * SpectateCam.AppPause (12, 0).
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
extern const char action_name_80378edc[];  /* "Crate.LooseChute" */
extern const char action_name_80378ef0[];  /* "SpectateCam.RotateLeftPressed" */
extern const char action_name_80378f10[];  /* "SpectateCam.RotateLeftReleased" */
extern const char action_name_80378f30[];  /* "SpectateCam.RotateRightPressed" */
extern const char action_name_80378f50[];  /* "SpectateCam.RotateRightReleased" */
extern const char action_name_80378f70[];  /* "SpectateCam.RotateDownPressed" */
extern const char action_name_80378f90[];  /* "SpectateCam.RotateDownReleased" */
extern const char action_name_80378fb0[];  /* "SpectateCam.RotateUpPressed" */
extern const char action_name_80378fcc[];  /* "SpectateCam.RotateUpReleased" */
extern const char action_name_80378fec[];  /* "SpectateCam.ForwardPressed" */
extern const char action_name_80379008[];  /* "SpectateCam.ForwardReleased" */
extern const char action_name_80379024[];  /* "SpectateCam.BackPressed" */
extern const char action_name_8037903c[];  /* "SpectateCam.BackReleased" */
extern const char action_name_80379058[];  /* "SpectateCam.LeftPressed" */
extern const char action_name_80379070[];  /* "SpectateCam.LeftReleased" */
extern const char action_name_8037908c[];  /* "SpectateCam.RightPressed" */
extern const char action_name_803790a8[];  /* "SpectateCam.RightReleased" */
extern const char action_name_803790c4[];  /* "SpectateCam.BlimpViewPressed" */
extern const char action_name_803790e4[];  /* "SpectateCam.BlimpViewReleased" */
extern const char action_name_80379104[];  /* "SpectateCam.AppPause" */
extern "C" void w3d_d24g_spectate_cam_actions_8005e4a4(Ptr32<void>, Ptr32<Owner> self)
{
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378ef0, 0, 3, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378f10, 0, 3, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378f30, 0, 3, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378f50, 0, 3, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378f70, 0, 4, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378f90, 0, 4, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378fb0, 0, 4, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378fcc, 0, 4, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378fec, 0, 1, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80379008, 0, 1, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80379024, 0, 1, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_8037903c, 0, 1, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80379058, 0, 0, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80379070, 0, 0, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_8037908c, 0, 0, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803790a8, 0, 0, 0, 2)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803790c4, 0, 6, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_803790e4, 0, 6, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378edc, 0, 8, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80379104, 0, 12, 0)));
}


