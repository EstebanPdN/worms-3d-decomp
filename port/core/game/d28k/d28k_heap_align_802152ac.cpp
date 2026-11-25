#include "w3d_ptr.h"
#line 1 "d28k_heap_align_802152ac.cpp"
// Heap aligned allocation (Vmalloc bestalign shape; Worms 3D GameCube PAL, 0x802152ac).
// Alignments up to 8 use plain allocation. Otherwise rounds the size and alignment, reserves
// room for debug headers in debug mode, allocates extra, frees the unaligned left part and
// any large tail into the junk cache, consolidates and notifies the watch hook.

struct Node { Ptr32<Node> back; unsigned int size; Ptr32<Node> next; };
struct Heap { unsigned int flags; int b,c,d,e,f,g; Ptr32<Node> small[7]; Ptr32<Node> fresh[8]; };
struct Arena { char pad[48]; Ptr32<Heap> heap; };
extern "C" Ptr32<char> fn_80214344(Ptr32<Arena>, unsigned int);
extern "C" int fn_80213f98(Ptr32<Heap>, Ptr32<Node>, int);
extern "C" Ptr32<void (Ptr32<Arena>, Ptr32<void>, Ptr32<void>, unsigned int)> lbl_8040077c[];
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
extern "C" Ptr32<char> w3d_d28k_heap_align_802152ac(Ptr32<Arena> vm, unsigned int size, unsigned int align) {
 Ptr32<Heap> vd = vm->heap;
 Ptr32<char> data;
 Ptr32<Node> tp; Ptr32<Node> np;
 Ptr32<Node> seg;
 unsigned int local; unsigned int s; unsigned int extra; unsigned int want; unsigned int orgsize;
 if (size == 0 || align == 0) return 0;
 if (align <= 8) return fn_80214344(vm, size);
 local = vd->flags & 1;
 if (!local) {
  unsigned int t = vd->flags & ~16384UL;
  local = vd->flags & 16384;
  vd->flags = t;
  if (!local) {
   if (vd->flags & 8192) return 0;
   vd->flags = t | 8192;
  }
  orgsize = size;
 }
 want = size <= 8 ? 8 : (size + 7) & ~7UL;
 align = (align & 7) == 0 ? align : 8 / align * align == 8 ? 8 : align * 8;
 extra = 0;
 if ((vd->flags & 0x7c0) == 512) {
  extra = 16;
  while (align - extra < 24) align += align;
 }
 {
  unsigned int z = extra + 8;
  unsigned int t = want + 2 * (align + z);
  vm->heap->flags |= 16384;
  data = fn_80214344(vm, t);
 }
 if (!data) goto done;
 tp = (Ptr32<Node>)(data - 8);
 seg = tp->back;
 if ((s = ((unsigned int)w3d::H(data) + extra) % align) != 0) data += align - s;
 np = (Ptr32<Node>)(data - 8);
 if (np != tp) {
  if ((int)((Ptr32<char>)np - (Ptr32<char>)tp) < (int)(24 + extra)) {
   data += align - extra;
   np = (Ptr32<Node>)(data - 8);
  }
  s = (Ptr32<char>)np - (Ptr32<char>)tp;
  np->size = ((tp->size & ~7UL) - s) | 1;
  np->back = seg;
  tp->size = (s - 8) | (tp->size & 7) | 4;
  tp->next = vd->fresh[BIN(tp->size)];
  vd->fresh[BIN(tp->size)] = tp;
 }
 if ((s = np->size - want) > 23) {
  unsigned int off = want + 8;
  np->size = want;
  tp = (Ptr32<Node>)((Ptr32<char>)np + off);
  tp->size = ((s & ~7UL) - 8) | 5;
  *(Ptr32<Ptr32<Node>>)((Ptr32<char>)np + off) = seg;
  tp->next = vd->fresh[BIN(tp->size)];
  vd->fresh[BIN(tp->size)] = tp;
  np->size |= s & 7;
 }
 fn_80213f98(vd, 0, 0);
 if (!local) {
  unsigned int t = vd->flags;
  if ((t & 1) == 0 && lbl_8040077c[0] && (t & 1986) == 66) lbl_8040077c[0](vm, 0, data, orgsize);
 }
done:
 if (!local) vd->flags &= ~8192UL;
 return data;
}


