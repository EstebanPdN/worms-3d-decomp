#include "w3d_ptr.h"
#line 1 "d43c_payload_spawn_scatter_800ebad8.cpp"
// d43c: 0x800ebad8. Spawns the desc-count child objects of a payload:
// reflects the incoming direction off the surface normal, builds an aim
// rotation from the up axis, then for each child creates the class named by
// the description, randomises a direction through the euler matrix and a
// speed from the description's range and adds it to the task manager. Names
// are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float asin_802e7c30(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float n = 1.0f / len(); x *= n; y *= n; z *= n; }
};
inline float dot(const Vec &a, const Vec &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline Vec operator*(const Vec &a, float s) { Vec r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline void Cross(Vec &r, const Vec &a, const Vec &b) { r.x = a.y * b.z - a.z * b.y; r.y = a.z * b.x - a.x * b.z; r.z = a.x * b.y - a.y * b.x; }
struct Mat { float m[9]; Mat() {} const Vec &R(int i) const { return *(Ptr32<const Vec>)&m[i * 3]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void ctor_801f6034(Ptr32<Mat>);
extern "C" void set_axis_angle_801f656c(Ptr32<Mat>, Ptr32<const Vec>, float);
struct Info { int w[4]; };
struct Object;
struct ObjectVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVt> vt; };
struct Own {
    Ptr32<Object> p;
    Own() { p = 0; }
    template <class W3dU> Own(Ptr32<W3dU> w3d_p) : Own((Object *)w3d_p.get()) {}
 Own(Object *q) { p = q; if (q) q->vt->retain(q); }
    Own(const Own &o) { p = o.p; if (p) p->vt->retain(p); }
    ~Own() { if (p) p->vt->release(p); }
};
struct Key { Ptr32<const char> name; };
struct Desc { char u0[256]; unsigned count; char u260[32]; float spread; char u296[24]; float lo; char u324[4]; float hi; char u332[8]; Ptr32<const char> cls; };
struct Self { char u0[192]; Ptr32<void> desc; };
struct Clock { char u0[20]; int now; };
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> cast_801797b4(Ptr32<void>);
extern "C" Ptr32<Object> create_8020b680(Ptr32<const Info>);
extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ptr32<Object>>);
extern "C" void assign_800eb65c(Ptr32<Object>, Own);
extern "C" void position_800eb8d0(Ptr32<Object>, Ptr32<const Vec>);
extern "C" void velocity_800eb8f0(Ptr32<Object>, Ptr32<const Vec>);
extern "C" float random_801610a0(Ptr32<Self>);
extern "C" void euler_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
extern "C" int add_80164514(Ptr32<void>, Ptr32<Object>, int);
extern Ptr32<void> world_804b178c;
extern Ptr32<Clock> clock_804aab4c;
extern Info i_8040fd78[];
extern "C" void d43c_payload_spawn_scatter_800ebad8(Ptr32<Self> self, Ptr32<const Vec> pos, Ptr32<const Vec> a, Ptr32<const Vec> b) {
    Ptr32<Desc> d = cast_801797b4(empty_80341584(self->desc));
    Vec up(0.0f, 1.0f, 0.0f);
    Mat base;
    ctor_801f6034(&base);
    if (b->lenSq() > 0.0f && a->lenSq() > 0.0f) {
        Vec out, n;
        n = *b;
        n.normalize();
        float k = dot(*a, n);
        out = *a - n * (k + k);
        out.normalize();
        Vec axis; Cross(axis, up, out);
        float angle = asin_802e7c30(axis.len());
        if (angle == 0.0f) set_axis_angle_801f656c(&base, &axis, angle);
    }
    for (unsigned i = 0; i < d->count; i++) {
        Vec e, v, w;
        Mat rot;
        Ptr32<const Info> t = i_8040fd78; Own obj(create_8020b680(t));
        Own cls;
        Key key; key.name = d->cls;
        lookup_800fc1b0(&key, &cls.p);
        assign_800eb65c(obj.p, cls);
        position_800eb8d0(obj.p, pos);
        e.y = random_801610a0(self) * 6.2831855f;
        e.x = d->spread * random_801610a0(self);
        e.z = 0.0f;
        euler_801a3eb0(&e, 0, &rot);
        rot.rotate(v, up);
        base.rotate(w, v);
        float speed = (d->hi - d->lo) * random_801610a0(self) + d->lo;
        Vec r = w * speed;
        velocity_800eb8f0(obj.p, &r);
        add_80164514(world_804b178c, obj.p, clock_804aab4c->now);
    }
}


