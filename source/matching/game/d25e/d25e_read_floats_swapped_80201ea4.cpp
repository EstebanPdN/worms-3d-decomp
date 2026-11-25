// (Worms 3D GameCube PAL, 0x80201ea4).
//
// Stream reader for n big-endian floats: with a null output skips n*4 bytes
// through virtual slot 7 (origin 1); otherwise reads n*4 bytes through slot
// 5 and byte-swaps each float in place.

inline void Swap(float &v) { unsigned x = *(unsigned *)&v; unsigned r = (x << 24) | ((x & 0xff00) << 8) | ((x >> 8) & 0xff00) | (x >> 24); v = *(float *)&r; }
struct Stream { void **vtable; };
struct Reader { char u[20]; Stream *stream; };
extern "C" void w3d_d25e_read_floats_swapped_80201ea4(Reader *self, float *out, unsigned n) {
    if (out == 0) {
        ((int (*)(Stream *, unsigned, int, int))self->stream->vtable[7])(self->stream, n << 2, 1, 0);
    } else {
        ((int (*)(Stream *, void *, unsigned, int))self->stream->vtable[5])(self->stream, out, n << 2, 0);
        float *p = out;
        for (unsigned i = 0; i < n; ++i) Swap(*p++);
    }
}
