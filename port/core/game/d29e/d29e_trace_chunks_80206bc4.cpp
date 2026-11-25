#include "w3d_ptr.h"
#line 1 "d29e_trace_chunks_80206bc4.cpp"
// (Worms 3D GameCube PAL, 0x80206bc4).
//
// When tracing is enabled (0x804ab9a4), reports the length through out if
// given and prints the text: directly if null-terminated, otherwise in
// terminated chunks of at most 255 bytes through a 256-byte stack buffer.
// Returns 0. Names are inferred.

extern int lbl_804ab9a4;
extern "C" Ptr32<void> memcpy(...);
extern "C" void w3d_s21_trace_80217fc8(Ptr32<const char>);
struct Chunk { char d[255]; };
extern "C" int w3d_d29e_trace_chunks_80206bc4(Ptr32<void> self, Ptr32<const char> text, unsigned len, Ptr32<unsigned int> out) {
  if (lbl_804ab9a4 != 0) {
    Ptr32<const char> p = text;
    if (out) *out = len;
    if (p[len - 1] == 0) {
      w3d_s21_trace_80217fc8(p);
    } else if (len != 0) {
      char buf[256];
      do {
        if (len > 255) {
          *(Ptr32<Chunk>)buf = *(Ptr32<const Chunk>)p;
          buf[255] = 0;
          len -= 255;
          p += 255;
        } else {
          memcpy(w3d::VA(buf), w3d::VA(p), len);
          buf[len] = 0;
          len = 0;
        }
        w3d_s21_trace_80217fc8(buf);
      } while (len != 0);
    }
  }
  return 0;
}


