#include "w3d_ptr.h"
#line 1 "d46k_heap_reclaim_80213f98.cpp"
// GWMP8P rev0 0x80213f98. Reclaims delayed free blocks: merges each cached
// junk block with its neighbours, then files it on the tiny lists or the
// free tree. Shape agrees with AT&T Vmalloc bestreclaim as recalled; no
// upstream text is copied.
struct Node { Ptr32<Node> back; unsigned int size; Ptr32<Node> next; Ptr32<Node> prev; Ptr32<Node> self; };
struct Block { int a; Ptr32<Block> next; Ptr32<char> low; int b; Ptr32<char> high; };
struct Heap { int a,b,c; Ptr32<Block> blocks; Ptr32<Node> pending; Ptr32<Node> top; Ptr32<Node> root; Ptr32<Node> small[15]; };
extern "C" Ptr32<Node> fn_80213d90(Ptr32<Heap>, unsigned int, Ptr32<Node>);
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
#define UNLINK(h, p, s) \
 if ((s) != 8 && (p)->self == (p)) { \
  a = (p)->next; \
  if (a) a->prev = (p)->prev; \
  a = (p)->prev; \
  if (a) a->next = (p)->next; \
  else (h)->small[((s) - 8) >> 3] = (p)->next; \
 } else fn_80213d90((h), (p)->size, (p));
extern "C" int w3d_d46k_heap_reclaim_80213f98(Ptr32<Heap> h, Ptr32<Node> keep, int low) {
 Ptr32<Node> n = h->pending; Ptr32<Node> nx; Ptr32<Node> a; Ptr32<Node> rest;
 unsigned int sz; unsigned int ns;
 if (n) {
  n->next = h->small[14];
  h->small[14] = n;
  h->pending = 0;
 }
 Node big;
 big.next = 0;
 int count = 0;
 for (int i = 7; i >= low; i--) {
  int off = (i << 2) + 56;
  rest = *(Ptr32<Ptr32<Node>>)((Ptr32<char>)h + off);
  *(Ptr32<Ptr32<Node>>)((Ptr32<char>)h + off) = 0;
  while ((n = rest)) {
   rest = n->next;
   count++;
   sz = n->size;
   if (sz & 4) {
    if (sz & 2) {
     n = ((Ptr32<Ptr32<Node>>)n)[-1];
     ns = n->size;
     UNLINK(h, n, ns);
     sz = (sz & ~7UL) + ns + 8;
    } else sz &= ~7UL;
    for (;;) {
     nx = (Ptr32<Node>)((Ptr32<char>)n + sz + 8);
     ns = nx->size;
     if ((ns & 1) == 0) {
      if (nx == h->top) h->top = 0;
      else { UNLINK(h, nx, ns); }
     } else if (ns & 4) {
      if ((int)BIN(ns) < low) low = BIN(ns);
      nx->size = 0;
      ns &= ~7UL;
     } else break;
     sz += ns + 8;
    }
    n->size = sz;
    if (n != keep) {
     nx->size |= 2;
     *(Ptr32<Ptr32<Node>>)((Ptr32<char>)w3d::G(n->size) + (unsigned int)w3d::H(n) + 4) = n;
     if ((Ptr32<char>)nx + 8 >= h->blocks->high) h->top = n;
     else if (sz <= 63) {
      ns = (sz - 8) >> 3;
      nx = n->next = h->small[ns];
      if (ns == 0) {
       if (nx) nx->back = n;
       n->back = (Ptr32<Node>)w3d::G(ns);
      } else {
       if (nx) nx->prev = n;
       n->prev = 0;
       n->self = n;
      }
      h->small[ns] = n;
     } else {
      nx = &big;
      Ptr32<Node> o = nx->next;
      n->next = o;
      if (o) o->prev = n;
      nx->next = n;
      n->prev = nx;
      n->self = n;
     }
    }
   }
  }
 }
 rest = big.next;
 while (rest) {
  n = rest;
  rest = n->next;
  n->next = 0;
  n->self = 0;
  n->prev = 0;
  nx = h->root;
  if (!nx) h->root = n;
  else {
   sz = n->size;
   while (1) {
    ns = nx->size;
    if (ns > sz) {
     a = nx->prev;
     if (a) nx = a;
     else { nx->prev = n; break; }
    } else if (ns < sz) {
     a = nx->self;
     if (a) nx = a;
     else { nx->self = n; break; }
    } else {
     a = nx->next;
     if (a) { n->next = a; a->prev = n; }
     nx->next = n;
     n->prev = nx;
     n->self = n;
     break;
    }
   }
  }

 }
 return count;
}


