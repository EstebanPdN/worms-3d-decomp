// GWMP8P rev0 0x80218948. Buffered disc stream read: clamps the request to
// the bytes left; aligned requests read whole 32-byte blocks straight into
// the destination and the tail through the 1 KB cache; unaligned ones loop
// through the cache. Reports the count, flushes the range, returns
// 0x90000001 when nothing was read. Names are inferred from use.
extern "C" void *fn_80343994();
extern "C" int fn_801fdcac(void *, void *, void *, unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, ...);
extern "C" void fn_802fa988(void *, unsigned);
inline const unsigned &MinU(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
inline const int &MinI(const int &a, const int &b) { return b < a ? b : a; }
struct Stream { char u0[24]; char dvd[52]; unsigned size; char u80[4]; unsigned base; char *cache; int cached; char u96[8]; unsigned pos; };
extern "C" int w3d_d30k_disc_stream_read_80218948(Stream *self, char *dst, unsigned n, unsigned *read) {
 unsigned done = 0;
 unsigned odd = (unsigned)dst & 31;
 unsigned avail = self->size - self->pos;
 n = MinU(avail, n);
 if (!n) return 0x90000001;
 char *out = dst;
 if (odd == 0 && (self->pos & 3) == 0) {
  unsigned whole = n & ~31;
  if (whole) fn_801fdcac(fn_80343994(), self->dvd, dst, whole, self->pos);
  out = dst + whole;
  self->pos += whole;
  int rest = n - whole;
  if (rest) {
   self->base = self->pos & ~3;
   int m = 1024;
   int c = MinI(rest, m);
   fn_801fdcac(fn_80343994(), self->dvd, self->cache, (c + 31) & ~31, self->base);
   memcpy(out, self->cache, c);
   self->pos += c;
  }
  done = n;
  n = 0;
 } else {
  if (!self->cached) self->cached = 1;
  while (n) {
   self->base = self->pos & ~3;
   unsigned need = n + (self->pos & 3);
   unsigned m = 1024;
   unsigned c = MinU(need, m);
   fn_801fdcac(fn_80343994(), self->dvd, self->cache, (c + 31) & ~31, self->base);
   unsigned left = 1024 - (self->pos & 3);
   unsigned k = MinU(n, left);
   memcpy(out, self->cache + self->pos - self->base, k);
   out += k;
   done += k;
   self->pos += k;
   n -= k;
  }
 }
 if (read) *read = done;
 fn_802fa988(dst, done);
 int r = 0x90000001;
 if (done) r = 0;
 return r;
}
