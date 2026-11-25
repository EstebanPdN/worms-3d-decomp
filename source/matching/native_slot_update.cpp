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
    virtual void unknown0() = 0;
    virtual void unknown1() = 0;
    virtual void unknown2() = 0;
    virtual void unknown3() = 0;
    virtual void unknown4() = 0;
    virtual void unknown5() = 0;
    virtual void unknown6() = 0;
    virtual Result *query(u32 key) = 0;
};
struct Flags { u32 reserved:1; u32 active:1; u32 retained:1; u32 tag:29; };
struct Slot { u32 key; Object *object; u32 count; Flags flags; };
extern "C" void w3d_slots_update(Slot *slots)
{
    Slot *end = slots + 79;
    do {
        Object *object = slots->object;
        slots->flags.active = 0;
        Result *result;
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
