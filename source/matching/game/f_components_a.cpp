/* Reference-counted component types with per-type registry lists (0x80060a2c..).
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

typedef struct W3dComponent_80060a2c {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x12c - 0x6];
    int value_12c;
    unsigned char unknown_130[0x134 - 0x130];
    W3dInterface *held_134;
    W3dInterface *held_138;
    unsigned char unknown_13c[0x148 - 0x13c];
    W3dInterface *held_148;
} W3dComponent_80060a2c;

typedef struct W3dComponent_800612c0 {
    const void *vtable;
    unsigned short references;
} W3dComponent_800612c0;

typedef struct W3dComponent_80061744 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    int value_01c;
    W3dInterface *held_020;
    W3dInterface *held_024;
} W3dComponent_80061744;

typedef struct W3dComponent_80061e44 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x40 - 0x6];
    W3dInterface *held_040;
    int value_044;
    int value_048;
    W3dInterface *held_04c;
    W3dInterface *held_050;
    W3dInterface *held_054;
} W3dComponent_80061e44;

typedef struct W3dComponent_80062b00 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface *held_01c;
    unsigned char unknown_020[0x28 - 0x20];
    W3dInterface *held_028;
    W3dInterface *held_02c;
    W3dInterface *held_030;
    W3dInterface *held_034;
} W3dComponent_80062b00;

extern W3dSharedList w3d_component_list_80360210;
extern W3dSharedList w3d_component_list_80360240;
extern W3dSharedList w3d_component_list_80360270;
extern W3dSharedList w3d_component_list_803602a0;
extern W3dSharedList w3d_component_list_803602d0;
extern const void *w3d_component_vtable_8040ec08[];
extern const void *w3d_component_vtable_8040ec78[];
extern const void *w3d_component_vtable_8040ece8[];
extern const void *w3d_component_vtable_8040ed28[];
extern const void *w3d_component_vtable_8040ed80[];

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(W3dSharedList *list, void *link);
void w3d_state_register(W3dSharedList *list, void *link);
void w3d_actor_base_destroy(void *object, int flags);
int w3d_actor_base_initialize(void *object);
int w3d_base_construct_8002a914(void *object);
int w3d_base_construct_800ea180(void *object);
void w3d_base_destroy_8002a978(void *object, int flags);
void w3d_base_destroy_800ea324(void *object, int flags);
void w3d_base_destroy_8015ff2c(void *object, int flags);
int w3d_base_handle_message_800ea62c(void *object, W3dMessage *message);
void w3d_component_start_80060cc0(void *object);
void w3d_component_start_80061684(void *object);
void w3d_component_stop_80060fe0(void *object);
void w3d_component_stop_800616a4(void *object);

W3dComponent_80060a2c *w3d_component_construct_80060b50(W3dComponent_80060a2c *object);
void w3d_component_destroy_80060ba0(W3dComponent_80060a2c *object, int flags);
void w3d_component_unlink_80060a38(W3dComponent_80060a2c *object);

W3dSharedList *w3d_component_list_get_80060a2c(void)
{
    return &w3d_component_list_80360210;
}

void w3d_component_unlink_80060a38(W3dComponent_80060a2c *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360210, &object->references);
    w3d_component_list_80360210.count--;
}

W3dComponent_80060a2c *w3d_component_create_80060a7c(void)
{
    W3dComponent_80060a2c *object = w3d_component_construct_80060b50((W3dComponent_80060a2c *)w3d_heap_allocate_entry_a(332));
    w3d_state_register(&w3d_component_list_80360210, object ? &object->references : 0);
    w3d_component_list_80360210.count++;
    return object;
}

unsigned short w3d_component_release_80060adc(W3dComponent_80060a2c *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80060a38(object);
        if (object)
            w3d_component_destroy_80060ba0(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80060b38(W3dComponent_80060a2c *object)
{
    return object->references++;
}

W3dComponent_80060a2c *w3d_component_construct_80060b50(W3dComponent_80060a2c *object)
{
    w3d_base_construct_800ea180(object);
    object->vtable = w3d_component_vtable_8040ec08;
    object->held_134 = 0;
    object->held_138 = 0;
    object->held_148 = 0;
    object->value_12c = 0;
    return object;
}

void w3d_component_destroy_80060ba0(W3dComponent_80060a2c *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ec08;
    if (object->held_148)
        object->held_148->vtable->release(object->held_148);
    if (object->held_138)
        object->held_138->vtable->release(object->held_138);
    if (object->held_134)
        object->held_134->vtable->release(object->held_134);
    w3d_base_destroy_800ea324(object, flags);
}

int w3d_component_handle_message_80060c38(W3dComponent_80060a2c *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_800ea62c(object, message) >= 0) {
            w3d_component_start_80060cc0(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_80060fe0(object);
        break;
    }
    return w3d_base_handle_message_800ea62c(object, message);
}

void w3d_component_stop_80060fe0(void *object)
{
}

W3dComponent_800612c0 *w3d_component_construct_800613e4(W3dComponent_800612c0 *object);
void w3d_component_destroy_80061420(W3dComponent_800612c0 *object, int flags);
void w3d_component_unlink_800612cc(W3dComponent_800612c0 *object);

W3dSharedList *w3d_component_list_get_800612c0(void)
{
    return &w3d_component_list_80360240;
}

void w3d_component_unlink_800612cc(W3dComponent_800612c0 *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360240, &object->references);
    w3d_component_list_80360240.count--;
}

W3dComponent_800612c0 *w3d_component_create_80061310(void)
{
    W3dComponent_800612c0 *object = w3d_component_construct_800613e4((W3dComponent_800612c0 *)w3d_heap_allocate_entry_a(308));
    w3d_state_register(&w3d_component_list_80360240, object ? &object->references : 0);
    w3d_component_list_80360240.count++;
    return object;
}

unsigned short w3d_component_release_80061370(W3dComponent_800612c0 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800612cc(object);
        if (object)
            w3d_component_destroy_80061420(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800613cc(W3dComponent_800612c0 *object)
{
    return object->references++;
}

W3dComponent_800612c0 *w3d_component_construct_800613e4(W3dComponent_800612c0 *object)
{
    w3d_base_construct_800ea180(object);
    object->vtable = w3d_component_vtable_8040ec78;
    return object;
}

void w3d_component_destroy_80061420(W3dComponent_800612c0 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ec78;
    w3d_base_destroy_800ea324(object, flags);
}

int w3d_component_handle_message_80061450(W3dComponent_800612c0 *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_800ea62c(object, message) >= 0) {
            w3d_component_start_80061684(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800616a4(object);
        break;
    }
    return w3d_base_handle_message_800ea62c(object, message);
}

void w3d_component_stop_800616a4(void *object)
{
}

W3dComponent_80061744 *w3d_component_construct_80061868(W3dComponent_80061744 *object);
void w3d_component_destroy_800618b8(W3dComponent_80061744 *object, int flags);
void w3d_component_unlink_80061750(W3dComponent_80061744 *object);

W3dSharedList *w3d_component_list_get_80061744(void)
{
    return &w3d_component_list_80360270;
}

void w3d_component_unlink_80061750(W3dComponent_80061744 *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360270, &object->references);
    w3d_component_list_80360270.count--;
}

W3dComponent_80061744 *w3d_component_create_80061794(void)
{
    W3dComponent_80061744 *object = w3d_component_construct_80061868((W3dComponent_80061744 *)w3d_heap_allocate_entry_a(44));
    w3d_state_register(&w3d_component_list_80360270, object ? &object->references : 0);
    w3d_component_list_80360270.count++;
    return object;
}

unsigned short w3d_component_release_800617f4(W3dComponent_80061744 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80061750(object);
        if (object)
            w3d_component_destroy_800618b8(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80061850(W3dComponent_80061744 *object)
{
    return object->references++;
}

W3dComponent_80061744 *w3d_component_construct_80061868(W3dComponent_80061744 *object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_8040ece8;
    object->value_01c = 20;
    object->held_020 = 0;
    object->held_024 = 0;
    return object;
}

void w3d_component_destroy_800618b8(W3dComponent_80061744 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ece8;
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    object->held_024 = 0;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_actor_base_destroy(object, flags);
}

W3dComponent_80061e44 *w3d_component_construct_80061f68(W3dComponent_80061e44 *object);
void w3d_component_destroy_80061fc0(W3dComponent_80061e44 *object, int flags);
void w3d_component_unlink_80061e50(W3dComponent_80061e44 *object);

W3dSharedList *w3d_component_list_get_80061e44(void)
{
    return &w3d_component_list_803602a0;
}

void w3d_component_unlink_80061e50(W3dComponent_80061e44 *object)
{
    w3d_owner_list_remove(&w3d_component_list_803602a0, &object->references);
    w3d_component_list_803602a0.count--;
}

W3dComponent_80061e44 *w3d_component_create_80061e94(void)
{
    W3dComponent_80061e44 *object = w3d_component_construct_80061f68((W3dComponent_80061e44 *)w3d_heap_allocate_entry_a(92));
    w3d_state_register(&w3d_component_list_803602a0, object ? &object->references : 0);
    w3d_component_list_803602a0.count++;
    return object;
}

unsigned short w3d_component_release_80061ef4(W3dComponent_80061e44 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80061e50(object);
        if (object)
            w3d_component_destroy_80061fc0(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80061f50(W3dComponent_80061e44 *object)
{
    return object->references++;
}

W3dComponent_80061e44 *w3d_component_construct_80061f68(W3dComponent_80061e44 *object)
{
    w3d_base_construct_8002a914(object);
    object->vtable = w3d_component_vtable_8040ed28;
    object->held_040 = 0;
    object->held_050 = 0;
    object->held_054 = 0;
    object->value_044 = 0;
    object->value_048 = 0;
    object->held_04c = 0;
    return object;
}

void w3d_component_destroy_80061fc0(W3dComponent_80061e44 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ed28;
    if (object->held_054)
        object->held_054->vtable->release(object->held_054);
    if (object->held_050)
        object->held_050->vtable->release(object->held_050);
    if (object->held_04c)
        object->held_04c->vtable->release(object->held_04c);
    if (object->held_040)
        object->held_040->vtable->release(object->held_040);
    w3d_base_destroy_8002a978(object, flags);
}

W3dComponent_80062b00 *w3d_component_construct_80062c24(W3dComponent_80062b00 *object);
void w3d_component_destroy_80062ccc(W3dComponent_80062b00 *object, int flags);
void w3d_component_unlink_80062b0c(W3dComponent_80062b00 *object);

W3dSharedList *w3d_component_list_get_80062b00(void)
{
    return &w3d_component_list_803602d0;
}

void w3d_component_unlink_80062b0c(W3dComponent_80062b00 *object)
{
    w3d_owner_list_remove(&w3d_component_list_803602d0, &object->references);
    w3d_component_list_803602d0.count--;
}

W3dComponent_80062b00 *w3d_component_create_80062b50(void)
{
    W3dComponent_80062b00 *object = w3d_component_construct_80062c24((W3dComponent_80062b00 *)w3d_heap_allocate_entry_a(76));
    w3d_state_register(&w3d_component_list_803602d0, object ? &object->references : 0);
    w3d_component_list_803602d0.count++;
    return object;
}

unsigned short w3d_component_release_80062bb0(W3dComponent_80062b00 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80062b0c(object);
        if (object)
            w3d_component_destroy_80062ccc(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80062c0c(W3dComponent_80062b00 *object)
{
    return object->references++;
}

void w3d_component_destroy_80062ccc(W3dComponent_80062b00 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ed80;
    if (object->held_034)
        object->held_034->vtable->release(object->held_034);
    if (object->held_030)
        object->held_030->vtable->release(object->held_030);
    if (object->held_02c)
        object->held_02c->vtable->release(object->held_02c);
    if (object->held_028)
        object->held_028->vtable->release(object->held_028);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

}
