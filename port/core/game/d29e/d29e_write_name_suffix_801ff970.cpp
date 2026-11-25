#include "w3d_ptr.h"
#line 1 "d29e_write_name_suffix_801ff970.cpp"
// (Worms 3D GameCube PAL, 0x801ff970).
//
// From a null-terminated list of names computes the length of the prefix
// shared by all of them; writes the name at the selected index without that
// prefix to the output, or formats the unknown index with the text at
// 0x803b2a50. Names are inferred.

extern "C" unsigned strlen(Ptr32<const char>);
extern "C" int w3d_s21_write_text_8020dbf8(Ptr32<void>, Ptr32<const char>);
extern "C" void w3d_cx10b_text_format_variadic_8020d6bc(Ptr32<void>, Ptr32<const char>, ...);
extern const char lbl_803b2a50[];
extern "C" void w3d_d29e_write_name_suffix_801ff970(Ptr32<void> self, Ptr32<void> out, Ptr32<unsigned int> index, Ptr32<Ptr32<const char>> names) {
  unsigned which = *index;
  unsigned len = strlen(names[0]);
  unsigned n = 0;
  for (Ptr32<Ptr32<const char>> p = names + 1; *p; p++, n++) {
    unsigned i = 0;
    while (i < len) {
      if (names[0][i] != (*p)[i]) { len = i; break; }
      i++;
    }
  }
  if (which < n) w3d_s21_write_text_8020dbf8(out, names[which] + len);
  else w3d_cx10b_text_format_variadic_8020d6bc(out, lbl_803b2a50, which);
}


