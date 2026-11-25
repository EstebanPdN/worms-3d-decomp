#include "w3d_ptr.h"
#line 1 "d24g_ninja_rope_actions_80058f18.cpp"
/* Input action registration (Worms 3D GameCube PAL, 0x80058f18). Appends, in order,
 * NinjaRope.Shorten.On (4, 1), NinjaRope.Shorten.Off (4, 0),
 * NinjaRope.Lengthen.On (5, 1), NinjaRope.Lengthen.Off (5, 0),
 * NinjaRope.SwingForward.On (1, 1, axis 2), NinjaRope.SwingForward.Off (1,
 * 0, axis 2), NinjaRope.SwingBackward.On (1, 1, axis 1),
 * NinjaRope.SwingBackward.Off (1, 0, axis 1), NinjaRope.SwingLeft.On (0,
 * 1, axis 1), NinjaRope.SwingLeft.Off (0, 0, axis 1),
 * NinjaRope.SwingRight.On (0, 1, axis 2), NinjaRope.SwingRight.Off (0, 0,
 * axis 2).
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
extern const char action_name_8037894c[];  /* "NinjaRope.Shorten.On" */
extern const char action_name_80378964[];  /* "NinjaRope.Shorten.Off" */
extern const char action_name_8037897c[];  /* "NinjaRope.Lengthen.On" */
extern const char action_name_80378994[];  /* "NinjaRope.Lengthen.Off" */
extern const char action_name_803789ac[];  /* "NinjaRope.SwingForward.On" */
extern const char action_name_803789c8[];  /* "NinjaRope.SwingForward.Off" */
extern const char action_name_803789e4[];  /* "NinjaRope.SwingBackward.On" */
extern const char action_name_80378a00[];  /* "NinjaRope.SwingBackward.Off" */
extern const char action_name_80378a1c[];  /* "NinjaRope.SwingLeft.On" */
extern const char action_name_80378a34[];  /* "NinjaRope.SwingLeft.Off" */
extern const char action_name_80378a4c[];  /* "NinjaRope.SwingRight.On" */
extern const char action_name_80378a64[];  /* "NinjaRope.SwingRight.Off" */
extern "C" void w3d_d24g_ninja_rope_actions_80058f18(Ptr32<void>, Ptr32<Owner> self)
{
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037894c, 0, 4, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378964, 0, 4, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_8037897c, 0, 5, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378994, 0, 5, 0)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803789ac, 0, 1, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803789c8, 0, 1, 0, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_803789e4, 0, 1, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378a00, 0, 1, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378a1c, 0, 0, 1, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378a34, 0, 0, 0, 1)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378a4c, 0, 0, 1, 2)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378a64, 0, 0, 0, 2)));
}


