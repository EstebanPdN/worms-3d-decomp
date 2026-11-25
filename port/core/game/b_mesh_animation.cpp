#include "w3d_ptr.h"
#line 1 "b_mesh_animation.cpp"
/* XMeshInstance animation playback: clip lookup, play, fade and update
 * (0x8018136c..). Same source file as b_mesh_instance; split because that
 * unit is frozen. Names are inferred from behavior; no symbols survive.
 * Instance fields: +0x68 child vector, +0x74 owner, +0xb4 state flags
 * (0x20000000 = registered with the scene list), +0xbc clip set,
 * +0xc0 blender, +0xc4 animation controller, +0xc8 current time.
 */
#include "b_types2.h"

extern "C" {

/* Clip set (+0xbc): +0x20 returns a list record with a count at +4,
 * +0x24 returns the entry at an index.
 */
typedef struct W3dClipEntry {
    Ptr32<const char> name;
    float length;              /* +0x04 */
    unsigned char unknown_08[0x50 - 0x08];
    unsigned char users;       /* +0x50 */
} W3dClipEntry;
typedef struct W3dClipList {
    unsigned char unknown_00[4];
    unsigned int count;
} W3dClipList;
typedef struct W3dClipSet W3dClipSet;
typedef struct W3dClipSetVtbl {
    W3D_VTBL_HEAD(W3dClipSet);
    Ptr32<void> slot_14[3];
    Ptr32<Ptr32<W3dClipList> (Ptr32<W3dClipSet>)> get_list;
    Ptr32<Ptr32<W3dClipEntry> (Ptr32<W3dClipSet>, unsigned int)> get_entry;
} W3dClipSetVtbl;
struct W3dClipSet { Ptr32<W3dClipSetVtbl> vt; };

/* Blender (+0xc0). */
typedef struct W3dBlender W3dBlender;
typedef struct W3dBlenderVtbl {
    W3D_VTBL_HEAD(W3dBlender);
    Ptr32<void> slot_14[11];
    Ptr32<void (Ptr32<W3dBlender>, unsigned int, float)> set_target;
    Ptr32<void (Ptr32<W3dBlender>, unsigned int, float, float)> set_fade;
} W3dBlenderVtbl;
struct W3dBlender { Ptr32<W3dBlenderVtbl> vt; };

/* Animation controller (+0xc4). */
typedef struct W3dAnimControl W3dAnimControl;
typedef struct W3dAnimControlVtbl {
    W3D_VTBL_HEAD(W3dAnimControl);
    Ptr32<void> slot_14[2];
    Ptr32<int (Ptr32<W3dAnimControl>, unsigned int, int, int, float, float, float)> play;
    Ptr32<void> slot_20;
    Ptr32<void (Ptr32<W3dAnimControl>)> update;
    Ptr32<void (Ptr32<W3dAnimControl>, float)> set_time;
    Ptr32<int (Ptr32<W3dAnimControl>, Ptr32<float>)> get_progress;
    Ptr32<int (Ptr32<W3dAnimControl>)> is_stopped;
    Ptr32<void (Ptr32<W3dAnimControl>)> slot_34;
    Ptr32<int (Ptr32<W3dAnimControl>)> slot_38;
    Ptr32<void (Ptr32<W3dAnimControl>)> slot_3c;
} W3dAnimControlVtbl;
struct W3dAnimControl { Ptr32<W3dAnimControlVtbl> vt; };

/* Owner reached through the instance vtable (+0x40); +0x44 returns its name. */
typedef struct W3dNamed W3dNamed;
typedef struct W3dNamedVtbl {
    W3D_VTBL_HEAD(W3dNamed);
    Ptr32<void> slot_14[12];
    Ptr32<Ptr32<W3dString> (Ptr32<W3dNamed>)> get_name;
} W3dNamedVtbl;
struct W3dNamed { Ptr32<W3dNamedVtbl> vt; };

typedef struct W3dMeshInstance W3dMeshInstance;
typedef struct W3dMeshInstanceVtbl {
    W3D_VTBL_HEAD(W3dMeshInstance);
    Ptr32<void> slot_14[6];
    Ptr32<void (Ptr32<W3dMeshInstance>, float)> set_rate;
    Ptr32<void> slot_30[4];
    Ptr32<Ptr32<W3dNamed> (Ptr32<W3dMeshInstance>)> get_owner;
} W3dMeshInstanceVtbl;

/* Scene registry reached through a global; +0x78 adds, +0x7c removes. */
typedef struct W3dSceneList W3dSceneList;
typedef struct W3dSceneListVtbl {
    Ptr32<void> slot_00[30];
    Ptr32<int (Ptr32<W3dSceneList>, Ptr32<W3dMeshInstance>)> add;
    Ptr32<void (Ptr32<W3dSceneList>, Ptr32<W3dMeshInstance>)> remove;
} W3dSceneListVtbl;
struct W3dSceneList { Ptr32<W3dSceneListVtbl> vt; };

/* Mesh owner (+0x74): +0x3c detaches an instance, +0x48 returns a byte. */
typedef struct W3dMeshOwner W3dMeshOwner;
typedef struct W3dMeshOwnerVtbl {
    Ptr32<void> slot_00[15];
    Ptr32<void (Ptr32<W3dMeshOwner>, Ptr32<W3dMeshInstance>)> detach;
    Ptr32<void> slot_40[2];
    Ptr32<Ptr32<unsigned char> (Ptr32<W3dMeshOwner>)> get_flags;
} W3dMeshOwnerVtbl;
struct W3dMeshOwner { Ptr32<W3dMeshOwnerVtbl> vt; };

struct W3dMeshInstance {
    Ptr32<W3dMeshInstanceVtbl> vt;
    unsigned char unknown_04[0x68 - 0x04];
    W3dPtrVector children;     /* +0x68 */
    unsigned char unknown_70[0x74 - 0x70];
    Ptr32<W3dMeshOwner> owner;       /* +0x74 */
    unsigned char unknown_78[0xa8 - 0x78];
    unsigned char member_a8[0xb4 - 0xa8];
    union {
        unsigned int flags;    /* +0xb4 */
        struct {
            unsigned int bits_08:24; unsigned int flag_07:1; unsigned int flag_06:1; unsigned int flag_05:1; unsigned int flag_04:1; unsigned int flag_03:1; unsigned int registered:1; unsigned int bits_00:2;
        } bits;
    } state;
    Ptr32<W3dObject> ref_b8;
    Ptr32<W3dClipSet> clips;         /* +0xbc */
    Ptr32<W3dBlender> blender;       /* +0xc0 */
    Ptr32<W3dAnimControl> control;   /* +0xc4 */
    float time;                /* +0xc8 */
};

extern int w3d_mesh_active_count_804ab628;
extern Ptr32<W3dSceneList> w3d_scene_list_804ab5fc;
extern const float w3d_f32_803a7850[];
extern const float w3d_f32_803a7854[];
extern const float w3d_f32_803a7858[];
extern float w3d_f32_803a785c[];
extern float w3d_f32_803a788c[];

void w3d_mesh_instance_update_child_8017a07c(Ptr32<W3dMeshInstance> self, unsigned int index);
int w3d_mesh_instance_stop_801819f4(Ptr32<W3dMeshInstance> self, int mode);
int w3d_mesh_instance_finish_8017b348(Ptr32<W3dMeshInstance> self);
int w3d_text_compare_802ef234(Ptr32<const char> a, Ptr32<const char> b);
int w3d_buffer_manager_poll_state(Ptr32<void> manager);
Ptr32<void> w3d_slots_shared(void);
void w3d_slots_request_801983cc(Ptr32<void> slots, unsigned int index, Ptr32<W3dClipSet> clips, int a, int b);

int w3d_mesh_instance_advance(Ptr32<W3dMeshInstance> self, float delta)
{
    float progress;
    int done;
    unsigned int i = 0;
    self->time += delta;
    self->control->vt->set_time(self->control, self->time);
    self->control->vt->update(self->control);
    for (; i < w3d_ptr_vector_size(&self->children); i++)
        w3d_mesh_instance_update_child_8017a07c(self, i);
    done = self->control->vt->get_progress(self->control, &progress);
    if (progress == w3d_f32_803a7850[0] && done) {
        w3d_scene_list_804ab5fc->vt->remove(w3d_scene_list_804ab5fc, self);
        self->state.bits.registered = 0;
    }
    return 0;
}

unsigned char w3d_mesh_instance_owner_flags(Ptr32<W3dMeshInstance> self)
{
    return *self->owner->vt->get_flags(self->owner);
}

/* Inlined smart-pointer member assignment: release the old object, store. */
typedef struct W3dRefSlot { Ptr32<W3dObject> p; } W3dRefSlot;

static inline void w3d_ref_assign(Ptr32<W3dRefSlot> slot, Ptr32<W3dObject> value)
{
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

int w3d_mesh_instance_shutdown(Ptr32<W3dMeshInstance> self)
{
    int result;
    w3d_mesh_instance_stop_801819f4(self, 0);
    if (self->state.flags & 0x20000000)
        w3d_scene_list_804ab5fc->vt->remove(w3d_scene_list_804ab5fc, self);
    result = w3d_mesh_instance_finish_8017b348(self);
    self->owner->vt->detach(self->owner, self);
    w3d_ref_assign((Ptr32<W3dRefSlot>)&self->blender, 0);
    w3d_ref_assign((Ptr32<W3dRefSlot>)&self->control, 0);
    w3d_ref_assign((Ptr32<W3dRefSlot>)&self->clips, 0);
    w3d_mesh_active_count_804ab628--;
    return result;
}

int w3d_mesh_instance_find_clip(Ptr32<W3dMeshInstance> self, Ptr32<const char> name, Ptr32<unsigned int> index)
{
    unsigned int i = 0;
    unsigned int count = self->clips->vt->get_list(self->clips)->count;
    for (; i < count; i++) {
        if (w3d_text_compare_802ef234(self->clips->vt->get_entry(self->clips, i)->name, name) == 0) {
            *index = i;
            return 0;
        }
    }
    *index = 0;
    return W3D_E_FAIL;
}

#if 0 /* 0x80181640: original reserves an unexplained 8-byte stack slot per float kept across the call. */
int w3d_mesh_instance_play_index(W3dMeshInstance *self, unsigned int index, int *handle, int mode,
                                 float speed, float weight, float blend);

int w3d_mesh_instance_play_named(W3dMeshInstance *self, const char *name, int *handle, int mode,
                                 float speed, float weight, float blend)
{
    unsigned int index;
    int result = w3d_mesh_instance_find_clip(self, name, &index);
    if (result < 0) {
        *handle = -1;
        return result;
    }
    return w3d_mesh_instance_play_index(self, index, handle, mode, speed, weight, blend);
}

#endif

int w3d_mesh_instance_play_index(Ptr32<W3dMeshInstance> self, unsigned int index, Ptr32<int> handle, int mode,
                                 float speed, float weight, float blend)
{
    int result = self->control->vt->play(self->control, index, mode, 0, weight,
                                         w3d_f32_803a7854[0] / speed, blend);
    *handle = result;
    if (result == -1)
        return W3D_E_FAIL;
    if (!(self->state.flags & 0x20000000)) {
        if (w3d_scene_list_804ab5fc->vt->add(w3d_scene_list_804ab5fc, self) < 0)
            return W3D_E_FAIL;
        self->state.bits.registered = 1;
        self->vt->set_rate(self, w3d_f32_803a7858[0]);
    }
    return 0;
}

int w3d_mesh_instance_check_control(Ptr32<W3dMeshInstance> self)
{
    return self->control->vt->slot_38(self->control) ? 0 : W3D_E_FAIL;
}

int w3d_mesh_instance_control_3c(Ptr32<W3dMeshInstance> self)
{
    self->control->vt->slot_3c(self->control);
    return 0;
}

#if 0 /* 0x80181814, 0x80181884: same unexplained 8-byte stack slot per float kept across calls. */
int w3d_mesh_instance_fade_index(W3dMeshInstance *self, unsigned int index, float time, float weight);

int w3d_mesh_instance_fade_named(W3dMeshInstance *self, const char *name, float time, float weight)
{
    unsigned int index;
    if (w3d_mesh_instance_find_clip(self, name, &index) < 0)
        return W3D_E_FAIL;
    return w3d_mesh_instance_fade_index(self, index, time, weight);
}

int w3d_mesh_instance_fade_index(W3dMeshInstance *self, unsigned int index, float time, float weight)
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

#endif

int w3d_mesh_instance_is_playing(Ptr32<W3dMeshInstance> self)
{
    return self->control->vt->is_stopped(self->control) ^ 1;
}

void w3d_mesh_instance_control_34(Ptr32<W3dMeshInstance> self)
{
    self->control->vt->slot_34(self->control);
}

float w3d_mesh_instance_clip_length_index(Ptr32<W3dMeshInstance> self, unsigned int index);

float w3d_mesh_instance_clip_length_named(Ptr32<W3dMeshInstance> self, Ptr32<const char> name)
{
    unsigned int index;
    float length;
    if (w3d_mesh_instance_find_clip(self, name, &index) < 0) {
        Ptr32<W3dNamed> owner = self->vt->get_owner(self);
        Ptr32<W3dString> owner_name = owner->vt->get_name(owner);
        {
            /* Copied and dropped unused; probably a compiled-out report. */
            W3dLocalString copy;
            w3d_local_string_copy(&copy, owner_name);
        }
        length = w3d_f32_803a788c[0];
    } else {
        length = w3d_mesh_instance_clip_length_index(self, index);
    }
    return length;
}

float w3d_mesh_instance_clip_length_index(Ptr32<W3dMeshInstance> self, unsigned int index)
{
    return self->clips->vt->get_entry(self->clips, index)->length;
}


}


