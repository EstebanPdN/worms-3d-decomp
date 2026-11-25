// GWMP8P rev0 0x8026f528. Creates the text box scroll list on first use:
// creates the object through 0x8020b680, registers it, passes the two held
// interfaces, places it from the box geometry and copies its settings, then
// updates the scroll bar when one exists. Names are inferred from use. The
// leading literal 2.0 stays extern because the pool starts 4 bytes past an
// 8-byte boundary; owns the tail from 0x803cbf08. Built with -mps-float:
// frame gap only without it.
struct Obj;
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Ref {
 Obj *p;
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
};
struct Vec { float x, y, z; Vec() {} Vec(float a, float b, float c) { Vec *p = this; x = a; y = b; p->z = c; } };
struct Info { char u[20]; float x, y; char u28[92]; float f120; int f124; };
struct Box {
 char u0[20]; int f20; char u24[4]; char text[4]; int f32; char u36[4]; Info *info; char u44[68]; Obj *f112; char u116[24]; int f140; char u144[44]; int f188; char u192[60]; float f252; char u256[28]; Obj *f284; Obj *list; void *f292;
};
struct List { char u[92]; float f92; };
extern "C" Obj *fn_8020b680(void *);
extern "C" int fn_80164514(void *, Obj *, int);
extern "C" void fn_802bc098(Obj *, Ref, Ref);
extern "C" void fn_802bc180(Obj *, const Vec *);
extern "C" void fn_802bcb6c(Obj *, int);
extern "C" void fn_802bcc40(Obj *, int);
extern "C" void fn_802bcbd8(Obj *, float);
extern "C" float fn_802b1880(void *);
extern "C" void fn_802bcd10(Obj *, int);
extern "C" void fn_802bcd18(Obj *, int);
extern "C" void fn_802bc570(Obj *);
extern "C" void fn_8026fac4(Box *);
extern "C" unsigned fn_802bc71c(Obj *);
extern "C" float fn_802bc778(Obj *);
extern "C" void fn_80296378(void *, float, float, float);
extern "C" void fn_80296410(void *, float);
extern char lbl_8041c850[];
extern "C" void *lbl_804b178c;
extern float lbl_803cbf04[];
extern "C" void w3d_d30k_scroll_list_create_8026f528(Box *self) {
 if (self->list) return;
 float h = self->f252;
 Obj *&slot = self->list;
 slot = fn_8020b680(lbl_8041c850);
 fn_80164514(lbl_804b178c, slot, self->f20);
 fn_802bc098(self->list, Ref(self->f284), Ref(self->f112));
 Info *in = self->info;
 float d = h - lbl_803cbf04[0];
 Vec v(in->x - d + 1.0f, in->y - d, 1.0f);
 fn_802bc180(self->list, &v);
 fn_802bcb6c(self->list, in->f124);
 fn_802bcc40(self->list, self->f188);
 fn_802bcbd8(self->list, in->f120);
 ((List *)self->list)->f92 = fn_802b1880(self->text);
 fn_802bcd10(self->list, self->f32);
 fn_802bcd18(self->list, self->f140);
 fn_802bc570(self->list);
 fn_8026fac4(self);
 void *s = self->f292;
 if (s) {
  float n = fn_802bc71c(self->list);
  fn_80296378(s, 0.0f, n, fn_802bc778(self->list));
  fn_80296410(self->f292, 0.0f);
 }
}
