#include "w3d_ptr.h"
#line 1 "d28k_debug_alloc_80215fd8.cpp"
// Debug heap allocation (Worms 3D GameCube PAL, 0x80215fd8).
// Takes the pending file and line from the arena, refuses re-entry (flag 8192, error
// through 0x8021573c), optionally checks the heap, allocates with a 32-byte overhead
// through the allocator table, tags the block (0x80215c58), calls the watch hook and
// logs when tracing is on. Names are inferred from the callers and guard use.

struct Heap { unsigned int flags; };
struct Hooks { int a; Ptr32<void (Ptr32<void>, int, Ptr32<void>, Ptr32<Hooks>)> fail; };
struct Arena { char pad[36]; Ptr32<const char> file; int line; Ptr32<Hooks> hooks; Ptr32<Heap> heap; };
struct Alloc { Ptr32<Ptr32<void> (Ptr32<Arena>, unsigned int)> alloc; Ptr32<Ptr32<void> (Ptr32<Arena>, Ptr32<void>, unsigned int, unsigned int)> resize; Ptr32<int (Ptr32<Arena>, Ptr32<void>)> release; };
struct Table { Ptr32<void> slot[3]; Ptr32<void> copy; Ptr32<void> b; Ptr32<void (Ptr32<Arena>, Ptr32<void>, Ptr32<void>, unsigned int)> watch; };
extern "C" Table lbl_80400768[];
extern "C" Ptr32<Alloc> lbl_804aba74;
extern "C" int lbl_804b06c4;
extern "C" void fn_8021573c(Ptr32<Arena>, Ptr32<void>, int, Ptr32<const char>, int, int);
extern "C" void fn_80215be4(Ptr32<Arena>, Ptr32<void>, Ptr32<const char>, int, int);
extern "C" void fn_80215c58(Ptr32<char>, unsigned int, Ptr32<const char>, int);
extern "C" int fn_80216638(Ptr32<Arena>);
extern "C" int fn_80215e10(Ptr32<Arena>, Ptr32<void>);
extern "C" Ptr32<char> w3d_d28k_debug_alloc_80215fd8(Ptr32<Arena> self, unsigned int size) {
 Ptr32<const char> file = self->file;
 int line = self->line;
 Ptr32<Heap> h = self->heap;
 self->file = 0;
 self->line = 0;
 unsigned int flags = h->flags;
 if (flags & 8192) {
  fn_8021573c(self, 0, 0, file, line, 1);
  return 0;
 }
 flags |= 8192;
 h->flags = flags;
 if (flags & 4) fn_80216638(self);
 unsigned int total = ((size + 7) & ~7UL) + 32;
 if (total <= 15) total = 16;
 self->heap->flags |= 16384;
 Ptr32<char> p = (Ptr32<char>)lbl_804aba74->alloc(self, total);
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


