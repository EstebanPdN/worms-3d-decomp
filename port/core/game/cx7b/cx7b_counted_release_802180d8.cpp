#include "w3d_ptr.h"
#line 1 "cx7b_counted_release_802180d8.cpp"
// Inferred layout: vtable at +0, unsigned reference count at +4.
struct Cx7bCounted;
struct Cx7bCountedVtable { Ptr32<void> slots[11]; Ptr32<void (Ptr32<Cx7bCounted>, int)> destroy; };
struct Cx7bCounted { Ptr32<Cx7bCountedVtable> vtable; unsigned short references; };
extern "C" unsigned short w3d_cx7b_counted_release_802180d8(Ptr32<Cx7bCounted> self) {
 unsigned short left = --self->references;
 if (left == 0 && self) self->vtable->destroy(self,3);
 return left;
}


