#include "w3d_ptr.h"
#line 1 "d33a_wind_aim_angle_8001c36c.cpp"
// GWMP8P rev0 0x8001c36c. Scales the current wind by Wind.MaxSpeed and ten
// into the output vector; when it is nonzero, returns one minus the
// normalised angle between a given direction, or the opposite of the wind
// when that direction is zero, and the wind. Names are inferred from the
// property string and the original instructions.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Object;
struct ObjectTable { char pad[16]; Ptr32<void (Ptr32<Object>)> Release; };
struct Object { Ptr32<ObjectTable> table; void Release() { table->Release(this); } };
struct Key { Ptr32<const char> name; };
struct Handle { Ptr32<Object> p; Handle() { p = 0; } ~Handle() { if (p) p->Release(); } };
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" float value_80178df0(Ptr32<Object>);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    void NegateTo(Vec &o) const { o.x = -x; o.y = -y; o.z = -z; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    bool operator==(const Vec &o) const { bool r = false; if (*(Ptr32<int>)&x == *(Ptr32<int>)&o.x && *(Ptr32<int>)&y == *(Ptr32<int>)&o.y) r = *(Ptr32<int>)&z == *(Ptr32<int>)&o.z; return r; }
};
inline Vec operator*(const Vec &a, float f) { Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline Vec operator/(const Vec &a, float d) { float f = 1.0f / d; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline Vec operator-(const Vec &a) { Vec r; r.x = -a.x; r.y = -a.y; r.z = -a.z; return r; }
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
extern "C" Ptr32<void> w3d_cx14a_wind_vector_8001a9a0(Ptr32<Vec>);
extern "C" void w3d_d33a_wind_aim_angle_8001c36c(Ptr32<const Vec> self, Ptr32<Vec> out, Ptr32<float> angle)
{
    Handle h;
    Vec p, d;
    Key key;
    key.name = "Wind.MaxSpeed";
    w3d_constructor_lookup_name(key, h);
    float maxSpeed = value_80178df0(w3d_identity_80342a74(h.p));
    Vec wind;
    w3d_cx14a_wind_vector_8001a9a0(&wind);
    float f = 1.0f / maxSpeed;
    d.x = wind.x * f; d.y = wind.y * f; d.z = wind.z * f;
    Vec scaled;
    scaled.x = d.x * 10.0f; scaled.y = d.y * 10.0f; scaled.z = d.z * 10.0f;
    p.x = scaled.x; p.y = scaled.y; p.z = scaled.z;
    *out = p;
    if (out->lenSq() != 0.0f) {
        p.Set(self->x, self->y, self->z);
        d.Set(0.0f, 0.0f, 0.0f);
        if (d == p) {
            out->NegateTo(wind);
            p = wind;
            Vec t(wind);
        }
        p.normalize();
        d.x = out->x; d.y = out->y; d.z = out->z;
        d.normalize();
        float c = p.dot(d);
        c = fmin(c, 1.0f);
        c = fmax(c, 0.0f);
        float t = acos_802e79e0(c);
        *angle = 1.0f - (t + t) / 3.14159274f;
    }
}


