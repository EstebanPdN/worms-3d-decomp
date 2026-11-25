// Heap trim (Worms 3D GameCube PAL, 0x802150b0).
// Consolidates free chunks (0x80213f98), then for each memory block whose last chunk
// is free: unlinks that chunk from the top slot, small bin or size tree (0x80213d90),
// asks the release hook (0x80400768 slot 1) to shrink the block, and returns any
// remaining chunk to its fresh bin. Field names are inferred from their use.

struct Node { Node *back; unsigned long size; Node *next; Node *prev; Node *self; };
struct Block { int a; Block *next; int c; int d; char *high; unsigned long reserve; };
struct Heap { unsigned long flags; int b,c; Block *blocks; Node *pending; Node *top; Node *root; Node *small[7]; Node *fresh[8]; };
struct Arena { char pad[48]; Heap *heap; };
struct Ops { void *acquire; int (*release)(Arena *, Block *, unsigned long, int); };
extern "C" Ops lbl_80400768[];
extern "C" int fn_80213f98(Heap *, Node *, int);
extern "C" Node *fn_80213d90(Heap *, unsigned long, Node *);
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
extern "C" int w3d_d28k_heap_trim_802150b0(Arena *self) {
 Heap *h = self->heap;
 unsigned long flags = h->flags;
 if ((flags & 1) == 0) {
  if (flags & 8192) return -1;
  h->flags = flags | 8192;
 }
 fn_80213f98(h, 0, 0);
 Block *b = h->blocks;
 if (b) do {
  Block *rest = b->next;
  Node *p = (Node *)(b->high - 8);
  if (p->size & 2) {
   p = ((Node **)p)[-1];
   unsigned long s = p->size;
   Node *a;
   if (s + (unsigned long)p + 16 >= (unsigned long)h->blocks->high) h->top = 0;
   else if (s != 8 && p->self == p) {
    a = p->next;
    if (a) a->prev = p->prev;
    a = p->prev;
    if (a) a->next = p->next;
    else h->small[(s - 8) >> 3] = p->next;
   } else fn_80213d90(h, p->size, p);
   ((Node *)((char *)p->size + (unsigned long)p + 8))->size &= ~2UL;
   if (s < b->reserve) s += 8;
   if (lbl_80400768[0].release(self, b, s, 1) >= 0) {
    s = (unsigned long)b->high - (unsigned long)p - 8;
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
