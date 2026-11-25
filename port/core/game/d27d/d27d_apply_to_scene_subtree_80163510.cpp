#include "w3d_ptr.h"
#line 1 "d27d_apply_to_scene_subtree_80163510.cpp"
// GWMP8P rev0 0x80163510. Apply an argument to a scene node's target and
// optionally to the targets of its direct children, using the node table of
// the global scene. Node handles carry a 12-bit table index. Before
// applying, the target's type chain selects engine-context mode 8, 6 or 7.
// Returns the apply result, or E_FAIL for an invalid handle. Same shape as
// the admitted 0x8034ab10; class, field and slot names are inferred; virtual
// slots are reference-ABI observations.
struct TypeDesc {
    char pad_00[20];
    Ptr32<TypeDesc> parent;
    inline bool is_a(Ptr32<TypeDesc> target)
    {
        Ptr32<TypeDesc> t = this;
        while (t != target) {
            if (t == t->parent)
                return false;
            t = t->parent;
        }
        return true;
    }
};
struct Target {
    int w3d_r_query_interface() __asm__(W3D_SYM("_ZN6Target15query_interfaceEv"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN6Target6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN6Target7releaseEv"));
    Ptr32<TypeDesc> w3d_r_type() __asm__(W3D_SYM("_ZN6Target4typeEv"));
    void w3d_r_slot_24() __asm__(W3D_SYM("_ZN6Target7slot_24Ev"));
    void w3d_r_slot_28() __asm__(W3D_SYM("_ZN6Target7slot_28Ev"));
    void w3d_r_slot_32() __asm__(W3D_SYM("_ZN6Target7slot_32Ev"));
    int w3d_r_apply(Ptr32<void> arg) __asm__(W3D_SYM("_ZN6Target5applyEPv"));
 __attribute__((always_inline)) inline int query_interface() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<TypeDesc> type() { return ((Ptr32<TypeDesc> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Target, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int apply(Ptr32<void> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Target, 9))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Target; };
// Observed 36-byte node record.
struct Node {
    char pad_00[6];
    unsigned short first_child;
    char pad_08[2];
    unsigned short next_sibling;
    Ptr32<Target> target;
    char pad_10[4];
    unsigned handle;
    char pad_18[12];
};
struct NodeTable { Ptr32<Node> nodes; };
struct EngineContext { char pad_00[60]; int mode; };
extern "C" Ptr32<EngineContext> w3d_engine_get_context(void);
extern "C" Ptr32<Target> w3d_actor_from_handle(Ptr32<NodeTable> tree, unsigned handle);
extern TypeDesc type_803618f0[];
extern TypeDesc type_80361860[];
extern TypeDesc type_803617d0[];

inline void set_context_mode(int mode)
{
    w3d_engine_get_context()->mode = mode;
}

struct Scene { char pad_00[28]; Ptr32<NodeTable> tree; };
extern Ptr32<Scene> scene_804b178c;
extern "C" int d27d_apply_to_scene_subtree_80163510(Ptr32<void> arg, unsigned handle, int recurse)
{
    Ptr32<NodeTable> tree = scene_804b178c->tree;
    Ptr32<Node> node;
    if (handle == 0xffffffff) {
        node = 0;
    } else {
        Ptr32<Node> candidate = &tree->nodes[handle & 0xfff];
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
            Ptr32<Node> child = &tree->nodes[index];
            handles[count++] = child->handle;
            index = child->next_sibling;
        }
        for (int i = 0; i < count; i++) {
            Ptr32<Target> t = w3d_actor_from_handle(tree, handles[i]);
            if (t)
                result = t->apply(arg);
            if (result < 0)
                break;
        }
    }
    return result;
}


