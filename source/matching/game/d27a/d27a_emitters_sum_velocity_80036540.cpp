// GWMP8P rev0 0x80036540. Sums the velocity of every active emitter into
// three output vectors. Names are inferred from the original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float s) const { Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    Vec &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
};
struct Emitter;
extern "C" int w3d_auto_80036c8c(Emitter *);
extern "C" void f9b_random_decay_80036b08(Emitter *, Vec &);
struct List {
    Emitter **begin, **end;
    unsigned size() const { return end - begin; }
    Emitter *&operator[](unsigned i) { return begin[i]; }
};
struct Set { int unknown00; List list; };
extern "C" void w3d_d27a_emitters_sum_velocity_80036540(Set *self, float k, Vec &a, Vec &b, Vec &c)
{
    for (unsigned i = 0; i < self->list.size(); i++) {
        if (w3d_auto_80036c8c(self->list[i])) {
            Vec v;
            f9b_random_decay_80036b08(self->list[i], v);
            v *= k;
            Vec h;
            h = v * 1000.0f;
            h.z = 0.0f;
            a += h;
            b += h;
            c += v + v;
        }
    }
}
