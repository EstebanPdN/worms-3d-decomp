#include "w3d_ptr.h"
#line 1 "d41n_buffer_manager_load_stream_80191130.cpp"
// GWMP8P rev0 0x80191130. Loads a buffer manager's entries and records from
// a stream, with an older-format check on the name prefix. The extended flag
// is a function-level false that the original still tests each record.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "compat/module_allocator.h"
extern "C" void fn_8034f190(Ptr32<void>);
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern "C" void fn_8020bb2c(Ptr32<void>);
extern "C" void fn_801907d0(Ptr32<void>);
extern "C" void fn_80197d78(Ptr32<void>);
extern "C" Ptr32<void> fn_801fe220(unsigned);
extern "C" void fn_801fe240(Ptr32<void>);
extern "C" int strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
extern const char lbl_803a825c[];
extern int lbl_804ab6d0, lbl_804ab6d4, lbl_804ab6d8, lbl_804ab6dc;
void *operator new[](__SIZE_TYPE__);
void operator delete[](void *);
struct Hdr { unsigned short refs; unsigned short len; };
struct W3dString_803426b8 {
    Ptr32<char> text;
    W3dString_803426b8();
    Ptr32<const char> c_str() const { return text; }
    bool operator==(const char *o) const;
    W3dString_803426b8(const W3dString_803426b8 &);
    ~W3dString_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
    W3dString_803426b8 &operator=(const W3dString_803426b8 &o) {
        ((Ptr32<Hdr>)(o.text - 6))->refs++;
        Ptr32<Hdr> h = (Ptr32<Hdr>)(text - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        text = o.text;
        return *this;
    }
    int length() const { return ((Ptr32<Hdr>)(text - 6))->len; }
};
typedef W3dString_803426b8 Str;
inline bool Str::operator==(const char *o) const { return strcmp_802ef234(c_str(), o) == 0; }
extern "C" Ptr32<Str> fn_8020c048(Ptr32<Str>, Ptr32<const Str>, int);
extern "C" Ptr32<Str> fn_8020c0fc(Ptr32<Str>, Ptr32<const Str>, int);
struct Stage { float x0, x1, a, b, c, d; ~Stage() {} };
struct Inner { Inner() { fn_8034f190(this); } Stage &operator[](unsigned i) { return stages[i]; } Ptr32<Stage> stages; unsigned short size; 
    void set(unsigned short n, Ptr32<Stage> p) { stages = p; size = n; } };
struct Elem {
    void set(unsigned a3, unsigned a2, unsigned a1, unsigned ac, unsigned ab) { f0 = 1; f3 = a3; f2 = a2; f1 = a1; c = ac; b = ab; }
    unsigned short w; /* palabra PPC: bits y luego índice; el índice es la mitad baja del anfitrión */ unsigned short d:6; unsigned short c:3; unsigned short b:3; unsigned short f3:1; unsigned short f2:1; unsigned short f1:1; unsigned short f0:1;
    Inner inner;
    ~Elem() {}
};
struct ElemVec { Ptr32<Elem> start; Elem &operator[](unsigned i) { return start[i]; } };
struct Body { char u[72]; Body(); ~Body(); };
extern "C" void fn_80197dd4(Ptr32<Body>, unsigned, Ptr32<Elem>);
extern "C" void fn_80197e08(Ptr32<Body>, Ptr32<ElemVec>);
extern "C" void fn_80197ed0(Ptr32<Body>);
extern "C" void fn_80197f0c(Ptr32<Body>, Ptr32<Body>);
struct Record { Str name; float weight; Body body; unsigned char flag; };
struct Entry { Str name; unsigned char a, b; unsigned short c; };
struct Reader;
struct ReaderVtable {
    Ptr32<void> u0[12];
    Ptr32<int (Ptr32<Reader>, Ptr32<unsigned int>, int)> readWord;
    Ptr32<void> u34[15];
    Ptr32<int (Ptr32<Reader>, Ptr32<unsigned char>, int)> readByte;
    Ptr32<void> u74;
    Ptr32<int (Ptr32<Reader>, Ptr32<unsigned short>, int)> readShort;
    Ptr32<void> u7c;
    Ptr32<int (Ptr32<Reader>, Ptr32<unsigned int>, int)> readCount;
    Ptr32<void> u84[2];
    Ptr32<int (Ptr32<Reader>, Ptr32<float>, int)> readFloat;
    Ptr32<void> u90;
    Ptr32<int (Ptr32<Reader>, Ptr32<Str>, int)> readString;
};
struct Reader { Ptr32<ReaderVtable> vtable; };
struct Stream {
    Ptr32<Reader> reader;
    template <class W3dU> Stream(Ptr32<W3dU> w3d_p) : Stream((Reader *)w3d_p.get()) {}
 Stream(Reader *r) : reader(r) {}
    int readWord(unsigned &x) { return reader->vtable->readWord(reader, &x, 0); }
    int readByte(unsigned char &x) { return reader->vtable->readByte(reader, &x, 0); }
    int readShort(unsigned short &x) { return reader->vtable->readShort(reader, &x, 0); }
    int readCount(unsigned &x) { return reader->vtable->readCount(reader, &x, 0); }
    int readFloat(float &x) { return reader->vtable->readFloat(reader, &x, 0); }
    int readString(Str &x) { return reader->vtable->readString(reader, &x, 0); }
};
struct Self;
struct SelfVtable { Ptr32<void> u0[11]; Ptr32<int (Ptr32<Self>, Ptr32<Stream>)> loadNew; Ptr32<int (Ptr32<Self>, unsigned int)> setCount; Ptr32<void> u34[3]; Ptr32<void (Ptr32<Self>, Ptr32<Record>, Ptr32<Ptr32<ElemVec>>, unsigned int)> addRecord; };
struct Entries { Ptr32<Entry> start; Ptr32<Entry> finish; Entry &operator[](unsigned i) { return start[i]; } unsigned size() const { return finish - start; } };
typedef _STL::vector<Stage, ModuleAllocator<Stage> > StageVec;
struct Self { Ptr32<SelfVtable> vtable; char u4[16]; Entries entries; char u1c[8]; struct { Ptr32<char> start; Record &operator[](unsigned i) { return ((Ptr32<Record>)start)[i]; } } records; char u28[28]; Str name; };
extern "C" int w3d_d41n_buffer_manager_load_stream_80191130(Ptr32<Self> self, Ptr32<Reader> r) {
    bool extended = false;
    Stream s(r);
    s.readString(self->name);
    Str prefix;
    fn_8020c048(&prefix, &self->name, 7);
    if (prefix == lbl_803a825c) {
        Str rest;
        rest = self->name;
        fn_8020c0fc(&self->name, &rest, rest.length() - 7);
        return self->vtable->loadNew(self, &s);
    }
    unsigned entryCount, recordCount;
    s.readCount(entryCount);
    self->vtable->setCount(self, entryCount);
    Ptr32<Elem> elems = w3d::new_array<Elem>(entryCount);
    StageVec unused;
    Elem e;
    unsigned i;
    for (i = 0; i < entryCount; ++i) {
        s.readByte(self->entries[i].a);
        s.readShort(self->entries[i].c);
        s.readByte(self->entries[i].b);
        s.readString(self->entries[i].name);
    }
    s.readCount(recordCount);
    for (unsigned n = 0; n < recordCount; ++n) {
        Record rec;
        Ptr32<ElemVec> list = 0;
        s.readFloat(rec.weight);
        s.readString(rec.name);
        rec.flag = 0;
        unsigned used = 0;
        Ptr32<Inner> in;
        unsigned listSize;
        if (extended) s.readCount(listSize);
        else listSize = entryCount;
        fn_80197d78(&rec.body);
        for (unsigned short idx = 0; idx < listSize; ++idx) {
            unsigned v;
            s.readWord(v);
            e.f0 = v;
            s.readWord(v);
            e.f3 = v;
            s.readWord(v);
            e.f2 = v;
            s.readWord(v);
            e.f1 = v;
            if (extended) s.readShort(e.w);
            else e.w = idx;
            unsigned u, stageCount;
            s.readCount(u);
            e.c = u;
            s.readCount(u);
            e.b = u;
            s.readCount(stageCount);
            if (stageCount) {
                if (e.f0) {
                    elems[used].f0 = 1;
                    elems[used].f3 = e.f3;
                    elems[used].f2 = e.f2;
                    elems[used].f1 = e.f1;
                    elems[used].c = e.c;
                    elems[used].b = e.b;
                    elems[used].w = e.w;
                    fn_80197dd4(&rec.body, stageCount, &elems[used]);
                    for (unsigned k = 0; k < stageCount; ++k) {
                        Stage &t = elems[used].inner[k];
                        s.readFloat(t.a);
                        s.readFloat(t.b);
                        s.readFloat(t.c);
                        s.readFloat(t.d);
                        s.readFloat(t.x0);
                        s.readFloat(t.x1);
                    }
                    ++used;
                } else {
                    float dummy;
                    for (unsigned k = 0; k < stageCount; ++k) {
                        s.readFloat(dummy);
                        s.readFloat(dummy);
                        s.readFloat(dummy);
                        s.readFloat(dummy);
                        s.readFloat(dummy);
                        s.readFloat(dummy);
                    }
                }
            }
        }
        if (used) {
            rec.flag = 0;
            self->vtable->addRecord(self, &rec, &list, used);
            for (unsigned j = 0; j < used; ++j) {
                (*list)[j].f0 = elems[j].f0;
                (*list)[j].f3 = elems[j].f3;
                (*list)[j].f2 = elems[j].f2;
                (*list)[j].f1 = elems[j].f1;
                (*list)[j].c = elems[j].c;
                (*list)[j].b = elems[j].b;
                (*list)[j].w = elems[j].w;
                in = &elems[j].inner;
                (*list)[j].inner.set(in->size, in->stages);
                ++lbl_804ab6dc;
                lbl_804ab6d4 += in->size * 24;
            }
            lbl_804ab6d8 += used * sizeof(Elem);
        }
        if (list) {
            fn_80197e08(&rec.body, list);
            fn_80197f0c(&rec.body, &self->records[n].body);
        } else fn_80197ed0(&rec.body);
        lbl_804ab6d0 += self->entries.size() - used;
    }
    w3d::delete_array(elems);
    return 0;
}


