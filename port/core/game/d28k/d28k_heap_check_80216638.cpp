#include "w3d_ptr.h"
#line 1 "d28k_heap_check_80216638.cpp"
// Debug heap check (Worms 3D GameCube PAL, 0x80216638).
// Returns -1 unless the heap has checks enabled (flag 512). Walks every chunk of every
// block; for an in-use chunk it counts a non-positive tail counter as bad, then scans the
// guard bytes (value 173) before and after the payload. A damaged guard is reported
// through 0x8021573c, the tail counter is negated and the chunk counts as bad.

struct Node { Ptr32<Node> back; unsigned int size; };
struct Hdr { char pad[20]; char guard[4]; };
struct Block { int a; Ptr32<Block> next; int c; int d; Ptr32<char> high; };
struct Heap { unsigned int flags; int b,c; Ptr32<Block> blocks; };
struct Arena { char pad[48]; Ptr32<Heap> heap; };
extern "C" int fn_8021573c(Ptr32<Arena>, Ptr32<char>, int, Ptr32<void>, int, int);
#define TAIL(u) ((char *)w3d::AG(*(unsigned long *)w3d::AG((u) - 20) & ~7UL) + (unsigned long)w3d::AI(u))
extern "C" int w3d_d28k_heap_check_80216638(Ptr32<Arena> self) {
 Ptr32<Heap> h = self->heap;
 if ((h->flags & 512) == 0) return -1;
 int bad = 0;
 Ptr32<Block> b = h->blocks;
 while (b) {
  Ptr32<char> end = b->high - 8;
  Ptr32<Node> p = (Ptr32<Node>)((Ptr32<char>)b + 32);
  while ((Ptr32<char>)p < end) {
   if ((p->size & 5) == 1) {
    Ptr32<char> user = (Ptr32<char>)p + 24;
    if (*(Ptr32<int>)(TAIL(user) - 20) <= 0) bad++;
    else {
     Ptr32<char> c = ((Ptr32<Hdr>)p)->guard; Ptr32<char> lim;
     Ptr32<int> q;
     for (; c < user; c++) if (*(Ptr32<unsigned char>)c != 173) goto corrupt;
     lim = TAIL(user) - 20;
     c = user + *(Ptr32<int>)(user - 12);
     if (c < lim) do {
      if (*(Ptr32<unsigned char>)c != 173) {
      corrupt:
       fn_8021573c(self, user, c - user, 0, 0, 0);
       q = (Ptr32<int>)(TAIL(user) - 24);
       if (q[1] > 0) q[1] = -q[1];
       bad++;
       break;
      }
      c++;
     } while (c < lim);
    }
   }
   p = (Ptr32<Node>)((Ptr32<char>)p + ((p->size & ~7UL) + 8));
  }
  b = b->next;
 }
 return bad;
}


