// GWMP8P rev0 0x8025eed0. Fills the colour array of a mesh's geometry with
// one value: owner to mesh, sub-object, geometry, array at +72, then locks
// it and copies the value to every element. Names are inferred from use. The
// loop bound goes through an inline const reference.
struct Obj;
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; char data[1]; };
extern "C" void *fn_801ef048(void *, unsigned, int, int);
struct Color { unsigned v; };
struct Arr { Hdr *h; };
struct Obj { ObjVt *vt; char u4[16]; Arr a20; char u24[8]; Obj *f32; char u36[8]; Obj *f44; Obj *f48; char u52[20]; Obj *f72; };
struct Ref {
 Obj *p;
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
 Obj *operator->() const { return p; }
};
struct Owner { Obj *o; };
inline unsigned Id(const unsigned &v) { return v; }
extern "C" Obj *fn_801750d4(Obj *);
extern "C" void w3d_d30k_mesh_fill_colour_8025eed0(Owner *self, const Color *c) {
 Ref a(fn_801750d4(self->o));
 Ref b(a->f44->f32);
 Ref d(b->f48);
 Ref e(d->f72);
 Arr *arr = &e->a20;
 Hdr *h = arr->h; unsigned n = h->count; Color *q; if (h->refs == 1) { h->gen++; q = (Color *)h->data; } else q = (Color *)fn_801ef048(arr, n, 4, 2);
 for (unsigned i = 0; i < Id(n); i++) *q++ = *c;
}
