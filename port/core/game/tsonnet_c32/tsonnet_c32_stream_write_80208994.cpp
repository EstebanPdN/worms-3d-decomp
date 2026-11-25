#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c32_stream_write_80208994.c"
/* Reference-only: formatting into the 128-byte buffer is unbounded here;
   safety for arbitrary header strings and lengths is not established. */
/* Reference-only: writes a stream message. While a pending-header flag is
   set, the header is formatted with the elapsed time into a local buffer and
   written through the stream's sixth virtual slot (clearing the flag on
   success); then the caller's data is written. Field offsets are observed;
   names and meanings are inferred. */
struct Stream;
struct StreamVtable { char pad[24]; Ptr32<int (Ptr32<struct Stream>, Ptr32<const char>, int, int)> write; };
struct Stream { Ptr32<struct StreamVtable> vtable; };
struct Writer { char unknown00[20]; Ptr32<struct Stream> stream; Ptr32<char> header; int pending; };
extern int fn_801fe45c(void);
extern int fn_803434d4(Ptr32<char> buf, Ptr32<const char> fmt, ...);
extern int fn_802ef9c0(Ptr32<const char> s);

int tsonnet_c32_stream_write_80208994(Ptr32<struct Writer> self, Ptr32<const char> data, int size) {
    if (self->pending) {
        char buf[128];
        Ptr32<struct Stream> s;
        int r;
        Ptr32<char> p;
        fn_803434d4(buf, self->header, fn_801fe45c());
        s = self->stream;
        p = buf;
        r = s->vtable->write(s, p, fn_802ef9c0(p), 0);
        if (r < 0) return r;
        self->pending = 0;
    }
    return self->stream->vtable->write(self->stream, data, size, 0);
}

}
