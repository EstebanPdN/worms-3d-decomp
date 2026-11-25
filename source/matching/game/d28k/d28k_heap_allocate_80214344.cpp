// Heap allocate (Worms 3D GameCube PAL, 0x80214344).
// Bins are small (exact, 7 lists) and fresh (8 lists, unconsolidated). Tries the matching
// fresh list, then splits the pending chunk, searches the small bins, consolidates, takes
// the smallest fit from the size tree (0x80213d90), retries after consolidation, uses the top
// chunk, then the system hook. The spare tail goes back as pending or as the new top.
// The request parameter is reused as the tail chunk pointer, as the register use in the
// original shows. Field names are inferred.

struct Node { Node *back; unsigned long size; Node *next; Node *prev; Node *self; };
struct Block { int a; Block *next; int c; int d; char *high; };
struct Heap { unsigned long flags; int b,c; Block *blocks; Node *pending; Node *top; Node *root; Node *small[15]; };
struct Arena { char pad[48]; Heap *heap; };
extern "C" Node *fn_80213d90(Heap *, unsigned long, Node *);
extern "C" int fn_80213f98(Heap *, Node *, int);
typedef Node *(*Grow)(Arena *, unsigned long, Node *(*)(Heap *, unsigned long, Node *));
extern "C" Grow lbl_80400768[];
extern "C" void (*lbl_8040077c[])(Arena *, void *, void *, unsigned long);
extern "C" char *w3d_d28k_heap_allocate_80214344(Arena *self, unsigned long size) {
 Heap *h = self->heap;
 unsigned long flags = h->flags, want, s;
 unsigned long guard = flags & 1;
 Node *n;
 unsigned long asked;
 if (guard == 0) {
  unsigned long t = flags & ~16384UL;
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
  n = *(Node **)((char *)h + off);
  if (n) {
   *(Node **)((char *)h + off) = n->next;
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
    unsigned long left = (s & ~7UL) - 8;
    Node *b = n->back;
    n->size = want;
    unsigned long off = want + 8;
    left -= want;
    *(Node **)((char *)n + off) = b;
    size = (unsigned long)((char *)n + off);
    left |= 5;
    ((Node *)size)->size = left;
    h->pending = (Node *)size;
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
    unsigned long o = (s << 2) + 28;
    Node **slot = (Node **)((char *)o + (unsigned long)h);
    do {
     n = *slot;
     if (n) {
      if (n->size != 8 && n->self == n) {
       size = (unsigned long)n->next;
       if (size) ((Node *)size)->prev = n->prev;
       size = (unsigned long)n->prev;
       if (size) ((Node *)size)->next = n->next;
       else *slot = n->next;
      } else fn_80213d90(h, n->size, n);
      ((Node *)((char *)n->size + (unsigned long)n + 8))->size &= ~2UL;
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
   unsigned long t = h->flags;
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
 ((Node *)((char *)n->size + (unsigned long)n + 8))->size &= ~2UL;
 s = n->size - want;
 if (s > 15) {
  n->size = want;
  unsigned long off = want + 8;
  Node *b = n->back;
  *(Node **)((char *)n + off) = b;
  size = (unsigned long)((char *)n + off);
  ((Node *)size)->size = (s - 8) | 5;
  if (!h->root || (char *)((Node *)size)->size + size + 16 < h->blocks->high) h->pending = (Node *)size;
  else {
   unsigned long t = ((Node *)size)->size & ~7UL;
   ((Node *)size)->size = t;
   *(Node **)((char *)t + size + 4) = (Node *)size;
   ((Node *)((char *)((Node *)size)->size + size + 8))->size |= 2;
   h->top = (Node *)size;
  }
 }
 n->size = n->size | 1;
mark:
 {
  char *p = (char *)n + 8;
  if (!guard) {
   unsigned long t = h->flags;
   if ((t & 2) && lbl_8040077c[0] && (t & 0x7c0) == 64) lbl_8040077c[0](self, 0, p, asked);
  }
  if (!guard) h->flags &= ~8192UL;
  return p;
 }
}
