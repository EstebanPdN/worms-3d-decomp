/* Worms 3D GameCube PAL 0x80073290. Rebuilds a terrain chunk mesh: walks the inner 7x7x7 cells of a 9x9x9 grid, reads each cell's material from a run-length iterator at +28, skips cells whose corner mask is not an open surface, then emits one quad (four positions, uvs, colours, two edge indices and six list indices) for every open edge. Built with -mps-float. Field and type names are inferred from the original instructions; the grid is viewed through Slab; globals are external views of original data. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec3 operator+(const Vec3 &o) const { Vec3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct UV { float u, v; };
struct Run { unsigned short value; unsigned short length; };
struct RunIter {
    Run *data; int idx; int off; int pos;
    void Fix() {
        if (off < 0) {
            do { idx--; off += data[idx].length; } while (off < 0);
        } else {
            while (off >= data[idx].length) { off -= data[idx].length; idx++; }
        }
    }
    void SetPos(int p) {
        int d = p - pos;
        off += d; pos += d;
    }
    unsigned short Value() { return data[idx].value; }
};
union GridCell { int word; struct { unsigned short hi, lo; } half; };
struct Slab { GridCell c[324]; };
struct GridBlock { GridCell c[18]; };
struct GridBlock2 { GridCell c[18][18]; };
struct ListVec {
    unsigned short **start;
    unsigned short *&operator[](unsigned i) { return start[i]; }
};
struct UShortVec {
    unsigned short *start; unsigned short *finish;
    unsigned size() const { return finish - start; }
    unsigned short &operator[](unsigned i) { return start[i]; }
};
struct Terrain {
    char pad0[28];
    RunIter iter;
    char pad44[116 - 44];
    void **materials;
    char pad120[536 - 120];
    int dirty;
    char pad540[672 - 540];
    Vec3 *verts; int pad676; unsigned *colours;
    char pad684[704 - 684];
    Vec3 *outPos; UV *outUv; unsigned *outCol; unsigned short *outEdge;
    unsigned char *map;
    char pad724[2448 - 724];
    ListVec lists;
    char pad2452[2460 - 2452];
    UShortVec counts;
    char pad2468[2478 - 2468];
    unsigned short nverts;
    char pad2480[2492 - 2480];
    GridBlock *grid;
};
extern "C" void * w3d_empty_80342a74(void *);
extern "C" float w3d_auto_80178df0(void *);
extern "C" void w3d_d26b_preview_init_80091ee0(Terrain *);
extern void *lbl_804ae548;
extern UV w3d_quad_uv_table_80430020[8][4];
extern Vec3 w3d_cell_offset_804336a0, w3d_cell_offset_804336ac, w3d_cell_offset_804336b8, w3d_cell_offset_804336c4, w3d_cell_offset_804336d0, w3d_cell_offset_804336dc, w3d_cell_offset_804336e8, w3d_cell_offset_804336f4;

#define GR(I, J, K) (s->c[(I) * 324 + (J) * 18 + (K)].word)
#define GZ() (((Slab *)((char *)line + si))->c[0].word)
#define U(I, J, K) (s->c[(I) * 324 + (J) * 18 + (K)].half.lo)

#define EMIT(A, B, V1, V2, S) { \
    const UV *t1 = &w3d_quad_uv_table_80430020[(S) & 7][1]; \
    const UV *t0 = &w3d_quad_uv_table_80430020[(S) & 7][0]; \
    const UV *t3 = &w3d_quad_uv_table_80430020[(S) & 7][3]; \
    const UV *t2 = &w3d_quad_uv_table_80430020[(S) & 7][2]; \
    self->outPos[self->nverts] = self->verts[A]; \
    self->outPos[self->nverts + 1] = self->verts[A] + (V1) * dt; \
    self->outPos[self->nverts + 2] = self->verts[B] + (V2) * dt; \
    self->outPos[self->nverts + 3] = self->verts[B]; \
    self->outUv[self->nverts] = *t1; \
    self->outUv[self->nverts + 1] = *t0; \
    self->outUv[self->nverts + 2] = *t3; \
    self->outUv[self->nverts + 3] = *t2; \
    self->outCol[self->nverts] = self->colours[A] | 0xff00; \
    self->outCol[self->nverts + 1] = self->colours[A] | 0xff00; \
    self->outCol[self->nverts + 2] = self->colours[B] | 0xff00; \
    self->outCol[self->nverts + 3] = self->colours[B] | 0xff00; \
    self->outEdge[self->nverts / 2] = A; \
    self->outEdge[self->nverts / 2 + 1] = B; \
    self->lists[m][self->counts[m]++] = self->nverts; \
    self->lists[m][self->counts[m]++] = self->nverts + 1; \
    self->lists[m][self->counts[m]++] = self->nverts + 2; \
    self->lists[m][self->counts[m]++] = self->nverts; \
    self->lists[m][self->counts[m]++] = self->nverts + 2; \
    self->lists[m][self->counts[m]++] = self->nverts + 3; \
    self->nverts += 4; }

static inline int Packed(unsigned z, unsigned y, unsigned x) { return y + (z << 10) + (x << 5); }
static inline unsigned char At(unsigned char *m, unsigned x, unsigned y, unsigned z) { return m[z + y * 9 + x * 81]; }
extern "C" int w3d_d28g_terrain_mesh_cells_80073290(Terrain *self) {float dt = w3d_auto_80178df0((void *)w3d_empty_80342a74(lbl_804ae548));
    if (self->dirty) w3d_d26b_preview_init_80091ee0(self);
    unsigned count = self->counts.size();
    for (unsigned c = 0; c < count; c++) self->counts[c] = 0;
    unsigned j, k, i;
    unsigned c1, c2, c3;
    int f0, f1, f2, f3;
    self->nverts = 0;
    unsigned seed = 0;
    unsigned char *map = self->map;
    for (i = 1; i < 8; i++) {
        for (j = 1; j < 8; j++) {
            for (k = 1; k < 8; k++) {
                seed += j + k + i;
                unsigned kk = k - 1, jj = j - 1, ii = i - 1; RunIter *it = &self->iter; it->SetPos(Packed(kk, jj, ii)); it->Fix();
                unsigned m = self->iter.Value() & 0xff;
                if (m > 127) continue;
                if (self->materials[m] == 0) continue;
                unsigned c0 = At(map, i, j, k + 1);
                if ((c0 & 17) != 16) continue;
                Slab *line = (Slab *)((char *)&self->grid->c[k + 1] + j * 72);
                c1 = At(map, i, j + 1, k + 1);
                c2 = At(map, i + 1, j, k + 1);
                c3 = At(map, i + 1, j + 1, k + 1);
                unsigned si = i * 1296;
                Vec3 d, a, b, e;
                a = w3d_cell_offset_804336c4; b = w3d_cell_offset_804336dc; d = w3d_cell_offset_804336ac; e = w3d_cell_offset_804336f4; 
                Slab *s = (Slab *)((char *)line + si);
                if (GZ() == -1) { a.z -= 0.2f; d.x -= 0.2f; }
                if (GR(0,1,0) == -1) { b.z -= 0.2f; d.x += 0.2f; }
                if (GR(1,0,0) == -1) { a.z += 0.2f; e.x -= 0.2f; }
                if (GR(1,1,0) == -1) { b.z += 0.2f; e.x += 0.2f; }
                f0 = 0; f1 = 0; f2 = 0; f3 = 0;
                if (GZ() == -1) { f0 = 1; EMIT(U(0,9,0), U(0,0,9), a, d, seed) }
                if (GR(0,1,0) == -1) { f1 = 1; EMIT(U(0,0,9), U(0,10,0), d, b, seed + 1) }
                if (GR(1,0,0) == -1) { f2 = 1; EMIT(U(1,0,9), U(0,9,0), e, a, seed + 2) }
                if (GR(1,1,0) == -1) { f3 = 1; EMIT(U(0,10,0), U(1,0,9), b, e, seed + 3) }
                if ((c0 & 85) == 84 || (c0 & 85) == 20) {
                    if (!f0) EMIT((GZ() & 0xffff), U(0,0,9), w3d_cell_offset_804336a0, w3d_cell_offset_804336a0, seed + 4)
                    if (!f1) EMIT(U(0,0,9), U(0,1,0), w3d_cell_offset_804336a0, w3d_cell_offset_804336a0, seed + 5)
                }
                if ((c0 & 85) == 16) {
                    if (!f0) EMIT(U(0,0,0), U(0,0,9), w3d_cell_offset_804336ac, d, seed + 4)
                    if (!f1) EMIT(U(0,0,9), U(0,1,0), d, w3d_cell_offset_804336ac, seed + 5)
                }
                if ((c2 & 204) == 200 || (c2 & 204) == 72) {
                    if (!f0) EMIT(U(0,9,0), U(0,0,0), w3d_cell_offset_804336b8, w3d_cell_offset_804336b8, seed + 6)
                    if (!f2) EMIT(U(1,0,0), U(0,9,0), w3d_cell_offset_804336b8, w3d_cell_offset_804336b8, seed + 7)
                }
                if ((c2 & 204) == 64) {
                    if (!f0) EMIT(U(0,9,0), U(0,0,0), a, w3d_cell_offset_804336c4, seed + 6)
                    if (!f2) EMIT(U(1,0,0), U(0,9,0), w3d_cell_offset_804336c4, a, seed + 7)
                }
                if ((c1 & 51) == 49 || (c1 & 51) == 33) {
                    if (!f1) EMIT(U(0,1,0), U(0,10,0), w3d_cell_offset_804336d0, w3d_cell_offset_804336d0, seed)
                    if (!f3) EMIT(U(0,10,0), U(1,1,0), w3d_cell_offset_804336d0, w3d_cell_offset_804336d0, seed + 1)
                }
                if ((c1 & 51) == 32) {
                    if (!f1) EMIT(U(0,1,0), U(0,10,0), w3d_cell_offset_804336dc, b, seed)
                    if (!f3) EMIT(U(0,10,0), U(1,1,0), b, w3d_cell_offset_804336dc, seed + 1)
                }
                if ((c3 & 170) == 162 || (c1 & 51) == 130) {
                    if (!f2) EMIT(U(1,0,9), U(1,0,0), w3d_cell_offset_804336e8, w3d_cell_offset_804336e8, seed + 2)
                    if (!f3) EMIT(U(1,1,0), U(1,0,9), w3d_cell_offset_804336e8, w3d_cell_offset_804336e8, seed + 3)
                }
                if ((c3 & 170) == 128) {
                    if (!f2) EMIT(U(1,0,9), U(1,0,0), e, w3d_cell_offset_804336f4, seed + 2)
                    if (!f3) EMIT(U(1,1,0), U(1,0,9), w3d_cell_offset_804336f4, e, seed + 3)
                }
            }
        }
    }
    return 0;
}
