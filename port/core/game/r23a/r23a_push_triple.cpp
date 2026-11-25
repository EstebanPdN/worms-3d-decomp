#include "w3d_ptr.h"
#line 1 "r23a_push_triple.cpp"
// Isolated from historical s20_small_ap; the old source and receipt are preserved.
// GWMP8P rev0 PPC32: three int columns start at +4/+8/+12 with stride 12.
// The count is +552 and readiness word +556; allocation/capacity are unresolved.
// Fields describe observed offsets, not a verified complete class or capacity.
struct TripleBuffer {
    int unknown_header;
    int first_column;
    int second_column;
    int third_column;
    unsigned char unknown_16[536];
    int count;
    int ready;
};
extern "C" void initialize_buffer_8016e608(Ptr32<TripleBuffer>);
extern "C" void w3d_r23a_push_triple_8016e57c(Ptr32<TripleBuffer> self, int a, int b, int c) {
    if (self->ready == 0) initialize_buffer_8016e608(self);
    Ptr32<char> first = reinterpret_cast<char *>(w3d::R(&self->first_column));
    Ptr32<char> second = reinterpret_cast<char *>(w3d::R(&self->second_column));
    Ptr32<char> third = reinterpret_cast<char *>(w3d::R(&self->third_column));
    Ptr32<int> slot = reinterpret_cast<int *>(w3d::R(first + self->count * 12));
    *slot = a;
    slot = reinterpret_cast<int *>(w3d::R(second + self->count * 12));
    *slot = b;
    slot = reinterpret_cast<int *>(w3d::R(third + self->count * 12));
    *slot = c;
    self->count = self->count + 1;
}


