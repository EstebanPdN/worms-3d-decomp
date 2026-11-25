// (Worms 3D GameCube PAL, 0x801f282c).
//
// Resize of a reference array: shrinking clears the dropped references;
// growing allocates a new counted array, copies the references with add-ref
// and release, destroys the old array and stores the new capacity.

extern "C" void *w3d_heap_allocate_801fe220(unsigned);
extern "C" void w3d_task_array_release_801fe240(void *);
struct Obj { virtual void v8(); virtual void add_ref(); virtual void release(); };
struct Ptr {
    Obj *p;
    Ptr() : p(0) { }
    ~Ptr() { if (p) p->release(); }
    Ptr &operator=(const Ptr &o) { if (o.p) o.p->add_ref(); if (p) p->release(); p = o.p; return *this; }
    Ptr &operator=(Obj *o) { if (o) o->add_ref(); if (p) p->release(); p = o; return *this; }
    static void *operator new[](unsigned n) { return w3d_heap_allocate_801fe220(n); }
    static void operator delete[](void *q) { w3d_task_array_release_801fe240(q); }
};
struct RefArray {
    unsigned count; unsigned short cap; Ptr *data;
    void resize(unsigned n);
};
extern "C" void w3d_d42e_ref_array_resize_801f282c(RefArray *self, int n)
{
    if (self->cap >= n) {
        for (unsigned i = n; i < self->count; i++) self->data[i] = (Obj *)0;
        self->count = n;
    } else {
        Ptr *fresh = new Ptr[n];
        if (self->data) {
            for (unsigned i = 0; i < self->count; i++) fresh[i] = self->data[i];
            delete[] self->data;
        }
        self->count = n;
        self->data = fresh;
        self->cap = n;
    }
}
