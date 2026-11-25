/* Entity types from 0x80129738..0x8012c348: WalkingPayloadLogicEntity,
 * WaterRipplesGraphicEntity, WaterSparklesGraphicEntity,
 * WeaponCursorGraphicEntity and WeaponSelectPanelLogicEntity, plus a few
 * application helpers that precede them.
 *
 * Names are inferred from behavior and from the type-name strings registered
 * by the static initializers; no original symbols survive. Each type follows
 * the registry-list shape described in h_entities_a.cpp.
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

/* Engine string: one pointer to text behind a small header. */
typedef struct W3dString {
    char *data;
} W3dString;

/* Embedded handle member (constructed and destroyed out of line). */
typedef struct W3dMember {
    unsigned char unknown_00[4];
} W3dMember;

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(W3dSharedList *list, void *link);
void w3d_state_register(W3dSharedList *list, void *link);
void w3d_string_base_finish(W3dString *string);
void w3d_string_release(W3dString *string);

extern const void *w3d_walking_payload_logic_entity_vtable_80410cd0[];
extern const void *w3d_water_ripples_graphic_entity_vtable_80410d40[];
extern const void *w3d_water_sparkles_graphic_entity_vtable_80410d80[];
extern const void *w3d_weapon_cursor_graphic_entity_vtable_80410dc0[];
extern const void *w3d_weapon_select_panel_logic_entity_vtable_80410e00[];
extern void *w3d_weapon_select_panel_logic_entity_instance_804ab0cc;
int w3d_base_handle_message_800ea62c(void *object, W3dMessage *message);
int w3d_base_handle_message_8015fb34(void *object, W3dMessage *message);
void w3d_actor_base_destroy(void *object, int flags);
void w3d_base_destroy_800ea324(void *object, int flags);
void w3d_base_destroy_8015ff2c(void *object, int flags);

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dCursorGraphic W3dCursorGraphic;
typedef struct W3dCursorGraphicTable {
    void *unknown_00[4];
    void (*release)(W3dCursorGraphic *object);
    void *unknown_14[17];
    void (*set_visible_58)(W3dCursorGraphic *object, int visible);
} W3dCursorGraphicTable;
struct W3dCursorGraphic {
    W3dCursorGraphicTable *vtable;
};

/* Lazily resolved message name (identifier word, then the name text). */
typedef struct W3dCachedMessage {
    unsigned int value;
    const char *name;
} W3dCachedMessage;

typedef struct W3dWalkingPayloadLogicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x24 - 0x6];
    W3dVec3 target_024;
    W3dVec3 position_030;
    unsigned char unknown_03c[0xc0 - 0x3c];
    void * resource_0c0;
    unsigned char unknown_0c4[0x134 - 0xc4];
    int walking_134;
    W3dVec3 walk_origin_138;
    int value_144;
} W3dWalkingPayloadLogicEntity;
extern W3dSharedList w3d_walking_payload_logic_entity_list_80361470;

typedef struct W3dWaterRipplesGraphicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x3a0 - 0x6];
    W3dInterface * held_3a0;
    W3dInterface * held_3a4;
} W3dWaterRipplesGraphicEntity;
extern W3dSharedList w3d_water_ripples_graphic_entity_list_803614a0;

typedef struct W3dWaterSparklesGraphicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface * held_01c;
    unsigned char unknown_020[0x48 - 0x20];
    W3dInterface * held_048;
} W3dWaterSparklesGraphicEntity;
extern W3dSharedList w3d_water_sparkles_graphic_entity_list_803614d0;

typedef struct W3dWeaponCursorGraphicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dCursorGraphic * held_01c;
    W3dInterface * held_020;
} W3dWeaponCursorGraphicEntity;
extern W3dSharedList w3d_weapon_cursor_graphic_entity_list_80361500;

typedef struct W3dWeaponSelectPanelLogicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface * held_01c;
    W3dInterface * held_020;
    W3dInterface * held_024;
    W3dInterface * held_028;
    W3dInterface * held_02c;
    W3dInterface * held_030;
    W3dInterface * held_034;
    W3dInterface * held_038;
    W3dInterface * held_03c;
    W3dInterface * held_040;
    W3dInterface * held_044;
    unsigned char unknown_048[0x54 - 0x48];
    W3dInterface * held_054;
    W3dInterface * held_058;
    W3dInterface * held_05c;
    W3dInterface * held_060;
    W3dInterface * held_064;
    W3dInterface * held_068;
    W3dInterface * held_06c;
    W3dInterface * held_070;
    W3dInterface * held_074;
    W3dInterface * held_078;
    W3dInterface * held_07c;
    W3dInterface * held_080;
    W3dInterface * held_084;
    W3dInterface * held_088;
    W3dInterface * held_08c;
    W3dInterface * held_090;
    W3dInterface * held_094;
    W3dInterface * held_098;
    W3dInterface * held_09c;
    W3dInterface * held_0a0;
    W3dInterface * held_0a4;
    W3dInterface * held_0a8;
    W3dInterface * held_0ac;
    W3dInterface * held_0b0;
} W3dWeaponSelectPanelLogicEntity;
extern W3dSharedList w3d_weapon_select_panel_logic_entity_list_80361530;

/* WalkingPayloadLogicEntity: registry list 0x80361470, 328 bytes. */
W3dWalkingPayloadLogicEntity *w3d_walking_payload_logic_entity_construct_80129ae8(W3dWalkingPayloadLogicEntity *object);
void w3d_walking_payload_logic_entity_destroy_80129b2c(W3dWalkingPayloadLogicEntity *object, int flags);
void w3d_walking_payload_logic_entity_unlink_801299d0(W3dWalkingPayloadLogicEntity *object);
void w3d_walking_payload_logic_entity_attach_8012a618(W3dWalkingPayloadLogicEntity *object);
void w3d_walking_payload_logic_entity_detach_8012a6bc(W3dWalkingPayloadLogicEntity *object);

W3dSharedList *w3d_walking_payload_logic_entity_list_get_801299c4(void)
{
    return &w3d_walking_payload_logic_entity_list_80361470;
}

void w3d_walking_payload_logic_entity_unlink_801299d0(W3dWalkingPayloadLogicEntity *object)
{
    w3d_owner_list_remove(&w3d_walking_payload_logic_entity_list_80361470, &object->references);
    w3d_walking_payload_logic_entity_list_80361470.count--;
}

W3dWalkingPayloadLogicEntity *w3d_walking_payload_logic_entity_create_80129a14(void)
{
    W3dWalkingPayloadLogicEntity *object = w3d_walking_payload_logic_entity_construct_80129ae8((W3dWalkingPayloadLogicEntity *)w3d_heap_allocate_entry_a(328));
    w3d_state_register(&w3d_walking_payload_logic_entity_list_80361470, object ? &object->references : 0);
    w3d_walking_payload_logic_entity_list_80361470.count++;
    return object;
}

unsigned short w3d_walking_payload_logic_entity_release_80129a74(W3dWalkingPayloadLogicEntity *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_walking_payload_logic_entity_unlink_801299d0(object);
        if (object)
            w3d_walking_payload_logic_entity_destroy_80129b2c(object, 3);
    }
    return remaining;
}

unsigned short w3d_walking_payload_logic_entity_retain_80129ad0(W3dWalkingPayloadLogicEntity *object)
{
    return object->references++;
}

void w3d_walking_payload_logic_entity_destroy_80129b2c(W3dWalkingPayloadLogicEntity *object, int flags)
{
    object->vtable = w3d_walking_payload_logic_entity_vtable_80410cd0;
    w3d_base_destroy_800ea324(object, flags);
}

int w3d_walking_payload_logic_entity_handle_message_80129b5c(W3dWalkingPayloadLogicEntity *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_800ea62c(object, message) >= 0) {
            w3d_walking_payload_logic_entity_attach_8012a618(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_walking_payload_logic_entity_detach_8012a6bc(object);
        break;
    }
    return w3d_base_handle_message_800ea62c(object, message);
}

/* WaterRipplesGraphicEntity: registry list 0x803614a0, 944 bytes. */
W3dWaterRipplesGraphicEntity *w3d_water_ripples_graphic_entity_construct_8012a938(W3dWaterRipplesGraphicEntity *object);
void w3d_water_ripples_graphic_entity_destroy_8012a980(W3dWaterRipplesGraphicEntity *object, int flags);
void w3d_water_ripples_graphic_entity_unlink_8012a820(W3dWaterRipplesGraphicEntity *object);

W3dSharedList *w3d_water_ripples_graphic_entity_list_get_8012a814(void)
{
    return &w3d_water_ripples_graphic_entity_list_803614a0;
}

void w3d_water_ripples_graphic_entity_unlink_8012a820(W3dWaterRipplesGraphicEntity *object)
{
    w3d_owner_list_remove(&w3d_water_ripples_graphic_entity_list_803614a0, &object->references);
    w3d_water_ripples_graphic_entity_list_803614a0.count--;
}

W3dWaterRipplesGraphicEntity *w3d_water_ripples_graphic_entity_create_8012a864(void)
{
    W3dWaterRipplesGraphicEntity *object = w3d_water_ripples_graphic_entity_construct_8012a938((W3dWaterRipplesGraphicEntity *)w3d_heap_allocate_entry_a(944));
    w3d_state_register(&w3d_water_ripples_graphic_entity_list_803614a0, object ? &object->references : 0);
    w3d_water_ripples_graphic_entity_list_803614a0.count++;
    return object;
}

unsigned short w3d_water_ripples_graphic_entity_release_8012a8c4(W3dWaterRipplesGraphicEntity *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_water_ripples_graphic_entity_unlink_8012a820(object);
        if (object)
            w3d_water_ripples_graphic_entity_destroy_8012a980(object, 3);
    }
    return remaining;
}

unsigned short w3d_water_ripples_graphic_entity_retain_8012a920(W3dWaterRipplesGraphicEntity *object)
{
    return object->references++;
}

void w3d_water_ripples_graphic_entity_destroy_8012a980(W3dWaterRipplesGraphicEntity *object, int flags)
{
    object->vtable = w3d_water_ripples_graphic_entity_vtable_80410d40;
    if (object->held_3a4)
        object->held_3a4->vtable->release(object->held_3a4);
    if (object->held_3a0)
        object->held_3a0->vtable->release(object->held_3a0);
    w3d_base_destroy_8015ff2c(object, flags);
}

/* WaterSparklesGraphicEntity: registry list 0x803614d0, 76 bytes. */
W3dWaterSparklesGraphicEntity *w3d_water_sparkles_graphic_entity_construct_8012b1c0(W3dWaterSparklesGraphicEntity *object);
void w3d_water_sparkles_graphic_entity_destroy_8012b208(W3dWaterSparklesGraphicEntity *object, int flags);
void w3d_water_sparkles_graphic_entity_unlink_8012b0a8(W3dWaterSparklesGraphicEntity *object);
void w3d_water_sparkles_graphic_entity_attach_8012b870(W3dWaterSparklesGraphicEntity *object);
void w3d_water_sparkles_graphic_entity_detach_8012ba08(W3dWaterSparklesGraphicEntity *object);

W3dSharedList *w3d_water_sparkles_graphic_entity_list_get_8012b09c(void)
{
    return &w3d_water_sparkles_graphic_entity_list_803614d0;
}

void w3d_water_sparkles_graphic_entity_unlink_8012b0a8(W3dWaterSparklesGraphicEntity *object)
{
    w3d_owner_list_remove(&w3d_water_sparkles_graphic_entity_list_803614d0, &object->references);
    w3d_water_sparkles_graphic_entity_list_803614d0.count--;
}

W3dWaterSparklesGraphicEntity *w3d_water_sparkles_graphic_entity_create_8012b0ec(void)
{
    W3dWaterSparklesGraphicEntity *object = w3d_water_sparkles_graphic_entity_construct_8012b1c0((W3dWaterSparklesGraphicEntity *)w3d_heap_allocate_entry_a(76));
    w3d_state_register(&w3d_water_sparkles_graphic_entity_list_803614d0, object ? &object->references : 0);
    w3d_water_sparkles_graphic_entity_list_803614d0.count++;
    return object;
}

unsigned short w3d_water_sparkles_graphic_entity_release_8012b14c(W3dWaterSparklesGraphicEntity *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_water_sparkles_graphic_entity_unlink_8012b0a8(object);
        if (object)
            w3d_water_sparkles_graphic_entity_destroy_8012b208(object, 3);
    }
    return remaining;
}

unsigned short w3d_water_sparkles_graphic_entity_retain_8012b1a8(W3dWaterSparklesGraphicEntity *object)
{
    return object->references++;
}

void w3d_water_sparkles_graphic_entity_destroy_8012b208(W3dWaterSparklesGraphicEntity *object, int flags)
{
    object->vtable = w3d_water_sparkles_graphic_entity_vtable_80410d80;
    if (object->held_048)
        object->held_048->vtable->release(object->held_048);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_water_sparkles_graphic_entity_handle_message_8012b284(W3dWaterSparklesGraphicEntity *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_water_sparkles_graphic_entity_attach_8012b870(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_water_sparkles_graphic_entity_detach_8012ba08(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

/* WeaponCursorGraphicEntity: registry list 0x80361500, 36 bytes. */
W3dWeaponCursorGraphicEntity *w3d_weapon_cursor_graphic_entity_construct_8012bbbc(W3dWeaponCursorGraphicEntity *object);
void w3d_weapon_cursor_graphic_entity_destroy_8012bc04(W3dWeaponCursorGraphicEntity *object, int flags);
void w3d_weapon_cursor_graphic_entity_unlink_8012baa4(W3dWeaponCursorGraphicEntity *object);
void w3d_weapon_cursor_graphic_entity_attach_8012bd78(W3dWeaponCursorGraphicEntity *object);
void w3d_weapon_cursor_graphic_entity_detach_8012bee4(W3dWeaponCursorGraphicEntity *object);

W3dSharedList *w3d_weapon_cursor_graphic_entity_list_get_8012ba98(void)
{
    return &w3d_weapon_cursor_graphic_entity_list_80361500;
}

void w3d_weapon_cursor_graphic_entity_unlink_8012baa4(W3dWeaponCursorGraphicEntity *object)
{
    w3d_owner_list_remove(&w3d_weapon_cursor_graphic_entity_list_80361500, &object->references);
    w3d_weapon_cursor_graphic_entity_list_80361500.count--;
}

W3dWeaponCursorGraphicEntity *w3d_weapon_cursor_graphic_entity_create_8012bae8(void)
{
    W3dWeaponCursorGraphicEntity *object = w3d_weapon_cursor_graphic_entity_construct_8012bbbc((W3dWeaponCursorGraphicEntity *)w3d_heap_allocate_entry_a(36));
    w3d_state_register(&w3d_weapon_cursor_graphic_entity_list_80361500, object ? &object->references : 0);
    w3d_weapon_cursor_graphic_entity_list_80361500.count++;
    return object;
}

unsigned short w3d_weapon_cursor_graphic_entity_release_8012bb48(W3dWeaponCursorGraphicEntity *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_weapon_cursor_graphic_entity_unlink_8012baa4(object);
        if (object)
            w3d_weapon_cursor_graphic_entity_destroy_8012bc04(object, 3);
    }
    return remaining;
}

unsigned short w3d_weapon_cursor_graphic_entity_retain_8012bba4(W3dWeaponCursorGraphicEntity *object)
{
    return object->references++;
}

void w3d_weapon_cursor_graphic_entity_destroy_8012bc04(W3dWeaponCursorGraphicEntity *object, int flags)
{
    object->vtable = w3d_weapon_cursor_graphic_entity_vtable_80410dc0;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_weapon_cursor_graphic_entity_handle_message_8012bc80(W3dWeaponCursorGraphicEntity *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_weapon_cursor_graphic_entity_attach_8012bd78(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_weapon_cursor_graphic_entity_detach_8012bee4(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

/* WeaponSelectPanelLogicEntity: registry list 0x80361530, 216 bytes. */
W3dWeaponSelectPanelLogicEntity *w3d_weapon_select_panel_logic_entity_construct_8012c098(W3dWeaponSelectPanelLogicEntity *object);
void w3d_weapon_select_panel_logic_entity_destroy_8012c348(W3dWeaponSelectPanelLogicEntity *object, int flags);
void w3d_weapon_select_panel_logic_entity_unlink_8012bf80(W3dWeaponSelectPanelLogicEntity *object);

W3dSharedList *w3d_weapon_select_panel_logic_entity_list_get_8012bf74(void)
{
    return &w3d_weapon_select_panel_logic_entity_list_80361530;
}

void w3d_weapon_select_panel_logic_entity_unlink_8012bf80(W3dWeaponSelectPanelLogicEntity *object)
{
    w3d_owner_list_remove(&w3d_weapon_select_panel_logic_entity_list_80361530, &object->references);
    w3d_weapon_select_panel_logic_entity_list_80361530.count--;
}

W3dWeaponSelectPanelLogicEntity *w3d_weapon_select_panel_logic_entity_create_8012bfc4(void)
{
    W3dWeaponSelectPanelLogicEntity *object = w3d_weapon_select_panel_logic_entity_construct_8012c098((W3dWeaponSelectPanelLogicEntity *)w3d_heap_allocate_entry_a(216));
    w3d_state_register(&w3d_weapon_select_panel_logic_entity_list_80361530, object ? &object->references : 0);
    w3d_weapon_select_panel_logic_entity_list_80361530.count++;
    return object;
}

unsigned short w3d_weapon_select_panel_logic_entity_release_8012c024(W3dWeaponSelectPanelLogicEntity *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_weapon_select_panel_logic_entity_unlink_8012bf80(object);
        if (object)
            w3d_weapon_select_panel_logic_entity_destroy_8012c348(object, 3);
    }
    return remaining;
}

unsigned short w3d_weapon_select_panel_logic_entity_retain_8012c080(W3dWeaponSelectPanelLogicEntity *object)
{
    return object->references++;
}

void w3d_weapon_select_panel_logic_entity_destroy_8012c348(W3dWeaponSelectPanelLogicEntity *object, int flags)
{
    object->vtable = w3d_weapon_select_panel_logic_entity_vtable_80410e00;
    w3d_weapon_select_panel_logic_entity_instance_804ab0cc = 0;
    if (object->held_0b0)
        object->held_0b0->vtable->release(object->held_0b0);
    if (object->held_0ac)
        object->held_0ac->vtable->release(object->held_0ac);
    if (object->held_0a8)
        object->held_0a8->vtable->release(object->held_0a8);
    if (object->held_0a4)
        object->held_0a4->vtable->release(object->held_0a4);
    if (object->held_0a0)
        object->held_0a0->vtable->release(object->held_0a0);
    if (object->held_09c)
        object->held_09c->vtable->release(object->held_09c);
    if (object->held_098)
        object->held_098->vtable->release(object->held_098);
    if (object->held_094)
        object->held_094->vtable->release(object->held_094);
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
    if (object->held_028)
        object->held_028->vtable->release(object->held_028);
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_actor_base_destroy(object, flags);
}


/* ---- Hand-recovered members ---- */

typedef struct W3dDevice W3dDevice;
typedef struct W3dDeviceTable {
    void *unknown_00[21];
    void (*set_mode_54)(W3dDevice *device, int mode);
    void *unknown_58[9];
    void (*set_sound_mode_7c)(W3dDevice *device, int mode);
    void (*set_flag_80)(W3dDevice *device, int flag);
} W3dDeviceTable;
struct W3dDevice {
    W3dDeviceTable *vtable;
};

typedef struct W3dApplication {
    unsigned char unknown_00[0x6c];
    W3dDevice *audio_06c;
    unsigned char unknown_70[0x74 - 0x70];
    W3dDevice *display_074;
    unsigned char unknown_78[0xb4 - 0x78];
    int sound_mode_0b4;
} W3dApplication;

struct W3dVec3c {
    float x, y, z;
    W3dVec3c(float a, float b, float c) { x = a; y = b; z = c; }
};

typedef struct W3dFloatPair {
    float x, y;
} W3dFloatPair;

typedef struct W3dWalkInfo {
    unsigned char unknown_00[0xdc];
    float height_0dc;
} W3dWalkInfo;

extern W3dApplication *w3d_application_804b1788;
extern const char w3d_str_8039c994[];
extern unsigned char w3d_data_8039cff0[];
extern const float w3d_f32_8039d228[];
extern const float w3d_f32_8039d22c[];
extern W3dCachedMessage w3d_msg_804af608;

int w3d_sound_mode_802ff730(void);
int w3d_save_set_int_800fc43c(const char **key, int value);
int w3d_video_mode_802ff854(void);
void w3d_options_select_80127ba0(W3dApplication *object, int mode);
void w3d_app_enter_8015cc24(W3dApplication *object);
void w3d_app_leave_8015cc64(W3dApplication *object);
int w3d_app_is_active_8015ccbc(W3dApplication *object);
void *w3d_empty_80341584(void *resource);
W3dWalkInfo *w3d_resource_info_801797b4(void *resource);
void w3d_entity_set_target_800eac84(void *object, W3dVec3 *target);
void w3d_entity_update_800eb6e4(void *object);
void w3d_entity_update_800ed090(void *object);
void w3d_entity_update_800edca0(void *object);
int w3d_base_construct_800ea180(void *object);
int w3d_base_construct_8015fef0(void *object);
int w3d_message_is_8015f620(W3dCachedMessage *message, unsigned short id);
W3dVec3 *w3d_vec_message_value_80126034(W3dMessage *message);
int w3d_base_handle_message_8015fb34(void *object, W3dMessage *message);
int w3d_cursor_state_80178d1c(void *object);
void *w3d_constructor_native_cast(void *object);
void w3d_entity_update_8015fb2c(void *object, void *argument);

void w3d_audio_set_mode5_80129738(void)
{
    w3d_application_804b1788->audio_06c->vtable->set_mode_54(w3d_application_804b1788->audio_06c, 5);
}

void w3d_options_apply_sound_mode_80129770(W3dApplication *object)
{
    int mode;
    const char *key;
    object->sound_mode_0b4 = 0;
    mode = w3d_sound_mode_802ff730();
    if (mode == 0)
        object->sound_mode_0b4 = mode;
    else if (mode == 1)
        object->sound_mode_0b4 = mode;
    key = w3d_str_8039c994;
    w3d_save_set_int_800fc43c(&key, object->sound_mode_0b4);
    w3d_application_804b1788->audio_06c->vtable->set_sound_mode_7c(w3d_application_804b1788->audio_06c, object->sound_mode_0b4);
}

void w3d_options_apply_video_mode_801297ec(W3dApplication *object)
{
    int mode;
    switch (w3d_video_mode_802ff854()) {
    case 1:
        mode = 4;
        break;
    case 2:
        mode = 3;
        break;
    case 3:
        mode = 9;
        break;
    case 4:
        mode = 5;
        break;
    case 0:
    default:
        mode = 0;
        break;
    }
    w3d_options_select_80127ba0(object, mode);
}

void w3d_app_enter_80129878(W3dApplication *object)
{
    w3d_app_enter_8015cc24(object);
    if (w3d_app_is_active_8015ccbc(object))
        object->display_074->vtable->set_flag_80(object->display_074, 1);
}

void w3d_app_leave_801298cc(W3dApplication *object)
{
    w3d_app_leave_8015cc64(object);
    if (!w3d_app_is_active_8015ccbc(object))
        object->display_074->vtable->set_flag_80(object->display_074, 0);
}

unsigned char *w3d_options_table_801299b8(void)
{
    return w3d_data_8039cff0;
}

W3dWalkingPayloadLogicEntity *w3d_walking_payload_logic_entity_construct_80129ae8(W3dWalkingPayloadLogicEntity *object)
{
    w3d_base_construct_800ea180(object);
        object->vtable = w3d_walking_payload_logic_entity_vtable_80410cd0;
    object->value_144 = 0;
        return object;
}

#if 0 /* 0x8012a618: code matches but the original frame is 8 bytes larger; dead-vector and struct-local variants tried. */
void w3d_walking_payload_logic_entity_attach_8012a618(W3dWalkingPayloadLogicEntity *object)
{
    w3d_resource_info_801797b4(w3d_empty_80341584(object->resource_0c0));
    object->walking_134 = 1;
    W3dFloatPair level;
    level.x = w3d_f32_8039d228[0];
    object->walk_origin_138 = object->position_030;
    object->walk_origin_138.y = level.x;
    w3d_entity_set_target_800eac84(object, &object->target_024);
    w3d_entity_update_800eb6e4(object);
    W3dVec3c unused(level.x, level.x, level.x);
    w3d_entity_update_800ed090(object);
    w3d_entity_update_800edca0(object);
}
#endif

void w3d_walking_payload_logic_entity_detach_8012a6bc(W3dWalkingPayloadLogicEntity *object)
{
}

void w3d_walking_payload_logic_entity_get_offset_8012a6c0(W3dWalkingPayloadLogicEntity *object, int unused, W3dVec3 *out)
{
    W3dWalkInfo *info = w3d_resource_info_801797b4(w3d_empty_80341584(object->resource_0c0));
    W3dVec3c offset(w3d_f32_8039d22c[0], info->height_0dc, w3d_f32_8039d22c[0]);
    *out = *(W3dVec3 *)&offset;
}

W3dWaterRipplesGraphicEntity *w3d_water_ripples_graphic_entity_construct_8012a938(W3dWaterRipplesGraphicEntity *object)
{
    w3d_base_construct_8015fef0(object);
        object->vtable = w3d_water_ripples_graphic_entity_vtable_80410d40;
    object->held_3a0 = 0;
    object->held_3a4 = 0;
        return object;
}

void w3d_water_ripples_graphic_entity_attach_8012aec0(W3dWaterRipplesGraphicEntity *object);
void w3d_water_ripples_graphic_entity_detach_8012affc(W3dWaterRipplesGraphicEntity *object);
void w3d_water_ripples_graphic_entity_add_ripple_8012ad58(W3dWaterRipplesGraphicEntity *object, W3dVec3 *position);

int w3d_water_ripples_graphic_entity_handle_message_8012a9fc(W3dWaterRipplesGraphicEntity *object, W3dMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_water_ripples_graphic_entity_attach_8012aec0(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_water_ripples_graphic_entity_detach_8012affc(object);
        break;
    default:
        if (w3d_message_is_8015f620(&w3d_msg_804af608, message->id))
            w3d_water_ripples_graphic_entity_add_ripple_8012ad58(object, w3d_vec_message_value_80126034(message));
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

void w3d_water_ripples_graphic_entity_detach_8012affc(W3dWaterRipplesGraphicEntity *object)
{
}

W3dWaterSparklesGraphicEntity *w3d_water_sparkles_graphic_entity_construct_8012b1c0(W3dWaterSparklesGraphicEntity *object)
{
    w3d_base_construct_8015fef0(object);
        object->vtable = w3d_water_sparkles_graphic_entity_vtable_80410d80;
    object->held_01c = 0;
    object->held_048 = 0;
        return object;
}

void w3d_water_sparkles_graphic_entity_detach_8012ba08(W3dWaterSparklesGraphicEntity *object)
{
}

W3dWeaponCursorGraphicEntity *w3d_weapon_cursor_graphic_entity_construct_8012bbbc(W3dWeaponCursorGraphicEntity *object)
{
    w3d_base_construct_8015fef0(object);
        object->vtable = w3d_weapon_cursor_graphic_entity_vtable_80410dc0;
    object->held_01c = 0;
    object->held_020 = 0;
        return object;
}

#if 0 /* 0x8012bd08: interface and vtable registers (r11/r9) are swapped; 3 variants tried. */
int w3d_weapon_cursor_graphic_entity_update_8012bd08(W3dWeaponCursorGraphicEntity *object, void *argument)
{
    int state = w3d_cursor_state_80178d1c(w3d_constructor_native_cast(object->held_020));
    object->held_01c->vtable->set_visible_58(object->held_01c, state == 2 ? 0 : 1);
    w3d_entity_update_8015fb2c(object, argument);
    return 0;
}
#endif

void w3d_weapon_cursor_graphic_entity_detach_8012bee4(W3dWeaponCursorGraphicEntity *object)
{
}

/* ---- WeaponSelectPanelLogicEntity helpers ---- */
typedef struct W3dPanelState {
    unsigned char unknown_00[0x40];
    void *selector_040;
    void *selector_044;
    unsigned char unknown_48[0x4c - 0x48];
    int dirty_04c;
} W3dPanelState;

extern int w3d_weapon_layout_803fd9e4[];
extern unsigned char w3d_weapon_flags_80451a9c[];
extern const char w3d_str_8039d9b0[];
extern const char w3d_str_8039daa4[];
extern const char w3d_str_8039dac4[];
extern W3dPanelState *w3d_weapon_select_panel_instance_804ab0cc;
extern int w3d_weapon_select_panel_mode_804ab0d0;

void w3d_weapon_select_panel_refresh_8012f77c(W3dPanelState *object);
int w3d_selector_set_80178d28(void *selector, int *value);

int w3d_weapon_layout_row_start_8012c768(void *object, unsigned int row)
{
    unsigned int i = 0;
    int index = 0;
    for (; row > i; i++) {
        while (w3d_weapon_layout_803fd9e4[index] != 60)
            index++;
        index++;
    }
    return index;
}

void w3d_weapon_select_panel_refresh_if_dirty_8012d894(W3dPanelState *object)
{
    if (object->dirty_04c)
        w3d_weapon_select_panel_refresh_8012f77c(object);
}

const char *w3d_weapon_select_panel_reason_text_8012f0f8(void *object, int reason)
{
    switch (reason) {
    case 4:
    case 7:
    case 18:
    case 23:
    case 24:
    case 33:
    case 48:
        break;
    case 13:
    case 41:
    case 42:
        return w3d_str_8039daa4;
    default:
        return w3d_str_8039dac4;
    }
    return w3d_str_8039d9b0;
}

unsigned char w3d_weapon_flags_8012f954(int weapon)
{
    return w3d_weapon_flags_80451a9c[weapon];
}

typedef void (*W3dSelectorSetRef)(void *selector, const int &value);
#define w3d_selector_set_ref ((W3dSelectorSetRef)w3d_selector_set_80178d28)

void w3d_weapon_select_panel_set_mode_8012f964(int mode)
{
    if (mode != w3d_weapon_select_panel_mode_804ab0d0) {
        w3d_weapon_select_panel_mode_804ab0d0 = mode;
        switch (mode) {
        case 0:
            w3d_selector_set_ref(w3d_weapon_select_panel_instance_804ab0cc->selector_040, 1);
            w3d_selector_set_ref(w3d_weapon_select_panel_instance_804ab0cc->selector_044, 1);
            break;
        case 1:
            w3d_selector_set_ref(w3d_weapon_select_panel_instance_804ab0cc->selector_040, 1);
            w3d_selector_set_ref(w3d_weapon_select_panel_instance_804ab0cc->selector_044, 0);
            break;
        case 2:
            w3d_selector_set_ref(w3d_weapon_select_panel_instance_804ab0cc->selector_040, 0);
            w3d_selector_set_ref(w3d_weapon_select_panel_instance_804ab0cc->selector_044, 0);
            break;
        }
    }
}

}
