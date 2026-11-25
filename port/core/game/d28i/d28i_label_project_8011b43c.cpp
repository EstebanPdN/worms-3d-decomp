#include "w3d_ptr.h"
#line 1 "d28i_label_project_8011b43c.cpp"
// GWMP8P rev0 0x8011b43c. Projects the object's anchor through the world and
// HUD camera matrices and places its two graphics at the projected point.
struct Vec { float x, y, z; };
struct Mat4 { float m[16]; };
struct Pos { float x, y, z; Pos(); };
struct Row { float x, y, z; };
struct Mtx34 {
    Row r0, r1, r2; Pos p;
    const Row &R(int i) const { return (&r0)[i]; }
    const Pos &P() const { return p; }
    void xf(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Box { Vec lo; float u12; Vec hi; };
struct Graphic;
struct GraphicVt { char u0[76]; Ptr32<void (Ptr32<Graphic>, Ptr32<const Vec>, int)> setPos; char u80[4]; Ptr32<void (Ptr32<Graphic>, Ptr32<const Box>, int)> setBox; };
struct Graphic { Ptr32<GraphicVt> vt; };
struct Cam;
struct CamVt { char u0[24]; Ptr32<Ptr32<const Mat4> (Ptr32<Cam>)> view; char u28[4]; Ptr32<Ptr32<const Mat4> (Ptr32<Cam>)> proj; };
struct Cam { Ptr32<CamVt> vt; };
struct Globals { char u0[48]; Ptr32<Cam> world; char u52[80]; Ptr32<Cam> hud; };
struct Label { char u0[28]; Ptr32<Graphic> back; Ptr32<Graphic> front; char u36[16]; Vec anchor; };
extern Ptr32<Globals> globals_804b1788;
extern "C" void fromMat4_801f74d0(Ptr32<Mtx34>, Ptr32<const Mat4>);
extern "C" int invert_801f76e0(Ptr32<Mtx34>, Ptr32<const Mtx34>);
extern "C" float depth_8011ba08(Ptr32<Label>);
extern "C" void backing_8011bc28(Ptr32<Label>);
inline Ptr32<const Box> fill(Box &b, float k) { b.hi.x = k; b.hi.y = k; b.hi.z = k; b.lo.x = k; b.lo.y = k; b.lo.z = k; return &b; }
extern "C" void d28i_label_project_8011b43c(Ptr32<Label> self) {
    Mat4 m0 = *globals_804b1788->world->vt->view(globals_804b1788->world);
    Mat4 m1 = *globals_804b1788->world->vt->proj(globals_804b1788->world);
    Mat4 m2 = *globals_804b1788->hud->vt->view(globals_804b1788->hud);
    Mat4 m3 = *globals_804b1788->hud->vt->proj(globals_804b1788->hud);
    Mtx34 a, b, c, d, e, f;
    fromMat4_801f74d0(&a, &m0);
    fromMat4_801f74d0(&b, &m1);
    fromMat4_801f74d0(&c, &m2);
    fromMat4_801f74d0(&d, &m3);
    invert_801f76e0(&e, &c);
    invert_801f76e0(&f, &d);
    Vec v, w, t;
    a.xf(v, self->anchor);
    b.xf(w, v);
    f.xf(v, w);
    e.xf(t, v);
    self->front->vt->setPos(self->front, &t, 0);
    t.x *= 0.99f;
    t.y *= 0.99f;
    t.z = t.z * 0.99f + 5.0f;
    self->back->vt->setPos(self->back, &t, 0);
    float s = depth_8011ba08(self);
    Vec u; u.x = s; u.y = s; u.z = s;
    float k = s * 5.0f;
    Box box;
    self->back->vt->setBox(self->back, fill(box, k), 0);
    backing_8011bc28(self);
}


