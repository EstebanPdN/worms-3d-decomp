#include "w3d_ptr.h"
#line 1 "d25l_create_scroll_bar_box_802b85f4.cpp"
// GWMP8P rev0 0x802b85f4. Creates a box for a scrolling list when its
// content exceeds the available size. The slot reference is the store form
// that reproduces the original's register choice for the new box.
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Obj;
struct ObjVt { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct ObjRef { Ptr32<Obj> value; ObjRef(const ObjRef &o) : value(o.value) { if (value) value->vt->retain(value); } };
struct Box { char pad[216]; int a216; };
struct Data { char pad[20]; float a20; float a24; char pad28[120]; int a148; char pad152[24]; int a176; };
struct Sub { char pad[68]; float a68; };
struct TL { char pad0[20]; int a20; char pad24[4]; int a28; int a32; char pad36[4]; Ptr32<Data> data; char pad44[68]; ObjRef a112; char pad116[24]; int a140; char pad144[32]; int a176; char pad180[40]; float a220; char pad224[60]; Ptr32<Sub> a284; Ptr32<Box> box; char pad292[124]; float a416; };
extern "C" float w3d_s4_box_border_thickness_802966f8(Ptr32<TL>);
extern "C" Ptr32<Box> w3d_new_box_8020b680(Ptr32<void>);
extern unsigned char lbl_8041c220[];
extern Ptr32<Box> lbl_804b178c;
extern "C" int fn_80164514(Ptr32<Box>, Ptr32<Box>, int);
extern "C" void fn_80296774(Ptr32<Box>, int);
extern "C" void fn_8029550c(Ptr32<Box>, float);
extern "C" void fn_80295468(Ptr32<Box>, Vec);
extern "C" void fn_80296298(Ptr32<Box>, int), fn_8029623c(Ptr32<Box>, int), fn_80296518(Ptr32<Box>, int), fn_8029677c(Ptr32<Box>, int), fn_80296410(Ptr32<Box>, float);
extern "C" void fn_80295268(Ptr32<Box>, ObjRef);
extern float lbl_803d80c4[];
extern "C" void d25l_create_scroll_bar_box_802b85f4(Ptr32<TL> self)
{
 float t = w3d_s4_box_border_thickness_802966f8(self);
 if (self->box == 0 && t < self->a416 + self->a416) {
 Ptr32<Data> d = self->data;
 float h = self->a220;
 Ptr32<Box> b = w3d_new_box_8020b680(lbl_8041c220); Ptr32<Box> &slot = self->box; slot = b; fn_80164514(lbl_804b178c, b, self->a20);
 fn_80296774(self->box, self->a32 + 5);
 self->box->a216 = self->a28;
 fn_8029550c(self->box, self->a416 + self->a416);
 Vec v;
 Ptr32<Vec> p = &v;
float xx = d->a20 - h; float yy = *lbl_803d80c4 - d->a24; yy -= self->a416;  p->x = xx; p->y = yy; p->z = *lbl_803d80c4;
 fn_80295468(self->box, v);
 fn_80296298(self->box, d->a176);
 fn_8029623c(self->box, d->a148);
 fn_80296518(self->box, self->a176);
 fn_8029677c(self->box, self->a140);
 fn_80296410(self->box, self->a284->a68);
 fn_80295268(self->box, self->a112);
 }
}


