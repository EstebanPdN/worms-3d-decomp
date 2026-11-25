#include "w3d_ptr.h"
#line 1 "f_components_e.cpp"
/* Reference-counted component types with per-type registry lists (0x8009a7fc..).
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

typedef struct W3dComponent_8009a7fc {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    Ptr32<W3dInterface> held_020;
    int value_024;
    Ptr32<W3dInterface> held_028;
} W3dComponent_8009a7fc;

typedef struct W3dComponent_8009b2b0 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_8009b2b0;

typedef struct W3dComponent_8009eee8 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x14c - 0x6];
    Ptr32<W3dInterface> held_14c;
} W3dComponent_8009eee8;

typedef struct W3dComponent_8009fe68 {
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
    Ptr32<W3dInterface> held_03c;
    Ptr32<W3dInterface> held_040;
    Ptr32<W3dInterface> held_044;
    Ptr32<W3dInterface> held_048;
    Ptr32<W3dInterface> held_04c;
    int value_050;
    int value_054;
    int value_058;
    int value_05c;
    Ptr32<W3dInterface> held_060;
} W3dComponent_8009fe68;

typedef struct W3dComponent_800a17b0 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x34 - 0x6];
    Ptr32<W3dInterface> held_034;
    Ptr32<W3dInterface> held_038;
    Ptr32<W3dInterface> held_03c;
    Ptr32<W3dInterface> held_040;
    Ptr32<W3dInterface> held_044;
    Ptr32<W3dInterface> held_048;
    Ptr32<W3dInterface> held_04c;
    Ptr32<W3dInterface> held_050;
    int value_054;
    Ptr32<W3dInterface> held_058;
    Ptr32<W3dInterface> held_05c;
    Ptr32<W3dInterface> held_060;
    Ptr32<W3dInterface> held_064;
    Ptr32<W3dInterface> held_068;
    Ptr32<W3dInterface> held_06c;
    Ptr32<W3dInterface> held_070;
    Ptr32<W3dInterface> held_074;
    Ptr32<W3dInterface> held_078;
    Ptr32<W3dInterface> held_07c;
    Ptr32<W3dInterface> held_080;
    Ptr32<W3dInterface> held_084;
    Ptr32<W3dInterface> held_088;
    Ptr32<W3dInterface> held_08c;
    Ptr32<W3dInterface> held_090;
    int value_094;
    int value_098;
    Ptr32<W3dInterface> held_09c;
    Ptr32<W3dInterface> held_0a0;
    Ptr32<W3dInterface> held_0a4;
} W3dComponent_800a17b0;

typedef struct W3dComponent_800a3750 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    int value_01c;
    int value_020;
    int value_024;
    int value_028;
    int value_02c;
    int value_030;
    int value_034;
    int value_038;
    int value_03c;
    int value_040;
    unsigned char unknown_044[0x48 - 0x44];
    Ptr32<W3dInterface> held_048;
    Ptr32<W3dInterface> held_04c;
    Ptr32<W3dInterface> held_050;
    Ptr32<W3dInterface> held_054;
    Ptr32<W3dInterface> held_058;
} W3dComponent_800a3750;

typedef struct W3dComponent_800a4184 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_800a4184;

typedef struct W3dComponent_800a493c {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x20 - 0x6];
    Ptr32<W3dInterface> held_020;
    unsigned char unknown_024[0x28 - 0x24];
    int value_028;
    int value_02c;
} W3dComponent_800a493c;

typedef struct W3dComponent_800a4f84 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_800a4f84;

extern W3dSharedList w3d_component_list_80360630;
extern W3dSharedList w3d_component_list_80360660;
extern W3dSharedList w3d_component_list_80360690;
extern W3dSharedList w3d_component_list_803606c0;
extern W3dSharedList w3d_component_list_803606f0;
extern W3dSharedList w3d_component_list_80360720;
extern W3dSharedList w3d_component_list_80360750;
extern W3dSharedList w3d_component_list_80360780;
extern W3dSharedList w3d_component_list_803607b0;
extern Ptr32<const void> w3d_component_vtable_8040f350[];
extern Ptr32<const void> w3d_component_vtable_8040f3f8[];
extern Ptr32<const void> w3d_component_vtable_8040f468[];
extern Ptr32<const void> w3d_component_vtable_8040f4a8[];
extern Ptr32<const void> w3d_component_vtable_8040f4e8[];
extern Ptr32<const void> w3d_component_vtable_8040f528[];
extern Ptr32<const void> w3d_component_vtable_8040f568[];

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
int w3d_base_construct_800ea180(Ptr32<void> object);
int w3d_base_construct_8015fef0(Ptr32<void> object);
int w3d_base_construct_801628b0(Ptr32<void> object);
void w3d_base_destroy_800ea324(Ptr32<void> object, int flags);
void w3d_base_destroy_8015ff2c(Ptr32<void> object, int flags);
void w3d_base_destroy_801628ec(Ptr32<void> object, int flags);
int w3d_base_handle_message_800ea62c(Ptr32<void> object, Ptr32<W3dMessage> message);
int w3d_base_handle_message_8015fb34(Ptr32<void> object, Ptr32<W3dMessage> message);
int w3d_base_handle_message_8016293c(Ptr32<void> object, Ptr32<W3dMessage> message);
void w3d_component_start_8009f29c(Ptr32<void> object);
void w3d_component_start_800a4534(Ptr32<void> object);
void w3d_component_start_800a4bf4(Ptr32<void> object);
void w3d_component_start_800a51f8(Ptr32<void> object);
void w3d_component_stop_8009f464(Ptr32<void> object);
void w3d_component_stop_800a47fc(Ptr32<void> object);
void w3d_component_stop_800a4c50(Ptr32<void> object);
void w3d_component_stop_800a538c(Ptr32<void> object);

Ptr32<W3dComponent_8009a7fc> w3d_component_construct_8009a920(Ptr32<W3dComponent_8009a7fc> object);
void w3d_component_destroy_8009a970(Ptr32<W3dComponent_8009a7fc> object, int flags);
void w3d_component_unlink_8009a808(Ptr32<W3dComponent_8009a7fc> object);

Ptr32<W3dSharedList> w3d_component_list_get_8009a7fc(void)
{
    return &w3d_component_list_80360630;
}

void w3d_component_unlink_8009a808(Ptr32<W3dComponent_8009a7fc> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360630, &object->references);
    w3d_component_list_80360630.count--;
}

Ptr32<W3dComponent_8009a7fc> w3d_component_create_8009a84c(void)
{
    Ptr32<W3dComponent_8009a7fc> object = w3d_component_construct_8009a920((Ptr32<W3dComponent_8009a7fc>)w3d_heap_allocate_entry_a(44));
    w3d_state_register(&w3d_component_list_80360630, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360630.count++;
    return object;
}

unsigned short w3d_component_release_8009a8ac(Ptr32<W3dComponent_8009a7fc> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8009a808(object);
        if (object)
            w3d_component_destroy_8009a970(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_8009a908(Ptr32<W3dComponent_8009a7fc> object)
{
    return object->references++;
}

Ptr32<W3dComponent_8009a7fc> w3d_component_construct_8009a920(Ptr32<W3dComponent_8009a7fc> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f350;
    object->held_01c = 0;
    object->held_020 = 0;
    object->held_028 = 0;
    object->value_024 = 0;
    return object;
}

void w3d_component_destroy_8009a970(Ptr32<W3dComponent_8009a7fc> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f350;
    if (object->held_028)
        object->held_028->vtable->release(object->held_028);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

Ptr32<W3dComponent_8009b2b0> w3d_component_construct_8009b3d4(Ptr32<W3dComponent_8009b2b0> object);
void w3d_component_destroy_8009b4e0(Ptr32<W3dComponent_8009b2b0> object, int flags);
void w3d_component_unlink_8009b2bc(Ptr32<W3dComponent_8009b2b0> object);

Ptr32<W3dSharedList> w3d_component_list_get_8009b2b0(void)
{
    return &w3d_component_list_80360660;
}

void w3d_component_unlink_8009b2bc(Ptr32<W3dComponent_8009b2b0> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360660, &object->references);
    w3d_component_list_80360660.count--;
}

Ptr32<W3dComponent_8009b2b0> w3d_component_create_8009b300(void)
{
    Ptr32<W3dComponent_8009b2b0> object = w3d_component_construct_8009b3d4((Ptr32<W3dComponent_8009b2b0>)w3d_heap_allocate_entry_a(152));
    w3d_state_register(&w3d_component_list_80360660, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360660.count++;
    return object;
}

unsigned short w3d_component_release_8009b360(Ptr32<W3dComponent_8009b2b0> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8009b2bc(object);
        if (object)
            w3d_component_destroy_8009b4e0(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_8009b3bc(Ptr32<W3dComponent_8009b2b0> object)
{
    return object->references++;
}

Ptr32<W3dComponent_8009eee8> w3d_component_construct_8009f00c(Ptr32<W3dComponent_8009eee8> object);
void w3d_component_destroy_8009f050(Ptr32<W3dComponent_8009eee8> object, int flags);
void w3d_component_unlink_8009eef4(Ptr32<W3dComponent_8009eee8> object);

Ptr32<W3dSharedList> w3d_component_list_get_8009eee8(void)
{
    return &w3d_component_list_80360690;
}

void w3d_component_unlink_8009eef4(Ptr32<W3dComponent_8009eee8> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360690, &object->references);
    w3d_component_list_80360690.count--;
}

Ptr32<W3dComponent_8009eee8> w3d_component_create_8009ef38(void)
{
    Ptr32<W3dComponent_8009eee8> object = w3d_component_construct_8009f00c((Ptr32<W3dComponent_8009eee8>)w3d_heap_allocate_entry_a(340));
    w3d_state_register(&w3d_component_list_80360690, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360690.count++;
    return object;
}

unsigned short w3d_component_release_8009ef98(Ptr32<W3dComponent_8009eee8> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8009eef4(object);
        if (object)
            w3d_component_destroy_8009f050(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_8009eff4(Ptr32<W3dComponent_8009eee8> object)
{
    return object->references++;
}

Ptr32<W3dComponent_8009eee8> w3d_component_construct_8009f00c(Ptr32<W3dComponent_8009eee8> object)
{
    w3d_base_construct_800ea180(object);
    object->vtable = w3d_component_vtable_8040f3f8;
    object->held_14c = 0;
    return object;
}

void w3d_component_destroy_8009f050(Ptr32<W3dComponent_8009eee8> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f3f8;
    if (object->held_14c)
        object->held_14c->vtable->release(object->held_14c);
    w3d_base_destroy_800ea324(object, flags);
}

int w3d_component_handle_message_8009f0b0(Ptr32<W3dComponent_8009eee8> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_800ea62c(object, message) >= 0) {
            w3d_component_start_8009f29c(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_8009f464(object);
        break;
    }
    return w3d_base_handle_message_800ea62c(object, message);
}

Ptr32<W3dComponent_8009fe68> w3d_component_construct_8009ff8c(Ptr32<W3dComponent_8009fe68> object);
void w3d_component_destroy_800a0014(Ptr32<W3dComponent_8009fe68> object, int flags);
void w3d_component_unlink_8009fe74(Ptr32<W3dComponent_8009fe68> object);

Ptr32<W3dSharedList> w3d_component_list_get_8009fe68(void)
{
    return &w3d_component_list_803606c0;
}

void w3d_component_unlink_8009fe74(Ptr32<W3dComponent_8009fe68> object)
{
    w3d_owner_list_remove(&w3d_component_list_803606c0, &object->references);
    w3d_component_list_803606c0.count--;
}

Ptr32<W3dComponent_8009fe68> w3d_component_create_8009feb8(void)
{
    Ptr32<W3dComponent_8009fe68> object = w3d_component_construct_8009ff8c((Ptr32<W3dComponent_8009fe68>)w3d_heap_allocate_entry_a(100));
    w3d_state_register(&w3d_component_list_803606c0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803606c0.count++;
    return object;
}

unsigned short w3d_component_release_8009ff18(Ptr32<W3dComponent_8009fe68> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8009fe74(object);
        if (object)
            w3d_component_destroy_800a0014(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_8009ff74(Ptr32<W3dComponent_8009fe68> object)
{
    return object->references++;
}

Ptr32<W3dComponent_8009fe68> w3d_component_construct_8009ff8c(Ptr32<W3dComponent_8009fe68> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f468;
    object->held_028 = 0;
    object->held_02c = 0;
    object->held_030 = 0;
    object->held_034 = 0;
    object->held_038 = 0;
    object->held_03c = 0;
    object->held_040 = 0;
    object->held_044 = 0;
    object->held_048 = 0;
    object->held_04c = 0;
    object->held_060 = 0;
    object->value_050 = 0;
    object->value_05c = 0;
    object->held_01c = 0;
    object->held_024 = 0;
    object->value_054 = 1;
    object->value_058 = 0;
    return object;
}

void w3d_component_destroy_800a0014(Ptr32<W3dComponent_8009fe68> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f468;
    if (object->held_060)
        object->held_060->vtable->release(object->held_060);
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
    if (object->held_028)
        object->held_028->vtable->release(object->held_028);
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}

Ptr32<W3dComponent_800a17b0> w3d_component_construct_800a18d4(Ptr32<W3dComponent_800a17b0> object);
void w3d_component_destroy_800a198c(Ptr32<W3dComponent_800a17b0> object, int flags);
void w3d_component_unlink_800a17bc(Ptr32<W3dComponent_800a17b0> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a17b0(void)
{
    return &w3d_component_list_803606f0;
}

void w3d_component_unlink_800a17bc(Ptr32<W3dComponent_800a17b0> object)
{
    w3d_owner_list_remove(&w3d_component_list_803606f0, &object->references);
    w3d_component_list_803606f0.count--;
}

Ptr32<W3dComponent_800a17b0> w3d_component_create_800a1800(void)
{
    Ptr32<W3dComponent_800a17b0> object = w3d_component_construct_800a18d4((Ptr32<W3dComponent_800a17b0>)w3d_heap_allocate_entry_a(180));
    w3d_state_register(&w3d_component_list_803606f0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803606f0.count++;
    return object;
}

unsigned short w3d_component_release_800a1860(Ptr32<W3dComponent_800a17b0> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a17bc(object);
        if (object)
            w3d_component_destroy_800a198c(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a18bc(Ptr32<W3dComponent_800a17b0> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800a17b0> w3d_component_construct_800a18d4(Ptr32<W3dComponent_800a17b0> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f4a8;
    object->held_034 = 0;
    object->held_038 = 0;
    object->held_03c = 0;
    object->held_040 = 0;
    object->held_044 = 0;
    object->held_048 = 0;
    object->held_04c = 0;
    object->held_050 = 0;
    object->held_058 = 0;
    object->held_05c = 0;
    object->held_060 = 0;
    object->held_064 = 0;
    object->held_068 = 0;
    object->held_06c = 0;
    object->held_070 = 0;
    object->held_074 = 0;
    object->held_078 = 0;
    object->held_07c = 0;
    object->held_080 = 0;
    object->held_084 = 0;
    object->held_088 = 0;
    object->held_08c = 0;
    object->held_090 = 0;
    object->held_09c = 0;
    object->held_0a0 = 0;
    object->held_0a4 = 0;
    object->value_054 = 0;
    object->value_094 = 1;
    object->value_098 = 0;
    return object;
}

void w3d_component_destroy_800a198c(Ptr32<W3dComponent_800a17b0> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f4a8;
    if (object->held_0a4)
        object->held_0a4->vtable->release(object->held_0a4);
    if (object->held_0a0)
        object->held_0a0->vtable->release(object->held_0a0);
    if (object->held_09c)
        object->held_09c->vtable->release(object->held_09c);
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
    w3d_base_destroy_8015ff2c(object, flags);
}

Ptr32<W3dComponent_800a3750> w3d_component_construct_800a3874(Ptr32<W3dComponent_800a3750> object);
void w3d_component_destroy_800a38f8(Ptr32<W3dComponent_800a3750> object, int flags);
void w3d_component_unlink_800a375c(Ptr32<W3dComponent_800a3750> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a3750(void)
{
    return &w3d_component_list_80360720;
}

void w3d_component_unlink_800a375c(Ptr32<W3dComponent_800a3750> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360720, &object->references);
    w3d_component_list_80360720.count--;
}

Ptr32<W3dComponent_800a3750> w3d_component_create_800a37a0(void)
{
    Ptr32<W3dComponent_800a3750> object = w3d_component_construct_800a3874((Ptr32<W3dComponent_800a3750>)w3d_heap_allocate_entry_a(92));
    w3d_state_register(&w3d_component_list_80360720, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360720.count++;
    return object;
}

unsigned short w3d_component_release_800a3800(Ptr32<W3dComponent_800a3750> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a375c(object);
        if (object)
            w3d_component_destroy_800a38f8(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a385c(Ptr32<W3dComponent_800a3750> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800a3750> w3d_component_construct_800a3874(Ptr32<W3dComponent_800a3750> object)
{
    w3d_base_construct_801628b0(object);
    object->vtable = w3d_component_vtable_8040f4e8;
    object->held_048 = 0;
    object->held_04c = 0;
    object->held_050 = 0;
    object->held_054 = 0;
    object->held_058 = 0;
    object->value_020 = -1;
    object->value_024 = -1;
    object->value_028 = -1;
    object->value_02c = -1;
    object->value_030 = -1;
    object->value_03c = -1;
    object->value_034 = -1;
    object->value_038 = -1;
    object->value_040 = -1;
    object->value_01c = 1;
    return object;
}

void w3d_component_destroy_800a38f8(Ptr32<W3dComponent_800a3750> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f4e8;
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
    w3d_base_destroy_801628ec(object, flags);
}

Ptr32<W3dComponent_800a4184> w3d_component_construct_800a42a8(Ptr32<W3dComponent_800a4184> object);
void w3d_component_destroy_800a42e4(Ptr32<W3dComponent_800a4184> object, int flags);
void w3d_component_unlink_800a4190(Ptr32<W3dComponent_800a4184> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a4184(void)
{
    return &w3d_component_list_80360750;
}

void w3d_component_unlink_800a4190(Ptr32<W3dComponent_800a4184> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360750, &object->references);
    w3d_component_list_80360750.count--;
}

Ptr32<W3dComponent_800a4184> w3d_component_create_800a41d4(void)
{
    Ptr32<W3dComponent_800a4184> object = w3d_component_construct_800a42a8((Ptr32<W3dComponent_800a4184>)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_component_list_80360750, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360750.count++;
    return object;
}

unsigned short w3d_component_release_800a4234(Ptr32<W3dComponent_800a4184> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a4190(object);
        if (object)
            w3d_component_destroy_800a42e4(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a4290(Ptr32<W3dComponent_800a4184> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800a4184> w3d_component_construct_800a42a8(Ptr32<W3dComponent_800a4184> object)
{
    w3d_base_construct_801628b0(object);
    object->vtable = w3d_component_vtable_8040f528;
    return object;
}

void w3d_component_destroy_800a42e4(Ptr32<W3dComponent_800a4184> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f528;
    w3d_base_destroy_801628ec(object, flags);
}

int w3d_component_handle_message_800a4314(Ptr32<W3dComponent_800a4184> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8016293c(object, message) >= 0) {
            w3d_component_start_800a4534(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800a47fc(object);
        break;
    }
    return w3d_base_handle_message_8016293c(object, message);
}

void w3d_component_stop_800a47fc(Ptr32<void> object)
{
}

Ptr32<W3dComponent_800a493c> w3d_component_construct_800a4a60(Ptr32<W3dComponent_800a493c> object);
void w3d_component_destroy_800a4aac(Ptr32<W3dComponent_800a493c> object, int flags);
void w3d_component_unlink_800a4948(Ptr32<W3dComponent_800a493c> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a493c(void)
{
    return &w3d_component_list_80360780;
}

void w3d_component_unlink_800a4948(Ptr32<W3dComponent_800a493c> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360780, &object->references);
    w3d_component_list_80360780.count--;
}

Ptr32<W3dComponent_800a493c> w3d_component_create_800a498c(void)
{
    Ptr32<W3dComponent_800a493c> object = w3d_component_construct_800a4a60((Ptr32<W3dComponent_800a493c>)w3d_heap_allocate_entry_a(48));
    w3d_state_register(&w3d_component_list_80360780, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360780.count++;
    return object;
}

unsigned short w3d_component_release_800a49ec(Ptr32<W3dComponent_800a493c> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a4948(object);
        if (object)
            w3d_component_destroy_800a4aac(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a4a48(Ptr32<W3dComponent_800a493c> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800a493c> w3d_component_construct_800a4a60(Ptr32<W3dComponent_800a493c> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f568;
    object->held_020 = 0;
    object->value_028 = 0;
    object->value_02c = 0;
    return object;
}

void w3d_component_destroy_800a4aac(Ptr32<W3dComponent_800a493c> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f568;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_component_handle_message_800a4b0c(Ptr32<W3dComponent_800a493c> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_800a4bf4(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800a4c50(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

Ptr32<W3dComponent_800a4f84> w3d_component_construct_800a50a8(Ptr32<W3dComponent_800a4f84> object);
void w3d_component_destroy_800a50f4(Ptr32<W3dComponent_800a4f84> object, int flags);
void w3d_component_unlink_800a4f90(Ptr32<W3dComponent_800a4f84> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a4f84(void)
{
    return &w3d_component_list_803607b0;
}

void w3d_component_unlink_800a4f90(Ptr32<W3dComponent_800a4f84> object)
{
    w3d_owner_list_remove(&w3d_component_list_803607b0, &object->references);
    w3d_component_list_803607b0.count--;
}

Ptr32<W3dComponent_800a4f84> w3d_component_create_800a4fd4(void)
{
    Ptr32<W3dComponent_800a4f84> object = w3d_component_construct_800a50a8((Ptr32<W3dComponent_800a4f84>)w3d_heap_allocate_entry_a(36));
    w3d_state_register(&w3d_component_list_803607b0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803607b0.count++;
    return object;
}

unsigned short w3d_component_release_800a5034(Ptr32<W3dComponent_800a4f84> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a4f90(object);
        if (object)
            w3d_component_destroy_800a50f4(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a5090(Ptr32<W3dComponent_800a4f84> object)
{
    return object->references++;
}

int w3d_component_handle_message_800a5168(Ptr32<W3dComponent_800a4f84> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_800a51f8(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800a538c(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

void w3d_component_stop_800a538c(Ptr32<void> object)
{
}

}


