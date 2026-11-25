#include "w3d_ptr.h"
#line 1 "d24g_input_move_jump_actions_80058a68.cpp"
/* Input action registration (Worms 3D GameCube PAL, 0x80058a68). Appends, in order,
 * Input.MoveX (0, 0, axis 0), Input.MoveY (1, 0, axis 0),
 * Input.JumpPressed (9, 1), Input.JumpReleased (9, 0).
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
extern const char action_name_80378908[];  /* "Input.MoveX" */
extern const char action_name_80378914[];  /* "Input.MoveY" */
extern const char action_name_80378920[];  /* "Input.JumpPressed" */
extern const char action_name_80378934[];  /* "Input.JumpReleased" */
extern "C" void w3d_d24g_input_move_jump_actions_80058a68(Ptr32<void>, Ptr32<Owner> self)
{
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378908, 0, 0, 0, 0)));
    self->storage.push((unsigned)w3d::H(new AxisAction(action_name_80378914, 0, 1, 0, 0)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378920, 0, 9, 1)));
    self->storage.push((unsigned)w3d::H(new ButtonAction(action_name_80378934, 0, 9, 0)));
}


