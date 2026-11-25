#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c26_swapped_header_80202bb4.c"
struct Stream { Ptr32<Ptr32<void>> vtable; };
struct Reader { char head[20]; Ptr32<struct Stream> stream; };
struct Hdr { unsigned int a; unsigned short b, c; unsigned int d; unsigned int trailing; };
extern int fn_802025a8(Ptr32<struct Reader>, Ptr32<void>, int);
static inline unsigned int swap32(unsigned int v) { return v; }
static inline unsigned short swap16(unsigned short v) { return v; }
int tsonnet_c26_read_swapped_header_80202bb4(Ptr32<struct Reader> self) {
 struct Hdr h;
 fn_802025a8(self, &h, 16);
 h.b = swap16(h.b);
 h.c = swap16(h.c);
 h.d = swap32(h.d);
 ((Ptr32<void (Ptr32<struct Stream>, unsigned int, int, int)>)self->stream->vtable[7])(self->stream, h.d, 1, 0);
 return 0;
}

}
