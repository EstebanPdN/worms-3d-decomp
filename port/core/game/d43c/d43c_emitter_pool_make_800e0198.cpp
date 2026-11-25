#include "w3d_ptr.h"
#line 1 "d43c_emitter_pool_make_800e0198.cpp"
// d43c: 0x800e0198. Builds a particle pool of the requested type: releases
// the old pool, then if the heap has room for the items plus a 4 KB margin
// allocates the pool object, sets its table and context, allocates and
// constructs the item array and points each item at the context. need is one
// function-level variable shared by the arms, which makes it a global pseudo
// and gives the separate intermediate registers. Names are inferred.
extern int heap_804aecac;
extern "C" unsigned heap_free_80209a20(Ptr32<void>);
extern "C" Ptr32<void> alloc_800de8d8(unsigned);
extern "C" Ptr32<void> alloc_800dc5bc(unsigned);
extern Ptr32<void> vtA_8040ff48[]; extern Ptr32<void> vtB_8040ff28[]; extern Ptr32<void> vtC_8040ff08[];
#define NEW void *operator new[](__SIZE_TYPE__ n) { return alloc_800dc5bc(n); } void operator delete[](void *);
struct PA { char u0[108]; Ptr32<void> owner; char u112[4]; PA(); ~PA(); NEW };
struct PB { char u0[108]; Ptr32<void> owner; char u112[64]; PB(); ~PB(); NEW };
struct PC { char u0[108]; Ptr32<void> owner; char u112[72]; PC(); ~PC(); NEW };
struct Pool { Ptr32<Ptr32<void>> vtable; Ptr32<void> items; Ptr32<void> ctx; };
struct Self { char u0[4]; Ptr32<Pool> pool; };
extern "C" void release_800e0400(Ptr32<Self>);
extern "C" void d43c_emitter_pool_make_800e0198(Ptr32<Self> self, int n, int type, Ptr32<void> ctx) {
    release_800e0400(self);
    self->pool = 0;
    unsigned need;
    switch (type) {
    case 0: {
        unsigned size = n * sizeof(PA);
        need = ((size + 43) & ~31) + 4096;
        if (need < heap_free_80209a20(&heap_804aecac)) {
            Ptr32<Pool> p = (Ptr32<Pool>)alloc_800de8d8(12);
            p->ctx = ctx;
            p->vtable = vtA_8040ff48;
            Ptr32<PA> items = w3d::new_array<PA>(n);
            p->items = items;
            for (unsigned i = 0; i < (unsigned)n; i++) ((Ptr32<PA>)p->items)[i].owner = p->ctx;
            self->pool = p;
        }
        break;
    }
    case 1: {
        unsigned size = n * sizeof(PB);
        need = ((size + 43) & ~31) + 4096;
        if (need < heap_free_80209a20(&heap_804aecac)) {
            Ptr32<Pool> p = (Ptr32<Pool>)alloc_800de8d8(12);
            p->ctx = ctx;
            p->vtable = vtB_8040ff28;
            Ptr32<PB> items = w3d::new_array<PB>(n);
            p->items = items;
            for (unsigned i = 0; i < (unsigned)n; i++) ((Ptr32<PB>)p->items)[i].owner = p->ctx;
            self->pool = p;
        }
        break;
    }
    case 2: {
        unsigned size = n * sizeof(PC);
        need = ((size + 43) & ~31) + 4096;
        if (need < heap_free_80209a20(&heap_804aecac)) {
            Ptr32<Pool> p = (Ptr32<Pool>)alloc_800de8d8(12);
            p->ctx = ctx;
            p->vtable = vtC_8040ff08;
            Ptr32<PC> items = w3d::new_array<PC>(n);
            p->items = items;
            for (unsigned i = 0; i < (unsigned)n; i++) ((Ptr32<PC>)p->items)[i].owner = p->ctx;
            self->pool = p;
        }
        break;
    }
    }
}


