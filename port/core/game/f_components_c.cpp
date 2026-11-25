#include "w3d_ptr.h"
#line 1 "f_components_c.cpp"
/* Reference-counted component types with per-type registry lists (0x8006ffc4..).
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

typedef struct W3dComponent_8006ffc4 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0xf4 - 0x6];
    Ptr32<W3dInterface> held_0f4;
} W3dComponent_8006ffc4;

typedef struct W3dComponent_8007081c {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x168 - 0x6];
    Ptr32<W3dInterface> held_168;
    Ptr32<W3dInterface> held_16c;
    Ptr32<W3dInterface> held_170;
    Ptr32<W3dInterface> held_174;
    Ptr32<W3dInterface> held_178;
    Ptr32<W3dInterface> held_17c;
    Ptr32<W3dInterface> held_180;
    Ptr32<W3dInterface> held_184;
    Ptr32<W3dInterface> held_188;
    Ptr32<W3dInterface> held_18c;
    Ptr32<W3dInterface> held_190;
    Ptr32<W3dInterface> held_194;
    Ptr32<W3dInterface> held_198;
} W3dComponent_8007081c;

typedef struct W3dComponent_80072d24 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    int value_01c;
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
} W3dComponent_80072d24;

typedef struct W3dComponent_800877b8 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_800877b8;

typedef struct W3dComponent_800932c4 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x20 - 0x6];
    Ptr32<W3dInterface> held_020;
    int value_024;
} W3dComponent_800932c4;

typedef struct W3dComponent_80093870 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x40 - 0x6];
    Ptr32<W3dInterface> held_040;
    Ptr32<W3dInterface> held_044;
    Ptr32<W3dInterface> held_048;
    Ptr32<W3dInterface> held_04c;
    Ptr32<W3dInterface> held_050;
    Ptr32<W3dInterface> held_054;
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
    Ptr32<W3dInterface> held_094;
    Ptr32<W3dInterface> held_098;
    Ptr32<W3dInterface> held_09c;
    Ptr32<W3dInterface> held_0a0;
    Ptr32<W3dInterface> held_0a4;
    Ptr32<W3dInterface> held_0a8;
    unsigned char unknown_0ac[0x2d4 - 0xac];
    Ptr32<W3dInterface> held_2d4;
    Ptr32<W3dInterface> held_2d8;
    Ptr32<W3dInterface> held_2dc;
    Ptr32<W3dInterface> held_2e0;
    unsigned char unknown_2e4[0x2f0 - 0x2e4];
    Ptr32<W3dInterface> held_2f0;
} W3dComponent_80093870;

typedef struct W3dComponent_80096858 {
    Ptr32<const void> vtable;
    unsigned short references;
} W3dComponent_80096858;

extern W3dSharedList w3d_component_list_80360450;
extern W3dSharedList w3d_component_list_80360480;
extern W3dSharedList w3d_component_list_803604b0;
extern W3dSharedList w3d_component_list_803604e0;
extern W3dSharedList w3d_component_list_80360510;
extern W3dSharedList w3d_component_list_80360540;
extern W3dSharedList w3d_component_list_80360570;
extern Ptr32<const void> w3d_component_vtable_8040f000[];
extern Ptr32<const void> w3d_component_vtable_8040f048[];
extern Ptr32<const void> w3d_component_vtable_8040f0e0[];
extern Ptr32<const void> w3d_component_vtable_8040f1b8[];
extern Ptr32<const void> w3d_component_vtable_8040f1f8[];

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_actor_base_destroy(Ptr32<void> object, int flags);
int w3d_actor_base_initialize(Ptr32<void> object);
int w3d_base_construct_800e7e20(Ptr32<void> object);
int w3d_base_construct_800ea180(Ptr32<void> object);
int w3d_base_construct_8015fef0(Ptr32<void> object);
void w3d_base_destroy_8002a978(Ptr32<void> object, int flags);
void w3d_base_destroy_800e7ed8(Ptr32<void> object, int flags);
void w3d_base_destroy_800ea324(Ptr32<void> object, int flags);
void w3d_base_destroy_8015ff2c(Ptr32<void> object, int flags);
int w3d_base_handle_message_8015fb34(Ptr32<void> object, Ptr32<W3dMessage> message);
void w3d_component_start_8009369c(Ptr32<void> object);
void w3d_component_stop_80093780(Ptr32<void> object);

Ptr32<W3dComponent_8006ffc4> w3d_component_construct_800700e8(Ptr32<W3dComponent_8006ffc4> object);
void w3d_component_destroy_8007012c(Ptr32<W3dComponent_8006ffc4> object, int flags);
void w3d_component_unlink_8006ffd0(Ptr32<W3dComponent_8006ffc4> object);

Ptr32<W3dSharedList> w3d_component_list_get_8006ffc4(void)
{
    return &w3d_component_list_80360450;
}

void w3d_component_unlink_8006ffd0(Ptr32<W3dComponent_8006ffc4> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360450, &object->references);
    w3d_component_list_80360450.count--;
}

Ptr32<W3dComponent_8006ffc4> w3d_component_create_80070014(void)
{
    Ptr32<W3dComponent_8006ffc4> object = w3d_component_construct_800700e8((Ptr32<W3dComponent_8006ffc4>)w3d_heap_allocate_entry_a(248));
    w3d_state_register(&w3d_component_list_80360450, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360450.count++;
    return object;
}

unsigned short w3d_component_release_80070074(Ptr32<W3dComponent_8006ffc4> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8006ffd0(object);
        if (object)
            w3d_component_destroy_8007012c(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800700d0(Ptr32<W3dComponent_8006ffc4> object)
{
    return object->references++;
}

Ptr32<W3dComponent_8006ffc4> w3d_component_construct_800700e8(Ptr32<W3dComponent_8006ffc4> object)
{
    w3d_base_construct_800e7e20(object);
    object->vtable = w3d_component_vtable_8040f000;
    object->held_0f4 = 0;
    return object;
}

void w3d_component_destroy_8007012c(Ptr32<W3dComponent_8006ffc4> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f000;
    if (object->held_0f4)
        object->held_0f4->vtable->release(object->held_0f4);
    w3d_base_destroy_800e7ed8(object, flags);
}

Ptr32<W3dComponent_8007081c> w3d_component_construct_80070940(Ptr32<W3dComponent_8007081c> object);
void w3d_component_destroy_800709b4(Ptr32<W3dComponent_8007081c> object, int flags);
void w3d_component_unlink_80070828(Ptr32<W3dComponent_8007081c> object);

Ptr32<W3dSharedList> w3d_component_list_get_8007081c(void)
{
    return &w3d_component_list_80360480;
}

void w3d_component_unlink_80070828(Ptr32<W3dComponent_8007081c> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360480, &object->references);
    w3d_component_list_80360480.count--;
}

Ptr32<W3dComponent_8007081c> w3d_component_create_8007086c(void)
{
    Ptr32<W3dComponent_8007081c> object = w3d_component_construct_80070940((Ptr32<W3dComponent_8007081c>)w3d_heap_allocate_entry_a(412));
    w3d_state_register(&w3d_component_list_80360480, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360480.count++;
    return object;
}

unsigned short w3d_component_release_800708cc(Ptr32<W3dComponent_8007081c> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80070828(object);
        if (object)
            w3d_component_destroy_800709b4(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80070928(Ptr32<W3dComponent_8007081c> object)
{
    return object->references++;
}

Ptr32<W3dComponent_8007081c> w3d_component_construct_80070940(Ptr32<W3dComponent_8007081c> object)
{
    w3d_base_construct_800ea180(object);
    object->vtable = w3d_component_vtable_8040f048;
    object->held_168 = 0;
    object->held_16c = 0;
    object->held_170 = 0;
    object->held_174 = 0;
    object->held_178 = 0;
    object->held_17c = 0;
    object->held_180 = 0;
    object->held_184 = 0;
    object->held_188 = 0;
    object->held_18c = 0;
    object->held_190 = 0;
    object->held_194 = 0;
    object->held_198 = 0;
    return object;
}

void w3d_component_destroy_800709b4(Ptr32<W3dComponent_8007081c> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f048;
    if (object->held_198)
        object->held_198->vtable->release(object->held_198);
    if (object->held_194)
        object->held_194->vtable->release(object->held_194);
    if (object->held_190)
        object->held_190->vtable->release(object->held_190);
    if (object->held_18c)
        object->held_18c->vtable->release(object->held_18c);
    if (object->held_188)
        object->held_188->vtable->release(object->held_188);
    if (object->held_184)
        object->held_184->vtable->release(object->held_184);
    if (object->held_180)
        object->held_180->vtable->release(object->held_180);
    if (object->held_17c)
        object->held_17c->vtable->release(object->held_17c);
    if (object->held_178)
        object->held_178->vtable->release(object->held_178);
    if (object->held_174)
        object->held_174->vtable->release(object->held_174);
    if (object->held_170)
        object->held_170->vtable->release(object->held_170);
    if (object->held_16c)
        object->held_16c->vtable->release(object->held_16c);
    if (object->held_168)
        object->held_168->vtable->release(object->held_168);
    w3d_base_destroy_800ea324(object, flags);
}

Ptr32<W3dComponent_80072d24> w3d_component_construct_80072e48(Ptr32<W3dComponent_80072d24> object);
void w3d_component_destroy_80072e94(Ptr32<W3dComponent_80072d24> object, int flags);
void w3d_component_unlink_80072d30(Ptr32<W3dComponent_80072d24> object);

Ptr32<W3dSharedList> w3d_component_list_get_80072d24(void)
{
    return &w3d_component_list_803604b0;
}

void w3d_component_unlink_80072d30(Ptr32<W3dComponent_80072d24> object)
{
    w3d_owner_list_remove(&w3d_component_list_803604b0, &object->references);
    w3d_component_list_803604b0.count--;
}

Ptr32<W3dComponent_80072d24> w3d_component_create_80072d74(void)
{
    Ptr32<W3dComponent_80072d24> object = w3d_component_construct_80072e48((Ptr32<W3dComponent_80072d24>)w3d_heap_allocate_entry_a(40));
    w3d_state_register(&w3d_component_list_803604b0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803604b0.count++;
    return object;
}

unsigned short w3d_component_release_80072dd4(Ptr32<W3dComponent_80072d24> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80072d30(object);
        if (object)
            w3d_component_destroy_80072e94(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80072e30(Ptr32<W3dComponent_80072d24> object)
{
    return object->references++;
}

Ptr32<W3dComponent_80072d24> w3d_component_construct_80072e48(Ptr32<W3dComponent_80072d24> object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_8040f0e0;
    object->held_020 = 0;
    object->held_024 = 0;
    object->value_01c = 0;
    return object;
}

void w3d_component_destroy_80072e94(Ptr32<W3dComponent_80072d24> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f0e0;
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_actor_base_destroy(object, flags);
}

Ptr32<W3dComponent_800877b8> w3d_component_construct_800878dc(Ptr32<W3dComponent_800877b8> object);
void w3d_component_destroy_80087a88(Ptr32<W3dComponent_800877b8> object, int flags);
void w3d_component_unlink_800877c4(Ptr32<W3dComponent_800877b8> object);

Ptr32<W3dSharedList> w3d_component_list_get_800877b8(void)
{
    return &w3d_component_list_803604e0;
}

void w3d_component_unlink_800877c4(Ptr32<W3dComponent_800877b8> object)
{
    w3d_owner_list_remove(&w3d_component_list_803604e0, &object->references);
    w3d_component_list_803604e0.count--;
}

Ptr32<W3dComponent_800877b8> w3d_component_create_80087808(void)
{
    Ptr32<W3dComponent_800877b8> object = w3d_component_construct_800878dc((Ptr32<W3dComponent_800877b8>)w3d_heap_allocate_entry_a(388));
    w3d_state_register(&w3d_component_list_803604e0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803604e0.count++;
    return object;
}

unsigned short w3d_component_release_80087868(Ptr32<W3dComponent_800877b8> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800877c4(object);
        if (object)
            w3d_component_destroy_80087a88(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800878c4(Ptr32<W3dComponent_800877b8> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800932c4> w3d_component_construct_800933e8(Ptr32<W3dComponent_800932c4> object);
void w3d_component_destroy_80093430(Ptr32<W3dComponent_800932c4> object, int flags);
void w3d_component_unlink_800932d0(Ptr32<W3dComponent_800932c4> object);

Ptr32<W3dSharedList> w3d_component_list_get_800932c4(void)
{
    return &w3d_component_list_80360510;
}

void w3d_component_unlink_800932d0(Ptr32<W3dComponent_800932c4> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360510, &object->references);
    w3d_component_list_80360510.count--;
}

Ptr32<W3dComponent_800932c4> w3d_component_create_80093314(void)
{
    Ptr32<W3dComponent_800932c4> object = w3d_component_construct_800933e8((Ptr32<W3dComponent_800932c4>)w3d_heap_allocate_entry_a(40));
    w3d_state_register(&w3d_component_list_80360510, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360510.count++;
    return object;
}

unsigned short w3d_component_release_80093374(Ptr32<W3dComponent_800932c4> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800932d0(object);
        if (object)
            w3d_component_destroy_80093430(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_800933d0(Ptr32<W3dComponent_800932c4> object)
{
    return object->references++;
}

Ptr32<W3dComponent_800932c4> w3d_component_construct_800933e8(Ptr32<W3dComponent_800932c4> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f1b8;
    object->held_020 = 0;
    object->value_024 = 0;
    return object;
}

void w3d_component_destroy_80093430(Ptr32<W3dComponent_800932c4> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f1b8;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_base_destroy_8015ff2c(object, flags);
}

int w3d_component_handle_message_80093490(Ptr32<W3dComponent_800932c4> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_8015fb34(object, message) >= 0) {
            w3d_component_start_8009369c(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_80093780(object);
        break;
    }
    return w3d_base_handle_message_8015fb34(object, message);
}

Ptr32<W3dComponent_80093870> w3d_component_construct_80093994(Ptr32<W3dComponent_80093870> object);
void w3d_component_destroy_80093b44(Ptr32<W3dComponent_80093870> object, int flags);
void w3d_component_unlink_8009387c(Ptr32<W3dComponent_80093870> object);

Ptr32<W3dSharedList> w3d_component_list_get_80093870(void)
{
    return &w3d_component_list_80360540;
}

void w3d_component_unlink_8009387c(Ptr32<W3dComponent_80093870> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360540, &object->references);
    w3d_component_list_80360540.count--;
}

Ptr32<W3dComponent_80093870> w3d_component_create_800938c0(void)
{
    Ptr32<W3dComponent_80093870> object = w3d_component_construct_80093994((Ptr32<W3dComponent_80093870>)w3d_heap_allocate_entry_a(768));
    w3d_state_register(&w3d_component_list_80360540, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360540.count++;
    return object;
}

unsigned short w3d_component_release_80093920(Ptr32<W3dComponent_80093870> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_8009387c(object);
        if (object)
            w3d_component_destroy_80093b44(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_8009397c(Ptr32<W3dComponent_80093870> object)
{
    return object->references++;
}

void w3d_component_destroy_80093b44(Ptr32<W3dComponent_80093870> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f1f8;
    if (object->held_2f0)
        object->held_2f0->vtable->release(object->held_2f0);
    if (object->held_2e0)
        object->held_2e0->vtable->release(object->held_2e0);
    if (object->held_2dc)
        object->held_2dc->vtable->release(object->held_2dc);
    if (object->held_2d8)
        object->held_2d8->vtable->release(object->held_2d8);
    if (object->held_2d4)
        object->held_2d4->vtable->release(object->held_2d4);
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
    w3d_base_destroy_8002a978(object, flags);
}

Ptr32<W3dComponent_80096858> w3d_component_construct_8009697c(Ptr32<W3dComponent_80096858> object);
void w3d_component_destroy_800969ec(Ptr32<W3dComponent_80096858> object, int flags);
void w3d_component_unlink_80096864(Ptr32<W3dComponent_80096858> object);

Ptr32<W3dSharedList> w3d_component_list_get_80096858(void)
{
    return &w3d_component_list_80360570;
}

void w3d_component_unlink_80096864(Ptr32<W3dComponent_80096858> object)
{
    w3d_owner_list_remove(&w3d_component_list_80360570, &object->references);
    w3d_component_list_80360570.count--;
}

Ptr32<W3dComponent_80096858> w3d_component_create_800968a8(void)
{
    Ptr32<W3dComponent_80096858> object = w3d_component_construct_8009697c((Ptr32<W3dComponent_80096858>)w3d_heap_allocate_entry_a(72));
    w3d_state_register(&w3d_component_list_80360570, object ? w3d::R(&object->references) : 0);
    w3d_component_list_80360570.count++;
    return object;
}

unsigned short w3d_component_release_80096908(Ptr32<W3dComponent_80096858> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_80096864(object);
        if (object)
            w3d_component_destroy_800969ec(object, 3);
    }
    return remaining;
}

unsigned short w3d_component_retain_80096964(Ptr32<W3dComponent_80096858> object)
{
    return object->references++;
}

}


