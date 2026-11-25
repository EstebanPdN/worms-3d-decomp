struct S19V3 { int x, y, z; };
extern void FUN_800a5e04(void *);
struct S19Obj { char pad0[36]; struct S19V3 v; };
static inline void s19_clear(struct S19V3 *q) {
    q->z = 0;
    q->y = 0;
    q->x = 0;
}
void *s19_reset_range_800a5d6c(struct S19Obj *self)
{
    s19_clear(&self->v);
    FUN_800a5e04(self);
    return self;
}
