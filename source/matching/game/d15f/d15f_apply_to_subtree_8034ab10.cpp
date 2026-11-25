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
    D15fTypeDesc *parent;
    inline bool is_a(D15fTypeDesc *target)
    {
        D15fTypeDesc *t = this;
        while (t != target) {
            if (t == t->parent)
                return false;
            t = t->parent;
        }
        return true;
    }
};
struct D15fTarget {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual D15fTypeDesc *type();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_32();
    virtual int apply(void *arg);
};
// Observed 36-byte node record.
struct D15fNode {
    char pad_00[6];
    unsigned short first_child;
    char pad_08[2];
    unsigned short next_sibling;
    D15fTarget *target;
    char pad_10[4];
    unsigned handle;
    char pad_18[12];
};
struct D15fNodeTable { D15fNode *nodes; };
struct D15fEngineContext { char pad_00[60]; int mode; };
extern "C" D15fEngineContext *w3d_engine_get_context(void);
extern "C" D15fTarget *w3d_actor_from_handle(D15fNodeTable *tree, unsigned handle);
extern D15fTypeDesc type_803618f0[];
extern D15fTypeDesc type_80361860[];
extern D15fTypeDesc type_803617d0[];

inline void set_context_mode(int mode)
{
    w3d_engine_get_context()->mode = mode;
}

extern "C" int d15f_apply_to_subtree_8034ab10(D15fNodeTable *tree, void *arg, unsigned handle, int recurse)
{
    D15fNode *node;
    if (handle == 0xffffffff) {
        node = 0;
    } else {
        D15fNode *candidate = &tree->nodes[handle & 0xfff];
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
            D15fNode *child = &tree->nodes[index];
            handles[count++] = child->handle;
            index = child->next_sibling;
        }
        for (int i = 0; i < count; i++) {
            D15fTarget *t = w3d_actor_from_handle(tree, handles[i]);
            if (t)
                result = t->apply(arg);
            if (result < 0)
                break;
        }
    }
    return result;
}
