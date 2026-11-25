#include "w3d_ptr.h"
#line 1 "d28k_heap_allocate_80214344.cpp"
// Heap allocate (Worms 3D GameCube PAL, 0x80214344).
// Bins are small (exact, 7 lists) and fresh (8 lists, unconsolidated). Tries the matching
// fresh list, then splits the pending chunk, searches the small bins, consolidates, takes
// the smallest fit from the size tree (0x80213d90), retries after consolidation, uses the top
// chunk, then the system hook. The spare tail goes back as pending or as the new top.
// The request parameter is reused as the tail chunk pointer, as the register use in the
// original shows. Field names are inferred.

struct Node { Ptr32<Node> back; unsigned int size; Ptr32<Node> next; Ptr32<Node> prev; Ptr32<Node> self; };
struct Block { int a; Ptr32<Block> next; int c; int d; Ptr32<char> high; };
struct Heap { unsigned int flags; int b,c; Ptr32<Block> blocks; Ptr32<Node> pending; Ptr32<Node> top; Ptr32<Node> root; Ptr32<Node> small[15]; };
struct Arena { char pad[48]; Ptr32<Heap> heap; };
extern "C" Ptr32<Node> fn_80213d90(Ptr32<Heap>, unsigned int, Ptr32<Node>);
extern "C" int fn_80213f98(Ptr32<Heap>, Ptr32<Node>, int);
typedef Ptr32<Ptr32<Node> (Ptr32<Arena>, unsigned int, Ptr32<Ptr32<Node> (Ptr32<Heap>, unsigned int, Ptr32<Node>)>)> Grow;
extern "C" Grow lbl_80400768[];
extern "C" Ptr32<void (Ptr32<Arena>, Ptr32<void>, Ptr32<void>, unsigned int)> lbl_8040077c[];
extern "C" Ptr32<char> w3d_d28k_heap_allocate_80214344(Ptr32<Arena> self, unsigned int size) {
 Ptr32<Heap> h = self->heap;
 unsigned int flags = h->flags; unsigned int want; unsigned int s;
 unsigned int guard = flags & 1;
 Ptr32<Node> n;
 unsigned int asked;
 if (guard == 0) {
  unsigned int t; t = flags & ~16384UL;
  guard = flags & 16384;
  h->flags = t;
  if (guard == 0) {
   if (flags & 8192) {
   fail:
    return 0;
   }
   h->flags = t | 8192;
  }
  asked = size;
 }
 want = size <= 8 ? 8 : (size + 7) & ~7UL;
 if (want <= 63) {
  int off = ((want - 8) >> 1) + 56;
  n = *(Ptr32<Ptr32<Node>>)((Ptr32<char>)h + off);
  if (n) {
   *(Ptr32<Ptr32<Node>>)((Ptr32<char>)h + off) = n->next;
   n->size = n->size & ~4UL;
   goto mark;
  }
 }
 n = h->pending;
 if (n) {
  h->pending = 0;
  s = n->size;
  if (s < want) {
   n->next = h->small[14];
   h->small[14] = n;
  } else {
   if (s >= want + 16) {
    unsigned int left = (s & ~7UL) - 8;
    Ptr32<Node> b = n->back;
    n->size = want;
    unsigned int off = want + 8;
    left -= want;
    *(Ptr32<Ptr32<Node>>)((Ptr32<char>)n + off) = b;
    size = (unsigned int)w3d::H(((Ptr32<char>)n + off));
    left |= 5;
    ((Ptr32<Node>)w3d::G(size))->size = left;
    h->pending = (Ptr32<Node>)w3d::G(size);
    n->size |= s & 7;
   }
   n->size = n->size & ~4UL;
   goto mark;
  }
 }
 goto search;
take:
 h->top = 0;
 goto split;
search:
 for (;;) {
  {
   s = (want - 8) >> 3;
   if (s <= 6) {
    unsigned int o = (s << 2) + 28;
    Ptr32<Ptr32<Node>> slot = (Ptr32<Ptr32<Node>>)((Ptr32<char>)w3d::G(o) + (unsigned int)w3d::H(h));
    do {
     n = *slot;
     if (n) {
      if (n->size != 8 && n->self == n) {
       size = (unsigned int)w3d::H(n->next);
       if (size) ((Ptr32<Node>)w3d::G(size))->prev = n->prev;
       size = (unsigned int)w3d::H(n->prev);
       if (size) ((Ptr32<Node>)w3d::G(size))->next = n->next;
       else *slot = n->next;
      } else fn_80213d90(h, n->size, n);
      ((Ptr32<Node>)((Ptr32<char>)w3d::G(n->size) + (unsigned int)w3d::H(n) + 8))->size &= ~2UL;
      goto split;
     }
     s++;
     slot++;
    } while (s <= 6);
   }
  }
  if (h->small[14]) fn_80213f98(h, 0, 7);
  if (h->root) {
   n = fn_80213d90(h, want, 0);
   if (n) goto split;
  }
  if (fn_80213f98(h, 0, 0)) continue;
  if ((h->flags & 16) == 0) {
   n = h->top;
   if (n && n->size >= want) goto take;
  }
  n = lbl_80400768[0](self, want, fn_80213d90);
  if (n) goto split;
  {
   unsigned int t = h->flags;
   if (t & 4096) {
    h->flags = t & ~4096UL;
    continue;
   }
   if (guard) goto fail;
   h->flags = t & ~8192UL;
   goto fail;
  }
 }
split:
 ((Ptr32<Node>)((Ptr32<char>)w3d::G(n->size) + (unsigned int)w3d::H(n) + 8))->size &= ~2UL;
 s = n->size - want;
 if (s > 15) {
  n->size = want;
  unsigned int off = want + 8;
  Ptr32<Node> b = n->back;
  *(Ptr32<Ptr32<Node>>)((Ptr32<char>)n + off) = b;
  size = (unsigned int)w3d::H(((Ptr32<char>)n + off));
  ((Ptr32<Node>)w3d::G(size))->size = (s - 8) | 5;
  if (!h->root || (Ptr32<char>)w3d::G(((Ptr32<Node>)w3d::G(size))->size) + size + 16 < h->blocks->high) h->pending = (Ptr32<Node>)w3d::G(size);
  else {
   unsigned int t = ((Ptr32<Node>)w3d::G(size))->size & ~7UL;
   ((Ptr32<Node>)w3d::G(size))->size = t;
   *(Ptr32<Ptr32<Node>>)((Ptr32<char>)w3d::G(t) + size + 4) = (Ptr32<Node>)w3d::G(size);
   ((Ptr32<Node>)((Ptr32<char>)w3d::G(((Ptr32<Node>)w3d::G(size))->size) + size + 8))->size |= 2;
   h->top = (Ptr32<Node>)w3d::G(size);
  }
 }
 n->size = n->size | 1;
mark:
 {
  Ptr32<char> p = (Ptr32<char>)n + 8;
  if (!guard) {
   unsigned int t = h->flags;
   if ((t & 2) && lbl_8040077c[0] && (t & 0x7c0) == 64) lbl_8040077c[0](self, 0, p, asked);
  }
  if (!guard) h->flags &= ~8192UL;
  return p;
 }
}


