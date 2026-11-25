// desc: Appears to set a byte buffer: it stores the size, releases the old buffer, then allocates a copy of the data of that size or clears the pointer when no data is given, returning zero.
struct S21Object { char pad[20]; unsigned size; void *buffer; };
extern void fn_801fe240(void *);
extern void *fn_801fe220(unsigned);
extern void *fn_802eee50(void *, const void *, unsigned, ...);
int w3d_s21_set_buffer_801df57c(struct S21Object *self, unsigned size, const void *data)
{
    self->size = size;
    if (self->buffer)
        fn_801fe240(self->buffer);
    if (data) {
        void *copy = fn_801fe220(self->size);
        self->buffer = copy;
        fn_802eee50(copy, data, self->size);
    } else
        self->buffer = (void *)data;
    return 0;
}
