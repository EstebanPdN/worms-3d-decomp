// d24c: 0x800f30f0 (684 bytes). Bind a mesh instance's bone table: load the
// named mesh (name at +892, load flag at +3176) into the mesh slot (+28) and
// call its virtual +88 with 0; query the mesh's owner value (virtual +56, key
// 0x8040e078) for the table object and retain it in +36, releasing the previous
// one; publish the table's entries (+32 of its data) at +80 and their count
// (+24 of its data) at +84; resize the word vector at +68 to that count,
// filling new words with 0. The query reference is released on return.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return.
// The vector's growth code is reproduced as observed, including the capacity
// computed in bytes and the fill loop that does not advance its pointer. Names
// are inferred; memcpy goes through the compiler's builtin (unprototyped call).
// The body after the load is an inline helper, which gives the reference its own
// frame block: this is the 4-byte gap above it in the original's stack layout.
typedef unsigned int size_t;
extern "C" void *memcpy(void *, const void *, size_t);
extern "C" void *memmove(void *, const void *, size_t);
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Data { unsigned char unknown00[24]; unsigned count; };
struct Table { void **vtable; unsigned char unknown04[40]; Data *data; };
struct Lookup {
    struct V { void *u[14]; void (*find)(Lookup *, const void *, int, Ref *); } *vtable;
};
struct Mesh {
    struct V { void *u[22]; void (*enable)(Mesh *, int); } *vtable;
};
extern "C" int load_8015adf4(void *, Mesh **, unsigned char);
extern "C" Lookup *owner_80182150(Mesh *);
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
extern const unsigned char key_8040e078[];
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Vec {
    int *start, *finish, *eos;
    void insert(int *pos, unsigned n, const int &x, unsigned size) {
        if (pos + n > eos) {
            unsigned used = (char *)finish - (char *)start;
            int cap = (char *)eos - (char *)start;
            int a = cap + (n - (eos - finish));
            int b = cap + ((unsigned)cap >> 1);
            unsigned bytes = maximum(a, b) << 2;
            int *p = (int *)alloc_80212fd4(bytes);
            if (start) {
                memcpy(p, start, minimum(bytes, used));
                release_802134fc(start);
            }
            start = p;
            pos = p + size;
            finish = (int *)((char *)p + used);
            eos = (int *)((char *)p + bytes);
        }
        if (pos == finish) {
            for (unsigned i = 0; i < n; i++) finish[i] = x;
            finish += n;
        } else {
            int v = x;
            memmove(pos + n, pos, (char *)finish - (char *)pos);
            finish += n;
            for (unsigned i = 0; i < n; i++) *pos = v;
        }
    }
    void erase(int *first, int *last) {
        int removed = (char *)last - (char *)first;
        memcpy(first, last, (char *)finish - (char *)last);
        finish = (int *)((char *)finish - removed);
    }
    void resize(unsigned n, const int &x) {
        unsigned size = finish - start;
        if (n < size) erase(start + n, finish);
        else insert(finish, n - size, x, size);
    }
};
struct Self {
    unsigned char u0[28];
    Mesh *mesh;       // +28
    unsigned char u32[4];
    Object *table;    // +36
    unsigned char u40[28];
    Vec vec;          // +68
    unsigned *data;   // +80
    unsigned count;   // +84
    unsigned char u88[804];
    unsigned char name[2284]; // +892
    unsigned char flag; // +3176
};
inline void d24c_bind_table(Self *self) {
    Lookup *o = owner_80182150(self->mesh);
    Ref r;
    r.value = 0;
    o->vtable->find(o, key_8040e078, 0, &r);
    Object *t = r.value;
    if (t) t->vtable->retain(t);
    if (self->table) self->table->vtable->release(self->table);
    self->table = t;
    Data *d = ((Table *)t)->data;
    unsigned c = d->count;
    self->data = (unsigned *)((char *)d + 32);
    self->count = c;
    self->vec.resize(c, 0);
}
extern "C" void d24c_mesh_table_bind_800f30f0(Self *self) {
    load_8015adf4(self->name, &self->mesh, self->flag);
    self->mesh->vtable->enable(self->mesh, 0);
    d24c_bind_table(self);
}
