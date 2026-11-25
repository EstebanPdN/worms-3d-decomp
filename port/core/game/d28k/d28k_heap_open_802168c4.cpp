#include "w3d_ptr.h"
#line 1 "d28k_heap_open_802168c4.cpp"
// Heap region open (Vmalloc vmopen shape; Worms 3D GameCube PAL, 0x802168c4).
// Allocates the handle from the heap region, copies the method, asks the discipline's exception
// hook about shared regions, rounds the increment, gets memory for the region data, aligns it,
// builds the region, first segment and first free block, and links the region into the list.

struct Vmalloc;
struct Seg { Ptr32<Vmalloc> vm; Ptr32<Seg> next; Ptr32<char> addr; unsigned int extent; Ptr32<char> baddr; unsigned int size; Ptr32<void> free; int pad; Ptr32<void> seg0; };
struct Block { Ptr32<void> seg; unsigned int size; };
struct Vmdata { unsigned int mode; unsigned int incr; unsigned int pool; Ptr32<Seg> seg; Ptr32<void> free; Ptr32<void> wild; Ptr32<void> root; Ptr32<void> tiny[7]; Ptr32<void> cache[8]; };
struct Vmdisc;
typedef Ptr32<Ptr32<void> (Ptr32<Vmalloc>, Ptr32<void>, unsigned int, unsigned int, Ptr32<Vmdisc>)> Memory;
struct Vmdisc { Memory memoryf; Ptr32<int (Ptr32<Vmalloc>, int, Ptr32<void>, Ptr32<Vmdisc>)> exceptf; unsigned int round; };
struct Method { Ptr32<Ptr32<Vmalloc> (Ptr32<Vmalloc>, unsigned int)> allocf; int b; Ptr32<void (Ptr32<Vmalloc>, Ptr32<void>)> freef; int c,d,e,f; unsigned short meth; unsigned short g; };
struct Vmalloc { Method meth; Ptr32<const char> file; int line; int func; Ptr32<Vmdisc> disc; Ptr32<Vmdata> data; Ptr32<Vmalloc> next; };
extern "C" Ptr32<Vmalloc> lbl_804aba6c;
extern "C" unsigned int lbl_80400770[];
#define ROUND(x,y) (((y) & ((y) - 1)) ? (((x) - 1 + (y)) / (y)) * (y) : ((x) - 1 + (y)) & ~((y) - 1))
#define MULTIPLE(x,y) ((x) % (y) == 0 ? (x) : (y) % (x) == 0 ? (y) : (y) * (x))
extern "C" Ptr32<Vmalloc> w3d_d28k_heap_open_802168c4(Ptr32<Vmdisc> disc, Ptr32<Method> meth, int mode) {
 Ptr32<Vmalloc> vm;
 Ptr32<Vmdata> vd;
 unsigned int s; unsigned int a; unsigned int incr;
 Ptr32<Block> b;
 Ptr32<Seg> seg;
 Ptr32<char> addr;
 Memory memoryf;
 int e;
 if (!meth || !disc || !(memoryf = disc->memoryf)) return 0;
 lbl_80400770[0] = 8192;
 if (!(vm = lbl_804aba6c->meth.allocf(lbl_804aba6c, sizeof(Vmalloc)))) return 0;
 vm->meth = *meth;
 vm->disc = disc;
 vm->file = 0;
 vm->line = 0;
 vm->func = 0;
 if (disc->exceptf) {
  addr = 0;
  if ((e = disc->exceptf(vm, 0, &addr, disc)) != 0) {
   if (e < 0 || !addr) goto open_error;
   if ((a = (unsigned int)w3d::H(addr) % 8) != 0) addr += 8 - a;
   vd = (Ptr32<Vmdata>)addr;
   if ((vd->mode & meth->meth) != 0) {
    vm->data = vd;
    return vm;
   } else {
   open_error:
    lbl_804aba6c->meth.freef(lbl_804aba6c, vm);
    return 0;
   }
  }
 }
 incr = disc->round == 0 ? lbl_80400770[0] : disc->round;
 incr = MULTIPLE(incr, 8);
 s = ROUND(172, incr);
 if (!(addr = (Ptr32<char>)memoryf(vm, 0, 0, s, disc))) {
  lbl_804aba6c->meth.freef(lbl_804aba6c, vm);
  return 0;
 }
 if ((a = (unsigned int)w3d::H(addr) % 8) != 0) addr += 8 - a;
 vd = (Ptr32<Vmdata>)addr;
 vd->mode = (mode & 31) | meth->meth;
 vd->incr = incr;
 vd->pool = 0;
 vd->free = vd->wild = 0;
 if (vd->mode & 514) vd->mode &= ~1UL;
 if (vd->mode & 1600) {
  vd->root = 0;
  for (e = 6; e >= 0; --e) vd->tiny[e] = 0;
  for (e = 7; e >= 0; --e) vd->cache[e] = 0;
  incr = sizeof(Vmdata);
 } else incr = 24;
 vd->seg = (Ptr32<Seg>)(addr + ((incr + 7) & ~7UL));
 seg = vd->seg;
 seg->next = 0;
 seg->vm = vm;
 {
  Ptr32<char> p;
  if (a) { p = addr - 8; p += a; }
  else p = addr;
  seg->addr = p;
 }
 seg->extent = s;
 seg->baddr = addr + s;
 if (a) seg->baddr -= 8;
 seg->size = s;
 seg->free = 0;
 b = (Ptr32<Block>)((Ptr32<char>)seg + 32);
 b->seg = seg;
 b->size = seg->baddr - (Ptr32<char>)b - 16;
 *(Ptr32<Ptr32<Block>>)((Ptr32<char>)w3d::G(b->size) + (unsigned int)w3d::H(b) + 4) = b;
 ((Ptr32<Block>)((Ptr32<char>)w3d::G(b->size) + (unsigned int)w3d::H(b) + 8))->seg = seg;
 ((Ptr32<Block>)((Ptr32<char>)w3d::G(b->size) + (unsigned int)w3d::H(b) + 8))->size = 3;
 if (vd->mode & 384) seg->free = b;
 else vd->wild = b;
 vm->data = vd;
 vm->next = lbl_804aba6c->next;
 lbl_804aba6c->next = vm;
 return vm;
}


