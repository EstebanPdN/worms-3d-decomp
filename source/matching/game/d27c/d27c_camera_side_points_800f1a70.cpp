// d27c: 0x800f1a70. Places two targets 5 units either side of the camera's world position, taken from the inverted view matrix. Names are inferred; Mat is a partial view.
struct Vec3 { float x, y, z; Vec3() {} Vec3(float a, float b, float c) { x = a; y = b; z = c; } Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Mat { float m[12]; Vec3 pos; float w; const Vec3 &P() const { return pos; } };
struct Cam { struct V { void *u[6]; const Mat *(*matrix)(Cam *); } *vtable; };
struct Svc { char u[48]; Cam *cam; };
struct Lit { struct V { void *u[14]; void (*set)(Lit *, int, Vec3 *); } *vtable; };
struct Self { char u[28]; Lit *a; Lit *b; };
extern Svc *svc_804b1788;
extern "C" int norm_801f6c2c(Mat *, const Mat *);
extern "C" void d27c_camera_side_points_800f1a70(Self *self) {
    Vec3 v;
    Vec3 &p = v;
    Mat m;
    norm_801f6c2c(&m, svc_804b1788->cam->vtable->matrix(svc_804b1788->cam));
    p.x = m.pos.x; p.y = m.pos.y; p.z = m.pos.z;
    float d = 5.0f;
    Vec3 a(p.x + d, p.y, p.z);
    self->a->vtable->set(self->a, 3, &a);
    Vec3 b(p); b.x -= d;
    self->b->vtable->set(self->b, 3, &b);
}
