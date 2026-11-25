#include "w3d_ptr.h"
#line 1 "d28k_debug_free_80216154.cpp"
// Debug heap free (Worms 3D GameCube PAL, 0x80216154).
// Takes the pending file and line, returns 0 for a null block, refuses re-entry, optionally
// checks the heap and validates the block (0x80215e10); a bad block goes to the error
// hook and 0x8021573c and returns -1. Otherwise logs, calls the watch hook, clears the
// payload words and returns the result of the allocator's release slot.

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
extern "C" int w3d_d28k_debug_free_80216154(Ptr32<Arena> self, Ptr32<char> mem) {
 Ptr32<const char> file = self->file;
 int line = self->line;
 Ptr32<Heap> h = self->heap;
 self->file = 0;
 self->line = 0;
 if (!mem) return 0;
 unsigned int flags = h->flags;
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
  Ptr32<Hooks> k = self->hooks;
  if (k->fail) k->fail(self, 3, mem, k);
  fn_8021573c(self, mem, bad == -1 ? 0 : 1, file, line, 2);
  h->flags &= ~8192UL;
  return -1;
 }
 if (lbl_804b06c4 > 0) fn_80215be4(self, mem, file, line, 2);
 if ((h->flags & 2) && lbl_80400768[0].watch) {
  self->file = file;
  self->line = line;
  lbl_80400768[0].watch(self, mem, 0, *(Ptr32<unsigned int>)(mem - 12));
 }
 Ptr32<char> q = mem;
 Ptr32<char> base = q - 16;
 Ptr32<char> end = q + ((*(Ptr32<unsigned int>)(q - 12) + 3) & ~3UL);
 for (; q < end; q += 4) *(Ptr32<int>)q = 0;
 h->flags &= ~8192UL;
 return lbl_804aba74->release(self, base);
}


