#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c32_storage_open_8020f3f0.c"
/* Reference-only: first-use initialization of a storage request. Unless the
   state word at offset 0 is already 1, initializes the backing store, appends a
   block, rounds the size at offset 4 up to 32 bytes, records it and the
   32-byte-aligned limit from offset 12 in the new block and sets the state to
   1. Returns 1 when it initialized and 0 when it was already open. Field
   offsets are observed; names and meanings are inferred. */
struct Block { unsigned int size; unsigned int limit; };
struct Request { int state; unsigned int size; int unknown08; unsigned int limit; };
extern int fn_8020f8d4(void);
extern Ptr32<struct Block> fn_8020f850(Ptr32<struct Request> self);

int tsonnet_c32_storage_open_8020f3f0(Ptr32<struct Request> self) {
    Ptr32<struct Block> b;
    if (self->state == 1) return 0;
    fn_8020f8d4();
    b = fn_8020f850(self);
    self->size = (self->size + 31) & ~31u;
    b->size = self->size;
    b->limit = self->limit & ~31u;
    self->state = 1;
    return 1;
}

}
