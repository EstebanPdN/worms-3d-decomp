// desc: Appears to call virtual slot 5 of the object with its arguments, clearing bit 4 of the last one.
struct S21Object;
struct S21Methods { void (*reserved[5])(void); int (*open)(struct S21Object *, int, unsigned); };
struct S21Object { struct S21Methods *methods; };
int w3d_s21_open_masked_802185c8(struct S21Object *self, int name, unsigned flags)
{
    return self->methods->open(self, name, flags & ~4);
}
