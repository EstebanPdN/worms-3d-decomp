// d24c: 0x800cd990 (76 bytes). Detach a weapon's trail: when the trail handle (+32) is
// valid, look it up, flag the graphic entity when found, and invalidate the handle.
// Names are inferred. Both branches store the invalid handle; GCC 2.95 cross-jumps the
// two stores, and the two uses of the constant keep it in a saved register.
struct Slot { unsigned char u[32]; int handle; };
extern "C" void *lookup_80164fc8(int);
extern "C" void trail_80122af8(void *);
extern "C" void d24c_trail_detach_800cd990(Slot *self) {
    int none = -1;
    if (self->handle != -1) {
        void *o = lookup_80164fc8(self->handle);
        if (o) {
            trail_80122af8(o);
            self->handle = none;
        } else {
            self->handle = none;
        }
    }
}
