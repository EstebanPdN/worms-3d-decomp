#include "w3d_ptr.h"
#line 1 "d33g_water_shade_8007eb54.cpp"
// GWMP8P rev0 0x8007eb54. Water shading pass: a flat mesh shades each vertex
// from a lookup table; otherwise each vertex is traced toward the light
// along the sun direction and the trace range gives the shade. Both paths
// darken the stored colour, write a packed output word and store the
// average. Sibling of 0x8007ef70. Field names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
    void Take(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void Scale(float f) { x *= f; y *= f; z *= f; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline void Cross(Vec &o, const Vec &a, const Vec &b) {
    o.x = a.y * b.z - a.z * b.y;
    o.y = a.z * b.x - a.x * b.z;
    o.z = a.x * b.y - a.y * b.x;
}
extern "C" void w3d_sweep_800b0824(Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<const Vec>, int, int);
struct Light { char unknown00[104]; Vec position; };
extern Ptr32<Light> lbl_804b17e0;
extern unsigned lbl_804b1764;
extern Vec lbl_8043add8[], lbl_8043ade4[];
extern "C" void w3d_copy_vectors_800bd808(Ptr32<Light>);
struct Tile { unsigned short key; unsigned short a; }; /* palabra de 32 bits: key es la mitad baja, PPC +2 */
struct Batch { char unknown00[104]; unsigned short count; };
struct Mesh {
    char unknown00[248]; Vec dir; char unknown260[412]; Ptr32<Vec> positions; char unknown676[4]; Ptr32<unsigned int> colors; char unknown684[12]; Ptr32<unsigned char> lut; int flat;
    char unknown704[1774]; unsigned short count;
};
inline void SetRay(const Vec &s, const Vec &d, unsigned range) { lbl_8043add8[0] = s; lbl_8043ade4[0] = d; lbl_804b1764 = range; }
extern "C" void w3d_d33g_water_shade_8007eb54(Ptr32<Mesh> self, Ptr32<Batch> batch, Ptr32<const Tile> tiles, Ptr32<unsigned int> out) {
    Ptr32<const Tile> t = tiles;
    unsigned sum = 0;
    unsigned c;
    if (self->flat) {
        for (unsigned i = 0; i < self->count; i++) {
            Ptr32<unsigned char> lut = self->lut;
            Ptr32<unsigned int> colors = self->colors;
            c = colors[i];
            unsigned b = t->key;
            b = lut[b];
            unsigned low = c & 0xff;
            sum += b;
            if (b <= 149) {
                unsigned n = b + 105;
                if (low > n) colors[i] = (c & 0xff00) | n;
            }
            *out = (b << 24) + (low << 16) + t->key;
            t++;
            out++;
        }
        sum /= self->count;
        *out = sum;
        batch->count = self->count;
    } else {
        Vec start(0.0f, 0.0f, 0.0f);
        Vec spot(0.0f, 0.0f, 0.0f);
        w3d_sweep_800b0824(&start, &self->dir, &spot, 300, 0);
        Vec up(0.0f, 1.0f, 0.0f);
        Vec side;
        Cross(side, up, self->dir);
        Cross(up, side, self->dir);
        float one = 1.0f;
        up.Scale(one / up.len());
        one = one / side.len();
        side.Scale(one);
        up.Scale(0.05f);
        side.Scale(0.05f);
        Vec far;
        const Vec &dd = self->dir;
        Vec scaled(dd.x * 10.0f, dd.y * 10.0f, dd.z * 10.0f);
        far.Take(scaled);
        far -= lbl_804b17e0->position;
        for (unsigned i = 0; i < self->count; i++) {
            start = self->positions[i] + far;
            SetRay(start, self->dir, 1000);
            w3d_copy_vectors_800bd808(lbl_804b17e0);
            Ptr32<unsigned int> colors = self->colors;
            c = colors[i];
            unsigned b = lbl_804b1764;
            b = b * 150 / 1000;
            unsigned low = c & 0xff;
            sum += b;
            if (b <= 149) {
                unsigned n = b + 105;
                if (low > n) colors[i] = (c & 0xff00) | n;
            }
            *out = (b << 24) + (low << 16) + t->key;
            t++;
            out++;
        }
        sum /= self->count;
        *out = sum;
        batch->count = 0;
    }
}


