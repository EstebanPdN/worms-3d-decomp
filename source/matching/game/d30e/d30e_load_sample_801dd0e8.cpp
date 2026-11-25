// (Worms 3D GameCube PAL, 0x801dd0e8).
//
// Creates a sound sample object from a description: loads a .wav or .vag
// file by extension, or copies an already registered sample found by name
// when it reports ready; applies the description's fields through virtual
// slots 9 and 11 and setters at 0x801df1dc to 0x801df280, then appends it to
// the manager. Returns 0 or 0x80004005. Reference counted through a one-word
// holder. Names are inferred.

struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void v3(),v4(),v5(); virtual int v32(); virtual void v36(int); virtual void v8(); virtual void v44(int); };
struct Ref {
  Obj *p;
  Ref(Obj *o) { p = o; if (p) p->AddRef(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->Release(); }
};
struct Mgr;
struct Desc { int a; char q[8]; char *name; int count; int b; int c; float d, e, f, g, h; int i; int j; };
extern char lbl_8036564c[];
extern char lbl_803b0110[], lbl_803b0118[];

extern "C" char *strstr(const char *, const char *);
extern "C" Obj *w3d_r24b_invoke_ready_callback_8020fcb4(void *);
extern "C" int w3d_s21_has_name_801ddff4(Mgr *, char *);
extern "C" int w3d_s21_index_of_name_801de080(Mgr *, char *);
extern "C" Obj *w3d_s21_get_item_801de10c(Mgr *, int);
extern "C" int w3d_s21_copy_from_801df11c(Obj *, Obj *);
extern "C" int w3d_constant_801df10c(Obj *, char *, int);
extern "C" int w3d_constant_801df114(Obj *, char *);
extern "C" void w3d_set_801df234(Obj *, int);
extern "C" void w3d_set_801df1dc(Obj *, int);
extern "C" void w3d_setf_801df1fc(Obj *, float);
extern "C" void w3d_auto_801df1e4(Obj *, float, float);
extern "C" void w3d_setf_801df204(Obj *, float);
extern "C" void w3d_auto_801df1f0(Obj *, float, float);
extern "C" int w3d_auto_801df20c(Obj *, char *);
extern "C" void w3d_set_801df280(Obj *, int);
extern "C" int w3d_s21_append_ref_801ddf5c(Mgr *, Obj *);
extern "C" int w3d_d30e_load_sample_801dd0e8(void *self, Mgr *mgr, Desc *d) {
  Ref r(w3d_r24b_invoke_ready_callback_8020fcb4(lbl_8036564c));
  if (!strstr(d->name, lbl_803b0110) && !strstr(d->name, lbl_803b0118)) {
    if (!w3d_s21_has_name_801ddff4(mgr, d->name)) return 0x80004005;
    Ref t(w3d_s21_get_item_801de10c(mgr, w3d_s21_index_of_name_801de080(mgr, d->name)));
    if (!t.p->v32()) return 0x80004005;
    w3d_s21_copy_from_801df11c(r.p, t.p);
  } else if (strstr(d->name, lbl_803b0110)) {
    if (!w3d_constant_801df10c(r.p, d->name, d->i)) return 0x80004005;
  } else if (strstr(d->name, lbl_803b0118)) {
    if (!w3d_constant_801df114(r.p, d->name)) return 0x80004005;
  }
  r.p->v36(d->a);
  if (d->count > 0) w3d_set_801df234(r.p, d->count);
  r.p->v44(d->b);
  w3d_set_801df1dc(r.p, d->c);
  w3d_setf_801df1fc(r.p, d->d);
  w3d_auto_801df1e4(r.p, d->e, 0.0f);
  w3d_setf_801df204(r.p, d->f);
  w3d_auto_801df1f0(r.p, d->g, d->h);
  w3d_auto_801df20c(r.p, d->name);
  w3d_set_801df280(r.p, d->j);
  if (!w3d_s21_append_ref_801ddf5c(mgr, r.p)) return 0x80004005;
  return 0;
}
