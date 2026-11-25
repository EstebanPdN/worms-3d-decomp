// GWMP8P rev0 0x8003e3a4. Moves a shot's bounds handle, finds the nearest
// sphere under its position and, when the shot overlaps that sphere, pushes
// the shot out along the hit direction to the sphere surface and applies the
// impulse. With no sphere it marks the shot as having hit. Names are
// inferred from the original instructions.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float Len2() const { return x * x + y * y + z * z; }
    float DistTo2(const Vec &o) const { float dy = y - o.y, dx = x - o.x, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
    Vec operator*(float f) const { Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    void Normalize() { float f = 1.0f / sqrt_802e82c0(Len2()); x *= f; y *= f; z *= f; }
};
inline Vec Copy(const Vec &o) { return Vec(o.x, o.y, o.z); }
struct Sphere { Vec c; float radius; int pad; int a, b; };
struct Handle { int words[2]; };
struct Shot {
    char pad[28]; Vec pos; Vec dir; char pad2[12]; float radius; Handle h; char pad3[8]; int hit; int stopped; int stopped_copy; int pad4[4]; int mask;
};
extern unsigned short w3d_map_804aa95e;
extern "C" Sphere *w3d_auto_8003f240(unsigned short);
extern "C" void w3d_actor_handle_member_set_bounds(Handle *, Vec *, float);
extern "C" int d19c_nearest_sphere_801263fc(Handle *, Vec *, int, int);
extern "C" const Vec *w3d_cx11a_query_hit_delta_800418ac(void);
extern "C" void cxa_normalized_impulse_8003eb1c(Shot *, int, int, const Vec *);
extern "C" void w3d_d30a_shot_sphere_collide_8003e3a4(Shot *self)
{
    if (self->stopped) return;
    w3d_actor_handle_member_set_bounds(&self->h, &self->pos, self->radius);
    if (d19c_nearest_sphere_801263fc(&self->h, &self->dir, 20, self->mask) == 0xffff) {
        self->hit = 1;
        self->stopped_copy = 0;
        return;
    }
    Vec c = Copy(w3d_auto_8003f240(w3d_map_804aa95e)->c);
    float d = self->pos.DistTo2(c);
    float r1 = w3d_auto_8003f240(w3d_map_804aa95e)->radius;
    float r2 = w3d_auto_8003f240(w3d_map_804aa95e)->radius;
    float own = self->radius;
    bool near = d < (r1 + own) * (r2 + own);
    if (near) {
        Vec n(*w3d_cx11a_query_hit_delta_800418ac());
        n.Normalize();
        self->pos = Copy(w3d_auto_8003f240(w3d_map_804aa95e)->c) + n * (self->radius + w3d_auto_8003f240(w3d_map_804aa95e)->radius);
    }
    int a = w3d_auto_8003f240(w3d_map_804aa95e)->a;
    int b = w3d_auto_8003f240(w3d_map_804aa95e)->b;
    cxa_normalized_impulse_8003eb1c(self, a, b, w3d_cx11a_query_hit_delta_800418ac());
}
