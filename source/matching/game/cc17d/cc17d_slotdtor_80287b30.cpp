// cc17d: destructor at 0x80287b30. Observed: installs vtable 0x8041c010,
// releases the 64 interface words at +28..+284 from last to first through
// vtable slot +16 when nonzero, then calls the base destructor 0x8015ff2c.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct Cc17dHeld { void *ptr; };
struct Cc17dSlotOwner {
    const void *vtable;
    char pad04[24];
    Cc17dHeld slots[64];               // +28..+284
};
extern const void *w3d_vtable_8041c010[];
extern "C" void w3d_base_destroy_8015ff2c(void *self, int flags);
static inline void cc17d_release(Cc17dHeld *h)
{
    if (h->ptr)
        VCALL(h->ptr, void (*)(void *), 16)(h->ptr);
}
static inline void cc17d_destroy(Cc17dHeld *base, Cc17dHeld *t)
{
    if (base != t) {
        do {
            --t;
            cc17d_release(t);
        } while (base != t);
    }
}
extern "C" void w3d_cc17d_slot_owner_destroy_80287b30(Cc17dSlotOwner *self, int flags)
{
    self->vtable = w3d_vtable_8041c010;
    Cc17dHeld *base = self->slots;
    if (base)
        cc17d_destroy(base, self->slots + 64);
    w3d_base_destroy_8015ff2c(self, flags);
}
