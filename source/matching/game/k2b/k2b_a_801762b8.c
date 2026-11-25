struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; };
struct K2bHandler { void **vtable; };
int w3d_k2b_apply_plain_items_801762b8(struct K2bHandler *self, struct K2bItem *items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    struct K2bItem *p;
    if (i < count) {
        p = items;
        do {
            int status = ((int (*)(struct K2bHandler *, struct K2bItem *, void *, int, int))self->vtable[15])(self, p, 0, p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with no extra object through a virtual handler and return the last negative status.
