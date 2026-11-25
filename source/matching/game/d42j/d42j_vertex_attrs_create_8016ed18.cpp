// Creates the four vertex attribute objects of a mesh format from a constant table and returns the array.
// Names are inferred: the table entries are the four values handed to the attribute setter.
struct Attr {
    virtual void s0(); virtual void addRef(); virtual void release();
};
struct AttrDesc { unsigned short a, b; unsigned char c, d; };
extern const AttrDesc table_803a645c[];
extern char type_80361ad8[];
extern "C" Attr *w3d_r24b_invoke_ready_callback_8020fcb4(void *);
extern "C" void w3d_auto_8016f8a0(Attr *, unsigned short, unsigned short, unsigned short, unsigned char);
struct Ptr { Attr *p;
    Ptr &operator=(Attr *q) { if (q) q->addRef(); if (p) p->release(); p = q; return *this; }
};
struct Arr {
    unsigned size; unsigned short cap; Ptr *data;
    Ptr *begin() { return data; }
};
extern "C" void w3d_d30k_compact_vector_resize_80210b90(Arr *, int);
struct Self { char u[20]; Arr arr; };
inline void resize(Arr &a, int n) { w3d_d30k_compact_vector_resize_80210b90(&a, n); }

extern "C" Ptr *vertex_attrs_create_8016ed18(Self *self, int *count)
{
    int n = 4;
    *count = n;
    resize(self->arr, n);
    for (unsigned i = 0; i < n; ++i) {
        Attr *o = w3d_r24b_invoke_ready_callback_8020fcb4(type_80361ad8);
        Ptr *slots = self->arr.begin();
        slots[i] = o;
        w3d_auto_8016f8a0(o, table_803a645c[i].a, table_803a645c[i].b, table_803a645c[i].c, table_803a645c[i].d);
    }
    return self->arr.begin();
}
