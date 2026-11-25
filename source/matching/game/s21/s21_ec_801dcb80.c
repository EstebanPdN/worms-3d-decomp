// desc: Appears to hand out a held interface: it fails with 0x80004005 when none is held, otherwise retains it, releases the previous value of the output and stores it, returning zero.
struct S21Ref;
struct S21RefMethods { void (*reserved[3])(void); void (*retain)(struct S21Ref *); void (*release)(struct S21Ref *); };
struct S21Ref { struct S21RefMethods *methods; };
struct S21Object { char pad[172]; struct S21Ref *held; };
int w3d_s21_get_held_801dcb80(struct S21Object *self, struct S21Ref **out)
{
    if (self->held == 0)
        return 0x80004005;
    self->held->methods->retain(self->held);
    if (*out)
        (*out)->methods->release(*out);
    *out = self->held;
    return 0;
}
