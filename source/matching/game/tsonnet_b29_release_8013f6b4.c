/* Releases the object's registered handle: when a handle id is set, applies two
   values to the attached interface (virtual slot 24), flags the object the
   handle resolves to and clears the id. Offsets are observed; field names and
   meanings are inferred. The cleared id is an inline parameter because the
   original keeps it in a saved register across the calls; the do-while
   wrapper was found with the permuter and is what keeps it there. */
typedef struct { void **vtable; } Iface;
typedef struct { char p0[32]; int a; int b; char p1[116]; int handle; char p2[4]; Iface *attached; } Holder;
extern void *fn_80164fc8(int);
extern void fn_80122af8(void *);
static inline void release(Holder *h, int none) {
    if (h->handle != -1) {
        if (h->attached) {
            ((void (*)(Iface *, int))h->attached->vtable[24])(h->attached, h->a);
            ((void (*)(Iface *, int))h->attached->vtable[24])(h->attached, h->b);
        }
        {
            void *o = fn_80164fc8(h->handle);
            if (o) fn_80122af8(o);
        }
        h->handle = none;
    }
}
void tsonnet_b29_release_8013f6b4(Holder *h) {
    do { release(h, -1); } while (0);
}
