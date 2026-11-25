/* Reference-counted component types with per-type registry lists (0x80097600..).
 *
 * Names are inferred from behavior; no original symbols survive. Each type
 * keeps a global registry list (u16 count at +0x22) and follows one shape:
 * list getter, unlink, create (allocate, construct, register), release and
 * retain on the u16 reference count at +4 (which is also the list link), a
 * constructor that installs the type vtable and clears fields, a destructor
 * that releases held interfaces (4-byte-entry vtable at +0, release slot at
 * +0x10) before the base destructor, and often a message handler for ids 64
 * and 66 (0x80004005 is returned when the base handler fails on 64).
 */
extern "C" {

typedef struct W3dSharedList {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dSharedList;

typedef struct W3dMessage {
    unsigned short id;
} W3dMessage;

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    void *unknown_00[4];
    void (*release)(W3dInterface *object);
} W3dInterfaceTable;

struct W3dInterface {
    W3dInterfaceTable *vtable;
};

typedef struct W3dComponent_80097600 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface *held_01c;
    unsigned char unknown_020[0x3c - 0x20];
    int value_03c;
    int value_040;
} W3dComponent_80097600;

typedef struct W3dComponent_80097f88 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x98 - 0x6];
    W3dInterface *held_098;
} W3dComponent_80097f88;

typedef struct W3dComponent_80098a94 {
    const void *vtable;
    unsigned short references;
} W3dComponent_80098a94;

extern W3dSharedList w3d_component_list_803605a0;
extern W3dSharedList w3d_component_list_803605d0;
extern W3dSharedList w3d_component_list_80360600;
extern const void *w3d_component_vtable_8040f290[];
extern const void *w3d_component_vtable_8040f2d0[];

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(W3dSharedList *list, void *link);
void w3d_state_register(W3dSharedList *list, void *link);
int w3d_base_construct_8015fef0(void *object);
void w3d_base_destroy_8003de80(void *object, int flags);
void w3d_base_destroy_8015ff2c(void *object, int flags);
int w3d_base_handle_message_8003df40(void *object, W3dMessage *message);
int w3d_base_handle_message_8015fb34(void *object, W3dMessage *message);
void w3d_component_start_80097980(void *object);
void w3d_component_start_80098240(void *object);
void w3d_component_stop_80097c5c(void *object);
void w3d_component_stop_8009836c(void *object);

W3dComponent_80097600 *w3d_component_construct_80097724(W3dComponent_80097600 *object);
void w3d_component_destroy_80097774(W3dComponent_80097600 *object, int flags);
void w3d_component_unlink_8009760c(W3dComponent_80097600 *object);

W3dSharedList *w3d_component_list_get_80097600(void)
{
    return &w3d_component_list_803605a0;
}

void w3d_component_unlink_8009760c(W3dComponent_80097600 *object)
{
    w3d_owner_list_remove(&w3d_component_list_803605a0, &object->references);
    w3d_component_list_803605a0.count--;
}

W3dComponent_80097600 *w3d_component_create_80097650(void)
{
    W3dComponent_80097600 *object = w3d_component_construct_80097724((W3dComponent_80097600 *)w3d_heap_allocate_entry_a(72));
    w3d_state_register(&w3d_component_list_803605a0, object ? &object->references : 0);
    w3d_component_list_803605a0.count++;
    return object;
}

unsigned short w3d_component_release_800976b0(W3dComponent_80097600 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8009760c(object);
        if (object)
            w3d_component_destroy_80097774(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_8009770c(W3dComponent_80097600 *object)
{
    return object->references++;
}

W3dComponent_80097600 *w3d_component_construct_80097724(W3dComponent_80097600 *object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f290;
    object->held_01c = 0;
    object->value_03c = -1;
    object->value_040 = 0;
    return object;
}

void w3d_component_destroy_80097774(W3dComponent_80097600 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040f290;
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_component_handle_message_800977d4(W3dComponent_80097600 *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_80097980(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_80097c5c(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

W3dComponent_80097f88 *w3d_component_construct_800980ac(W3dComponent_80097f88 *object);
void w3d_component_destroy_8009810c(W3dComponent_80097f88 *object, int flags);
void w3d_component_unlink_80097f94(W3dComponent_80097f88 *object);

W3dSharedList *w3d_component_list_get_80097f88(void)
{
    return &w3d_component_list_803605d0;
}

void w3d_component_unlink_80097f94(W3dComponent_80097f88 *object)
{
    w3d_owner_list_remove(&w3d_component_list_803605d0, &object->references);
    w3d_component_list_803605d0.count--;
}

W3dComponent_80097f88 *w3d_component_create_80097fd8(void)
{
    W3dComponent_80097f88 *object = w3d_component_construct_800980ac((W3dComponent_80097f88 *)w3d_heap_allocate_entry_a(156));
    w3d_state_register(&w3d_component_list_803605d0, object ? &object->references : 0);
    w3d_component_list_803605d0.count++;
    return object;
}

unsigned short w3d_component_release_80098038(W3dComponent_80097f88 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80097f94(object);
        if (object)
            w3d_component_destroy_8009810c(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80098094(W3dComponent_80097f88 *object)
{
    return object->references++;
}

void w3d_component_destroy_8009810c(W3dComponent_80097f88 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040f2d0;
    if (object->held_098)
        object->held_098->vtable->release(object->held_098);
    w3d_base_destroy_8003de80(object, flags);
}

int w3d_component_handle_message_8009816c(W3dComponent_80097f88 *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8003df40(object, message) >= 0) {
            w3d_component_start_80098240(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_8009836c(object);
        break;
    }
    return w3d_base_handle_message_8003df40(object, message);
}

void w3d_component_stop_8009836c(void *object)
{
}

W3dComponent_80098a94 *w3d_component_construct_80098bb8(W3dComponent_80098a94 *object);
void w3d_component_destroy_80098c2c(W3dComponent_80098a94 *object, int flags);
void w3d_component_unlink_80098aa0(W3dComponent_80098a94 *object);

W3dSharedList *w3d_component_list_get_80098a94(void)
{
    return &w3d_component_list_80360600;
}

void w3d_component_unlink_80098aa0(W3dComponent_80098a94 *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360600, &object->references);
    w3d_component_list_80360600.count--;
}

W3dComponent_80098a94 *w3d_component_create_80098ae4(void)
{
    W3dComponent_80098a94 *object = w3d_component_construct_80098bb8((W3dComponent_80098a94 *)w3d_heap_allocate_entry_a(80));
    w3d_state_register(&w3d_component_list_80360600, object ? &object->references : 0);
    w3d_component_list_80360600.count++;
    return object;
}

unsigned short w3d_component_release_80098b44(W3dComponent_80098a94 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80098aa0(object);
        if (object)
            w3d_component_destroy_80098c2c(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80098ba0(W3dComponent_80098a94 *object)
{
    return object->references++;
}

}
