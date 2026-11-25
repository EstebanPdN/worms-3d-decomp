// GWMP8P rev0 0x800bae54. Land bounds grow and publish. Names are inferred.
// Handles are one word with a user copy constructor; the named locals in
// declaration order give the original stack slots.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
};
struct Object;
struct ObjectVtable { void *u[4]; void (*release)(Object *); };
struct Object { ObjectVtable *vt; };
struct Handle {
    Object *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { if (p) p->vt->release(p); }
};
struct Key { const char *name; Key(const char *n) : name(n) {} };
extern "C" int lookup_800fc1b0(Key *, Handle *);
extern "C" int float_assign_800fc4c8(Key *, float);
extern "C" void *as_vector_80342fa4(Object *);
extern "C" void *as_float_80342a74(Object *);
extern "C" int set_vector_80178fa4(void *, const Vec *);
extern "C" int set_float_80178dfc(void *, const float *);
struct Land { unsigned char u[12548]; Vec lo, hi; };
extern "C" void d26h_land_bounds_publish_800bae54(Land *self, const Vec &a, const Vec &b) {
    Vec p(a);
    Vec q(b);
    if (p.x < self->lo.x) self->lo.x = p.x;
    if (p.y < self->lo.y) self->lo.y = p.y;
    if (p.z < self->lo.z) self->lo.z = p.z;
    if (q.x > self->hi.x) self->hi.x = q.x;
    if (q.y > self->hi.y) self->hi.y = q.y;
    if (q.z > self->hi.z) self->hi.z = q.z;
    Handle hc;
    Handle hr;
    Key kc("Land.Center");
    lookup_800fc1b0(&kc, &hc);
    Vec half = (self->hi - self->lo) * 0.5f;
    Vec c = half + self->lo;
    float radius = half.len();
    set_vector_80178fa4(as_vector_80342fa4(hc.p), &c);
    Key kr("Land.Radius");
    lookup_800fc1b0(&kr, &hr);
    set_float_80178dfc(as_float_80342a74(hr.p), &radius);
    Key kh("Land.MaxHeight");
    float_assign_800fc4c8(&kh, self->hi.y);
    Handle hmin;
    Key kmin("Land.MinBounds");
    lookup_800fc1b0(&kmin, &hmin);
    set_vector_80178fa4(as_vector_80342fa4(hmin.p), &self->lo);
    Handle hmax;
    Key kmax("Land.MaxBounds");
    lookup_800fc1b0(&kmax, &hmax);
    set_vector_80178fa4(as_vector_80342fa4(hmax.p), &self->hi);
}
