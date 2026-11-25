#include "w3d_ptr.h"
#line 1 "d24l_strip_text_codes_802cc3d0.cpp"
// GWMP8P rev0 0x802cc3d0. Removes control codes from a text buffer in place when
// the global switch at 0x804abce4 is set: each backspace (8) deletes itself and
// the character before it (or, at the very start, only itself), then each 0xFF
// escape is removed: 0xFA up to and including the next 0xF0 terminator, and
// 0xFB..0xFE together with their one parameter byte. Any other code after 0xFF
// is not consumed, so the original loop does not advance past it.
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern "C" unsigned strlen(Ptr32<const char>);
extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, unsigned);
extern int lbl_804abce4;
extern "C" void d24l_strip_text_codes_802cc3d0(Ptr32<char> text) {
  if (lbl_804abce4 == 0) return;
  Ptr32<char> p = strchr(text, 8);
  while (p) {
    if (p == text) {
      memmove(text, text + 1, strlen(text));
    } else {
      Ptr32<char> d = p - 1;
      Ptr32<char> s2 = p + 1;
      memmove(d, s2, strlen(p));
    }
    p = strchr(text, 8);
  }
  Ptr32<char> q = strchr(text, 255);
  while (q) {
    switch ((unsigned char)q[1]) {
    case 251: case 252: case 253: case 254: {
      Ptr32<char> s = q + 3;
      memmove(q, s, strlen(q + 2));
      q = strchr(text, 255);
      break; }
    case 250: {
      Ptr32<char> e = strchr(q, 240) + 1;
      memmove(q, e, strlen(e - 1));
      q = strchr(e, 255);
      break; }
    }
  }
}


