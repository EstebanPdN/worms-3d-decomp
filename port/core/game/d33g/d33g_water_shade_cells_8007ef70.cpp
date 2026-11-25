#include "w3d_ptr.h"
#line 1 "d33g_water_shade_cells_8007ef70.cpp"
// GWMP8P rev0 0x8007ef70. Shades water cells by tracing from each cell
// position toward the light along the sun direction: the trace range sets
// the shade byte, and the colour nibbles come from a palette entry chosen by
// the shade. Sibling of 0x8007eb54. Field names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
    void Set(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    void Add(const Vec &o) { Ptr32<Vec> p = this; x += o.x; p->y += o.y; p->z += o.z; }
    void Sum(const Vec &a, const Vec &b) { Ptr32<Vec> p = this; x = a.x + b.x; p->y = a.y + b.y; p->z = a.z + b.z; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
extern "C" void trace_800b0cf8(float, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>, int, int);
struct Light { char unknown00[104]; Vec position; };
extern Ptr32<Light> lbl_804b17e0;
extern unsigned lbl_804b1764;
extern Vec lbl_8043add8[];
extern "C" void collect_800bcd6c(Ptr32<Light>);
extern "C" void collect_800bd8a0(Ptr32<Light>);
struct Sphere { Vec center; float radius; };
// Celda de 32 bits por vértice: (shade << 24) | (low << 16) | clave. Así la escriben 8007eb54 (palabra) y los .csh
// (land_held, copia de palabras), en el orden del host. El original la lee por bytes (byte 0 = shade, byte 1 = low), que
// en PowerPC son los bits 31-24 y 23-16. En la 3DS y el Mac (little-endian) los bytes 0 y 1 son la clave: low salía
// 1 o 2, el resombreado tras romperse el terreno elegía el color 1 de la paleta (casi negro) y machacaba la clave
// (aviso del dueño en la v21: el terreno roto se ennegrece poco a poco; volcados 006, 007 y 009).
typedef w3d_u32 Cell;
struct Short3 { short x, y, z; };
struct Color { unsigned short a:4; unsigned short b:4; unsigned short g:4; unsigned short r:4; };
struct Self { char unknown00[248]; Vec dir; };
inline unsigned short Hi(const unsigned short &c, unsigned m) { return c & m; }
// Byte 1 del u16 en PowerPC = byte bajo del valor. La paleta y los colores son u16 del host (GX los lee con rd16).
inline unsigned char Lo(const unsigned short &c) { return (unsigned char)(c & 0xff); }
inline void Merge(unsigned short &d, unsigned keep, const unsigned short &v) { unsigned short t = d & keep; d = t | v; }
extern "C" void w3d_d33g_water_shade_cells_8007ef70(Ptr32<Self> self, Ptr32<Cell> cells, Ptr32<unsigned short> dst, Ptr32<const Short3> pos, unsigned count, Ptr32<const unsigned short> src, Ptr32<const Sphere> s) {
    Vec start(0.0f, 0.0f, 0.0f);
    Vec spot(0.0f, 0.0f, 0.0f);
    unsigned short i = 0;
    Vec far = self->dir * 10.0f;
    far -= lbl_804b17e0->position;
    start.Sum(s->center, far);
    trace_800b0cf8(s->radius, &start, &self->dir, &spot, 1000, 0);
    collect_800bcd6c(lbl_804b17e0);
    for (; i < count; ) {
        const Short3 &q = *(Ptr32<const Short3>)w3d::G((i * 6 + (int)w3d::H(pos)));
        start.Set((float)q.x * 0.0625f, (float)q.y * 0.0625f, (float)q.z * 0.0625f);
        start.Add(far);
        lbl_8043add8[0] = start;
        unsigned range = 1000;
        lbl_804b1764 = range;
        collect_800bd8a0(lbl_804b17e0);
        unsigned b = lbl_804b1764 * 150 / 1000;
        unsigned n = b + 105;
        *cells = (*cells & 0x00ffffffu) | (w3d_u32)(b & 0xff) << 24;
        unsigned low = (*cells >> 16) & 0xff;
        if (low < n) n = low;
        Merge(dst[i], 0xfff, Hi(src[n], 0xf000));
        Merge(dst[i], 0xf0ff, Hi(src[n], 0xf00));
        Merge(dst[i], 0xff0f, Lo(src[n]) & 0xf0);
        i++;
        cells++;
    }
}


