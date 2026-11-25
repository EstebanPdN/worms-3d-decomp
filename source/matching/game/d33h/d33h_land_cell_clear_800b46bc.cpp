// GWMP8P rev0 0x800b46bc. Clears one voxel of the land occupancy grid at x,
// y, z: locks the grid and the packed corner data, repacks the corners,
// rebuilds, marks the touched cell and every neighbouring cell it borders in
// the 26 directions, and queues the cells linked to this land through the
// shared cell lists. One offset variable is shared across the first plane
// block because the original keeps its copy of the plane base apart. Names
// are inferred.
struct Header { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short locks; char unknown30[2]; char data[1]; };
extern "C" void *reserve_801ef048(void *, int, int, int);
struct ArrayRef {
    Header *header;
    void *Lock(int size, int flag) {
        Header *h = header;
        int n = h->count;
        if (h->kind == 1) { ++h->locks; return h->data; }
        return reserve_801ef048(this, n, size, flag);
    }
};
struct Cell { char unknown0[102]; unsigned short a; unsigned short b; };
struct Owner {
    char unknown0[44]; char *cells; char unknown48[392]; ArrayRef a440; char unknown444[10];
    unsigned char c454, c455, c456, c457, c458, c459; ArrayRef a460;
};
struct Land { void **vt; Owner *owner; char unknown8[4]; unsigned id; };
struct Info { unsigned char c0, c1, c2, x, y, z, x1, y1, z1; };
extern "C" void clear_8002c70c(void *, int, int, int);
extern "C" void fill_8002c4ec(void *, int, int);
extern "C" void pack_800b3fe4(void *, void *, Info *);
extern "C" void fill_800b2328(Land *);
extern "C" void set_80251398(Cell *, int);
extern "C" void queue_8008e7d4(Owner *, Cell *);
extern "C" void queue_8008e9c0(void *, Cell *);
extern "C" Owner *get_800b4d98(void *);
extern unsigned lbl_804b1828;
extern unsigned short *lbl_804b182c, *lbl_804b1834;
extern unsigned *lbl_804b1830;
struct LandList { char *start, *finish, *end; };
extern LandList lbl_8043bb64;
inline void Touch(Land *self, Cell **c, int off) { set_80251398(c[off], 1); queue_8008e7d4(self->owner, c[off]); }
#define TOUCH(expr) \
    off = (expr); \
    off <<= 2; \
    set_80251398(*(Cell **)(off + (int)c), 1); \
    queue_8008e7d4(self->owner, *(Cell **)(off + (int)c))
extern "C" void d33h_land_cell_clear_800b46bc(Land *self, unsigned x, unsigned y, unsigned z) {
    Owner *own = self->owner;
    unsigned nz = own->c456, nx = own->c455, ny = own->c454;
    unsigned cx = x / 7, cy = y / 7, cz = z / 7;
    char *cells0 = own->cells + 32;
    void *grid = own->a440.Lock(4, 2);
    clear_8002c70c(grid, x, y, z);
    fill_8002c4ec(grid, 1, 1);
    Owner *o2 = self->owner;
    Info info;
    info.c0 = o2->c459 + 1;
    info.c1 = o2->c458 + 1;
    info.c2 = o2->c457 + 1;
    info.x = x; info.y = y; info.z = z;
    info.x1 = x + 1; info.y1 = y + 1; info.z1 = z + 1;
    void *data = o2->a460.Lock(1, 2);
    int one = 1;
    pack_800b3fe4(grid, data, &info);
    int layer = nx * nz;
    fill_800b2328(self);
    int idx = cy + cx * nx + cz * nz * nx;
    x -= cx * 7; y -= cy * 7; z -= cz * 7;
    Cell **c = (Cell **)cells0 + idx;
    Touch(self, c, 0);
    int xlo = x == 0 && cx != 0;
    int xhi = x == 6 && cx < nz - 1;
    int ylo = y == 0 && cy != 0;
    int yhi = y == 6 && cy < ny - 1;
    int zlo = z == 0 && cz != 0;
    int zhi = z == 6 && cz < ny - 1;
    if (zlo) {
        int off = -layer;
        int base = off;
        off <<= 2;
        set_80251398(*(Cell **)(off + (int)c), 1);
        queue_8008e7d4(self->owner, *(Cell **)(off + (int)c));
        if (xlo) {
            TOUCH(base - nx);
            if (ylo) { off = nx + 1; off = base - off; TOUCH(off); }
            else if (yhi) { off = base + 1; off -= nx; TOUCH(off); }
        } else if (xhi) {
            int b = base + nx;
            off = b << 2;
            set_80251398(*(Cell **)(off + (int)c), 1);
            queue_8008e7d4(self->owner, *(Cell **)(off + (int)c));
            if (ylo) { TOUCH(b - 1); }
            else if (yhi) { TOUCH(b + 1); }
        }
        if (ylo) { TOUCH(base - 1); }
        else if (yhi) { TOUCH(base + 1); }
    } else if (zhi) {
        Touch(self, c, layer);
        if (xlo) {
            Touch(self, c, layer - nx);
            if (ylo) { int t = nx + 1; Touch(self, c, layer - t); }
            else if (yhi) { int t = layer + 1; Touch(self, c, t - nx); }
        } else if (xhi) {
            int b = layer + nx;
            Touch(self, c, b);
            if (ylo) Touch(self, c, b - 1);
            else if (yhi) Touch(self, c, b + 1);
        }
        if (ylo) Touch(self, c, layer - 1);
        else if (yhi) Touch(self, c, layer + 1);
    }
    if (xlo) {
        Touch(self, c, -nx);
        if (ylo) Touch(self, c, ~nx);
        else if (yhi) Touch(self, c, 1 - nx);
    } else if (xhi) {
        Touch(self, c, nx);
        if (ylo) Touch(self, c, nx - 1);
        else if (yhi) Touch(self, c, nx + 1);
    }
    if (ylo) Touch(self, c, -one);
    else if (yhi) Touch(self, c, one);
    unsigned id = self->id;
    if (id < lbl_804b1828) {
        unsigned k = lbl_804b182c[id] + idx;
        unsigned i = lbl_804b1830[k], end = lbl_804b1830[k + 1];
        while (i < end) {
            unsigned u = lbl_804b1834[i++];
            unsigned a = u >> 4 & 0xffc;
            unsigned n = u & 63;
            Cell **cs = (Cell **)(get_800b4d98(*(void **)(lbl_8043bb64.start + a))->cells + 32);
            set_80251398(cs[n], 1);
            cs[n]->b = cs[n]->a;
            queue_8008e9c0(get_800b4d98(*(void **)(lbl_8043bb64.start + a)), cs[n]);
        }
    }
}
