// GWMP8P rev0 0x80213f98. Reclaims delayed free blocks: merges each cached
// junk block with its neighbours, then files it on the tiny lists or the
// free tree. Shape agrees with AT&T Vmalloc bestreclaim as recalled; no
// upstream text is copied.
struct Node { Node *back; unsigned long size; Node *next; Node *prev; Node *self; };
struct Block { int a; Block *next; char *low; int b; char *high; };
struct Heap { int a,b,c; Block *blocks; Node *pending; Node *top; Node *root; Node *small[15]; };
extern "C" Node *fn_80213d90(Heap *, unsigned long, Node *);
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
#define UNLINK(h, p, s) \
 if ((s) != 8 && (p)->self == (p)) { \
  a = (p)->next; \
  if (a) a->prev = (p)->prev; \
  a = (p)->prev; \
  if (a) a->next = (p)->next; \
  else (h)->small[((s) - 8) >> 3] = (p)->next; \
 } else fn_80213d90((h), (p)->size, (p));
extern "C" int w3d_d46k_heap_reclaim_80213f98(Heap *h, Node *keep, int low) {
 Node *n = h->pending, *nx, *a, *rest;
 unsigned long sz, ns;
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
  rest = *(Node **)((char *)h + off);
  *(Node **)((char *)h + off) = 0;
  while ((n = rest)) {
   rest = n->next;
   count++;
   sz = n->size;
   if (sz & 4) {
    if (sz & 2) {
     n = ((Node **)n)[-1];
     ns = n->size;
     UNLINK(h, n, ns);
     sz = (sz & ~7UL) + ns + 8;
    } else sz &= ~7UL;
    for (;;) {
     nx = (Node *)((char *)n + sz + 8);
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
     *(Node **)((char *)n->size + (unsigned long)n + 4) = n;
     if ((char *)nx + 8 >= h->blocks->high) h->top = n;
     else if (sz <= 63) {
      ns = (sz - 8) >> 3;
      nx = n->next = h->small[ns];
      if (ns == 0) {
       if (nx) nx->back = n;
       n->back = (Node *)ns;
      } else {
       if (nx) nx->prev = n;
       n->prev = 0;
       n->self = n;
      }
      h->small[ns] = n;
     } else {
      nx = &big;
      Node *o = nx->next;
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
