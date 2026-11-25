struct Stream { void **vtable; };
struct Reader { char head[20]; struct Stream *stream; char pad[40]; unsigned int limit; };
extern int fn_802025a8(struct Reader *, void *, int);
static inline unsigned int swap32(unsigned int v) { return (v << 24) | ((v << 8) & 0xff0000) | ((v >> 8) & 0xff00) | (v >> 24); }
int tsonnet_c26_skip_records_80202b18(struct Reader *self) {
 unsigned int buf[4];
 if (self->limit <= 0x1ffffff) return 0;
 fn_802025a8(self, buf, 16);
 buf[1] = swap32(buf[1]);
 ((void (*)(struct Stream *, unsigned int, int, int))self->stream->vtable[7])(self->stream, buf[1] << 4, 1, 0);
 return 0;
}
