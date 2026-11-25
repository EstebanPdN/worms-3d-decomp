#include "w3d_ptr.h"
#line 1 "d28k_heap_trim_802150b0.cpp"
// Heap trim (Worms 3D GameCube PAL, 0x802150b0).
// Consolidates free chunks (0x80213f98), then for each memory block whose last chunk
// is free: unlinks that chunk from the top slot, small bin or size tree (0x80213d90),
// asks the release hook (0x80400768 slot 1) to shrink the block, and returns any
// remaining chunk to its fresh bin. Field names are inferred from their use.

struct Node { Ptr32<Node> back; unsigned int size; Ptr32<Node> next; Ptr32<Node> prev; Ptr32<Node> self; };
struct Block { int a; Ptr32<Block> next; int c; int d; Ptr32<char> high; unsigned int reserve; };
struct Heap { unsigned int flags; int b,c; Ptr32<Block> blocks; Ptr32<Node> pending; Ptr32<Node> top; Ptr32<Node> root; Ptr32<Node> small[7]; Ptr32<Node> fresh[8]; };
struct Arena { char pad[48]; Ptr32<Heap> heap; };
struct Ops { Ptr32<void> acquire; Ptr32<int (Ptr32<Arena>, Ptr32<Block>, unsigned int, int)> release; };
extern "C" Ops lbl_80400768[];
extern "C" int fn_80213f98(Ptr32<Heap>, Ptr32<Node>, int);
extern "C" Ptr32<Node> fn_80213d90(Ptr32<Heap>, unsigned int, Ptr32<Node>);
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
extern "C" int w3d_d28k_heap_trim_802150b0(Ptr32<Arena> self) {
 Ptr32<Heap> h = self->heap;
 unsigned int flags = h->flags;
 if ((flags & 1) == 0) {
  if (flags & 8192) return -1;
  h->flags = flags | 8192;
 }
 fn_80213f98(h, 0, 0);
 Ptr32<Block> b = h->blocks;
 if (b) do {
  Ptr32<Block> rest = b->next;
  Ptr32<Node> p = (Ptr32<Node>)(b->high - 8);
  if (p->size & 2) {
   p = ((Ptr32<Ptr32<Node>>)p)[-1];
   unsigned int s = p->size;
   Ptr32<Node> a;
   if (s + (unsigned int)w3d::H(p) + 16 >= (unsigned int)w3d::H(h->blocks->high)) h->top = 0;
   else if (s != 8 && p->self == p) {
    a = p->next;
    if (a) a->prev = p->prev;
    a = p->prev;
    if (a) a->next = p->next;
    else h->small[(s - 8) >> 3] = p->next;
   } else fn_80213d90(h, p->size, p);
   ((Ptr32<Node>)((Ptr32<char>)w3d::G(p->size) + (unsigned int)w3d::H(p) + 8))->size &= ~2UL;
   if (s < b->reserve) s += 8;
   if (lbl_80400768[0].release(self, b, s, 1) >= 0) {
    s = (unsigned int)w3d::H(b->high) - (unsigned int)w3d::H(p) - 8;
    if (s) p->size = s - 8;
    else p = 0;
   }
   if (p) {
    p->size |= 5;
    p->next = h->fresh[BIN(p->size)];
    h->fresh[BIN(p->size)] = p;
   }
  }
  b = rest;
 } while (b);
 h->flags &= ~8192UL;
 return 0;
}


