// GWMP8P rev0 0x80191130. Loads a buffer manager's entries and records from
// a stream, with an older-format check on the name prefix. The extended flag
// is a function-level false that the original still tests each record.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "compat/module_allocator.h"
extern "C" void fn_8034f190(void *);
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" void fn_8020bb2c(void *);
extern "C" void fn_801907d0(void *);
extern "C" void fn_80197d78(void *);
extern "C" void *fn_801fe220(unsigned);
extern "C" void fn_801fe240(void *);
extern "C" int strcmp_802ef234(const char *, const char *);
extern const char lbl_803a825c[];
extern int lbl_804ab6d0, lbl_804ab6d4, lbl_804ab6d8, lbl_804ab6dc;
void *operator new[](unsigned);
void operator delete[](void *);
struct Hdr { unsigned short refs; unsigned short len; };
struct W3dString_803426b8 {
    char *text;
    W3dString_803426b8();
    const char *c_str() const { return text; }
    bool operator==(const char *o) const;
    W3dString_803426b8(const W3dString_803426b8 &);
    ~W3dString_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
    W3dString_803426b8 &operator=(const W3dString_803426b8 &o) {
        ((Hdr *)(o.text - 6))->refs++;
        Hdr *h = (Hdr *)(text - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        text = o.text;
        return *this;
    }
    int length() const { return ((Hdr *)(text - 6))->len; }
};
typedef W3dString_803426b8 Str;
inline bool Str::operator==(const char *o) const { return strcmp_802ef234(c_str(), o) == 0; }
extern "C" Str *fn_8020c048(Str *, const Str *, int);
extern "C" Str *fn_8020c0fc(Str *, const Str *, int);
struct Stage { float x0, x1, a, b, c, d; ~Stage() {} };
struct Inner { Inner() { fn_8034f190(this); } Stage &operator[](unsigned i) { return stages[i]; } Stage *stages; unsigned short size; 
    void set(unsigned short n, Stage *p) { stages = p; size = n; } };
struct Elem {
    void set(unsigned a3, unsigned a2, unsigned a1, unsigned ac, unsigned ab) { f0 = 1; f3 = a3; f2 = a2; f1 = a1; c = ac; b = ab; }
    unsigned f0 : 1; unsigned f1 : 1; unsigned f2 : 1; unsigned f3 : 1; unsigned b : 3; unsigned c : 3; unsigned d : 6; unsigned short w;
    Inner inner;
    ~Elem() {}
};
struct ElemVec { Elem *start; Elem &operator[](unsigned i) { return start[i]; } };
struct Body { char u[72]; Body(); ~Body(); };
extern "C" void fn_80197dd4(Body *, unsigned, Elem *);
extern "C" void fn_80197e08(Body *, ElemVec *);
extern "C" void fn_80197ed0(Body *);
extern "C" void fn_80197f0c(Body *, Body *);
struct Record { Str name; float weight; Body body; unsigned char flag; };
struct Entry { Str name; unsigned char a, b; unsigned short c; };
struct Reader;
struct ReaderVtable {
    void *u0[12];
    int (*readWord)(Reader *, unsigned *, int);
    void *u34[15];
    int (*readByte)(Reader *, unsigned char *, int);
    void *u74;
    int (*readShort)(Reader *, unsigned short *, int);
    void *u7c;
    int (*readCount)(Reader *, unsigned *, int);
    void *u84[2];
    int (*readFloat)(Reader *, float *, int);
    void *u90;
    int (*readString)(Reader *, Str *, int);
};
struct Reader { ReaderVtable *vtable; };
struct Stream {
    Reader *reader;
    Stream(Reader *r) : reader(r) {}
    int readWord(unsigned &x) { return reader->vtable->readWord(reader, &x, 0); }
    int readByte(unsigned char &x) { return reader->vtable->readByte(reader, &x, 0); }
    int readShort(unsigned short &x) { return reader->vtable->readShort(reader, &x, 0); }
    int readCount(unsigned &x) { return reader->vtable->readCount(reader, &x, 0); }
    int readFloat(float &x) { return reader->vtable->readFloat(reader, &x, 0); }
    int readString(Str &x) { return reader->vtable->readString(reader, &x, 0); }
};
struct Self;
struct SelfVtable { void *u0[11]; int (*loadNew)(Self *, Stream *); int (*setCount)(Self *, unsigned); void *u34[3]; void (*addRecord)(Self *, Record *, ElemVec **, unsigned); };
struct Entries { Entry *start, *finish; Entry &operator[](unsigned i) { return start[i]; } unsigned size() const { return finish - start; } };
typedef _STL::vector<Stage, ModuleAllocator<Stage> > StageVec;
struct Self { SelfVtable *vtable; char u4[16]; Entries entries; char u1c[8]; struct { char *start; Record &operator[](unsigned i) { return ((Record *)start)[i]; } } records; char u28[28]; Str name; };
extern "C" int w3d_d41n_buffer_manager_load_stream_80191130(Self *self, Reader *r) {
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
    Elem *elems = new Elem[entryCount];
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
        ElemVec *list = 0;
        s.readFloat(rec.weight);
        s.readString(rec.name);
        rec.flag = 0;
        unsigned used = 0;
        Inner *in;
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
    delete[] elems;
    return 0;
}
