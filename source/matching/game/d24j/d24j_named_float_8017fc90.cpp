// Read a named float of a mesh's material (Worms 3D GameCube PAL, 0x8017fc90).
//
// Prepares the source at +40 when needed (0x8017ffbc; "Cound't..." is reported
// through 0x801fcb64 when it stays empty), queries its array interface
// (0x8040e0a8), holds it in a handle and scans the name/value pairs. Writes the
// value and returns 0, or returns 0x80004005 when the name is absent. The
// source is a real virtual call (built with -fvtable-thunks): the virtual call
// keeps the object in its own register and copies it to r3.

extern "C" int strcmp(const char *, const char *);
extern "C" int fn_8017ffbc(void *);
extern "C" int fn_801fcb64(const char *, int);
extern char text_803a779c[];
extern char iid_8040e0a8[];
// The handle is one word, held in an inline helper with its own stack block.

struct Pair { const char *name; float value; };
struct Count { int u; unsigned count; };
struct Array { void **vtable;
    void retain() { ((void (*)(Array *))vtable[3])(this); }
    void release() { ((void (*)(Array *))vtable[4])(this); }
    const Count *counts() { return ((const Count *(*)(Array *))vtable[8])(this); }
    const Pair *at(unsigned i) { return ((const Pair *(*)(Array *, unsigned))vtable[9])(this, i); }
};
struct Handle { Array *p;
    Handle() { p = 0; }
    Handle(Array *v) { p = v; if (v) v->retain(); }
    ~Handle() { if (p) p->release(); }
};
struct Source {
    virtual void slot_0();
    virtual void slot_1();
    virtual void slot_2();
    virtual void slot_3();
    virtual void slot_4();
    virtual void slot_5();
    virtual void slot_6();
    virtual void slot_7();
    virtual void slot_8();
    virtual void slot_9();
    virtual void slot_10();
    virtual void slot_11();
    virtual void query(void *iid, int z, Array **out);
};
inline void query_array(Source *s, Array **out) { *out = 0; s->query(iid_8040e0a8, 0, out); }
struct Mesh { char u[40]; Source *source; };
inline Array *get_array(Source *s) {
    Array *raw = 0;
    s->query(iid_8040e0a8, 0, &raw);
    Array *p = raw;
    if (p) p->release();
    return p;
}
inline int find_value(Mesh *m, const char *name, float *out) {
    Array *raw;
    query_array(m->source, &raw);
    Array *p = raw;
    if (p) p->release();
    Handle h(p);
    for (unsigned i = 0; i < h.p->counts()->count; i++) {
        if (strcmp(h.p->at(i)->name, name) == 0) {
            *out = h.p->at(i)->value;
            return 0;
        }
    }
    return 0x80004005;
}

extern "C" int d24j_named_float_8017fc90(Mesh *m, const char *name, float *out)
{
    if (m->source == 0) {
        fn_8017ffbc(m);
        if (m->source == 0) fn_801fcb64(text_803a779c, 0);
    }
    return find_value(m, name, out);
}
