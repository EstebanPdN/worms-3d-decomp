#include "w3d_ptr.h"
#line 1 "d31e_transform_children_801ad168.cpp"
// (Worms 3D GameCube PAL, 0x801ad168).
//
// Runs a transform pass over the child list at +44 of a tree: for each child
// calls the handler selected by the child's kind at +6. On failure returns
// the error. A replacement in the result reference at +96 is either appended
// to the task (flag set) or stored into a child slot of the tree, copying
// the tree first through 0x801ad108 unless already copied or preserved.
// Children marked changed at +88 are appended, or their indices pushed on a
// real STLport vector and erased after the loop. Leaves the copy in the
// result and the flag in +88. Names are inferred.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <vector>

struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref {
    Ptr32<Obj> p;
    Ref() : p(0) { }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
    operator Ptr32<Obj>() const { return (Obj *)this->operator Obj *(); }
 operator Obj *() const { return p; }
};
struct Node { char pad[6]; unsigned short kind; };
struct NodeList { char pad[24]; int count; char pad28[4]; Ptr32<Node> items[1]; };
struct Tree : Obj { char pad[40] __attribute__((aligned(__alignof__(Obj)))); Ptr32<NodeList> children; };
struct Pass;
typedef Ptr32<int (Ptr32<Pass>, Ptr32<Node>)> Handler;
struct Pass { char pad[24]; Ptr32<Handler> handlers; };
struct Task {
    char pad0[4];
    Pass pass;
    char pad32[56];
    int changed;
    char pad92[4];
    Ref result;
    char pad100[36];
    int preserve;
};
extern "C" void w3d_k7b_task_owner_append_801acdd4(Ptr32<Task>, Ptr32<void>);
extern "C" Ptr32<Tree> w3d_s20_query_then_run_801ad108(Ptr32<Task>, Ptr32<Tree>);
extern "C" void w3d_k5b_iface_array_field_set_801ef2ec(Ptr32<Tree>, int, int, Ptr32<Obj>, int);
extern "C" void fn_801ef380(Ptr32<Tree>, int, int, int, int);

extern "C" int w3d_d31e_transform_children_801ad168(Ptr32<Task> self, Ptr32<Tree> tree, int flag)
{
    std::vector<int> removed;
    int saved = self->preserve;
    if (saved) flag = 0;
    Ref copy;
    self->preserve = 0;
    int preserved = saved;
    Ptr32<NodeList> list = tree->children;
    Ptr32<Ptr32<Node>> p = list->items;
    Ptr32<Ptr32<Node>> base = p;
    Ptr32<Ptr32<Node>> end = p + list->count;
    for (; p != end; p++) {
        self->changed = 0;
        self->result = 0;
        Ptr32<Pass> pass = &self->pass;
        int hr = pass->handlers[(*p)->kind](pass, *p);
        if (hr < 0) return hr;
        Ptr32<Obj> r = self->result;
        if (r) {
            if (flag) {
                w3d_k7b_task_owner_append_801acdd4(self, r);
                self->result = 0;
            } else {
                if (!preserved) {
                    Ptr32<Tree> t = w3d_s20_query_then_run_801ad108(self, tree);
                    copy = t;
                    tree = t;
                }
                w3d_k5b_iface_array_field_set_801ef2ec(tree, 44, 3, r, p - base);
                preserved = 1;
                self->result = 0;
            }
        } else {
            int changed = self->changed;
            if (flag) {
                if (!changed) {
                    w3d_k7b_task_owner_append_801acdd4(self, *p);
                    continue;
                }
            } else if (!changed) continue;
            if (!flag) removed.push_back(p - base);
        }
    }
    {
        int n = 0;
        Ptr32<int> e = removed.end();
        for (Ptr32<int> i = removed.begin(); i != e; i++) {
            fn_801ef380(tree, 44, 3, *i - n, 1);
            n++;
        }
    }
    self->result = copy.p;
    self->changed = flag;
    return 0;
}


