// GWMP8P rev0 0x802b8430. Creates the panel scroller object once its owner
// handle is set. Store through the slot reference reproduces the original's
// register choice for the new object.
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Obj;
struct ObjVt { void *s0[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct ObjRef { Obj *value; ObjRef(const ObjRef &o) : value(o.value) { if (value) value->vt->retain(value); } };
struct Bar { char pad[92]; float a92; };
struct Box;
struct Data { char pad[20]; float a20; char pad24[112]; float a136; char pad140[4]; int a144; };
struct TL { char pad0[20]; int a20; char pad24[4]; char a28[4]; int a32; char pad36[4]; Data *data; char pad44[68]; ObjRef a112; char pad116[72]; int a188; char pad192[28]; float a220; char pad224[56]; ObjRef a280; Bar *bar; Box *box; char pad292[4]; int a296; char pad300[108]; int a408; char pad412[4]; float a416; };
extern "C" Bar *w3d_new_box_8020b680(void *);
extern unsigned char lbl_8041c850[];
extern Bar *lbl_804b178c;
extern int lbl_804abb4c;
extern float lbl_803d80b0[];
extern float lbl_803d80c0[];
extern "C" int fn_80164514(Bar *, Bar *, int);
extern "C" void w3d_paired_802bc098(Bar *, ObjRef, ObjRef);
extern "C" void w3d_set_position_802bc180(Bar *, const Vec &);
extern "C" void w3d_set_802bcd10(Bar *, int), w3d_set_802bcb6c(Bar *, int), w3d_set_802bcc40(Bar *, int), w3d_clamp_802bcbd8(Bar *, float);
extern "C" float tsonnet_c31_text_size_802b1880(void *);
extern "C" void w3d_auto_802bc570(Bar *), d24f_select_item_802bc8b4(Bar *, int);
extern "C" void w3d_panel_activity_802b879c(TL *);
extern "C" unsigned w3d_nested_802bc71c(Bar *);
extern "C" float w3d_auto_802bc778(Bar *);
extern "C" void w3d_auto_80296378(Box *, float, float, float), w3d_auto_80296410(Box *, float);
extern "C" void d25l_panel_scroller_create_802b8430(TL *self)
{
 if (self->a280.value == 0 || self->bar) return;
 float h = self->a220;
 Bar *b = w3d_new_box_8020b680(lbl_8041c850); Bar *&slot = self->bar; slot = b; fn_80164514(lbl_804b178c, b, self->a20);
 w3d_paired_802bc098(self->bar, self->a280, self->a112);
 Data *d = self->data;
 Vec v;
 Vec *p = &v;
 p->x = d->a20 - h; v.y = self->a416; p->z = *lbl_803d80b0;
 w3d_set_position_802bc180(self->bar, v);
 w3d_set_802bcd10(self->bar, self->a32 + 5);
 w3d_set_802bcb6c(self->bar, d->a144);
 w3d_set_802bcc40(self->bar, self->a188);
 w3d_clamp_802bcbd8(self->bar, d->a136);
 self->bar->a92 = tsonnet_c31_text_size_802b1880(self->a28);
 w3d_auto_802bc570(self->bar);
 d24f_select_item_802bc8b4(self->bar, self->a296);
 w3d_panel_activity_802b879c(self);
 Box *box = self->box;
 if (box) {
  float t = w3d_nested_802bc71c(self->bar);
  float u = w3d_auto_802bc778(self->bar);
  w3d_auto_80296378(box, *lbl_803d80c0, t, u);
  w3d_auto_80296410(self->box, *(float *)((char *)self->bar + 68));
 }
 lbl_804abb4c = 1;
 self->a408 = 1;
}
