// (Worms 3D GameCube PAL, 0x80202714).
//
// Reads an object file into a table of objects: runs the header reader
// (tracing and returning on failure) and the section readers, allocates the
// object table at +28, creates the objects of each class record at +124
// through the factory from 0x8020b648 and each class's maker, stores the
// root object in the result with a reference, lets each object read itself
// and reports it to the optional listener at +36, frees the table, and runs
// the sort pass with state 2. Returns 0, or E_FAIL when a class has no
// maker. Names are inferred.

struct Reader;
struct Item {
    virtual void v0(); virtual void AddRef(); virtual void Release();
    virtual Item *Create();
    virtual void v5();
    virtual void Read(Reader *);
};
struct ClassItem : Item { };
struct Factory {
    virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void v3();
    virtual void a4(), a5(), a6(), a7(), a8(), a9(), a10(), a11(), a12(), a13(), a14(), a15(), a16(), a17(), a18();
    virtual Item *Find(void *);
};
struct Maker { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(),v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(),v18(),v19();
    virtual Item *Make(); };
struct Ref {
    Factory *p;
    Ref(Factory *o) { p = o; if (p) p->AddRef(); }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
};
struct Record { char u[8]; unsigned count; char u12[4]; char name[48]; };
struct Listener { virtual void Add(unsigned, Item *); };
struct Reader {
    char u0[24];
    int state;
    Item **items;
    unsigned total;
    Listener *listener;
    char u40[44];
    unsigned records;
    unsigned nitems;
    unsigned root;
    char u96[28];
    Record *table;
};
extern int g_trace;
extern const char s_bad[];
extern "C" void w3d_trace_stub_80347324(int *, const char *, ...);
extern "C" int fn_80202f34(Reader *);
extern "C" int w3d_d26e_read_records_802029b8(Reader *);
extern "C" int tsonnet_c26_skip_records_80202b18(Reader *);
extern "C" int tsonnet_c26_read_swap_80202bb4(Reader *);
extern "C" int fn_80202c5c(Reader *);
extern "C" int w3d_auto_80202f28(Reader *);
extern "C" Factory *w3d_auto_8020b648();
extern "C" int cc42b_sort_dispatch_802025dc(Reader *);
extern "C" int w3d_d31e_read_object_file_80202714(Reader *self, Item **out)
{
    *out = 0;
    self->state = 1;
    int hr = fn_80202f34(self);
    if (hr < 0) {
        w3d_trace_stub_80347324(&g_trace, s_bad);
        return hr;
    }
    w3d_d26e_read_records_802029b8(self);
    tsonnet_c26_skip_records_80202b18(self);
    tsonnet_c26_read_swap_80202bb4(self);
    fn_80202c5c(self);
    w3d_auto_80202f28(self);
    Ref factory(w3d_auto_8020b648());
    unsigned n = 1;
    self->items = new Item *[self->nitems + 1];
    self->items[0] = 0;
    for (unsigned i = 0; i < self->records; i++) {
        Record *r = &self->table[i];
        unsigned count = r->count;
        if (count) {
            Item *maker = factory.p->Find(r->name);
            self->items[n++] = maker;
            Item *m = 0;
            if (maker) m = maker->Create();
            if (!m) return 0x80004005;
            for (unsigned j = 1; j < count; j++) {
                self->items[n] = ((Maker *)m)->Make();
                n++;
            }
        }
    }
    self->total = n;
    Item *top = self->items[self->root];
    *out = top;
    top->AddRef();
    for (unsigned k = 1; k <= self->nitems; k++) {
        Item *o = self->items[k];
        o->Read(self);
        if (self->listener) self->listener->Add(k, o);
    }
    delete[] self->items;
    self->state = 2;
    cc42b_sort_dispatch_802025dc(self);
    self->state = 0;
    return 0;
}
