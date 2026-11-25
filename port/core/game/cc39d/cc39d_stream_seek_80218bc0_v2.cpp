#include "w3d_ptr.h"
#line 1 "cc39d_stream_seek_80218bc0_v2.cpp"
// Memory-stream seek (0x80218bc0). Reports the previous position when an
// output is supplied, then forms the target from origin 0 (start), 2 (end:
// size + offset) or 1 (current: position + offset); each origin reads the
// size limit itself. The target and limit compare unsigned, so a negative
// result wraps and fails. Unknown origins return 0x90000002 and targets past
// the size return 0x90000003, both leaving the position unchanged.
// Partial observed view: size at +76, position at +104; the full type, its
// other members and sizeof are unknown.
struct cc39d_MemoryStream { unsigned char unknown00[76]; unsigned int size; unsigned char unknown50[24]; unsigned int position; };
extern "C" int cc39d_stream_seek_80218bc0(Ptr32<cc39d_MemoryStream> self, int offset, int origin, Ptr32<unsigned int> previous) {
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


