struct TsonnetC26Stream { void **vtable; };
struct TsonnetC26Reader { char head[20]; struct TsonnetC26Stream *stream; };
static inline unsigned int tsonnet_c26_swap32(unsigned int v) { return (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24); }
void tsonnet_c26_read_u32_swapped_80201630(struct TsonnetC26Reader *self, unsigned int *value) {
 ((void (*)(struct TsonnetC26Stream *, void *, int, int))self->stream->vtable[5])(self->stream, value, 4, 0);
 *value = tsonnet_c26_swap32(*value);
}
