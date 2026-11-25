// (Worms 3D GameCube PAL, 0x801b3b30).
//
// Loads a resource by name: returns a cached entry found in either name
// table, otherwise dispatches on the extension: TGA, TIF and TIFF through
// virtual slot 6, RTG through slot 7, XOM by opening the tagged reader and a
// stream, then testing the root's type chain against 0x80364fa4 and
// 0x80362704 and calling slots 4 or 5. Returns the failure code of each
// step, 0x80004005 for an unknown root and 0x80070057 for an unknown
// extension. Names are inferred.

struct TypeInfo { char p[20]; TypeInfo *parent; };
static inline bool isA(TypeInfo *self, TypeInfo *base) {
  TypeInfo *t = self;
  while (t != base) {
    TypeInfo *n = t->parent;
    if (t == n) return false;
    t = n;
  }
  return true;
}
extern TypeInfo lbl_80364fa4[], lbl_80362704[];
struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual TypeInfo *type(); };
struct Stream { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void attach(int); virtual void v4(),v5(); virtual int seek(int, int); };
struct Tagged { int w[5]; int value; Tagged(); ~Tagged(); int refill(const char *, int); int data() { return value; } };
struct Ref { Stream *p; Ref(Stream *o) { p = o; if (p) p->AddRef(); } Ref(const Ref &); ~Ref() { if (p) p->Release(); } };
extern char lbl_803aaab8[], lbl_803aaabc[], lbl_803aaac0[], lbl_803aaac8[], lbl_803aaacc[];
extern "C" char *strrchr(const char *, int);
extern "C" int w3d_d24z_strcasecmp_802ef074(const char *, const char *);
extern "C" Stream *w3d_auto_8020b6c0();
extern "C" int w3d_auto_801ffea8(TypeInfo *);
struct Loader;
extern "C" int w3d_s10_find_string_801b4060(Loader *, const char *);
extern "C" int w3d_s10_find_string_801b40d0(Loader *, const char *);
struct LoaderBase { virtual void v0(),v1(),v2(),v3(); virtual int v24(const char *, Obj *); virtual int v28(const char *, Obj *); virtual int v32(const char *, void **); virtual int v36(const char *, void **); };
struct Loader : LoaderBase { char p[40]; void **a; char q[20]; void **b; };
extern "C" int w3d_d30e_load_by_extension_801b3b30(Loader *self, const char *name, void **out) {
  int i = w3d_s10_find_string_801b4060(self, name);
  if (i != -1) { *out = *(void **)((i << 2) + (char *)self->a); return 0; }
  i = w3d_s10_find_string_801b40d0(self, name);
  if (i != -1) { *out = self->b[i]; return 0; }
  const char *ext = strrchr(name, '.');
  if (!ext) return 0x80004005;
  if (w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaab8) || w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaabc) || w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaac0))
    return self->v32(name, out);
  if (w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaac8)) return self->v36(name, out);
  if (w3d_d24z_strcasecmp_802ef074(ext, lbl_803aaacc)) {
    Obj **root = 0;
    Tagged t;
    int hr = t.refill(name, 1);
    if (hr < 0) return hr;
    Ref s(w3d_auto_8020b6c0());
    s.p->attach(t.data());
    hr = s.p->seek(0, 0);
    if (hr < 0) return hr;
    TypeInfo *ty = (*root)->type();
    if (isA(ty, lbl_80364fa4)) self->v24(name, *root);
    else if (isA(ty, lbl_80362704)) self->v28(name, *root);
    else {
      w3d_auto_801ffea8(ty);
      (*root)->Release();
      return 0x80004005;
    }
    return 0;
  }
  return 0x80070057;
}
