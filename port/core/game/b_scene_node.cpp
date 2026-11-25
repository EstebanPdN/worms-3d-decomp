#include "w3d_ptr.h"
#line 1 "b_scene_node.cpp"
/* XParticleSetInstance tail and the scene-node base class with vtable
 * 0x80412cf0 (0x8018573c..0x80185ba0). The node keeps a 15-bit reference
 * count in the word at +0x08, three 3-float vectors at +0x0c/+0x18/+0x24,
 * a 48-byte transform at +0x38 initialised from a global identity, a child
 * vector at +0x68 and a referenced object at +0x74. Names are inferred.
 */
#include "b_types2.h"

extern "C" {

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

static inline void w3d_vec3_set(Ptr32<W3dVec3> v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void w3d_empty_80343740(Ptr32<W3dVec3> vector);

typedef struct W3dTransform {
    float m[9];
    W3dVec3 origin;            /* has an empty out-of-line constructor */
} W3dTransform;

static inline void w3d_transform_init(Ptr32<W3dTransform> transform)
{
    w3d_empty_80343740(&transform->origin);
}

/* Pointer vector with capacity word. */
typedef struct W3dPtrVector3 {
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
    Ptr32<Ptr32<void>> capacity;
} W3dPtrVector3;

static inline void w3d_ptr_vector3_init(Ptr32<W3dPtrVector3> vector)
{
    vector->begin = vector->end = vector->capacity = 0;
}

typedef struct W3dNode W3dNode;
typedef struct W3dNodeVtbl {
    Ptr32<void> slot_00[7];
    Ptr32<int (Ptr32<W3dNode>)> is_attached;              /* +0x1c */
    Ptr32<void> slot_20[11];
    Ptr32<void (Ptr32<W3dNode>, int, int)> apply_mode; /* +0x4c */
    Ptr32<void> slot_50[4];
    Ptr32<void (Ptr32<W3dNode>, Ptr32<void>)> remove_child;       /* +0x60 */
    Ptr32<int (Ptr32<W3dNode>)> mode_value;                       /* +0x64 */
    Ptr32<void> slot_68[8];
    Ptr32<void (Ptr32<W3dNode>)> destroy;                         /* +0x88 */
} W3dNodeVtbl;

typedef struct W3dNodeParent W3dNodeParent;
typedef struct W3dNodeParentVtbl {
    Ptr32<void> slot_00[24];
    Ptr32<int (Ptr32<W3dNodeParent>, Ptr32<W3dNode>)> remove_child; /* +0x60 */
} W3dNodeParentVtbl;
struct W3dNodeParent { Ptr32<W3dNodeParentVtbl> vt; };

struct W3dNode {
    Ptr32<W3dNodeVtbl> vt;
    unsigned char type;        /* +0x04 */
    unsigned char unknown_05;
    unsigned short slot;       /* +0x06 */
    unsigned int flag:1; unsigned int references:15; unsigned int id:16;
    W3dVec3 position;          /* +0x0c */
    W3dVec3 rotation;          /* +0x18 */
    W3dVec3 scale;             /* +0x24 */
    Ptr32<W3dNodeParent> parent;     /* +0x30 */
    unsigned char mode;        /* +0x34 */
    unsigned char unknown_35[0x38 - 0x35];
    W3dTransform transform;    /* +0x38 */
    W3dPtrVector3 children;    /* +0x68 */
    Ptr32<W3dObject> attachment;     /* +0x74 */
};

/* XParticleSetInstance fields used by its shutdown. */
typedef struct W3dPSetInstance W3dPSetInstance;
typedef struct W3dInstanceOwner W3dInstanceOwner;
typedef struct W3dInstanceOwnerVtbl {
    Ptr32<void> slot_00[15];
    Ptr32<void (Ptr32<W3dInstanceOwner>, Ptr32<W3dPSetInstance>)> detach;
    Ptr32<void> slot_40[2];
    Ptr32<Ptr32<unsigned char> (Ptr32<W3dInstanceOwner>)> get_flags;
} W3dInstanceOwnerVtbl;
struct W3dInstanceOwner { Ptr32<W3dInstanceOwnerVtbl> vt; };

typedef struct W3dRefSlot { Ptr32<W3dObject> p; } W3dRefSlot;

static inline void w3d_ref_slot_assign(Ptr32<W3dRefSlot> slot, Ptr32<W3dObject> value)
{
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

struct W3dPSetInstance {
    Ptr32<void> vtable;
    unsigned char unknown_04[0x74 - 0x04];
    Ptr32<W3dInstanceOwner> owner;   /* +0x74 */
    unsigned char unknown_78[0xa8 - 0x78];
    Ptr32<W3dObject> emitter;        /* +0xa8 */
};

extern unsigned char w3d_node_vtable_80412cf0[];
extern W3dTransform w3d_identity_transform_8045e748;
extern int w3d_pset_active_count_804ab670;
extern const float w3d_f32_803a7a94[];
extern const float w3d_f32_803a7a98[];
extern const float w3d_f32_803a7a9c[];
extern const float w3d_f32_803a7aa0[];

int w3d_instance_finish_8017b348(Ptr32<W3dPSetInstance> self);
void w3d_handle_storage_release(Ptr32<void> storage);
void w3d_actor_member_delete_backend(Ptr32<void> object);

int w3d_fn_8018573c(void)
{
    return 0;
}

unsigned char w3d_pset_instance_owner_flags(Ptr32<W3dPSetInstance> self)
{
    return *self->owner->vt->get_flags(self->owner);
}

int w3d_pset_instance_shutdown(Ptr32<W3dPSetInstance> self)
{
    int result = w3d_instance_finish_8017b348(self);
    self->owner->vt->detach(self->owner, self);
    w3d_pset_active_count_804ab670--;
    w3d_ref_slot_assign((Ptr32<W3dRefSlot>)&self->emitter, 0);
    return result;
}

Ptr32<W3dNode> w3d_node_construct(Ptr32<W3dNode> self)
{
    float zero;
    float one;
    self->vt = (Ptr32<W3dNodeVtbl>)w3d_node_vtable_80412cf0;
    w3d_transform_init(&self->transform);
    w3d_ptr_vector3_init(&self->children);
    self->attachment = 0;
    self->references = 0;
    self->slot = 0xffff;
    self->id = 0xffff;
    zero = w3d_f32_803a7a94[0];
    w3d_vec3_set(&self->position, zero, zero, zero);
    w3d_vec3_set(&self->rotation, zero, zero, zero);
    one = w3d_f32_803a7a98[0];
    w3d_vec3_set(&self->scale, one, one, one);
    self->transform = w3d_identity_transform_8045e748;
    self->mode = 7;
    return self;
}

void w3d_node_destruct(Ptr32<W3dNode> self, int flags)
{
    self->vt = (Ptr32<W3dNodeVtbl>)w3d_node_vtable_80412cf0;
    if (self->attachment)
        self->attachment->vt->release(self->attachment);
    if (self->children.begin)
        w3d_handle_storage_release(self->children.begin);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

unsigned int w3d_node_add_ref(Ptr32<W3dNode> self)
{
    return ++self->references;
}

unsigned int w3d_node_release(Ptr32<W3dNode> self)
{
    unsigned int remaining = --self->references;
    if (remaining == 0)
        self->vt->destroy(self);
    return remaining;
}

int w3d_node_query_interface(Ptr32<W3dNode> self, Ptr32<const void> iid, Ptr32<Ptr32<void>> out)
{
    *out = 0;
    return (int)0x80004002;
}

int w3d_node_reset(Ptr32<W3dNode> self)
{
    int result = 0;
    if (self->vt->is_attached(self) != 0) {
        int status = self->parent->vt->remove_child(self->parent, self);
        if (status < 0)
            result = status;
    }
    while (w3d_ptr_vector_size((Ptr32<W3dPtrVector>)&self->children) != 0)
        self->vt->remove_child(self, *self->children.begin);
    {
        float zero = w3d_f32_803a7a9c[0];
        float one = w3d_f32_803a7aa0[0];
        w3d_vec3_set(&self->position, zero, zero, zero);
        w3d_vec3_set(&self->rotation, zero, zero, zero);
        w3d_vec3_set(&self->scale, one, one, one);
    }
    return result;
}

int w3d_node_set_type(Ptr32<W3dNode> self, Ptr32<void> unused, unsigned char type)
{
    self->type = type;
    return (int)0x80004001;
}

int w3d_node_not_implemented(void)
{
    return (int)0x80004001;
}

int w3d_node_in_use(Ptr32<W3dNode> self)
{
    if (self->references)
        return 1;
    return 0;
}

unsigned short w3d_node_slot(Ptr32<W3dNode> self)
{
    return self->slot;
}

int w3d_node_set_id(Ptr32<W3dNode> self, unsigned short id)
{
    self->id = id;
    return 0;
}

unsigned short w3d_node_id(Ptr32<W3dNode> self)
{
    return self->id;
}

int w3d_node_set_mode(Ptr32<W3dNode> self, unsigned int mode)
{
    if (self->mode != mode) {
        Ptr32<W3dNodeVtbl> vt;
        self->mode = mode;
        vt = self->vt;
        vt->apply_mode(self, vt->mode_value(self), 1);
    }
    return 0;
}

}


