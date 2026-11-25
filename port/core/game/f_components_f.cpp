#include "w3d_ptr.h"
#line 1 "f_components_f.cpp"
/* Reference-counted component types with per-type registry lists (0x800a54d8..).
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

typedef struct W3dComponent_800a54d8 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    Ptr32<W3dInterface> held_020;
} W3dComponent_800a54d8;

typedef struct W3dComponent_800a5eb8 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_800a5eb8;

typedef struct W3dComponent_800a9dbc {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
    Ptr32<W3dInterface> held_028;
    Ptr32<W3dInterface> held_02c;
    Ptr32<W3dInterface> held_030;
    Ptr32<W3dInterface> held_034;
    Ptr32<W3dInterface> held_038;
    Ptr32<W3dInterface> held_03c;
    Ptr32<W3dInterface> held_040;
    Ptr32<W3dInterface> held_044;
    unsigned char unknown_048[0x7c - 0x48];
    Ptr32<W3dInterface> held_07c;
    Ptr32<W3dInterface> held_080;
    unsigned char unknown_084[0xb0 - 0x84];
    Ptr32<W3dInterface> held_0b0;
    unsigned char unknown_0b4[0xb8 - 0xb4];
    Ptr32<W3dInterface> held_0b8;
    Ptr32<W3dInterface> held_0bc;
    Ptr32<W3dInterface> held_0c0;
    Ptr32<W3dInterface> held_0c4;
    Ptr32<W3dInterface> held_0c8;
    Ptr32<W3dInterface> held_0cc;
    Ptr32<W3dInterface> held_0d0;
    Ptr32<W3dInterface> held_0d4;
    Ptr32<W3dInterface> held_0d8;
    Ptr32<W3dInterface> held_0dc;
    Ptr32<W3dInterface> held_0e0;
    Ptr32<W3dInterface> held_0e4;
    Ptr32<W3dInterface> held_0e8;
    Ptr32<W3dInterface> held_0ec;
} W3dComponent_800a9dbc;

typedef struct W3dComponent_800ad934 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x20 - 0x6];
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
    Ptr32<W3dInterface> held_028;
    Ptr32<W3dInterface> held_02c;
    Ptr32<W3dInterface> held_030;
    unsigned char unknown_034[0x54 - 0x34];
    Ptr32<W3dInterface> held_054;
    Ptr32<W3dInterface> held_058;
    Ptr32<W3dInterface> held_05c;
    Ptr32<W3dInterface> held_060;
    unsigned char unknown_064[0x70 - 0x64];
    Ptr32<W3dInterface> held_070;
} W3dComponent_800ad934;

typedef struct W3dComponent_800b938c {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_800b938c;

typedef struct W3dComponent_800ba760 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
    Ptr32<W3dInterface> held_028;
    Ptr32<W3dInterface> held_02c;
    Ptr32<W3dInterface> held_030;
    Ptr32<W3dInterface> held_034;
    Ptr32<W3dInterface> held_038;
    Ptr32<W3dInterface> held_03c;
    Ptr32<W3dInterface> held_040;
    unsigned char unknown_044[0x74 - 0x44];
    Ptr32<void> handle_074;
    unsigned char unknown_078[0x3100 - 0x78];
    Ptr32<W3dInterface> held_3100;
} W3dComponent_800ba760;

typedef struct W3dComponent_800bed38 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    int value_01c;
    int value_020;
    int value_024;
    unsigned char unknown_028[0x38 - 0x28];
    int value_038;
    unsigned char value_03c;
} W3dComponent_800bed38;

typedef struct W3dComponent_800bfe90 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_800bfe90;

extern W3dSharedList w3d_component_list_803607e0;
extern W3dSharedList w3d_component_list_80360810;
extern W3dSharedList w3d_component_list_80360840;
extern W3dSharedList w3d_component_list_80360870;
extern W3dSharedList w3d_component_list_803608d0;
extern W3dSharedList w3d_component_list_80360900;
extern W3dSharedList w3d_component_list_80360930;
extern W3dSharedList w3d_component_list_80360960;
extern Ptr32<const void> w3d_component_vtable_8040f5e8[];
extern Ptr32<const void> w3d_component_vtable_8040f690[];
extern Ptr32<const void> w3d_component_vtable_8040f6f8[];
extern Ptr32<const void> w3d_component_vtable_8040f828[];
extern Ptr32<const void> w3d_component_vtable_8040f868[];

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_actor_base_destroy(Ptr32<void> object, int flags);
int w3d_actor_base_initialize(Ptr32<void> object);
int w3d_base_construct_8015fef0(Ptr32<void> object);
void w3d_base_destroy_8015ff2c(Ptr32<void> object, int flags);
int w3d_base_handle_message_8015fb34(Ptr32<void> object, Ptr32<W3dMessage> message);
void w3d_component_start_800a5750(Ptr32<void> object);
void w3d_component_start_800ade2c(Ptr32<void> object);
void w3d_component_stop_800a5ccc(Ptr32<void> object);
void w3d_component_stop_800ae200(Ptr32<void> object);
void w3d_handle_storage_release(Ptr32<void> handle);

Ptr32<W3dComponent_800a54d8> w3d_component_construct_800a55fc(Ptr32<W3dComponent_800a54d8> object);
void w3d_component_destroy_800a5644(Ptr32<W3dComponent_800a54d8> object, int flags);
void w3d_component_unlink_800a54e4(Ptr32<W3dComponent_800a54d8> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a54d8(void)
{
    return &w3d_component_list_803607e0;
}

void w3d_component_unlink_800a54e4(Ptr32<W3dComponent_800a54d8> object)
{
    w3d_owner_list_remove(&w3d_component_list_803607e0, &object->references);
    w3d_component_list_803607e0.count--;
}

Ptr32<W3dComponent_800a54d8> w3d_component_create_800a5528(void)
{
    Ptr32<W3dComponent_800a54d8> object = w3d_component_construct_800a55fc((Ptr32<W3dComponent_800a54d8>)w3d_heap_allocate_entry_a(36));
    w3d_state_register(&w3d_component_list_803607e0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803607e0.count++;
    return object;
}

unsigned short w3d_component_release_800a5588(Ptr32<W3dComponent_800a54d8> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a54e4(object);
        if (object)
            w3d_component_destroy_800a5644(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a55e4(Ptr32<W3dComponent_800a54d8> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800a54d8> w3d_component_construct_800a55fc(Ptr32<W3dComponent_800a54d8> object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_8040f5e8;
    object->held_01c = 0;
    object->held_020 = 0;
    return object;
}

void w3d_component_destroy_800a5644(Ptr32<W3dComponent_800a54d8> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f5e8;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_actor_base_destroy(object, flags);
}

int w3d_component_handle_message_800a56c0(Ptr32<W3dComponent_800a54d8> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_800a5750(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800a5ccc(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

void w3d_component_stop_800a5ccc(Ptr32<void> object)
{
}

Ptr32<W3dComponent_800a5eb8> w3d_component_construct_800a5fdc(Ptr32<W3dComponent_800a5eb8> object);
void w3d_component_destroy_800a60e8(Ptr32<W3dComponent_800a5eb8> object, int flags);
void w3d_component_unlink_800a5ec4(Ptr32<W3dComponent_800a5eb8> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a5eb8(void)
{
    return &w3d_component_list_80360810;
}

void w3d_component_unlink_800a5ec4(Ptr32<W3dComponent_800a5eb8> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360810, &object->references);
    w3d_component_list_80360810.count--;
}

Ptr32<W3dComponent_800a5eb8> w3d_component_create_800a5f08(void)
{
    Ptr32<W3dComponent_800a5eb8> object = w3d_component_construct_800a5fdc((Ptr32<W3dComponent_800a5eb8>)w3d_heap_allocate_entry_a(184));
    w3d_state_register(&w3d_component_list_80360810, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360810.count++;
    return object;
}

unsigned short w3d_component_release_800a5f68(Ptr32<W3dComponent_800a5eb8> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a5ec4(object);
        if (object)
            w3d_component_destroy_800a60e8(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a5fc4(Ptr32<W3dComponent_800a5eb8> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800a9dbc> w3d_component_construct_800a9ee0(Ptr32<W3dComponent_800a9dbc> object);
void w3d_component_destroy_800aa020(Ptr32<W3dComponent_800a9dbc> object, int flags);
void w3d_component_unlink_800a9dc8(Ptr32<W3dComponent_800a9dbc> object);

Ptr32<W3dSharedList> w3d_component_list_get_800a9dbc(void)
{
    return &w3d_component_list_80360840;
}

void w3d_component_unlink_800a9dc8(Ptr32<W3dComponent_800a9dbc> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360840, &object->references);
    w3d_component_list_80360840.count--;
}

Ptr32<W3dComponent_800a9dbc> w3d_component_create_800a9e0c(void)
{
    Ptr32<W3dComponent_800a9dbc> object = w3d_component_construct_800a9ee0((Ptr32<W3dComponent_800a9dbc>)w3d_heap_allocate_entry_a(240));
    w3d_state_register(&w3d_component_list_80360840, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360840.count++;
    return object;
}

unsigned short w3d_component_release_800a9e6c(Ptr32<W3dComponent_800a9dbc> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800a9dc8(object);
        if (object)
            w3d_component_destroy_800aa020(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800a9ec8(Ptr32<W3dComponent_800a9dbc> object)
{
    return object->references++;
}

void w3d_component_destroy_800aa020(Ptr32<W3dComponent_800a9dbc> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f690;
    if (object->held_0ec)
        object->held_0ec->vtable->release(object->held_0ec);
    if (object->held_0e8)
        object->held_0e8->vtable->release(object->held_0e8);
    if (object->held_0e4)
        object->held_0e4->vtable->release(object->held_0e4);
    if (object->held_0e0)
        object->held_0e0->vtable->release(object->held_0e0);
    if (object->held_0dc)
        object->held_0dc->vtable->release(object->held_0dc);
    if (object->held_0d8)
        object->held_0d8->vtable->release(object->held_0d8);
    if (object->held_0d4)
        object->held_0d4->vtable->release(object->held_0d4);
    if (object->held_0d0)
        object->held_0d0->vtable->release(object->held_0d0);
    if (object->held_0cc)
        object->held_0cc->vtable->release(object->held_0cc);
    if (object->held_0c8)
        object->held_0c8->vtable->release(object->held_0c8);
    if (object->held_0c4)
        object->held_0c4->vtable->release(object->held_0c4);
    if (object->held_0c0)
        object->held_0c0->vtable->release(object->held_0c0);
    if (object->held_0bc)
        object->held_0bc->vtable->release(object->held_0bc);
    if (object->held_0b8)
        object->held_0b8->vtable->release(object->held_0b8);
    if (object->held_0b0)
        object->held_0b0->vtable->release(object->held_0b0);
    if (object->held_080)
        object->held_080->vtable->release(object->held_080);
    if (object->held_07c)
        object->held_07c->vtable->release(object->held_07c);
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

Ptr32<W3dComponent_800ad934> w3d_component_construct_800ada58(Ptr32<W3dComponent_800ad934> object);
void w3d_component_destroy_800adad0(Ptr32<W3dComponent_800ad934> object, int flags);
void w3d_component_unlink_800ad940(Ptr32<W3dComponent_800ad934> object);

Ptr32<W3dSharedList> w3d_component_list_get_800ad934(void)
{
    return &w3d_component_list_80360870;
}

void w3d_component_unlink_800ad940(Ptr32<W3dComponent_800ad934> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360870, &object->references);
    w3d_component_list_80360870.count--;
}

Ptr32<W3dComponent_800ad934> w3d_component_create_800ad984(void)
{
    Ptr32<W3dComponent_800ad934> object = w3d_component_construct_800ada58((Ptr32<W3dComponent_800ad934>)w3d_heap_allocate_entry_a(116));
    w3d_state_register(&w3d_component_list_80360870, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360870.count++;
    return object;
}

unsigned short w3d_component_release_800ad9e4(Ptr32<W3dComponent_800ad934> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800ad940(object);
        if (object)
            w3d_component_destroy_800adad0(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800ada40(Ptr32<W3dComponent_800ad934> object)
{
    return object->references++;
}

void w3d_component_destroy_800adad0(Ptr32<W3dComponent_800ad934> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f6f8;
    if (object->held_070)
        object->held_070->vtable->release(object->held_070);
    if (object->held_060)
        object->held_060->vtable->release(object->held_060);
    if (object->held_05c)
        object->held_05c->vtable->release(object->held_05c);
    if (object->held_058)
        object->held_058->vtable->release(object->held_058);
    if (object->held_054)
        object->held_054->vtable->release(object->held_054);
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
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_component_handle_message_800adc2c(Ptr32<W3dComponent_800ad934> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_800ade2c(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800ae200(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

Ptr32<W3dComponent_800b938c> w3d_component_construct_800b94b0(Ptr32<W3dComponent_800b938c> object);
void w3d_component_destroy_800b9598(Ptr32<W3dComponent_800b938c> object, int flags);
void w3d_component_unlink_800b9398(Ptr32<W3dComponent_800b938c> object);

Ptr32<W3dSharedList> w3d_component_list_get_800b938c(void)
{
    return &w3d_component_list_803608d0;
}

void w3d_component_unlink_800b9398(Ptr32<W3dComponent_800b938c> object)
{
    w3d_owner_list_remove(&w3d_component_list_803608d0, &object->references);
    w3d_component_list_803608d0.count--;
}

Ptr32<W3dComponent_800b938c> w3d_component_create_800b93dc(void)
{
    Ptr32<W3dComponent_800b938c> object = w3d_component_construct_800b94b0((Ptr32<W3dComponent_800b938c>)w3d_heap_allocate_entry_a(6212));
    w3d_state_register(&w3d_component_list_803608d0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803608d0.count++;
    return object;
}

unsigned short w3d_component_release_800b943c(Ptr32<W3dComponent_800b938c> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800b9398(object);
        if (object)
            w3d_component_destroy_800b9598(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800b9498(Ptr32<W3dComponent_800b938c> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800ba760> w3d_component_construct_800ba884(Ptr32<W3dComponent_800ba760> object);
void w3d_component_destroy_800ba9a8(Ptr32<W3dComponent_800ba760> object, int flags);
void w3d_component_unlink_800ba76c(Ptr32<W3dComponent_800ba760> object);

Ptr32<W3dSharedList> w3d_component_list_get_800ba760(void)
{
    return &w3d_component_list_80360900;
}

void w3d_component_unlink_800ba76c(Ptr32<W3dComponent_800ba760> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360900, &object->references);
    w3d_component_list_80360900.count--;
}

Ptr32<W3dComponent_800ba760> w3d_component_create_800ba7b0(void)
{
    Ptr32<W3dComponent_800ba760> object = w3d_component_construct_800ba884((Ptr32<W3dComponent_800ba760>)w3d_heap_allocate_entry_a(12576));
    w3d_state_register(&w3d_component_list_80360900, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360900.count++;
    return object;
}

unsigned short w3d_component_release_800ba810(Ptr32<W3dComponent_800ba760> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800ba76c(object);
        if (object)
            w3d_component_destroy_800ba9a8(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800ba86c(Ptr32<W3dComponent_800ba760> object)
{
    return object->references++;
}

void w3d_component_destroy_800ba9a8(Ptr32<W3dComponent_800ba760> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f828;
    if (object->held_3100)
        object->held_3100->vtable->release(object->held_3100);
    if (object->handle_074)
        w3d_handle_storage_release(object->handle_074);
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

Ptr32<W3dComponent_800bed38> w3d_component_construct_800bee5c(Ptr32<W3dComponent_800bed38> object);
void w3d_component_destroy_800beeb0(Ptr32<W3dComponent_800bed38> object, int flags);
void w3d_component_unlink_800bed44(Ptr32<W3dComponent_800bed38> object);

Ptr32<W3dSharedList> w3d_component_list_get_800bed38(void)
{
    return &w3d_component_list_80360930;
}

void w3d_component_unlink_800bed44(Ptr32<W3dComponent_800bed38> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360930, &object->references);
    w3d_component_list_80360930.count--;
}

Ptr32<W3dComponent_800bed38> w3d_component_create_800bed88(void)
{
    Ptr32<W3dComponent_800bed38> object = w3d_component_construct_800bee5c((Ptr32<W3dComponent_800bed38>)w3d_heap_allocate_entry_a(64));
    w3d_state_register(&w3d_component_list_80360930, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360930.count++;
    return object;
}

unsigned short w3d_component_release_800bede8(Ptr32<W3dComponent_800bed38> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800bed44(object);
        if (object)
            w3d_component_destroy_800beeb0(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800bee44(Ptr32<W3dComponent_800bed38> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800bed38> w3d_component_construct_800bee5c(Ptr32<W3dComponent_800bed38> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f868;
    object->value_020 = 0;
    object->value_024 = 0;
    object->value_038 = 0;
    object->value_01c = 0;
    object->value_03c = 0;
    return object;
}

Ptr32<W3dComponent_800bfe90> w3d_component_construct_800bffb4(Ptr32<W3dComponent_800bfe90> object);
void w3d_component_destroy_800c000c(Ptr32<W3dComponent_800bfe90> object, int flags);
void w3d_component_unlink_800bfe9c(Ptr32<W3dComponent_800bfe90> object);

Ptr32<W3dSharedList> w3d_component_list_get_800bfe90(void)
{
    return &w3d_component_list_80360960;
}

void w3d_component_unlink_800bfe9c(Ptr32<W3dComponent_800bfe90> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360960, &object->references);
    w3d_component_list_80360960.count--;
}

Ptr32<W3dComponent_800bfe90> w3d_component_create_800bfee0(void)
{
    Ptr32<W3dComponent_800bfe90> object = w3d_component_construct_800bffb4((Ptr32<W3dComponent_800bfe90>)w3d_heap_allocate_entry_a(36));
    w3d_state_register(&w3d_component_list_80360960, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360960.count++;
    return object;
}

unsigned short w3d_component_release_800bff40(Ptr32<W3dComponent_800bfe90> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800bfe9c(object);
        if (object)
            w3d_component_destroy_800c000c(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800bff9c(Ptr32<W3dComponent_800bfe90> object)
{
    return object->references++;
}

}


