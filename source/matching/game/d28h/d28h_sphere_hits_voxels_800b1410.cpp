// GWMP8P rev0 0x800b1410. Tests whether a sphere touches solid terrain.
// Names are inferred. Transforms the centre to local space, scales the
// radius per axis, then walks the terrain blocks whose bounds contain the
// centre, testing each block's 7x7x7 cells for a solid voxel inside the
// ellipsoid.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
    float lenSq() const { return x * x + y * y + z * z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Axis { float x, y, z; };
struct Pos { float x, y, z; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &A(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x + P().x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y + P().y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z + P().z;
    }
};
struct Sphere { Vec center; float radius; };
struct Block { char u0[20]; Sphere sphere; char u36[12]; unsigned char x, z, y; };
struct BlockArray { char u0[32]; Block *data[1]; };
struct VoxelData { char u0[4]; unsigned short kind; char u6[18]; void *h24; unsigned short refs; char u30[2]; char data[1]; };
struct VoxelRef;
extern "C" char *lock_801ef048(VoxelRef *, int, int, int);
struct VoxelRef {
    VoxelData *p;
    char *Lock() {
        VoxelData *d = p;
        void *h = d->h24;
        if (d->kind == 1) { d->refs++; return d->data; }
        return lock_801ef048(this, (int)h, 4, 2);
    }
};
struct Terrain {
    char u0[44];
    BlockArray *blocks; // +44
    char u48[144];
    Transform toLocal;  // +192
    char u240[132];
    Vec scale;          // +372
    char u384[56];
    VoxelRef voxels;    // +440
    char u444[10];
    unsigned char nx, ny, nz; // +454
};
struct Self { void *vt; Terrain *terrain; };
struct Game { char u0[104]; Vec origin; };
extern Game *g_game_804b17e0;
extern "C" int grid_test_8002c73c(char *, int, int, int, int);
extern "C" void cell_center_800b41c4(Self *, unsigned char, unsigned char, unsigned char, Vec *);
extern "C" int d28h_sphere_hits_voxels_800b1410(Self *self, const Vec &c, float radius) {
    Vec p;
    self->terrain->toLocal.apply(p, c);
    Vec r;
    Vec q;
    Terrain *t = self->terrain;
    Vec s(t->scale);
    r.x = radius / s.x; r.y = radius / s.y; r.z = radius / s.z;
    Vec inv(1.0f / r.x, 1.0f / r.y, 1.0f / r.z);
    Block **b = t->blocks->data;
    char *v = t->voxels.Lock();
    Terrain *t2 = self->terrain;
    unsigned char mj = t2->nz - 1;
    unsigned char mk = t2->ny - 1;
    unsigned char mi = t2->nx - 1;
    Vec o(g_game_804b17e0->origin);
    for (unsigned char i = 0; i <= mi; i++)
        for (unsigned char j = 0; j <= mj; j++)
            for (unsigned char k = 0; k <= mk; k++, b++) {
                const Sphere &sp = (*b)->sphere;
                Vec d; d.x = sp.center.x - o.x; d.y = sp.center.y - o.y; d.z = sp.center.z - o.z;
                float rr = sp.radius;
                d -= c;
                if (d.x < rr && d.x > -rr && d.y < rr && d.y > -rr && d.z < rr && d.z > -rr) {
                    Block *e = *b;
                    unsigned char ez = e->y; unsigned char ey = e->z; unsigned char ex = e->x;
                    for (unsigned char l = 0; l <= 6; l++)
                        for (unsigned char m = 0; m <= 6; m++)
                            for (unsigned char n = 0; n <= 6; n++) {
                                int a0 = l + ex, a1 = m + ez, a2 = n + ey;
                                if (grid_test_8002c73c(v, a1, a2, a0, 0)) {
                                    cell_center_800b41c4(self, a1, a2, a0, &q);
                                    q -= p;
                                    q.x *= inv.x; q.y *= inv.y; q.z *= inv.z;
                                    if (q.lenSq() < 1.0f) return 1;
                                }
                            }
                }
            }
    return 0;
}
