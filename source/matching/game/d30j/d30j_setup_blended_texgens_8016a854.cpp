// Set up two texture generators for a blended material: apply its attributes,
// then in one of two modes bind both textures, scale and offset coordinate
// generators by the material's scroll values, load an indirect matrix and set
// the shared GX state; with neither mode set, use the plain setup. GWMP8P rev0
// 0x8016a854.
struct Tex { char p0[6]; unsigned short id; };
struct Sub { char p0[24]; int (**table)(Sub *, Tex *); };
struct View { int vt; Sub sub; };
struct Rend { char p0[116]; void *attrs; char p78[96]; int p216; };
struct Attr { char p0[24]; int count; char p1c[4]; char data[1]; };
struct Mat { char p0[28]; float rate; float amount; char p24[12]; Attr *attr; char p34[4]; Tex *tex2; char p3c[8]; Tex *tex1; int mode1; int mode2; float u, v; };
extern char *lbl_804b1884;
extern "C" {
int w3d_d27e_apply_attributes_801a2bf4(void *, char *, int);
void d19d_texgen_scale_offset_8016c130(Rend *, int, int, float, float, float);
void fn_8030aab8(int, float *, int);
void fn_8030ad74(int, int, int);
void fn_8030ac30(int, int, int);
void fn_8030aecc(int, int, int, int, int);
void fn_8030ae60(int);
void fn_803080a4(int);
void fn_8030b648(int);
void w3d_auto_8016803c(char *, int);
void w3d_auto_8016c1f4(Rend *);
inline void set_blend_state() {
  fn_8030ad74(0, 1, 1);
  fn_8030ac30(0, 0, 0);
  fn_8030aecc(0, 0, 1, 0, 1);
  fn_8030ae60(1);
  fn_803080a4(2);
  fn_8030b648(1);
  w3d_auto_8016803c(lbl_804b1884, 128);
}
int d30j_setup_blended_texgens_8016a854(char *arg, Mat *m) {
  Rend *self = arg ? (Rend *)(arg - 4) : 0;
  Attr *at = m->attr;
  Tex *t1 = m->tex1;
  Tex *t2 = m->tex2;
  w3d_d27e_apply_attributes_801a2bf4(self->attrs, at->data, at->count);
  self->p216 = 0;
  if (m->mode1) {
    Sub *s = (Sub *)((char *)self + 4);
    s->table[t1->id](s, t1);
    const float k = 0.5f;
    d19d_texgen_scale_offset_8016c130(self, 0, 4, 0.07f, m->u * k, m->v * k);
    s->table[t2->id](s, t2);
    float a[6];
    a[0] = k; a[1] = k; a[2] = 0.0f; a[3] = k; a[4] = k; a[5] = 0.0f;
    fn_8030aab8(1, a, 1);
    d19d_texgen_scale_offset_8016c130(self, 1, 4, 0.2f, -m->v * 0.1f, -m->u * 0.1f);
    set_blend_state();
  } else if (m->mode2) {
    Sub *s = (Sub *)((char *)self + 4);
    s->table[t1->id](s, t1);
    float g = m->amount;
    d19d_texgen_scale_offset_8016c130(self, 0, 4, g, m->u * g * 0.9f, m->v * g * 0.9f);
    s->table[t2->id](s, t2);
    float a[6];
    a[0] = 0.5f; a[1] = 0.5f; a[2] = 0.0f; a[3] = 0.5f; a[4] = 0.5f; a[5] = 0.0f;
    fn_8030aab8(1, a, 1);
    float r = m->rate;
    float q = r * 0.2f;
    d19d_texgen_scale_offset_8016c130(self, 1, 4, r, -m->v * q, -m->u * q);
    set_blend_state();
  } else {
    w3d_auto_8016c1f4(self);
    fn_8030b648(1);
  }
  return 0;
}
}
