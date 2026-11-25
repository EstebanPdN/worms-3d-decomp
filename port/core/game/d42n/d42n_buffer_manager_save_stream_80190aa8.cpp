#include "w3d_ptr.h"
#line 1 "d42n_buffer_manager_save_stream_80190aa8.cpp"
// GWMP8P rev0 0x80190aa8. Saves a buffer manager to a stream, the writing
// twin of the loader at 0x80191130: the prefixed name, the entry table, then
// per record the weight, name and per-element stage data. Class, field and
// slot names are inferred from use.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
extern "C" void fn_8019800c(Ptr32<void>);
struct Str_803426b8 {
 Ptr32<char> p;
 Str_803426b8();
 template <class W3dU> Str_803426b8(Ptr32<W3dU> w3d_p) : Str_803426b8((const char *)w3d_p.get()) {}
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 Str_803426b8 &operator=(const Str_803426b8 &o) {
  ++((Ptr32<Header>)(o.p - 6))->refs;
  Ptr32<Header> h = (Ptr32<Header>)(p - 6);
  if (--h->refs == 0) fn_8020bb2c(h);
  p = o.p;
  return *this;
 }
 Str_803426b8 &operator+=(const char *);
};
typedef Str_803426b8 Str;
extern "C" Ptr32<Str> fn_8020bf2c(Ptr32<Str>, Ptr32<const char>);
inline Str &Str::operator+=(const char *t) { fn_8020bf2c(this, t); return *this; }
inline Str operator+(const Str &a, const Str &b) { Str r = a; r += b.p; return r; }
extern const char lbl_803a825c[];
struct Stage { float x0, x1, a, b, c, d; };
struct Elem {
 unsigned short w; /* palabra PPC: bits y luego índice; el índice es la mitad baja del anfitrión */ unsigned short d:6; unsigned short c:3; unsigned short b:3; unsigned short f3:1; unsigned short f2:1; unsigned short f1:1; unsigned short f0:1;
 Ptr32<Stage> stages; unsigned short size;
};
struct List { Ptr32<Elem> start; Ptr32<Elem> finish; Ptr32<Elem> end; int u; unsigned size() const { return finish - start; } Elem &operator[](unsigned i) { return start[i]; } };
struct Body { char u[72]; };
extern "C" int fn_8019805c(Ptr32<Body>, Ptr32<List>);
struct Record { Str name; float weight; Body body; unsigned char flag; };
struct Entry { Str name; unsigned char a, b; unsigned short c; };
struct Writer;
struct WriterVt {
 Ptr32<void> u0[10];
 Ptr32<int (Ptr32<Writer>, bool, int, int)> wbit;
 Ptr32<void> u2c[2];
 Ptr32<int (Ptr32<Writer>, unsigned char, int, int)> wbyte;
 Ptr32<void> u38[3];
 Ptr32<int (Ptr32<Writer>, unsigned short, int, int)> wshort;
 Ptr32<void> u48[2];
 Ptr32<int (Ptr32<Writer>, unsigned int, int, int)> wsmall;
 Ptr32<int (Ptr32<Writer>, unsigned int, int, int)> wcount;
 Ptr32<void> u58[6];
 Ptr32<int (Ptr32<Writer>, float, int, int)> wfloat;
 Ptr32<void> u74[3];
 Ptr32<int (Ptr32<Writer>, Ptr32<const Str>, int, int)> wstring;
};
struct Writer { Ptr32<WriterVt> vt; };
template <class T> struct Arr { Ptr32<T> start; Ptr32<T> finish; Ptr32<T> end; int pad; T &operator[](unsigned i) { return start[i]; } unsigned size() const { return finish - start; } };
struct Self {
 Ptr32<void> vt; char u4[16];
 Arr<Entry> es;
 Arr<Record> rs;
 Arr<List> ls;
 Str name;
};
struct Stream {
 Ptr32<Writer> w;
 template <class W3dU> Stream(Ptr32<W3dU> w3d_p) : Stream((Writer *)w3d_p.get()) {}
 Stream(Writer *r) : w(r) {}
 void wbit(bool x) { w->vt->wbit(w, x, 0, 0); }
 void wbyte(unsigned char x) { w->vt->wbyte(w, x, 0, 0); }
 void wshort(unsigned short x) { w->vt->wshort(w, x, 0, 0); }
 void wsmall(unsigned x) { w->vt->wsmall(w, x, 0, 0); }
 void wcount(unsigned x) { w->vt->wcount(w, x, 0, 0); }
 void wfloat(float x) { w->vt->wfloat(w, x, 0, 0); }
 void wstring(const Str &x) { w->vt->wstring(w, &x, 0, 0); }
};
extern "C" int w3d_d42n_buffer_manager_save_stream_80190aa8(Ptr32<Self> self, Ptr32<Writer> w) {
 Stream t(w);
 Str n;
 n = Str(lbl_803a825c) + self->name;
 t.wstring(n);
 t.wcount(self->es.size());
 for (unsigned i = 0; i < self->es.size(); ++i) {
  Stream s(w);
  s.wbyte(self->es[i].a);
  s.wshort(self->es[i].c);
  s.wbyte(self->es[i].b);
  s.wstring(self->es[i].name);
 }
 t.wcount(self->rs.size());
 for (unsigned j = 0; j < self->rs.size(); ++j) {
  Stream s(w);
  s.wfloat(self->rs[j].weight);
  s.wstring(self->rs[j].name);
  fn_8019805c(&self->rs[j].body, &self->ls[j]);
  s.wcount(self->ls[j].size());
  for (unsigned k = 0; k < self->ls[j].size(); ++k) {
   bool on = self->ls[j][k].f0;
   Stream s(w);
   s.wbit(on);
   s.wbit(self->ls[j][k].f3);
   s.wbit(self->ls[j][k].f2);
   s.wbit(self->ls[j][k].f1);
   s.wshort(self->ls[j][k].w);
   s.wsmall(self->ls[j][k].c);
   s.wsmall(self->ls[j][k].b);
   s.wcount(self->ls[j][k].size);
   for (unsigned m = 0; m < self->ls[j][k].size; ++m) {
    Stage &t = self->ls[j][k].stages[m];
    Stream s(w);
    s.wfloat(t.a);
    s.wfloat(t.b);
    s.wfloat(t.c);
    s.wfloat(t.d);
    s.wfloat(t.x0);
    s.wfloat(t.x1);
   }
  }
  fn_8019800c(&self->rs[j].body);
 }
 return 0;
}


