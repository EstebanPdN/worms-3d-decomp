// Debug heap reallocation (Worms 3D GameCube PAL, 0x80216330).
// Null block allocates (0x80215fd8), size zero frees (0x80216154). Otherwise follows the
// debug free checks, saves the old tag, resizes through the allocator table with mode bit
// 4 masked, restores the old tag on failure or writes a new one on success, then clears
// the grown bytes when mode bit 4 is set.

struct Heap { unsigned long flags; };
struct Hooks { int a; void (*fail)(void *, int, void *, Hooks *); };
struct Arena { char pad[36]; const char *file; int line; Hooks *hooks; Heap *heap; };
struct Alloc { void *(*alloc)(Arena *, unsigned long); void *(*resize)(Arena *, void *, unsigned long, unsigned long); int (*release)(Arena *, void *); };
struct Table { void *slot[3]; void *copy; void *b; void (*watch)(Arena *, void *, void *, unsigned long); };
extern "C" Table lbl_80400768[];
extern "C" Alloc *lbl_804aba74;
extern "C" int lbl_804b06c4;
extern "C" void fn_8021573c(Arena *, void *, int, const char *, int, int);
extern "C" void fn_80215be4(Arena *, void *, const char *, int, int);
extern "C" void fn_80215c58(char *, unsigned long, const char *, int);
extern "C" int fn_80216638(Arena *);
extern "C" int fn_80215e10(Arena *, void *);
extern "C" int abs(int);
extern "C" char *fn_80215fd8(Arena *, unsigned long);
extern "C" int fn_80216154(Arena *, char *);
extern "C" char *w3d_d28k_debug_resize_80216330(Arena *self, char *mem, unsigned long size, unsigned long mode) {
 Heap *h = self->heap;
 char *p;
 unsigned long old;
 if (!mem) {
  p = fn_80215fd8(self, size);
  old = 0;
 } else {
  if (size == 0) {
   fn_80216154(self, mem);
   return 0;
  }
  const char *file = self->file;
  int line = self->line;
  self->file = 0;
  self->line = 0;
  unsigned long flags = h->flags;
  if (flags & 8192) {
   fn_8021573c(self, 0, 0, file, line, 3);
   return 0;
  }
  flags |= 8192;
 h->flags = flags;
  if (flags & 4) fn_80216638(self);
  self->heap->flags |= 16384;
  p = (char *)fn_80215e10(self, mem);
  if (p) {
   Hooks *k = self->hooks;
   if (k->fail) k->fail(self, 3, mem, k);
   fn_8021573c(self, mem, p == (char *)-1 ? 0 : 1, file, line, 3);
   h->flags &= ~8192UL;
   return 0;
  }
  if (lbl_804b06c4 > 0) fn_80215be4(self, mem, file, line, 3);
  p = mem - 16;
  old = *(unsigned long *)(mem - 12);
  const char *ofile = *(const char **)(mem - 16);
  int oline = abs(*(int *)((char *)(*(unsigned long *)(mem - 20) & ~7UL) + (unsigned long)mem - 20));
  unsigned long total = ((size + 7) & ~7UL) + 32;
  if (total <= 15) total = 16;
  self->heap->flags |= 16384;
  p = (char *)lbl_804aba74->resize(self, p, total, mode & ~4UL);
  if (!p) {
   fn_8021573c(self, 0, 1, file, line, 3);
   fn_80215c58(mem, old, ofile, oline);
  } else {
   p += 16;
   fn_80215c58(p, size, file, line);
   if ((h->flags & 2) && lbl_80400768[0].watch) {
    self->file = file;
    self->line = line;
    lbl_80400768[0].watch(self, mem, p, size);
   }
   if (lbl_804b06c4 > 0) fn_80215be4(self, p, file, line, 5);
  }
  h->flags &= ~8192UL;
 }
 if (p && (mode & 4) && size > old) {
  char *q = p + old, *e = p + size;
  do { *q++ = 0; } while (q < e);
 }
 return p;
}
