// Inferred layout: vtable at +0, unsigned reference count at +4.
struct Cx7bCounted;
struct Cx7bCountedVtable { void *slots[11]; void (*destroy)(Cx7bCounted *, int); };
struct Cx7bCounted { Cx7bCountedVtable *vtable; unsigned short references; };
extern "C" unsigned short w3d_cx7b_counted_release_802180d8(Cx7bCounted *self) {
 unsigned short left = --self->references;
 if (left == 0 && self) self->vtable->destroy(self,3);
 return left;
}
