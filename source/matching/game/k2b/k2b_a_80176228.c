struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; int extra; };
struct K2bHandler { void **vtable; };
extern void *w3d_s20_forward_held_8019013c(struct K2bItem *item);
int w3d_k2b_apply_held_items_80176228(struct K2bHandler *self, struct K2bItem *items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    struct K2bItem *p;
    if (i < count) {
        p = items;
        do {
            void **vtable = self->vtable;
            int status = ((int (*)(struct K2bHandler *, struct K2bItem *, void *, int, int))vtable[14])(self, p, w3d_s20_forward_held_8019013c(p), p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with its forwarded held object through a virtual handler and return the last negative status.
