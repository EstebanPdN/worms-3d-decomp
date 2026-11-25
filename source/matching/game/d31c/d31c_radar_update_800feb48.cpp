// d31c: 0x800feb48. Radar update: builds the view rotation from the camera, then places each living worm on the radar mesh relative to the viewer, clamped to the radar radius; hands the rest to the radar update. Names are inferred; classes are partial views.
// Radar update.
extern "C" float sqrt_802e82c0(float);
extern "C" float atan2_802e7e5c(float, float);
struct W { int a, b, c; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Row { float x, y, z; };
struct Mat;
extern "C" void vec_ctor_80343740(Vec *);
struct Mat { Row row[3]; Vec pos; Mat() { vec_ctor_80343740(&pos); } const Row &R(int i) const { return row[i]; } const Vec &P() const { return pos; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    } };
struct Row4 { float x, y, z, w; };
struct Mat44 { Row4 row[4]; const Row4 &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    } };
struct Camera;
struct Mat44;
struct CameraV { void *u[6]; const Mat44 *(*view)(Camera *); };
struct Camera { CameraV *vt; };
struct Manager { char u0[48]; Camera *camera; };
extern Manager *manager_804b1788;
struct Mesh;
struct Worm { char u0[80]; W pos; char u92[121]; unsigned char team; char u214[6]; int u220; char u224[36]; int u260; };
struct Radar { char u0[32]; void *mesh; char u36[4]; W centre; void *h52; char u56[12]; void *h68, *h72; };
extern "C" void lerp_800ff97c(Radar *, int);
extern "C" int normalize_801f6c2c(Mat44 *, const Mat44 *);
extern "C" void invert_801f74d0(Mat *, const Mat44 *);
extern "C" void axis_801f7538(Mat *, float, float, float, float);
extern "C" void *cast_803426b4(void *);
extern "C" int value_80178c48(void *);
extern "C" Mesh *as_mesh_8034380c(void *);
extern "C" Worm *worm_800fc6dc(unsigned);
extern "C" unsigned char *flags_80189704(Mesh *);
extern "C" void *cast_80342a74(void *);
extern "C" float fvalue_80178df0(void *);
extern "C" Vec *positions_80189518(Mesh *);
extern "C" void marker_800ff56c(Radar *, unsigned, unsigned char, int);
struct Colour { int v; };
extern "C" Colour *colours_80189760(Mesh *);
extern "C" Colour colour_800fd388(...);
extern "C" void radar_800ff6a4(Radar *, Vec *, Mat *);
extern "C" int d31c_radar_update_800feb48(Radar *self, int arg) {
    Vec w, d, t, p, eye;
    Mat44 view;
    lerp_800ff97c(self, arg);
    normalize_801f6c2c(&view, manager_804b1788->camera->vt->view(manager_804b1788->camera));
    eye.x = view.row[3].x; eye.y = view.row[3].y; eye.z = view.row[3].z;
    Mat inv;
    invert_801f74d0(&inv, &view);
    Vec v;
    Vec *pv = &v;
    pv->x = 1.0f; pv->y = 0.0f; pv->z = 0.0f;
    Vec r;
    float angle;
    {
        Mat44 m;
        const Vec &ip = inv.pos;
        m.row[0].w = 0.0f;
        float a0 = inv.row[0].x, a1 = inv.row[0].y, a2 = inv.row[0].z;
        float b0 = inv.row[1].x, b1 = inv.row[1].y, b2 = inv.row[1].z;
        float c0 = inv.row[2].x, c1 = inv.row[2].y, c2 = inv.row[2].z;
        float d0 = ip.x, d1 = ip.y, d2 = ip.z;
        m.row[0].x = a0; m.row[0].y = a1; m.row[0].z = a2;
        m.row[1].x = b0; m.row[1].y = b1; m.row[1].z = b2; m.row[1].w = 0.0f;
        m.row[2].x = c0; m.row[2].y = c1; m.row[2].z = c2; m.row[2].w = 0.0f;
        m.row[3].x = d0; m.row[3].y = d1; m.row[3].z = d2; m.row[3].w = 1.0f;
        m.rotate(r, v);
        angle = atan2_802e7e5c(r.z, r.x) + 3.1415927f;
    }
    Mat rot;
    axis_801f7538(&rot, 0.0f, 1.0f, 0.0f, angle);
    int active = value_80178c48(cast_803426b4(self->h52));
    Mesh *mesh = as_mesh_8034380c(self->mesh);
    for (unsigned i = 0; i < 16; i++) {
        Worm *wm = worm_800fc6dc(i);
        if (wm->u220 && !wm->u260) {
            flags_80189704(mesh)[i] = 1;
            *(W *)&w = wm->pos;
            d = eye - w;
            d.y = 0.0f;
            rot.apply(t, d);
            float s = fvalue_80178df0(self->h68);
            t.x *= s; t.y *= s; t.z *= s;
            float len = sqrt_802e82c0(t.x * t.x + t.y * t.y + t.z * t.z);
            if (len >= fvalue_80178df0(self->h72)) {
                float k = fvalue_80178df0(self->h72) / len;
                t.x *= k; t.y *= k; t.z *= k;
            }
            *(W *)&p = self->centre;
            p.x += t.x;
            p.y -= t.z;
            Vec *base = positions_80189518(mesh);
            int off = i;
            off *= 12;
            off += (int)base;
            Vec *o = (Vec *)off;
            float ax = p.x, ay = p.y;
            o->x = ax; o->y = ay; o->z = 0.0f;
            if (i == active) marker_800ff56c(self, i, wm->team, arg);
            else {
                colours_80189760(mesh)[i] = colour_800fd388(i);
            }
        } else {
            flags_80189704(mesh)[i] = 0;
        }
    }
    radar_800ff6a4(self, &eye, &rot);
    return 0;
}
