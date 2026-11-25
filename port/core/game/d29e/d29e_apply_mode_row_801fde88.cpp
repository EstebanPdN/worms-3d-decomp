#include "w3d_ptr.h"
#line 1 "d29e_apply_mode_row_801fde88.cpp"
// (Worms 3D GameCube PAL, 0x801fde88).
//
// Reads a row index from 0x802ff854, then by the kind word at the start of
// self (1 to 5) passes the three words of that row from one of five
// consecutive tables (0x803b2700 to 0x803b2730, 60-byte stride) to
// 0x801fdf60. Returns 0, or 1 for an unknown kind. Names are inferred.

struct Row { int a, b, c; char p[48]; };
extern Row lbl_803b2700[], lbl_803b270c[], lbl_803b2718[], lbl_803b2724[], lbl_803b2730[];
extern "C" int fn_802ff854();
extern "C" int w3d_auto_801fdf60(Ptr32<void>, int, int, int);
extern "C" int w3d_d29e_apply_mode_row_801fde88(Ptr32<int> self) {
  int result = 0;
  int i = fn_802ff854();
  switch (*self) {
    case 1: { const Row &t = lbl_803b2700[i]; w3d_auto_801fdf60(self, t.a, t.b, t.c); break; }
    case 2: { const Row &t = lbl_803b270c[i]; w3d_auto_801fdf60(self, t.a, t.b, t.c); break; }
    case 3: { const Row &t = lbl_803b2718[i]; w3d_auto_801fdf60(self, t.a, t.b, t.c); break; }
    case 4: { const Row &t = lbl_803b2724[i]; w3d_auto_801fdf60(self, t.a, t.b, t.c); break; }
    case 5: { const Row &t = lbl_803b2730[i]; w3d_auto_801fdf60(self, t.a, t.b, t.c); break; }
    default: result = 1;
  }
  return result;
}


