#include "w3d_ptr.h"
#line 1 "b_mesh_instance.cpp"
/* XMesh descriptor and XMeshInstance component code (0x801801b0..).
 *
 * Names are inferred from behavior and the type-name strings the functions
 * return; no original symbols survive. Interface objects are reference
 * counted through vtable slots +0x0c (add) and +0x10 (release).
 */
#include "b_types.h"

extern "C" {

typedef struct W3dMeshDescriptor {
    unsigned char unknown_00[0x28];
    Ptr32<W3dObject> clip_library;   /* +0x28 */
    unsigned char unknown_2c[0x30 - 0x2c];
    Ptr32<W3dObject> animation;      /* +0x30 */
    unsigned char unknown_34[0x70 - 0x34];
    int bound;                 /* +0x70 */
} W3dMeshDescriptor;

typedef struct W3dMeshTargetState {
    unsigned char unknown_00[4];
    unsigned char flags; char w3d_tag_rest[3];       /* bit 0 cleared on reset */
} W3dMeshTargetState;

static inline void w3d_mesh_target_state_clear(Ptr32<W3dMeshTargetState> state)
{
    state->flags &= ~1;
}

typedef struct W3dMeshTarget {
    unsigned char unknown_00[4];
    W3dMeshTargetState state;  /* +0x04 */
    unsigned char unknown_0c[0x48 - 0x0c];
    Ptr32<W3dObject> shared;         /* +0x48 */
} W3dMeshTarget;

typedef struct W3dMeshInstance {
    Ptr32<void> vtable;
    unsigned char unknown_04[0xa8 - 0x04];
    unsigned char member_a8[0xb4 - 0xa8];
    union {
        unsigned int flags;    /* +0xb4 */
        struct {
            unsigned int bits_08:24; unsigned int flag_07:1; unsigned int flag_06:1; unsigned int flag_05:1; unsigned int flag_04:1; unsigned int flag_03:1; unsigned int bits_00:3;
        } bits;
    } state;
    Ptr32<W3dObject> ref_b8;
    Ptr32<W3dObject> ref_bc;
    Ptr32<W3dObject> ref_c0;
    Ptr32<W3dObject> ref_c4;
} W3dMeshInstance;

static inline unsigned int w3d_mesh_instance_flag_06(Ptr32<W3dMeshInstance> instance)
{
    return instance->state.bits.flag_06;
}

static inline unsigned int w3d_mesh_instance_flag_07(Ptr32<W3dMeshInstance> instance)
{
    return instance->state.bits.flag_07;
}

extern const char w3d_str_803a76f0[];
extern const char w3d_str_803a779c[];
extern const char w3d_str_803a7808[];
extern const char w3d_str_803a782c[];
extern const unsigned char w3d_key_8040e0a8[];
extern unsigned char w3d_class_80414160[];
extern unsigned char w3d_mesh_instance_vtable_804129e0[];
extern Ptr32<W3dObject> w3d_mesh_shared_804b01c4;
extern W3dClassInfo w3d_class_80362844;
extern W3dClassInfo w3d_class_80362984;
extern W3dClassInfo w3d_class_80363474;
extern W3dClassInfo w3d_class_80363d34;
extern W3dClassInfo w3d_class_80364694;
extern W3dClassInfo w3d_class_80365274;
extern int w3d_mesh_instance_count_804ab624;

Ptr32<W3dObject> w3d_create_object_8020b680(Ptr32<void> klass);
void w3d_fatal_801fcb64(Ptr32<const char> message, int code);
Ptr32<void> w3d_component_construct_8017990c(Ptr32<void> self);
void w3d_component_destruct_801799d4(Ptr32<void> self, int flags);
void w3d_member_construct_801f2678(Ptr32<void> member);
void w3d_member_destruct_801f2758(Ptr32<void> member, int flags);

int w3d_mesh_descriptor_bind_animation(Ptr32<W3dMeshDescriptor> self)
{
    Ptr32<W3dObject> created;
    int bound = self->bound;
    if (bound == 0) {
        Ptr32<W3dObject> found;
        self->clip_library->vt->get_value_38(self->clip_library, w3d_key_8040e0a8, 0, &found);
        W3dRef held(found);
        if (held.p)
            found->vt->release(found);
        if (self->clip_library)
            self->clip_library->vt->release(self->clip_library);
        self->clip_library = (Ptr32<W3dObject>)w3d::G(bound);
        if (self->animation)
            self->animation->vt->release(self->animation);
        self->animation = (Ptr32<W3dObject>)w3d::G(bound);
        created = w3d_create_object_8020b680(w3d_class_80414160);
        if (created)
            created->vt->add_ref(created);
        if (self->clip_library)
            self->clip_library->vt->release(self->clip_library);
        self->clip_library = created;
        if (held.p) {
            W3dLocalString name;
            w3d_string_from_text(&name.s, w3d_str_803a7808);
            self->clip_library->vt->set_value_20(self->clip_library, w3d_key_8040e0a8, held.p, &name.s);
        }
    }
    return 0;
}

int w3d_fn_801803f0(void)
{
    return 1;
}

Ptr32<const char> w3d_mesh_type_name(void)
{
    return w3d_str_803a76f0;
}

Ptr32<W3dObject> w3d_mesh_descriptor_get_clip(Ptr32<W3dMeshDescriptor> self)
{
    if (self->clip_library == 0)
        w3d_fatal_801fcb64(w3d_str_803a779c, 0);
    W3dRef result;
    self->clip_library->vt->get_value_38(self->clip_library, w3d_key_8040e0a8, 0, &result.p);
    return result.p;
}

int w3d_mesh_filter_accepts(Ptr32<W3dObject> self, int mode, Ptr32<W3dMeshInstance> instance)
{
    if (mode == 1)
        return 1;
    if (instance->state.flags & 0x10000000) {
        if (W3D_OBJECT_IS_A(self, w3d_class_80362844) || W3D_OBJECT_IS_A(self, w3d_class_80362984))
            return 1;
    }
    if (w3d_mesh_instance_flag_07(instance) || w3d_mesh_instance_flag_06(instance)) {
        if (W3D_OBJECT_IS_A(self, w3d_class_80362844) || W3D_OBJECT_IS_A(self, w3d_class_80362984)
            || W3D_OBJECT_IS_A(self, w3d_class_80363474))
            return 1;
    }
    if (instance->state.flags & 0x08000000) {
        if (W3D_OBJECT_IS_A(self, w3d_class_80362844) || W3D_OBJECT_IS_A(self, w3d_class_80364694)
            || W3D_OBJECT_IS_A(self, w3d_class_80365274))
            return 1;
    }
    return W3D_OBJECT_IS_A(self, w3d_class_80363d34);
}

int w3d_mesh_target_reset_shared(Ptr32<void> unused, Ptr32<W3dMeshTarget> target)
{
    Ptr32<W3dObject> shared = w3d_mesh_shared_804b01c4;
    Ptr32<W3dObject> old = target->shared;
    target->shared = shared;
    if (shared)
        shared->vt->add_ref(shared);
    if (old)
        old->vt->release(old);
    w3d_mesh_target_state_clear(&target->state);
    return 0;
}

Ptr32<W3dMeshInstance> w3d_mesh_instance_construct(Ptr32<W3dMeshInstance> self)
{
    w3d_component_construct_8017990c(self);
    self->vtable = w3d_mesh_instance_vtable_804129e0;
    w3d_member_construct_801f2678(self->member_a8);
    self->ref_b8 = 0;
    self->ref_bc = 0;
    self->ref_c0 = 0;
    self->ref_c4 = 0;
    w3d_mesh_instance_count_804ab624++;
    self->state.bits.flag_03 = 0;
    self->state.bits.flag_06 = 0;
    self->state.bits.flag_07 = 0;
    return self;
}

void w3d_mesh_instance_destruct(Ptr32<W3dMeshInstance> self, int flags)
{
    self->vtable = w3d_mesh_instance_vtable_804129e0;
    w3d_mesh_instance_count_804ab624--;
    if (self->ref_c4)
        self->ref_c4->vt->release(self->ref_c4);
    if (self->ref_c0)
        self->ref_c0->vt->release(self->ref_c0);
    if (self->ref_bc)
        self->ref_bc->vt->release(self->ref_bc);
    if (self->ref_b8)
        self->ref_b8->vt->release(self->ref_b8);
    w3d_member_destruct_801f2758(self->member_a8, 2);
    w3d_component_destruct_801799d4(self, flags);
}

int w3d_fn_801809c0(void)
{
    return 1;
}

Ptr32<const char> w3d_mesh_instance_type_name(void)
{
    return w3d_str_803a782c;
}

}


