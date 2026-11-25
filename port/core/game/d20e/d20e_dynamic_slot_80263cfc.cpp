#include "w3d_ptr.h"
#line 1 "d20e_dynamic_slot_80263cfc.cpp"
// Dynamic slot allocate/release (Worms 3D GameCube PAL, 0x80263cfc).
//
// Slots 15..46 are tracked by the bit mask 0x804abb64 (bit = slot - 15).
// With slot != -1 the slot's bit is cleared and -1 is returned. With
// slot == -1 the lowest free bit is found, the service named by the string
// argument is looked up (0x8015ae3c, then 0x80343808), two entries are
// acquired with code 79 (0x80171ee0), entry slot of the first pair table
// (0x80171fa0) is set to (0x803cb1fc, 0.0) and entry slot of the second pair
// table (0x80171ff8) to (0.109375, scale / 128); the bit is marked and the
// slot number returned. The by-value string parameter is destroyed by the
// callee (string finish 0x8020c5c4 and release 0x80341588) on both paths.
//
// Names are structural; the meaning of the pair tables is unknown. The
// leading pool float (0x803cb1fc, 4 bytes past an 8-byte boundary) stays an
// external object and the aligned tail of the pool is owned. The scale
// product is computed before the third store, which gives the original load
// order. Built with -mps-float (one saved FPR in a non-leaf function).
// Derived from the f10a/g3a drafts (never proved).
extern unsigned w3d_slot_mask_804abb64;
struct D20eSlotPair { float a, b; };
struct D20eSlotName {
    Ptr32<char> text;
    ~D20eSlotName();
};
extern "C" void w3d_string_base_finish(Ptr32<D20eSlotName>);
extern "C" void w3d_string_release(Ptr32<D20eSlotName>);
inline D20eSlotName::~D20eSlotName()
{
    w3d_string_base_finish(this);
    w3d_string_release(this);
}
extern "C" Ptr32<void> fn_8015ae3c(Ptr32<D20eSlotName>); Ptr32<void> fn_80343808(Ptr32<void>);
extern "C" int fn_80171ee0(Ptr32<void>, int);
extern "C" Ptr32<D20eSlotPair> fn_80171fa0(Ptr32<void>); Ptr32<D20eSlotPair> fn_80171ff8(Ptr32<void>);
extern float w3d_slot_value_803cb1fc[];   // leading pool float
extern "C" int w3d_d20e_dynamic_slot_80263cfc(D20eSlotName name, int slot, float scale)
{
    int result;
    if (slot != -1) {
        w3d_slot_mask_804abb64 &= ~(1u << (slot - 15));
        result = -1;
    } else {
        result = 0;
        while (w3d_slot_mask_804abb64 & (1 << result))
            ++result;
        Ptr32<void> pool = fn_80343808(fn_8015ae3c(&name));
        fn_80171ee0(pool, 79);
        Ptr32<D20eSlotPair> first = fn_80171fa0(pool); Ptr32<D20eSlotPair> second = fn_80171ff8(pool);
        int index = result + 15;
        first[index].a = w3d_slot_value_803cb1fc[0];
        first[index].b = 0.0f;
        float g = scale * 0.0078125f;
        second[index].a = 0.109375f;
        second[index].b = g;
        w3d_slot_mask_804abb64 |= 1u << result;
        result = index;
    }
    return result;
}


