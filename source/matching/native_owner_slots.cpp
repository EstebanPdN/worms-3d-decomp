/* Complete native801982c0..801982f4. Clears80 four-word slots, preserving
 * low29 flag bits and returning the original base in r3. Slot field names and
 * game role are inferred; no original source spelling or data ownership claim. */
typedef unsigned int u32;
struct Slot { u32 key; void *object; u32 count; u32 flags; };
extern "C" Slot *w3d_slots_clear(Slot *slots)
{
    Slot *original = slots;
    int count = 80;
    do {
        slots->key = 0;
        slots->object = 0;
        slots->flags &= 0x1fffffffu;
        slots->count = 0;
        ++slots;
    } while (--count);
    return original;
}
