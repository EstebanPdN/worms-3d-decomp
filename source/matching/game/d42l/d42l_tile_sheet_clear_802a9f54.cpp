// GWMP8P rev0 0x802a9f54. Releases the tile sprites and part handles of a
// sheet panel. Partial views. Ref's layout and the 80-byte row stride come
// from the original's reads and mulli.
struct Obj;
struct ObjT { void *s0[4]; void (*release)(Obj *); void *s20[19]; void (*remove)(Obj *, Obj *); };
struct Obj { ObjT *vt; };
struct Ref {
 Obj *p;
 Ref();
 operator Obj *() const { return p; }
 Obj *operator->() const { return p; }
 Ref(const Ref &);
 ~Ref();
 void clear() { if (p) p->vt->release(p); p = 0; }
 void operator=(Obj *n) { if (p) p->vt->release(p); p = n; }
};
struct Tile { Ref sprite; int w[3]; };
struct Sheet {
 char u0[28]; char panel[184]; Ref a, b, c; char u224[20]; Ref self244;
 Ref node[3]; char u260[820]; Tile tile[3][5]; char u1320[36];
 Ref d, e; Ref sub[3];
};
extern "C" void w3d_auto_802b0fec(void *);
extern "C" void d42l_tile_sheet_clear_802a9f54(Sheet *self)
{
 self->self244.clear();
 for (int i = 0; i <= 2; i++) {
  for (int j = 0; j < 5; j++) {
   Ref &s = ((Tile *)(i * 80 + (int)self->tile))[j].sprite;
   if (s) {
    { Obj *n = self->node[i]; n->vt->remove(n, s); }
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
