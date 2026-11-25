#include "w3d_ptr.h"
#line 1 "d28k_fixed_resize_8021707c.cpp"
// Fixed-size pool resize (Worms 3D GameCube PAL, 0x8021707c).
// A null block allocates through 0x80216c4c and clears it when mode bit 4 is set; size
// zero frees through 0x80216f5c. Otherwise only the pool's own fixed size is accepted:
// the block is checked (0x80216e7c), a failure goes to the arena's error hook with code 3,
// and the realloc hook (0x8040077c) is notified. Field names are inferred from use.

struct Heap { unsigned int flags; int b; unsigned int fixed; };
struct Hooks { int a; Ptr32<void (Ptr32<void>, int, Ptr32<void>, Ptr32<Hooks>)> fail; };
struct Arena { char pad[44]; Ptr32<Hooks> hooks; Ptr32<Heap> heap; };
extern "C" Ptr32<void> fn_80216c4c(Ptr32<Arena>, unsigned int);
extern "C" int fn_80216f5c(Ptr32<Arena>, Ptr32<void>);
extern "C" int fn_80216e7c(Ptr32<Arena>, Ptr32<void>);
extern "C" Ptr32<void (Ptr32<Arena>, Ptr32<void>, Ptr32<void>, unsigned int)> lbl_8040077c[];
extern "C" Ptr32<void> w3d_d28k_fixed_resize_8021707c(Ptr32<Arena> self, Ptr32<void> mem, unsigned int size, int mode) {
 Ptr32<Heap> h = self->heap;
 if (!mem) {
  mem = fn_80216c4c(self, size);
  if (mem && (mode & 4)) {
   Ptr32<char> end = (Ptr32<char>)mem + size;
   Ptr32<int> q = (Ptr32<int>)mem;
   do { *q++ = 0; } while ((Ptr32<char>)q < end);
  }
 } else {
  if (size == 0) {
   fn_80216f5c(self, mem);
  fail:
   return 0;
  }
  unsigned int flags = h->flags;
  if ((flags & 1) == 0) {
   if (flags & 8192) goto fail;
   if (size == h->fixed) {
    h->flags = flags | 16384;
    if (fn_80216e7c(self, mem) == 0) goto ok;
   }
   {
    Ptr32<Hooks> k = self->hooks;
    if (k->fail) k->fail(self, 3, mem, k);
   }
   goto fail;
  ok:
   if ((h->flags & 2) && lbl_8040077c[0]) lbl_8040077c[0](self, mem, mem, size);
  }
 }
 return mem;
}


