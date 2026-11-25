struct K2bVec3 { float x, y, z; };
struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; struct K2bVec3 vector; };
struct K2bHandler { void **vtable; };
int w3d_k2b_apply_vector_items_80176108(struct K2bHandler *self, struct K2bItem *items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    struct K2bItem *p;
    if (i < count) {
        p = items;
        do {
            struct K2bVec3 vector;
            int status;
            vector.x = p->vector.x;
            vector.y = p->vector.y;
            vector.z = p->vector.z;
            status = ((int (*)(struct K2bHandler *, struct K2bItem *, struct K2bVec3 *, int, int))self->vtable[12])(self, p, &vector, p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with a copy of its vector through a virtual handler and return the last negative status.
