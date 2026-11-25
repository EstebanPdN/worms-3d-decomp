// Memory-stream seek: origin 0 from the start, 1 from the current position,
// 2 from the end. Targets past the size fail with 0x90000003 and unknown
// origins with 0x90000002; the previous position is reported first. Partial
// observed view: size at +76, position at +104; full type and sizeof unknown.
struct cc39d_MemoryStream { unsigned char unknown00[76]; unsigned int size; unsigned char unknown50[24]; unsigned int position; };
extern "C" int cc39d_stream_seek_80218bc0(cc39d_MemoryStream *self, int offset, int origin, unsigned int *previous) {
    if (previous) *previous = self->position;
    unsigned int target = offset;
    switch (origin) {
    case 0: break;
    case 2: target += self->size; break;
    case 1: target += self->position; break;
    default: return (int)0x90000002;
    }
    if (target > self->size) return (int)0x90000003;
    self->position = target;
    return 0;
}
