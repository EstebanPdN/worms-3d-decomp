// GWMP8P rev0 0x802708dc. Animates a 40-column water strip: time scaled by
// 10 and 1.5 drives two cosine waves (period constants 12.5 and 8.5, heights
// 0.1 and 0.05), writing each column's lower and upper vertex x and y. Names
// are inferred from use. Owns the literals from 0x803cc030. Built with -mps-
// float: frame gap only without it.
extern "C" float fn_802e86d4(float);
struct Obj;
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); void *u20[11]; Obj *(*get)(Obj *); };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; int count; unsigned short gen; char u30[2]; char data[1]; };
struct Arr { Hdr *h; };
extern "C" void *fn_801ef048(Arr *, int, int, int);
inline void *Lock(Arr *a, int count, int size, int flag) {
 Hdr *h = a->h;
 if (h->refs == 1 && h->count == count) { h->gen++; return h->data; }
 return fn_801ef048(a, count, size, flag);
}
struct Vec { float x, y, z; };
struct Geo { char u[20]; Arr a; };
struct Obj { ObjVt *vt; char u4[36]; Obj *f40; char u44[4]; Obj *f48; char u52[28]; Geo *f80; };
struct Ref {
 Obj *p;
 void operator=(Obj *n) { if (n) n->vt->retain(n); if (p) p->vt->release(p); p = n; }
 Ref() : p(0) {}
 Ref(Obj *n) : p(0) { *this = n; }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
 Obj *operator->() const { return p; }
};
struct Wave { char u[212]; Obj *f212; };
extern "C" void w3d_d30k_water_wave_update_802708dc(Wave *self, unsigned t) {
 float x = t;
 float a = x / 10.0f;
 float b = x / 1.5f;
 Ref r1(self->f212->vt->get(self->f212));
 Ref r2; r2 = r1->f40;
 Ref r3; r3 = r2->f48;
 Vec *v = (Vec *)Lock(&r3->f80->a, 80, 12, 0);
 for (unsigned i = 0; i < 40; i++) {
  float px = (float)i * (1.0f / 39.0f);
  float c = fn_802e86d4((px + a) * 12.5f) * 0.1f;
  float d = fn_802e86d4((px + b) * 8.5f) * 0.05f;
  int j = i * 2;
  v[j].x = px;
  v[j].y = c + 0.0f + d;
  j++;
  v[j].x = px;
  v[j].y = c + 1.0f + d;
 }
}
