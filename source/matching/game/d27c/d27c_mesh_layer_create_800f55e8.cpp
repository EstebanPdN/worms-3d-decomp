// d27c: 0x800f55e8. Allocates a mesh animation layer, optionally counts a reference on its index, binds and retains the shared table for that index, and sizes its word vector to the table's entry count, zeroing every word. Names are inferred; the vector's growth code is as in 0x800f30f0, including its odd fill loop.
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
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Vec {
    int *start, *finish, *eos;
    int &operator[](int i) { return start[i]; }
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
struct Data { unsigned char u0[24]; unsigned count; };
struct Table : Object { unsigned char u4[76]; Data *data; };
struct Item { void **vt; Vec vec; unsigned char u16[12]; int index; Table *table; };
struct Self { unsigned char u0[68]; int *counts; unsigned char u72[8]; Table **tables; };
extern char heap_804adde4;
extern "C" void *heap_802098d8(void *, int);
extern "C" Item *reset_800f6c64(void *);
inline unsigned count_of(const unsigned &v) { return v; }
extern "C" Item *d27c_mesh_layer_create_800f55e8(Self *self, int index, int retain) {
    Item *it = reset_800f6c64(heap_802098d8(&heap_804adde4, 64));
    if (retain) (*(int *)((char *)self->counts + (index << 2)))++;
    it->index = index;
    Table *t = self->tables[index];
    if (t) t->vtable->retain(t);
    if (it->table) it->table->vtable->release(it->table);
    it->table = t;
    unsigned n = self->tables[index]->data->count;
    it->vec.resize(n, 0);
    for (unsigned i = 0; i < count_of(n); i++) it->vec[i] = 0;
    return it;
}
