#include "w3d_ptr.h"
#line 1 "d30k_scroll_list_create_8026f528.cpp"
// GWMP8P rev0 0x8026f528. Creates the text box scroll list on first use:
// creates the object through 0x8020b680, registers it, passes the two held
// interfaces, places it from the box geometry and copies its settings, then
// updates the scroll bar when one exists. Names are inferred from use. The
// leading literal 2.0 stays extern because the pool starts 4 bytes past an
// 8-byte boundary; owns the tail from 0x803cbf08. Built with -mps-float:
// frame gap only without it.
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
 Ptr32<Obj> p;
 template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 // 0x802bc098 suelta sus dos argumentos en el PPC (GCC 2.95); aquí los suelta quien llama.
 ~Ref() { if (p) p->vt->release(p); }
};
struct Vec { float x, y, z; Vec() {} Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; y = b; p->z = c; } };
struct Info { char u[20]; float x, y; char u28[92]; float f120; int f124; };
struct Box {
 char u0[20]; int f20; char u24[4]; char text[4]; int f32; char u36[4]; Ptr32<Info> info; char u44[68]; Ptr32<Obj> f112; char u116[24]; int f140; char u144[44]; int f188; char u192[60]; float f252; char u256[28]; Ptr32<Obj> f284; Ptr32<Obj> list; Ptr32<void> f292;
};
struct List { char u[92]; float f92; };
extern "C" Ptr32<Obj> fn_8020b680(Ptr32<void>);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<Obj>, int);
extern "C" void fn_802bc098(Ptr32<Obj>, Ref, Ref);
extern "C" void fn_802bc180(Ptr32<Obj>, Ptr32<const Vec>);
extern "C" void fn_802bcb6c(Ptr32<Obj>, int);
extern "C" void fn_802bcc40(Ptr32<Obj>, int);
extern "C" void fn_802bcbd8(Ptr32<Obj>, float);
extern "C" float fn_802b1880(Ptr32<void>);
extern "C" void fn_802bcd10(Ptr32<Obj>, int);
extern "C" void fn_802bcd18(Ptr32<Obj>, int);
extern "C" void fn_802bc570(Ptr32<Obj>);
extern "C" void fn_8026fac4(Ptr32<Box>);
extern "C" unsigned fn_802bc71c(Ptr32<Obj>);
extern "C" float fn_802bc778(Ptr32<Obj>);
extern "C" void fn_80296378(Ptr32<void>, float, float, float);
extern "C" void fn_80296410(Ptr32<void>, float);
extern char lbl_8041c850[];
extern "C" Ptr32<void> lbl_804b178c;
extern float lbl_803cbf04[];
extern "C" void w3d_d30k_scroll_list_create_8026f528(Ptr32<Box> self) {
 if (self->list) return;
 float h = self->f252;
 Ptr32<Obj> &slot = self->list;
 slot = fn_8020b680(lbl_8041c850);
 fn_80164514(lbl_804b178c, slot, self->f20);
 fn_802bc098(self->list, Ref(self->f284), Ref(self->f112));
 Ptr32<Info> in = self->info;
 float d = h - lbl_803cbf04[0];
 Vec v(in->x - d + 1.0f, in->y - d, 1.0f);
 fn_802bc180(self->list, &v);
 fn_802bcb6c(self->list, in->f124);
 fn_802bcc40(self->list, self->f188);
 fn_802bcbd8(self->list, in->f120);
 ((Ptr32<List>)self->list)->f92 = fn_802b1880(self->text);
 fn_802bcd10(self->list, self->f32);
 fn_802bcd18(self->list, self->f140);
 fn_802bc570(self->list);
 fn_8026fac4(self);
 Ptr32<void> s = self->f292;
 if (s) {
  float n = fn_802bc71c(self->list);
  fn_80296378(s, 0.0f, n, fn_802bc778(self->list));
  fn_80296410(self->f292, 0.0f);
 }
}


