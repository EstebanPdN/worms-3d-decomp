/* Camera helpers and two logic entities around the ninja camera (0x800c9d98..0x800cdbb4).
 *
 * Names are inferred from behavior; no original symbols survive.
 * Logic entity type 0x80360b70 (68 bytes): +0x20 id (-1 when unset),
 * +0x24/+0x28 held objects, +0x2c deferred task list {count, ?, data},
 * +0x38/+0x3c held objects, +0x40 enabled flag.
 * Several helpers resolve an actor id at +0x1c through 0x80164fc8 and fall
 * back to a default value when the actor is gone.
 */
#include "g_types2.h"

extern "C" {

typedef struct W3dGActor W3dGActor;

typedef struct W3dGTaskList {
    unsigned int count;
    unsigned char unknown_04[4];
    W3dGIface **data;
} W3dGTaskList;

typedef struct W3dGCamera {
    unsigned char unknown_00[0x48];
    void *secondary_vtable;
} W3dGCamera;

typedef struct W3dGTracker {
    unsigned char unknown_00[0x1c];
    int actor;
    int target;
} W3dGTracker;

typedef struct W3dLogic_80360b70 {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x20 - 0x06];
    int id;
    W3dGIface *held_24;
    W3dGIface *held_28;
    W3dGTaskList tasks;
    W3dGIface *held_38;
    W3dGIface *held_3c;
    int enabled;
} W3dLogic_80360b70;

typedef struct W3dLogic_80360ba0 {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
} W3dLogic_80360ba0;

extern W3dLogicType w3d_logic_type_80360b70;
extern W3dLogicType w3d_logic_type_80360ba0;
extern unsigned char w3d_class_804144f8[];
extern unsigned char w3d_vtable_8040fb90[];
extern unsigned char w3d_vtable_8040fbc8[];
extern const char w3d_str_80387d74[];
extern const char w3d_str_80387d7c[];
extern const W3dGVec3 w3d_vec3_zero_8045e788[];
extern const float w3d_f32_80387e24[];

void w3d_camera_attach_80174820(void *target, W3dGIface *object);
void w3d_camera_base_construct_800d2dec(W3dGCamera *camera, int owner, const char *kind, int flags);
void w3d_camera_set_name_800d31d8(W3dGCamera *camera, const char *name);
void w3d_camera_reset_800d308c(void *camera);
void w3d_camera_update_800d5028(void *camera);
void w3d_base_construct_8015fef0(void *object);
void w3d_base_destroy_8015ff2c(void *object, int flags);
void w3d_task_list_init_802109dc(W3dGTaskList *list);
void w3d_task_list_destroy_80210abc(W3dGTaskList *list, int flags);
void w3d_task_deferred_clear(W3dGTaskList *list);
void w3d_logic_clear_800ccd54(W3dLogic_80360b70 *object);
W3dGActor *w3d_actor_lookup_80164fc8(int id);
W3dGPos w3d_actor_position_800d1104(W3dGActor *actor);
float w3d_actor_heading_800d1128(W3dGActor *actor);
int w3d_actor_state_800d1c14(W3dGActor *actor);
void w3d_actor_release_target_80122af8(W3dGActor *actor);

int w3d_camera_attach_default_800c9d98(void *target)
{
    W3dGHeld object(w3d_class_create_8020b680(w3d_class_804144f8));
    w3d_camera_attach_80174820(target, object.object);
    return 0;
}

W3dGCamera *w3d_ninja_camera_construct_800cc6d0(W3dGCamera *camera, int owner, int flags)
{
    w3d_camera_base_construct_800d2dec(camera, owner, w3d_str_80387d74, flags);
    camera->secondary_vtable = w3d_vtable_8040fb90;
    w3d_camera_set_name_800d31d8(camera, w3d_str_80387d7c);
    return camera;
}

void w3d_ninja_camera_reset_800cc728(void *camera)
{
    w3d_camera_reset_800d308c(camera);
    w3d_camera_update_800d5028(camera);
}

void w3d_ninja_camera_update_800cc75c(void *camera)
{
    w3d_camera_update_800d5028(camera);
}

W3dLogicType *w3d_logic_type_get_800cc77c(void)
{
    return &w3d_logic_type_80360b70;
}

void w3d_logic_unlink_800cc788(W3dLogic_80360b70 *object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360b70, &object->references);
    w3d_logic_type_80360b70.count--;
}

W3dLogic_80360b70 *w3d_logic_construct_800cc8a0(W3dLogic_80360b70 *object);
W3dLogic_80360b70 *w3d_logic_create_800cc7cc(void)
{
    W3dLogic_80360b70 *object = w3d_logic_construct_800cc8a0((W3dLogic_80360b70 *)w3d_heap_allocate_entry_a(68));
    w3d_state_register(&w3d_logic_type_80360b70, object ? &object->references : 0);
    w3d_logic_type_80360b70.count++;
    return object;
}

void w3d_logic_unlink_800cc788(W3dLogic_80360b70 *object);
void w3d_logic_destroy_800cc908(W3dLogic_80360b70 *object, int flags);
unsigned short w3d_logic_release_800cc82c(W3dLogic_80360b70 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800cc788(object);
        if (object)
            w3d_logic_destroy_800cc908(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800cc888(W3dLogic_80360b70 *object)
{
    return object->references++;
}

W3dLogic_80360b70 *w3d_logic_construct_800cc8a0(W3dLogic_80360b70 *object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_vtable_8040fbc8;
    object->held_24 = 0;
    object->held_28 = 0;
    w3d_task_list_init_802109dc(&object->tasks);
    object->held_38 = 0;
    object->held_3c = 0;
    object->id = -1;
    object->enabled = 1;
    return object;
}

void w3d_logic_destroy_800cc908(W3dLogic_80360b70 *object, int flags)
{
    object->vtable = w3d_vtable_8040fbc8;
    if (object->held_3c)
        object->held_3c->vtbl->release(object->held_3c);
    if (object->held_38)
        object->held_38->vtbl->release(object->held_38);
    w3d_task_list_destroy_80210abc(&object->tasks, 2);
    if (object->held_28)
        object->held_28->vtbl->release(object->held_28);
    if (object->held_24)
        object->held_24->vtbl->release(object->held_24);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_logic_kind_800ccaf0(void)
{
    return -1;
}

void w3d_logic_detach_800ccbf4(W3dLogic_80360b70 *object)
{
    w3d_logic_clear_800ccd54(object);
}

W3dGIface **w3d_logic_held_28_800ccd04(W3dGIface **out, W3dLogic_80360b70 *object)
{
    W3dGIface *held = object->held_28;
    *out = held;
    if (held)
        held->vtbl->retain(held);
    return out;
}

void w3d_logic_clear_800ccd54(W3dLogic_80360b70 *object)
{
    unsigned int index;
    for (index = 0; index < object->tasks.count; index++) {
        W3dGTaskList *tasks = &object->tasks;
        if (tasks->data[index])
            tasks->data[index]->vtbl->release(tasks->data[index]);
        tasks->data[index] = 0;
    }
    w3d_task_deferred_clear(&object->tasks);
}

W3dGPos w3d_tracker_position_800cd0d0(W3dGTracker *tracker)
{
    W3dGActor *actor = w3d_actor_lookup_80164fc8(tracker->actor);
    if (!actor) {
        const W3dGVec3 &zero = w3d_vec3_zero_8045e788[0];
        return W3dGPos(zero.x, zero.y, zero.z);
    }
    return w3d_actor_position_800d1104(actor);
}

float w3d_tracker_heading_800cd13c(W3dGTracker *tracker)
{
    W3dGActor *actor = w3d_actor_lookup_80164fc8(tracker->actor);
    if (actor)
        return w3d_actor_heading_800d1128(actor);
    return w3d_f32_80387e24[0];
}

int w3d_tracker_state_800cd7fc(W3dGTracker *tracker)
{
    W3dGActor *actor = w3d_actor_lookup_80164fc8(tracker->actor);
    if (actor)
        return w3d_actor_state_800d1c14(actor);
    return 0;
}

void w3d_tracker_drop_target_800cd990(W3dGTracker *tracker)
{
    if (tracker->target != -1) {
        W3dGActor *actor = w3d_actor_lookup_80164fc8(tracker->target);
        if (actor)
            w3d_actor_release_target_80122af8(actor);
        tracker->target = -1;
    }
}

W3dLogicType *w3d_logic_type_get_800cdaa8(void)
{
    return &w3d_logic_type_80360ba0;
}

void w3d_logic_unlink_800cdab4(W3dLogic_80360ba0 *object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360ba0, &object->references);
    w3d_logic_type_80360ba0.count--;
}

W3dLogic_80360ba0 *w3d_logic_construct_800cdbcc(W3dLogic_80360ba0 *object);
W3dLogic_80360ba0 *w3d_logic_create_800cdaf8(void)
{
    W3dLogic_80360ba0 *object = w3d_logic_construct_800cdbcc((W3dLogic_80360ba0 *)w3d_heap_allocate_entry_a(316));
    w3d_state_register(&w3d_logic_type_80360ba0, object ? &object->references : 0);
    w3d_logic_type_80360ba0.count++;
    return object;
}

void w3d_logic_unlink_800cdab4(W3dLogic_80360ba0 *object);
void w3d_logic_destroy_800cdd68(W3dLogic_80360ba0 *object, int flags);
unsigned short w3d_logic_release_800cdb58(W3dLogic_80360ba0 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800cdab4(object);
        if (object)
            w3d_logic_destroy_800cdd68(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800cdbb4(W3dLogic_80360ba0 *object)
{
    return object->references++;
}

}
