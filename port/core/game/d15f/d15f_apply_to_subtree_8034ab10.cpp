#include "w3d_ptr.h"
#line 1 "d15f_apply_to_subtree_8034ab10.cpp"
// Applies an argument to a node's target object and, optionally, to the
// targets of the node's direct children. GC32 reconstruction from the original
// instructions; class, field and slot names are inferred.
//
// Node handles carry a 12-bit table index in their low bits; a node is valid
// only when its stored handle equals the requested one. Before applying, the
// target's type descriptor is tested against three descriptors (walking the
// parent chain at +20 until a descriptor is its own parent) to select an
// engine-context mode (8, 6 or 7). The mode is stored through an inline
// helper, so each branch holds its constant in a saved register across the
// context call and the jump pass merges the three identical call/store tails.
// The apply result is returned; child application stops at the first negative
// result. Invalid handles return E_FAIL (0x80004005).
//
// Virtual slots are reference-ABI observations (4-byte entries after an
// 8-byte header: +20 type descriptor, +36 apply), hence -fvtable-thunks.
// The views are partial: no vtable, descriptor or member is defined here.

struct D15fTypeDesc {
    char pad_00[20];
    Ptr32<D15fTypeDesc> parent;
    inline bool is_a(Ptr32<D15fTypeDesc> target)
    {
        Ptr32<D15fTypeDesc> t = this;
        while (t != target) {
            if (t == t->parent)
                return false;
            t = t->parent;
        }
        return true;
    }
};
struct D15fTarget {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN10D15fTarget15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN10D15fTarget6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN10D15fTarget7releaseEv"));
    Ptr32<D15fTypeDesc> w3d_r_type() __asm__(W3D_SYM("_ZN10D15fTarget4typeEv"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN10D15fTarget7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN10D15fTarget7slot_28Ev"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN10D15fTarget7slot_32Ev"));
    int w3d_r_apply(Ptr32<void> arg) __asm__(W3D_SYM("_ZN10D15fTarget5applyEPv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<D15fTypeDesc> type() { return ((Ptr32<D15fTypeDesc> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D15fTarget, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int apply(Ptr32<void> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_D15fTarget, 9))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D15fTarget; };
// Observed 36-byte node record.
struct D15fNode {
    char pad_00[6];
    unsigned short first_child;
    char pad_08[2];
    unsigned short next_sibling;
    Ptr32<D15fTarget> target;
    char pad_10[4];
    unsigned handle;
    char pad_18[12];
};
struct D15fNodeTable { Ptr32<D15fNode> nodes; };
struct D15fEngineContext { char pad_00[60]; int mode; };
extern "C" Ptr32<D15fEngineContext> w3d_engine_get_context(void);
extern "C" Ptr32<D15fTarget> w3d_actor_from_handle(Ptr32<D15fNodeTable> tree, unsigned handle);
extern D15fTypeDesc type_803618f0[];
extern D15fTypeDesc type_80361860[];
extern D15fTypeDesc type_803617d0[];

inline void set_context_mode(int mode)
{
    w3d_engine_get_context()->mode = mode;
}

extern "C" int d15f_apply_to_subtree_8034ab10(Ptr32<D15fNodeTable> tree, Ptr32<void> arg, unsigned handle, int recurse)
{
    Ptr32<D15fNode> node;
    if (handle == 0xffffffff) {
        node = 0;
    } else {
        Ptr32<D15fNode> candidate = &tree->nodes[handle & 0xfff];
        node = 0;
        if (candidate->handle == handle)
            node = candidate;
    }
    if (node == 0)
        return (int)0x80004005;
    w3d_engine_get_context();
    if (node->target->type()->is_a(type_803618f0))
        set_context_mode(8);
    else if (node->target->type()->is_a(type_80361860))
        set_context_mode(6);
    else if (node->target->type()->is_a(type_803617d0))
        set_context_mode(7);
    int result = node->target->apply(arg);
    if (result >= 0 && recurse != 0) {
        unsigned handles[256];
        int count = 0;
        unsigned index = node->first_child;
        while (index != 0) {
            Ptr32<D15fNode> child = &tree->nodes[index];
            handles[count++] = child->handle;
            index = child->next_sibling;
        }
        for (int i = 0; i < count; i++) {
            Ptr32<D15fTarget> t = w3d_actor_from_handle(tree, handles[i]);
            if (t)
                result = t->apply(arg);
            if (result < 0)
                break;
        }
    }
    return result;
}


