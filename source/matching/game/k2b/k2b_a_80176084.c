struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; float amount; };
struct K2bHandler { void **vtable; };
int w3d_k2b_apply_items_80176084(struct K2bHandler *self, struct K2bItem *items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    struct K2bItem *p;
    if (i < count) {
        p = items;
        do {
            int status = ((int (*)(struct K2bHandler *, struct K2bItem *, float, int, int))self->vtable[11])(self, p, p->amount, p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array through a virtual handler and return the last negative status, else zero.
