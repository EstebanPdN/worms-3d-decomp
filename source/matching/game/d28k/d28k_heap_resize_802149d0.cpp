// Heap resize (Vmalloc bestresize shape; Worms 3D GameCube PAL, 0x802149d0).
// Null block allocates and size zero frees. Otherwise merges forward over free, junk and top
// chunks, extends a wild segment through the discipline's memory hook when needed, splits
// a spare tail, or allocates, copies (the word switch or memcpy) and caches the old chunk as
// junk. Notifies the watch hook and zeroes grown bytes on request.

struct Node { Node *back; unsigned long size; Node *next; Node *prev; Node *self; };
struct Seg { int a,b; void *addr; unsigned long extent; char *high; unsigned long size; };
struct Disc;
struct Heap { unsigned long flags; unsigned long incr; int c; int d; Node *pending; Node *top; Node *root; Node *small[15]; };
struct Arena { char pad[44]; Disc *disc; Heap *heap; };
struct Disc { void *(*memory)(Arena *, void *, unsigned long, unsigned long, Disc *); };
extern "C" char *fn_80214344(Arena *, unsigned long);
extern "C" int fn_80214894(Arena *, void *);
extern "C" int fn_80214718(Arena *, void *);
extern "C" int fn_80213f98(Heap *, Node *, int);
extern "C" Node *fn_80213d90(Heap *, unsigned long, Node *);
extern "C" void *fn_802eee50(...);
extern "C" void *fn_802eefe0(void *, int, unsigned long);
extern "C" void (*lbl_8040077c[])(Arena *, void *, void *, unsigned long);
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
extern "C" char *w3d_d28k_heap_resize_802149d0(Arena *self, char *data, unsigned long size, int type) {
 Heap *h = self->heap;
 Node *rp, *np, *t;
 unsigned long oldsize, bits, s, want, local, orgsize;
 char *orgdata;
 int *d, *oldd;
 if (!data) {
  data = fn_80214344(self, size);
  oldsize = 0;
  goto done;
 }
 if (size == 0) {
  fn_80214894(self, data);
 none:
  return 0;
 }
 {
  unsigned long m = h->flags;
  local = m & 1;
  if (!local) {
   local = m & 16384;
   h->flags = m & ~16384UL;
   if (!local) {
    if (m & 8192) goto none;
    self->heap->flags |= 16384;
    if (fn_80214718(self, data)) goto none;
    h->flags |= 8192;
   }
   orgdata = data;
   orgsize = size;
  }
 }
 want = size <= 8 ? 8 : (size + 7) & ~7UL;
 size = want;
 rp = (Node *)(data - 8);
 oldsize = bits = rp->size;
 if (oldsize < size) {
  {
   unsigned long c = oldsize & ~7UL;
   rp->size = c;
   np = (Node *)((char *)rp + (rp->size + 8));
  }
  do {
   s = np->size;
   if (np == h->pending) {
    h->pending = 0;
    s &= ~7UL;
   } else if (s & 4) {
    rp->size |= bits & 7;
    fn_80213f98(h, np, BIN(s));
    bits = rp->size;
    s = np->size;
    rp->size = bits & ~7UL;
   } else if ((s & 1) == 0) {
    if (np == h->top) h->top = 0;
    else if (s != 8 && np->self == np) {
     t = np->next;
     if (t) t->prev = np->prev;
     t = np->prev;
     if (t) t->next = np->next;
     else h->small[(s - 8) >> 3] = np->next;
    } else fn_80213d90(h, np->size, np);
   } else break;
   rp->size += (s += 8);
   np = (Node *)((char *)np + s);
   np->size &= ~2UL;
  } while (rp->size < want);
  if (rp->size < want && want > h->incr) {
   if ((char *)rp->size + (unsigned long)rp + 16 >= ((Seg *)rp->back)->high) {
    unsigned long y = h->incr, x = want - rp->size, m = y - 1;
    if (y & m) { unsigned long z = x + 7; s = (z + y) / y * y; }
    else { unsigned long z = x + 7; s = (z + y) & ~m; }
    Seg *seg = (Seg *)rp->back;
    Disc *disc = self->disc;
    if (disc->memory(self, seg->addr, seg->extent, seg->extent + s, disc) == seg->addr) {
     rp->size += s;
     seg->extent += s;
     seg->size += s;
     seg->high += s;
     ((Node *)((char *)rp->size + (unsigned long)rp + 8))->back = (Node *)seg;
     ((Node *)((char *)rp->size + (unsigned long)rp + 8))->size = 1;
    }
   }
  }
  rp->size |= bits & 7;
 }
 bits = want < 32 ? want : want < 1024 ? want >> 1 : 1024;
 s = rp->size;
 if (s >= want + bits + 16) {
  {
   unsigned long left = (s & ~7UL) - want - 8;
   Node *b = rp->back;
   rp->size = want;
   unsigned long off = want + 8;
   *(Node **)((char *)rp + off) = b;
   np = (Node *)((char *)rp + off);
   np->size = left | 5;
  }
  rp->size |= s & 7;
  rp = np;
  goto do_free;
 } else if (s < want) {
  if (!(type & 3)) data = 0;
  else {
   oldd = (int *)data;
   {
    unsigned long c = (s & ~7UL) + bits;
    if (want < c) size = c;
   }
   self->heap->flags |= 16384;
   data = fn_80214344(self, size);
   if (data) {
    if (type & 1) {
     d = (int *)data;
     switch (s / 4) {
      default: fn_802eee50(d, oldd, s); break;
      case 7: *d++ = *oldd++;
      case 6: *d++ = *oldd++;
      case 5: *d++ = *oldd++;
      case 4: *d++ = *oldd++;
      case 3: *d++ = *oldd++;
      case 2: *d++ = *oldd++;
      case 1: *d++ = *oldd++;
     }
    }
   do_free:
    rp->size |= 4;
    rp->next = h->small[14];
    h->small[14] = rp;
    rp = h->pending;
    if (rp) {
     h->pending = 0;
     rp->next = h->small[14];
     h->small[14] = rp;
    }
   }
  }
 }
 if (!local && lbl_8040077c[0] && data && (h->flags & 1986) == 66) lbl_8040077c[0](self, orgdata, data, orgsize);
 if (!local) h->flags &= ~8192UL;
done:
 if (data && (type & 4) && size > (oldsize &= ~7UL)) {
  size -= oldsize;
  d = (int *)(data + oldsize);
  switch (size / 4) {
   default: fn_802eefe0(d, 0, size); break;
   case 7: *d++ = 0;
   case 6: *d++ = 0;
   case 5: *d++ = 0;
   case 4: *d++ = 0;
   case 3: *d++ = 0;
   case 2: *d++ = 0;
   case 1: *d++ = 0;
  }
 }
 return data;
}
