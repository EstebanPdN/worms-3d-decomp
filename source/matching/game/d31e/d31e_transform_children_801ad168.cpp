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

struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Ref {
    Obj *p;
    Ref() : p(0) { }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
    Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
    operator Obj *() const { return p; }
};
struct Node { char pad[6]; unsigned short kind; };
struct NodeList { char pad[24]; int count; char pad28[4]; Node *items[1]; };
struct Tree : Obj { char pad[40]; NodeList *children; };
struct Pass;
typedef int (*Handler)(Pass *, Node *);
struct Pass { char pad[24]; Handler *handlers; };
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
extern "C" void w3d_k7b_task_owner_append_801acdd4(Task *, void *);
extern "C" Tree *w3d_s20_query_then_run_801ad108(Task *, Tree *);
extern "C" void w3d_k5b_iface_array_field_set_801ef2ec(Tree *, int, int, Obj *, int);
extern "C" void fn_801ef380(Tree *, int, int, int, int);

extern "C" int w3d_d31e_transform_children_801ad168(Task *self, Tree *tree, int flag)
{
    std::vector<int> removed;
    int saved = self->preserve;
    if (saved) flag = 0;
    Ref copy;
    self->preserve = 0;
    int preserved = saved;
    NodeList *list = tree->children;
    Node **p = list->items;
    Node **base = p;
    Node **end = p + list->count;
    for (; p != end; p++) {
        self->changed = 0;
        self->result = 0;
        Pass *pass = &self->pass;
        int hr = pass->handlers[(*p)->kind](pass, *p);
        if (hr < 0) return hr;
        Obj *r = self->result;
        if (r) {
            if (flag) {
                w3d_k7b_task_owner_append_801acdd4(self, r);
                self->result = 0;
            } else {
                if (!preserved) {
                    Tree *t = w3d_s20_query_then_run_801ad108(self, tree);
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
        int *e = removed.end();
        for (int *i = removed.begin(); i != e; i++) {
            fn_801ef380(tree, 44, 3, *i - n, 1);
            n++;
        }
    }
    self->result = copy.p;
    self->changed = flag;
    return 0;
}
