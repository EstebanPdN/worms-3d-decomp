/* XMeshInstance binding helpers (0x80181e18..0x801825b4): child mesh
 * collection, colour and resource-node access. Same class as
 * b_mesh_instance; names are inferred from behavior.
 */
#include "b_types2.h"

extern "C" {

/* Smart-pointer slot; member access keeps the in-struct alias flag. */
typedef struct W3dRefSlot { W3dObject *p; } W3dRefSlot;

/* Assignment that adds the new reference before dropping the old one. */
static inline void w3d_ref_slot_set(W3dRefSlot *slot, W3dObject *value)
{
    if (value)
        value->vt->add_ref(value);
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

typedef struct W3dNodeState {
    unsigned char unknown_00[7];
    unsigned char flags;       /* bit 1 cleared on unbind */
} W3dNodeState;

static inline void w3d_node_state_clear_bound(W3dNodeState *state)
{
    state->flags &= ~2;
}



typedef struct W3dRenderNode {
    unsigned char unknown_00[4];
    W3dNodeState state;        /* +0x04 */
} W3dRenderNode;

typedef struct W3dMaterialInfo {
    unsigned char unknown_00[0x18];
    int value_18;
} W3dMaterialInfo;

typedef struct W3dResourceSlot {
    unsigned char unknown_00[0x30];
    W3dObject *resource;       /* +0x30 */
    unsigned char unknown_34[0x54 - 0x34];
    W3dMaterialInfo *material; /* +0x54 */
} W3dResourceSlot;

typedef struct W3dResourceGroup {
    unsigned char unknown_00[0x20];
    W3dResourceSlot *slot;     /* +0x20 */
} W3dResourceGroup;

typedef struct W3dSceneNode {
    unsigned char unknown_00[0x2c];
    W3dResourceGroup *group;   /* +0x2c */
    W3dRenderNode *render;     /* +0x30 */
} W3dSceneNode;

typedef struct W3dColor4 {
    unsigned int word[4];
} W3dColor4;

typedef struct W3dTint {
    unsigned char unknown_00[0x14];
    W3dColor4 color;           /* +0x14 */
} W3dTint;

typedef struct W3dRefArray {
    int count;
    int unknown_04;
    W3dRefSlot *data;
} W3dRefArray;

typedef struct W3dOwnerInfo {
    unsigned char unknown_00[0x24];
    unsigned short flags;      /* +0x24, bit 3 = shareable */
    unsigned char unknown_26[0x28 - 0x26];
    int value_28;
} W3dOwnerInfo;

typedef struct W3dNamedVtbl2 {
    void *slot_00[17];
    W3dString *(*get_name)(void *self);
} W3dNamedVtbl2;
typedef struct W3dNamed2 { W3dNamedVtbl2 *vt; } W3dNamed2;

typedef struct W3dBindInstance W3dBindInstance;
typedef struct W3dBindInstanceVtbl {
    void *slot_00[16];
    void *(*get_owner)(W3dBindInstance *self);
} W3dBindInstanceVtbl;

struct W3dBindInstance {
    W3dBindInstanceVtbl *vt;
    unsigned char unknown_04[0x74 - 0x04];
    void *owner;               /* +0x74 */
    W3dSceneNode *node;        /* +0x78 */
    unsigned char unknown_7c[0xa4 - 0x7c];
    int bound;                 /* +0xa4 */
    W3dRefArray children;      /* +0xa8 */
    unsigned char unknown_b4[0xb8 - 0xb4];
    W3dTint *tint;             /* +0xb8 */
};

/* Mesh source passed to the collection callback. */
typedef struct W3dMeshSource {
    unsigned char unknown_00[0x24];
    const char *name;          /* +0x24 */
    unsigned char unknown_28[0x30 - 0x28];
    W3dObject *object;         /* +0x30 */
} W3dMeshSource;

/* Factory object: +0x18 runs a visit, +0x2c returns the visitor. */
typedef struct W3dVisitor W3dVisitor;
typedef struct W3dVisitorVtbl {
    W3D_VTBL_HEAD(W3dVisitor);
    void *slot_14;
    void (*visit)(W3dVisitor *self, void *a, void *b, int c);
} W3dVisitorVtbl;
struct W3dVisitor { W3dVisitorVtbl *vt; };

/* Walker that owns the visitor: +0x18 walks a root, +0x2c returns it. */
typedef struct W3dWalker W3dWalker;
typedef struct W3dWalkerVtbl {
    W3D_VTBL_HEAD(W3dWalker);
    void *slot_14;
    void (*walk)(W3dWalker *self, void *root);
    void *slot_1c[4];
    W3dVisitor *(*get_visitor)(W3dWalker *self);
} W3dWalkerVtbl;
struct W3dWalker { W3dWalkerVtbl *vt; };

/* Reference holders; the original reserves 8-byte, 8-aligned slots. */
struct W3dWalkerRef {
    W3dWalker *p;
    int unknown_04;
    W3dWalkerRef(W3dWalker *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~W3dWalkerRef() { if (p) p->vt->release(p); }
};

struct W3dVisitorRef {
    W3dVisitor *p;
    int unknown_04;
    W3dVisitorRef(W3dVisitor *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~W3dVisitorRef() { if (p) p->vt->release(p); }
};

extern W3dClassInfo w3d_class_80363834;
extern unsigned char w3d_class_80417000[];
extern unsigned char w3d_class_803627a4[];
extern const char w3d_str_803a7890[];
extern W3dBindInstance *w3d_mesh_collect_target_804b01d0;

void *w3d_empty_80341348(void *object);
int strncmp(const char *a, const char *b, unsigned int n);
int w3d_mesh_source_visit_801a381c(void *context, W3dMeshSource *source);
W3dWalker *w3d_create_object_8020b680(void *klass);
void w3d_ref_array_reserve_801f29d0(W3dRefArray *array, int count);
void w3d_resource_set_801ef174(W3dObject *resource, int key, int a, void *value);
void w3d_resource_set_801ef380(W3dObject *resource, int key, int a, int b, int value);

/* Returns the render node; callers probably ignore it. */
W3dRenderNode *w3d_mesh_instance_unbind(W3dBindInstance *self)
{
    W3dRenderNode *render;
    self->bound = 0;
    render = self->node->render;
    w3d_node_state_clear_bound(&render->state);
    return render;
}

int w3d_mesh_instance_owner_value(W3dBindInstance *self)
{
    return ((W3dOwnerInfo *)w3d_empty_80341348(self->owner))->value_28;
}

int w3d_mesh_instance_set_tint(W3dBindInstance *self, W3dColor4 *color)
{
    self->tint->color = *color;
    return 0;
}

void w3d_mesh_instance_add_child(W3dBindInstance *self, W3dObject *child);

/* The prefix ("$") is evaluated before the text, as in the original. */
static inline int w3d_text_has_prefix(const char *prefix, const char *text)
{
    return strncmp(text, prefix, 1) == 0;
}

void w3d_mesh_collect_visit(void *context, W3dMeshSource *source)
{
    W3dObject *object = source->object;
    W3dObject *mesh = object && W3D_OBJECT_IS_A(object, w3d_class_80363834) ? object : 0;
    if (mesh && !w3d_text_has_prefix(w3d_str_803a7890, source->name))
        w3d_mesh_instance_add_child(w3d_mesh_collect_target_804b01d0, (W3dObject *)source);
    w3d_mesh_source_visit_801a381c(context, source);
}

void w3d_mesh_instance_collect(W3dBindInstance *self, void *root)
{
    W3dWalkerRef walker(w3d_create_object_8020b680(w3d_class_80417000));
    W3dVisitorRef visitor(walker.p->vt->get_visitor(walker.p));
    visitor.p->vt->visit(visitor.p, w3d_class_803627a4, (void *)w3d_mesh_collect_visit, 0);
    w3d_mesh_collect_target_804b01d0 = self;
    walker.p->vt->walk(walker.p, root);
}

void w3d_mesh_instance_add_child(W3dBindInstance *self, W3dObject *child)
{
    W3dRefArray *children = &self->children;
    w3d_ref_array_reserve_801f29d0(children, self->children.count + 1);
    w3d_ref_slot_set(&children->data[self->children.count], child);
    self->children.count++;
}

int w3d_fn_80182408(void)
{
    return 0;
}

int w3d_mesh_instance_set_resource_value(W3dBindInstance *self, int value)
{
    w3d_resource_set_801ef174(self->node->group->slot->resource, 0x54, 0, (void *)value);
    return 0;
}

int w3d_mesh_instance_reset_resource_value(W3dBindInstance *self)
{
    W3dObject *resource = self->node->group->slot->resource;
    w3d_resource_set_801ef380(resource, 0x54, 0, 0, ((W3dResourceSlot *)resource)->material->value_18);
    return 0;
}

#if 0 /* 0x80182498: original addresses both +0x2c loads through one register holding 44 (li/lwzx); not reproduced. */
int w3d_mesh_instance_share_resource(W3dBindInstance *self, W3dBindInstance *other)
{
    int result;
    if (!(((W3dOwnerInfo *)w3d_empty_80341348(self->vt->get_owner(self)))->flags & 8)) {
        W3dNamed2 *owner = (W3dNamed2 *)w3d_empty_80341348(self->vt->get_owner(self));
        W3dString *name = owner->vt->get_name(owner);
        {
            W3dLocalString copy;
            w3d_local_string_copy(&copy, name);
        }
        result = W3D_E_FAIL;
    } else {
        W3dObject *shared = other->node->group->slot->resource;
        W3dResourceSlot *mine = self->node->group->slot;
        W3dObject *old = mine->resource;
        mine->resource = shared;
        if (shared)
            shared->vt->add_ref(shared);
        if (old)
            old->vt->release(old);
        result = 0;
    }
    return result;
}

#endif

}
