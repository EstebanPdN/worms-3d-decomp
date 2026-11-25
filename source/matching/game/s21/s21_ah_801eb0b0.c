// desc: Appears to return one when the first object's flag byte has bit 4 or 32 set, else the result of a virtual slot called with this.
struct S21Object;
struct S21Methods { void (*reserved[6])(void); int (*query)(struct S21Object *); };
struct S21First { char pad[7]; unsigned char flags; };
struct S21Object { struct S21First *first; struct S21Methods *methods; };
int w3d_s21_query_flags_801eb0b0(struct S21Object *self)
{
    unsigned flags = self->first->flags;
    if (flags & 4)
        goto done;
    if (flags & 32)
        goto done;
    return self->methods->query(self);
done:
    return 1;
}
