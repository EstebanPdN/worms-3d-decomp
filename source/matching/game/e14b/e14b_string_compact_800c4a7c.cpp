// A string buffer view: two character pointers into a shared text block.
// Only the two words the recovered body reads and writes are declared.
struct e14b_StringView {
  char *begin;
  char *end;
};
// The string object owned by the caller; its layout belongs to the assign
// helper's unit.
struct e14b_String;
// Recovered elsewhere: replace the string object's contents with a text.
extern "C" e14b_String *w3d_string_assign(e14b_String *string, const char *text);
// The original issues the varargs call sequence (crclr before the branch),
// so the block copy is declared with a trailing ellipsis.
extern "C" void *w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
// Compact the buffer behind self+4 by dropping the 33-byte text header: when
// the buffer is non-empty, hand its bytes to the string object, move the text
// down over the header and shorten the buffer. A void buffer leaves the
// failure status untouched; the original tests equality first so it returns
// the default status through a single shared epilogue.
extern "C" int e14b_string_compact_800c4a7c(char *self, e14b_String *string)
{
  e14b_StringView *view = (e14b_StringView *)(self + 4);
  int status = 0x80004005;
  char *begin = view->begin;
  if (begin == view->end)
    return status;
  w3d_string_assign(string, begin);
  char *p = view->begin;
  char *end = view->end;
  if (p + 33 != end) {
    char *stop = end - 33;
    w3d_memcpy_802eee50(p, p + 33, (unsigned int)(stop - p));
  }
  view->end = view->end - 33;
  return 0;
}
