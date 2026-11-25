// (Worms 3D GameCube PAL, 0x801a46bc).
//
// Picks the level of detail for a mesh node: transforms the node centre by
// the world matrix, takes the view depth clamped at zero, scans the
// ascending limits table for the first limit not below it and stores that
// index as the level (returns 0 when past the last limit), then calls the
// renderer's draw slot chosen by the top ten bits of the active slot record.

struct Vec {
    float x, y, z;
};
struct Row { float x, y, z, w; };
struct Matrix {
    Row rows[3];
    Row position;
    const Row &R(int i) const { return rows[i]; }
    const Row &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        float a = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        float b = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        float c = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
        o.x = a;
        o.y = b;
        o.z = c;
    }
};
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Table { char pad[24]; unsigned count; int pad2; float limits[1]; };
struct Lod { char pad[20]; int locked; float level; Vec centre; Table *table; };
struct Slots { char pad[32]; unsigned slot : 10; };
extern Slots *slots_80363b18[];
struct Self;
typedef int (*Fn)(Self *, Lod *);
struct Self { char pad[24]; Fn *table; };
extern "C" int w3d_d27e_lod_select_801a46bc(Self *self, Lod *n, const Matrix *m) {
    if (n->locked == 0) {
        Vec o;
        Table *t = n->table;
        unsigned count = t->count;
        const float *limits = t->limits;
        m->apply(o, n->centre);
        float d = fmax(0.0f, -o.z);
        unsigned i = 0;
        while (limits[i] < d) {
            if (++i == count) return 0;
        }
        n->level = (float)i;
    }
    return self->table[slots_80363b18[0]->slot](self, n);
}
