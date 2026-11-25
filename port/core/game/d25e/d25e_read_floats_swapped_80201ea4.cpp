#include "w3d_ptr.h"
#line 1 "d25e_read_floats_swapped_80201ea4.cpp"
// (Worms 3D GameCube PAL, 0x80201ea4).
//
// Stream reader for n big-endian floats: with a null output skips n*4 bytes
// through virtual slot 7 (origin 1); otherwise reads n*4 bytes through slot
// 5 and byte-swaps each float in place.

inline void Swap(float &v) { unsigned x = *(Ptr32<unsigned int>)&v; unsigned r = x; v = *(Ptr32<float>)&r; }
struct Stream { Ptr32<Ptr32<void>> vtable; };
struct Reader { char u[20]; Ptr32<Stream> stream; };
extern "C" void w3d_d25e_read_floats_swapped_80201ea4(Ptr32<Reader> self, Ptr32<float> out, unsigned n) {
    if (out == 0) {
        ((Ptr32<int (Ptr32<Stream>, unsigned int, int, int)>)self->stream->vtable[7])(self->stream, n << 2, 1, 0);
    } else {
        ((Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, int)>)self->stream->vtable[5])(self->stream, out, n << 2, 0);
        Ptr32<float> p = out;
        for (unsigned i = 0; i < n; ++i) Swap(*p++);
    }
}


