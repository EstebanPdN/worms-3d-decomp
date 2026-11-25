#include "w3d_ptr.h"
#line 1 "d31e_init_actor_tree_801e7e24.cpp"
// (Worms 3D GameCube PAL, 0x801e7e24).
//
// Initializes an actor and its children: on first use creates the worker
// from class record 0x803657d8, keeps it in the reference at +48, sets its
// owner and flag and attaches it to the parent's worker (or null for a
// root); then sets up hooks through 0x801e7658, recurses into each direct
// child found with the child iterator, and calls the worker's prepare slot.
// Bracketed by 0x8020b5c8(-1) and 0x8020b5d0. Returns 0. Names are inferred.

struct Actor;
struct ActorBase { char u0[4]; Ptr32<Actor> next; char u8[12]; };
struct Actor;
struct Worker;
struct Ref {
    Ptr32<Worker> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Worker *)w3d_p.get()); }
 Ref &operator=(Worker *q);
};
extern "C" Ptr32<Actor> w3d_actor_types_first();
extern "C" Ptr32<Actor> w3d_auto_8020ff34();
struct Actor : ActorBase {
    Ptr32<Actor> parent __attribute__((aligned(__alignof__(ActorBase))));
    char u24[24];
    Ref worker;
};
struct ChildIter {
    Ptr32<Actor> root;
    Ptr32<Actor> cur;
    unsigned int rest:30; unsigned int both:1; unsigned int second:1;
    template <class W3dU> ChildIter(Ptr32<W3dU> w3d_p) : ChildIter((Actor *)w3d_p.get()) {}
 ChildIter(Actor *r) {
        second = 0;
        both = 0;
        root = r;
        cur = w3d_actor_types_first();
        while (cur == r || (cur && cur->parent != r)) cur = cur->next;
        if (!cur && both) {
            cur = w3d_auto_8020ff34();
            second = 1;
            while (cur == r || (cur && cur->parent != r)) cur = cur->next;
        }
    }
    ChildIter(Ptr32<Actor> r, int) { root = r; cur = 0; }
    Ptr32<Actor> operator*() const { return cur; }
    bool operator!=(const ChildIter &o) const { return root != o.root || cur != o.cur; }
    ChildIter &operator++() {
        if (cur) {
            do {
                cur = cur->next;
            } while (cur == root || (cur && cur->parent != root));
            if (!cur) {
                if (!second) {
                    if (both) {
                        cur = w3d_auto_8020ff34();
                        second = 1;
                        while (cur == root || (cur && cur->parent != root)) cur = cur->next;
                    }
                }
            }
        }
        return *this;
    }
};
struct WorkerBase {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN10WorkerBase2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN10WorkerBase6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN10WorkerBase7ReleaseEv")); void w3d_r_v3() __asm__(W3D_SYM("_ZN10WorkerBase2v3Ev")), w3d_r_v4() __asm__(W3D_SYM("_ZN10WorkerBase2v4Ev")), w3d_r_v5() __asm__(W3D_SYM("_ZN10WorkerBase2v5Ev"));
    void w3d_r_attach(Ptr32<Worker>) __asm__(W3D_SYM("_ZN10WorkerBase6attachEP6Worker"));
    void w3d_r_v7() __asm__(W3D_SYM("_ZN10WorkerBase2v7Ev"));
    int w3d_r_prepare() __asm__(W3D_SYM("_ZN10WorkerBase7prepareEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void attach(Ptr32<Worker> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Worker>))w3d::vfn(this->w3d_vptr_WorkerBase, 8))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int prepare() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_WorkerBase, 10))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_WorkerBase; };
struct Worker : WorkerBase {
    char u4[28] __attribute__((aligned(__alignof__(WorkerBase))));
    unsigned int rest:30; unsigned int b1:1; unsigned int b0:1;
    char u36[28];
    Ptr32<Actor> owner;
};
inline Ref &Ref::operator=(Worker *q) {
    if (q) q->AddRef();
    if (p) p->Release();
    p = q;
    return *this;
}
struct ClassInfo;
extern ClassInfo k_803657d8[];
extern "C" Ptr32<Worker> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<const ClassInfo>);
extern "C" int w3d_constant_8020b5c8(int);
extern "C" void w3d_empty_8020b5d0();
extern "C" int fn_801e7658(Ptr32<Actor>);
extern "C" int w3d_d31e_init_actor_tree_801e7e24(Ptr32<Actor> self)
{
    w3d_constant_8020b5c8(-1);
    if (!self->worker.p) {
        self->worker = w3d_r24b_invoke_ready_callback_8020fcb4(k_803657d8);
        Ptr32<Worker> o = self->worker.p;
        o->owner = self;
        o->b1 = 1;
        if (self->parent == self) o->attach(0);
        else o->attach(self->parent->worker.p);
    }
    fn_801e7658(self);
    ChildIter it(self), end(self, 0);
    while (it != end) {
        w3d_d31e_init_actor_tree_801e7e24(*it);
        ++it;
    }
    self->worker.p->prepare();
    w3d_empty_8020b5d0();
    return 0;
}


