#include "w3d_ptr.h"
#line 1 "d28b_girder_track_80095db4.cpp"
/* Girder collision tracking (0x80095db4): state 2 (+684) tests the height range against the limits
 * +756 and +760, sweeps the top four edges of the corner box (0x800b0824), counts blocked edges and
 * casts the first ray; state 3 sweeps the four verticals and casts the second; state 4 sweeps down
 * from +172, and when short sweeps the bottom edges, then casts the last two rays. A ray hit sets
 * +708. Field names are inferred from the original instructions; the default vector is an external
 * view. Owns the literals at 0x8037ebd0. */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void Set(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    void Scale(float f) { x *= f; y *= f; z *= f; }
    bool Same(const Vec &b) const { return *(Ptr32<int>)&x == *(Ptr32<int>)&b.x && *(Ptr32<int>)&y == *(Ptr32<int>)&b.y && *(Ptr32<int>)&z == *(Ptr32<int>)&b.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
extern Vec lbl_8045e788[];
extern unsigned lbl_804b1764;
extern "C" int w3d_sweep_800b0824(Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>, unsigned, int);
extern "C" void w3d_ray_begin_801262c0(Ptr32<void>, Ptr32<const Vec>);
extern "C" void w3d_ray_cast_80126384(Ptr32<void>, Ptr32<const Vec>, unsigned);
extern "C" int w3d_ray_hit_801264fc(Ptr32<void>);
extern "C" void w3d_ray_end_80126524(Ptr32<void>);
struct Girder {
    char unknown00[172]; Vec bottom; char unknown184[308]; Vec corner[8]; Vec ray[4];
    char unknown636[48]; int state; char unknown688[4]; int f692; int f696; int f700; int f704; int f708; int f712; int f716; int f720; char unknown724[24]; unsigned blocked; char unknown752[4]; float low; float high; Ptr32<void> ray764;
};
extern "C" void w3d_d28b_girder_track_80095db4(Ptr32<Girder> self) {
    Vec from;
    Vec dir;
    Vec zero(0.0f, 0.0f, 0.0f);
    unsigned steps;
    switch (self->state) {
    case 2: {
        float half = __builtin_fabsf(self->corner[4].y - self->corner[0].y) * 0.5f;
        if (self->bottom.y + half <= self->low) {
            self->f700 = 1;
            self->f692 = 1;
            self->f720 = 1;
            if (self->f716) self->f712 = 1;
        }
        if (self->bottom.y + half > self->high + 750.0f) {
            self->f700 = 1;
            self->f692 = 1;
            if (self->f716) self->f712 = 1;
        }
        float one = 1.0f;
        for (unsigned i = 0; i <= 3; i++) {
            from = self->corner[i];
            if (i == 3) dir = self->corner[0] - self->corner[3];
            else dir = self->corner[i + 1] - self->corner[i];
            steps = (int)dir.len() + 1;
            if (!dir.Same(lbl_8045e788[0])) dir.Scale(one / dir.len());
            w3d_sweep_800b0824(&from, &dir, &zero, steps, 1);
            if (lbl_804b1764 < steps) {
                self->f700 = 1;
                self->blocked++;
            }
        }
        w3d_ray_begin_801262c0(self->ray764, &self->ray[0]);
        w3d_ray_cast_80126384(self->ray764, &dir, steps);
        if (w3d_ray_hit_801264fc(self->ray764) != 0xffff) self->f708 = 1;
        w3d_ray_end_80126524(self->ray764);
        break;
    }
    case 3: {
        float one = 1.0f;
        for (unsigned i = 4; i <= 7; i++) {
            from = self->corner[i];
            dir = self->corner[i - 4] - self->corner[i];
            steps = (int)dir.len() + 1;
            if (!dir.Same(lbl_8045e788[0])) dir.Scale(one / dir.len());
            w3d_sweep_800b0824(&from, &dir, &zero, steps, 1);
            if (lbl_804b1764 < steps) {
                self->f700 = 1;
                self->blocked++;
            }
        }
        w3d_ray_begin_801262c0(self->ray764, &self->ray[1]);
        w3d_ray_cast_80126384(self->ray764, &dir, steps);
        if (w3d_ray_hit_801264fc(self->ray764) != 0xffff) self->f708 = 1;
        w3d_ray_end_80126524(self->ray764);
        break;
    }
    case 4:
        dir.Set(0.0f, 0.1f, 0.0f);
        steps = 10;
        w3d_sweep_800b0824(&self->bottom, &dir, &zero, steps, 1);
        if (lbl_804b1764 < steps) {
            self->f692 = 1;
            float one = 1.0f;
            for (unsigned i = 4; i <= 7; i++) {
                from = self->corner[i];
                if (i == 7) dir = self->corner[4] - self->corner[7];
                else dir = self->corner[i + 1] - self->corner[i];
                steps = (int)dir.len() + 1;
                if (!dir.Same(lbl_8045e788[0])) dir.Scale(one / dir.len());
                w3d_sweep_800b0824(&from, &dir, &zero, steps, 1);
                if (lbl_804b1764 < steps) {
                    self->f700 = 1;
                    self->blocked++;
                }
            }
            if (self->blocked > 9 || self->f716) self->f712 = 1;
        }
        for (unsigned i = 2; i <= 3; i++) {
            w3d_ray_begin_801262c0(self->ray764, &self->ray[i]);
            w3d_ray_cast_80126384(self->ray764, &dir, steps);
            if (w3d_ray_hit_801264fc(self->ray764) != 0xffff) self->f708 = 1;
        w3d_ray_end_80126524(self->ray764);
        }
        break;
    }
}


