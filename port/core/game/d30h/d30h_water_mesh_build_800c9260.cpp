#include "w3d_ptr.h"
#line 1 "d30h_water_mesh_build_800c9260.cpp"
// GWMP8P rev0 0x800c9260. Water plane mesh build, called from the water init
// 0x800c8e90. Names are inferred. Locks the index array of the mesh and
// writes 21 indices per ring segment (fan around vertex 0, then three strips
// between the rings 1, 21, 41, 61, each 20 vertices), then locks the vertex
// array, zeroes the centre and writes the unit ring at +88 scaled by 0.1,
// 0.35, 0.8 and 1. Class layouts are partial views. Owns the literals at
// 0x80387be8.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct ArrayHeader { char unknown00[4]; unsigned short refs; char unknown06[18]; int count; unsigned short gen; char unknown30[2]; char data[1]; };
struct Array { Ptr32<ArrayHeader> header; };
extern "C" Ptr32<void> w3d_array_ref_lock_801ef048(Ptr32<Array>, int, int, int);
struct Object { Ptr32<ObjectVtable> vtable; };
inline Ptr32<void> LockAll(Ptr32<Array> a, int size, int flag) {
    Ptr32<ArrayHeader> h = a->header;
    int n = h->count;
    if (h->refs == 1) { h->gen++; return h->data; }
    return w3d_array_ref_lock_801ef048(a, n, size, flag);
}
template <class T> struct Held {
    Ptr32<T> object;
    template <class W3dU> Held<T>(Ptr32<W3dU> w3d_p) : Held<T>((T *)w3d_p.get()) {}
 Held(T *o) : object(o) { if (o) o->vtable->retain(o); }
    Held(const Held &o);
    ~Held() { if (object) object->vtable->release(object); }
    Ptr32<T> operator->() const { return object; }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Indices : Object { char unknown04[20] __attribute__((aligned(__alignof__(Object)))); Array array; };
struct Vertices : Object { char unknown04[16] __attribute__((aligned(__alignof__(Object)))); Array array; };
struct Mesh : Object { char unknown04[76] __attribute__((aligned(__alignof__(Object)))); Ptr32<Vertices> vertices; char unknown84[8]; Ptr32<Indices> indices; };
struct Node { char unknown00[48]; Ptr32<Mesh> mesh; };
struct Water { char unknown00[60]; Ptr32<Node> node; char unknown64[24]; Vec ring[20]; };
extern "C" int d30h_water_mesh_build_800c9260(Ptr32<Water> self) {
    Held<Mesh> mesh(self->node->mesh);
    Held<Indices> ih(mesh->indices);
    Ptr32<unsigned short> ind = (Ptr32<unsigned short>)LockAll(&ih->array, 2, 2);
    unsigned short n = 0;
    for (unsigned short i = 1; i <= 20; i++) {
        unsigned short j = i + 1;
        if (j > 20) j = 1;
        ind[n++] = 0;
        ind[n++] = i;
        ind[n++] = j;
        ind[n++] = i;
        ind[n++] = i + 20;
        ind[n++] = j + 20;
        ind[n++] = i;
        ind[n++] = j + 20;
        ind[n++] = j;
        ind[n++] = i + 20;
        ind[n++] = i + 40;
        ind[n++] = j + 40;
        ind[n++] = i + 20;
        ind[n++] = j + 40;
        ind[n++] = j + 20;
        ind[n++] = i + 40;
        ind[n++] = i + 60;
        ind[n++] = j + 60;
        ind[n++] = i + 40;
        ind[n++] = j + 60;
        ind[n++] = j + 40;
    }
    Held<Vertices> vh(mesh->vertices);
    Ptr32<Vec> v = (Ptr32<Vec>)LockAll(&vh->array, 12, 2);
    v->x = 0.0f; v->y = 0.0f; v->z = 0.0f;
    for (int k = 0; k < 20; k++) {
        v[k + 1] = self->ring[k] * 0.1f;
        v[k + 21] = self->ring[k] * 0.35f;
        v[k + 41] = self->ring[k] * 0.8f;
        v[k + 61] = self->ring[k];
    }
    return 0;
}


