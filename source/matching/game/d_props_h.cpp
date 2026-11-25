/* Property accessors of a registered engine type (0x802493a8..0x80249588).
 *
 * These accessors cover the 0x11c-byte engine type registered at 0x80367748
 * (constructed by 0x80241bac): plain fields, reference-counted strings,
 * in-place vectors and signed byte flags. Each struct covers one observed
 * accessor block; field meanings are unknown.
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps802493a8 {
    unsigned char unknown_00[0x14];
    W3dVector3 vector_14;
    unsigned char unknown_20[0x6c - 0x20];
    W3dString name_6c;
    unsigned char unknown_70[0x78 - 0x70];
    int value_78;
    unsigned char unknown_7c[0x88 - 0x7c];
    int value_88;
    unsigned char unknown_8c[0x94 - 0x8c];
    float value_94;
    W3dString name_98;
    int value_9c;
    int value_a0;
    int value_a4;
    unsigned short value_a8;
    unsigned char unknown_aa[0xb8 - 0xaa];
    int value_b8;
    int value_bc;
    int value_c0;
    int value_c4;
    int value_c8;
    unsigned char unknown_cc[0xd0 - 0xcc];
    int value_d0;
    unsigned char value_d4;
} W3dProps802493a8;

void w3d_props_set_u8_802493a8(W3dProps802493a8 *props, unsigned char value)
{
    props->value_d4 = value;
}

unsigned char w3d_props_get_u8_802493b0(W3dProps802493a8 *props)
{
    return props->value_d4;
}

void w3d_props_set_u16_802493b8(W3dProps802493a8 *props, unsigned short value)
{
    props->value_a8 = value;
}

unsigned short w3d_props_get_u16_802493c0(W3dProps802493a8 *props)
{
    return props->value_a8;
}

void w3d_props_set_i32_802493c8(W3dProps802493a8 *props, int value)
{
    props->value_c4 = value;
}

int w3d_props_get_i32_802493d0(W3dProps802493a8 *props)
{
    return props->value_c4;
}

void w3d_props_set_i32_802493d8(W3dProps802493a8 *props, int value)
{
    props->value_88 = value;
}

int w3d_props_get_i32_802493e0(W3dProps802493a8 *props)
{
    return props->value_88;
}

void w3d_props_set_i32_802493e8(W3dProps802493a8 *props, int value)
{
    props->value_78 = value;
}

int w3d_props_get_i32_802493f0(W3dProps802493a8 *props)
{
    return props->value_78;
}

void w3d_props_set_i32_802493f8(W3dProps802493a8 *props, int value)
{
    props->value_d0 = value;
}

int w3d_props_get_i32_80249400(W3dProps802493a8 *props)
{
    return props->value_d0;
}

void w3d_props_set_i32_80249408(W3dProps802493a8 *props, int value)
{
    props->value_a4 = value;
}

int w3d_props_get_i32_80249410(W3dProps802493a8 *props)
{
    return props->value_a4;
}

void w3d_props_set_i32_80249418(W3dProps802493a8 *props, int value)
{
    props->value_a0 = value;
}

int w3d_props_get_i32_80249420(W3dProps802493a8 *props)
{
    return props->value_a0;
}

void w3d_props_set_i32_80249428(W3dProps802493a8 *props, int value)
{
    props->value_9c = value;
}

int w3d_props_get_i32_80249430(W3dProps802493a8 *props)
{
    return props->value_9c;
}

void w3d_props_set_string_80249438(W3dProps802493a8 *props, W3dString *value)
{
    W3dStringHeader *old;
    ++((W3dStringHeader *)(value->data - 6))->references;
    old = (W3dStringHeader *)(props->name_6c.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_6c.data = value->data;
}

W3dString *w3d_props_field_802494a0(W3dProps802493a8 *props)
{
    return &props->name_6c;
}

void w3d_props_set_string_802494a8(W3dProps802493a8 *props, W3dString *value)
{
    W3dStringHeader *old;
    ++((W3dStringHeader *)(value->data - 6))->references;
    old = (W3dStringHeader *)(props->name_98.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_98.data = value->data;
}

W3dString *w3d_props_field_80249510(W3dProps802493a8 *props)
{
    return &props->name_98;
}

void w3d_props_set_i32_80249518(W3dProps802493a8 *props, int value)
{
    props->value_c8 = value;
}

int w3d_props_get_i32_80249520(W3dProps802493a8 *props)
{
    return props->value_c8;
}

void w3d_props_set_vec3_80249528(W3dProps802493a8 *props, const W3dVector3 *value)
{
    props->vector_14 = *value;
}

W3dVector3 *w3d_props_field_80249548(W3dProps802493a8 *props)
{
    return &props->vector_14;
}

void w3d_props_set_i32_80249550(W3dProps802493a8 *props, int value)
{
    props->value_c0 = value;
}

int w3d_props_get_i32_80249558(W3dProps802493a8 *props)
{
    return props->value_c0;
}

void w3d_props_set_i32_80249560(W3dProps802493a8 *props, int value)
{
    props->value_bc = value;
}

int w3d_props_get_i32_80249568(W3dProps802493a8 *props)
{
    return props->value_bc;
}

void w3d_props_set_i32_80249570(W3dProps802493a8 *props, int value)
{
    props->value_b8 = value;
}

int w3d_props_get_i32_80249578(W3dProps802493a8 *props)
{
    return props->value_b8;
}

void w3d_props_set_f32_80249580(W3dProps802493a8 *props, float value)
{
    props->value_94 = value;
}

float w3d_props_get_f32_80249588(W3dProps802493a8 *props)
{
    return props->value_94;
}

}
