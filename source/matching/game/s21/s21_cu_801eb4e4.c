// desc: Appears to compare the bytes at a descriptor's halfword offset in two buffers over a length from a helper and report whether they are equal.
struct S21Info { char pad[4]; unsigned short offset; char pad1[2]; int size; };
struct S21Object { struct S21Info *info; };
extern unsigned fn_80200050(int);
extern int fn_802eedc0(const void *, const void *, unsigned);
int w3d_s21_equal_801eb4e4(struct S21Object *self, char *a, char *b)
{
    struct S21Info *info = self->info;
    unsigned short offset = info->offset;
    char *first = a + offset;
    char *second = b + offset;
    unsigned length = fn_80200050(info->size);
    return fn_802eedc0(first, second, length) == 0;
}
