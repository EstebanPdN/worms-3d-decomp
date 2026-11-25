/* Reference-counted component types with per-type registry lists (0x800635bc..).
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

typedef struct W3dComponent_800635bc {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface *held_01c;
    W3dInterface *held_020;
    W3dInterface *held_024;
    unsigned char unknown_028[0x68 - 0x28];
    W3dInterface *held_068;
    W3dInterface *held_06c;
    W3dInterface *held_070;
    W3dInterface *held_074;
    W3dInterface *held_078;
    W3dInterface *held_07c;
    W3dInterface *held_080;
    W3dInterface *held_084;
    W3dInterface *held_088;
    W3dInterface *held_08c;
    W3dInterface *held_090;
} W3dComponent_800635bc;

typedef struct W3dComponent_80064f4c {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x2c - 0x6];
    W3dInterface *held_02c;
    W3dInterface *held_030;
    W3dInterface *held_034;
    W3dInterface *held_038;
    W3dInterface *held_03c;
    W3dInterface *held_040;
    W3dInterface *held_044;
    W3dInterface *held_048;
    W3dInterface *held_04c;
    W3dInterface *held_050;
    W3dInterface *held_054;
    W3dInterface *held_058;
    W3dInterface *held_05c;
    W3dInterface *held_060;
    W3dInterface *held_064;
    W3dInterface *held_068;
} W3dComponent_80064f4c;

typedef struct W3dComponent_80066974 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x20 - 0x6];
    W3dInterface *held_020;
} W3dComponent_80066974;

typedef struct W3dComponent_80066dac {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x40 - 0x6];
    int value_040;
    int value_044;
    W3dInterface *held_048;
    W3dInterface *held_04c;
    W3dInterface *held_050;
    int value_054;
    int value_058;
} W3dComponent_80066dac;

typedef struct W3dComponent_80067f14 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface *held_01c;
    W3dInterface *held_020;
    int value_024;
} W3dComponent_80067f14;

typedef struct W3dComponent_8006844c {
    const void *vtable;
    unsigned short references;
} W3dComponent_8006844c;

typedef struct W3dComponent_80069abc {
    const void *vtable;
    unsigned short references;
} W3dComponent_80069abc;

extern W3dSharedList w3d_component_list_80360300;
extern W3dSharedList w3d_component_list_80360330;
extern W3dSharedList w3d_component_list_80360360;
extern W3dSharedList w3d_component_list_80360390;
extern W3dSharedList w3d_component_list_803603c0;
extern W3dSharedList w3d_component_list_803603f0;
extern W3dSharedList w3d_component_list_80360420;
extern const void *w3d_component_vtable_8040edc0[];
extern const void *w3d_component_vtable_8040ee00[];
extern const void *w3d_component_vtable_8040ee40[];
extern const void *w3d_component_vtable_8040ee80[];
extern const void *w3d_component_vtable_8040eee8[];

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(W3dSharedList *list, void *link);
void w3d_state_register(W3dSharedList *list, void *link);
void w3d_actor_base_destroy(void *object, int flags);
int w3d_actor_base_initialize(void *object);
int w3d_base_construct_8015fef0(void *object);
void w3d_base_destroy_8015ff2c(void *object, int flags);
int w3d_base_handle_message_8015fb34(void *object, W3dMessage *message);
void w3d_component_start_80063a0c(void *object);
void w3d_component_start_80066c9c(void *object);
void w3d_component_start_800670e0(void *object);
void w3d_component_stop_80064104(void *object);
void w3d_component_stop_80066d1c(void *object);
void w3d_component_stop_80067264(void *object);

W3dComponent_800635bc *w3d_component_construct_800636e0(W3dComponent_800635bc *object);
void w3d_component_destroy_80063794(W3dComponent_800635bc *object, int flags);
void w3d_component_unlink_800635c8(W3dComponent_800635bc *object);

W3dSharedList *w3d_component_list_get_800635bc(void)
{
    return &w3d_component_list_80360300;
}

void w3d_component_unlink_800635c8(W3dComponent_800635bc *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360300, &object->references);
    w3d_component_list_80360300.count--;
}

W3dComponent_800635bc *w3d_component_create_8006360c(void)
{
    W3dComponent_800635bc *object = w3d_component_construct_800636e0((W3dComponent_800635bc *)w3d_heap_allocate_entry_a(148));
    w3d_state_register(&w3d_component_list_80360300, object ? &object->references : 0);
    w3d_component_list_80360300.count++;
    return object;
}

unsigned short w3d_component_release_8006366c(W3dComponent_800635bc *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800635c8(object);
        if (object)
            w3d_component_destroy_80063794(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800636c8(W3dComponent_800635bc *object)
{
    return object->references++;
}

void w3d_component_destroy_80063794(W3dComponent_800635bc *object, int flags)
{
    object->vtable = w3d_component_vtable_8040edc0;
    if (object->held_090)
        object->held_090->vtable->release(object->held_090);
    if (object->held_08c)
        object->held_08c->vtable->release(object->held_08c);
    if (object->held_088)
        object->held_088->vtable->release(object->held_088);
    if (object->held_084)
        object->held_084->vtable->release(object->held_084);
    if (object->held_080)
        object->held_080->vtable->release(object->held_080);
    if (object->held_07c)
        object->held_07c->vtable->release(object->held_07c);
    if (object->held_078)
        object->held_078->vtable->release(object->held_078);
    if (object->held_074)
        object->held_074->vtable->release(object->held_074);
    if (object->held_070)
        object->held_070->vtable->release(object->held_070);
    if (object->held_06c)
        object->held_06c->vtable->release(object->held_06c);
    if (object->held_068)
        object->held_068->vtable->release(object->held_068);
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_component_handle_message_80063960(W3dComponent_800635bc *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_80063a0c(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_80064104(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

W3dComponent_80064f4c *w3d_component_construct_80065070(W3dComponent_80064f4c *object);
void w3d_component_destroy_80065110(W3dComponent_80064f4c *object, int flags);
void w3d_component_unlink_80064f58(W3dComponent_80064f4c *object);

W3dSharedList *w3d_component_list_get_80064f4c(void)
{
    return &w3d_component_list_80360330;
}

void w3d_component_unlink_80064f58(W3dComponent_80064f4c *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360330, &object->references);
    w3d_component_list_80360330.count--;
}

W3dComponent_80064f4c *w3d_component_create_80064f9c(void)
{
    W3dComponent_80064f4c *object = w3d_component_construct_80065070((W3dComponent_80064f4c *)w3d_heap_allocate_entry_a(128));
    w3d_state_register(&w3d_component_list_80360330, object ? &object->references : 0);
    w3d_component_list_80360330.count++;
    return object;
}

unsigned short w3d_component_release_80064ffc(W3dComponent_80064f4c *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80064f58(object);
        if (object)
            w3d_component_destroy_80065110(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80065058(W3dComponent_80064f4c *object)
{
    return object->references++;
}

void w3d_component_destroy_80065110(W3dComponent_80064f4c *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ee00;
    if (object->held_068)
        object->held_068->vtable->release(object->held_068);
    if (object->held_064)
        object->held_064->vtable->release(object->held_064);
    if (object->held_060)
        object->held_060->vtable->release(object->held_060);
    if (object->held_05c)
        object->held_05c->vtable->release(object->held_05c);
    if (object->held_058)
        object->held_058->vtable->release(object->held_058);
    if (object->held_054)
        object->held_054->vtable->release(object->held_054);
    if (object->held_050)
        object->held_050->vtable->release(object->held_050);
    if (object->held_04c)
        object->held_04c->vtable->release(object->held_04c);
    if (object->held_048)
        object->held_048->vtable->release(object->held_048);
    if (object->held_044)
        object->held_044->vtable->release(object->held_044);
    if (object->held_040)
        object->held_040->vtable->release(object->held_040);
    if (object->held_03c)
        object->held_03c->vtable->release(object->held_03c);
    if (object->held_038)
        object->held_038->vtable->release(object->held_038);
    if (object->held_034)
        object->held_034->vtable->release(object->held_034);
    if (object->held_030)
        object->held_030->vtable->release(object->held_030);
    if (object->held_02c)
        object->held_02c->vtable->release(object->held_02c);
    w3d_base_destroy_8015ff2c(object, flags);
}

W3dComponent_80066974 *w3d_component_construct_80066a98(W3dComponent_80066974 *object);
void w3d_component_destroy_80066adc(W3dComponent_80066974 *object, int flags);
void w3d_component_unlink_80066980(W3dComponent_80066974 *object);

W3dSharedList *w3d_component_list_get_80066974(void)
{
    return &w3d_component_list_80360360;
}

void w3d_component_unlink_80066980(W3dComponent_80066974 *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360360, &object->references);
    w3d_component_list_80360360.count--;
}

W3dComponent_80066974 *w3d_component_create_800669c4(void)
{
    W3dComponent_80066974 *object = w3d_component_construct_80066a98((W3dComponent_80066974 *)w3d_heap_allocate_entry_a(48));
    w3d_state_register(&w3d_component_list_80360360, object ? &object->references : 0);
    w3d_component_list_80360360.count++;
    return object;
}

unsigned short w3d_component_release_80066a24(W3dComponent_80066974 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80066980(object);
        if (object)
            w3d_component_destroy_80066adc(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80066a80(W3dComponent_80066974 *object)
{
    return object->references++;
}

W3dComponent_80066974 *w3d_component_construct_80066a98(W3dComponent_80066974 *object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040ee40;
    object->held_020 = 0;
    return object;
}

void w3d_component_destroy_80066adc(W3dComponent_80066974 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ee40;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_component_handle_message_80066b3c(W3dComponent_80066974 *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_80066c9c(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_80066d1c(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

void w3d_component_stop_80066d1c(void *object)
{
}

W3dComponent_80066dac *w3d_component_construct_80066ed0(W3dComponent_80066dac *object);
void w3d_component_destroy_80066f2c(W3dComponent_80066dac *object, int flags);
void w3d_component_unlink_80066db8(W3dComponent_80066dac *object);

W3dSharedList *w3d_component_list_get_80066dac(void)
{
    return &w3d_component_list_80360390;
}

void w3d_component_unlink_80066db8(W3dComponent_80066dac *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360390, &object->references);
    w3d_component_list_80360390.count--;
}

W3dComponent_80066dac *w3d_component_create_80066dfc(void)
{
    W3dComponent_80066dac *object = w3d_component_construct_80066ed0((W3dComponent_80066dac *)w3d_heap_allocate_entry_a(96));
    w3d_state_register(&w3d_component_list_80360390, object ? &object->references : 0);
    w3d_component_list_80360390.count++;
    return object;
}

unsigned short w3d_component_release_80066e5c(W3dComponent_80066dac *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80066db8(object);
        if (object)
            w3d_component_destroy_80066f2c(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80066eb8(W3dComponent_80066dac *object)
{
    return object->references++;
}

W3dComponent_80066dac *w3d_component_construct_80066ed0(W3dComponent_80066dac *object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_8040ee80;
    object->held_048 = 0;
    object->held_04c = 0;
    object->held_050 = 0;
    object->value_040 = 0;
    object->value_044 = 0;
    object->value_058 = 0;
    object->value_054 = 0;
    return object;
}

void w3d_component_destroy_80066f2c(W3dComponent_80066dac *object, int flags)
{
    object->vtable = w3d_component_vtable_8040ee80;
    if (object->held_050)
        object->held_050->vtable->release(object->held_050);
    if (object->held_04c)
        object->held_04c->vtable->release(object->held_04c);
    if (object->held_048)
        object->held_048->vtable->release(object->held_048);
    w3d_actor_base_destroy(object, flags);
}

int w3d_component_handle_message_80066fc4(W3dComponent_80066dac *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_800670e0(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_80067264(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

void w3d_component_stop_80067264(void *object)
{
}

W3dComponent_80067f14 *w3d_component_construct_80068038(W3dComponent_80067f14 *object);
void w3d_component_destroy_80068084(W3dComponent_80067f14 *object, int flags);
void w3d_component_unlink_80067f20(W3dComponent_80067f14 *object);

W3dSharedList *w3d_component_list_get_80067f14(void)
{
    return &w3d_component_list_803603c0;
}

void w3d_component_unlink_80067f20(W3dComponent_80067f14 *object)
{
    w3d_owner_list_remove(&w3d_component_list_803603c0, &object->references);
    w3d_component_list_803603c0.count--;
}

W3dComponent_80067f14 *w3d_component_create_80067f64(void)
{
    W3dComponent_80067f14 *object = w3d_component_construct_80068038((W3dComponent_80067f14 *)w3d_heap_allocate_entry_a(40));
    w3d_state_register(&w3d_component_list_803603c0, object ? &object->references : 0);
    w3d_component_list_803603c0.count++;
    return object;
}

unsigned short w3d_component_release_80067fc4(W3dComponent_80067f14 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80067f20(object);
        if (object)
            w3d_component_destroy_80068084(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80068020(W3dComponent_80067f14 *object)
{
    return object->references++;
}

W3dComponent_80067f14 *w3d_component_construct_80068038(W3dComponent_80067f14 *object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_8040eee8;
    object->held_01c = 0;
    object->held_020 = 0;
    object->value_024 = 0;
    return object;
}

void w3d_component_destroy_80068084(W3dComponent_80067f14 *object, int flags)
{
    object->vtable = w3d_component_vtable_8040eee8;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_actor_base_destroy(object, flags);
}

W3dComponent_8006844c *w3d_component_construct_80068570(W3dComponent_8006844c *object);
void w3d_component_destroy_80068648(W3dComponent_8006844c *object, int flags);
void w3d_component_unlink_80068458(W3dComponent_8006844c *object);

W3dSharedList *w3d_component_list_get_8006844c(void)
{
    return &w3d_component_list_803603f0;
}

void w3d_component_unlink_80068458(W3dComponent_8006844c *object)
{
    w3d_owner_list_remove(&w3d_component_list_803603f0, &object->references);
    w3d_component_list_803603f0.count--;
}

W3dComponent_8006844c *w3d_component_create_8006849c(void)
{
    W3dComponent_8006844c *object = w3d_component_construct_80068570((W3dComponent_8006844c *)w3d_heap_allocate_entry_a(400));
    w3d_state_register(&w3d_component_list_803603f0, object ? &object->references : 0);
    w3d_component_list_803603f0.count++;
    return object;
}

unsigned short w3d_component_release_800684fc(W3dComponent_8006844c *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80068458(object);
        if (object)
            w3d_component_destroy_80068648(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80068558(W3dComponent_8006844c *object)
{
    return object->references++;
}

W3dComponent_80069abc *w3d_component_construct_80069c8c(W3dComponent_80069abc *object);
void w3d_component_destroy_80069e94(W3dComponent_80069abc *object, int flags);
void w3d_component_unlink_80069ac8(W3dComponent_80069abc *object);

W3dSharedList *w3d_component_list_get_80069abc(void)
{
    return &w3d_component_list_80360420;
}

void w3d_component_unlink_80069ac8(W3dComponent_80069abc *object)
{
    w3d_owner_list_remove(&w3d_component_list_80360420, &object->references);
    w3d_component_list_80360420.count--;
}

W3dComponent_80069abc *w3d_component_create_80069b0c(void)
{
    W3dComponent_80069abc *object = w3d_component_construct_80069c8c((W3dComponent_80069abc *)w3d_heap_allocate_entry_a(3348));
    w3d_state_register(&w3d_component_list_80360420, object ? &object->references : 0);
    w3d_component_list_80360420.count++;
    return object;
}

unsigned short w3d_component_release_80069b6c(W3dComponent_80069abc *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80069ac8(object);
        if (object)
            w3d_component_destroy_80069e94(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80069bc8(W3dComponent_80069abc *object)
{
    return object->references++;
}

}
