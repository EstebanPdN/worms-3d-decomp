#include "w3d_ptr.h"
#line 1 "d27c_camera_follow_update_800d40f4.cpp"
// d27c: 0x800d40f4. Per-frame camera update: tracks idle time, eases zoom toward its limit unless input is held, blends aim, target and eye toward their goals, and keeps eye and target above the water level plus 5. Names are inferred; Pad is a partial view.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float floorv(float a, const float &b) { return fmax(a, b); }
inline bool below(const float &a, const float &b) { return a < b; }
struct Desc { char u0[68]; float followT; float aimT; char u76[56]; float eyeT; char u136[4]; float zoomOut; float zoomIn; };
struct Pad { unsigned int rest:22; unsigned int b9:1; unsigned int b8:1; unsigned int b7:1; unsigned int b6:1; unsigned int b5:1; unsigned int b4:1; unsigned int b3:1; unsigned int b2:1; unsigned int b1:1; unsigned int b0:1; int u4; int a; int b; int c; };
inline bool any_input(Ptr32<const Pad> p) {
    if (p->b0) return true;
    if (p->b1) return true;
    if (p->b2) return true;
    if (p->b3) return true;
    if (p->b4) return true;
    if (p->b5) return true;
    if (p->b6) return true;
    if (p->b7) return true;
    if (p->a > 0) return true;
    if (p->b > 0) return true;
    if (p->c > 0) return true;
    if (p->b9) return true;
    return false;
}
struct Cam {
    char u0[4]; Vec3 eye; Vec3 target; Vec3 up; char u40[24]; Ptr32<void> h64; char u68[8]; Vec3 goalEye; Vec3 goalTarget; char u100[12];
    Vec3 aimGoal; Vec3 aim; Ptr32<void> h136; Vec3 offset; char u152[24]; float yaw; float pitch; float lift; float dist; float maxDist; unsigned idle;
};
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void spherical_800d4d64(Ptr32<Cam>, Ptr32<Vec3>, float, float, float);
extern "C" float value_80178df0(Ptr32<void>);
// v25 (core/native/camara_cerca.cpp): factor de la distancia para la opción CAM; 1 si esta cámara no se acerca.
extern "C" float w3d_cam_cerca(w3d_u32 props);
extern "C" void d27c_camera_follow_update_800d40f4(Ptr32<Cam> self, float dt, Ptr32<const Pad> pad) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h136));
    dt *= 1000.0f;
    float eyeT = d->eyeT, followT = d->followT, in = d->zoomIn, out = d->zoomOut, aimT = d->aimT;
    self->idle += (unsigned)dt;
    if (below(self->maxDist, self->dist)) {
        self->dist = self->dist * (1.0f - in) + self->maxDist * in;
        self->idle = 0;
    } else {
        bool active = false;
        if (pad->b0) goto on;
        if (pad->b1) goto on;
        if (pad->b2) goto on;
        if (pad->b3) goto on;
        if (pad->b4) goto on;
        if (pad->b5) goto on;
        if (pad->b6) goto on;
        if (pad->b7) goto on;
        if (pad->a > 0) goto on;
        if (pad->b > 0) goto on;
        if (pad->c > 0) goto on;
        if (!pad->b9) goto done;
    on:
        active = true;
    done:
        if (!active) self->dist = self->dist * (1.0f - out) + self->maxDist * out;
    }
    float one = 1.0f;
    self->aim = self->aim * (one - aimT) + self->aimGoal * aimT;
    self->goalTarget = self->offset + self->aim;
    self->goalTarget.y += self->lift;
    // v25: con CAM a p %, la tercera persona (ajustes ShoulderCamera y NinjaCamera) se pone a 1/(1+p/100) de la
    // distancia. 0x800d4d64 lee el radio de self->dist (+0xbc), no del quinto argumento: la distancia se escala solo
    // durante la llamada y vuelve después, así que el resto de la cámara (objetivo, oclusión, zoom) sigue igual.
    float keep = self->dist;
    self->dist = keep * w3d_cam_cerca((w3d_u32)self->h136);
    spherical_800d4d64(self, &self->goalEye, self->yaw, self->pitch, self->dist);
    self->dist = keep;
    float low = value_80178df0(self->h64) + 5.0f;
    self->goalEye.y = floorv(low, self->goalEye.y);
    self->goalTarget.y = floorv(low, self->goalTarget.y);
    self->eye = self->eye * (one - eyeT) + self->goalEye * eyeT;
    self->target = self->target * (one - followT) + self->goalTarget * followT;
    self->up = Vec3(0.0f, one, 0.0f);
}


