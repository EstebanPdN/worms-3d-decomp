// GWMP8P rev0 0x8013c5f0. Pick the worm aim: among the other 16 worm records
// that are alive, take the nearest within squared range 28900 (170 units)
// that passes aim test 0x8013b5bc and keep its heading and elevation. Then
// position the sphere finder (+720) at the worm and, if it reports a hit,
// prefer the shared target when nearer and in range. Apply the result
// through 0x8013c21c. Names are inferred; the raised copy of the position is
// a real dead store in the original.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline float distSq(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
struct Info { unsigned char u0[44]; Vec dir; unsigned char u56[24]; Vec pos; unsigned char u92[128]; int alive; };
struct Mesh;
struct Worm {
    unsigned char u0[20]; int id;
    unsigned char u24[28]; Vec pos; Vec rot;
    unsigned char u76[36]; int index;
    unsigned char u116[604]; char finder[4];
    const Vec &Pos() const { return pos; }
};
extern "C" Info *index_query_800fc6dc(int);
extern "C" int aim_8013b5bc(Worm *, const Vec &, const Vec &, const Vec &, float *);
extern "C" float elevation_8013b898(Worm *, const Vec &, const Vec &);
extern "C" void query_801262c0(void *, const Vec &);
extern "C" int nearest_801263fc(void *, const Vec *, int, int);
extern "C" Vec *targetpos_8003f240(unsigned short);
extern "C" void apply_8013c21c(Worm *, Mesh *, float, float);
extern unsigned short target_804aa95e;
extern "C" void d25d_worm_pick_aim_8013c5f0(Worm *self, Mesh *mesh) {
    float pitch = 0.0f, best = 28900.0f;
    int found = -1;
    float yaw = pitch, limit = best;
    float out;
    for (int i = 0; i <= 15; i++) {
        if (i != self->index) {
            Info *in = index_query_800fc6dc(i);
            if (in->alive) {
                const Vec &p = in->pos;
                float q = distSq(p, self->Pos());
                if (q < limit && (found == -1 || q < best)
                    && aim_8013b5bc(self, p, self->Pos(), self->rot, &out)) {
                    yaw = out;
                    pitch = elevation_8013b898(self, p, self->Pos());
                    best = q;
                    found = i;
                }
            }
        }
    }
    Info *me = index_query_800fc6dc(self->index);
    Vec dir = me->dir;
    Vec at = self->Pos();
    at.y += 15.0f;
    query_801262c0(self->finder, self->Pos());
    if (nearest_801263fc(self->finder, &dir, 20, self->id) != 65535) {
        Vec t = *targetpos_8003f240(target_804aa95e);
        if (distSq(t, self->Pos()) < best && aim_8013b5bc(self, t, self->Pos(), self->rot, &out)) {
            yaw = out;
            pitch = elevation_8013b898(self, t, self->Pos());
        }
    }
    apply_8013c21c(self, mesh, yaw, pitch);
}
