// Load mesh channel data from a stream, GWMP8P rev0 0x80191a70. Reads the
// entry count and sizes the entries through a virtual call, reads each entry's
// bytes, short and name, then for each record reads its weight, name and list
// size, adds the record (0x8019217c family, through the vtable), and reads
// every list element: four flag words into the first four bits, a short, two
// 3-bit fields, and the stage count; the element is then stored with its first
// flag set, its stages allocated through the record body, and each stage's six
// floats read in file order. Finally the body is finished and copied to the
// stored record.

extern "C" void * fn_803426b8(void *);
extern "C" void fn_8034f190(void *);
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" void * fn_80197c8c(void *);
extern "C" void fn_80197ce4(void *, int);
extern "C" void fn_80197d78(void *);
struct Str {
    char *text;
    Str() { fn_803426b8(this); }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Stage { float x0, x1, a, b, c, d; };
struct Inner { Inner() { fn_8034f190(this); } Stage *stages; int size; };
struct Elem {
    unsigned f0 : 1; unsigned f1 : 1; unsigned f2 : 1; unsigned f3 : 1; unsigned b : 3; unsigned c : 3; unsigned d : 6; unsigned short w;
    Inner inner;
};
struct ElemVec { Elem *start; Elem &operator[](unsigned i) { return start[i]; } };
struct Body {
    char u[72];
    Body() { fn_80197c8c(this); }
    ~Body() { fn_80197ce4(this, 2); }
};
extern "C" void fn_80197dd4(Body *, unsigned, Elem *);
extern "C" void fn_80197e08(Body *, ElemVec *);
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
    int readWord(unsigned &x) { return reader->vtable->readWord(reader, &x, 0); }
    int readByte(unsigned char &x) { return reader->vtable->readByte(reader, &x, 0); }
    int readShort(unsigned short &x) { return reader->vtable->readShort(reader, &x, 0); }
    int readCount(unsigned &x) { return reader->vtable->readCount(reader, &x, 0); }
    int readFloat(float &x) { return reader->vtable->readFloat(reader, &x, 0); }
    int readString(Str &x) { return reader->vtable->readString(reader, &x, 0); }
};
struct Self;
struct SelfVtable { void *u0[12]; int (*setCount)(Self *, unsigned); void *u34[3]; void (*addRecord)(Self *, Record *, ElemVec **, unsigned); };
struct Entries { Entry *start; Entry &operator[](unsigned i) { return start[i]; } };
struct Self { SelfVtable *vtable; char u4[16]; Entries entries; char u18[12]; struct { char *start; Record &operator[](unsigned i) { return ((Record *)start)[i]; } } records; };
extern "C" int d27j_load_stream_80191a70(Self *self, Stream *s) {
    unsigned entryCount, recordCount;
    s->readCount(entryCount);
    self->vtable->setCount(self, entryCount);
    Elem e;
    unsigned i;
    for (i = 0; i < entryCount; ++i) {
        s->readByte(self->entries[i].a);
        s->readShort(self->entries[i].c);
        s->readByte(self->entries[i].b);
        s->readString(self->entries[i].name);
    }
    s->readCount(recordCount);
    for (unsigned r = 0; r < recordCount; ++r) {
        Record rec;
        s->readFloat(rec.weight);
        s->readString(rec.name);
        unsigned listSize;
        s->readCount(listSize);
        rec.flag = 0;
        ElemVec *list;
        self->vtable->addRecord(self, &rec, &list, listSize);
        fn_80197d78(&rec.body);
        for (i = 0; i < listSize; ++i) {
            unsigned v;
            s->readWord(v);
            e.f0 = v;
            s->readWord(v);
            e.f3 = v;
            s->readWord(v);
            e.f2 = v;
            s->readWord(v);
            e.f1 = v;
            s->readShort(e.w);
            unsigned u, stageCount;
            s->readCount(u);
            e.c = u;
            s->readCount(u);
            e.b = u;
            s->readCount(stageCount);
            (*list)[i].f0 = 1;
            (*list)[i].f3 = e.f3;
            (*list)[i].f2 = e.f2;
            (*list)[i].f1 = e.f1;
            (*list)[i].c = e.c;
            (*list)[i].b = e.b;
            (*list)[i].w = e.w;
            fn_80197dd4(&rec.body, stageCount, &(*list)[i]);
            for (unsigned k = 0; k < stageCount; ++k) {
                Stage &t = (*list)[i].inner.stages[k];
                s->readFloat(t.a);
                s->readFloat(t.b);
                s->readFloat(t.c);
                s->readFloat(t.d);
                s->readFloat(t.x0);
                s->readFloat(t.x1);
            }
        }
        fn_80197e08(&rec.body, list);
        fn_80197f0c(&rec.body, &self->records[r].body);
    }
    return 0;
}
