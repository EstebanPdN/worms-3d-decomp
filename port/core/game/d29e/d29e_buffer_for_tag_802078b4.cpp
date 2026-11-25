#include "w3d_ptr.h"
#line 1 "d29e_buffer_for_tag_802078b4.cpp"
// (Worms 3D GameCube PAL, 0x802078b4).
//
// Returns the data pointer of the record buffer selected by the 24-bit id in
// a tag word. An unset id gets a new buffer from 0x8020777c, stored back in
// the tag, and the buffer is grown to need; otherwise the buffer is grown
// only if its capacity is below need. Names are inferred.

struct Buf { Ptr32<void> data; unsigned cap; };
struct Table { char p[36]; Ptr32<Ptr32<Buf>> bufs; };
struct Tag { unsigned a; unsigned int kind:8; unsigned int id:24; };
extern "C" int fn_8020777c(Ptr32<Table>);
extern "C" void w3d_cx10b_record_buffer_grow_80207514(Ptr32<Buf>, unsigned, int);
extern "C" Ptr32<void> w3d_d29e_buffer_for_tag_802078b4(Ptr32<Table> self, Ptr32<Tag> tag, unsigned need) {
  unsigned short id = tag->id;
  if (id == 0) {
    int n = fn_8020777c(self);
    tag->id = (unsigned short)n;
    Ptr32<Buf> b = *(Ptr32<Ptr32<Buf>>)((Ptr32<char>)self->bufs + (n << 2));
    w3d_cx10b_record_buffer_grow_80207514(b, need, 0);
    return b->data;
  }
  Ptr32<Buf> b = *(Ptr32<Ptr32<Buf>>)((Ptr32<char>)self->bufs + (id << 2));
  if (b->cap < need) w3d_cx10b_record_buffer_grow_80207514(b, need, 0);
  return b->data;
}


