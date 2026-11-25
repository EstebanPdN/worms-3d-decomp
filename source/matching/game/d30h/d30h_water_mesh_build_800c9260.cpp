// GWMP8P rev0 0x800c9260. Water plane mesh build, called from the water init
// 0x800c8e90. Names are inferred. Locks the index array of the mesh and
// writes 21 indices per ring segment (fan around vertex 0, then three strips
// between the rings 1, 21, 41, 61, each 20 vertices), then locks the vertex
// array, zeroes the centre and writes the unit ring at +88 scaled by 0.1,
// 0.35, 0.8 and 1. Class layouts are partial views. Owns the literals at
// 0x80387be8.
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
};
struct ArrayHeader { char unknown00[4]; unsigned short refs; char unknown06[18]; int count; unsigned short gen; char unknown30[2]; char data[1]; };
struct Array { ArrayHeader *header; };
extern "C" void *w3d_array_ref_lock_801ef048(Array *, int, int, int);
struct Object { ObjectVtable *vtable; };
inline void *LockAll(Array *a, int size, int flag) {
    ArrayHeader *h = a->header;
    int n = h->count;
    if (h->refs == 1) { h->gen++; return h->data; }
    return w3d_array_ref_lock_801ef048(a, n, size, flag);
}
template <class T> struct Held {
    T *object;
    Held(T *o) : object(o) { if (o) o->vtable->retain(o); }
    Held(const Held &o);
    ~Held() { if (object) object->vtable->release(object); }
    T *operator->() const { return object; }
};
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Indices : Object { char unknown04[20]; Array array; };
struct Vertices : Object { char unknown04[16]; Array array; };
struct Mesh : Object { char unknown04[76]; Vertices *vertices; char unknown84[8]; Indices *indices; };
struct Node { char unknown00[48]; Mesh *mesh; };
struct Water { char unknown00[60]; Node *node; char unknown64[24]; Vec ring[20]; };
extern "C" int d30h_water_mesh_build_800c9260(Water *self) {
    Held<Mesh> mesh(self->node->mesh);
    Held<Indices> ih(mesh->indices);
    unsigned short *ind = (unsigned short *)LockAll(&ih->array, 2, 2);
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
    Vec *v = (Vec *)LockAll(&vh->array, 12, 2);
    v->x = 0.0f; v->y = 0.0f; v->z = 0.0f;
    for (int k = 0; k < 20; k++) {
        v[k + 1] = self->ring[k] * 0.1f;
        v[k + 21] = self->ring[k] * 0.35f;
        v[k + 41] = self->ring[k] * 0.8f;
        v[k + 61] = self->ring[k];
    }
    return 0;
}
