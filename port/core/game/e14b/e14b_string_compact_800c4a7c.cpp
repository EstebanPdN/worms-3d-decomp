#include "w3d_ptr.h"
#line 1 "e14b_string_compact_800c4a7c.cpp"
// A string buffer view: two character pointers into a shared text block.
// Only the two words the recovered body reads and writes are declared.
struct e14b_StringView {
  Ptr32<char> begin;
  Ptr32<char> end;
};
// The string object owned by the caller; its layout belongs to the assign
// helper's unit.
struct e14b_String;
// Recovered elsewhere: replace the string object's contents with a text.
extern "C" Ptr32<e14b_String> w3d_string_assign(Ptr32<e14b_String> string, Ptr32<const char> text);
// The original issues the varargs call sequence (crclr before the branch),
// so the block copy is declared with a trailing ellipsis.
extern "C" Ptr32<void> w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
// Compact the buffer behind self+4 by dropping the 33-byte text header: when
// the buffer is non-empty, hand its bytes to the string object, move the text
// down over the header and shorten the buffer. A void buffer leaves the
// failure status untouched; the original tests equality first so it returns
// the default status through a single shared epilogue.
extern "C" int e14b_string_compact_800c4a7c(Ptr32<char> self, Ptr32<e14b_String> string)
{
  Ptr32<e14b_StringView> view = (Ptr32<e14b_StringView>)(self + 4);
  int status = 0x80004005;
  Ptr32<char> begin = view->begin;
  if (begin == view->end)
    return status;
  w3d_string_assign(string, begin);
  Ptr32<char> p = view->begin;
  Ptr32<char> end = view->end;
  if (p + 33 != end) {
    Ptr32<char> stop = end - 33;
    w3d_memcpy_802eee50(p, p + 33, (unsigned int)(stop - p));
  }
  view->end = view->end - 33;
  return 0;
}


