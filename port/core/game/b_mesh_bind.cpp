#include "w3d_ptr.h"
#line 1 "b_mesh_bind.cpp"
/* XMeshInstance binding helpers (0x80181e18..0x801825b4): child mesh
 * collection, colour and resource-node access. Same class as
 * b_mesh_instance; names are inferred from behavior.
 */
#include "b_types2.h"

extern "C" {

/* Smart-pointer slot; member access keeps the in-struct alias flag. */
typedef struct W3dRefSlot { Ptr32<W3dObject> p; } W3dRefSlot;

/* Assignment that adds the new reference before dropping the old one. */
static inline void w3d_ref_slot_set(Ptr32<W3dRefSlot> slot, Ptr32<W3dObject> value)
{
    if (value)
        value->vt->add_ref(value);
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

typedef struct W3dNodeState {
    unsigned char unknown_00[4];
    unsigned char flags; char w3d_tag_rest[3];       /* bit 1 cleared on unbind */
} W3dNodeState;

static inline void w3d_node_state_clear_bound(Ptr32<W3dNodeState> state)
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
    Ptr32<W3dObject> resource;       /* +0x30 */
    unsigned char unknown_34[0x54 - 0x34];
    Ptr32<W3dMaterialInfo> material; /* +0x54 */
} W3dResourceSlot;

typedef struct W3dResourceGroup {
    unsigned char unknown_00[0x20];
    Ptr32<W3dResourceSlot> slot;     /* +0x20 */
} W3dResourceGroup;

typedef struct W3dSceneNode {
    unsigned char unknown_00[0x2c];
    Ptr32<W3dResourceGroup> group;   /* +0x2c */
    Ptr32<W3dRenderNode> render;     /* +0x30 */
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
    Ptr32<W3dRefSlot> data;
} W3dRefArray;

typedef struct W3dOwnerInfo {
    unsigned char unknown_00[0x24];
    unsigned short flags;      /* +0x24, bit 3 = shareable */
    unsigned char unknown_26[0x28 - 0x26];
    int value_28;
} W3dOwnerInfo;

typedef struct W3dNamedVtbl2 {
    Ptr32<void> slot_00[17];
    Ptr32<Ptr32<W3dString> (Ptr32<void>)> get_name;
} W3dNamedVtbl2;
typedef struct W3dNamed2 { Ptr32<W3dNamedVtbl2> vt; } W3dNamed2;

typedef struct W3dBindInstance W3dBindInstance;
typedef struct W3dBindInstanceVtbl {
    Ptr32<void> slot_00[16];
    Ptr32<Ptr32<void> (Ptr32<W3dBindInstance>)> get_owner;
} W3dBindInstanceVtbl;

struct W3dBindInstance {
    Ptr32<W3dBindInstanceVtbl> vt;
    unsigned char unknown_04[0x74 - 0x04];
    Ptr32<void> owner;               /* +0x74 */
    Ptr32<W3dSceneNode> node;        /* +0x78 */
    unsigned char unknown_7c[0xa4 - 0x7c];
    int bound;                 /* +0xa4 */
    W3dRefArray children;      /* +0xa8 */
    unsigned char unknown_b4[0xb8 - 0xb4];
    Ptr32<W3dTint> tint;             /* +0xb8 */
};

/* Mesh source passed to the collection callback. */
typedef struct W3dMeshSource {
    unsigned char unknown_00[0x24];
    Ptr32<const char> name;          /* +0x24 */
    unsigned char unknown_28[0x30 - 0x28];
    Ptr32<W3dObject> object;         /* +0x30 */
} W3dMeshSource;

/* Factory object: +0x18 runs a visit, +0x2c returns the visitor. */
typedef struct W3dVisitor W3dVisitor;
typedef struct W3dVisitorVtbl {
    W3D_VTBL_HEAD(W3dVisitor);
    Ptr32<void> slot_14;
    Ptr32<void (Ptr32<W3dVisitor>, Ptr32<void>, Ptr32<void>, int)> visit;
} W3dVisitorVtbl;
struct W3dVisitor { Ptr32<W3dVisitorVtbl> vt; };

/* Walker that owns the visitor: +0x18 walks a root, +0x2c returns it. */
typedef struct W3dWalker W3dWalker;
typedef struct W3dWalkerVtbl {
    W3D_VTBL_HEAD(W3dWalker);
    Ptr32<void> slot_14;
    Ptr32<void (Ptr32<W3dWalker>, Ptr32<void>)> walk;
    Ptr32<void> slot_1c[4];
    Ptr32<Ptr32<W3dVisitor> (Ptr32<W3dWalker>)> get_visitor;
} W3dWalkerVtbl;
struct W3dWalker { Ptr32<W3dWalkerVtbl> vt; };

/* Reference holders; the original reserves 8-byte, 8-aligned slots. */
struct W3dWalkerRef {
    Ptr32<W3dWalker> p;
    int unknown_04;
    W3dWalkerRef(Ptr32<W3dWalker> w3d_p) : W3dWalkerRef((W3dWalker *)w3d_p.get()) {}
 W3dWalkerRef(W3dWalker *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~W3dWalkerRef() { if (p) p->vt->release(p); }
};

struct W3dVisitorRef {
    Ptr32<W3dVisitor> p;
    int unknown_04;
    W3dVisitorRef(Ptr32<W3dVisitor> w3d_p) : W3dVisitorRef((W3dVisitor *)w3d_p.get()) {}
 W3dVisitorRef(W3dVisitor *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~W3dVisitorRef() { if (p) p->vt->release(p); }
};

extern W3dClassInfo w3d_class_80363834;
extern unsigned char w3d_class_80417000[];
extern unsigned char w3d_class_803627a4[];
extern const char w3d_str_803a7890[];
extern Ptr32<W3dBindInstance> w3d_mesh_collect_target_804b01d0;

Ptr32<void> w3d_empty_80341348(Ptr32<void> object);
int strncmp(Ptr32<const char> a, Ptr32<const char> b, unsigned int n);
int w3d_mesh_source_visit_801a381c(Ptr32<void> context, Ptr32<W3dMeshSource> source);
Ptr32<W3dWalker> w3d_create_object_8020b680(Ptr32<void> klass);
void w3d_ref_array_reserve_801f29d0(Ptr32<W3dRefArray> array, int count);
void w3d_resource_set_801ef174(Ptr32<W3dObject> resource, int key, int a, Ptr32<void> value);
void w3d_resource_set_801ef380(Ptr32<W3dObject> resource, int key, int a, int b, int value);

/* Returns the render node; callers probably ignore it. */
Ptr32<W3dRenderNode> w3d_mesh_instance_unbind(Ptr32<W3dBindInstance> self)
{
    Ptr32<W3dRenderNode> render;
    self->bound = 0;
    render = self->node->render;
    w3d_node_state_clear_bound(&render->state);
    return render;
}

int w3d_mesh_instance_owner_value(Ptr32<W3dBindInstance> self)
{
    return ((Ptr32<W3dOwnerInfo>)w3d_empty_80341348(self->owner))->value_28;
}

int w3d_mesh_instance_set_tint(Ptr32<W3dBindInstance> self, Ptr32<W3dColor4> color)
{
    self->tint->color = *color;
    return 0;
}

void w3d_mesh_instance_add_child(Ptr32<W3dBindInstance> self, Ptr32<W3dObject> child);

/* The prefix ("$") is evaluated before the text, as in the original. */
static inline int w3d_text_has_prefix(Ptr32<const char> prefix, Ptr32<const char> text)
{
    return strncmp(text, prefix, 1) == 0;
}

void w3d_mesh_collect_visit(Ptr32<void> context, Ptr32<W3dMeshSource> source)
{
    Ptr32<W3dObject> object = source->object;
    Ptr32<W3dObject> mesh = object && W3D_OBJECT_IS_A(object, w3d_class_80363834) ? w3d::R(object) : 0;
    if (mesh && !w3d_text_has_prefix(w3d_str_803a7890, source->name))
        w3d_mesh_instance_add_child(w3d_mesh_collect_target_804b01d0, (Ptr32<W3dObject>)source);
    w3d_mesh_source_visit_801a381c(context, source);
}

void w3d_mesh_instance_collect(Ptr32<W3dBindInstance> self, Ptr32<void> root)
{
    W3dWalkerRef walker(w3d_create_object_8020b680(w3d_class_80417000));
    W3dVisitorRef visitor(walker.p->vt->get_visitor(walker.p));
    visitor.p->vt->visit(visitor.p, w3d_class_803627a4, (Ptr32<void>)w3d_mesh_collect_visit, 0);
    w3d_mesh_collect_target_804b01d0 = self;
    walker.p->vt->walk(walker.p, root);
}

void w3d_mesh_instance_add_child(Ptr32<W3dBindInstance> self, Ptr32<W3dObject> child)
{
    Ptr32<W3dRefArray> children = &self->children;
    w3d_ref_array_reserve_801f29d0(children, self->children.count + 1);
    w3d_ref_slot_set(&children->data[self->children.count], child);
    self->children.count++;
}

int w3d_fn_80182408(void)
{
    return 0;
}

int w3d_mesh_instance_set_resource_value(Ptr32<W3dBindInstance> self, int value)
{
    w3d_resource_set_801ef174(self->node->group->slot->resource, 0x54, 0, (Ptr32<void>)w3d::G(value));
    return 0;
}

int w3d_mesh_instance_reset_resource_value(Ptr32<W3dBindInstance> self)
{
    Ptr32<W3dObject> resource = self->node->group->slot->resource;
    w3d_resource_set_801ef380(resource, 0x54, 0, 0, ((Ptr32<W3dResourceSlot>)resource)->material->value_18);
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


