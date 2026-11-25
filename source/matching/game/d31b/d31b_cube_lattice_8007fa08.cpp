/* Cube lattice vertices (0x8007fa08): nine points on the top and nine on the bottom of a terrain cell
 * (corners, edge midpoints and the centre; grid links +1, +10, +19, +163, +172, +181, +325, +334, +343 and
 * those minus one below the current cell at +564), each for the two vertex sets gated bit by bit in
 * 0x804adb20 / 0x804adb24. When the point's 16-bit link (low half for set A, high half for set B of the word
 * at +2492) is still 0xffff, builds the vertex: position + point offset (0.0, 0.5 or 1.0, the edge table at
 * 0x804adaf4, and a height from the tables 0x8037cf4c, 0x8037cfac, 0x8037d06c indexed by the level bytes at
 * 0x804ada6c) + rotated offset at +2572 (not for the centre), publishes it in 0x80431460, appends grid index
 * (+692), position (+672), uv from the planes at +400/+412 or +424/+436 with bias +464 or +472 (+676) and
 * colour (+680: doubled corner colour 0x804ada74, sum of two for an edge, 0x804adb28 or 0x804adb30 for set A and zero for set B at the centre),
 * and records the vertex number from the counter +2478 in the link. Field names are inferred from the
 * original instructions; layouts are partial views. Owns the literals 0.0, 0.5, 1.0 at 0x8037cf24. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Uv { float u, v; };
union Link { unsigned w; struct { unsigned short hi, lo; } h; };
struct Cube {
    char unknown000[400]; Vec a0, a1, b0, b1; char unknown448[16]; float a2[2], b2[2]; char unknown480[84];
    int cur; char unknown568[104]; Vec *pos; Uv *uv; unsigned *col; char unknown684[8]; int *ref; char unknown696[1782];
    unsigned short count; char unknown2480[12]; Link *links; char unknown2496[40]; float y[4], m[5]; Vec rot[16];
};
extern unsigned w3d_flags_a_804adb20;
extern unsigned w3d_flags_b_804adb24;
extern const float w3d_h1_8037cf4c[];
extern const float w3d_h2_8037cfac[];
extern const float w3d_h4_8037d06c[];
extern Vec w3d_vert_80431460;
extern unsigned w3d_centre_col_804adb28;
extern unsigned w3d_centre_col_804adb30;
extern unsigned char w3d_level_804ada6c;
extern float w3d_edge_804adaf4;
extern unsigned char w3d_level_804ada6d;
extern float w3d_edge_804adaf8;
extern unsigned char w3d_level_804ada6e;
extern float w3d_edge_804adafc;
extern unsigned char w3d_level_804ada6f;
extern float w3d_edge_804adb00;
extern unsigned char w3d_level_804ada70;
extern float w3d_edge_804adb04;
extern unsigned char w3d_level_804ada71;
extern float w3d_edge_804adb08;
extern unsigned char w3d_level_804ada72;
extern float w3d_edge_804adb0c;
extern unsigned char w3d_level_804ada73;
extern float w3d_edge_804adb10;
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
extern "C" void w3d_d31b_cube_lattice_8007fa08(Cube *self, const Vec *p, int n) {
    if (w3d_flags_a_804adb20 & 1) {
        if ((self->links[self->cur + 1].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.0f, w3d_h1_8037cf4c[w3d_level_804ada6c] + self->y[0], 0.0f) + self->rot[n & 15];
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
            w3d_vert_80431460 = *p + Vec(0.0f, w3d_h1_8037cf4c[w3d_level_804ada6c] + self->y[0], 0.0f) + self->rot[n & 15];
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
    if (w3d_flags_a_804adb20 & 2) {
        if ((self->links[self->cur + 10].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.5f, w3d_h2_8037cfac[w3d_level_804ada6c + w3d_level_804ada6d] + self->m[0], w3d_edge_804adafc) + self->rot[(n + 8) & 15];
            self->ref[self->count] = self->cur + 10;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada74 + w3d_col_804ada78;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 10].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 2) {
        if ((self->links[self->cur + 10].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(0.5f, w3d_h2_8037cfac[w3d_level_804ada6c + w3d_level_804ada6d] + self->m[0], w3d_edge_804adafc) + self->rot[(n + 8) & 15];
            self->ref[self->count] = self->cur + 10;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada94 + w3d_col_804ada98;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 10].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 4) {
        if ((self->links[self->cur + 19].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f, w3d_h1_8037cf4c[w3d_level_804ada6d] + self->y[1], 0.0f) + self->rot[(n + 1) & 15];
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
            w3d_vert_80431460 = *p + Vec(1.0f, w3d_h1_8037cf4c[w3d_level_804ada6d] + self->y[1], 0.0f) + self->rot[(n + 1) & 15];
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
    if (w3d_flags_a_804adb20 & 8) {
        if ((self->links[self->cur + 163].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adaf4, w3d_h2_8037cfac[w3d_level_804ada6c + w3d_level_804ada6e] + self->m[1], 0.5f) + self->rot[(n + 11) & 15];
            self->ref[self->count] = self->cur + 163;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada74 + w3d_col_804ada7c;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 163].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 8) {
        if ((self->links[self->cur + 163].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adaf4, w3d_h2_8037cfac[w3d_level_804ada6c + w3d_level_804ada6e] + self->m[1], 0.5f) + self->rot[(n + 11) & 15];
            self->ref[self->count] = self->cur + 163;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada94 + w3d_col_804ada9c;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 163].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 16) {
        if ((self->links[self->cur + 172].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.5f, w3d_h4_8037d06c[(w3d_level_804ada6c + w3d_level_804ada6d + w3d_level_804ada6e + w3d_level_804ada6f) >> 1] + self->m[4], 0.5f);
            self->ref[self->count] = self->cur + 172;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_centre_col_804adb28;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 172].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 16) {
        if ((self->links[self->cur + 172].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(0.5f, w3d_h4_8037d06c[(w3d_level_804ada6c + w3d_level_804ada6d + w3d_level_804ada6e + w3d_level_804ada6f) >> 1] + self->m[4], 0.5f);
            self->ref[self->count] = self->cur + 172;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = 0;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 172].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 32) {
        if ((self->links[self->cur + 181].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adaf8, w3d_h2_8037cfac[w3d_level_804ada6d + w3d_level_804ada6f] + self->m[2], 0.5f) + self->rot[(n + 12) & 15];
            self->ref[self->count] = self->cur + 181;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada78 + w3d_col_804ada80;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 181].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 32) {
        if ((self->links[self->cur + 181].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adaf8, w3d_h2_8037cfac[w3d_level_804ada6d + w3d_level_804ada6f] + self->m[2], 0.5f) + self->rot[(n + 12) & 15];
            self->ref[self->count] = self->cur + 181;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada98 + w3d_col_804adaa0;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 181].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 64) {
        if ((self->links[self->cur + 325].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.0f, w3d_h1_8037cf4c[w3d_level_804ada6e] + self->y[2], 1.0f) + self->rot[(n + 2) & 15];
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
            w3d_vert_80431460 = *p + Vec(0.0f, w3d_h1_8037cf4c[w3d_level_804ada6e] + self->y[2], 1.0f) + self->rot[(n + 2) & 15];
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
    if (w3d_flags_a_804adb20 & 128) {
        if ((self->links[self->cur + 334].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.5f, w3d_h2_8037cfac[w3d_level_804ada6e + w3d_level_804ada6f] + self->m[3], w3d_edge_804adb00) + self->rot[(n + 10) & 15];
            self->ref[self->count] = self->cur + 334;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada7c + w3d_col_804ada80;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 334].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 128) {
        if ((self->links[self->cur + 334].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(0.5f, w3d_h2_8037cfac[w3d_level_804ada6e + w3d_level_804ada6f] + self->m[3], w3d_edge_804adb00) + self->rot[(n + 10) & 15];
            self->ref[self->count] = self->cur + 334;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa0 + w3d_col_804ada9c;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 334].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 256) {
        if ((self->links[self->cur + 343].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f, w3d_h1_8037cf4c[w3d_level_804ada6f] + self->y[3], 1.0f) + self->rot[(n + 3) & 15];
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
            w3d_vert_80431460 = *p + Vec(1.0f, w3d_h1_8037cf4c[w3d_level_804ada6f] + self->y[3], 1.0f) + self->rot[(n + 3) & 15];
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
            w3d_vert_80431460 = *p + Vec(0.0f, self->y[0] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada70], 0.0f) + self->rot[(n + 4) & 15];
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
            w3d_vert_80431460 = *p + Vec(0.0f, self->y[0] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada70], 0.0f) + self->rot[(n + 4) & 15];
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
    if (w3d_flags_a_804adb20 & 1024) {
        if ((self->links[self->cur + 9].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.5f, self->m[0] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada70 + w3d_level_804ada71], w3d_edge_804adb0c) + self->rot[(n + 12) & 15];
            self->ref[self->count] = self->cur + 9;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada88 + w3d_col_804ada84;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 9].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 1024) {
        if ((self->links[self->cur + 9].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(0.5f, self->m[0] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada70 + w3d_level_804ada71], w3d_edge_804adb0c) + self->rot[(n + 12) & 15];
            self->ref[self->count] = self->cur + 9;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa4 + w3d_col_804adaa8;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 9].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 2048) {
        if ((self->links[self->cur + 18].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f, self->y[1] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada71], 0.0f) + self->rot[(n + 5) & 15];
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
            w3d_vert_80431460 = *p + Vec(1.0f, self->y[1] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada71], 0.0f) + self->rot[(n + 5) & 15];
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
    if (w3d_flags_a_804adb20 & 4096) {
        if ((self->links[self->cur + 162].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adb04, self->m[1] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada70 + w3d_level_804ada72], 0.5f) + self->rot[(n + 15) & 15];
            self->ref[self->count] = self->cur + 162;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada84 + w3d_col_804ada8c;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 162].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 4096) {
        if ((self->links[self->cur + 162].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adb04, self->m[1] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada70 + w3d_level_804ada72], 0.5f) + self->rot[(n + 15) & 15];
            self->ref[self->count] = self->cur + 162;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa4 + w3d_col_804adaac;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 162].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 8192) {
        if ((self->links[self->cur + 171].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.5f, self->m[4] + 1.0f - w3d_h4_8037d06c[(w3d_level_804ada70 + w3d_level_804ada71 + w3d_level_804ada72 + w3d_level_804ada73) >> 1], 0.5f);
            self->ref[self->count] = self->cur + 171;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_centre_col_804adb30;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 171].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 8192) {
        if ((self->links[self->cur + 171].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(0.5f, self->m[4] + 1.0f - w3d_h4_8037d06c[(w3d_level_804ada70 + w3d_level_804ada71 + w3d_level_804ada72 + w3d_level_804ada73) >> 1], 0.5f);
            self->ref[self->count] = self->cur + 171;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = 0;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 171].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 16384) {
        if ((self->links[self->cur + 180].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adb08, self->m[2] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada71 + w3d_level_804ada73], 0.5f) + self->rot[n & 15];
            self->ref[self->count] = self->cur + 180;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada88 + w3d_col_804ada90;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 180].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 16384) {
        if ((self->links[self->cur + 180].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(w3d_edge_804adb08, self->m[2] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada71 + w3d_level_804ada73], 0.5f) + self->rot[n & 15];
            self->ref[self->count] = self->cur + 180;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaa8 + w3d_col_804adab0;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 180].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 32768) {
        if ((self->links[self->cur + 324].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.0f, self->y[2] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada72], 1.0f) + self->rot[(n + 6) & 15];
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
            w3d_vert_80431460 = *p + Vec(0.0f, self->y[2] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada72], 1.0f) + self->rot[(n + 6) & 15];
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
    if (w3d_flags_a_804adb20 & 65536) {
        if ((self->links[self->cur + 333].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(0.5f, self->m[3] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada72 + w3d_level_804ada73], w3d_edge_804adb10) + self->rot[(n + 14) & 15];
            self->ref[self->count] = self->cur + 333;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804ada8c + w3d_col_804ada90;
            float u = w3d_vert_80431460.dot(self->a0) + self->a2[0];
            float v = w3d_vert_80431460.dot(self->a1) + self->a2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 333].h.lo = self->count++;
        }
    }
    if (w3d_flags_b_804adb24 & 65536) {
        if ((self->links[self->cur + 333].w & 0xffff0000) == 0xffff0000) {
            w3d_vert_80431460 = *p + Vec(0.5f, self->m[3] + 1.0f - w3d_h2_8037cfac[w3d_level_804ada72 + w3d_level_804ada73], w3d_edge_804adb10) + self->rot[(n + 14) & 15];
            self->ref[self->count] = self->cur + 333;
            self->pos[self->count] = w3d_vert_80431460;
            unsigned c = w3d_col_804adaac + w3d_col_804adab0;
            float u = w3d_vert_80431460.dot(self->b0) + self->b2[0];
            float v = w3d_vert_80431460.dot(self->b1) + self->b2[1];
            Uv t;
            t.u = u;
            t.v = v;
            self->uv[self->count] = t;
            self->col[self->count] = c;
            self->links[self->cur + 333].h.hi = self->count++;
        }
    }
    if (w3d_flags_a_804adb20 & 131072) {
        if ((self->links[self->cur + 342].w & 0xffff) == 0xffff) {
            w3d_vert_80431460 = *p + Vec(1.0f, self->y[3] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada73], 1.0f) + self->rot[(n + 7) & 15];
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
            w3d_vert_80431460 = *p + Vec(1.0f, self->y[3] + 1.0f - w3d_h1_8037cf4c[w3d_level_804ada73], 1.0f) + self->rot[(n + 7) & 15];
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
