#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b33_arena_801613f0.c"
/* Bump allocation from a buffer. The request size is rounded up to a multiple
   of four and a four-byte length header is added. When the request does not
   fit between the current offset and the capacity, the offset restarts at
   zero. The header holds the rounded size and the payload pointer follows it.
   The original compares the offset with a fourth field and stores the same
   new offset on both outcomes; that comparison has no effect on the result and
   is kept only because it reproduces the instructions. Offsets are observed;
   field names and meanings are inferred. */
typedef struct { Ptr32<char> base; unsigned used; unsigned cap; unsigned limit; } Arena;
Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<Arena> a, int n) {
    unsigned need = (((unsigned)n + 3) & ~3u) + 4;
    unsigned off;
    Ptr32<char> hdr;
    if (need > a->cap - a->used)
        a->used = 0;
    off = a->used;
    hdr = a->base + off;
    if (off < a->limit) a->used = off + need; else a->used = off + need;
    *(Ptr32<unsigned int>)hdr = need;
    return hdr + 4;
}

}
