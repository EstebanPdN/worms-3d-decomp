struct K6bStream { void **vtable; };
struct K6bReader {
    char head[20];
    struct K6bStream *stream;
};
static inline unsigned int k6b_swap32(unsigned int v)
{
    return (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24);
}
void w3d_k6b_reader_read_u32_swapped_80201630(struct K6bReader *self, unsigned int *value)
{
    ((void (*)(struct K6bStream *, void *, int, int))self->stream->vtable[5])(self->stream, value, 4, 0);
    *value = k6b_swap32(*value);
}
// desc: w3d_k6b_reader_read_u32_swapped_80201630: Appears to read four bytes through virtual slot 5 of the stream at +20 and byte-swap the word in place.
