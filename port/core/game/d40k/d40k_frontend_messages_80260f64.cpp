#include "w3d_ptr.h"
#line 1 "d40k_frontend_messages_80260f64.cpp"
// GWMP8P rev0 0x80260f64. Front-end screen message handler: a chain of
// cached message-id tests covering tooltips, property writes, level name
// parsing and navigation, backup and restore of level properties, briefing
// text, error text, screen offset adjustment and language selection, then
// the base handler.
struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str_803426b8 {
 Ptr32<char> p;
 Str_803426b8();
 template <class W3dU> Str_803426b8(Ptr32<W3dU> w3d_p) : Str_803426b8((const char *)w3d_p.get()) {}
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 unsigned short len() const { return ((Ptr32<Header>)(p - 6))->length; }
 Str_803426b8 &operator=(const Str_803426b8 &o) {
  ++((Ptr32<Header>)(o.p - 6))->refs;
  Ptr32<Header> h = (Ptr32<Header>)(p - 6);
  if (--h->refs == 0) fn_8020bb2c(h);
  p = o.p;
  return *this;
 }
};
struct Type { char u0[20]; Ptr32<Type> parent; };
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> add; Ptr32<void (Ptr32<Obj>)> rel; Ptr32<Ptr32<Type> (Ptr32<Obj>)> type; Ptr32<int (Ptr32<Obj>)> kind; };
struct Obj { Ptr32<ObjVt> vt; };
struct Held { Ptr32<Obj> o; Held() : o(0) {} Held(const Held &); ~Held() { if (o) o->vt->rel(o); } };
struct Key { Ptr32<const char> n; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *s) : n(s) {} };
struct Msg { unsigned short id; };
struct Note { unsigned short id; Ptr32<const void> vt; };
struct IdCache { short id; };
struct Sound; struct SoundVt { char u0[124]; Ptr32<void (Ptr32<Sound>, int)> mode; };
struct Sound { Ptr32<SoundVt> vt; };
struct Lang { char u0[108]; Ptr32<Sound> sound; };
struct Source { char u0[36]; Str title; Str brief; };
// Names are inferred from use; Self, Source and Note are partial views.
struct Self { char u0[28]; Ptr32<Obj> f28; Ptr32<void> f32; Ptr32<void> f36; char u40[136]; int f176; char u180[4]; Ptr32<void> names; char u188[8]; int f196; char u200[12]; Str f212; };
extern "C" {
int fn_8016293c(Ptr32<Self>, Ptr32<Msg>);
void fn_802622fc(Ptr32<Self>);
void fn_802629bc(Ptr32<Self>);
int fn_8015f65c(unsigned short, Ptr32<IdCache>);
int fn_8026462c(Ptr32<Self>);
Ptr32<void> fn_80341584(Ptr32<Obj>);
Ptr32<Source> fn_801797b4(Ptr32<void>);
Ptr32<void> fn_801613f0(Ptr32<void>, int);
short fn_8015f5a0(Ptr32<IdCache>, int);
Ptr32<void> fn_8010a8e0(Ptr32<void>, unsigned short, Ptr32<const char>);
int fn_8016239c(Ptr32<void>);
Ptr32<const char> fn_8010a8fc(Ptr32<Msg>);
int fn_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
int fn_800fc550(const Key &, Ptr32<const char>);
int fn_800fc43c(const Key &, int);
int fn_800fc230(const Key &, Ptr32<int>);
int fn_800fc1f0(const Key &, Ptr32<int>);
int fn_800fc3b0(const Key &, int);
int fn_800fc1b0(const Key &, Ptr32<Ptr32<Obj>>);
void fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
int fn_8015fc58(Ptr32<Self>, Ptr32<void>);
int fn_801790bc(Ptr32<void>, Ptr32<const char>);
int fn_800c4b00(Ptr32<void>, Ptr32<const char>);
void fn_80262a58(Ptr32<Self>);
int fn_800c4660(Ptr32<void>);
int fn_800c4d38(Ptr32<void>, Ptr32<Str>);
int fn_800c4d9c(Ptr32<void>, Ptr32<Str>);
void fn_802644a8(Ptr32<Self>, Ptr32<const char>);
void fn_80262124(Ptr32<Self>, Ptr32<const char>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
int fn_80162c20();
Ptr32<void> fn_803426b4(Ptr32<Obj>);
int fn_80178c54(Ptr32<void>, const unsigned &);
Ptr32<void> fn_80342a78(Ptr32<Obj>);
int fn_80178d28(Ptr32<void>, const int &);
Ptr32<Str> fn_80179170(Ptr32<void>);
void fn_8029301c(Ptr32<void>);
void fn_802643d0(Ptr32<Self>, Ptr32<const char>);
void fn_80127ba0(Ptr32<Lang>, int);
}
extern int lbl_804abb5c, lbl_804abb54, lbl_804abb58, lbl_804abb50, lbl_804abb48, lbl_804ab094, lbl_804ab098;
extern Ptr32<void> lbl_804b1754; extern Ptr32<void> lbl_804abbfc;
extern Ptr32<Lang> lbl_804b1788;
extern char tbl_8040db38[];
extern Type type_803667a8[];
extern Str lbl_804b06a0_[];
extern IdCache id_804b097c;
extern IdCache id_804b0984;
extern IdCache id_804b098c;
extern IdCache id_804b0994;
extern IdCache id_804b099c;
extern IdCache id_804b09a4;
extern IdCache id_804b09ac;
extern IdCache id_804b09b4;
extern IdCache id_804b09bc;
extern IdCache id_804b09c4;
extern IdCache id_804b09d4;
extern IdCache id_804b09dc;
extern IdCache id_804b09e4;
extern IdCache id_804b09fc;
extern IdCache id_804b0a04;
extern IdCache id_804b0a0c;
extern IdCache id_804b0a14;
extern IdCache id_804b0a1c;
extern IdCache id_804b0a24;
extern IdCache id_804b0a2c;
extern IdCache id_804b0a34;
extern IdCache id_804b0a3c;
extern IdCache id_804b0a44;
extern IdCache id_804b0a4c;
extern IdCache id_804b0a54;
extern IdCache id_804b0a5c;
extern IdCache id_804b0a64;
extern IdCache id_804b0a6c;
extern IdCache id_804b0a74;
extern IdCache id_804b0a7c;
extern IdCache id_804b0a84;
extern IdCache id_804b0a8c;
extern char s_803cabf0[];
extern char s_803cac08[];
extern char s_803cac68[];
extern char s_803cac80[];
extern char s_803cac88[];
extern char s_803cac98[];
extern char s_803cacb0[];
extern char s_803cacc4[];
extern char s_803cacdc[];
extern char s_803cace8[];
extern char s_803cacfc[];
extern char s_803cad0c[];
extern char s_803cad20[];
extern char s_803cad28[];
extern char s_803cad40[];
extern char s_803cad48[];
extern char s_803cad58[];
extern char s_803cad6c[];
extern char s_803cad7c[];
extern char s_803cad8c[];
extern char s_803cad94[];
extern char s_803cada4[];
extern char s_803cadb4[];
extern char s_803cadbc[];
extern char s_803cadc4[];
extern char s_803cadc8[];
extern char s_803cadd0[];
extern char s_803caddc[];
extern char s_803cade4[];
extern char s_803cadec[];
extern char s_803cadf4[];
extern char s_803cadfc[];
extern char s_803cae0c[];
extern char s_803cae14[];
extern char s_803cae1c[];
extern char s_803cae24[];
extern char s_803cae2c[];
inline Ptr32<void> New(int n) { return fn_801613f0(lbl_804b1754, n); }
inline Ptr32<void> Make8(Ptr32<IdCache> c) {
 Ptr32<Note> m = (Ptr32<Note>)New(8);
 m->id = fn_8015f5a0(c, 1);
 m->vt = tbl_8040db38;
 return m;
}
inline bool Digit(unsigned char c) { return c >= '0' && c <= '9'; }
inline bool Eq(const Str &s, Ptr32<const char> t) { return strcmp(s.p, t) == 0; }
inline void PostText(Ptr32<IdCache> c, Ptr32<const char> const &t) {
 Ptr32<void> m = New(12);
 unsigned short id = fn_8015f5a0(c, 1);
 fn_8016239c(fn_8010a8e0(m, id, t));
}
template <Type *want> inline bool IsA(Ptr32<Obj> o) {
 Ptr32<Type> t = o->vt->type(o);
 while (t != want) {
  Ptr32<Type> up = t->parent;
  if (t == up) return false;
  t = up;
 }
 return true;
}
extern "C" int w3d_d40k_frontend_messages_80260f64(Ptr32<Self> self, Ptr32<Msg> msg) {
 switch (msg->id) {
 case 64:
  if (fn_8016293c(self, msg) >= 0) { fn_802622fc(self); return 0; }
  return 0x80004005;
 case 66:
  fn_802629bc(self);
  break;
 default:
  if (fn_8015f65c(msg->id, &id_804b09e4) && fn_8026462c(self)) {
   int posted = 0;
   if (lbl_804abb5c != 0 && lbl_804abb5c == lbl_804abb54) return 0;
   if (self->f28) {
    Ptr32<Source> src = fn_801797b4(fn_80341584(self->f28));
    if (src->title.len() != 0) {
     posted = 1;
     PostText(&id_804b09fc, src->title.p);
    }
   }
   if (!posted && lbl_804abb5c != 0) {
    fn_8016239c(Make8(&id_804b0a44));
    fn_8016239c(Make8(&id_804b0a0c));
   }
  } else if (fn_8015f65c(msg->id, &id_804b0a14)) {
   Str s(fn_8010a8fc(msg));
   Ptr32<const char> t;
   Ptr32<Str> ps = &s;
   if (fn_800fc2b0(Key(s.p), &t) == 0) fn_8020bd38(ps, t);
   fn_800fc550(Key(s_803cac68), s.p);
  } else if (fn_8015f65c(msg->id, &id_804b0a1c)) {
   Str s(fn_8010a8fc(msg));
   fn_800fc43c(Key(s.p), 1);
  } else if (int r = fn_8015f65c(msg->id, &id_804b0a24)) {
   Str s(fn_8010a8fc(msg));
   fn_800fc43c(Key(s.p), 0);
  } else if (fn_8015f65c(msg->id, &id_804b098c)) {
   Str s;
   fn_8020bd38(&s, fn_8010a8fc(msg));
   Ptr32<char> p = s.p;
   lbl_804abb50 = 0;
   lbl_804abb58 = 0;
   if (s.len() != 0 && Digit(*p)) {
    lbl_804abb50 = (signed char)*p - 48;
    fn_8020bd38(&s, p + 1);
    if (Digit(*p)) {
     lbl_804abb58 = (signed char)*p - 48;
     fn_8020bd38(&s, p + 1);
    }
   }
   fn_8015fc58(self, msg);
   fn_801790bc(self->f36, s.p);
   fn_800c4b00(self->names, s.p);
   fn_80262a58(self);
  } else if (fn_8015f65c(msg->id, &id_804b0a04)) {
   Ptr32<void> m = New(12);
   unsigned short id = fn_8015f5a0(&id_804b098c, 1);
   fn_8016239c(fn_8010a8e0(m, id, fn_8010a8fc(msg)));
  } else if (fn_8015f65c(msg->id, &id_804b0994)) {
   Str s(fn_8010a8fc(msg));
   lbl_804abb50 = -1;
   lbl_804abb58 = -1;
   fn_8015fc58(self, Make8(&id_804b09b4));
   fn_801790bc(self->f36, s.p);
   while (fn_800c4660(self->names) != 0) {
    Str t;
    fn_800c4d38(self->names, &t);
   }
   fn_800c4b00(self->names, s.p);
   self->f196 = 2;
  } else if (fn_8015f65c(msg->id, &id_804b09d4)) {
   fn_802644a8(self, fn_8010a8fc(msg));
  } else if (fn_8015f65c(msg->id, &id_804b0a6c)) {
   fn_80262124(self, fn_8010a8fc(msg));
  } else if (fn_8015f65c(msg->id, &id_804b097c)) {
   Ptr32<const char> t = fn_8010a8fc(msg);
   int v;
   if (strcmp(t, s_803cac80) == 0) {
    fn_800fc2b0(Key(s_803cac88), &t);
    fn_800fc550(Key(s_803cac98), t);
    fn_800fc230(Key(s_803cacb0), &v);
    fn_800fc43c(Key(s_803cacc4), v);
    fn_800fc230(Key(s_803cacdc), &v);
    fn_800fc43c(Key(s_803cace8), v);
    fn_800fc230(Key(s_803cacfc), &v);
    fn_800fc43c(Key(s_803cad0c), v);
   } else if (strcmp(t, s_803cad20) == 0) {
    fn_800fc230(Key(s_803cacc4), &v);
    fn_800fc43c(Key(s_803cacb0), v);
    fn_800fc230(Key(s_803cace8), &v);
    fn_800fc43c(Key(s_803cacdc), v);
    fn_800fc230(Key(s_803cad0c), &v);
    fn_800fc43c(Key(s_803cacfc), v);
    fn_800fc2b0(Key(s_803cac98), &t);
    fn_800fc550(Key(s_803cac88), t);
   }
  } else if (fn_8015f65c(msg->id, &id_804b0a74)) {
   fn_800fc43c(Key(s_803cad28), 0);
  } else if (fn_8015f65c(msg->id, &id_804b0a64)) {
   int v = fn_80162c20();
   Str s(fn_8010a8fc(msg));
   if (s.len() != 0) {
    Held h;
    if (fn_800fc1b0(Key(s.p), &h.o) >= 0) {
     switch (h.o->vt->kind(h.o)) {
     case 0: fn_80178c54(fn_803426b4(h.o), v); break;
     case 1: fn_80178d28(fn_80342a78(h.o), v); break;
     }
    }
   }
  } else if (fn_8015f65c(msg->id, &id_804b0a5c)) {
   Str s(fn_8010a8fc(msg));
   if (s.len() != 0) {
    if (strcmp(s.p, s_803cad40) == 0) {
     fn_800fc550(Key(s_803cad48), s_803cabf0);
    } else {
     Held h;
     if (fn_800fc1b0(Key(s.p), &h.o) >= 0) if (h.o->vt->kind(h.o) == 5) if (IsA<type_803667a8>((Ptr32<Obj>)fn_801797b4(fn_80341584(h.o)))) {
      Ptr32<Source> src = fn_801797b4(fn_80341584(h.o));
      s = src->brief;
      if (s.len() != 0) {
       Ptr32<const char> t;
       if (fn_800fc2b0(Key(s.p), &t) >= 0) fn_8020bd38(&s, t);
      } else {
       fn_8020bd38(&s, s_803cad58);
      }
      fn_800fc550(Key(s_803cad48), s.p);
     }
    }
   }
  } else if (fn_8015f65c(msg->id, &id_804b099c)) {
   Str t(*fn_80179170(self->f36));
   fn_800c4d38(self->names, &t);
   fn_800c4d38(self->names, &t);
   Ptr32<char> a = t.p;
   if (strcmp(a, fn_80179170(self->f36)->p) != 0) PostText(&id_804b098c, t.p);
  } else if (fn_8015f65c(msg->id, &id_804b09a4)) {
   Str t(*fn_80179170(self->f36));
   fn_800c4d38(self->names, &t);
   if (fn_800c4d9c(self->names, &t) >= 0) {
    int r = fn_800fc1b0(Key(t.p), &self->f28);
    fn_801790bc(self->f32, t.p);
    if (r < 0) fn_801790bc(self->f32, s_803cac08);
   }
  } else if (fn_8015f65c(msg->id, &id_804b09dc)) {
   if (lbl_804abbfc) fn_8029301c(lbl_804abbfc);
  } else if (fn_8015f65c(msg->id, &id_804b09ac)) {
   fn_8016239c(Make8(&id_804b09a4));
   fn_8015fc58(self, Make8(&id_804b09b4));
  } else if (fn_8015f65c(msg->id, &id_804b0984)) {
   fn_8015fc58(self, Make8(&id_804b09b4));
   lbl_804abb50 = -1;
   lbl_804abb58 = -1;
   self->f196 = 2;
  } else if (fn_8015f65c(msg->id, &id_804b09bc)) {
  } else if (fn_8015f65c(msg->id, &id_804b09c4)) {
   self->f176 = -1;
  } else if (fn_8015f65c(msg->id, &id_804b0a34)) {
   Ptr32<Str> f = &self->f212;
   Ptr32<const char> x = fn_8010a8fc(msg);
   if (strcmp(self->f212.p, x) != 0) {
    fn_8020bd38(f, fn_8010a8fc(msg));
    Ptr32<const char> t;
    if (fn_800fc2b0(Key(fn_8010a8fc(msg)), &t) != (int)0x80004005) fn_800fc550(Key(s_803cad6c), t);
    else fn_800fc550(Key(s_803cad6c), fn_8010a8fc(msg));
    Ptr32<void> m = New(12);
    unsigned short id = fn_8015f5a0(&id_804b0a3c, 1);
    fn_8016239c(fn_8010a8e0(m, id, s_803cad7c));
   }
  } else if (fn_8015f65c(msg->id, &id_804b0a2c)) {
   self->f212 = *lbl_804b06a0_;
   fn_8016239c(Make8(&id_804b0a44));
  } else if (fn_8015f65c(msg->id, &id_804b0a4c)) {
   lbl_804abb48 = 1;
  } else if (fn_8015f65c(msg->id, &id_804b0a54)) {
   lbl_804abb48 = 0;
  } else if (fn_8015f65c(msg->id, &id_804b0a7c)) {
   Str s(fn_8010a8fc(msg));
   if (Eq(s, s_803cad8c)) {
    fn_800fc1f0(Key(s_803cad94), &lbl_804ab094);
    fn_800fc1f0(Key(s_803cada4), &lbl_804ab098);
    fn_802643d0(self, s_803cadb4);
   } else if (Eq(s, s_803cadbc)) {
    fn_800fc3b0(Key(s_803cad94), lbl_804ab094);
    fn_800fc3b0(Key(s_803cada4), lbl_804ab098);
    fn_802643d0(self, s_803cadb4);
   } else if (Eq(s, s_803cadc4)) {
    if ((lbl_804ab098 += 20) > 1024) { lbl_804ab098 = 1024; fn_802643d0(self, s_803cadc8); }
    else fn_802643d0(self, s_803cadd0);
   } else if (Eq(s, s_803caddc)) {
    if ((lbl_804ab098 -= 20) < -1024) { lbl_804ab098 = -1024; fn_802643d0(self, s_803cadc8); }
    else fn_802643d0(self, s_803cadd0);
   } else if (Eq(s, s_803cade4)) {
    if ((lbl_804ab094 -= 20) < -1024) { lbl_804ab094 = -1024; fn_802643d0(self, s_803cadc8); }
    else fn_802643d0(self, s_803cadd0);
   } else if (Eq(s, s_803cadec)) {
    if ((lbl_804ab094 += 20) > 1024) { lbl_804ab094 = 1024; fn_802643d0(self, s_803cadc8); }
    else fn_802643d0(self, s_803cadd0);
   }
  } else if (fn_8015f65c(msg->id, &id_804b0a84)) {
   Str s(fn_8010a8fc(msg));
   if (Eq(s, s_803cadf4)) { fn_80127ba0(lbl_804b1788, 0); fn_800fc43c(Key(s_803cadfc), 0); }
   else if (Eq(s, s_803cae0c)) { fn_80127ba0(lbl_804b1788, 4); fn_800fc43c(Key(s_803cadfc), 4); }
   else if (Eq(s, s_803cae14)) { fn_80127ba0(lbl_804b1788, 3); fn_800fc43c(Key(s_803cadfc), 3); }
   else if (Eq(s, s_803cae1c)) { fn_80127ba0(lbl_804b1788, 9); fn_800fc43c(Key(s_803cadfc), 9); }
   else if (Eq(s, s_803cae24)) { fn_80127ba0(lbl_804b1788, 5); fn_800fc43c(Key(s_803cadfc), 5); }
  } else if (fn_8015f65c(msg->id, &id_804b0a8c)) {
   int v;
   fn_800fc230(Key(s_803cae2c), &v);
   lbl_804b1788->sound->vt->mode(lbl_804b1788->sound, v);
  }
  break;
 }
 return fn_8016293c(self, msg);
}


