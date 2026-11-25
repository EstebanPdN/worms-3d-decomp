// Resize a mesh's arrays to n vertices, GWMP8P rev0 0x8018920c. Returns at once
// when the hidden flag array already has n entries. Otherwise locks each array
// for writing (reusing a sole-owner buffer of the right count, else calling
// 0x801ef048), clears the vertex data and records in the mesh flags whether the
// mesh is now empty. Each array's handle holds a header with mode, count and a
// lock count; its data follows the 32-byte header.
struct Header {
    unsigned char u0[4];
    unsigned short mode;
    unsigned char u6[18];
    volatile unsigned count;
    unsigned short locks;
    unsigned char u1e[2];
};
struct Vtx { float x, y, z; };
extern "C" void *lock_801ef048(Header *volatile *, unsigned, unsigned, unsigned);
inline void *lockArray(Header *volatile *st, const unsigned n, const unsigned size) {
    Header *h = *st;
    if (h->mode == 1 && n == h->count) { ++h->locks; return h + 1; }
    return lock_801ef048(st, n, size, 0);
}
inline void *lockEmpty(Header *volatile *st, const unsigned size) {
    Header *h = *st;
    if (h->mode == 1 && h->count == 0) { ++h->locks; return h + 1; }
    return lock_801ef048(st, 0, size, 0);
}
struct Flags { unsigned char u[7]; unsigned char bits; };
struct Mesh {
    unsigned char u0[4];
    Flags flags;
    unsigned char u12[52];
    Header *volatile positions;
    Header *volatile uvs;
    unsigned char u72[12];
    Header *volatile colours;
    Header *volatile normals;
    unsigned char u92[4];
    Header *volatile visible;
    Header *volatile hidden;
};
struct Owner { unsigned char u[48]; Mesh *mesh; };
struct Self { unsigned char u[168]; Owner *owner; };
extern "C" int d29j_resize_mesh_arrays_8018920c(Self *self, int n)
{
    Mesh *m = self->owner->mesh;
    if (n == m->hidden->count) return 0;
    unsigned char *h = (unsigned char *)lockArray(&m->hidden, n, 1);
    Vtx *p = (Vtx *)lockArray(&m->positions, n, 12);
    lockEmpty(&m->normals, 4);
    lockEmpty(&m->uvs, 8);
    lockEmpty(&m->colours, 4);
    unsigned char *v = (unsigned char *)lockArray(&m->visible, n, 1);
    for (unsigned i = 0; i < n; ++i) {
        h[i] = 0;
        p[i].x = 0.0f;
        p[i].y = 0.0f;
        p[i].z = 0.0f;
        v[i] = 1;
    }
    Flags *f = &m->flags;
    if (n == 0) f->bits |= 4;
    else f->bits &= ~4;
    return 0;
}
