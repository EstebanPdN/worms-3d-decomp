#include "w3d_ptr.h"
#line 1 "d42l_tile_sheet_clear_802a9f54.cpp"
// GWMP8P rev0 0x802a9f54. Releases the tile sprites and part handles of a
// sheet panel. Partial views. Ref's layout and the 80-byte row stride come
// from the original's reads and mulli.
struct Obj;
struct ObjT { Ptr32<void> s0[4]; Ptr32<void (Ptr32<Obj>)> release; Ptr32<void> s20[19]; Ptr32<void (Ptr32<Obj>, Ptr32<Obj>)> remove; };
struct Obj { Ptr32<ObjT> vt; };
struct Ref {
 Ptr32<Obj> p;
 Ref();
 operator Ptr32<Obj>() const { return (Obj *)this->operator Obj *(); }
 operator Obj *() const { return p; }
 Ptr32<Obj> operator->() const { return p; }
 Ref(const Ref &);
 ~Ref();
 void clear() { if (p) p->vt->release(p); p = 0; }
 template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *n) { if (p) p->vt->release(p); p = n; }
};
struct Tile { Ref sprite; int w[3]; };
struct Sheet {
 char u0[28]; char panel[184]; Ref a, b, c; char u224[20]; Ref self244;
 Ref node[3]; char u260[820]; Tile tile[3][5]; char u1320[36];
 Ref d, e; Ref sub[3];
};
extern "C" void w3d_auto_802b0fec(Ptr32<void>);
extern "C" void d42l_tile_sheet_clear_802a9f54(Ptr32<Sheet> self)
{
 self->self244.clear();
 for (int i = 0; i <= 2; i++) {
  for (int j = 0; j < 5; j++) {
   Ref &s = ((Ptr32<Tile>)w3d::G((i * 80 + (int)w3d::H(self->tile))))[j].sprite;
   if (s) {
    { Ptr32<Obj> n = self->node[i]; n->vt->remove(n, s); }
    s = 0;
   }
  }
  self->node[i] = 0;
  self->sub[i].clear();
 }
 self->a = 0;
 self->b = 0;
 self->c = 0;
 self->e = 0;
 self->d.clear();
 w3d_auto_802b0fec(self->panel);
}


