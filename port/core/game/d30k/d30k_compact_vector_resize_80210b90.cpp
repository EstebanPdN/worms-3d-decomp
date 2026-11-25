#include "w3d_ptr.h"
#line 1 "d30k_compact_vector_resize_80210b90.cpp"
// GWMP8P rev0 0x80210b90. Compact vector of held interfaces: shrinking
// clears the extra entries; growing allocates a new array with its count
// header (error message on failure), copies the held entries, frees the old
// array and updates capacity, data and size. Names are inferred from use.
// The size store appears in both arms and cross-jumps.
typedef unsigned int size_t;
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
extern "C" Ptr32<void> fn_801fe220(size_t);
extern "C" void fn_801fe240(Ptr32<void>);
extern "C" void fn_802fb7ac(Ptr32<const char>, ...);
extern char lbl_803b35bc[];
struct Held {
 Ptr32<Obj> p;
 Held() : p(0) {}
 ~Held() { if (p) p->vt->release(p); }
 template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *n) { if (p) p->vt->release(p); p = n; }
 void operator=(const Held &o) { if (o.p) o.p->vt->retain(o.p); if (p) p->vt->release(p); p = o.p; }
 void *operator new[](__SIZE_TYPE__ n) { return fn_801fe220(n); }
 void operator delete[](void *q) { fn_801fe240(q); }
};
struct List { unsigned size; unsigned short capacity; unsigned short quantum; Ptr32<Held> data; };
extern "C" void w3d_d30k_compact_vector_resize_80210b90(Ptr32<List> self, int n) {
 if (self->capacity >= n) {
  for (unsigned i = n; i < self->size; i++) self->data[i] = (Ptr32<Obj>)0;
  self->size = n;
 } else {
  Ptr32<Held> d = w3d::new_array<Held>(n);
  if (!d) {
   fn_802fb7ac(lbl_803b35bc, n);
   return;
  }
  if (self->data) {
   for (unsigned i = 0; i < self->size; i++) d[i] = self->data[i];
   w3d::delete_array(self->data);
  }
  self->data = d;
  self->size = n;
  self->capacity = n;
 }
}


