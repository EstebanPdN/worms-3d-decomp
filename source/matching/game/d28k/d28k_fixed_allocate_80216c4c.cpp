// Fixed-size pool allocate (Vmalloc poolalloc shape; Worms 3D GameCube PAL, 0x80216c4c).
// Zero size or a size other than the pool's fixed size fails. The first call fixes the size
// and carves the spare chunk of every block into pending slots (marked 0x55555555). Pops a
// pending slot, else grows through the system hook and carves the new block, clearing the
// retry flag 4096 once on failure, then calls the watch hook. Names are inferred.

struct Node { Node *back; unsigned long size; };
struct Block { int a; Block *next; int c; int d; char *high; int e; Node *spare; };
struct Heap { unsigned long flags; unsigned long gran; unsigned long fixed; Block *blocks; Node *pending; };
struct Arena { char pad[48]; Heap *heap; };
typedef Node *(*Grow)(Arena *, unsigned long, void *);
extern "C" Grow lbl_80400768[];
extern "C" void (*lbl_8040077c[])(Arena *, void *, void *, unsigned long);
extern "C" Node *w3d_d28k_fixed_allocate_80216c4c(Arena *self, unsigned long size) {
 Heap *h = self->heap;
 Node *n;
 unsigned long guard, room;
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
  Block *b = h->blocks;
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
     n = (Node *)((char *)n + size);
    } while (room >= size);
   }
   b = b->next;
  }
 }
 for (;;) {
  n = h->pending;
  if (n) goto pop;
  {
   unsigned long g = h->gran;
   Grow *t = lbl_80400768;
   unsigned long k = g - 1;
   if (g & k) { room = h->fixed - 1; room += g; room /= g; size = room * g; }
   else { room = h->fixed - 1; room += g; size = room & ~k; }
   n = t[0](self, size, 0);
  }
  if (n) break;
  {
   unsigned long t = h->flags;
   if ((t & 4096) == 0) goto done;
   h->flags = t & ~4096UL;
  }
 }
 {
  size = (h->fixed + 7) & ~7UL;
  Node *q = (Node *)((char *)n + size);
  char *first = (char *)q + 8;
  room = h->blocks->high - first;
  if (room >= size) do {
   q->size = 0x55555555;
   room -= size;
   q->back = h->pending;
   h->pending = q;
   q = (Node *)((char *)q + size);
  } while (room >= size);
 }
done:
 if (!guard && (h->flags & 2) && lbl_8040077c[0] && n) lbl_8040077c[0](self, 0, n, h->fixed);
 h->flags &= ~8192UL;
 return n;
}
