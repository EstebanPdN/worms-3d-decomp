// desc: Appears to reset a memory stream and load it from a buffer: it reserves room through virtual slot 8, records the size and copies the data, or clears the fields when no data is given, then rewinds and returns zero.
struct S21Stream;
struct S21StreamMethods { void (*reserved[8])(void); int (*reserve)(struct S21Stream *, unsigned); };
struct S21Stream { struct S21StreamMethods *methods; char pad[16]; char *buffer; int flag; unsigned position; unsigned size; };
extern int fn_80208fd8(struct S21Stream *);
extern void *fn_802eee50(void *, const void *, unsigned, ...);
int w3d_s21_load_80208f48(struct S21Stream *self, const void *data, unsigned size)
{
    fn_80208fd8(self);
    self->flag = 0;
    if (data) {
        self->methods->reserve(self, size);
        self->size = size;
        fn_802eee50(self->buffer, data, size);
    } else {
        self->buffer = (char *)data;
        self->flag = (int)data;
        self->size = (unsigned)data;
    }
    self->position = 0;
    return 0;
}
