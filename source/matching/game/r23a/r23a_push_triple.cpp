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
extern "C" void initialize_buffer_8016e608(TripleBuffer *);
extern "C" void w3d_r23a_push_triple_8016e57c(TripleBuffer *self, int a, int b, int c) {
    if (self->ready == 0) initialize_buffer_8016e608(self);
    char *first = reinterpret_cast<char *>(&self->first_column);
    char *second = reinterpret_cast<char *>(&self->second_column);
    char *third = reinterpret_cast<char *>(&self->third_column);
    int *slot = reinterpret_cast<int *>(first + self->count * 12);
    *slot = a;
    slot = reinterpret_cast<int *>(second + self->count * 12);
    *slot = b;
    slot = reinterpret_cast<int *>(third + self->count * 12);
    *slot = c;
    self->count = self->count + 1;
}
