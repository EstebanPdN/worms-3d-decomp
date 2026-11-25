#include "w3d_ptr.h"
#line 1 "tsonnet_c26_pop.cpp"
struct TsonnetC26Item { int lo; int hi; TsonnetC26Item() {} TsonnetC26Item(const TsonnetC26Item &o) { hi = o.hi; lo = o.lo; } };
struct TsonnetC26Stack { char head[16]; TsonnetC26Item items[256]; int count; };
extern "C" void tsonnet_c26_stack_pop_8020f8ac(Ptr32<TsonnetC26Stack> self, Ptr32<TsonnetC26Item> out) {
 self->count--;
 *out = self->items[self->count];
}


