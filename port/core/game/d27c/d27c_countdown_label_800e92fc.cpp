#include "w3d_ptr.h"
#line 1 "d27c_countdown_label_800e92fc.cpp"
// d27c: 0x800e92fc. Shows a countdown above an object while up to five seconds remain: projects the label position through the camera matrix, prints the remaining seconds rounded up, and picks a colour by whether three seconds are left. Names are inferred.
extern "C" float ceil_802e85fc(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float v) { x = v; y = v; z = v; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Row { float x, y, z, w; };
struct Mat {
    Row r[4];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec3 &o, const Vec3 &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Cam { struct V { Ptr32<void> u[6]; Ptr32<Ptr32<const Mat> (Ptr32<Cam>)> matrix; }; Ptr32<struct V> vtable; };
struct Svc { char u[48]; Ptr32<Cam> cam; };
struct Hud { struct V { Ptr32<void> u[10]; Ptr32<void (Ptr32<Hud>, const Vec3 &)> position; Ptr32<void (Ptr32<Hud>, Ptr32<const char>)> text; }; Ptr32<struct V> vtable; };
struct Desc { char u0[220]; float height; };
struct Context { char u0[52]; int now; };
struct Self { char u0[28]; Ptr32<void> h28; char u32[28]; Vec3 pos; char u72[24]; Ptr32<Hud> hud; Ptr32<void> h100; char u104[56]; int end; };
extern Ptr32<Svc> svc_804b1788;
struct Color { unsigned v; };
extern Color colorA_804aee50, colorB_804aee54;
extern Color propKey_804af3b4;
extern char fmt_8038b264[];
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" Ptr32<Context> ctx_80165254(void);
extern "C" void visible_8011afac(Ptr32<Hud>, int);
extern "C" int norm_801f6c2c(Ptr32<Mat>, Ptr32<const Mat>);
extern "C" Ptr32<void> empty_80342a74(Ptr32<void>);
extern "C" float value_80178df0(Ptr32<void>);
extern "C" int format_803434d4(Ptr32<char>, Ptr32<const char>, ...);
extern "C" void props_8011adf8(Ptr32<Hud>, Ptr32<const Color>, Ptr32<const Color>);
extern "C" void d27c_countdown_label_800e92fc(Ptr32<Self> self) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h28));
    int left = self->end - ctx_80165254()->now;
    if ((unsigned)(left - 1) <= 4999) {
        visible_8011afac(self->hud, 1);
        Mat m;
        norm_801f6c2c(&m, svc_804b1788->cam->vtable->matrix(svc_804b1788->cam));
        Vec3 o(0.0f), v(0.0f);
        float y = d->height;
        y += value_80178df0(empty_80342a74(self->h100));
        v.y = y;
        m.rotate(o, v);
        { Vec3 p = self->pos + o; self->hud->vtable->position(self->hud, p); }
        char buf[128];
        format_803434d4(buf, fmt_8038b264, (int)ceil_802e85fc(left / 1000.0f));
        self->hud->vtable->text(self->hud, buf);
        Color c = left <= 3000 ? colorB_804aee54 : colorA_804aee50;
        props_8011adf8(self->hud, &c, &propKey_804af3b4);
    } else {
        visible_8011afac(self->hud, 0);
    }
}


