#include "w3d_ptr.h"
#line 1 "d43l_key_border_setup_802c73a4.cpp"
// GWMP8P rev0 0x802c73a4. Key-button setup: fills the border sprite's UVs,
// loads the three-part FE.K.KeyBdr border twice, sets each part's glyph byte
// by state and row, attaches the parts to the panel and marks the key ready.
struct Str {
 Ptr32<char> text;
 template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
 Str(const Str &);
 ~Str();
};
extern "C" void w3d_string_base_finish(Ptr32<Str>);
extern "C" void w3d_string_release(Ptr32<Str>);
inline Str::~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
struct Obj;
struct ObjT {
 Ptr32<void> s0[3];
 Ptr32<void (Ptr32<Obj>)> retain;
 Ptr32<void (Ptr32<Obj>)> release;
 Ptr32<void> s20[18];
 Ptr32<void (Ptr32<Obj>, Ptr32<Obj>, int)> attach;
};
struct Obj { Ptr32<ObjT> vt; };
extern "C" int w3d_handle_set_name(const Str &, Ptr32<Ptr32<Obj>>, unsigned char);
struct Held {
 Ptr32<Obj> value;
 Held() { value = 0; }
 Held(const Held &);
 ~Held() { if (value) value->vt->release(value); }
 operator Ptr32<Obj>() const { return (Obj *)this->operator Obj *(); }
 operator Obj *() const { return value; }
 template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *p)
 {
  if (p) p->vt->retain(p);
  if (value) value->vt->release(value);
  value = p;
 }
};
extern int w3d_resource_base_804abb60;
extern "C" Ptr32<Obj> w3d_empty_8034357c(Ptr32<Obj>);
extern "C" void d26l_key_border_uvs_802c7f60(Ptr32<struct Key>);
extern "C" int w3d_s20_store_byte_value_80173f88(Ptr32<Obj>, const unsigned char &);
struct Temp { Ptr32<Obj> value; Temp() { value = 0; } Temp(const Temp &); ~Temp() { if (value) value->vt->release(value); } };
struct Key { unsigned w0[7]; Ptr32<Obj> panel; unsigned w32[2]; Held a[2]; Held b[2]; Held c[2]; unsigned w64[5]; int alt; unsigned w88[5]; int ready; };
inline void load(Held &d, const Str &n, unsigned char t) {
 Temp h;
 w3d_handle_set_name(n, &h.value, t);
 d = w3d_empty_8034357c(h.value);
}
extern "C" void d43l_key_border_setup_802c73a4(Ptr32<Key> self)
{
 d26l_key_border_uvs_802c7f60(self);
 int base = w3d_resource_base_804abb60;
 for (unsigned i = 0; i < 2; i++) {
  load(self->a[i], Str("FE.K.KeyBdr"), !self->alt ? base + 30 : base + 31);
  load(self->b[i], Str("FE.K.KeyBdr"), !self->alt ? base + 30 : base + 31);
  load(self->c[i], Str("FE.K.KeyBdr"), !self->alt ? base + 30 : base + 31);
  int k = 0;
  if (self->alt) k = 6;
  if (i == 1) k = 3;
  w3d_s20_store_byte_value_80173f88(self->a[i], k);
  w3d_s20_store_byte_value_80173f88(self->b[i], k + 1);
  w3d_s20_store_byte_value_80173f88(self->c[i], k + 2);
  self->panel->vt->attach(self->panel, self->a[i], 0);
  self->panel->vt->attach(self->panel, self->b[i], 0);
  self->panel->vt->attach(self->panel, self->c[i], 0);
 }
 self->ready = 1;
}


