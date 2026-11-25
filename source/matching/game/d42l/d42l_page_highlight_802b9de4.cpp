// GWMP8P rev0 0x802b9de4. Lights the selected page's parts and sets their
// brightness. Self, Part, Mesh and Bar are partial views. The real-class
// Held array is inferred from the add-then-load element reads.
struct Colour {
 unsigned char r, g, b, a;
 Colour(unsigned char x, unsigned char y, unsigned char z, unsigned char w) { r = x; g = y; b = z; a = w; }
};
struct Part;
struct PartT { void *s0[22]; void (*show)(Part *, int); };
struct Part { PartT *vt; };
struct Mesh;
struct Bar;
struct Held {
 Part *p;
 Held();
 Held(const Held &);
 ~Held();
 operator Part *() const { return p; }
};
struct Self {
 char u0[140]; int alt; char u144[32]; int active; char u180[44];
 Mesh *mesh[3]; char u236[52]; Bar *bar; char u292[32];
 Held a[3]; Held b[3]; Held c[3]; char u360[4]; Held d; Held e; char u372[4];
 Held x[2]; Held y[2]; Held z[2];
};
extern "C" void *memset(void *, int, unsigned, ...);
extern "C" void w3d_auto_8025f064(Mesh *, int);
extern "C" void w3d_d30k_mesh_fill_colour_8025eed0(Mesh *, const Colour *);
extern "C" int d26j_set_colour_80173df0(Part *, const Colour *);
extern "C" void w3d_auto_8029677c(Bar *, int);
inline void Zero(void *p, unsigned n) { memset(p, 0, n); }
// Lights the page selected by mode and applies the matching brightness.
extern "C" void d42l_page_highlight_802b9de4(Self *self)
{
 unsigned char v = 255;
 if (self->alt == 0) v = 128;
 Colour col(v, v, v, 255);
 int sel[3];
 Zero(sel, 12);
 if (self->active) sel[1] = 1;
 else if (self->alt == 0) sel[2] = 1;
 else sel[0] = 1;
 for (unsigned i = 0; i < 3; i++) {
  if (self->mesh[i]) w3d_auto_8025f064(self->mesh[i], sel[i]);
  if (self->a[i]) { Part *p = self->a[i]; p->vt->show(p, sel[i]); }
  if (self->b[i]) { Part *p = self->b[i]; p->vt->show(p, sel[i]); }
  if (self->c[i]) { Part *p = self->c[i]; p->vt->show(p, sel[i]); }
 }
 if (self->d) { Part *p = self->d; p->vt->show(p, self->alt); }
 if (self->e) { Part *p = self->e; p->vt->show(p, self->alt ^ 1); }
 for (unsigned j = 0; j < 2; j++) {
  if (self->mesh[j]) w3d_d30k_mesh_fill_colour_8025eed0(self->mesh[j], &col);
  if (self->a[j]) d26j_set_colour_80173df0(self->a[j], &col);
  if (self->b[j]) d26j_set_colour_80173df0(self->b[j], &col);
  if (self->c[j]) d26j_set_colour_80173df0(self->c[j], &col);
  if (self->x[j]) d26j_set_colour_80173df0(self->x[j], &col);
  if (self->y[j]) d26j_set_colour_80173df0(self->y[j], &col);
  if (self->z[j]) d26j_set_colour_80173df0(self->z[j], &col);
 }
 if (self->bar) w3d_auto_8029677c(self->bar, self->alt);
}
