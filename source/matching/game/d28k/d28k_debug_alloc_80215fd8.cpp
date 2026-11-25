// Debug heap allocation (Worms 3D GameCube PAL, 0x80215fd8).
// Takes the pending file and line from the arena, refuses re-entry (flag 8192, error
// through 0x8021573c), optionally checks the heap, allocates with a 32-byte overhead
// through the allocator table, tags the block (0x80215c58), calls the watch hook and
// logs when tracing is on. Names are inferred from the callers and guard use.

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
extern "C" char *w3d_d28k_debug_alloc_80215fd8(Arena *self, unsigned long size) {
 const char *file = self->file;
 int line = self->line;
 Heap *h = self->heap;
 self->file = 0;
 self->line = 0;
 unsigned long flags = h->flags;
 if (flags & 8192) {
  fn_8021573c(self, 0, 0, file, line, 1);
  return 0;
 }
 flags |= 8192;
 h->flags = flags;
 if (flags & 4) fn_80216638(self);
 unsigned long total = ((size + 7) & ~7UL) + 32;
 if (total <= 15) total = 16;
 self->heap->flags |= 16384;
 char *p = (char *)lbl_804aba74->alloc(self, total);
 if (!p) fn_8021573c(self, 0, 1, file, line, 1);
 else {
  p += 16;
  fn_80215c58(p, size, file, line);
  if ((h->flags & 2) && lbl_80400768[0].watch) {
   self->file = file;
   self->line = line;
   lbl_80400768[0].watch(self, 0, p, size);
  }
  if (lbl_804b06c4 > 0) fn_80215be4(self, p, file, line, 1);
 }
 h->flags &= ~8192UL;
 return p;
}
