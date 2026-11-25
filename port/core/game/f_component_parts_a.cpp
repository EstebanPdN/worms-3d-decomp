#include "w3d_ptr.h"
#line 1 "f_component_parts_a.cpp"
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

typedef struct W3dComponent_800635bc {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
    float value_028;
    float value_02c;
    int value_030;
    int value_034;
    unsigned char unknown_038[0x54 - 0x38];
    float value_054;
    int value_058;
    int value_05c;
    int value_060;
    int value_064;
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
} W3dComponent_800635bc;

typedef struct W3dComponent_80064f4c {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x2c - 0x6];
    Ptr32<W3dInterface> held_02c;
    Ptr32<W3dInterface> held_030;
    Ptr32<W3dInterface> held_034;
    Ptr32<W3dInterface> held_038;
    Ptr32<W3dInterface> held_03c;
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
    int value_06c;
    int value_070;
    int value_074;
    int value_078;
    float value_07c;
} W3dComponent_80064f4c;

typedef struct W3dComponent_800877b8 {
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
    Ptr32<W3dInterface> held_0ac;
    Ptr32<W3dInterface> held_0b0;
    Ptr32<W3dInterface> held_0b4;
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
    Ptr32<W3dInterface> held_0f0;
    Ptr32<W3dInterface> held_0f4;
    Ptr32<W3dInterface> held_0f8;
    Ptr32<W3dInterface> held_0fc;
    Ptr32<W3dInterface> held_100;
    Ptr32<W3dInterface> held_104;
    Ptr32<W3dInterface> held_108;
    Ptr32<W3dInterface> held_10c;
    Ptr32<W3dInterface> held_110;
    Ptr32<W3dInterface> held_114;
    Ptr32<W3dInterface> held_118;
    Ptr32<W3dInterface> held_11c;
    unsigned char unknown_120[0x128 - 0x120];
    Ptr32<void> handle_128;
    unsigned char unknown_12c[0x134 - 0x12c];
    Ptr32<void> handle_134;
    unsigned char unknown_138[0x140 - 0x138];
    Ptr32<void> handle_140;
    unsigned char unknown_144[0x14c - 0x144];
    Ptr32<void> handle_14c;
    unsigned char unknown_150[0x158 - 0x150];
    Ptr32<void> handle_158;
    unsigned char unknown_15c[0x164 - 0x15c];
    Ptr32<W3dInterface> held_164;
    Ptr32<W3dInterface> held_168;
    unsigned char unknown_16c[0x178 - 0x16c];
    Ptr32<W3dInterface> held_178;
    Ptr32<W3dInterface> held_17c;
} W3dComponent_800877b8;

typedef struct W3dComponent_80096858 {
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
} W3dComponent_80096858;

typedef struct W3dComponent_80097f88 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x88 - 0x6];
    int value_088;
    int value_08c;
    float value_090;
    float value_094;
    Ptr32<W3dInterface> held_098;
} W3dComponent_80097f88;

typedef struct W3dComponent_8009b2b0 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    Ptr32<W3dInterface> held_01c;
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
    Ptr32<W3dInterface> held_028;
    unsigned char unknown_02c[0x38 - 0x2c];
    Ptr32<void> handle_038;
    unsigned char unknown_03c[0x44 - 0x3c];
    Ptr32<W3dInterface> held_044;
    unsigned char unknown_048[0x60 - 0x48];
    Ptr32<W3dInterface> held_060;
    unsigned char unknown_064[0x80 - 0x64];
    Ptr32<W3dInterface> held_080;
    Ptr32<W3dInterface> held_084;
    Ptr32<W3dInterface> held_088;
    Ptr32<W3dInterface> held_08c;
    Ptr32<W3dInterface> held_090;
} W3dComponent_8009b2b0;

typedef struct W3dComponent_800ad934 {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x20 - 0x6];
    Ptr32<W3dInterface> held_020;
    Ptr32<W3dInterface> held_024;
    Ptr32<W3dInterface> held_028;
    Ptr32<W3dInterface> held_02c;
    Ptr32<W3dInterface> held_030;
    unsigned char unknown_034[0x4c - 0x34];
    float value_04c;
    float value_050;
    Ptr32<W3dInterface> held_054;
    Ptr32<W3dInterface> held_058;
    Ptr32<W3dInterface> held_05c;
    Ptr32<W3dInterface> held_060;
    unsigned char unknown_064[0x70 - 0x64];
    Ptr32<W3dInterface> held_070;
} W3dComponent_800ad934;

extern W3dSharedList w3d_component_list_80360300;
extern W3dSharedList w3d_component_list_80360330;
extern W3dSharedList w3d_component_list_803604e0;
extern W3dSharedList w3d_component_list_80360570;
extern W3dSharedList w3d_component_list_803605d0;
extern W3dSharedList w3d_component_list_80360660;
extern W3dSharedList w3d_component_list_80360870;
extern Ptr32<const void> w3d_component_vtable_8040edc0[];
extern Ptr32<const void> w3d_component_vtable_8040ee00[];
extern Ptr32<const void> w3d_component_vtable_8040f120[];
extern Ptr32<const void> w3d_component_vtable_8040f250[];
extern Ptr32<const void> w3d_component_vtable_8040f2d0[];
extern Ptr32<const void> w3d_component_vtable_8040f390[];
extern Ptr32<const void> w3d_component_vtable_8040f6f8[];
extern const float w3d_f32_80379bf4[];
extern const float w3d_f32_80379bf8[];
extern const float w3d_f32_80379e14[];
extern const float w3d_f32_8037f740[];
extern const float w3d_f32_803820f4[];
extern Ptr32<void> w3d_component_instance_804aab4c;
extern Ptr32<void> w3d_component_instance_804aaba4;
extern Ptr32<void> w3d_component_instance_804aabe8;

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_actor_base_destroy(Ptr32<void> object, int flags);
int w3d_base_construct_8003dde0(Ptr32<void> object);
int w3d_base_construct_8015fef0(Ptr32<void> object);
int w3d_base_construct_801628b0(Ptr32<void> object);
void w3d_base_destroy_8003de80(Ptr32<void> object, int flags);
void w3d_base_destroy_8015ff2c(Ptr32<void> object, int flags);
void w3d_base_destroy_801628ec(Ptr32<void> object, int flags);
int w3d_base_handle_message_8003df40(Ptr32<void> object, Ptr32<W3dMessage> message);
int w3d_base_handle_message_8015fb34(Ptr32<void> object, Ptr32<W3dMessage> message);
void w3d_component_start_80063a0c(Ptr32<void> object);
void w3d_component_start_80098240(Ptr32<void> object);
void w3d_component_start_800ade2c(Ptr32<void> object);
void w3d_component_stop_80064104(Ptr32<void> object);
void w3d_component_stop_8009836c(Ptr32<void> object);
void w3d_component_stop_800ae200(Ptr32<void> object);
void w3d_handle_storage_release(Ptr32<void> handle);

Ptr32<W3dComponent_800635bc> w3d_component_construct_800636e0(Ptr32<W3dComponent_800635bc> object);
void w3d_component_destroy_80063794(Ptr32<W3dComponent_800635bc> object, int flags);
void w3d_component_unlink_800635c8(Ptr32<W3dComponent_800635bc> object);

Ptr32<W3dComponent_800635bc> w3d_component_construct_800636e0(Ptr32<W3dComponent_800635bc> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040edc0;
    object->held_01c = 0;
    object->held_020 = 0;
    object->value_054 = w3d_f32_80379bf4[0];
    object->held_024 = 0;
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
    object->value_028 = w3d_f32_80379bf8[0];
    object->value_058 = 0;
    object->value_030 = -1;
    object->value_02c = w3d_f32_80379bf8[0];
    object->value_060 = 0;
    object->value_034 = -1;
    object->value_05c = 1;
    object->value_064 = 0;
    return object;
}

Ptr32<W3dComponent_80064f4c> w3d_component_construct_80065070(Ptr32<W3dComponent_80064f4c> object);
void w3d_component_destroy_80065110(Ptr32<W3dComponent_80064f4c> object, int flags);
void w3d_component_unlink_80064f58(Ptr32<W3dComponent_80064f4c> object);

Ptr32<W3dComponent_80064f4c> w3d_component_construct_80065070(Ptr32<W3dComponent_80064f4c> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040ee00;
    object->held_02c = 0;
    object->held_030 = 0;
    object->held_034 = 0;
    object->held_038 = 0;
    object->held_03c = 0;
    object->held_040 = 0;
    object->held_044 = 0;
    object->held_048 = 0;
    object->held_04c = 0;
    object->held_050 = 0;
    object->held_054 = 0;
    object->held_058 = 0;
    object->held_05c = 0;
    object->held_060 = 0;
    object->held_064 = 0;
    object->held_068 = 0;
    object->value_06c = 1;
    object->value_070 = 1;
    object->value_078 = 0;
    object->value_074 = 0;
    object->value_07c = w3d_f32_80379e14[0];
    return object;
}

Ptr32<W3dComponent_800877b8> w3d_component_construct_800878dc(Ptr32<W3dComponent_800877b8> object);
void w3d_component_destroy_80087a88(Ptr32<W3dComponent_800877b8> object, int flags);
void w3d_component_unlink_800877c4(Ptr32<W3dComponent_800877b8> object);

void w3d_component_destroy_80087a88(Ptr32<W3dComponent_800877b8> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f120;
    w3d_component_instance_804aab4c = 0;
    if (object->held_17c)
        object->held_17c->vtable->release(object->held_17c);
    if (object->held_178)
        object->held_178->vtable->release(object->held_178);
    if (object->held_168)
        object->held_168->vtable->release(object->held_168);
    if (object->held_164)
        object->held_164->vtable->release(object->held_164);
    if (object->handle_158)
        w3d_handle_storage_release(object->handle_158);
    if (object->handle_14c)
        w3d_handle_storage_release(object->handle_14c);
    if (object->handle_140)
        w3d_handle_storage_release(object->handle_140);
    if (object->handle_134)
        w3d_handle_storage_release(object->handle_134);
    if (object->handle_128)
        w3d_handle_storage_release(object->handle_128);
    if (object->held_11c)
        object->held_11c->vtable->release(object->held_11c);
    if (object->held_118)
        object->held_118->vtable->release(object->held_118);
    if (object->held_114)
        object->held_114->vtable->release(object->held_114);
    if (object->held_110)
        object->held_110->vtable->release(object->held_110);
    if (object->held_10c)
        object->held_10c->vtable->release(object->held_10c);
    if (object->held_108)
        object->held_108->vtable->release(object->held_108);
    if (object->held_104)
        object->held_104->vtable->release(object->held_104);
    if (object->held_100)
        object->held_100->vtable->release(object->held_100);
    if (object->held_0fc)
        object->held_0fc->vtable->release(object->held_0fc);
    if (object->held_0f8)
        object->held_0f8->vtable->release(object->held_0f8);
    if (object->held_0f4)
        object->held_0f4->vtable->release(object->held_0f4);
    if (object->held_0f0)
        object->held_0f0->vtable->release(object->held_0f0);
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
    if (object->held_0b4)
        object->held_0b4->vtable->release(object->held_0b4);
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
    if (object->held_028)
        object->held_028->vtable->release(object->held_028);
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_801628ec(object, flags);
}

Ptr32<W3dComponent_80096858> w3d_component_construct_8009697c(Ptr32<W3dComponent_80096858> object);
void w3d_component_destroy_800969ec(Ptr32<W3dComponent_80096858> object, int flags);
void w3d_component_unlink_80096864(Ptr32<W3dComponent_80096858> object);

Ptr32<W3dComponent_80096858> w3d_component_construct_8009697c(Ptr32<W3dComponent_80096858> object)
{
    w3d_base_construct_801628b0(object);
    object->vtable = w3d_component_vtable_8040f250;
    object->held_01c = 0;
    object->held_020 = 0;
    object->held_024 = 0;
    object->held_028 = 0;
    object->held_02c = 0;
    object->held_030 = 0;
    object->held_034 = 0;
    object->held_038 = 0;
    object->held_03c = 0;
    object->held_040 = 0;
    object->held_044 = 0;
    w3d_component_instance_804aaba4 = object;
    return object;
}

void w3d_component_destroy_800969ec(Ptr32<W3dComponent_80096858> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f250;
    w3d_component_instance_804aaba4 = 0;
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
    w3d_base_destroy_801628ec(object, flags);
}

Ptr32<W3dComponent_80097f88> w3d_component_construct_800980ac(Ptr32<W3dComponent_80097f88> object);
void w3d_component_destroy_8009810c(Ptr32<W3dComponent_80097f88> object, int flags);
void w3d_component_unlink_80097f94(Ptr32<W3dComponent_80097f88> object);

Ptr32<W3dComponent_80097f88> w3d_component_construct_800980ac(Ptr32<W3dComponent_80097f88> object)
{
    w3d_base_construct_8003dde0(object);
    object->vtable = w3d_component_vtable_8040f2d0;
    object->held_098 = 0;
    object->value_094 = w3d_f32_8037f740[0];
    object->value_088 = -1;
    object->value_090 = w3d_f32_8037f740[0];
    object->value_08c = 0;
    return object;
}

Ptr32<W3dComponent_8009b2b0> w3d_component_construct_8009b3d4(Ptr32<W3dComponent_8009b2b0> object);
void w3d_component_destroy_8009b4e0(Ptr32<W3dComponent_8009b2b0> object, int flags);
void w3d_component_unlink_8009b2bc(Ptr32<W3dComponent_8009b2b0> object);

void w3d_component_destroy_8009b4e0(Ptr32<W3dComponent_8009b2b0> object, int flags)
{
    object->vtable = w3d_component_vtable_8040f390;
    w3d_component_instance_804aabe8 = 0;
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
    if (object->held_060)
        object->held_060->vtable->release(object->held_060);
    if (object->held_044)
        object->held_044->vtable->release(object->held_044);
    if (object->handle_038)
        w3d_handle_storage_release(object->handle_038);
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

Ptr32<W3dComponent_800ad934> w3d_component_construct_800ada58(Ptr32<W3dComponent_800ad934> object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040f6f8;
    object->held_020 = 0;
    object->held_024 = 0;
    object->held_028 = 0;
    object->held_02c = 0;
    object->held_030 = 0;
    object->held_054 = 0;
    object->held_058 = 0;
    object->held_05c = 0;
    object->held_060 = 0;
    object->value_04c = w3d_f32_803820f4[0];
    object->held_070 = 0;
    object->value_050 = w3d_f32_803820f4[0];
    return object;
}

}


