#include "w3d_ptr.h"
#line 1 "d28k_fixed_allocate_80216c4c.cpp"
// Fixed-size pool allocate (Vmalloc poolalloc shape; Worms 3D GameCube PAL, 0x80216c4c).
// Zero size or a size other than the pool's fixed size fails. The first call fixes the size
// and carves the spare chunk of every block into pending slots (marked 0x55555555). Pops a
// pending slot, else grows through the system hook and carves the new block, clearing the
// retry flag 4096 once on failure, then calls the watch hook. Names are inferred.

struct Node { Ptr32<Node> back; unsigned int size; };
struct Block { int a; Ptr32<Block> next; int c; int d; Ptr32<char> high; int e; Ptr32<Node> spare; };
struct Heap { unsigned int flags; unsigned int gran; unsigned int fixed; Ptr32<Block> blocks; Ptr32<Node> pending; };
struct Arena { char pad[48]; Ptr32<Heap> heap; };
typedef Ptr32<Ptr32<Node> (Ptr32<Arena>, unsigned int, Ptr32<void>)> Grow;
extern "C" Grow lbl_80400768[];
extern "C" Ptr32<void (Ptr32<Arena>, Ptr32<void>, Ptr32<void>, unsigned int)> lbl_8040077c[];
extern "C" Ptr32<Node> w3d_d28k_fixed_allocate_80216c4c(Ptr32<Arena> self, unsigned int size) {
 Ptr32<Heap> h = self->heap;
 Ptr32<Node> n;
 unsigned int guard; unsigned int room;
 if (!size) goto none;
 guard = h->flags & 1;
 if (!guard) {
  if (h->flags & 8192) goto none;
  if (h->fixed && size != h->fixed) {
  none:
   return 0;
  pop:
   h->pending = n->back;
   goto done;
  }
  h->flags |= 8192;
 }
 if (h->fixed == 0) {
  Ptr32<Block> b = h->blocks;
  h->fixed = size;
  size = (size + 7) & ~7UL;
  while (b) {
   n = b->spare;
   if (n) {
    b->spare = 0;
    room = (n->size & ~7UL) + 8;
    if (room >= size) do {
     n->size = 0x55555555;
     room -= size;
     n->back = h->pending;
     h->pending = n;
     n = (Ptr32<Node>)((Ptr32<char>)n + size);
    } while (room >= size);
   }
   b = b->next;
  }
 }
 for (;;) {
  n = h->pending;
  if (n) goto pop;
  {
   unsigned int g = h->gran;
   Ptr32<Grow> t = lbl_80400768;
   unsigned int k = g - 1;
   if (g & k) { room = h->fixed - 1; room += g; room /= g; size = room * g; }
   else { room = h->fixed - 1; room += g; size = room & ~k; }
   n = t[0](self, size, 0);
  }
  if (n) break;
  {
   unsigned int t = h->flags;
   if ((t & 4096) == 0) goto done;
   h->flags = t & ~4096UL;
  }
 }
 {
  size = (h->fixed + 7) & ~7UL;
  Ptr32<Node> q = (Ptr32<Node>)((Ptr32<char>)n + size);
  Ptr32<char> first = (Ptr32<char>)q + 8;
  room = h->blocks->high - first;
  if (room >= size) do {
   q->size = 0x55555555;
   room -= size;
   q->back = h->pending;
   h->pending = q;
   q = (Ptr32<Node>)((Ptr32<char>)q + size);
  } while (room >= size);
 }
done:
 if (!guard && (h->flags & 2) && lbl_8040077c[0] && n) lbl_8040077c[0](self, 0, n, h->fixed);
 h->flags &= ~8192UL;
 return n;
}


