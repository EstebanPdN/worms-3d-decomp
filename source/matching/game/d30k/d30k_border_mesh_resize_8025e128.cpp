// GWMP8P rev0 0x8025e128. Lays out a nine-patch border mesh: clamps the
// corner size to the smaller half extent, builds the 16 grid corners, writes
// the triangle vertices from the index table at 0x804012c0, and updates the
// bounding box and sphere. Names are inferred from use. Built with -mps-
// float: frame gap only without it.
struct Obj;
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; char data[1]; };
extern "C" void *fn_801ef048(void *, unsigned, int, int);
struct Vec { float x, y, z; Vec() {} void Set(float a, float b, float c) { Vec *p = this; x = a; y = b; p->z = c; } };
struct Box { Vec min, max; Box() {} Box(float a,float b,float c,float d,float e,float f){ min.Set(a,b,c); max.Set(d,e,f);} };
struct Sphere { float v[4]; };
struct Arr { Hdr *h; };
struct Mark { char u[7]; unsigned char f; void Clear() { f &= 0xfe; } };
struct Obj { ObjVt *vt; Mark mark; char u12[8]; Arr a20; Box &box() { return *(Box *)&a20; } Sphere &sphere() { return *(Sphere *)&a20; } };
struct Obj2 { char u[40]; int f40; void Set40(int v) { f40 = v; } };
struct Obj3 { char u[32]; Obj *f32; char u36[8]; Obj3 *f44; Obj *f48; char u52[28]; Obj *f80; };
struct Ref {
 Obj *p;
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
 Obj *operator->() const { return p; }
 Obj3 *x() const { return (Obj3 *)p; }
};
struct Owner { Obj *o; };
extern "C" Obj *fn_801750d4(Obj *);
extern "C" void * fn_801f55ec(Sphere *, Box *);
extern const unsigned char lbl_804012c0[];
inline unsigned Id(const unsigned &v) { return v; }
inline const float &Min(const float &a, const float &b) { return b < a ? b : a; }
inline void Put(Box &d, const Box &v) { d = v; }
inline void Put(Sphere &d, const Sphere &v) { d = v; }
extern "C" void w3d_d30k_border_mesh_resize_8025e128(Owner *self, float r, float a, float b) {
 if (a < r || b < r) r = Min(a, b);
 Ref o(fn_801750d4(self->o));
 Ref m(o.x()->f44->f32);
 Ref g(m.x()->f48);
 Ref e(g.x()->f80);
 Arr *arr = &e->a20;
 Hdr *h = arr->h; unsigned n = h->count; Vec *q; if (h->refs == 1) { h->gen++; q = (Vec *)h->data; } else q = (Vec *)fn_801ef048(arr, n, 12, 2);
 Vec v[16];
 for (unsigned i = 0; i < 4; i++) { v[i].y = b; v[i + 4].y = b - r; v[i + 8].y = r - b; v[i + 12].y = -b; }
 for (unsigned i = 0; i < 4; i++) { v[i * 4].x = -a; v[i * 4 + 1].x = r - a; v[i * 4 + 2].x = a - r; v[i * 4 + 3].x = a; }
 for (unsigned i = 0; i < Id(n); i++) { *q = v[lbl_804012c0[i]]; q->z = 0.0f; q++; }
 m->mark.Clear();
 int z = 0;
 Box box(-a, -b, 0.0f, a, b, 0.0f); Sphere s;
 fn_801f55ec(&s, &box);
 Put(g->box(), box);
 Put(m->sphere(), s);
 ((Obj2 *)m.p)->Set40(z);
}
