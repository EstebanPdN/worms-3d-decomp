// (Worms 3D GameCube PAL, 0x802029b8).
//
// Reads the record table of a chunk reader: resizes the 64-byte record
// vector at +124 to the count at +84 (vector erase with an empty copy loop
// and a destroy loop, or fill insert), reads count*64 bytes through stream
// virtual slot 5 and byte-swaps fields a, b, c and d of each record. Field
// names are inferred from the original instructions.

extern "C" void *memset(...);
struct Record {
    char u0[8]; unsigned a; char u1[4]; unsigned b; unsigned short c, d; char u2[40];
    ~Record() {}
};
struct Stream { void **vtable; };
inline void Swap(unsigned &x) { x = (x << 24) | ((x & 0xff00) << 8) | ((x >> 8) & 0xff00) | (x >> 24); }
inline unsigned short Swap(unsigned short x) { return ((x & 0xff) << 8) | (x >> 8); }
inline void Distance(Record *first, Record *last, int &n) { n += last - first; }
inline Record *CopyRange(Record *first, Record *last, Record *result)
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
    Record *b, *e, *c;
    unsigned size() const { return e - b; }
    Record *begin() { return b; }
    Record *end() { return e; }
    static void destroy(Record *f, Record *l) { for (; f != l; ++f) f->~Record(); }
    Record *erase(Record *f, Record *l) { Record *ne = CopyRange(l, e, f); destroy(ne, e); e = ne; return f; }
    void insert_fill(Record *pos, unsigned n, const Record &x);
    void resize(unsigned n, const Record &x) {
        if (n < size()) erase(begin() + n, end());
        else insert_fill(e, n - size(), x);
    }
};
struct Reader { char u[20]; Stream *stream; char v[60]; unsigned count; char w[36]; Records records; int ReadRecords(); };
extern "C" int w3d_d26e_read_records_802029b8(Reader *self) {
    unsigned n = self->count;
    Records &v = self->records;
    Record z;
    memset(&z, 0, sizeof(z));
    v.resize(n, z);
    ((int (*)(Stream *, void *, unsigned, int))self->stream->vtable[5])(self->stream, self->records.b, self->count << 6, 0);
    for (unsigned i = 0; i < self->count; ++i) {
        Record &r = self->records.b[i];
        Swap(r.a);
        Swap(r.b);
        r.c = Swap(r.c);
        r.d = Swap(r.d);
    }
    return 0;
}
