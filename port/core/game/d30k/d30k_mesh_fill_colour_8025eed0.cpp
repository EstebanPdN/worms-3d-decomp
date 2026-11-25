#include "w3d_ptr.h"
#line 1 "d30k_mesh_fill_colour_8025eed0.cpp"
// GWMP8P rev0 0x8025eed0. Fills the colour array of a mesh's geometry with
// one value: owner to mesh, sub-object, geometry, array at +72, then locks
// it and copies the value to every element. Names are inferred from use. The
// loop bound goes through an inline const reference.
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; char data[1]; };
extern "C" Ptr32<void> fn_801ef048(Ptr32<void>, unsigned, int, int);
struct Color { unsigned v; };
struct Arr { Ptr32<Hdr> h; };
struct Obj { Ptr32<ObjVt> vt; char u4[16]; Arr a20; char u24[8]; Ptr32<Obj> f32; char u36[8]; Ptr32<Obj> f44; Ptr32<Obj> f48; char u52[20]; Ptr32<Obj> f72; };
struct Ref {
 Ptr32<Obj> p;
 template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
 Ptr32<Obj> operator->() const { return p; }
};
struct Owner { Ptr32<Obj> o; };
inline unsigned Id(const unsigned &v) { return v; }
extern "C" Ptr32<Obj> fn_801750d4(Ptr32<Obj>);
extern "C" void w3d_d30k_mesh_fill_colour_8025eed0(Ptr32<Owner> self, Ptr32<const Color> c) {
 Ref a(fn_801750d4(self->o));
 Ref b(a->f44->f32);
 Ref d(b->f48);
 Ref e(d->f72);
 Ptr32<Arr> arr = &e->a20;
 Ptr32<Hdr> h = arr->h; unsigned n = h->count; Ptr32<Color> q; if (h->refs == 1) { h->gen++; q = (Ptr32<Color>)h->data; } else q = (Ptr32<Color>)fn_801ef048(arr, n, 4, 2);
 for (unsigned i = 0; i < Id(n); i++) *q++ = *c;
}


