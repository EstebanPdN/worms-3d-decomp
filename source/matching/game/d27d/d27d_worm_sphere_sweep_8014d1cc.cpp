// GWMP8P rev0 0x8014d1cc. Sweep a moving sphere against a worm: solve the
// quadratic between the shot start and direction and the worm's raised
// position with the combined radius. On a hit before the stored best time
// post a hit message and record the hit point, time and worm index; a hit on
// the shot's owner sets a flag instead. A zero direction becomes a point-in-
// sphere test. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Plain { float x, y, z; };
struct Point : Plain {
    Point &operator=(const Plain &o) { Plain::operator=(o); return *this; }
    Point &operator=(const Point &o) { Plain::operator=(o); return *this; }
};
struct Vec : Plain {
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Message;
struct Shared { char u0[32]; void *owner; void *flag; };
struct Worm { char u0[560]; Vec pos; char u23c[12]; int index; };
extern "C" void *same_80342a78(void *);
extern "C" int id_80178d1c(void *);
extern "C" void update_80178d28(void *, int *);
extern "C" Message *alloc_801613f0(void *, int);
extern "C" Message *init_80131984(Message *, int);
extern "C" void post_8016239c(Message *);
extern Vec start_804522ec;
extern Point hitPoint_80452310;
extern Shared *shared_804ab400;
extern void *heap_804b1754;
extern unsigned limit_804b1874, best_804b1870;
extern int hitOwner_804b187c;
extern float radius_804b1878;
inline void setFlag(int v) { update_80178d28(same_80342a78(shared_804ab400->flag), &v); }
extern "C" void d27d_worm_sphere_sweep_8014d1cc(Worm *self) {
    Vec d;
    d = start_804522ec;
    d -= self->pos;
    float h = 10.0f;
    float tmax = (float)limit_804b1874;
    d.y -= h;
    Vec v;
    v = start_804522ec;
    float tbest = (float)best_804b1870;
    float a = v.dot(v);
    float r = radius_804b1878;
    r += h;
    if (a == 0.0f) {
        if (d.lenSq() < r * r) {
            Vec e;
            e = d;
            if (id_80178d1c(same_80342a78(shared_804ab400->owner)) == self->index) {
                setFlag(1);
                return;
            }
            post_8016239c(init_80131984(alloc_801613f0(heap_804b1754, 12), self->index));
            best_804b1870 = 0;
            hitOwner_804b187c = self->index;
            hitPoint_80452310 = e;
        }
        return;
    }
    float b = d.dot(v) * 2.0f;
    float s = b * b - a * 4.0f * (d.lenSq() - r);
    if (s >= 0.0f) {
        s = sqrt_802e82c0(s);
        float t;
        if (-b - s > 0.0f) t = (-b - s) / (a + a);
        else if (s - b > 0.0f) t = 0.0f;
        else return;
        if (t <= tmax) {
            if (id_80178d1c(same_80342a78(shared_804ab400->owner)) == self->index) {
                t = (-b + s) / (a + a);
                if (t <= tmax) setFlag(1);
                return;
            }
            post_8016239c(init_80131984(alloc_801613f0(heap_804b1754, 12), self->index));
            if (t < tbest) {
                Vec e;
                e = d + v * t;
                best_804b1870 = (int)t;
                hitOwner_804b187c = self->index;
                hitPoint_80452310 = e;
            }
        }
    }
}
