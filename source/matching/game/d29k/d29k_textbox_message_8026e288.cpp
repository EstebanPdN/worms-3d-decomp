// GWMP8P rev0 0x8026e288. Text box control message handler: setup, reset,
// and when the context is current and unlocked, the pointer, step and
// activate message ids, then the sub-object and base handlers. Names are
// inferred from use. Built with -mps-float: frame gap only without it.
struct Msg { unsigned short id; };
struct Cache { int a, b; };
struct Ctl;
struct CtlVt { char pad[52]; void (*activate)(Ctl *, int); };
struct Text { char pad[80]; const char *t80; const char *t84; const char *t88; };
struct Ctl { int current_802b264c(); void forward_802aff9c(Msg *); int on() { return f152 == 1 ? f156 : f148; }
 char pad1[12]; Text *text; char pad2[84]; int locked; char pad3[8]; int f140; char pad4[32]; int f148, f152, f156, f160; char pad6[16]; CtlVt *vt; };
struct Box {
 char pad0[28]; Ctl ctl;
 char pad7[44]; int f256, f260; char pad8[24]; void *list; char pad9[4]; int f296; int cur; int slot;
};
extern "C" int fn_8015fb34(Box *, Msg *);
extern "C" void fn_8026e98c(Box *);
extern "C" void fn_8026ec30(Box *);
extern "C" int fn_8015f65c(unsigned short, const void *);
extern "C" void fn_80069a50(Msg *, float *, float *);
extern "C" int fn_8026f820(Box *, int *, int *, float, float);
extern "C" void fn_8026f948(Box *, int, int);
extern "C" void fn_802bc8b4(void *, int);
extern "C" unsigned fn_802bc71c(void *);
extern "C" void fn_8026fc98(Box *, int);
extern "C" int fn_80270300(Box *);
extern "C" void fn_8010a904(Msg *, const char **, const char **);
extern "C" int strcmp(const char *, const char *);
extern "C" int atol(const char *);
extern "C" int lbl_804abb48;
extern "C" Cache lbl_804b0ae0, lbl_804b0b18, lbl_804b0ae8, lbl_804b0af0, lbl_804b0af8, lbl_804b0b00, lbl_804b0b08, lbl_804b0b20, lbl_804b0b10;
static inline unsigned short len(const char *t) { return *(const unsigned short *)(t - 4); }
extern "C" int w3d_d29k_textbox_message_8026e288(Box *self, Msg *m) {
 switch (m->id) {
  case 64:
   if (fn_8015fb34(self, m) >= 0) {
    fn_8026e98c(self);
    return 0;
   }
   return 0x80004005;
  case 66:
   fn_8026ec30(self);
   return fn_8015fb34(self, m);
 }
 {
  if (!self->ctl.current_802b264c()) return fn_8015fb34(self, m);
  if (!lbl_804abb48 && !self->ctl.locked) {
   int r;
   if (fn_8015f65c(m->id, &lbl_804b0ae0)) {
    if (self->f296 == 1 && self->ctl.f160 == 1) {
     float x, y; int a, b;
     fn_80069a50(m, &x, &y);
     if (fn_8026f820(self, &a, &b, x, y) == 1 && a != -1) {
      fn_8026f948(self, b, 0);
      fn_802bc8b4(self->list, b);
      self->cur = b;
      self->slot = a;
     }
    }
   } else if ((r = fn_8015f65c(m->id, &lbl_804b0b18))) {
    if (self->f296 == 1) {
     if (self->ctl.f160 == 1) {
      float x, y; int a, b;
      fn_80069a50(m, &x, &y);
      if (fn_8026f820(self, &a, &b, x, y) == 1) {
       if (a != -1) {
        fn_8026f948(self, b, 0);
        fn_802bc8b4(self->list, b);
        self->cur = b;
        self->slot = a;
        fn_8026fc98(self, 1);
       }
       return 0;
      }
     } else {
      float x, y; int a, b;
      fn_80069a50(m, &x, &y);
      if (fn_8026f820(self, &a, &b, x, y) != 1) return 0;
      if (!self->ctl.on()) return 0;
      if (!self->ctl.f140) return 0;
      self->ctl.vt->activate(&self->ctl, 1);
      if (a != -1) {
       fn_8026f948(self, b, 0);
       fn_802bc8b4(self->list, b);
       self->cur = b;
       self->slot = a;
      }
      return 0;
     }
    }
   } else if (fn_8015f65c(m->id, &lbl_804b0ae8) && self->f296 == 1 && self->ctl.f148 == 1 && self->ctl.f160 == 1) {
    if (--self->cur < 0) self->cur = 0;
    self->f260 = 0;
    self->f256 = 2000;
    fn_8026f948(self, self->cur, 0);
    fn_802bc8b4(self->list, self->cur);
    self->slot = -1;
    return fn_8015fb34(self, m);
   } else if (fn_8015f65c(m->id, &lbl_804b0af0) && self->f296 == 1 && self->ctl.f148 == 1 && self->ctl.f160 == 1) {
    float v = ++self->cur;
    if (v >= (float)fn_802bc71c(self->list)) self->cur = fn_802bc71c(self->list) - 1;
    if (self->cur < 0) self->cur = 0;
    self->f260 = 2000;
    self->f256 = 0;
    fn_8026f948(self, self->cur, 0);
    fn_802bc8b4(self->list, self->cur);
    self->slot = -1;
    return fn_8015fb34(self, m);
   } else if (fn_8015f65c(m->id, &lbl_804b0af8) && self->f296 == 1 && self->ctl.f148 == 1) {
    if (!self->ctl.f140) return 0;
    if (self->ctl.f160 == 1) {
     if (self->cur != -1) { fn_8026fc98(self, 1); return 0; }
    } else {
     self->ctl.vt->activate(&self->ctl, 1);
     return 0;
    }
   } else if (fn_8015f65c(m->id, &lbl_804b0b00) && self->f296 == 1 && self->ctl.f148 == 1 && self->ctl.f160 == 1) {
    if (fn_80270300(self)) self->ctl.vt->activate(&self->ctl, 0);
    else return 0;
   } else if (fn_8015f65c(m->id, &lbl_804b0b08) && self->ctl.f160 == 1) {
    if (!len(self->ctl.text->t84)) return fn_8015fb34(self, m);
    self->ctl.vt->activate(&self->ctl, 0);
   } else if (fn_8015f65c(m->id, &lbl_804b0b20) && self->ctl.f160 == 0) {
    const char *name, *value;
    fn_8010a904(m, &name, &value);
    if (!strcmp(self->ctl.text->t88, name)) fn_8026f948(self, atol(value), 0);
   } else if (fn_8015f65c(m->id, &lbl_804b0b10) && self->ctl.f160 == 1) {
    if (!len(self->ctl.text->t80)) return fn_8015fb34(self, m);
    self->ctl.vt->activate(&self->ctl, 0);
   }
  }
  self->ctl.forward_802aff9c(m);
 }
 return fn_8015fb34(self, m);
}
