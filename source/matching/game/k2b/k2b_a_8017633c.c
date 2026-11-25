struct K2bColor { unsigned char r, g, b, a; };
struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; struct K2bColor color; };
struct K2bHandler { void **vtable; };
int w3d_k2b_apply_color_items_8017633c(struct K2bHandler *self, struct K2bItem *items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    struct K2bItem *p;
    if (i < count) {
        p = items;
        do {
            struct K2bColor color;
            int status;
            color.r = p->color.r;
            color.g = p->color.g;
            color.b = p->color.b;
            color.a = p->color.a;
            status = ((int (*)(struct K2bHandler *, struct K2bItem *, struct K2bColor *, int, int))self->vtable[16])(self, p, &color, p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with a copy of its color through a virtual handler and return the last negative status.
