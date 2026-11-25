#include "w3d_ptr.h"
#line 1 "d27d_aim_beam_place_80140b24.cpp"
// GWMP8P rev0 0x80140b24. Place the two aiming beam nodes: invert the camera
// view, rotate up by it, then set each handle-looked-up node at the point 15
// above the position plus that axis scaled by 15 or 8 and by the node's
// depth ratio, through its virtual setter. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { return Vec(a.x * k, a.y * k, a.z * k); }
struct Row { float x, y, z, w; };
struct Matrix {
    Row r[4];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
    Vec pos() const { return Vec(r[3].x, r[3].y, r[3].z); }
};
struct Camera { struct Table { char u0[24]; Ptr32<Ptr32<const Matrix> (Ptr32<Camera>)> view; }; Ptr32<struct Table> vt; };
struct Settings { char u0[48]; Ptr32<Camera> camera; };
extern Ptr32<Settings> settings_804b1788;
struct Node { struct Table { char u0[40]; Ptr32<void (Ptr32<Node>, const Vec &)> place; }; Ptr32<struct Table> vt; };
struct Beam { char u0[28]; int a; int b; };
extern "C" int invert_801f6c2c(Ptr32<Matrix>, Ptr32<const Matrix>);
extern "C" Ptr32<Node> lookup_80164fc8(int);
extern "C" float ratio_8011ba08(Ptr32<Node>);
extern "C" void d27d_aim_beam_place_80140b24(Ptr32<Beam> self, const Vec &at) {
    Matrix m;
    Ptr32<Camera> c = settings_804b1788->camera;
    invert_801f6c2c(&m, c->vt->view(c));
    Vec cam = m.pos();
    Ptr32<Node> a = lookup_80164fc8(self->a);
    Ptr32<Node> b = lookup_80164fc8(self->b);
    Vec fw(0.0f, 1.0f, 0.0f);
    float k = 15.0f;
    Vec dir;
    m.rotate(dir, fw);
    Vec p(at.x, at.y + k, at.z);
    float rb = ratio_8011ba08(b);
    Vec e = p + dir * k * rb;
    b->vt->place(b, e);
    float ra = ratio_8011ba08(a);
    Vec e2 = p + dir * 8.0f * ra;
    a->vt->place(a, e2);
}


