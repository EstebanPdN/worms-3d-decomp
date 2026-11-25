#include "w3d_ptr.h"
#line 1 "d40n_evict_animation_slot_v2_801984fc.cpp"
// GWMP8P rev0 0x801984fc. Picks a slot for new animation data in the 80-slot
// cache, freeing until the heap has size plus 2048 bytes: a free slot on the
// first pass, else the oldest unlocked in-use one, else with a warning the
// oldest in use. Names inferred from the original's messages.
extern "C" void fn_802fb7ac(Ptr32<const char>, ...);
struct Registry;
extern "C" Ptr32<Registry> fn_80343810();
extern "C" unsigned fn_801981f8();
struct Records;
extern "C" void fn_80197f98(Ptr32<Records>, Ptr32<void>);
struct Owner { void w3d_r_s8() __asm__(W3D_SYM("_ZN5Owner2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN5Owner3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN5Owner3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN5Owner3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN5Owner3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN5Owner3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN5Owner3s32Ev"));
    Ptr32<char> w3d_r_Find(int id) __asm__(W3D_SYM("_ZN5Owner4FindEi")); int w3d_r_Size(int id) __asm__(W3D_SYM("_ZN5Owner4SizeEi"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Owner, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<char> Find(int w3d_a0) { return ((Ptr32<char> (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Owner, 9))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int Size(int w3d_a0) { return ((int (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Owner, 10))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Owner; };
struct Slot { int id; Ptr32<Owner> owner; unsigned stamp; int flags; };
extern const char msg_803a85a0[], msg_803a85d8[], msg_803a8610[], msg_803a8630[], msg_803a8650[];
extern "C" Ptr32<Slot> w3d_d40n_evict_animation_slot_v2_801984fc(Ptr32<Slot> slots, unsigned size) {
    unsigned need = size + 2048;
    int first = 1;
    unsigned tries = 0;
    Ptr32<Slot> e;
    int more;
    do {
        e = slots;
        unsigned best = 0xffffffff;
        int found = 0;
        unsigned victim = 80;
        for (unsigned i = 0; i < 80; i++) {
            e = &slots[i];
            if (e->flags >= 0 && first) { victim = i; found = 1; break; }
            if (!(e->flags & 0x40000000) && e->flags < 0 && e->stamp < best) { best = e->stamp; victim = i; found = 1; }
        }
        if (!found) {
            fn_802fb7ac(msg_803a85a0);
            fn_802fb7ac(msg_803a85d8);
            if (e->flags & 0x20000000) fn_802fb7ac(msg_803a8610);
            best = 0xffffffff;
            victim = 0;
            for (int i = 0; i < 80; i++) {
                if (slots[i].flags < 0 && slots[i].stamp < best) { best = slots[i].stamp; victim = i; }
            }
        }
        e = &slots[victim];
        if (e->flags < 0) {
            Ptr32<char> data = e->owner->Find(slots[victim].id);
            int bytes = e->owner->Size(slots[victim].id);
            if (data) {
                fn_802fb7ac(msg_803a8630);
                fn_80197f98((Ptr32<Records>)(data + 8), (Ptr32<void>)w3d::G(bytes));
                e->stamp = 0;
                e->flags &= 0x1fffffff;
            }
        }
        fn_80343810();
        if (fn_801981f8() < need) {
            tries++;
            first = 0;
            more = 1;
            if (tries > 80) { fn_802fb7ac(msg_803a8650); break; }
        } else {
            more = 0;
        }
    } while (more);
    return e;
}


