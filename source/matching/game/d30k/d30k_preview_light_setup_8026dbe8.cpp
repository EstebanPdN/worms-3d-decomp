// GWMP8P rev0 0x8026dbe8. Sets up a preview scene: finds the root nodes,
// places them, creates a light object with black, white and a normalised
// (1,-1,0) direction, registers it as PreviewLight and attaches it to the
// model instance. Names are inferred from use. Owns the three literals at
// 0x803cbd90. Built with -mps-float: frame gap only without it.
struct Vec {
 float x, y, z;
 Vec() {}
 Vec(float a, float b, float c) { Vec *p = this; x = a; p->y = b; p->z = c; }
};
extern "C" float fn_802e82c0(float);
struct Text { char *p; Text(const char *); Text(const Text &); ~Text(); };
extern "C" void fn_8020c5c4(Text *);
extern "C" void fn_80341588(Text *);
inline Text::~Text() { fn_8020c5c4(this); fn_80341588(this); }
struct Node;
struct NodeVt { void *u[19]; void (*set_pos)(Node *, const Vec *, int); void *u80; void (*set_rot)(Node *, const Vec *, int); void (*a88)(Node *, int); void (*attach)(Node *, Node *, int); };
struct Node { NodeVt *vt; };
struct Light { char u[108]; Vec dir, col, amb; int on; char u148[8]; Vec v156; };
inline void Put(Vec &d, const Vec &v) { d = v; }
struct Host; struct HostVt { void *u[48]; void (*add)(Host *, const char *, int, int, Light *); };
struct Host { HostVt *vt; };
struct Service { char u[116]; Host *host; };
extern "C" int fn_8015adf4(const Text &, Node **, int);
extern "C" Light *fn_8020b680(void *);
extern "C" void *fn_80343584(Node *);
extern "C" int fn_80182408();
extern "C" int fn_80182410(void *, Light *);
struct Engine { char u[52]; int f52; };
extern "C" Engine *fn_80165254();
extern char lbl_803cbd84[], lbl_803cbd18[], lbl_80414a90[];
struct ServiceHolder { Service *p; };
extern ServiceHolder lbl_804b17ec;
struct Preview { char u[32]; Vec f32; Vec f44; char u56[16]; Node *f72; Node *f76; char u80[4]; int f84; };
extern "C" void w3d_d30k_preview_light_setup_8026dbe8(Preview *self) {
 fn_8015adf4(Text(lbl_803cbd84), &self->f76, 255);
 fn_8015adf4(Text(lbl_803cbd84), &self->f72, 255);
 self->f76->vt->set_pos(self->f76, &self->f32, 0);
 self->f76->vt->set_rot(self->f76, &self->f44, 0);
 Vec v(0.0f, 0.0f, 0.0f);
 self->f72->vt->set_pos(self->f72, &v, 0);
 self->f72->vt->a88(self->f72, 0);
 self->f76->vt->a88(self->f76, 0);
 self->f76->vt->attach(self->f76, self->f72, 0);
 Light *o = fn_8020b680(lbl_80414a90);
 Vec a(0.0f, 0.0f, 0.0f);
 Vec b(1.0f, 1.0f, 1.0f);
 Vec c(1.0f, -1.0f, 0.0f);
 float k = 1.0f / fn_802e82c0(c.z * c.z + (c.x * c.x + c.y * c.y));
 c.x *= k; c.y *= k; c.z *= k;
 o->on = 1;
 Put(o->amb, a);
 Put(o->dir, a);
 Put(o->col, b);
 Put(o->v156, c);
 { Host *h = lbl_804b17ec.p->host; h->vt->add(h, lbl_803cbd18, 4, 0, o); }
 void *inst = fn_80343584(self->f72);
 fn_80182408();
 fn_80182410(inst, o);
 self->f84 = fn_80165254()->f52;
}
