/* Shared logic-class layouts and helpers for worker-g units (second header).
 * Names are inferred from behavior; no original symbols survive.
 */
#ifndef W3D_G_TYPES2_H
#define W3D_G_TYPES2_H

#include "g_types.h"

/* Counted interface held by value: retains on construction, releases on exit. */
struct W3dGHeld {
    W3dGIface *object;
    W3dGHeld(W3dGIface *pointer) : object(pointer)
    {
        if (object)
            object->vtbl->retain(object);
    }
    ~W3dGHeld()
    {
        if (object)
            object->vtbl->release(object);
    }
};

/* Position value built from three floats or copied float by float. */
struct W3dGPos {
    float x, y, z;
    W3dGPos() {}
    W3dGPos(float px, float py, float pz) : x(px), y(py), z(pz) {}
    W3dGPos(const W3dGVec3 &v) : x(v.x), y(v.y), z(v.z) {}
};

extern "C" {

/* Global type record of a logic class; u16 live-instance count at +0x22. */
typedef struct W3dLogicType {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dLogicType;

/* Message without payload: u16 identifier and the message vtable. */
typedef struct W3dPlainMessage {
    unsigned short id;
    void *vtable;
} W3dPlainMessage;

/* Engine string: data points past a {refs, length, capacity} u16 header. */
typedef struct W3dGString {
    char *data;
} W3dGString;

extern unsigned char w3d_vtable_8040db38[];
extern void *w3d_message_storage_804b1754;
extern void *w3d_registry_804b178c;

void w3d_state_register(W3dLogicType *type, void *link);
void w3d_owner_list_remove(W3dLogicType *type, void *link);
void * w3d_actor_base_initialize(void *object);
void w3d_actor_base_destroy(void *object, int flags);
void * w3d_logic_base_init_801628b0(void *object);
void w3d_logic_base_destroy_801628ec(void *object, int flags);
int w3d_actor_handle_8015fb34(void *object, W3dGMessage *message);
int w3d_logic_base_handle_8016293c(void *object, W3dGMessage *message);
int w3d_message_matches_8015f65c(unsigned int id, W3dGCachedMessage *message);
void w3d_actor_remove_8015fd1c(void *object);
void *w3d_message_allocate_801613f0(void *storage, unsigned int size);
W3dGIface *w3d_class_create_8020b680(void *type);
int w3d_registry_add_80164514(void *registry, W3dGIface *object, int owner);

}

/* Length field of an engine string (u16 just before the data's last header word). */
static inline unsigned short w3d_gstring_length(const W3dGString *string)
{
    return ((unsigned short *)string->data)[-2];
}

/* Creates an instance of a class and registers it with an owner. */
static inline void w3d_registry_add(W3dGIface *object, int owner)
{
    w3d_registry_add_80164514(w3d_registry_804b178c, object, owner);
}

/* Allocates, fills and posts a payload-free message. */
static inline void w3d_post_plain_message(W3dGCachedMessage *name)
{
    W3dPlainMessage *message =
        (W3dPlainMessage *)w3d_message_allocate_801613f0(w3d_message_storage_804b1754, 8);
    message->id = w3d_cached_message_id(name, 1);
    message->vtable = w3d_vtable_8040db38;
    w3d_message_post_current(message);
}

#endif
