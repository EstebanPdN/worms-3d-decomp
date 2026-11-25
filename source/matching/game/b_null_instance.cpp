/* XNullInstance methods (0x801831d4..0x801832b8). Same shapes as the
 * XMeshInstance helpers in b_mesh_animation/b_mesh_bind. Names inferred.
 */
#include "b_types2.h"

extern "C" {

typedef struct W3dNodeState {
    unsigned char unknown_00[7];
    unsigned char flags;           /* bit 1 cleared on unbind */
} W3dNodeState;

static inline void w3d_node_state_clear_bound(W3dNodeState *state)
{
    state->flags &= ~2;
}

typedef struct W3dRenderNode {
    unsigned char unknown_00[4];
    W3dNodeState state;            /* +0x04 */
} W3dRenderNode;

typedef struct W3dSceneNode {
    unsigned char unknown_00[0x30];
    W3dRenderNode *render;         /* +0x30 */
} W3dSceneNode;

typedef struct W3dNullInstance W3dNullInstance;

typedef struct W3dInstanceOwner W3dInstanceOwner;
typedef struct W3dInstanceOwnerVtbl {
    void *slot_00[15];
    void (*detach)(W3dInstanceOwner *self, W3dNullInstance *instance);
    void *slot_40[2];
    unsigned char *(*get_flags)(W3dInstanceOwner *self);
} W3dInstanceOwnerVtbl;
struct W3dInstanceOwner { W3dInstanceOwnerVtbl *vt; };

typedef struct W3dSceneList W3dSceneList;
typedef struct W3dSceneListVtbl {
    void *slot_00[31];
    void (*remove)(W3dSceneList *self, W3dNullInstance *instance);
} W3dSceneListVtbl;
struct W3dSceneList { W3dSceneListVtbl *vt; };

struct W3dNullInstance {
    void *vtable;
    unsigned char unknown_04[0x74 - 0x04];
    W3dInstanceOwner *owner;       /* +0x74 */
    W3dSceneNode *node;            /* +0x78 */
    unsigned char unknown_7c[0xa8 - 0x7c];
    int bound;                     /* +0xa8 */
    int registered;                /* +0xac */
};

extern W3dSceneList *w3d_scene_list_804ab5fc;
extern int w3d_null_active_count_804ab650;

int w3d_instance_finish_8017b348(W3dNullInstance *self);

int w3d_null_instance_not_implemented(void)
{
    return (int)0x80004001;
}

unsigned char w3d_null_instance_owner_flags(W3dNullInstance *self)
{
    return *self->owner->vt->get_flags(self->owner);
}

int w3d_null_instance_shutdown(W3dNullInstance *self)
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
W3dRenderNode *w3d_null_instance_unbind(W3dNullInstance *self)
{
    W3dRenderNode *render;
    self->bound = 0;
    render = self->node->render;
    w3d_node_state_clear_bound(&render->state);
    return render;
}

}
