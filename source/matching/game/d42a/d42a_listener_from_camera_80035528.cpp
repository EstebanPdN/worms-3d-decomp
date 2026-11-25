// GWMP8P rev0 0x80035528. Updates the 3D audio listener from the scene
// camera: inverts the camera matrix at slot 24, takes the inverse's
// translation as the listener position, rotates the forward and up axes by
// it, and passes position, axes and a zero velocity to the listener at +112
// of the scene when one exists. Names are inferred from the matrix use and
// virtual slots; the listener reading is an inference.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Row4 { float x, y, z, w; };
struct M44 {
    Row4 r[4];
    const Row4 &R(int i) const { return r[i]; }
    void Pos(Vec &o) const { o.x = r[3].x; o.y = r[3].y; o.z = r[3].z; }
    void Rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" int f4c_normalize_801f6c2c(M44 *, const M44 *);
struct Camera;
struct CameraTable { char pad[24]; const M44 *(*view)(Camera *); };
struct Camera { CameraTable *t; };
struct Listener;
struct ListenerTable {
    char pad[20];
    int (*set_pos)(Listener *, const Vec *);
    int (*set_axes)(Listener *, const Vec *, const Vec *);
    int (*set_vel)(Listener *, const Vec *);
};
struct Listener { ListenerTable *t; };
struct Scene { char pad[48]; Camera *cam; char pad2[60]; Listener *listener; };
extern Scene *lbl_804b1788;
extern "C" void w3d_d42a_listener_from_camera_80035528()
{
    M44 inv;
    Camera *cam = lbl_804b1788->cam;
    f4c_normalize_801f6c2c(&inv, cam->t->view(cam));
    Vec pos;
    inv.Pos(pos);
    Vec front(0.0f, 0.0f, 1.0f);
    Vec up(0.0f, 1.0f, 0.0f);
    Vec fw, uw;
    Vec vel(0.0f, 0.0f, 0.0f);
    inv.Rotate(fw, front);
    inv.Rotate(uw, up);
    Listener *l = lbl_804b1788->listener;
    if (l) {
        l->t->set_pos(l, &pos);
        lbl_804b1788->listener->t->set_axes(lbl_804b1788->listener, &fw, &uw);
        lbl_804b1788->listener->t->set_vel(lbl_804b1788->listener, &vel);
    }
}
