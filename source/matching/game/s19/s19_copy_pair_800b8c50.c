struct S19Pair { int w[12]; };
struct S19Owner { char pad0[4]; char *data; };

void s19_copy_pair_800b8c50(struct S19Owner *self, struct S19Pair *dst)
{
    *dst = *(struct S19Pair *)(self->data + 240);
}

void s19_copy_pair_800b8ca0(struct S19Owner *self, struct S19Pair *dst)
{
    *dst = *(struct S19Pair *)(self->data + 144);
}
