struct S19Ctx { char pad0[424]; int group; char pad428[36]; int value; };
extern struct { void **begin; void **end; int pad[2]; } lbl_8043bb64;
extern struct S19Ctx *w3d_get_800b4d98(void *);

int s19_find_peer_value_800be8f8(struct S19Ctx *self)
{
    void **it = lbl_8043bb64.begin;
    void **end = lbl_8043bb64.end;
    for (; it != end; it++) {
        if (w3d_get_800b4d98(*it) != self && w3d_get_800b4d98(*it)->group == self->group)
            return w3d_get_800b4d98(*it)->value;
    }
    return 0;
}
