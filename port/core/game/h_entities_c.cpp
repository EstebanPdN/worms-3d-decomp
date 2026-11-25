#include "w3d_ptr.h"
#line 1 "h_entities_c.cpp"
/* Registry-list plumbing for the remaining entity and service types in
 * 0x8012fed0..0x80165400: WindMeterEntity, WormGraphicEntity,
 * WormHealthNameEntity, WormManagerService, WormSelectLogicEntity,
 * ZCamUpdateFudgeService, TelnetService, Entity, InputService, LogicEntity,
 * MessageRegistrationService, Service and TimerService.
 *
 * Names are inferred from behavior and from the type-name strings registered
 * by the static initializers; no original symbols survive. Each type follows
 * the registry-list shape described in h_entities_a.cpp; only the list
 * getter, unlink, create, release, retain, destructor and standard message
 * handler are recovered here.
 */
extern "C" {

typedef struct W3dSharedList {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dSharedList;

typedef struct W3dMessage {
    unsigned short id;
} W3dMessage;

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    Ptr32<void> unknown_00[4];
    Ptr32<void (Ptr32<W3dInterface>)> release;
} W3dInterfaceTable;

struct W3dInterface {
    Ptr32<W3dInterfaceTable> vtable;
};

/* Engine string: one pointer to text behind a small header. */
typedef struct W3dString {
    Ptr32<char> data;
} W3dString;

/* Embedded handle member (constructed and destroyed out of line). */
typedef struct W3dMember {
    unsigned char unknown_00[4];
} W3dMember;

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_string_base_finish(Ptr32<W3dString> string);
void w3d_string_release(Ptr32<W3dString> string);

extern Ptr32<const void> w3d_entity_vtable_804115c8[];
extern Ptr32<const void> w3d_input_service_vtable_804116a8[];
extern Ptr32<const void> w3d_service_vtable_80411828[];
extern Ptr32<const void> w3d_timer_service_vtable_80411970[];
extern Ptr32<const void> w3d_wind_meter_entity_vtable_80410e40[];
extern Ptr32<const void> w3d_worm_health_name_entity_vtable_80410ec0[];
extern Ptr32<const void> w3d_zcam_update_fudge_service_vtable_80410fc0[];
int w3d_base_handle_message_8015fb34(Ptr32<void> object, Ptr32<W3dMessage> message);
Ptr32<void> w3d_actor_base_initialize(Ptr32<void> object);
Ptr32<void> w3d_base_construct_8015fef0(Ptr32<void> object);
void w3d_actor_base_destroy(Ptr32<void> object, int flags);
void w3d_base_destroy_8015fa94(Ptr32<void> object, int flags);
void w3d_base_destroy_8015ff2c(Ptr32<void> object, int flags);
void w3d_base_destroy_801628ec(Ptr32<void> object, int flags);


typedef struct W3dWindMeterEntity {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    unsigned char unknown_020[0x24 - 0x20];
    Ptr32<W3dInterface> held_024;
    Ptr32<W3dInterface> held_028;
    Ptr32<W3dInterface> held_02c;
    Ptr32<W3dInterface> held_030;
    Ptr32<W3dInterface> held_034;
    Ptr32<W3dInterface> held_038;
    unsigned char unknown_03c[0x48 - 0x3c];
    Ptr32<W3dInterface> held_048;
    Ptr32<W3dInterface> held_04c;
    unsigned char unknown_050[0x68 - 0x50];
    Ptr32<W3dInterface> held_068;
    unsigned char unknown_06c[0x78 - 0x6c];
    Ptr32<W3dInterface> held_078;
    Ptr32<W3dInterface> held_07c;
    Ptr32<W3dInterface> held_080;
    Ptr32<W3dInterface> held_084;
    Ptr32<W3dInterface> held_088;
    Ptr32<W3dInterface> held_08c;
    Ptr32<W3dInterface> held_090;
    Ptr32<W3dInterface> held_094;
    Ptr32<W3dInterface> held_098;
} W3dWindMeterEntity;
extern W3dSharedList w3d_wind_meter_entity_list_80361560;

typedef struct W3dWormGraphicEntity {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dWormGraphicEntity;
extern W3dSharedList w3d_worm_graphic_entity_list_80361590;

typedef struct W3dWormHealthNameEntity {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x30 - 0x6];
    Ptr32<W3dInterface> held_030;
} W3dWormHealthNameEntity;
extern W3dSharedList w3d_worm_health_name_entity_list_803615c0;

typedef struct W3dWormManagerService {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dWormManagerService;
extern W3dSharedList w3d_worm_manager_service_list_80454118;

typedef struct W3dWormSelectLogicEntity {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dWormSelectLogicEntity;
extern W3dSharedList w3d_worm_select_logic_entity_list_80361620;

typedef struct W3dZCamUpdateFudgeService {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dZCamUpdateFudgeService;
extern W3dSharedList w3d_zcam_update_fudge_service_list_80361650;

typedef struct W3dTelnetService {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dTelnetService;
extern W3dSharedList w3d_telnet_service_list_80361680;

typedef struct W3dEntity {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dEntity;
extern W3dSharedList w3d_entity_list_803617d0;

typedef struct W3dInputService {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
} W3dInputService;
extern W3dSharedList w3d_input_service_list_80361830;

typedef struct W3dLogicEntity {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dLogicEntity;
extern W3dSharedList w3d_logic_entity_list_80361860;

typedef struct W3dMessageRegistrationService {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dMessageRegistrationService;
extern W3dSharedList w3d_message_registration_service_list_803618c0;

typedef struct W3dService {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dService;
extern W3dSharedList w3d_service_list_803618f0;

typedef struct W3dTimerService {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dTimerService;
extern W3dSharedList w3d_timer_service_list_80361980;

/* WindMeterEntity: registry list 0x80361560, 156 bytes. */
Ptr32<W3dWindMeterEntity> w3d_wind_meter_entity_construct_8012fff4(Ptr32<W3dWindMeterEntity> object);
void w3d_wind_meter_entity_destroy_801300c8(Ptr32<W3dWindMeterEntity> object, int flags);
void w3d_wind_meter_entity_unlink_8012fedc(Ptr32<W3dWindMeterEntity> object);

Ptr32<W3dSharedList> w3d_wind_meter_entity_list_get_8012fed0(void)
{
    return &w3d_wind_meter_entity_list_80361560;
}

void w3d_wind_meter_entity_unlink_8012fedc(Ptr32<W3dWindMeterEntity> object)
{
    w3d_owner_list_remove(&w3d_wind_meter_entity_list_80361560, &object->references);
    w3d_wind_meter_entity_list_80361560.count--;
}

Ptr32<W3dWindMeterEntity> w3d_wind_meter_entity_create_8012ff20(void)
{
    Ptr32<W3dWindMeterEntity> object = w3d_wind_meter_entity_construct_8012fff4((Ptr32<W3dWindMeterEntity>)w3d_heap_allocate_entry_a(156));
    w3d_state_register(&w3d_wind_meter_entity_list_80361560, object ? w3d::R(&object->references) : 0);
    w3d_wind_meter_entity_list_80361560.count++;
    return object;
}

unsigned short w3d_wind_meter_entity_release_8012ff80(Ptr32<W3dWindMeterEntity> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_wind_meter_entity_unlink_8012fedc(object);
        if (object)
            w3d_wind_meter_entity_destroy_801300c8(object, 3);
    }
    return remaining;
}

unsigned short w3d_wind_meter_entity_retain_8012ffdc(Ptr32<W3dWindMeterEntity> object)
{
    return object->references++;
}

void w3d_wind_meter_entity_destroy_801300c8(Ptr32<W3dWindMeterEntity> object, int flags)
{
    object->vtable = w3d_wind_meter_entity_vtable_80410e40;
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
    if (object->held_068)
        object->held_068->vtable->release(object->held_068);
    if (object->held_04c)
        object->held_04c->vtable->release(object->held_04c);
    if (object->held_048)
        object->held_048->vtable->release(object->held_048);
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
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

/* WormGraphicEntity: registry list 0x80361590, 748 bytes. */
Ptr32<W3dWormGraphicEntity> w3d_worm_graphic_entity_construct_80131d44(Ptr32<W3dWormGraphicEntity> object);
void w3d_worm_graphic_entity_destroy_801320c8(Ptr32<W3dWormGraphicEntity> object, int flags);
void w3d_worm_graphic_entity_unlink_80131c2c(Ptr32<W3dWormGraphicEntity> object);

Ptr32<W3dSharedList> w3d_worm_graphic_entity_list_get_80131c20(void)
{
    return &w3d_worm_graphic_entity_list_80361590;
}

void w3d_worm_graphic_entity_unlink_80131c2c(Ptr32<W3dWormGraphicEntity> object)
{
    w3d_owner_list_remove(&w3d_worm_graphic_entity_list_80361590, &object->references);
    w3d_worm_graphic_entity_list_80361590.count--;
}

Ptr32<W3dWormGraphicEntity> w3d_worm_graphic_entity_create_80131c70(void)
{
    Ptr32<W3dWormGraphicEntity> object = w3d_worm_graphic_entity_construct_80131d44((Ptr32<W3dWormGraphicEntity>)w3d_heap_allocate_entry_a(748));
    w3d_state_register(&w3d_worm_graphic_entity_list_80361590, object ? w3d::R(&object->references) : 0);
    w3d_worm_graphic_entity_list_80361590.count++;
    return object;
}

unsigned short w3d_worm_graphic_entity_release_80131cd0(Ptr32<W3dWormGraphicEntity> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_worm_graphic_entity_unlink_80131c2c(object);
        if (object)
            w3d_worm_graphic_entity_destroy_801320c8(object, 3);
    }
    return remaining;
}

unsigned short w3d_worm_graphic_entity_retain_80131d2c(Ptr32<W3dWormGraphicEntity> object)
{
    return object->references++;
}

/* WormHealthNameEntity: registry list 0x803615c0, 52 bytes. */
Ptr32<W3dWormHealthNameEntity> w3d_worm_health_name_entity_construct_80140940(Ptr32<W3dWormHealthNameEntity> object);
void w3d_worm_health_name_entity_destroy_80140998(Ptr32<W3dWormHealthNameEntity> object, int flags);
void w3d_worm_health_name_entity_unlink_80140828(Ptr32<W3dWormHealthNameEntity> object);

Ptr32<W3dSharedList> w3d_worm_health_name_entity_list_get_8014081c(void)
{
    return &w3d_worm_health_name_entity_list_803615c0;
}

void w3d_worm_health_name_entity_unlink_80140828(Ptr32<W3dWormHealthNameEntity> object)
{
    w3d_owner_list_remove(&w3d_worm_health_name_entity_list_803615c0, &object->references);
    w3d_worm_health_name_entity_list_803615c0.count--;
}

Ptr32<W3dWormHealthNameEntity> w3d_worm_health_name_entity_create_8014086c(void)
{
    Ptr32<W3dWormHealthNameEntity> object = w3d_worm_health_name_entity_construct_80140940((Ptr32<W3dWormHealthNameEntity>)w3d_heap_allocate_entry_a(52));
    w3d_state_register(&w3d_worm_health_name_entity_list_803615c0, object ? w3d::R(&object->references) : 0);
    w3d_worm_health_name_entity_list_803615c0.count++;
    return object;
}

unsigned short w3d_worm_health_name_entity_release_801408cc(Ptr32<W3dWormHealthNameEntity> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_worm_health_name_entity_unlink_80140828(object);
        if (object)
            w3d_worm_health_name_entity_destroy_80140998(object, 3);
    }
    return remaining;
}

unsigned short w3d_worm_health_name_entity_retain_80140928(Ptr32<W3dWormHealthNameEntity> object)
{
    return object->references++;
}

void w3d_worm_health_name_entity_destroy_80140998(Ptr32<W3dWormHealthNameEntity> object, int flags)
{
    object->vtable = w3d_worm_health_name_entity_vtable_80410ec0;
    if (object->held_030)
        object->held_030->vtable->release(object->held_030);
    w3d_base_destroy_8015ff2c(object, flags);
}

/* WormManagerService: registry list 0x80454118, 424 bytes. */
Ptr32<W3dWormManagerService> w3d_worm_manager_service_construct_80154918(Ptr32<W3dWormManagerService> object);
void w3d_worm_manager_service_destroy_80154aa8(Ptr32<W3dWormManagerService> object, int flags);
void w3d_worm_manager_service_unlink_80154800(Ptr32<W3dWormManagerService> object);

Ptr32<W3dSharedList> w3d_worm_manager_service_list_get_801547f4(void)
{
    return &w3d_worm_manager_service_list_80454118;
}

void w3d_worm_manager_service_unlink_80154800(Ptr32<W3dWormManagerService> object)
{
    w3d_owner_list_remove(&w3d_worm_manager_service_list_80454118, &object->references);
    w3d_worm_manager_service_list_80454118.count--;
}

Ptr32<W3dWormManagerService> w3d_worm_manager_service_create_80154844(void)
{
    Ptr32<W3dWormManagerService> object = w3d_worm_manager_service_construct_80154918((Ptr32<W3dWormManagerService>)w3d_heap_allocate_entry_a(424));
    w3d_state_register(&w3d_worm_manager_service_list_80454118, object ? w3d::R(&object->references) : 0);
    w3d_worm_manager_service_list_80454118.count++;
    return object;
}

unsigned short w3d_worm_manager_service_release_801548a4(Ptr32<W3dWormManagerService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_worm_manager_service_unlink_80154800(object);
        if (object)
            w3d_worm_manager_service_destroy_80154aa8(object, 3);
    }
    return remaining;
}

unsigned short w3d_worm_manager_service_retain_80154900(Ptr32<W3dWormManagerService> object)
{
    return object->references++;
}

/* WormSelectLogicEntity: registry list 0x80361620, 76 bytes. */
Ptr32<W3dWormSelectLogicEntity> w3d_worm_select_logic_entity_construct_801594bc(Ptr32<W3dWormSelectLogicEntity> object);
void w3d_worm_select_logic_entity_destroy_80159538(Ptr32<W3dWormSelectLogicEntity> object, int flags);
void w3d_worm_select_logic_entity_unlink_801593a4(Ptr32<W3dWormSelectLogicEntity> object);

Ptr32<W3dSharedList> w3d_worm_select_logic_entity_list_get_80159398(void)
{
    return &w3d_worm_select_logic_entity_list_80361620;
}

void w3d_worm_select_logic_entity_unlink_801593a4(Ptr32<W3dWormSelectLogicEntity> object)
{
    w3d_owner_list_remove(&w3d_worm_select_logic_entity_list_80361620, &object->references);
    w3d_worm_select_logic_entity_list_80361620.count--;
}

Ptr32<W3dWormSelectLogicEntity> w3d_worm_select_logic_entity_create_801593e8(void)
{
    Ptr32<W3dWormSelectLogicEntity> object = w3d_worm_select_logic_entity_construct_801594bc((Ptr32<W3dWormSelectLogicEntity>)w3d_heap_allocate_entry_a(76));
    w3d_state_register(&w3d_worm_select_logic_entity_list_80361620, object ? w3d::R(&object->references) : 0);
    w3d_worm_select_logic_entity_list_80361620.count++;
    return object;
}

unsigned short w3d_worm_select_logic_entity_release_80159448(Ptr32<W3dWormSelectLogicEntity> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_worm_select_logic_entity_unlink_801593a4(object);
        if (object)
            w3d_worm_select_logic_entity_destroy_80159538(object, 3);
    }
    return remaining;
}

unsigned short w3d_worm_select_logic_entity_retain_801594a4(Ptr32<W3dWormSelectLogicEntity> object)
{
    return object->references++;
}

/* ZCamUpdateFudgeService: registry list 0x80361650, 28 bytes. */
Ptr32<W3dZCamUpdateFudgeService> w3d_zcam_update_fudge_service_construct_80159ef8(Ptr32<W3dZCamUpdateFudgeService> object);
void w3d_zcam_update_fudge_service_destroy_80159f34(Ptr32<W3dZCamUpdateFudgeService> object, int flags);
void w3d_zcam_update_fudge_service_unlink_80159de0(Ptr32<W3dZCamUpdateFudgeService> object);
void w3d_zcam_update_fudge_service_attach_8015a040(Ptr32<W3dZCamUpdateFudgeService> object);
void w3d_zcam_update_fudge_service_detach_8015a044(Ptr32<W3dZCamUpdateFudgeService> object);

Ptr32<W3dSharedList> w3d_zcam_update_fudge_service_list_get_80159dd4(void)
{
    return &w3d_zcam_update_fudge_service_list_80361650;
}

void w3d_zcam_update_fudge_service_unlink_80159de0(Ptr32<W3dZCamUpdateFudgeService> object)
{
    w3d_owner_list_remove(&w3d_zcam_update_fudge_service_list_80361650, &object->references);
    w3d_zcam_update_fudge_service_list_80361650.count--;
}

Ptr32<W3dZCamUpdateFudgeService> w3d_zcam_update_fudge_service_create_80159e24(void)
{
    Ptr32<W3dZCamUpdateFudgeService> object = w3d_zcam_update_fudge_service_construct_80159ef8((Ptr32<W3dZCamUpdateFudgeService>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_zcam_update_fudge_service_list_80361650, object ? w3d::R(&object->references) : 0);
    w3d_zcam_update_fudge_service_list_80361650.count++;
    return object;
}

unsigned short w3d_zcam_update_fudge_service_release_80159e84(Ptr32<W3dZCamUpdateFudgeService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_zcam_update_fudge_service_unlink_80159de0(object);
        if (object)
            w3d_zcam_update_fudge_service_destroy_80159f34(object, 3);
    }
    return remaining;
}

unsigned short w3d_zcam_update_fudge_service_retain_80159ee0(Ptr32<W3dZCamUpdateFudgeService> object)
{
    return object->references++;
}

void w3d_zcam_update_fudge_service_destroy_80159f34(Ptr32<W3dZCamUpdateFudgeService> object, int flags)
{
    object->vtable = w3d_zcam_update_fudge_service_vtable_80410fc0;
    w3d_actor_base_destroy(object, flags);
}

int w3d_zcam_update_fudge_service_handle_message_80159f64(Ptr32<W3dZCamUpdateFudgeService> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_zcam_update_fudge_service_attach_8015a040(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_zcam_update_fudge_service_detach_8015a044(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

/* TelnetService: registry list 0x80361680, 28 bytes. */
Ptr32<W3dTelnetService> w3d_telnet_service_construct_8015b084(Ptr32<W3dTelnetService> object);
void w3d_telnet_service_destroy_8015b0c4(Ptr32<W3dTelnetService> object, int flags);
void w3d_telnet_service_unlink_8015af6c(Ptr32<W3dTelnetService> object);

Ptr32<W3dSharedList> w3d_telnet_service_list_get_8015af60(void)
{
    return &w3d_telnet_service_list_80361680;
}

void w3d_telnet_service_unlink_8015af6c(Ptr32<W3dTelnetService> object)
{
    w3d_owner_list_remove(&w3d_telnet_service_list_80361680, &object->references);
    w3d_telnet_service_list_80361680.count--;
}

Ptr32<W3dTelnetService> w3d_telnet_service_create_8015afb0(void)
{
    Ptr32<W3dTelnetService> object = w3d_telnet_service_construct_8015b084((Ptr32<W3dTelnetService>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_telnet_service_list_80361680, object ? w3d::R(&object->references) : 0);
    w3d_telnet_service_list_80361680.count++;
    return object;
}

unsigned short w3d_telnet_service_release_8015b010(Ptr32<W3dTelnetService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_telnet_service_unlink_8015af6c(object);
        if (object)
            w3d_telnet_service_destroy_8015b0c4(object, 3);
    }
    return remaining;
}

unsigned short w3d_telnet_service_retain_8015b06c(Ptr32<W3dTelnetService> object)
{
    return object->references++;
}

/* Entity: registry list 0x803617d0, 28 bytes. */
void w3d_entity_unlink_8015fdd8(Ptr32<W3dEntity> object);

Ptr32<W3dSharedList> w3d_entity_list_get_8015fdcc(void)
{
    return &w3d_entity_list_803617d0;
}

void w3d_entity_unlink_8015fdd8(Ptr32<W3dEntity> object)
{
    w3d_owner_list_remove(&w3d_entity_list_803617d0, &object->references);
    w3d_entity_list_803617d0.count--;
}

Ptr32<W3dEntity> w3d_entity_create_8015fe1c(void)
{
    Ptr32<W3dEntity> object = (Ptr32<W3dEntity>)w3d_base_construct_8015fef0((Ptr32<W3dEntity>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_entity_list_803617d0, object ? w3d::R(&object->references) : 0);
    w3d_entity_list_803617d0.count++;
    return object;
}

unsigned short w3d_entity_release_8015fe7c(Ptr32<W3dEntity> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_entity_unlink_8015fdd8(object);
        if (object)
            w3d_base_destroy_8015ff2c(object, 3);
    }
    return remaining;
}

unsigned short w3d_entity_retain_8015fed8(Ptr32<W3dEntity> object)
{
    return object->references++;
}

void w3d_base_destroy_8015ff2c(Ptr32<void> self, int flags)
{
    Ptr32<W3dEntity> object = (Ptr32<W3dEntity>)self;
    object->vtable = w3d_entity_vtable_804115c8;
    w3d_base_destroy_8015fa94(object, flags);
}

/* InputService: registry list 0x80361830, 52 bytes. */
Ptr32<W3dInputService> w3d_input_service_construct_8016030c(Ptr32<W3dInputService> object);
void w3d_input_service_destroy_80160388(Ptr32<W3dInputService> object, int flags);
void w3d_input_service_unlink_801601f4(Ptr32<W3dInputService> object);

Ptr32<W3dSharedList> w3d_input_service_list_get_801601e8(void)
{
    return &w3d_input_service_list_80361830;
}

void w3d_input_service_unlink_801601f4(Ptr32<W3dInputService> object)
{
    w3d_owner_list_remove(&w3d_input_service_list_80361830, &object->references);
    w3d_input_service_list_80361830.count--;
}

Ptr32<W3dInputService> w3d_input_service_create_80160238(void)
{
    Ptr32<W3dInputService> object = w3d_input_service_construct_8016030c((Ptr32<W3dInputService>)w3d_heap_allocate_entry_a(52));
    w3d_state_register(&w3d_input_service_list_80361830, object ? w3d::R(&object->references) : 0);
    w3d_input_service_list_80361830.count++;
    return object;
}

unsigned short w3d_input_service_release_80160298(Ptr32<W3dInputService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_input_service_unlink_801601f4(object);
        if (object)
            w3d_input_service_destroy_80160388(object, 3);
    }
    return remaining;
}

unsigned short w3d_input_service_retain_801602f4(Ptr32<W3dInputService> object)
{
    return object->references++;
}

void w3d_input_service_destroy_80160388(Ptr32<W3dInputService> object, int flags)
{
    object->vtable = w3d_input_service_vtable_804116a8;
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_801628ec(object, flags);
}

/* LogicEntity: registry list 0x80361860, 28 bytes. */
void w3d_logic_entity_unlink_80160efc(Ptr32<W3dLogicEntity> object);

Ptr32<W3dSharedList> w3d_logic_entity_list_get_80160ef0(void)
{
    return &w3d_logic_entity_list_80361860;
}

void w3d_logic_entity_unlink_80160efc(Ptr32<W3dLogicEntity> object)
{
    w3d_owner_list_remove(&w3d_logic_entity_list_80361860, &object->references);
    w3d_logic_entity_list_80361860.count--;
}

Ptr32<W3dLogicEntity> w3d_logic_entity_create_80160f40(void)
{
    Ptr32<W3dLogicEntity> object = (Ptr32<W3dLogicEntity>)w3d_actor_base_initialize((Ptr32<W3dLogicEntity>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_logic_entity_list_80361860, object ? w3d::R(&object->references) : 0);
    w3d_logic_entity_list_80361860.count++;
    return object;
}

unsigned short w3d_logic_entity_release_80160fa0(Ptr32<W3dLogicEntity> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_entity_unlink_80160efc(object);
        if (object)
            w3d_actor_base_destroy(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_entity_retain_80160ffc(Ptr32<W3dLogicEntity> object)
{
    return object->references++;
}

/* MessageRegistrationService: registry list 0x803618c0, 28 bytes. */
Ptr32<W3dMessageRegistrationService> w3d_message_registration_service_construct_8016169c(Ptr32<W3dMessageRegistrationService> object);
void w3d_message_registration_service_destroy_80161ae0(Ptr32<W3dMessageRegistrationService> object, int flags);
void w3d_message_registration_service_unlink_80161458(Ptr32<W3dMessageRegistrationService> object);

Ptr32<W3dSharedList> w3d_message_registration_service_list_get_8016144c(void)
{
    return &w3d_message_registration_service_list_803618c0;
}

void w3d_message_registration_service_unlink_80161458(Ptr32<W3dMessageRegistrationService> object)
{
    w3d_owner_list_remove(&w3d_message_registration_service_list_803618c0, &object->references);
    w3d_message_registration_service_list_803618c0.count--;
}

Ptr32<W3dMessageRegistrationService> w3d_message_registration_service_create_8016149c(void)
{
    Ptr32<W3dMessageRegistrationService> object = w3d_message_registration_service_construct_8016169c((Ptr32<W3dMessageRegistrationService>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_message_registration_service_list_803618c0, object ? w3d::R(&object->references) : 0);
    w3d_message_registration_service_list_803618c0.count++;
    return object;
}

unsigned short w3d_message_registration_service_release_801614fc(Ptr32<W3dMessageRegistrationService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_message_registration_service_unlink_80161458(object);
        if (object)
            w3d_message_registration_service_destroy_80161ae0(object, 3);
    }
    return remaining;
}

unsigned short w3d_message_registration_service_retain_80161558(Ptr32<W3dMessageRegistrationService> object)
{
    return object->references++;
}

/* Service: registry list 0x803618f0, 28 bytes. */
Ptr32<W3dService> w3d_service_construct_801628b0(Ptr32<W3dService> object);
void w3d_service_destroy_801628ec(Ptr32<W3dService> object, int flags);
void w3d_service_unlink_80162798(Ptr32<W3dService> object);

Ptr32<W3dSharedList> w3d_service_list_get_8016278c(void)
{
    return &w3d_service_list_803618f0;
}

void w3d_service_unlink_80162798(Ptr32<W3dService> object)
{
    w3d_owner_list_remove(&w3d_service_list_803618f0, &object->references);
    w3d_service_list_803618f0.count--;
}

Ptr32<W3dService> w3d_service_create_801627dc(void)
{
    Ptr32<W3dService> object = w3d_service_construct_801628b0((Ptr32<W3dService>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_service_list_803618f0, object ? w3d::R(&object->references) : 0);
    w3d_service_list_803618f0.count++;
    return object;
}

unsigned short w3d_service_release_8016283c(Ptr32<W3dService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_service_unlink_80162798(object);
        if (object)
            w3d_service_destroy_801628ec(object, 3);
    }
    return remaining;
}

unsigned short w3d_service_retain_80162898(Ptr32<W3dService> object)
{
    return object->references++;
}

void w3d_service_destroy_801628ec(Ptr32<W3dService> object, int flags)
{
    object->vtable = w3d_service_vtable_80411828;
    w3d_base_destroy_8015fa94(object, flags);
}

/* TimerService: registry list 0x80361980, 28 bytes. */
Ptr32<W3dTimerService> w3d_timer_service_construct_801653ac(Ptr32<W3dTimerService> object);
void w3d_timer_service_destroy_801653f0(Ptr32<W3dTimerService> object, int flags);
void w3d_timer_service_unlink_80165294(Ptr32<W3dTimerService> object);

Ptr32<W3dSharedList> w3d_timer_service_list_get_80165288(void)
{
    return &w3d_timer_service_list_80361980;
}

void w3d_timer_service_unlink_80165294(Ptr32<W3dTimerService> object)
{
    w3d_owner_list_remove(&w3d_timer_service_list_80361980, &object->references);
    w3d_timer_service_list_80361980.count--;
}

Ptr32<W3dTimerService> w3d_timer_service_create_801652d8(void)
{
    Ptr32<W3dTimerService> object = w3d_timer_service_construct_801653ac((Ptr32<W3dTimerService>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_timer_service_list_80361980, object ? w3d::R(&object->references) : 0);
    w3d_timer_service_list_80361980.count++;
    return object;
}

unsigned short w3d_timer_service_release_80165338(Ptr32<W3dTimerService> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_timer_service_unlink_80165294(object);
        if (object)
            w3d_timer_service_destroy_801653f0(object, 3);
    }
    return remaining;
}

unsigned short w3d_timer_service_retain_80165394(Ptr32<W3dTimerService> object)
{
    return object->references++;
}

void w3d_timer_service_destroy_801653f0(Ptr32<W3dTimerService> object, int flags)
{
    object->vtable = w3d_timer_service_vtable_80411970;
    w3d_base_destroy_801628ec(object, flags);
}



}


