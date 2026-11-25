struct S19V3 { float x, y, z; };
struct S19Obj { char pad0[140]; struct S19V3 a; char pad152[12]; struct S19V3 b; char pad176[32]; int h208; int h212; };
extern struct S19V3 *w3d_auto_80178ec4(void *);

void s19_load_vectors_8009313c(struct S19Obj *self)
{
    self->a = *w3d_auto_80178ec4(self->h208);
    self->b = *w3d_auto_80178ec4(self->h212);
}
