// GWMP8P rev0 0x8007ef70. Shades water cells by tracing from each cell
// position toward the light along the sun direction: the trace range sets
// the shade byte, and the colour nibbles come from a palette entry chosen by
// the shade. Sibling of 0x8007eb54. Field names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Vec *p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
    void Set(float a, float b, float c) { Vec *p = this; x = a; p->y = b; p->z = c; }
    void Add(const Vec &o) { Vec *p = this; x += o.x; p->y += o.y; p->z += o.z; }
    void Sum(const Vec &a, const Vec &b) { Vec *p = this; x = a.x + b.x; p->y = a.y + b.y; p->z = a.z + b.z; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
extern "C" void trace_800b0cf8(float, const Vec *, const Vec *, const Vec *, int, int);
struct Light { char unknown00[104]; Vec position; };
extern Light *lbl_804b17e0;
extern unsigned lbl_804b1764;
extern Vec lbl_8043add8[];
extern "C" void collect_800bcd6c(Light *);
extern "C" void collect_800bd8a0(Light *);
struct Sphere { Vec center; float radius; };
struct Cell { unsigned char shade; unsigned char low; unsigned short pad; };
struct Short3 { short x, y, z; };
struct Color { unsigned short r : 4, g : 4, b : 4, a : 4; };
struct Self { char unknown00[248]; Vec dir; };
inline unsigned short Hi(const unsigned short &c, unsigned m) { return c & m; }
inline unsigned char Lo(const unsigned short &c) { return ((const unsigned char *)&c)[1]; }
inline void Merge(unsigned short &d, unsigned keep, const unsigned short &v) { unsigned short t = d & keep; d = t | v; }
extern "C" void w3d_d33g_water_shade_cells_8007ef70(Self *self, Cell *cells, unsigned short *dst, const Short3 *pos, unsigned count, const unsigned short *src, const Sphere *s) {
    Vec start(0.0f, 0.0f, 0.0f);
    Vec spot(0.0f, 0.0f, 0.0f);
    unsigned short i = 0;
    Vec far = self->dir * 10.0f;
    far -= lbl_804b17e0->position;
    start.Sum(s->center, far);
    trace_800b0cf8(s->radius, &start, &self->dir, &spot, 1000, 0);
    collect_800bcd6c(lbl_804b17e0);
    for (; i < count; ) {
        const Short3 &q = *(const Short3 *)(i * 6 + (int)pos);
        start.Set((float)q.x * 0.0625f, (float)q.y * 0.0625f, (float)q.z * 0.0625f);
        start.Add(far);
        lbl_8043add8[0] = start;
        unsigned range = 1000;
        lbl_804b1764 = range;
        collect_800bd8a0(lbl_804b17e0);
        unsigned b = lbl_804b1764 * 150 / 1000;
        unsigned n = b + 105;
        cells->shade = b;
        unsigned low = cells->low;
        if (low < n) n = low;
        Merge(dst[i], 0xfff, Hi(src[n], 0xf000));
        Merge(dst[i], 0xf0ff, Hi(src[n], 0xf00));
        Merge(dst[i], 0xff0f, Lo(src[n]) & 0xf0);
        i++;
        cells++;
    }
}
