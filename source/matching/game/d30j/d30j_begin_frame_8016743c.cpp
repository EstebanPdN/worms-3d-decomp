// Frame start, in the shape of Nintendo DEMOBeforeRender: swap, flush, optional
// sync token, viewport from the render mode (jittered on field rendering), cache
// invalidation, copy clear colour, then state reset. GWMP8P rev0 0x8016743c.
struct RenderMode { char p0[4]; unsigned short fbWidth; unsigned short efbHeight; char p8[16]; unsigned char field_rendering; };
struct Renderer { char p0[40]; RenderMode *mode; };
struct Colour { unsigned int rgba; };
struct Scene { char p0[40]; Colour clear; };
extern Renderer *lbl_804b1888;
extern char *lbl_804b1884;
extern int lbl_804ab4fc;
extern "C" {
int cc45a_swap_8016eed0(Renderer *);
void w3d_s20_flush_pending_80167094(Scene *);
void fn_803084e0(unsigned int);
void fn_8030ce00();
int fn_80304cac();
void fn_8030c20c(float, float, float, float, float, float, int);
void fn_8030c264(float, float, float, float, float, float);
void fn_80307e14();
void fn_8030a46c();
void fn_80308fc0(Colour *, unsigned int);
void fn_80308be8(int);
void fn_8030bff4(char *, int);
void w3d_k4b_state_reset_80167fe0(Scene *);
int d30j_begin_frame_8016743c(Scene *self) {
  cc45a_swap_8016eed0(lbl_804b1888);
  w3d_s20_flush_pending_80167094(self);
  if (lbl_804ab4fc) { fn_803084e0(0xfeeb); fn_8030ce00(); }
  RenderMode *m = lbl_804b1888->mode;
  if (m->field_rendering)
    fn_8030c20c(0.0f, 0.0f, (float)m->fbWidth, (float)m->efbHeight, 0.0f, 1.0f, fn_80304cac());
  else
    fn_8030c264(0.0f, 0.0f, (float)m->fbWidth, (float)m->efbHeight, 0.0f, 1.0f);
  fn_80307e14();
  fn_8030a46c();
  Colour c = self->clear;
  fn_80308fc0(&c, 0xffffff);
  fn_80308be8(1);
  fn_8030bff4(lbl_804b1884 + 1112, 0);
  w3d_k4b_state_reset_80167fe0(self);
  return 0;
}
}
