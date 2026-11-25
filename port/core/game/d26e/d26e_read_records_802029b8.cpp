#include "w3d_ptr.h"
#line 1 "d26e_read_records_802029b8.cpp"
// (Worms 3D GameCube PAL, 0x802029b8).
//
// Reads the record table of a chunk reader: resizes the 64-byte record
// vector at +124 to the count at +84 (vector erase with an empty copy loop
// and a destroy loop, or fill insert), reads count*64 bytes through stream
// virtual slot 5 and byte-swaps fields a, b, c and d of each record. Field
// names are inferred from the original instructions.

extern "C" Ptr32<void> memset(...);
struct Record {
    char u0[8]; unsigned a; char u1[4]; unsigned b; unsigned short c, d; char u2[40];
    ~Record() {}
};
struct Stream { Ptr32<Ptr32<void>> vtable; };
inline void Swap(unsigned &x) { x = x; }
inline unsigned short Swap(unsigned short x) { return x; }
inline void Distance(Ptr32<Record> first, Ptr32<Record> last, int &n) { n += last - first; }
inline Ptr32<Record> CopyRange(Ptr32<Record> first, Ptr32<Record> last, Ptr32<Record> result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}
struct Records {
    Ptr32<Record> b; Ptr32<Record> e; Ptr32<Record> c;
    unsigned size() const { return e - b; }
    Ptr32<Record> begin() { return b; }
    Ptr32<Record> end() { return e; }
    static void destroy(Ptr32<Record> f, Ptr32<Record> l) { for (; f != l; ++f) f->~Record(); }
    Ptr32<Record> erase(Ptr32<Record> f, Ptr32<Record> l) { Ptr32<Record> ne = CopyRange(l, e, f); destroy(ne, e); e = ne; return f; }
    void insert_fill(Ptr32<Record> pos, unsigned n, const Record &x);
    void resize(unsigned n, const Record &x) {
        if (n < size()) erase(begin() + n, end());
        else insert_fill(e, n - size(), x);
    }
};
struct Reader { char u[20]; Ptr32<Stream> stream; char v[60]; unsigned count; char w[36]; Records records; int ReadRecords(); };
extern "C" int w3d_d26e_read_records_802029b8(Ptr32<Reader> self) {
    unsigned n = self->count;
    Records &v = self->records;
    Record z;
    memset(w3d::VA(&z), 0, sizeof(z));
    v.resize(n, z);
    ((Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, int)>)self->stream->vtable[5])(self->stream, self->records.b, self->count << 6, 0);
    for (unsigned i = 0; i < self->count; ++i) {
        Record &r = self->records.b[i];
        Swap(r.a);
        Swap(r.b);
        r.c = Swap(r.c);
        r.d = Swap(r.d);
    }
    return 0;
}


