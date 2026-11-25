#include "w3d_ptr.h"
#line 1 "d28k_heap_resize_802149d0.cpp"
// Heap resize (Vmalloc bestresize shape; Worms 3D GameCube PAL, 0x802149d0).
// Null block allocates and size zero frees. Otherwise merges forward over free, junk and top
// chunks, extends a wild segment through the discipline's memory hook when needed, splits
// a spare tail, or allocates, copies (the word switch or memcpy) and caches the old chunk as
// junk. Notifies the watch hook and zeroes grown bytes on request.

struct Node { Ptr32<Node> back; unsigned int size; Ptr32<Node> next; Ptr32<Node> prev; Ptr32<Node> self; };
struct Seg { int a,b; Ptr32<void> addr; unsigned int extent; Ptr32<char> high; unsigned int size; };
struct Disc;
struct Heap { unsigned int flags; unsigned int incr; int c; int d; Ptr32<Node> pending; Ptr32<Node> top; Ptr32<Node> root; Ptr32<Node> small[15]; };
struct Arena { char pad[44]; Ptr32<Disc> disc; Ptr32<Heap> heap; };
struct Disc { Ptr32<Ptr32<void> (Ptr32<Arena>, Ptr32<void>, unsigned int, unsigned int, Ptr32<Disc>)> memory; };
extern "C" Ptr32<char> fn_80214344(Ptr32<Arena>, unsigned int);
extern "C" int fn_80214894(Ptr32<Arena>, Ptr32<void>);
extern "C" int fn_80214718(Ptr32<Arena>, Ptr32<void>);
extern "C" int fn_80213f98(Ptr32<Heap>, Ptr32<Node>, int);
extern "C" Ptr32<Node> fn_80213d90(Ptr32<Heap>, unsigned int, Ptr32<Node>);
extern "C" Ptr32<void> fn_802eee50(...);
extern "C" Ptr32<void> fn_802eefe0(Ptr32<void>, int, unsigned int);
extern "C" Ptr32<void (Ptr32<Arena>, Ptr32<void>, Ptr32<void>, unsigned int)> lbl_8040077c[];
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
extern "C" Ptr32<char> w3d_d28k_heap_resize_802149d0(Ptr32<Arena> self, Ptr32<char> data, unsigned int size, int type) {
 Ptr32<Heap> h = self->heap;
 Ptr32<Node> rp; Ptr32<Node> np; Ptr32<Node> t;
 unsigned int oldsize; unsigned int bits; unsigned int s; unsigned int want; unsigned int local; unsigned int orgsize;
 Ptr32<char> orgdata;
 Ptr32<int> d; Ptr32<int> oldd;
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
  unsigned int m = h->flags;
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
 rp = (Ptr32<Node>)(data - 8);
 oldsize = bits = rp->size;
 if (oldsize < size) {
  {
   unsigned int c = oldsize & ~7UL;
   rp->size = c;
   np = (Ptr32<Node>)((Ptr32<char>)rp + (rp->size + 8));
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
   np = (Ptr32<Node>)((Ptr32<char>)np + s);
   np->size &= ~2UL;
  } while (rp->size < want);
  if (rp->size < want && want > h->incr) {
   if ((Ptr32<char>)w3d::G(rp->size) + (unsigned int)w3d::H(rp) + 16 >= ((Ptr32<Seg>)rp->back)->high) {
    unsigned int y = h->incr; unsigned int x = want - rp->size; unsigned int m = y - 1;
    if (y & m) { unsigned int z = x + 7; s = (z + y) / y * y; }
    else { unsigned int z = x + 7; s = (z + y) & ~m; }
    Ptr32<Seg> seg = (Ptr32<Seg>)rp->back;
    Ptr32<Disc> disc = self->disc;
    if (disc->memory(self, seg->addr, seg->extent, seg->extent + s, disc) == seg->addr) {
     rp->size += s;
     seg->extent += s;
     seg->size += s;
     seg->high += s;
     ((Ptr32<Node>)((Ptr32<char>)w3d::G(rp->size) + (unsigned int)w3d::H(rp) + 8))->back = (Ptr32<Node>)seg;
     ((Ptr32<Node>)((Ptr32<char>)w3d::G(rp->size) + (unsigned int)w3d::H(rp) + 8))->size = 1;
    }
   }
  }
  rp->size |= bits & 7;
 }
 bits = want < 32 ? want : want < 1024 ? want >> 1 : 1024;
 s = rp->size;
 if (s >= want + bits + 16) {
  {
   unsigned int left = (s & ~7UL) - want - 8;
   Ptr32<Node> b = rp->back;
   rp->size = want;
   unsigned int off = want + 8;
   *(Ptr32<Ptr32<Node>>)((Ptr32<char>)rp + off) = b;
   np = (Ptr32<Node>)((Ptr32<char>)rp + off);
   np->size = left | 5;
  }
  rp->size |= s & 7;
  rp = np;
  goto do_free;
 } else if (s < want) {
  if (!(type & 3)) data = 0;
  else {
   oldd = (Ptr32<int>)data;
   {
    unsigned int c = (s & ~7UL) + bits;
    if (want < c) size = c;
   }
   self->heap->flags |= 16384;
   data = fn_80214344(self, size);
   if (data) {
    if (type & 1) {
     d = (Ptr32<int>)data;
     switch (s / 4) {
      default: fn_802eee50(w3d::VA(d), w3d::VA(oldd), s); break;
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
  d = (Ptr32<int>)(data + oldsize);
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


