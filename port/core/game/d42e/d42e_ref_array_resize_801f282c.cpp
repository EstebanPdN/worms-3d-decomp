#include "w3d_ptr.h"
#line 1 "d42e_ref_array_resize_801f282c.cpp"
// (Worms 3D GameCube PAL, 0x801f282c).
//
// Resize of a reference array: shrinking clears the dropped references;
// growing allocates a new counted array, copies the references with add-ref
// and release, destroys the old array and stores the new capacity.

extern "C" Ptr32<void> w3d_heap_allocate_801fe220(unsigned);
extern "C" void w3d_task_array_release_801fe240(Ptr32<void>);
struct Obj { void w3d_r_v8() __asm__(W3D_SYM("_ZN3Obj2v8Ev")); void w3d_r_add_ref() __asm__(W3D_SYM("_ZN3Obj7add_refEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN3Obj7releaseEv"));  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add_ref() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ptr {
    Ptr32<Obj> p;
    Ptr() : p(0) { }
    ~Ptr() { if (p) p->release(); }
    Ptr &operator=(const Ptr &o) { if (o.p) o.p->add_ref(); if (p) p->release(); p = o.p; return *this; }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ptr &operator=(Obj *o) { if (o) o->add_ref(); if (p) p->release(); p = o; return *this; }
    static void *operator new[](__SIZE_TYPE__ n) { return w3d_heap_allocate_801fe220(n); }
    static void operator delete[](void *q) { w3d_task_array_release_801fe240(q); }
};
struct RefArray {
    unsigned count; unsigned short cap; Ptr32<Ptr> data;
    void resize(unsigned n);
};
extern "C" void w3d_d42e_ref_array_resize_801f282c(Ptr32<RefArray> self, int n)
{
    if (self->cap >= n) {
        for (unsigned i = n; i < self->count; i++) self->data[i] = (Ptr32<Obj>)0;
        self->count = n;
    } else {
        Ptr32<Ptr> fresh = w3d::new_array<Ptr>(n);
        if (self->data) {
            for (unsigned i = 0; i < self->count; i++) fresh[i] = self->data[i];
            w3d::delete_array(self->data);
        }
        self->count = n;
        self->data = fresh;
        self->cap = n;
    }
}


