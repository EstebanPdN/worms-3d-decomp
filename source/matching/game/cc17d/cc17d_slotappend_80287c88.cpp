// cc17d: append to the 64-slot interface array of the object destroyed at
// 0x80287b30. Observed: calls the item's vtable slot +88 with 0, stores it
// into slot [count] (+28 + 4*count) with retain (+12) / release (+16) of the
// old value, increments the count at +284 and sets bit 31 of the word at +288.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct Cc17dHeld { void *ptr; };
struct Cc17dSlotOwner {
    const void *vtable;
    char pad04[24];
    Cc17dHeld slots[64];               // +28
    unsigned int count;                // +284
    unsigned int flags;                // +288
};
static inline void cc17d_assign(Cc17dHeld *h, void *p)
{
    if (p)
        VCALL(p, void (*)(void *), 12)(p);
    if (h->ptr)
        VCALL(h->ptr, void (*)(void *), 16)(h->ptr);
    h->ptr = p;
}
extern "C" void w3d_cc17d_slot_owner_append_80287c88(Cc17dSlotOwner *self, void *item)
{
    VCALL(item, void (*)(void *, int), 88)(item, 0);
    cc17d_assign(&self->slots[self->count], item);
    self->count++;
    self->flags |= 0x80000000;
}
