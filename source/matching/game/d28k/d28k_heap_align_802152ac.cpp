// Heap aligned allocation (Vmalloc bestalign shape; Worms 3D GameCube PAL, 0x802152ac).
// Alignments up to 8 use plain allocation. Otherwise rounds the size and alignment, reserves
// room for debug headers in debug mode, allocates extra, frees the unaligned left part and
// any large tail into the junk cache, consolidates and notifies the watch hook.

struct Node { Node *back; unsigned long size; Node *next; };
struct Heap { unsigned long flags; int b,c,d,e,f,g; Node *small[7]; Node *fresh[8]; };
struct Arena { char pad[48]; Heap *heap; };
extern "C" char *fn_80214344(Arena *, unsigned long);
extern "C" int fn_80213f98(Heap *, Node *, int);
extern "C" void (*lbl_8040077c[])(Arena *, void *, void *, unsigned long);
#define BIN(s) ((s) <= 63 ? ((s) - 8) >> 3 : 7)
extern "C" char *w3d_d28k_heap_align_802152ac(Arena *vm, unsigned long size, unsigned long align) {
 Heap *vd = vm->heap;
 char *data;
 Node *tp, *np;
 Node *seg;
 unsigned long local, s, extra, want, orgsize;
 if (size == 0 || align == 0) return 0;
 if (align <= 8) return fn_80214344(vm, size);
 local = vd->flags & 1;
 if (!local) {
  unsigned long t = vd->flags & ~16384UL;
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
  unsigned long z = extra + 8;
  unsigned long t = want + 2 * (align + z);
  vm->heap->flags |= 16384;
  data = fn_80214344(vm, t);
 }
 if (!data) goto done;
 tp = (Node *)(data - 8);
 seg = tp->back;
 if ((s = ((unsigned long)data + extra) % align) != 0) data += align - s;
 np = (Node *)(data - 8);
 if (np != tp) {
  if ((long)((char *)np - (char *)tp) < (long)(24 + extra)) {
   data += align - extra;
   np = (Node *)(data - 8);
  }
  s = (char *)np - (char *)tp;
  np->size = ((tp->size & ~7UL) - s) | 1;
  np->back = seg;
  tp->size = (s - 8) | (tp->size & 7) | 4;
  tp->next = vd->fresh[BIN(tp->size)];
  vd->fresh[BIN(tp->size)] = tp;
 }
 if ((s = np->size - want) > 23) {
  unsigned long off = want + 8;
  np->size = want;
  tp = (Node *)((char *)np + off);
  tp->size = ((s & ~7UL) - 8) | 5;
  *(Node **)((char *)np + off) = seg;
  tp->next = vd->fresh[BIN(tp->size)];
  vd->fresh[BIN(tp->size)] = tp;
  np->size |= s & 7;
 }
 fn_80213f98(vd, 0, 0);
 if (!local) {
  unsigned long t = vd->flags;
  if ((t & 1) == 0 && lbl_8040077c[0] && (t & 1986) == 66) lbl_8040077c[0](vm, 0, data, orgsize);
 }
done:
 if (!local) vd->flags &= ~8192UL;
 return data;
}
