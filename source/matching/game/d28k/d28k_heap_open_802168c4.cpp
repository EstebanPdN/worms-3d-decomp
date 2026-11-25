// Heap region open (Vmalloc vmopen shape; Worms 3D GameCube PAL, 0x802168c4).
// Allocates the handle from the heap region, copies the method, asks the discipline's exception
// hook about shared regions, rounds the increment, gets memory for the region data, aligns it,
// builds the region, first segment and first free block, and links the region into the list.

struct Vmalloc;
struct Seg { Vmalloc *vm; Seg *next; char *addr; unsigned long extent; char *baddr; unsigned long size; void *free; int pad; void *seg0; };
struct Block { void *seg; unsigned long size; };
struct Vmdata { unsigned long mode; unsigned long incr; unsigned long pool; Seg *seg; void *free; void *wild; void *root; void *tiny[7]; void *cache[8]; };
struct Vmdisc;
typedef void *(*Memory)(Vmalloc *, void *, unsigned long, unsigned long, Vmdisc *);
struct Vmdisc { Memory memoryf; int (*exceptf)(Vmalloc *, int, void *, Vmdisc *); unsigned long round; };
struct Method { Vmalloc *(*allocf)(Vmalloc *, unsigned long); int b; void (*freef)(Vmalloc *, void *); int c,d,e,f; unsigned short meth; unsigned short g; };
struct Vmalloc { Method meth; const char *file; int line; int func; Vmdisc *disc; Vmdata *data; Vmalloc *next; };
extern "C" Vmalloc *lbl_804aba6c;
extern "C" unsigned long lbl_80400770[];
#define ROUND(x,y) (((y) & ((y) - 1)) ? (((x) - 1 + (y)) / (y)) * (y) : ((x) - 1 + (y)) & ~((y) - 1))
#define MULTIPLE(x,y) ((x) % (y) == 0 ? (x) : (y) % (x) == 0 ? (y) : (y) * (x))
extern "C" Vmalloc *w3d_d28k_heap_open_802168c4(Vmdisc *disc, Method *meth, int mode) {
 Vmalloc *vm;
 Vmdata *vd;
 unsigned long s, a, incr;
 Block *b;
 Seg *seg;
 char *addr;
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
   if ((a = (unsigned long)addr % 8) != 0) addr += 8 - a;
   vd = (Vmdata *)addr;
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
 if (!(addr = (char *)memoryf(vm, 0, 0, s, disc))) {
  lbl_804aba6c->meth.freef(lbl_804aba6c, vm);
  return 0;
 }
 if ((a = (unsigned long)addr % 8) != 0) addr += 8 - a;
 vd = (Vmdata *)addr;
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
 vd->seg = (Seg *)(addr + ((incr + 7) & ~7UL));
 seg = vd->seg;
 seg->next = 0;
 seg->vm = vm;
 {
  char *p;
  if (a) { p = addr - 8; p += a; }
  else p = addr;
  seg->addr = p;
 }
 seg->extent = s;
 seg->baddr = addr + s;
 if (a) seg->baddr -= 8;
 seg->size = s;
 seg->free = 0;
 b = (Block *)((char *)seg + 32);
 b->seg = seg;
 b->size = seg->baddr - (char *)b - 16;
 *(Block **)((char *)b->size + (unsigned long)b + 4) = b;
 ((Block *)((char *)b->size + (unsigned long)b + 8))->seg = seg;
 ((Block *)((char *)b->size + (unsigned long)b + 8))->size = 3;
 if (vd->mode & 384) seg->free = b;
 else vd->wild = b;
 vm->data = vd;
 vm->next = lbl_804aba6c->next;
 lbl_804aba6c->next = vm;
 return vm;
}
