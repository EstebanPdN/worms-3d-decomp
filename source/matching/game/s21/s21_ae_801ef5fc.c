// desc: Appears to locate an embedded object using an offset from the type table, store one of its fields and return its member address.
struct S21TypeTable { char pad[4]; unsigned short offset; };
struct S21Holder { struct S21TypeTable *types; };
char *w3d_s21_locate_member_801ef5fc(struct S21Holder *self, char *base, int *out)
{
    char *object = *(char **)(base + self->types->offset);
    *out = *(int *)(object + 24);
    return object + 32;
}
