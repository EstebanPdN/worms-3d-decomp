// desc: Appears to initialize a buffer-backed object from a source: it stores configuration constants, clamps the source size to 27456, zero-fills the rest of the buffer, marks it ready and returns the clamped size.
struct S21Source { char pad[12]; unsigned size; };
struct S21Object { unsigned char state; char pad[15]; struct S21Source *source; unsigned char a; unsigned char b; char pad1[66]; int limit; unsigned size; char *buffer; int w100; int w104; unsigned char flag; char pad2[3]; int w112; int w116; int w120; int w124; };
extern void *fn_802eefe0(void *, int, unsigned, ...);
unsigned w3d_s21_init_buffer_801e4074(struct S21Object *self, struct S21Source *source, unsigned char a, unsigned char b)
{
    unsigned size;
    self->w124 = 0;
    self->w100 = 54912;
    self->w104 = 96096;
    self->a = a;
    self->b = b;
    self->flag = 1;
    self->limit = 27456;
    self->source = source;
    self->w112 = 1;
    self->w116 = 0;
    self->w120 = 1;
    size = source->size;
    self->size = size;
    if (size < 27456)
        fn_802eefe0(self->buffer + size, 0, 27456 - size);
    else
        size = 27456;
    self->state = 2;
    return size;
}
