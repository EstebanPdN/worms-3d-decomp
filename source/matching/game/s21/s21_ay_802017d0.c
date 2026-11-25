// desc: Appears to replace a shared string pointer with an entry of a string table chosen by a helper, adjusting reference counts and releasing the old header at zero.
#define S21_ENTRY (*(char **)((char *)table + (index << 2)))
struct S21Owner { char pad[140]; char **table; };
extern int fn_802024f4(struct S21Owner *);
extern void fn_8020bb2c(void *);
int w3d_s21_select_string_802017d0(struct S21Owner *self, char **slot)
{
    int index = fn_802024f4(self);
    char **table = self->table;
    unsigned short *count = (unsigned short *)(S21_ENTRY - 6);
    ++*count;
    {
        unsigned short *header = (unsigned short *)(*slot - 6);
        unsigned short remaining = --*header;
        if (remaining == 0)
            fn_8020bb2c(header);
    }
    *slot = S21_ENTRY;
    return 0;
}
