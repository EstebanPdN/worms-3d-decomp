/* d19d: 0x80181884 (368 bytes). XMeshInstance fade of one animation clip,
 * the routine kept under '#if 0' in the frozen b_mesh_animation.cpp: set
 * the blender fade (time, 0) and target weight of clip `index`; when the
 * weight is positive make sure the clip's buffer is resident (request it
 * through the shared slot manager unless its state is 2) and count one more
 * user, otherwise count one user less; register the instance with the scene
 * list when not yet registered, then refresh every child. The "unexplained
 * 8-byte stack slot per float kept across calls" was SN paired-single mode:
 * built with -mps-float (one reserved 8-byte slot per saved FPR).
 * Layouts follow b_mesh_animation.cpp; only the fields used here are named.
 */
#include "../b_types2.h"

extern "C" {

typedef struct W3dClipEntry {
    const char *name;
    float length;              /* +0x04 */
    unsigned char unknown_08[0x50 - 0x08];
    unsigned char users;       /* +0x50 */
} W3dClipEntry;
typedef struct W3dClipSet W3dClipSet;
typedef struct W3dClipSetVtbl {
    W3D_VTBL_HEAD(W3dClipSet);
    void *slot_14[4];
    W3dClipEntry *(*get_entry)(W3dClipSet *self, unsigned int index);
} W3dClipSetVtbl;
struct W3dClipSet { W3dClipSetVtbl *vt; };

typedef struct W3dBlender W3dBlender;
typedef struct W3dBlenderVtbl {
    W3D_VTBL_HEAD(W3dBlender);
    void *slot_14[11];
    void (*set_target)(W3dBlender *self, unsigned int index, float weight);
    void (*set_fade)(W3dBlender *self, unsigned int index, float time, float zero);
} W3dBlenderVtbl;
struct W3dBlender { W3dBlenderVtbl *vt; };

typedef struct W3dMeshInstance W3dMeshInstance;

/* Scene registry reached through a global; +0x78 adds an instance. */
typedef struct W3dSceneList W3dSceneList;
typedef struct W3dSceneListVtbl {
    void *slot_00[30];
    int (*add)(W3dSceneList *self, W3dMeshInstance *instance);
} W3dSceneListVtbl;
struct W3dSceneList { W3dSceneListVtbl *vt; };

struct W3dMeshInstance {
    void *vt;
    unsigned char unknown_04[0x68 - 0x04];
    W3dPtrVector children;     /* +0x68 */
    unsigned char unknown_70[0xb4 - 0x70];
    union {
        unsigned int flags;    /* +0xb4 */
        struct {
            unsigned int bits_00 : 2;
            unsigned int registered : 1;
            unsigned int bits_03 : 29;
        } bits;
    } state;
    void *ref_b8;
    W3dClipSet *clips;         /* +0xbc */
    W3dBlender *blender;       /* +0xc0 */
};

extern W3dSceneList *w3d_scene_list_804ab5fc;
extern float w3d_f32_803a785c[];

void w3d_mesh_instance_update_child_8017a07c(W3dMeshInstance *self, unsigned int index);
int w3d_buffer_manager_poll_state(void *manager);
void *w3d_slots_shared(void);
void * w3d_slots_request_801983cc(void *slots, unsigned int index, W3dClipSet *clips, int a, int b);

int d19d_mesh_fade_clip_80181884(W3dMeshInstance *self, unsigned int index, float time, float weight)
{
    unsigned int i;
    self->blender->vt->set_fade(self->blender, index, time, w3d_f32_803a785c[0]);
    self->blender->vt->set_target(self->blender, index, weight);
    if (weight > w3d_f32_803a785c[0]) {
        W3dClipEntry *entry = self->clips->vt->get_entry(self->clips, index);
        if (w3d_buffer_manager_poll_state(&entry->unknown_08) != 2)
            w3d_slots_request_801983cc(w3d_slots_shared(), index, self->clips, 1, 0);
        entry->users++;
    } else {
        self->clips->vt->get_entry(self->clips, index)->users--;
    }
    if (!(self->state.flags & 0x20000000)) {
        w3d_scene_list_804ab5fc->vt->add(w3d_scene_list_804ab5fc, self);
        self->state.bits.registered = 1;
    }
    i = 0;
    for (; i < w3d_ptr_vector_size(&self->children); i++)
        w3d_mesh_instance_update_child_8017a07c(self, i);
    return 0;
}

}
