#include "w3d_ptr.h"
#line 1 "d26d_worm_trace_corners_801412a4.cpp"
// GWMP8P rev0 0x801412a4. Sweep a worm's eleven collision points: trace the
// centre, then probe the ten corners, and keep the nearest accepted hit
// (point relative to the corner, normal, material words, corner index). A
// zero-distance hit moving away from the normal is ignored. The rotation
// matrix is built and never read in the original. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Hit { unsigned frac; Vec point; Vec normal; int a; int b; int index; };
struct Matrix { float m[16]; };
extern "C" void rotation_801f725c(Ptr32<Matrix>, float, float, float, float);
extern "C" void trace_800b0cf8(float, const Vec &, const Vec &, Ptr32<void>, int, int);
extern "C" void probe_800b11dc(const Vec &, int);
extern "C" void compute_800bd920();
extern Vec corners_80453030[];
extern Vec centre_804530a8;
extern Vec tracePoint_8043ae20;
extern Vec traceNormal_8043ae38;
extern float traceRange_804ab3cc;
extern unsigned traceFrac_804b1764;
extern int traceDone_804b1810;
extern int traceReady_804b1784;
extern int traceB_804b17a8;
extern int traceA_804b17ac;
extern "C" void d26d_worm_trace_corners_801412a4(Ptr32<Hit> self, const Vec &pos, const Vec &dir, Ptr32<void> user, const Vec &rot, int id) {
    self->frac = id + 1;
    Matrix m;
    rotation_801f725c(&m, 0.0f, 1.0f, 0.0f, rot.y);
    self->index = 0;
    Vec o, start;
    start = pos + centre_804530a8;
    trace_800b0cf8(traceRange_804ab3cc, start, dir, user, id, 1);
    for (int i = 0; i <= 9; i++) {
        o = corners_80453030[i];
        start = pos + o;
        probe_800b11dc(start, id);
        unsigned f = traceFrac_804b1764;
        if (f < self->frac && !traceDone_804b1810) {
            if (!traceReady_804b1784) compute_800bd920();
            Vec n = traceNormal_8043ae38;
            if (f == 0) {
                Vec d = dir;
                if (d.dot(n) >= 0.0f) continue;
            }
            self->frac = f;
            self->point = tracePoint_8043ae20 - o;
            self->normal = n;
            self->b = traceB_804b17a8;
            self->a = traceA_804b17ac;
            self->index = i;
        }
    }
}


