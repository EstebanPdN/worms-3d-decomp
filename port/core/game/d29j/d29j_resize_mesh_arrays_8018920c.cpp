#include "w3d_ptr.h"
#line 1 "d29j_resize_mesh_arrays_8018920c.cpp"
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
extern "C" Ptr32<void> lock_801ef048(Ptr32<Ptr32<Header> volatile>, unsigned, unsigned, unsigned);
inline Ptr32<void> lockArray(Ptr32<Ptr32<Header> volatile> st, const unsigned n, const unsigned size) {
    Ptr32<Header> h = *st;
    if (h->mode == 1 && n == h->count) { ++h->locks; return h + 1; }
    return lock_801ef048(st, n, size, 0);
}
inline Ptr32<void> lockEmpty(Ptr32<Ptr32<Header> volatile> st, const unsigned size) {
    Ptr32<Header> h = *st;
    if (h->mode == 1 && h->count == 0) { ++h->locks; return h + 1; }
    return lock_801ef048(st, 0, size, 0);
}
struct Flags { unsigned char u[4]; unsigned char bits; char w3d_tag_rest[3]; };
struct Mesh {
    unsigned char u0[4];
    Flags flags;
    unsigned char u12[52];
    Ptr32<Header> volatile positions;
    Ptr32<Header> volatile uvs;
    unsigned char u72[12];
    Ptr32<Header> volatile colours;
    Ptr32<Header> volatile normals;
    unsigned char u92[4];
    Ptr32<Header> volatile visible;
    Ptr32<Header> volatile hidden;
};
struct Owner { unsigned char u[48]; Ptr32<Mesh> mesh; };
struct Self { unsigned char u[168]; Ptr32<Owner> owner; };
extern "C" int d29j_resize_mesh_arrays_8018920c(Ptr32<Self> self, int n)
{
    Ptr32<Mesh> m = self->owner->mesh;
    if (n == m->hidden->count) return 0;
    Ptr32<unsigned char> h = (Ptr32<unsigned char>)lockArray(&m->hidden, n, 1);
    Ptr32<Vtx> p = (Ptr32<Vtx>)lockArray(&m->positions, n, 12);
    lockEmpty(&m->normals, 4);
    lockEmpty(&m->uvs, 8);
    lockEmpty(&m->colours, 4);
    Ptr32<unsigned char> v = (Ptr32<unsigned char>)lockArray(&m->visible, n, 1);
    for (unsigned i = 0; i < n; ++i) {
        h[i] = 0;
        p[i].x = 0.0f;
        p[i].y = 0.0f;
        p[i].z = 0.0f;
        v[i] = 1;
    }
    Ptr32<Flags> f = &m->flags;
    if (n == 0) f->bits |= 4;
    else f->bits &= ~4;
    return 0;
}


