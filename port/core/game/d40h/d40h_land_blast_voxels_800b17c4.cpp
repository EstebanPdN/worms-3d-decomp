#include "w3d_ptr.h"
#line 1 "d40h_land_blast_voxels_800b17c4.cpp"
// GWMP8P rev0 0x800b17c4. Blasts a sphere out of the land voxel grid. For a
// motion's position and radius it walks every 7x7x7 cell block, tests the
// sphere against each block's bounds, clears every occupied voxel inside the
// scaled sphere, tracks the touched bounds, flags the block and its
// neighbours in a 5x5x5 table, then refreshes those blocks and repacks the
// corner data. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator=(const Vec &o) { x = o.x; y = o.y; z = o.z; return *this; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
};
struct Sphere { Vec center; float radius; };
struct Object;
struct Motion;
struct Header { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short locks; char unknown30[2]; char data[1]; };
extern "C" Ptr32<void> reserve_801ef048(Ptr32<void>, int, int, int);
struct ArrayRef {
    Ptr32<Header> header;
    Ptr32<void> Lock(int size, int flag) {
        Ptr32<Header> h = header;
        int n = h->count;
        if (h->kind == 1) { ++h->locks; return h->data; }
        return reserve_801ef048(this, n, size, flag);
    }
};
struct Cell { char unknown0[20]; Sphere sphere; char unknown36[12]; unsigned char ox, oy, oz; char unknown51[51]; unsigned short a; unsigned short b; };
struct Mat43 {
    Vec r[4];
    void Mul(Vec &out, const Vec &v) const {
        out.x = v.x * r[0].x + v.y * r[1].x + v.z * r[2].x + r[3].x;
        out.y = v.x * r[0].y + v.y * r[1].y + v.z * r[2].y + r[3].y;
        out.z = v.x * r[0].z + v.y * r[1].z + v.z * r[2].z + r[3].z;
    }
};
struct Owner {
    char unknown0[44]; Ptr32<char> cells; char unknown48[144]; Mat43 m; char unknown240[132]; Vec scale; char unknown384[56]; ArrayRef a440; char unknown444[10];
    unsigned char c454, c455, c456, c457, c458, c459; ArrayRef a460;
};
struct Land { Ptr32<Ptr32<void>> vt; Ptr32<Owner> owner; char unknown8[4]; unsigned id; };
struct Info { unsigned char c0, c1, c2, x, y, z, x1, y1, z1; };
extern "C" Ptr32<Object> native_80342a78(Ptr32<Object>);
extern "C" unsigned value_80178d1c(Ptr32<Object>);
extern "C" int update_80178d28(Ptr32<Object>, Ptr32<int>);
extern "C" void position_80066894(Ptr32<Vec>, Ptr32<Motion>);
extern "C" float radius_800668ec(Ptr32<Motion>);
extern "C" int grid_test_8002c73c(Ptr32<void>, int, int, int, int);
extern "C" void point_800b41c4(Ptr32<Land>, unsigned char, unsigned char, unsigned char, Ptr32<Vec>);
extern "C" void clear_8002c70c(Ptr32<void>, int, int, int);
extern "C" void fill_8002c4ec(Ptr32<void>, int, int);
extern "C" void pack_800b3fe4(Ptr32<void>, Ptr32<void>, Ptr32<Info>);
extern "C" void fill_800b2328(Ptr32<Land>);
extern "C" void set_80251398(Ptr32<Cell>, int);
extern "C" void queue_8008e7d4(Ptr32<Owner>, Ptr32<Cell>);
extern "C" void queue_8008e9c0(Ptr32<void>, Ptr32<Cell>);
extern "C" Ptr32<Owner> get_800b4d98(Ptr32<void>);
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned int);
extern Ptr32<Object> lbl_804ae5e0; extern Ptr32<Object> lbl_804ae5dc;
extern unsigned lbl_804b1828;
extern Ptr32<unsigned short> lbl_804b182c; extern Ptr32<unsigned short> lbl_804b1834;
extern Ptr32<unsigned int> lbl_804b1830;
struct LandList { Ptr32<char> start; Ptr32<char> finish; Ptr32<char> end; };
extern LandList lbl_8043bb64;
struct Global { char unknown0[104]; Vec origin; };
extern Ptr32<Global> lbl_804b17e0;
struct Marks { int pad; int f[5][5][5]; };
extern Marks lbl_8043b044;
extern "C" int d40h_land_blast_voxels_800b17c4(Ptr32<Land> self, Ptr32<Motion> m) {
    if (value_80178d1c(native_80342a78(lbl_804ae5e0))) return 0;
    Vec pos;
    position_80066894(&pos, m);
    int hit = 0;
    float radius = radius_800668ec(m);
    Ptr32<Owner> own = self->owner;
    Vec local;
    {
    const Vec &r0 = own->m.r[1], &r1 = own->m.r[0], &r2 = own->m.r[2], &r3 = own->m.r[3];
    Ptr32<const Vec> p = &pos;
    local.x = pos.x * r1.x + p->y * r0.x + p->z * r2.x + r3.x;
    local.y = pos.x * r1.y + p->y * r0.y + p->z * r2.y + r3.y;
    local.z = pos.x * r1.z + p->y * r0.z + p->z * r2.z + r3.z;
    }
    Vec r, v;
    Vec scale = own->scale;
    Vec inv;
    r.x = radius / scale.x;
    r.y = radius / scale.y;
    r.z = radius / scale.z;
    inv.x = 1.0f / r.x;
    inv.y = 1.0f / r.y;
    inv.z = 1.0f / r.z;
    unsigned oz, oy, ox;
    Ptr32<void> grid;
    unsigned nb, nc, na, idx, b, c, a, k, j, i;
    int blo, clo, alo, bhi, chi, ahi, ihi;
    Ptr32<Ptr32<Cell>> cells;
    cells = (Ptr32<Ptr32<Cell>>)(own->cells + 32);
    grid = own->a440.Lock(4, 2);
    Ptr32<Owner> o2 = self->owner;
    idx = 0;
    nb = (unsigned char)(o2->c456 - 1); nc = (unsigned char)(o2->c455 - 1); na = (unsigned char)(o2->c454 - 1);
    Info info;
    info.c0 = o2->c459 + 1;
    info.c1 = o2->c458 + 1;
    info.c2 = o2->c457 + 1;
    info.x = 255; info.y = 255; info.z = 255;
    info.x1 = idx; info.y1 = idx; info.z1 = idx;
    a = 0;
    memset(lbl_8043b044.f, 0, 125);
    Vec origin = lbl_804b17e0->origin;
    for (; a <= na; a = (unsigned char)(a + 1)) {
        alo = a != 0;
        ahi = a < na;
        for (b = 0; b <= nb; b = (unsigned char)(b + 1)) {
            blo = b != 0;
            bhi = b < nb;
            for (c = 0; c <= nc; c = (unsigned char)(c + 1)) {
                clo = c != 0;
                chi = c < nc;
                Ptr32<Sphere> s = &(*cells)->sphere;
                Vec d;
                d.x = s->center.x - origin.x;
                d.y = s->center.y - origin.y;
                d.z = s->center.z - origin.z;
                float R = s->radius + radius;
                d -= pos;
                if (d.x < R && d.x > -R && d.y < R && d.y > -R && d.z < R && d.z > -R) {
                    int touched = 0;
                    oz = (*cells)->oz; oy = (*cells)->oy; ox = (*cells)->ox;
                    for (i = 0; i <= 6; i = (unsigned char)(i + 1)) {
                        int ilo = i == 0 && alo;
                        ihi = i == 6 && ahi;
                        for (j = 0; j <= 6; j = (unsigned char)(j + 1)) {
                            int jlo = j == 0 && blo;
                            int jhi = j == 6 && bhi;
                            for (k = 0; k <= 6; k = (unsigned char)(k + 1)) {
                                int klo = k == 0 && clo;
                                int khi = k == 6 && chi;
                                int vx = j + oz, vy = k + oy, vz = i + ox;
                                if (grid_test_8002c73c(grid, vx, vy, vz, 0)) {
                                    point_800b41c4(self, vx, vy, vz, &v);
                                    v -= local;
                                    v.x *= inv.x;
                                    v.y *= inv.y;
                                    v.z *= inv.z;
                                    if (v.x * v.x + v.y * v.y + v.z * v.z < 1.0f) {
                                        clear_8002c70c(grid, vx, vy, vz);
                                        hit = 1;
                                        touched = hit;
                                        if (vx < info.x) info.x = vx;
                                        if (vy < info.y) info.y = vy;
                                        if (vz < info.z) info.z = vz;
                                        if (vx > info.x1) info.x1 = vx;
                                        if (vy > info.y1) info.y1 = vy;
                                        if (vz > info.z1) info.z1 = vz;
                                        lbl_8043b044.f[b][c][a] = hit;
                                        if (klo) {
                                            lbl_8043b044.f[b][c - 1][a] = hit;
                                            if (jlo) {
                                                lbl_8043b044.f[b - 1][c - 1][a] = hit;
                                                if (ilo) lbl_8043b044.f[b - 1][c - 1][a - 1] = hit;
                                                else if (ihi) lbl_8043b044.f[b - 1][c - 1][a + 1] = hit;
                                            } else if (jhi) {
                                                lbl_8043b044.f[b + 1][c - 1][a] = hit;
                                                if (ilo) lbl_8043b044.f[b + 1][c - 1][a - 1] = hit;
                                                else if (ihi) lbl_8043b044.f[b + 1][c - 1][a + 1] = hit;
                                            }
                                            if (ilo) lbl_8043b044.f[b][c - 1][a - 1] = 1;
                                            else if (ihi) lbl_8043b044.f[b][c - 1][a + 1] = 1;
                                        } else if (khi) {
                                            lbl_8043b044.f[b][c + 1][a] = hit;
                                            if (jlo) {
                                                lbl_8043b044.f[b - 1][c + 1][a] = hit;
                                                if (ilo) lbl_8043b044.f[b - 1][c + 1][a - 1] = hit;
                                                else if (ihi) lbl_8043b044.f[b - 1][c + 1][a + 1] = hit;
                                            } else if (jhi) {
                                                lbl_8043b044.f[b + 1][c + 1][a] = hit;
                                                if (ilo) lbl_8043b044.f[b + 1][c + 1][a - 1] = hit;
                                                else if (ihi) lbl_8043b044.f[b + 1][c + 1][a + 1] = hit;
                                            }
                                            if (ilo) lbl_8043b044.f[b][c + 1][a - 1] = 1;
                                            else if (ihi) lbl_8043b044.f[b][c + 1][a + 1] = 1;
                                        }
                                        if (jlo) {
                                            lbl_8043b044.f[b - 1][c][a] = 1;
                                            if (ilo) lbl_8043b044.f[b - 1][c][a - 1] = 1;
                                            else if (ihi) lbl_8043b044.f[b - 1][c][a + 1] = 1;
                                        } else if (jhi) {
                                            lbl_8043b044.f[b + 1][c][a] = 1;
                                            if (ilo) lbl_8043b044.f[b + 1][c][a - 1] = 1;
                                            else if (ihi) lbl_8043b044.f[b + 1][c][a + 1] = 1;
                                        }
                                        if (ilo) lbl_8043b044.f[b][c][a - 1] = 1;
                                        else if (ihi) lbl_8043b044.f[b][c][a + 1] = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (touched) {
                        set_80251398(*cells, 1);
                        queue_8008e7d4(self->owner, *cells);
                        unsigned id = self->id;
                        if (id < lbl_804b1828) {
                            unsigned kk = lbl_804b182c[id] + idx;
                            unsigned n = lbl_804b1830[kk], end = lbl_804b1830[kk + 1];
                            while (n < end) {
                                unsigned u = lbl_804b1834[n++];
                                unsigned e = u >> 4 & 0xffc;
                                unsigned q = u & 63;
                                Ptr32<Ptr32<Cell>> cs = (Ptr32<Ptr32<Cell>>)(get_800b4d98(*(Ptr32<Ptr32<void>>)(lbl_8043bb64.start + e))->cells + 32);
                                set_80251398(cs[q], 1);
                                cs[q]->b = cs[q]->a;
                                queue_8008e9c0(get_800b4d98(*(Ptr32<Ptr32<void>>)(lbl_8043bb64.start + e)), cs[q]);
                            }
                        }
                    }
                }
                idx++;
                cells++;
            }
        }
    }
    int one = 1;
    if (hit) {
        cells = (Ptr32<Ptr32<Cell>>)(self->owner->cells + 32);
        for (a = 0; a <= na; a = (unsigned char)(a + 1)) {
            for (b = 0; b <= nb; b = (unsigned char)(b + 1)) {
                for (c = 0; c <= nc; c = (unsigned char)(c + 1)) {
                    if (lbl_8043b044.f[b][c][a]) {
                        set_80251398(*cells, 1);
                        queue_8008e7d4(self->owner, *cells);
                    }
                    cells++;
                }
            }
        }
        update_80178d28(native_80342a78(lbl_804ae5dc), &one);
        fill_8002c4ec(grid, 1, 1);
        info.x1++; info.y1++; info.z1++;
        pack_800b3fe4(grid, self->owner->a460.Lock(1, 2), &info);
        fill_800b2328(self);
    }
    return 0;
}


