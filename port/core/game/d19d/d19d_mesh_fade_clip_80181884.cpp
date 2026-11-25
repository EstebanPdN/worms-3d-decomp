#include "w3d_ptr.h"
#line 1 "d19d_mesh_fade_clip_80181884.cpp"
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
    Ptr32<const char> name;
    float length;              /* +0x04 */
    unsigned char unknown_08[0x50 - 0x08];
    unsigned char users;       /* +0x50 */
} W3dClipEntry;
typedef struct W3dClipSet W3dClipSet;
typedef struct W3dClipSetVtbl {
    W3D_VTBL_HEAD(W3dClipSet);
    Ptr32<void> slot_14[4];
    Ptr32<Ptr32<W3dClipEntry> (Ptr32<W3dClipSet>, unsigned int)> get_entry;
} W3dClipSetVtbl;
struct W3dClipSet { Ptr32<W3dClipSetVtbl> vt; };

typedef struct W3dBlender W3dBlender;
typedef struct W3dBlenderVtbl {
    W3D_VTBL_HEAD(W3dBlender);
    Ptr32<void> slot_14[11];
    Ptr32<void (Ptr32<W3dBlender>, unsigned int, float)> set_target;
    Ptr32<void (Ptr32<W3dBlender>, unsigned int, float, float)> set_fade;
} W3dBlenderVtbl;
struct W3dBlender { Ptr32<W3dBlenderVtbl> vt; };

typedef struct W3dMeshInstance W3dMeshInstance;

/* Scene registry reached through a global; +0x78 adds an instance. */
typedef struct W3dSceneList W3dSceneList;
typedef struct W3dSceneListVtbl {
    Ptr32<void> slot_00[30];
    Ptr32<int (Ptr32<W3dSceneList>, Ptr32<W3dMeshInstance>)> add;
} W3dSceneListVtbl;
struct W3dSceneList { Ptr32<W3dSceneListVtbl> vt; };

struct W3dMeshInstance {
    Ptr32<void> vt;
    unsigned char unknown_04[0x68 - 0x04];
    W3dPtrVector children;     /* +0x68 */
    unsigned char unknown_70[0xb4 - 0x70];
    union {
        unsigned int flags;    /* +0xb4 */
        struct {
            unsigned int bits_03:29; unsigned int registered:1; unsigned int bits_00:2;
        } bits;
    } state;
    Ptr32<void> ref_b8;
    Ptr32<W3dClipSet> clips;         /* +0xbc */
    Ptr32<W3dBlender> blender;       /* +0xc0 */
};

extern Ptr32<W3dSceneList> w3d_scene_list_804ab5fc;
extern float w3d_f32_803a785c[];

void w3d_mesh_instance_update_child_8017a07c(Ptr32<W3dMeshInstance> self, unsigned int index);
int w3d_buffer_manager_poll_state(Ptr32<void> manager);
Ptr32<void> w3d_slots_shared(void);
Ptr32<void> w3d_slots_request_801983cc(Ptr32<void> slots, unsigned int index, Ptr32<W3dClipSet> clips, int a, int b);

int d19d_mesh_fade_clip_80181884(Ptr32<W3dMeshInstance> self, unsigned int index, float time, float weight)
{
    unsigned int i;
    self->blender->vt->set_fade(self->blender, index, time, w3d_f32_803a785c[0]);
    self->blender->vt->set_target(self->blender, index, weight);
    if (weight > w3d_f32_803a785c[0]) {
        Ptr32<W3dClipEntry> entry = self->clips->vt->get_entry(self->clips, index);
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


