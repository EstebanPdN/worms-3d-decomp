// GWMP8P rev0 0x80087128. Terrain mesh rebuild: clears the group counters,
// walks seven rows, bends and transforms every vertex through the layer
// tables and the matrix, snaps height to one sixteenth, then sets the group
// offsets and draw callbacks and renders.

extern "C" void *memset(void *, int, unsigned);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Vec *p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Row { float x, y, z; };
struct Mat {
    Row r[4];
    const Row &R(int i) const { return r[i]; }
    const Row &P() const { return r[3]; }
    void Transform(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
static inline int Min(int a, int b) { return a > b ? b : a; }
struct Grid { float a, b; };
struct Shorts { short *start; short *finish; char unknown08[4]; short &operator[](unsigned i) { return *(short *)((char *)start + i * 2); } unsigned size() const { return finish - start; } };
struct Proto { char unknown00[288]; Vec center; char unknown300[157]; unsigned char zCells; unsigned char levels; unsigned char xCells; };
struct Mesh {
    char unknown00[44]; void *draw44; void *draw48; char *base52; char unknown56[264];
    Mat mat; char unknown368[128]; float *firstP; char unknown500pad[8]; unsigned firstRow; Grid *low; Grid *high; Vec offset; Proto *proto; int preview;
    char unknown540[132]; Vec *verts; char unknown676[44]; char *flags; char unknown724[1580];
    void **offs2304; char unknown2308[56]; Shorts s2364;  void **offs2376; char unknown2380[56]; Shorts s2436; char unknown2448[28];
    unsigned short n2476; unsigned short count; char unknown2480[12]; void *buf2492; char unknown2496[268]; unsigned char tag2764;
};
extern "C" void w3d_preview_init_80091ee0(Mesh *);
extern "C" void w3d_row_80086b08(Mesh *, unsigned, int, float *, Vec *, int, char *, unsigned char);
extern "C" int w3d_cells_80087628(Mesh *, int, int);
extern "C" void w3d_render_8010d8a4(Mesh *, int, int);
extern "C" void lbl_8010abc8(), lbl_8010ad20();
extern const float lbl_8037d0c4[];
struct Stride { char unknown00[492]; unsigned char stride; };
extern "C" int d41g_terrain_mesh_build_80087128(Mesh *self, int a, int b) {
    if (self->preview) w3d_preview_init_80091ee0(self);
    unsigned n = self->s2364.size();
    int s;
    for (unsigned i = 0; i < n; i++) { s = i * 2; *(short *)((char *)self->s2364.start + s) = 0; *(short *)((char *)self->s2436.start + s) = 0; }
    self->n2476 = 0;
    self->count = 0;
    char *flags = self->flags;
    flags += 91;
    float *p = self->firstP;
    const float zero = lbl_8037d0c4[0];
    Vec pos(zero, zero, zero);
    Vec t, o;
    int out = 343;
    unsigned char tag = self->tag2764;
    memset(self->buf2492, 255, 11664);
    for (int k = 1; k <= 7; k++) {
        t.Set(pos);
        w3d_row_80086b08(self, self->firstRow + k - 1, out, p, &t, b, flags, tag);
        pos.z += 1.0f;
        tag += 2;
        out += 324;
        p += ((Stride *)self)->stride;
        flags += 81;
    }
    Vec c(self->proto->center);
    unsigned j;
    for (j = 0; j < self->count; j++) {
        Vec &v = *(Vec *)(j * 12 + (unsigned)self->verts);
        t = v + self->offset;
        float y = t.y;
        int k = (int)y;
        if (k < 0) k = 0;
        Proto *pr = self->proto;
        s = pr->levels;
        int levels = s - 1;
        if (k > levels) k = levels;
        float f = y - (float)k;
        float g = 1.0f - f;
        Grid *l = (Grid *)((k << 3) + (unsigned)self->low), *h = (Grid *)((k << 3) + (unsigned)self->high);
        float e = l[1].a * f + l[0].a * g;
        float u = h[1].a * f + h[0].a * g;
        float x = t.x;
        t.x = x + (e + x * (u - e) / (float)pr->xCells);
        e = l[1].b * f + l[0].b * g;
        u = h[1].b * f + h[0].b * g;
        float z = t.z;
        z = z + (e + z * (u - e) / (float)pr->zCells);
        float px = t.x - c.x, py = y - c.y, pz = z - c.z;
        t.x = px; t.y = py; t.z = pz;
        self->mat.Transform(o, t);
        o.y = (float)((int)(o.y * 16.0f) & ~1) * 0.0625f;
        v = o;
    }
    w3d_cells_80087628(self, a, b);
    char *base = self->base52;
    for (j = 0; j < n; j++) {
        *(char **)((char *)self->offs2304 + (j << 2)) = base;
        *(char **)((char *)self->offs2376 + (j << 2)) = base + 8;
        base += 16;
    }
    self->draw44 = (void *)lbl_8010abc8;
    self->draw48 = (void *)lbl_8010ad20;
    w3d_render_8010d8a4(self, a, b);
    return 0;
}
