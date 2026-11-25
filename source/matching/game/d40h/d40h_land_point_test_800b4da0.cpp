// GWMP8P rev0 0x800b4da0. Terrain point test. Maps a point into land grid
// space through the layer bounds and the bilinear height field, tests the
// voxel grid, and when the corner blend flag is set compares the blended
// corner height against the point's fraction. The hit voxel is left in the
// shared statics. Statics are named by address; names are inferred.
struct Vec { float x, y, z; };
struct Pair { float lo, hi; };
struct Grid;
extern "C" int grid_test_8002c73c(Grid *, int, int, int, int);
extern float lbl_804ae4b0, lbl_804ae4b4;
extern Pair *lbl_804ae4b8, *lbl_804ae4bc;
extern float *lbl_804ae4c0, *lbl_804ae4c4;
extern signed char lbl_804ae4c9, lbl_804ae4cb, lbl_804ae4cc, lbl_804ae4cd, lbl_804ae4ce;
extern float lbl_804ae4d0, lbl_804ae4d8, lbl_804ae4e0, lbl_804ae4dc, lbl_804ae4e4;
extern Grid *lbl_804ae4e8;
extern unsigned char *lbl_804ae4f0;
extern int lbl_804ae4f8;
extern float lbl_804ae4fc, lbl_804ae500, lbl_804ae504, lbl_804ae508, lbl_804ae50c;
extern unsigned char *lbl_804b1800;
extern float lbl_8038252c[], lbl_8038258c[], lbl_8038264c[];
struct Owner { char unknown0[448]; unsigned char blend; };
struct Land { void **vt; Owner *owner; };
extern "C" int d40h_land_point_test_800b4da0(Land *self, Vec *p) {
    float y = p->y;
    int iy = (int)y;
    if (iy < 0) iy = 0;
    int top = lbl_804ae4c9 - 1;
    if (iy > top) iy = top;
    float fy = y - (float)iy;
    float inv = 1.0f - fy;
    float lo = lbl_804ae4b8[iy + 1].lo * fy + lbl_804ae4b8[iy].lo * inv;
    float hi = lbl_804ae4bc[iy + 1].lo * fy + lbl_804ae4bc[iy].lo * inv;
    p->x = (p->x - lo) / ((hi - lo) / lbl_804ae4d0 + 1.0f);
    signed char ix = (signed char)p->x;
    lo = lbl_804ae4b8[iy + 1].hi * fy + lbl_804ae4b8[iy].hi * inv;
    hi = lbl_804ae4bc[iy + 1].hi * fy + lbl_804ae4bc[iy].hi * inv;
    p->z = (p->z - lo) / ((hi - lo) / lbl_804ae4d8 + 1.0f);
    signed char iz = (signed char)p->z;
    if (p->x >= 0.0f && p->z >= 0.0f && p->x < lbl_804ae4d0 && p->z < lbl_804ae4d8) {
        int w = lbl_804ae4ce;
        float *col = lbl_804ae4c0 + ix;
        float fx = p->x - (float)ix, fz = p->z - (float)iz;
        lbl_804ae4dc = fx;
        lbl_804ae4e4 = fz;
        float *row = col + iz * w;
        lbl_804ae4c4 = row;
        float ifx = 1.0f - fx;
        float ifz = 1.0f - fz;
        p->y = y - ((*row * ifx + row[1] * fx) * ifz + (row[w] * ifx + row[w + 1] * fx) * fz);
        int iv = (int)p->y;
        lbl_804ae4e0 = p->y - (float)iv;
        if (p->y >= 0.0f && iv < lbl_804ae4c9) {
            signed char iv8 = (signed char)iv;
            if (grid_test_8002c73c(lbl_804ae4e8, ix, iv8, iz, 4)) {
                int width = lbl_804ae4ce;
                int layers = lbl_804ae4c9;
                lbl_804ae4f8 = 0;
                int stride = layers + 1;
                int i0 = iv8 + (ix + iz * width) * stride + 1;
                int a = i0 + 1; int i1 = a + layers;
                int i2 = i1 + width * stride;
                int b = i2 - 1; int i3 = b - layers;
                int ok;
                unsigned c0, c1, c2, c3;
                float sum = lbl_804ae4dc + lbl_804ae4e4;
                if (sum < 0.5f) {
                    c0 = lbl_804ae4f0[i0];
                    if (!(c0 & 0xee)) { lbl_804ae4f8 = 1; ok = 0; goto done; }
                    c1 = lbl_804ae4f0[i1]; c3 = lbl_804ae4f0[i3]; c2 = lbl_804ae4f0[i2];
                } else if (lbl_804ae4dc - lbl_804ae4e4 > 0.5f) {
                    c1 = lbl_804ae4f0[i1];
                    if (!(c1 & 0xdd)) { lbl_804ae4f8 = 1; ok = 0; goto done; }
                    c0 = lbl_804ae4f0[i0]; c3 = lbl_804ae4f0[i3]; c2 = lbl_804ae4f0[i2];
                } else if (lbl_804ae4e4 - lbl_804ae4dc > 0.5f) {
                    c3 = lbl_804ae4f0[i3];
                    if (!(c3 & 0xbb)) { lbl_804ae4f8 = 1; ok = 0; goto done; }
                    c0 = lbl_804ae4f0[i0]; c1 = lbl_804ae4f0[i1]; c2 = lbl_804ae4f0[i2];
                } else if (sum > 1.5f) {
                    c2 = lbl_804ae4f0[i2];
                    if (c2 & 0x77) { c0 = lbl_804ae4f0[i0]; c1 = lbl_804ae4f0[i1]; c3 = lbl_804ae4f0[i3]; } else { lbl_804ae4f8 = 1; ok = 0; goto done; }
                } else {
                    c0 = lbl_804ae4f0[i0]; c1 = lbl_804ae4f0[i1]; c3 = lbl_804ae4f0[i3]; c2 = lbl_804ae4f0[i2];
                }
                if (self->owner->blend) {
                    unsigned char *t = lbl_804b1800;
                    c0 = t[c0]; c1 = t[c1]; c3 = t[c3]; c2 = t[c2];
                    if (lbl_804ae4dc < 0.5f) {
                        if (lbl_804ae4e4 < 0.5f) {
                            lbl_804ae4fc = lbl_8038252c[c0];
                            lbl_804ae500 = lbl_8038258c[c0 + c1];
                            lbl_804ae504 = lbl_8038258c[c0 + c3];
                            lbl_804ae508 = lbl_8038264c[(c0 + c1 + c3 + c2) >> 1];
                            lbl_804ae4b0 = 0.0f;
                            lbl_804ae4b4 = 0.0f;
                        } else {
                            lbl_804ae4fc = lbl_8038258c[c0 + c3];
                            lbl_804ae500 = lbl_8038264c[(c0 + c1 + c3 + c2) >> 1];
                            lbl_804ae504 = lbl_8038252c[c3];
                            lbl_804ae508 = lbl_8038258c[c3 + c2];
                            lbl_804ae4b0 = 0.0f;
                            lbl_804ae4b4 = 0.5f;
                        }
                    } else if (lbl_804ae4e4 < 0.5f) {
                        lbl_804ae4fc = lbl_8038258c[c0 + c1];
                        lbl_804ae500 = lbl_8038252c[c1];
                        lbl_804ae504 = lbl_8038264c[(c0 + c1 + c3 + c2) >> 1];
                        lbl_804ae508 = lbl_8038258c[c1 + c2];
                        lbl_804ae4b0 = 0.5f;
                        lbl_804ae4b4 = 0.0f;
                    } else {
                        lbl_804ae4fc = lbl_8038264c[(c0 + c1 + c3 + c2) >> 1];
                        lbl_804ae500 = lbl_8038258c[c1 + c2];
                        lbl_804ae504 = lbl_8038258c[c3 + c2];
                        lbl_804ae508 = lbl_8038252c[c2];
                        lbl_804ae4b0 = 0.5f;
                        lbl_804ae4b4 = 0.5f;
                    }
                    float a = lbl_804ae4fc;
                    float dx = lbl_804ae500 - a, dz = lbl_804ae504 - a;
                    lbl_804ae504 = dz;
                    lbl_804ae500 = dx;
                    float d = lbl_804ae508 - (dx + dz + a);
                    lbl_804ae508 = d;
                    float u = (lbl_804ae4dc - lbl_804ae4b0) + (lbl_804ae4dc - lbl_804ae4b0);
                    float t2 = (lbl_804ae4e4 - lbl_804ae4b4) + (lbl_804ae4e4 - lbl_804ae4b4);
                    float val = u * t2 * d + (t2 * dz + (u * dx + a));
                    lbl_804ae50c = val;
                    ok = 0; if (!(lbl_804ae4e0 > val)) ok = 1;
                } else ok = 1;
done:
                if (ok) {
                    lbl_804ae4cb = ix;
                    lbl_804ae4cc = iv8;
                    lbl_804ae4cd = iz;
                    return 1;
                }
            }
        }
    }
    return 0;
}
