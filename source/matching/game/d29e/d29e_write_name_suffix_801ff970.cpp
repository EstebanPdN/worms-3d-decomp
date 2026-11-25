// (Worms 3D GameCube PAL, 0x801ff970).
//
// From a null-terminated list of names computes the length of the prefix
// shared by all of them; writes the name at the selected index without that
// prefix to the output, or formats the unknown index with the text at
// 0x803b2a50. Names are inferred.

extern "C" unsigned strlen(const char *);
extern "C" int w3d_s21_write_text_8020dbf8(void *, const char *);
extern "C" void w3d_cx10b_text_format_variadic_8020d6bc(void *, const char *, ...);
extern const char lbl_803b2a50[];
extern "C" void w3d_d29e_write_name_suffix_801ff970(void *self, void *out, unsigned *index, const char **names) {
  unsigned which = *index;
  unsigned len = strlen(names[0]);
  unsigned n = 0;
  for (const char **p = names + 1; *p; p++, n++) {
    unsigned i = 0;
    while (i < len) {
      if (names[0][i] != (*p)[i]) { len = i; break; }
      i++;
    }
  }
  if (which < n) w3d_s21_write_text_8020dbf8(out, names[which] + len);
  else w3d_cx10b_text_format_variadic_8020d6bc(out, lbl_803b2a50, which);
}
