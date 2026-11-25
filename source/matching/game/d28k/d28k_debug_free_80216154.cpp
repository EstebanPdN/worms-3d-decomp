// Debug heap free (Worms 3D GameCube PAL, 0x80216154).
// Takes the pending file and line, returns 0 for a null block, refuses re-entry, optionally
// checks the heap and validates the block (0x80215e10); a bad block goes to the error
// hook and 0x8021573c and returns -1. Otherwise logs, calls the watch hook, clears the
// payload words and returns the result of the allocator's release slot.

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
extern "C" int w3d_d28k_debug_free_80216154(Arena *self, char *mem) {
 const char *file = self->file;
 int line = self->line;
 Heap *h = self->heap;
 self->file = 0;
 self->line = 0;
 if (!mem) return 0;
 unsigned long flags = h->flags;
 if (flags & 8192) {
  fn_8021573c(self, 0, 0, file, line, 2);
  return -1;
 }
 flags |= 8192;
 h->flags = flags;
 if (flags & 4) fn_80216638(self);
 self->heap->flags |= 16384;
 int bad = fn_80215e10(self, mem);
 if (bad) {
  Hooks *k = self->hooks;
  if (k->fail) k->fail(self, 3, mem, k);
  fn_8021573c(self, mem, bad == -1 ? 0 : 1, file, line, 2);
  h->flags &= ~8192UL;
  return -1;
 }
 if (lbl_804b06c4 > 0) fn_80215be4(self, mem, file, line, 2);
 if ((h->flags & 2) && lbl_80400768[0].watch) {
  self->file = file;
  self->line = line;
  lbl_80400768[0].watch(self, mem, 0, *(unsigned long *)(mem - 12));
 }
 char *q = mem;
 char *base = q - 16;
 char *end = q + ((*(unsigned long *)(q - 12) + 3) & ~3UL);
 for (; q < end; q += 4) *(int *)q = 0;
 h->flags &= ~8192UL;
 return lbl_804aba74->release(self, base);
}
