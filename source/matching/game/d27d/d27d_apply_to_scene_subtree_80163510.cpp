// GWMP8P rev0 0x80163510. Apply an argument to a scene node's target and
// optionally to the targets of its direct children, using the node table of
// the global scene. Node handles carry a 12-bit table index. Before
// applying, the target's type chain selects engine-context mode 8, 6 or 7.
// Returns the apply result, or E_FAIL for an invalid handle. Same shape as
// the admitted 0x8034ab10; class, field and slot names are inferred; virtual
// slots are reference-ABI observations.
struct TypeDesc {
    char pad_00[20];
    TypeDesc *parent;
    inline bool is_a(TypeDesc *target)
    {
        TypeDesc *t = this;
        while (t != target) {
            if (t == t->parent)
                return false;
            t = t->parent;
        }
        return true;
    }
};
struct Target {
    virtual int query_interface();
    virtual void retain();
    virtual void release();
    virtual TypeDesc *type();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_32();
    virtual int apply(void *arg);
};
// Observed 36-byte node record.
struct Node {
    char pad_00[6];
    unsigned short first_child;
    char pad_08[2];
    unsigned short next_sibling;
    Target *target;
    char pad_10[4];
    unsigned handle;
    char pad_18[12];
};
struct NodeTable { Node *nodes; };
struct EngineContext { char pad_00[60]; int mode; };
extern "C" EngineContext *w3d_engine_get_context(void);
extern "C" Target *w3d_actor_from_handle(NodeTable *tree, unsigned handle);
extern TypeDesc type_803618f0[];
extern TypeDesc type_80361860[];
extern TypeDesc type_803617d0[];

inline void set_context_mode(int mode)
{
    w3d_engine_get_context()->mode = mode;
}

struct Scene { char pad_00[28]; NodeTable *tree; };
extern Scene *scene_804b178c;
extern "C" int d27d_apply_to_scene_subtree_80163510(void *arg, unsigned handle, int recurse)
{
    NodeTable *tree = scene_804b178c->tree;
    Node *node;
    if (handle == 0xffffffff) {
        node = 0;
    } else {
        Node *candidate = &tree->nodes[handle & 0xfff];
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
            Node *child = &tree->nodes[index];
            handles[count++] = child->handle;
            index = child->next_sibling;
        }
        for (int i = 0; i < count; i++) {
            Target *t = w3d_actor_from_handle(tree, handles[i]);
            if (t)
                result = t->apply(arg);
            if (result < 0)
                break;
        }
    }
    return result;
}
