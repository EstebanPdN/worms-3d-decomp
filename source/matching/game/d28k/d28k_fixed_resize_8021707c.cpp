// Fixed-size pool resize (Worms 3D GameCube PAL, 0x8021707c).
// A null block allocates through 0x80216c4c and clears it when mode bit 4 is set; size
// zero frees through 0x80216f5c. Otherwise only the pool's own fixed size is accepted:
// the block is checked (0x80216e7c), a failure goes to the arena's error hook with code 3,
// and the realloc hook (0x8040077c) is notified. Field names are inferred from use.

struct Heap { unsigned long flags; int b; unsigned long fixed; };
struct Hooks { int a; void (*fail)(void *, int, void *, Hooks *); };
struct Arena { char pad[44]; Hooks *hooks; Heap *heap; };
extern "C" void *fn_80216c4c(Arena *, unsigned long);
extern "C" int fn_80216f5c(Arena *, void *);
extern "C" int fn_80216e7c(Arena *, void *);
extern "C" void (*lbl_8040077c[])(Arena *, void *, void *, unsigned long);
extern "C" void *w3d_d28k_fixed_resize_8021707c(Arena *self, void *mem, unsigned long size, int mode) {
 Heap *h = self->heap;
 if (!mem) {
  mem = fn_80216c4c(self, size);
  if (mem && (mode & 4)) {
   char *end = (char *)mem + size;
   int *q = (int *)mem;
   do { *q++ = 0; } while ((char *)q < end);
  }
 } else {
  if (size == 0) {
   fn_80216f5c(self, mem);
  fail:
   return 0;
  }
  unsigned long flags = h->flags;
  if ((flags & 1) == 0) {
   if (flags & 8192) goto fail;
   if (size == h->fixed) {
    h->flags = flags | 16384;
    if (fn_80216e7c(self, mem) == 0) goto ok;
   }
   {
    Hooks *k = self->hooks;
    if (k->fail) k->fail(self, 3, mem, k);
   }
   goto fail;
  ok:
   if ((h->flags & 2) && lbl_8040077c[0]) lbl_8040077c[0](self, mem, mem, size);
  }
 }
 return mem;
}
