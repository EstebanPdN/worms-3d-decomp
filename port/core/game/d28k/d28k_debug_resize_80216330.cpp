#include "w3d_ptr.h"
#line 1 "d28k_debug_resize_80216330.cpp"
// Debug heap reallocation (Worms 3D GameCube PAL, 0x80216330).
// Null block allocates (0x80215fd8), size zero frees (0x80216154). Otherwise follows the
// debug free checks, saves the old tag, resizes through the allocator table with mode bit
// 4 masked, restores the old tag on failure or writes a new one on success, then clears
// the grown bytes when mode bit 4 is set.

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
extern "C" int abs(int);
extern "C" Ptr32<char> fn_80215fd8(Ptr32<Arena>, unsigned int);
extern "C" int fn_80216154(Ptr32<Arena>, Ptr32<char>);
extern "C" Ptr32<char> w3d_d28k_debug_resize_80216330(Ptr32<Arena> self, Ptr32<char> mem, unsigned int size, unsigned int mode) {
 Ptr32<Heap> h = self->heap;
 Ptr32<char> p;
 unsigned int old;
 if (!mem) {
  p = fn_80215fd8(self, size);
  old = 0;
 } else {
  if (size == 0) {
   fn_80216154(self, mem);
   return 0;
  }
  Ptr32<const char> file = self->file;
  int line = self->line;
  self->file = 0;
  self->line = 0;
  unsigned int flags = h->flags;
  if (flags & 8192) {
   fn_8021573c(self, 0, 0, file, line, 3);
   return 0;
  }
  flags |= 8192;
 h->flags = flags;
  if (flags & 4) fn_80216638(self);
  self->heap->flags |= 16384;
  p = (Ptr32<char>)w3d::G(fn_80215e10(self, mem));
  if (p) {
   Ptr32<Hooks> k = self->hooks;
   if (k->fail) k->fail(self, 3, mem, k);
   fn_8021573c(self, mem, p == (Ptr32<char>)w3d::G(-1) ? 0 : 1, file, line, 3);
   h->flags &= ~8192UL;
   return 0;
  }
  if (lbl_804b06c4 > 0) fn_80215be4(self, mem, file, line, 3);
  p = mem - 16;
  old = *(Ptr32<unsigned int>)(mem - 12);
  Ptr32<const char> ofile = *(Ptr32<Ptr32<const char>>)(mem - 16);
  int oline = abs(*(Ptr32<int>)((Ptr32<char>)w3d::G((*(Ptr32<unsigned int>)(mem - 20) & ~7UL)) + (unsigned int)w3d::H(mem) - 20));
  unsigned int total = ((size + 7) & ~7UL) + 32;
  if (total <= 15) total = 16;
  self->heap->flags |= 16384;
  p = (Ptr32<char>)lbl_804aba74->resize(self, p, total, mode & ~4UL);
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
  Ptr32<char> q = p + old; Ptr32<char> e = p + size;
  do { *q++ = 0; } while (q < e);
 }
 return p;
}


