struct K4bVec3 { float x, y, z; };
struct K4bBox {
    void **vtable;
    char base[16];
    struct K4bVec3 min;
    struct K4bVec3 max;
    int valid;
    int slots[4];
};
extern void *lbl_80415ac8[];
extern struct K4bVec3 lbl_8045e690[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
static inline void k4b_vec3_copy(struct K4bVec3 *d, const struct K4bVec3 *s)
{
    float x = s->x;
    float y = s->y;
    float z = s->z;
    d->x = x;
    d->y = y;
    d->z = z;
}
struct K4bBox *w3d_k4b_box_construct_801b5b30(struct K4bBox *self, void * arg_r4)
{
    unsigned int i;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_80415ac8;
    k4b_vec3_copy(&self->min, &lbl_8045e690[0]);
    k4b_vec3_copy(&self->max, &lbl_8045e690[1]);
    self->valid = 1;
    for (i = 0; i < 4; i++)
        self->slots[i] = 0;
    return self;
}
// desc: w3d_k4b_box_construct_801b5b30: Appears to construct a bounds-like object over 0x801ea0ec: vtable 0x80415ac8, two vectors copied from a global pair at 0x8045e690, valid flag and four cleared slots.
