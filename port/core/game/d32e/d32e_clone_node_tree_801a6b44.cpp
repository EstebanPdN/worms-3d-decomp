#include "w3d_ptr.h"
#line 1 "d32e_clone_node_tree_801a6b44.cpp"
// (Worms 3D GameCube PAL, 0x801a6b44).
//
// Clone visitor over an object tree, entered through a secondary-base
// pointer: decides by 0x801a69a8 whether a node is shared (returns an
// existing clone or the node) or copied; for a copy, walks the class
// properties from last to first and, for each object-valued property (type
// 24), reads the child, queries the object interface, and when its class
// derives from 0x80365788 replaces it with the clone found by 0x801a688c or,
// in deep mode, the result of visiting it. Handles array properties by index
// and single properties through member-function getters and setters. Returns
// 0, 1 if already handled, or the negative error.

inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
struct Prop;
struct Class { char u0[20]; Ptr32<Class> parent; char u24[36]; Ptr32<Ptr32<Prop>> first; Ptr32<Ptr32<Prop>> last; };
struct Desc { char u0[4]; unsigned short id; unsigned char arg; unsigned char flags; int type; };
extern "C" Ptr32<Prop> w3d_s21_vector_get_801e9db8(Ptr32<Class>, unsigned);
extern "C" int w3d_auto_801fffc8(int);
extern Class lbl_80365788[];
extern char lbl_8040c960[];
struct Node;
struct Unknown {
    int w3d_r_Query(Ptr32<const void> iid, Ptr32<Ptr32<Node>> out) __asm__(W3D_SYM("_ZN7Unknown5QueryEPKvPP4Node"));
    void w3d_r_AddRef() __asm__(W3D_SYM("_ZN7Unknown6AddRefEv")); int w3d_r_Release() __asm__(W3D_SYM("_ZN7Unknown7ReleaseEv"));
    Ptr32<Class> w3d_r_GetClass() __asm__(W3D_SYM("_ZN7Unknown8GetClassEv"));
 __attribute__((always_inline)) inline int Query(Ptr32<const void> w3d_a0, Ptr32<Ptr32<Node>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const void>, Ptr32<Ptr32<Node>>))w3d::vfn(this->w3d_vptr_Unknown, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unknown, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unknown, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Class> GetClass() { return ((Ptr32<Class> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unknown, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Unknown; };
struct Node : Unknown { char u4[2] __attribute__((aligned(__alignof__(Unknown)))); unsigned short id; };
struct Ref {
    Ptr32<Node> p;
    Ref() { p = 0; }
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Node *)w3d_p.get()) {}
 Ref(Node *q) { p = q; if (q) q->AddRef(); }
    Ref(const Ref &o);
    ~Ref() { if (p) p->Release(); }
    Ptr32<Node> operator->() const { return p; }
    Node &operator*() const { return *p; }
};
struct PropBase {
    Ptr32<Desc> desc;
    void w3d_r_v0() __asm__(W3D_SYM("_ZN8PropBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN8PropBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN8PropBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN8PropBase2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN8PropBase2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN8PropBase2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN8PropBase2v6Ev"));
    Ptr32<Ptr32<Node>> w3d_r_Array(Ptr32<Node>, int, int, Ptr32<unsigned int>) __asm__(W3D_SYM("_ZN8PropBase5ArrayEP4NodeiiPj"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_PropBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Ptr32<Node>> Array(Ptr32<Node> w3d_a0, int w3d_a1, int w3d_a2, Ptr32<unsigned int> w3d_a3) { return ((Ptr32<Ptr32<Node>> (*)(w3d_u32, Ptr32<Node>, int, int, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_PropBase, 9))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3); }  Ptr32<void> w3d_vptr_PropBase; };
struct Prop : PropBase {
    int u8 __attribute__((aligned(__alignof__(PropBase))));
    w3d::Pmf<Node, Ptr32<Node>()> get;
    w3d::Pmf<Node, void(Ptr32<Node>)> set;
};
struct Tree;
extern "C" int f11c_hierarchy_801a69a8(Ptr32<Tree>, Ptr32<Node>);
extern "C" Ptr32<Node> w3d_s20_find_value_801a688c(Ptr32<Tree>, Ptr32<Node>);
extern "C" void w3d_s10_assign_interface_801a66c0(Ptr32<Tree>, Ptr32<Node>);
extern "C" int w3d_s20_find_or_create_801a692c(Ptr32<Tree>, Ptr32<Node>);
extern "C" void w3d_k5b_iface_array_field_set_801ef2ec(Ptr32<Node>, int, int, Ptr32<Node>, unsigned);
struct Iface {
    char u0[24]; Ptr32<Ptr32<int (Ptr32<Iface>, Ptr32<Node>)>> table;
    int Visit(Ptr32<Node> n) { return table[n->id](this, n); }
};
struct TreeBase {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN8TreeBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN8TreeBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN8TreeBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN8TreeBase2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN8TreeBase2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN8TreeBase2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN8TreeBase2v6Ev"));
    void w3d_r_v7() __asm__(W3D_SYM("_ZN8TreeBase2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN8TreeBase2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN8TreeBase2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN8TreeBase3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN8TreeBase3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN8TreeBase3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN8TreeBase3v13Ev"));
    Ptr32<Node> w3d_r_Current() __asm__(W3D_SYM("_ZN8TreeBase7CurrentEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Node> Current() { return ((Ptr32<Node> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TreeBase, 16))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_TreeBase; };
struct Tree : TreeBase {
    char iface[40] __attribute__((aligned(__alignof__(TreeBase))));
    int mode;
    char u48[24];
    int stop;
    Ptr32<Iface> I() { return (Ptr32<Iface>)iface; }
};
static inline bool IsA(Ptr32<Class> t, Ptr32<Class> k) {
    while (t != k) {
        Ptr32<Class> p = t->parent;
        if (t == p) return false;
        t = p;
    }
    return true;
}
extern "C" int w3d_d32e_clone_node_tree_801a6b44(Ptr32<char> ip, Ptr32<Node> x)
{
    Ptr32<Tree> self = ip ? w3d::R((Ptr32<Tree>)(ip - 4)) : 0;
    int m = f11c_hierarchy_801a69a8(self, x);
    self->stop = 0;
    if (m == 1) {
        Ptr32<Node> v = w3d_s20_find_value_801a688c(self, x);
        if (v) w3d_s10_assign_interface_801a66c0(self, v);
        else w3d_s10_assign_interface_801a66c0(self, x);
        return 0;
    }
    int r = w3d_s20_find_or_create_801a692c(self, x);
    if (r < 0) return r;
    if (r == 1) return 1;
    Ref cur = self->Current();
    bool any = self->mode != 0;
    Ptr32<Class> c = cur->GetClass();
    int i = c->last - c->first;
    while (i--) {
        Ptr32<Prop> q = w3d_s21_vector_get_801e9db8(c, i);
        if (w3d_auto_801fffc8(q->desc->type) == 24) {
            if (q->desc->flags & 1) {
                unsigned n;
                Ptr32<Ptr32<Node>> arr = q->Array(cur.p, 0, 2, &n);
                for (unsigned j = 0; j < n; j++) {
                    Ptr32<Node> e = arr[j];
                    if (e) {
                        Ref o;
                        if (e->Query(lbl_8040c960, &o.p) >= 0) {
                            if (IsA(o->GetClass(), lbl_80365788)) {
                                Ptr32<Node> on = o.p;
                                Ptr32<Node> v = w3d_s20_find_value_801a688c(self, on);
                                if (!v) {
                                    if (any) {
                                        w3d_s10_assign_interface_801a66c0(self, 0);
                                        self->I()->Visit(on);
                                        v = self->Current();
                                    } else v = on;
                                }
                                if (v != on)
                                    w3d_k5b_iface_array_field_set_801ef2ec(cur.p, q->desc->id, q->desc->arg, v, j);
                            }
                        }
                    }
                }
            } else {
                Ptr32<Node> e = ((q->get))(&((*cur)));
                if (e) {
                    Ref o;
                    if (e->Query(lbl_8040c960, &o.p) >= 0) {
                        if (IsA(o->GetClass(), lbl_80365788)) {
                            Ptr32<Node> on = o.p;
                            Ptr32<Node> v = w3d_s20_find_value_801a688c(self, on);
                            if (!v) {
                                if (any) {
                                    w3d_s10_assign_interface_801a66c0(self, 0);
                                    self->I()->Visit(on);
                                    v = self->Current();
                                } else v = on;
                            }
                            if (v != on) ((q->set))(&((*cur)), v);
                        }
                    }
                }
            }
        }
    }
    w3d_s10_assign_interface_801a66c0(self, cur.p);
    return 0;
}


