// d32i: 0x80121330. Tests whether a world point is visible: transforms it
// through the camera view and scene projection and checks the clip range.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Matrix { float m[4][4]; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &A(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void from(const Matrix &);
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x + P().x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y + P().y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z + P().z;
    }
};
extern "C" void d18d_camera_view_matrix_8015aa04(void *, Matrix &);
extern "C" void w3d_k5b_mtx34_from_801f74d0(Transform *, const Matrix &);
struct Scene { char u0[328]; char camera[544]; Matrix projection; };
extern Scene *scene_804aa8c8;
inline void Get(void *cam, Matrix &m) { d18d_camera_view_matrix_8015aa04(cam, m); }
extern "C" int d32i_point_on_screen_80121330(const Vec &p) {
    Matrix proj = scene_804aa8c8->projection;
    Matrix view;
    Get(scene_804aa8c8->camera, view);
    Transform tv, tp;
    w3d_k5b_mtx34_from_801f74d0(&tv, view);
    w3d_k5b_mtx34_from_801f74d0(&tp, proj);
    int visible = 0;
    Vec e;
    tv.apply(e, p);
    Vec c;
    tp.apply(c, e);
    float x = c.x / c.z;
    float y = c.y / c.z;
    if (x >= -1.0f && y >= -1.0f && x <= 1.0f && y <= 1.0f && c.z > 0.0f) visible = 1;
    return visible;
}
