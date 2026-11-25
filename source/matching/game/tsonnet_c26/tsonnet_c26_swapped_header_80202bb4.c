struct Stream { void **vtable; };
struct Reader { char head[20]; struct Stream *stream; };
struct Hdr { unsigned int a; unsigned short b, c; unsigned int d; unsigned int trailing; };
extern int fn_802025a8(struct Reader *, void *, int);
static inline unsigned int swap32(unsigned int v) { return (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24); }
static inline unsigned short swap16(unsigned short v) { return ((v & 0xff) << 8) | (v >> 8); }
int tsonnet_c26_read_swapped_header_80202bb4(struct Reader *self) {
 struct Hdr h;
 fn_802025a8(self, &h, 16);
 h.b = swap16(h.b);
 h.c = swap16(h.c);
 h.d = swap32(h.d);
 ((void (*)(struct Stream *, unsigned int, int, int))self->stream->vtable[7])(self->stream, h.d, 1, 0);
 return 0;
}
