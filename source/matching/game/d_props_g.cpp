/* Property accessors of a registered engine type (0x80249198..0x802493a0).
 *
 * These accessors cover the 0x11c-byte engine type registered at 0x80367748
 * (constructed by 0x80241bac): plain fields, reference-counted strings,
 * in-place vectors and signed byte flags. Each struct covers one observed
 * accessor block; field meanings are unknown.
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80249198 {
    unsigned char unknown_00[0x20];
    W3dVector3 vector_20;
    W3dVector3 vector_2c;
    W3dVector3 vector_38;
    W3dVector3 vector_44;
    W3dVector3 vector_50;
    W3dVector3 vector_5c;
    int value_68;
    unsigned char unknown_6c[0x70 - 0x6c];
    int value_70;
    float value_74;
    unsigned char unknown_78[0x7c - 0x78];
    float value_7c;
    int value_80;
    int value_84;
    unsigned char unknown_88[0x8c - 0x88];
    W3dString name_8c;
    unsigned char unknown_90[0xaa - 0x90];
    unsigned short value_aa;
    unsigned char unknown_ac[0xcc - 0xac];
    int value_cc;
    unsigned char unknown_d0[0xd5 - 0xd0];
    unsigned char value_d5;
    unsigned char unknown_d6[0xd8 - 0xd6];
    int value_d8;
    int value_dc;
} W3dProps80249198;

void w3d_props_set_string_80249198(W3dProps80249198 *props, W3dString *value)
{
    W3dStringHeader *old;
    ++((W3dStringHeader *)(value->data - 6))->references;
    old = (W3dStringHeader *)(props->name_8c.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_8c.data = value->data;
}

W3dString *w3d_props_field_80249200(W3dProps80249198 *props)
{
    return &props->name_8c;
}

void w3d_props_set_i32_80249208(W3dProps80249198 *props, int value)
{
    props->value_dc = value;
}

int w3d_props_get_i32_80249210(W3dProps80249198 *props)
{
    return props->value_dc;
}

void w3d_props_set_vec3_80249218(W3dProps80249198 *props, const W3dVector3 *value)
{
    props->vector_50 = *value;
}

W3dVector3 *w3d_props_field_80249238(W3dProps80249198 *props)
{
    return &props->vector_50;
}

void w3d_props_set_vec3_80249240(W3dProps80249198 *props, const W3dVector3 *value)
{
    props->vector_44 = *value;
}

W3dVector3 *w3d_props_field_80249260(W3dProps80249198 *props)
{
    return &props->vector_44;
}

void w3d_props_set_vec3_80249268(W3dProps80249198 *props, const W3dVector3 *value)
{
    props->vector_38 = *value;
}

W3dVector3 *w3d_props_field_80249288(W3dProps80249198 *props)
{
    return &props->vector_38;
}

void w3d_props_set_vec3_80249290(W3dProps80249198 *props, const W3dVector3 *value)
{
    props->vector_5c = *value;
}

W3dVector3 *w3d_props_field_802492b0(W3dProps80249198 *props)
{
    return &props->vector_5c;
}

void w3d_props_set_vec3_802492b8(W3dProps80249198 *props, const W3dVector3 *value)
{
    props->vector_2c = *value;
}

W3dVector3 *w3d_props_field_802492d8(W3dProps80249198 *props)
{
    return &props->vector_2c;
}

void w3d_props_set_vec3_802492e0(W3dProps80249198 *props, const W3dVector3 *value)
{
    props->vector_20 = *value;
}

W3dVector3 *w3d_props_field_80249300(W3dProps80249198 *props)
{
    return &props->vector_20;
}

void w3d_props_set_i32_80249308(W3dProps80249198 *props, int value)
{
    props->value_80 = value;
}

int w3d_props_get_i32_80249310(W3dProps80249198 *props)
{
    return props->value_80;
}

void w3d_props_set_f32_80249318(W3dProps80249198 *props, float value)
{
    props->value_7c = value;
}

float w3d_props_get_f32_80249320(W3dProps80249198 *props)
{
    return props->value_7c;
}

void w3d_props_set_i32_80249328(W3dProps80249198 *props, int value)
{
    props->value_84 = value;
}

int w3d_props_get_i32_80249330(W3dProps80249198 *props)
{
    return props->value_84;
}

void w3d_props_set_f32_80249338(W3dProps80249198 *props, float value)
{
    props->value_74 = value;
}

float w3d_props_get_f32_80249340(W3dProps80249198 *props)
{
    return props->value_74;
}

void w3d_props_set_i32_80249348(W3dProps80249198 *props, int value)
{
    props->value_70 = value;
}

int w3d_props_get_i32_80249350(W3dProps80249198 *props)
{
    return props->value_70;
}

void w3d_props_set_i32_80249358(W3dProps80249198 *props, int value)
{
    props->value_d8 = value;
}

int w3d_props_get_i32_80249360(W3dProps80249198 *props)
{
    return props->value_d8;
}

void w3d_props_set_i32_80249368(W3dProps80249198 *props, int value)
{
    props->value_68 = value;
}

int w3d_props_get_i32_80249370(W3dProps80249198 *props)
{
    return props->value_68;
}

void w3d_props_set_u8_80249378(W3dProps80249198 *props, unsigned char value)
{
    props->value_d5 = value;
}

unsigned char w3d_props_get_u8_80249380(W3dProps80249198 *props)
{
    return props->value_d5;
}

void w3d_props_set_u16_80249388(W3dProps80249198 *props, unsigned short value)
{
    props->value_aa = value;
}

unsigned short w3d_props_get_u16_80249390(W3dProps80249198 *props)
{
    return props->value_aa;
}

void w3d_props_set_i32_80249398(W3dProps80249198 *props, int value)
{
    props->value_cc = value;
}

int w3d_props_get_i32_802493a0(W3dProps80249198 *props)
{
    return props->value_cc;
}

}
