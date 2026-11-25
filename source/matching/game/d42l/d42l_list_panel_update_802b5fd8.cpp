// GWMP8P rev0 0x802b5fd8. List panel per-tick update: eases its scroll
// offset and spinner. Partial views. Re-reading the fields in the blend
// gives the PRE copies.
struct Vec { float x, y, z; Vec(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Tracker { char u0[68]; int follow; char u72[20]; float value; };
struct List;
struct Smoother;
struct Ctl;
struct CtlT { char u0[20]; void (*set_active)(Ctl *, int); };
struct Ctl { char u0[164]; int hidden; char u168[12]; CtlT *vt; };
struct View;
struct ViewT { char u0[80]; void (*set_rotation)(View *, const Vec *, int); };
struct View { ViewT *vt; };
struct Panel {
 char u0[28]; Ctl ctl; char u212[32]; int pending; int last; char u252[32];
 List *list; Tracker *tracker; char u292[12];
 float offset; float offset_target; float range; char u316[48];
 View *view; char u368[36]; Smoother *smoother; char u408[4];
 float pos_target; float pos;
};
extern "C" {
void d28l_panel_update_802b0668(Ctl *);
int s11_current_context_802b264c(Ctl *);
void fn_802c0064(Smoother *);
void fn_802b929c(Panel *);
void w3d_auto_802bc790(List *, float);
void w3d_auto_80296410(Tracker *, float);
}
extern "C" int d42l_list_panel_update_802b5fd8(Panel *self, int now)
{
 d28l_panel_update_802b0668(&self->ctl);
 int dt = now - self->last;
 if (dt > 100) dt = 100;
 while (dt >= 20) {
  float step = self->range / 10.0f;
  if (self->pending && s11_current_context_802b264c(&self->ctl)) {
   self->ctl.vt->set_active(&self->ctl, 1);
   self->pending = 0;
  }
  if (self->ctl.hidden == 0) {
   if (self->smoother) fn_802c0064(self->smoother);
   Tracker *t = self->tracker;
   if (t && t->value != self->offset) {
    if (t->follow) {
     self->offset = t->value;
     self->offset_target = t->value;
    } else self->offset_target = t->value;
   }
   if (self->pos != self->pos_target) {
    if (self->pos_target > self->pos) {
     self->pos = self->pos + step;
     if (self->pos_target < self->pos) self->pos = self->pos_target;
    } else {
     self->pos = self->pos - step;
     if (self->pos_target > self->pos) self->pos = self->pos_target;
    }
    fn_802b929c(self);
    Vec v(0.0f, 0.0f, self->pos / self->range * 3.1415927f);
    self->view->vt->set_rotation(self->view, &v, 0);
   }
   if (self->offset_target != self->offset) {
    float d = self->offset_target - self->offset;
    if (d < 0.01f && d > -0.01f) self->offset = self->offset_target;
    else { float k = 0.25f; self->offset = self->offset * 0.75f + self->offset_target * k; }
   }
   if (self->list) w3d_auto_802bc790(self->list, self->offset);
   if (self->tracker) w3d_auto_80296410(self->tracker, self->offset);
  }
  dt -= 20;
 }
 self->last = now - dt;
 return 0;
}
