// Select the GX vertex format. On a change of format or lighting mode, describe
// every attribute (position, normal, colour, texture) with its fraction bits and
// index mode, and set the material colour and lighting channels; otherwise
// refresh only the per-material fraction bits and colours. Finally apply the
// render state. GWMP8P rev0 0x8016797c.
struct GXColor { unsigned char r, g, b, a; };
struct Mat { char p0[180]; int flags; char pb8[24]; GXColor colour; char pd4[80]; int stages; char p128[20]; unsigned char frac[3]; };
struct Ctx { char p0[232]; int fmt; int caps; int stages; char pf4[8]; int mode; };
extern GXColor lbl_804ab500;
extern "C" {
void fn_80307558();
void fn_80307590(int, int, int, int, int);
void fn_80306cd0(int, int);
void fn_8030972c(int, GXColor);
void fn_8030981c(int, GXColor);
void w3d_auto_8016803c(Ctx *, int);
void w3d_auto_8016804c(Ctx *, int);
void s9_apply_render_state_80167dd4(Ctx *, char *);
void d30j_set_vertex_format_8016797c(Ctx *self, int fmt, int mode, char *arg) {
  Mat *mat = arg ? (Mat *)(arg - 4) : 0;
  int changed = 0;
  if (self->fmt != fmt || self->mode != mode) changed = 1;
  else {
    if (mode == 4) goto textured;
    if (mode != 5) goto ready;
  textured:
    if (mat == 0) return;
    changed = 1;
  }
ready:
  if (changed) {
    int t0 = 1, t1 = 1, t2 = 1, t3 = 1;
    self->fmt = fmt;
    self->mode = mode;
    if (mode == 5) {
      int fl = mat->flags;
      if (fl < 0) mode = 4;
      else if (fl & 0x40000000) mode = 3;
      else mode = 2;
    }
    if (mode == 2) { t3 = 3; t2 = 3; t1 = 3; t0 = 3; }
    else if (mode == 3) { t3 = 2; t2 = 2; t1 = 2; t0 = 2; }
    else if (mode == 4) {
      self->stages = mat->stages;
      int s = mat->stages;
      t0 = 3; if (s & 2) t0 = 2;
      t1 = 3; if (s & 16) t1 = 2;
      t2 = 3; if (s & 64) t2 = 2;
      t3 = (s & 256) ? 2 : 3;
    }
    fn_80307558();
    if (fmt & 1) { fn_80307590(0, 9, 1, 4, 0); fn_80306cd0(9, t0); }
    else if (fmt & 2) { fn_80307590(0, 9, 1, 3, mat->frac[0]); fn_80306cd0(9, t0); }
    if (fmt & 4) { fn_80307590(0, 10, 0, 4, 0); fn_80306cd0(10, t1); }
    else if (fmt & 8) { fn_80307590(0, 10, 0, 3, mat->frac[1]); fn_80306cd0(10, t1); }
    if (fmt & 64) {
      if (!(self->caps & 4)) { fn_8030972c(4, mat->colour); fn_8030981c(4, mat->colour); }
      else fn_8030981c(4, lbl_804ab500);
      w3d_auto_8016803c(self, 16);
      w3d_auto_8016804c(self, 8);
    } else if (fmt & 16) {
      fn_80307590(0, 11, 1, 5, 0); fn_80306cd0(11, t2);
      w3d_auto_8016803c(self, 8);
      w3d_auto_8016804c(self, 16);
    } else if (fmt & 32) {
      fn_80307590(0, 11, 1, 3, 0); fn_80306cd0(11, t2);
      w3d_auto_8016803c(self, 8);
      w3d_auto_8016804c(self, 16);
    } else {
      if (!(self->caps & 4)) fn_8030972c(4, lbl_804ab500);
      fn_8030981c(4, lbl_804ab500);
      w3d_auto_8016804c(self, 8);
      w3d_auto_8016804c(self, 16);
    }
    if (fmt & 128) { fn_80307590(0, 13, 1, 4, 0); fn_80306cd0(13, t3); }
    else if (fmt & 256) { fn_80307590(0, 13, 1, 3, mat->frac[2]); fn_80306cd0(13, t3); }
  } else {
    if (fmt & 2) fn_80307590(0, 9, 1, 3, mat->frac[0]);
    if (fmt & 8) fn_80307590(0, 10, 0, 3, mat->frac[1]);
    if (fmt & 64) {
      if (!(self->caps & 4)) fn_8030972c(4, mat->colour);
      fn_8030981c(4, mat->colour);
    } else if (!(self->caps & 8)) {
      if (!(self->caps & 4)) fn_8030972c(4, lbl_804ab500);
      fn_8030981c(4, lbl_804ab500);
    }
    if (fmt & 256) fn_80307590(0, 13, 1, 3, mat->frac[2]);
  }
  s9_apply_render_state_80167dd4(self, arg);
}
}
