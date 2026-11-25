#include "w3d_ptr.h"
#line 1 "d26h_camera_spline_step_800b01b0.cpp"
// GWMP8P rev0 0x800b01b0. Camera path spline step. Field names are inferred.
// A cardinal spline with tension-derived coefficients blends the four
// segment points; expression temporaries give the stack blocks the original
// writes.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { return Vec(x * k, y * k, z * k); }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct Node { unsigned char u0[4]; int name; Vec pos; int u20; Ptr32<Node> next; int u28; };
struct Msg { unsigned short id; Ptr32<void> table; };
struct Path {
    unsigned char u0[4];
    Ptr32<Node> cur;     // +4
    unsigned char u8[8];
    float t;       // +16
    float tension; // +20
    Ptr32<void> loop;    // +24
    Ptr32<void> frames;  // +28
};
extern "C" void segment_points_800afeb8(Ptr32<Node>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>, Ptr32<Vec>);
extern "C" unsigned frames_80178d1c(Ptr32<void>);
extern "C" int rename_801790bc(Ptr32<void>, int);
extern "C" Ptr32<Msg> arena_alloc_801613f0(Ptr32<void>, int);
extern "C" unsigned message_id_8015f5a0(Ptr32<void>, int);
extern "C" int message_post_8016239c(Ptr32<Msg>);
extern Ptr32<void> g_arena_804b1754;
extern unsigned char id_804ae460[8];
extern unsigned char table_8040db38[];
extern "C" int d26h_camera_spline_step_800b01b0(Ptr32<Path> self, Ptr32<Vec> out) {
    if (self->cur->next == 0) {
        *out = self->cur->pos;
        return 1;
    }
    float one = 1.0f;
    float s = (one - self->tension) * 0.5f;
    float t = self->t;
    float t2 = t * t;
    float t3 = t2 * t;
    float a = -s * t3 + (s + s) * t2 - s * t;
    float b = (2.0f - s) * t3 + (s - 3.0f) * t2 + one;
    float c = (s - 2.0f) * t3 + (3.0f - (s + s)) * t2 + s * t;
    float d = s * t3 - s * t2;
    Vec p0, p1, p2, p3;
    segment_points_800afeb8(self->cur, &p0, &p1, &p2, &p3);
    *out = p0 * a + p1 * b + p2 * c + p3 * d;
    self->t += one / (float)frames_80178d1c(self->frames);
    if (self->t > one) {
        self->t = 0.0f;
        self->cur = self->cur->next;
        rename_801790bc(self->loop, self->cur->name);
        Ptr32<Msg> m = arena_alloc_801613f0(g_arena_804b1754, 8);
        m->id = message_id_8015f5a0(id_804ae460, 1);
        m->table = table_8040db38;
        message_post_8016239c(m);
    }
    return 0;
}


