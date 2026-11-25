#include "w3d_ptr.h"
#line 1 "d27c_mesh_layer_create_800f55e8.cpp"
// d27c: 0x800f55e8. Allocates a mesh animation layer, optionally counts a reference on its index, binds and retains the shared table for that index, and sizes its word vector to the table's entry count, zeroing every word. Names are inferred; the vector's growth code is as in 0x800f30f0, including its odd fill loop.
typedef unsigned int size_t;
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, size_t);
extern "C" Ptr32<void> memmove(Ptr32<void>, Ptr32<const void>, size_t);
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;       // +12
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Vec {
    Ptr32<int> start; Ptr32<int> finish; Ptr32<int> eos;
    int &operator[](int i) { return start[i]; }
    void insert(Ptr32<int> pos, unsigned n, const int &x, unsigned size) {
        if (pos + n > eos) {
            unsigned used = (Ptr32<char>)finish - (Ptr32<char>)start;
            int cap = (Ptr32<char>)eos - (Ptr32<char>)start;
            int a = cap + (n - (eos - finish));
            int b = cap + ((unsigned)cap >> 1);
            unsigned bytes = maximum(a, b) << 2;
            Ptr32<int> p = (Ptr32<int>)alloc_80212fd4(bytes);
            if (start) {
                memcpy(p, start, minimum(bytes, used));
                release_802134fc(start);
            }
            start = p;
            pos = p + size;
            finish = (Ptr32<int>)((Ptr32<char>)p + used);
            eos = (Ptr32<int>)((Ptr32<char>)p + bytes);
        }
        if (pos == finish) {
            for (unsigned i = 0; i < n; i++) finish[i] = x;
            finish += n;
        } else {
            int v = x;
            memmove(pos + n, pos, (Ptr32<char>)finish - (Ptr32<char>)pos);
            finish += n;
            for (unsigned i = 0; i < n; i++) *pos = v;
        }
    }
    void erase(Ptr32<int> first, Ptr32<int> last) {
        int removed = (Ptr32<char>)last - (Ptr32<char>)first;
        memcpy(first, last, (Ptr32<char>)finish - (Ptr32<char>)last);
        finish = (Ptr32<int>)((Ptr32<char>)finish - removed);
    }
    void resize(unsigned n, const int &x) {
        unsigned size = finish - start;
        if (n < size) erase(start + n, finish);
        else insert(finish, n - size, x, size);
    }
};
struct Data { unsigned char u0[24]; unsigned count; };
struct Table : Object { unsigned char u4[76] __attribute__((aligned(__alignof__(Object)))); Ptr32<Data> data; };
struct Item { Ptr32<Ptr32<void>> vt; Vec vec; unsigned char u16[12]; int index; Ptr32<Table> table; };
struct Self { unsigned char u0[68]; Ptr32<int> counts; unsigned char u72[8]; Ptr32<Ptr32<Table>> tables; };
extern char heap_804adde4;
extern "C" Ptr32<void> heap_802098d8(Ptr32<void>, int);
extern "C" Ptr32<Item> reset_800f6c64(Ptr32<void>);
inline unsigned count_of(const unsigned &v) { return v; }
extern "C" Ptr32<Item> d27c_mesh_layer_create_800f55e8(Ptr32<Self> self, int index, int retain) {
    Ptr32<Item> it = reset_800f6c64(heap_802098d8(&heap_804adde4, 64));
    if (retain) (*(Ptr32<int>)((Ptr32<char>)self->counts + (index << 2)))++;
    it->index = index;
    Ptr32<Table> t = self->tables[index];
    if (t) t->vtable->retain(t);
    if (it->table) it->table->vtable->release(it->table);
    it->table = t;
    unsigned n = self->tables[index]->data->count;
    it->vec.resize(n, 0);
    for (unsigned i = 0; i < count_of(n); i++) it->vec[i] = 0;
    return it;
}


