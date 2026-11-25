// GWMP8P rev0 0x800a0e2c. Distance-attenuated light, same shape as
// 0x8003c938: scales the ambient vector by a clamped inverse of the squared
// distance to the camera and sends it to a sink. Names are inferred from the
// original instructions.
// GWMP8P rev0 0x8003c938. Distance-attenuated light: scales the ambient
// vector by a clamped inverse of the squared distance to the camera and
// sends it to a sink. Names are inferred from the original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { x = o.x; y = o.y; z = o.z; }
};
inline Vec operator*(const Vec &a, float f) { Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
struct Mat { float rows[12]; Vec position; };
extern "C" int w3d_normalize_801f6c2c(Mat *, void *);
struct Source {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void *Matrix();    /* table +24 */
};
struct Scene { char unknown00[48]; Source *source; };
extern Scene *g_scene_804b1788;
extern Vec g_ambient_80437d24[];
struct Sink {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void Apply(const Vec &, int);    /* table +84 */
};
struct Self { char unknown00[36]; Sink *sink; };
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline void Clamp(float &v, const float &lo, const float &hi) { v = fmax(fmin(v, hi), lo); }

extern "C" void d27h_distance_light_800a0e2c(Self *self, const Vec *v)
{
    Vec p;
    Mat m;
    w3d_normalize_801f6c2c(&m, g_scene_804b1788->source->Matrix());
    Vec *q = &p;
    q->x = m.position.x;
    q->y = m.position.y;
    q->z = m.position.z;
    float dx = p.x - v->x, dy = q->y - v->y, dz = q->z - v->z;
    float d = dx * dx + dy * dy + dz * dz;
    float lo = 62500.0f;
    float hi = 160000.0f;
    Clamp(d, lo, hi);
    float k = lo / d;
    float klo = 0.5f;
    float khi = 0.65f;
    Clamp(k, klo, khi);
    Sink *s = self->sink;
    s->Apply(g_ambient_80437d24[0] * k, 0);
}
