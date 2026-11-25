#include "w3d_ptr.h"
#line 1 "d31b_cube_corners_800840f0.cpp"
/* Cube corner vertices (0x800840f0): for each of the eight corners of a terrain cell (grid links +1, +19,
 * +325, +343, +0, +18, +324, +342 from the current cell at +564) and for each of the two vertex sets whose
 * corner mask is set in 0x804adb20 / 0x804adb24, when the corner's 16-bit link (low half for set A, high half
 * for set B of the word at +2492) is still 0xffff, builds the vertex: position + corner offset from the size
 * table 0x804adb38 and the height table 0x8037cf4c indexed by level byte 0x804ada6c + rotated offset at
 * +2572, publishes it in 0x80431460, appends grid index (+692), position (+672), uv from the planes at
 * +400/+412 or +424/+436 with bias +464 or +472 (+676), doubled corner colour 0x804ada74 (+680), and records
 * the vertex number from the counter +2478 in the link. Field names are inferred from the original
 * instructions; layouts are partial views. Owns the literal 1.0 at 0x8037cf30. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Uv { float u, v; };
union Link { unsigned w; struct { unsigned short lo; unsigned short hi; } h; };
struct Cube {
    char unknown000[400]; Vec a0, a1, b0, b1; char unknown448[16]; float a2[2], b2[2]; char unknown480[84];
    int cur; char unknown568[104]; Ptr32<Vec> pos; Ptr32<Uv> uv; Ptr32<unsigned int> col; char unknown684[8]; Ptr32<int> ref; char unknown696[1782];
    unsigned short count; char unknown2480[12]; Ptr32<Link> links; char unknown2496[40]; float y[4]; char unknown2552[20]; Vec rot[16];
};
extern unsigned w3d_flags_a_804adb20;
extern unsigned w3d_flags_b_804adb24;
extern const float w3d_h_8037cf4c[];
extern Vec w3d_vert_80431460;
extern unsigned char w3d_level_804ada6c;
extern float w3d_size_804adb38;
extern unsigned char w3d_level_804ada6d;
extern float w3d_size_804adb3c;
extern unsigned char w3d_level_804ada6e;
extern float w3d_size_804adb40;
extern unsigned char w3d_level_804ada6f;
extern float w3d_size_804adb44;
extern unsigned char w3d_level_804ada70;
extern float w3d_size_804adb48;
extern unsigned char w3d_level_804ada71;
extern float w3d_size_804adb4c;
extern unsigned char w3d_level_804ada72;
extern float w3d_size_804adb50;
extern unsigned char w3d_level_804ada73;
extern float w3d_size_804adb54;
extern unsigned w3d_col_804ada74;
extern unsigned w3d_col_804ada78;
extern unsigned w3d_col_804ada7c;
extern unsigned w3d_col_804ada80;
extern unsigned w3d_col_804ada84;
extern unsigned w3d_col_804ada88;
extern unsigned w3d_col_804ada8c;
extern unsigned w3d_col_804ada90;
extern unsigned w3d_col_804ada94;
extern unsigned w3d_col_804ada98;
extern unsigned w3d_col_804ada9c;
extern unsigned w3d_col_804adaa0;
extern unsigned w3d_col_804adaa4;
extern unsigned w3d_col_804adaa8;
extern unsigned w3d_col_804adaac;
extern unsigned w3d_col_804adab0;
extern "C" void w3d_d31b_cube_corners_800840f0(Ptr32<Cube> self, Ptr32<const Vec> p, int n) {
    if (w3d_flags_a_804adb20 & 1) {
        if ((self->links[self->cur + 1].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb38, w3d_h_8037cf4c[w3d_level_804ada6c] + self->y[0], w3d_size_804adb38) + self->rot[(n) & 15];
            self->ref[self->count] = self->cur + 1;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada74 * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 1].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 1) {
        if ((self->links[self->cur + 1].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb38, w3d_h_8037cf4c[w3d_level_804ada6c] + self->y[0], w3d_size_804adb38) + self->rot[(n) & 15];
            self->ref[self->count] = self->cur + 1;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada94 * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 1].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 4) {
        if ((self->links[self->cur + 19].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb3c, w3d_h_8037cf4c[w3d_level_804ada6d] + self->y[1], w3d_size_804adb3c) + self->rot[(n + 1) & 15];
            self->ref[self->count] = self->cur + 19;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada78 * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 19].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 4) {
        if ((self->links[self->cur + 19].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb3c, w3d_h_8037cf4c[w3d_level_804ada6d] + self->y[1], w3d_size_804adb3c) + self->rot[(n + 1) & 15];
            self->ref[self->count] = self->cur + 19;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada98 * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 19].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 64) {
        if ((self->links[self->cur + 325].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb40, w3d_h_8037cf4c[w3d_level_804ada6e] + self->y[2], 1.0f - w3d_size_804adb40) + self->rot[(n + 2) & 15];
            self->ref[self->count] = self->cur + 325;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada7c * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 325].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 64) {
        if ((self->links[self->cur + 325].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb40, w3d_h_8037cf4c[w3d_level_804ada6e] + self->y[2], 1.0f - w3d_size_804adb40) + self->rot[(n + 2) & 15];
            self->ref[self->count] = self->cur + 325;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada9c * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 325].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 256) {
        if ((self->links[self->cur + 343].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb44, w3d_h_8037cf4c[w3d_level_804ada6f] + self->y[3], 1.0f - w3d_size_804adb44) + self->rot[(n + 3) & 15];
            self->ref[self->count] = self->cur + 343;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada80 * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 343].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 256) {
        if ((self->links[self->cur + 343].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb44, w3d_h_8037cf4c[w3d_level_804ada6f] + self->y[3], 1.0f - w3d_size_804adb44) + self->rot[(n + 3) & 15];
            self->ref[self->count] = self->cur + 343;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa0 * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 343].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 512) {
        if ((self->links[self->cur].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb48, self->y[0] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada70], w3d_size_804adb48) + self->rot[(n + 4) & 15];
            self->ref[self->count] = self->cur;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada84 * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 512) {
        if ((self->links[self->cur].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb48, self->y[0] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada70], w3d_size_804adb48) + self->rot[(n + 4) & 15];
            self->ref[self->count] = self->cur;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa4 * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 2048) {
        if ((self->links[self->cur + 18].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb4c, self->y[1] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada71], w3d_size_804adb4c) + self->rot[(n + 5) & 15];
            self->ref[self->count] = self->cur + 18;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada88 * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 18].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 2048) {
        if ((self->links[self->cur + 18].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb4c, self->y[1] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada71], w3d_size_804adb4c) + self->rot[(n + 5) & 15];
            self->ref[self->count] = self->cur + 18;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa8 * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 18].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 32768) {
        if ((self->links[self->cur + 324].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb50, self->y[2] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada72], 1.0f - w3d_size_804adb50) + self->rot[(n + 6) & 15];
            self->ref[self->count] = self->cur + 324;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada8c * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 324].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 32768) {
        if ((self->links[self->cur + 324].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_size_804adb50, self->y[2] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada72], 1.0f - w3d_size_804adb50) + self->rot[(n + 6) & 15];
            self->ref[self->count] = self->cur + 324;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaac * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 324].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 131072) {
        if ((self->links[self->cur + 342].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb54, self->y[3] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada73], 1.0f - w3d_size_804adb54) + self->rot[(n + 7) & 15];
            self->ref[self->count] = self->cur + 342;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada90 * 2;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 342].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 131072) {
        if ((self->links[self->cur + 342].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(1.0f - w3d_size_804adb54, self->y[3] + 1.0f - w3d_h_8037cf4c[w3d_level_804ada73], 1.0f - w3d_size_804adb54) + self->rot[(n + 7) & 15];
            self->ref[self->count] = self->cur + 342;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adab0 * 2;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 342].h.hi = self->count++;
        }
    }
}


