// GWMP8P rev0 0x8000aa9c. Walks from the shot centre toward the plan's
// target over the grid, one step per twenty units of weapon range: sets the
// plan's aim direction, snaps each step to ground height, and turns back on
// steep rises or near the target unless told to stop. Returns whether the
// walk ended within twenty units of the target. Names are inferred from the
// original instructions.
extern "C" float sqrt_802e82c0(float);
struct Res;
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Res &o);
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Res operator-(const Vec &o) const;
    Res operator+(const Vec &o) const;
    Vec operator-() const { Vec r; r.x = -x; r.y = -y; r.z = -z; return r; }
    float Len2() const { return x * x + y * y + z * z; }
    Vec &operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    void Normalize() { *this *= 1.0f / sqrt_802e82c0(Len2()); }
};
struct Res {
    float x, y, z;
    Res(float a, float b, float c) { x = a; y = b; z = c; }
    Res(const Vec &a, const Vec &b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
    Res operator-(const Vec &o) const { return Res(x - o.x, y - o.y, z - o.z); }
    float Len2() const { return x * x + y * y + z * z; }
};
inline Vec::Vec(const Res &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
inline Res Vec::operator-(const Vec &o) const { return Res(*this, o); }
inline Res Vec::operator+(const Vec &o) const { return Res(x + o.x, y + o.y, z + o.z); }
inline Vec Same(const Res &v) { return Vec(v.x, v.y, v.z); }
inline Vec Plain(const Res &v) { return Vec(v.x, 0.0f, v.z); }
inline Vec Diff(const Vec &a, const Vec &b) { return Same(a - b); }
inline Vec Sum(const Vec &a, const Vec &b) { return Same(a + b); }
inline Vec FlatDiff(const Vec &a, const Vec &b) { return Plain(a - b); }
struct Grid;
struct Cell { short x, y; ~Cell() {} };
struct Weapon { char pad[420]; unsigned int range; char pad2[32]; int climbs; };
struct Plan {
    char pad[24]; Vec target; Vec dir; char pad2[28]; int fixed; char pad3[8]; Vec start;
};
extern Grid *w3d_grid_804b1758;
extern Vec g_centre_8041d3a0;
extern "C" Weapon *w3d_cached_name_lookup_80341694(Plan *, int);
extern "C" int cc26a_grid_select_layer_8001e328(Grid *, const Vec *, short *, short *, int *);
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(Grid *, int, int, int);
extern "C" Vec w3d_cx12a_sample_grid_8001e224(Grid *, int, int, int);
extern "C" Vec k2a_grid_position_8001f9f0(Grid *, const Vec *);
extern "C" int w3d_d30a_walk_reach_test_8000aa9c(Plan *self, int stopAtHit, float climb, float speed)
{
    Weapon *w = w3d_cached_name_lookup_80341694(self, 0);
    int steps = w->range / 20;
    int climbs = w->climbs;
    if (self->fixed) g_centre_8041d3a0 = self->start;
    self->dir = Diff(self->target, g_centre_8041d3a0);
    self->dir.y = 0.0f;
    self->dir.Normalize();
    self->dir *= speed;
    Vec pos(g_centre_8041d3a0);
    Vec step = FlatDiff(self->target, g_centre_8041d3a0);
    float f = 1.0f / sqrt_802e82c0(step.Len2());
    float g = speed * 20.0f;
    step.x = step.x * f * g; step.y = step.y * f * g; step.z = step.z * f * g;
    for (int i = 0; i < steps; i++) {
        pos += step;
        pos.y = k2a_grid_position_8001f9f0(w3d_grid_804b1758, &pos).y;
        Vec d = Diff(self->target, pos);
        if (climbs) {
            Vec e = Diff(self->target, Sum(pos, step));
            if (e.Len2() > d.Len2()) break;
        }
        Vec next = Sum(pos, step);
        int hit = 0;
        Cell c; int layer;
        cc26a_grid_select_layer_8001e328(w3d_grid_804b1758, &next, &c.x, &c.y, &layer);
        next = w3d_cx12a_sample_grid_8001e224(w3d_grid_804b1758, c.x, c.y, layer);
        if (next.y - pos.y > climb) hit = 1;
        if (*cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, c.x, c.y, layer) == 1) break;
        if (d.Len2() < 25.0f) hit = 1;
        if (hit) {
            if (stopAtHit) break;
            step = -step;
        }
    }
    return Diff(pos, self->target).Len2() < 400.0f;
}
