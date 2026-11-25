#include "w3d_ptr.h"
#line 1 "native_slot_update.cpp"
/* Complete native8019831c..801983cc. Reference ABI only: bitfield and
 * vtable layouts require explicit adaptation for native ports. The unused
 * virtual declarations express slot positions; their true signatures and
 * implementations remain unknown. No historical source/compiler flag claim. */
namespace w3d_native_slot_update_detail {
/* Bit layout hypothesis from original masks: bits31/30/29, then29-bit tag. */
typedef unsigned int u32;
struct Result { unsigned char unknown[0x50]; unsigned char active; };
class Object {
public:
#if defined(__APPLE__)
    void w3d_r_unknown0()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown0Ev"));
    void w3d_r_unknown1()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown1Ev"));
    void w3d_r_unknown2()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown2Ev"));
    void w3d_r_unknown3()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown3Ev"));
    void w3d_r_unknown4()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown4Ev"));
    void w3d_r_unknown5()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown5Ev"));
    void w3d_r_unknown6()  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object8unknown6Ev"));
    Ptr32<Result> w3d_r_query(u32 key)  __asm__(W3D_SYM("_ZN29w3d_native_slot_update_detail6Object5queryEj"));
#endif
 __attribute__((always_inline)) inline void unknown0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unknown1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unknown2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unknown3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unknown4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unknown5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void unknown6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Result> query(u32 w3d_a0) { return ((Ptr32<Result> (*)(w3d_u32, u32))w3d::vfn(this->w3d_vptr_Object, 9))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Object; };
struct Flags { u32 tag:29; u32 retained:1; u32 active:1; u32 reserved:1; };
struct Slot { u32 key; Ptr32<Object> object; u32 count; Flags flags; };
extern "C" void w3d_slots_update(Ptr32<Slot> slots)
{
    Ptr32<Slot> end = slots + 79;
    do {
        Ptr32<Object> object = slots->object;
        slots->flags.active = 0;
        Ptr32<Result> result;
        if (object && (result = object->query(slots->key)) && result->active) {
            slots->flags.active = 1;
            slots->count = slots->count + 1;
        }
        if (slots->count > 2 && !slots->flags.retained)
            slots->count -= 2;
        ++slots;
    } while (slots <= end);
}

}


