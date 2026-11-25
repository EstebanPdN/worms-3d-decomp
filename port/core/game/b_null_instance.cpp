#include "w3d_ptr.h"
#line 1 "b_null_instance.cpp"
/* XNullInstance methods (0x801831d4..0x801832b8). Same shapes as the
 * XMeshInstance helpers in b_mesh_animation/b_mesh_bind. Names inferred.
 */
#include "b_types2.h"

extern "C" {

typedef struct W3dNodeState {
    unsigned char unknown_00[4];
    unsigned char flags; char w3d_tag_rest[3];           /* bit 1 cleared on unbind */
} W3dNodeState;

static inline void w3d_node_state_clear_bound(Ptr32<W3dNodeState> state)
{
    state->flags &= ~2;
}

typedef struct W3dRenderNode {
    unsigned char unknown_00[4];
    W3dNodeState state;            /* +0x04 */
} W3dRenderNode;

typedef struct W3dSceneNode {
    unsigned char unknown_00[0x30];
    Ptr32<W3dRenderNode> render;         /* +0x30 */
} W3dSceneNode;

typedef struct W3dNullInstance W3dNullInstance;

typedef struct W3dInstanceOwner W3dInstanceOwner;
typedef struct W3dInstanceOwnerVtbl {
    Ptr32<void> slot_00[15];
    Ptr32<void (Ptr32<W3dInstanceOwner>, Ptr32<W3dNullInstance>)> detach;
    Ptr32<void> slot_40[2];
    Ptr32<Ptr32<unsigned char> (Ptr32<W3dInstanceOwner>)> get_flags;
} W3dInstanceOwnerVtbl;
struct W3dInstanceOwner { Ptr32<W3dInstanceOwnerVtbl> vt; };

typedef struct W3dSceneList W3dSceneList;
typedef struct W3dSceneListVtbl {
    Ptr32<void> slot_00[31];
    Ptr32<void (Ptr32<W3dSceneList>, Ptr32<W3dNullInstance>)> remove;
} W3dSceneListVtbl;
struct W3dSceneList { Ptr32<W3dSceneListVtbl> vt; };

struct W3dNullInstance {
    Ptr32<void> vtable;
    unsigned char unknown_04[0x74 - 0x04];
    Ptr32<W3dInstanceOwner> owner;       /* +0x74 */
    Ptr32<W3dSceneNode> node;            /* +0x78 */
    unsigned char unknown_7c[0xa8 - 0x7c];
    int bound;                     /* +0xa8 */
    int registered;                /* +0xac */
};

extern Ptr32<W3dSceneList> w3d_scene_list_804ab5fc;
extern int w3d_null_active_count_804ab650;

int w3d_instance_finish_8017b348(Ptr32<W3dNullInstance> self);

int w3d_null_instance_not_implemented(void)
{
    return (int)0x80004001;
}

unsigned char w3d_null_instance_owner_flags(Ptr32<W3dNullInstance> self)
{
    return *self->owner->vt->get_flags(self->owner);
}

int w3d_null_instance_shutdown(Ptr32<W3dNullInstance> self)
{
    int result;
    if (self->registered)
        w3d_scene_list_804ab5fc->vt->remove(w3d_scene_list_804ab5fc, self);
    result = w3d_instance_finish_8017b348(self);
    self->owner->vt->detach(self->owner, self);
    w3d_null_active_count_804ab650--;
    return result;
}

/* Returns the render node; callers probably ignore it. */
Ptr32<W3dRenderNode> w3d_null_instance_unbind(Ptr32<W3dNullInstance> self)
{
    Ptr32<W3dRenderNode> render;
    self->bound = 0;
    render = self->node->render;
    w3d_node_state_clear_bound(&render->state);
    return render;
}

}


