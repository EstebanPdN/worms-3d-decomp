// GWMP8P rev0 0x8003c3bc. Moves the marker across two scene cameras: takes
// the world and projection matrices of the two cameras at +48 and +132 of
// the scene, carries the position through the first camera, applies the
// marker screen projection 0x8003cac8, and carries the result back through
// the inverse matrices of the second camera, placing the marker node at it.
// Names are inferred from the matrix use.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Point { float x, y, z; Point(); };
struct Row { float x, y, z; };
struct Mtx44 { float m[16]; };
struct Rows { Row r[3]; };
struct Mat {
    Rows r; Point p;
    Mat() {}
    const Row &R(int i) const { return r.r[i]; }
    const Point &P() const { return p; }
    void Transform(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
extern "C" void w3d_k5b_mtx34_from_mtx44_801f74d0(Mat *, const Mtx44 *);
extern "C" int w3d_auto_801f76e0(Mat *, const Mat *);
struct Camera;
struct CameraTable { char pad[24]; const Mtx44 *(*a)(Camera *); char pad2[4]; const Mtx44 *(*b)(Camera *); };
struct Camera { CameraTable *t; };
struct Scene { char pad[48]; Camera *view; char pad2[80]; Camera *other; };
extern Scene *lbl_804b1788;
struct Node;
struct NodeTable { char pad[76]; int (*set_pos)(Node *, const Vec *, int); };
struct Node { NodeTable *t; };
struct Self { char pad[28]; Node *node; };
extern "C" Vec w3d_d30a_marker_screen_project_8003cac8(Self *, Vec);
extern "C" void w3d_d42a_marker_view_transfer_8003c3bc(Self *self, const Vec *pos)
{
    Mtx44 m0 = *lbl_804b1788->view->t->a(lbl_804b1788->view);
    Mtx44 m1 = *lbl_804b1788->view->t->b(lbl_804b1788->view);
    Mtx44 m2 = *lbl_804b1788->other->t->a(lbl_804b1788->other);
    Mtx44 m3 = *lbl_804b1788->other->t->b(lbl_804b1788->other);
    Mat a, b, c, d, e, f;
    w3d_k5b_mtx34_from_mtx44_801f74d0(&a, &m0);
    w3d_k5b_mtx34_from_mtx44_801f74d0(&b, &m1);
    w3d_k5b_mtx34_from_mtx44_801f74d0(&c, &m2);
    w3d_k5b_mtx34_from_mtx44_801f74d0(&d, &m3);
    w3d_auto_801f76e0(&e, &c);
    w3d_auto_801f76e0(&f, &d);
    Vec v, s, w;
    a.Transform(v, *pos);
    b.Transform(s, v);
    s = w3d_d30a_marker_screen_project_8003cac8(self, s);
    f.Transform(v, s);
    e.Transform(w, v);
    self->node->t->set_pos(self->node, &w, 0);
}
