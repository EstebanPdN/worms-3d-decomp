#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c26_skip_records_80202b18.c"
struct Stream { Ptr32<Ptr32<void>> vtable; };
struct Reader { char head[20]; Ptr32<struct Stream> stream; char pad[40]; unsigned int limit; };
extern int fn_802025a8(Ptr32<struct Reader>, Ptr32<void>, int);
static inline unsigned int swap32(unsigned int v) { return v; }
int tsonnet_c26_skip_records_80202b18(Ptr32<struct Reader> self) {
 unsigned int buf[4];
 if (self->limit <= 0x1ffffff) return 0;
 fn_802025a8(self, buf, 16);
 buf[1] = swap32(buf[1]);
 ((Ptr32<void (Ptr32<struct Stream>, unsigned int, int, int)>)self->stream->vtable[7])(self->stream, buf[1] << 4, 1, 0);
 return 0;
}

}
