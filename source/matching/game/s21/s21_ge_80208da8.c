// desc: Appears to append bytes to a memory stream: it grows the stream through virtual slot 8 when the end passes the size, copies the data at the current position, advances the position and reports the count.
struct S21Stream;
struct S21StreamMethods { void (*reserved[8])(void); int (*reserve)(struct S21Stream *, unsigned); };
struct S21Stream { struct S21StreamMethods *methods; char pad[16]; char *buffer; int pad1; unsigned position; unsigned size; };
extern void *fn_802eee50(void *, const void *, unsigned);
int w3d_s21_write_bytes_80208da8(struct S21Stream *self, const void *data, unsigned count, unsigned *written)
{
    if (self->position + count > self->size)
        self->methods->reserve(self, self->position + count);
    fn_802eee50(self->buffer + self->position, data, count);
    self->position += count;
    if (written)
        *written = count;
    return 0;
}
