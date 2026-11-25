// Variant trials for 0x80218bc0 (per-case limit loads).
struct cc39d_MemoryStream { unsigned char unknown00[76]; unsigned int size; unsigned char unknown50[24]; unsigned int position; };
extern "C" int cc39d_seek_a(cc39d_MemoryStream *self, int offset, int origin, unsigned int *previous) {
    if (previous) *previous = self->position;
    unsigned int target, limit;
    switch (origin) {
    case 0: target = offset; limit = self->size; break;
    case 2: target = self->size + offset; limit = self->size; break;
    case 1: target = self->position + offset; limit = self->size; break;
    default: return (int)0x90000002;
    }
    if (target > limit) return (int)0x90000003;
    self->position = target;
    return 0;
}
extern "C" int cc39d_seek_b(cc39d_MemoryStream *self, int offset, int origin, unsigned int *previous) {
    if (previous) *previous = self->position;
    unsigned int target, limit;
    switch (origin) {
    case 0: limit = self->size; target = offset; break;
    case 2: limit = self->size; target = limit + offset; break;
    case 1: limit = self->size; target = self->position + offset; break;
    default: return (int)0x90000002;
    }
    if (target > limit) return (int)0x90000003;
    self->position = target;
    return 0;
}
