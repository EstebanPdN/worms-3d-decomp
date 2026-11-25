/* Reference-only: formatting into the 128-byte buffer is unbounded here;
   safety for arbitrary header strings and lengths is not established. */
/* Reference-only: writes a stream message. While a pending-header flag is
   set, the header is formatted with the elapsed time into a local buffer and
   written through the stream's sixth virtual slot (clearing the flag on
   success); then the caller's data is written. Field offsets are observed;
   names and meanings are inferred. */
struct Stream;
struct StreamVtable { char pad[24]; int (*write)(struct Stream *, const char *, int, int); };
struct Stream { struct StreamVtable *vtable; };
struct Writer { char unknown00[20]; struct Stream *stream; char *header; int pending; };
extern int fn_801fe45c(void);
extern int fn_803434d4(char *buf, const char *fmt, ...);
extern int fn_802ef9c0(const char *s);

int tsonnet_c32_stream_write_80208994(struct Writer *self, const char *data, int size) {
    if (self->pending) {
        char buf[128];
        struct Stream *s;
        int r;
        char *p;
        fn_803434d4(buf, self->header, fn_801fe45c());
        s = self->stream;
        p = buf;
        r = s->vtable->write(s, p, fn_802ef9c0(p), 0);
        if (r < 0) return r;
        self->pending = 0;
    }
    return self->stream->vtable->write(self->stream, data, size, 0);
}
