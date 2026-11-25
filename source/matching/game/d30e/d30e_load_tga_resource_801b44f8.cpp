// (Worms 3D GameCube PAL, 0x801b44f8).
//
// Loads a texture resource from a file: opens the file through the file
// service (slot 4), reads its size via slot 7 into a stat record, creates a
// buffer entry of that size, reads the file into it, and for a tga extension
// decodes through the codec service 0x804165e0 into a new object of type
// 0x80364fa4, then stores the object through out and its name string at +36.
// Returns the failure code of the reads or 0x80004005.

struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
extern "C" void w3d_string_release_header(void *);
struct String {
  char *p;
  String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &o) {
    ++*(unsigned short *)(o.p - 6);
    unsigned short *h = (unsigned short *)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual int v20(void *, int, int); virtual int v24(const char *, int, void *); virtual void v5(),v6(); virtual void v36(void *); };
struct Buf { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void v3(),v4(),v5(); virtual void v32(int); virtual void v36(); virtual int v40(void *); };
struct Out : Obj { char q[32]; String name; };
template <class T> struct Ref {
  T *p;
  Ref() { p = 0; }
  Ref(T *o) { p = o; if (p) p->AddRef(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->Release(); }
  Ref &operator=(T *o) { if (o) o->AddRef(); if (p) p->Release(); p = o; return *this; }
};
struct Self;
struct Stat { int size; int a, b, c; };
struct Dec { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual int v20(Buf *, Out *); };
extern char lbl_803aab64[], lbl_804165e0[], lbl_80364fa4[];
extern "C" char *strrchr(const char *, int);
extern "C" int w3d_d24z_strcasecmp_802ef074(const char *, const char *);
extern "C" Obj *w3d_auto_801b4938(Self *);
extern "C" Buf *w3d_s10_create_entry_80208aac(int);
extern "C" Obj *w3d_s10_service_forward_8020b680(void *);
extern "C" Out *w3d_r24b_invoke_ready_callback_8020fcb4(void *);
extern "C" int w3d_d30e_load_tga_resource_801b44f8(Self *self, const char *name, Out **out) {
  *out = 0;
  Ref<Obj> fs(w3d_auto_801b4938(self));
  Ref<Out> a;
  int result;
  {
    Ref<Buf> b;
    Ref<Obj> c;
    int hr = fs.p->v24(name, 1, &c.p);
    if (hr < 0) return hr;
    Stat st;
    c.p->v36(&st);
    Buf *n = w3d_s10_create_entry_80208aac(1);
    b = n;
    n->v32(st.size);
    void *data;
    n->v40(&data);
    hr = c.p->v20(data, st.size, 0);
    if (hr < 0) return hr;
    c = 0;
    const char *ext = strrchr(name, '.');
    if (ext && !w3d_d24z_strcasecmp_802ef074(ext + 1, lbl_803aab64)) c = w3d_s10_service_forward_8020b680(lbl_804165e0);
    if (!c.p) return 0x80004005;
    Out *na = w3d_r24b_invoke_ready_callback_8020fcb4(lbl_80364fa4);
    a = na;
    result = ((Dec *)c.p)->v20(b.p, na);
  }
  if (result < 0) return 0x80004005;
  *out = a.p;
  a.p->AddRef();
  Out *o = a.p;
  o->name = String(name);
  return 0;
}
