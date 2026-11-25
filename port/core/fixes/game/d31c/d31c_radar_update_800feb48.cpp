#include "w3d_ptr.h"
extern "C" void w3d_hud_radar_observe(unsigned,float,float,int);
#line 1 "d31c_radar_update_800feb48.cpp"
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
extern "C" void vec_ctor_80343740(Ptr32<Vec>);
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
struct CameraV { Ptr32<void> u[6]; Ptr32<Ptr32<const Mat44> (Ptr32<Camera>)> view; };
struct Camera { Ptr32<CameraV> vt; };
struct Manager { char u0[48]; Ptr32<Camera> camera; };
extern Ptr32<Manager> manager_804b1788;
struct Mesh;
struct Worm { char u0[80]; W pos; char u92[121]; unsigned char team; char u214[6]; int u220; char u224[36]; int u260; };
struct Radar { char u0[32]; Ptr32<void> mesh; char u36[4]; W centre; Ptr32<void> h52; char u56[12]; Ptr32<void> h68; Ptr32<void> h72; };
extern "C" void lerp_800ff97c(Ptr32<Radar>, int);
extern "C" int normalize_801f6c2c(Ptr32<Mat44>, Ptr32<const Mat44>);
extern "C" void invert_801f74d0(Ptr32<Mat>, Ptr32<const Mat44>);
extern "C" void axis_801f7538(Ptr32<Mat>, float, float, float, float);
extern "C" Ptr32<void> cast_803426b4(Ptr32<void>);
extern "C" int value_80178c48(Ptr32<void>);
extern "C" Ptr32<Mesh> as_mesh_8034380c(Ptr32<void>);
extern "C" Ptr32<Worm> worm_800fc6dc(unsigned);
extern "C" Ptr32<unsigned char> flags_80189704(Ptr32<Mesh>);
extern "C" Ptr32<void> cast_80342a74(Ptr32<void>);
extern "C" float fvalue_80178df0(Ptr32<void>);
extern "C" Ptr32<Vec> positions_80189518(Ptr32<Mesh>);
extern "C" void marker_800ff56c(Ptr32<Radar>, unsigned, unsigned char, int);
struct Colour { int v; };
extern "C" Ptr32<Colour> colours_80189760(Ptr32<Mesh>);
extern "C" Ptr32<Colour> colour_800fd388(Ptr32<Colour>, unsigned);
extern "C" void radar_800ff6a4(Ptr32<Radar>, Ptr32<Vec>, Ptr32<Mat>);
extern "C" int d31c_radar_update_800feb48(Ptr32<Radar> self, int arg) {
    Vec w, d, t, p, eye;
    Mat44 view;
    lerp_800ff97c(self, arg);
    normalize_801f6c2c(&view, manager_804b1788->camera->vt->view(manager_804b1788->camera));
    eye.x = view.row[3].x; eye.y = view.row[3].y; eye.z = view.row[3].z;
    Mat inv;
    invert_801f74d0(&inv, &view);
    Vec v;
    Ptr32<Vec> pv = &v;
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
    Ptr32<Mesh> mesh = as_mesh_8034380c(self->mesh);
    for (unsigned i = 0; i < 16; i++) {
        Ptr32<Worm> wm = worm_800fc6dc(i);
        if (wm->u220 && !wm->u260) {
            flags_80189704(mesh)[i] = 1;
            *(Ptr32<W>)&w = wm->pos;
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
            *(Ptr32<W>)&p = self->centre;
            const float radius=fvalue_80178df0(self->h72);
            w3d_hud_radar_observe(i,radius>0?t.x/radius:0,radius>0?t.z/radius:0,1);
            p.x += t.x;
            p.y -= t.z;
            Ptr32<Vec> base = positions_80189518(mesh);
            int off = i;
            off *= 12;
            off += (int)w3d::H(base);
            Ptr32<Vec> o = (Ptr32<Vec>)w3d::G(off);
            float ax = p.x, ay = p.y;
            o->x = ax; o->y = ay; o->z = 0.0f;
            if (i == active) marker_800ff56c(self, i, wm->team, arg);
            else {
                Colour w3d_c; colour_800fd388(&w3d_c, i); colours_80189760(mesh)[i] = w3d_c;
            }
        } else {
            flags_80189704(mesh)[i] = 0;
            w3d_hud_radar_observe(i,0,0,0);
        }
    }
    radar_800ff6a4(self, &eye, &rot);
    return 0;
}


