// d43c: 0x800e0198. Builds a particle pool of the requested type: releases
// the old pool, then if the heap has room for the items plus a 4 KB margin
// allocates the pool object, sets its table and context, allocates and
// constructs the item array and points each item at the context. need is one
// function-level variable shared by the arms, which makes it a global pseudo
// and gives the separate intermediate registers. Names are inferred.
extern int heap_804aecac;
extern "C" unsigned heap_free_80209a20(void *);
extern "C" void *alloc_800de8d8(unsigned);
extern "C" void *alloc_800dc5bc(unsigned);
extern void *vtA_8040ff48[], *vtB_8040ff28[], *vtC_8040ff08[];
#define NEW void *operator new[](unsigned n) { return alloc_800dc5bc(n); } void operator delete[](void *);
struct PA { char u0[108]; void *owner; char u112[4]; PA(); ~PA(); NEW };
struct PB { char u0[108]; void *owner; char u112[64]; PB(); ~PB(); NEW };
struct PC { char u0[108]; void *owner; char u112[72]; PC(); ~PC(); NEW };
struct Pool { void **vtable; void *items; void *ctx; };
struct Self { char u0[4]; Pool *pool; };
extern "C" void release_800e0400(Self *);
extern "C" void d43c_emitter_pool_make_800e0198(Self *self, int n, int type, void *ctx) {
    release_800e0400(self);
    self->pool = 0;
    unsigned need;
    switch (type) {
    case 0: {
        unsigned size = n * sizeof(PA);
        need = ((size + 43) & ~31) + 4096;
        if (need < heap_free_80209a20(&heap_804aecac)) {
            Pool *p = (Pool *)alloc_800de8d8(12);
            p->ctx = ctx;
            p->vtable = vtA_8040ff48;
            PA *items = new PA[n];
            p->items = items;
            for (unsigned i = 0; i < (unsigned)n; i++) ((PA *)p->items)[i].owner = p->ctx;
            self->pool = p;
        }
        break;
    }
    case 1: {
        unsigned size = n * sizeof(PB);
        need = ((size + 43) & ~31) + 4096;
        if (need < heap_free_80209a20(&heap_804aecac)) {
            Pool *p = (Pool *)alloc_800de8d8(12);
            p->ctx = ctx;
            p->vtable = vtB_8040ff28;
            PB *items = new PB[n];
            p->items = items;
            for (unsigned i = 0; i < (unsigned)n; i++) ((PB *)p->items)[i].owner = p->ctx;
            self->pool = p;
        }
        break;
    }
    case 2: {
        unsigned size = n * sizeof(PC);
        need = ((size + 43) & ~31) + 4096;
        if (need < heap_free_80209a20(&heap_804aecac)) {
            Pool *p = (Pool *)alloc_800de8d8(12);
            p->ctx = ctx;
            p->vtable = vtC_8040ff08;
            PC *items = new PC[n];
            p->items = items;
            for (unsigned i = 0; i < (unsigned)n; i++) ((PC *)p->items)[i].owner = p->ctx;
            self->pool = p;
        }
        break;
    }
    }
}
