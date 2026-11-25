#include "w3d_ptr.h"
#line 1 "d_props_f.cpp"
/* Property accessors of data-driven engine records (0x802416c0..0x80241ac0).
 *
 * Plain field getters/setters, reference-counted string fields, interface
 * pointers (retain new via vtable +0x0c, release old via +0x10) and in-place
 * vector/matrix values copied by assignment. Each struct covers one observed
 * accessor block. The block from 0x802413a0 likely belongs to the 0x11c-byte
 * object created at 0x80241b00 (offsets up to 0x110 fit inside it).
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps802416c0 {
    unsigned char unknown_00[0x1c];
    W3dString name_1c;
    W3dString name_20;
    unsigned char unknown_24[0x5c - 0x24];
    W3dVector3 vector_5c;
    W3dVector3 vector_68;
    W3dVector3 vector_74;
    unsigned char unknown_80[0xe0 - 0x80];
    int value_e0;
    int value_e4;
    int value_e8;
    float value_ec;
    float value_f0;
    float value_f4;
    float value_f8;
    float value_fc;
} W3dProps802416c0;

void w3d_props_set_f32_802416c0(Ptr32<W3dProps802416c0> props, float value)
{
    props->value_fc = value;
}

float w3d_props_get_f32_802416c8(Ptr32<W3dProps802416c0> props)
{
    return props->value_fc;
}

void w3d_props_set_f32_802416d0(Ptr32<W3dProps802416c0> props, float value)
{
    props->value_f8 = value;
}

float w3d_props_get_f32_802416d8(Ptr32<W3dProps802416c0> props)
{
    return props->value_f8;
}

void w3d_props_set_f32_802416e0(Ptr32<W3dProps802416c0> props, float value)
{
    props->value_f4 = value;
}

float w3d_props_get_f32_802416e8(Ptr32<W3dProps802416c0> props)
{
    return props->value_f4;
}

void w3d_props_set_f32_802416f0(Ptr32<W3dProps802416c0> props, float value)
{
    props->value_f0 = value;
}

float w3d_props_get_f32_802416f8(Ptr32<W3dProps802416c0> props)
{
    return props->value_f0;
}

void w3d_props_set_f32_80241700(Ptr32<W3dProps802416c0> props, float value)
{
    props->value_ec = value;
}

float w3d_props_get_f32_80241708(Ptr32<W3dProps802416c0> props)
{
    return props->value_ec;
}

void w3d_props_set_vec3_80241710(Ptr32<W3dProps802416c0> props, Ptr32<const W3dVector3> value)
{
    props->vector_74 = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241730(Ptr32<W3dProps802416c0> props)
{
    return &props->vector_74;
}

void w3d_props_set_vec3_80241738(Ptr32<W3dProps802416c0> props, Ptr32<const W3dVector3> value)
{
    props->vector_68 = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241758(Ptr32<W3dProps802416c0> props)
{
    return &props->vector_68;
}

void w3d_props_set_vec3_80241760(Ptr32<W3dProps802416c0> props, Ptr32<const W3dVector3> value)
{
    props->vector_5c = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241780(Ptr32<W3dProps802416c0> props)
{
    return &props->vector_5c;
}

void w3d_props_set_i32_80241788(Ptr32<W3dProps802416c0> props, int value)
{
    props->value_e8 = value;
}

int w3d_props_get_i32_80241790(Ptr32<W3dProps802416c0> props)
{
    return props->value_e8;
}

void w3d_props_set_i32_80241798(Ptr32<W3dProps802416c0> props, int value)
{
    props->value_e4 = value;
}

int w3d_props_get_i32_802417a0(Ptr32<W3dProps802416c0> props)
{
    return props->value_e4;
}

void w3d_props_set_i32_802417a8(Ptr32<W3dProps802416c0> props, int value)
{
    props->value_e0 = value;
}

int w3d_props_get_i32_802417b0(Ptr32<W3dProps802416c0> props)
{
    return props->value_e0;
}

void w3d_props_set_string_802417b8(Ptr32<W3dProps802416c0> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_1c.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_1c.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241820(Ptr32<W3dProps802416c0> props)
{
    return &props->name_1c;
}

void w3d_props_set_string_80241828(Ptr32<W3dProps802416c0> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_20.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_20.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241890(Ptr32<W3dProps802416c0> props)
{
    return &props->name_20;
}

typedef struct W3dProps80241898 {
    unsigned char unknown_00[0x1c];
    W3dString name_1c;
    W3dString name_20;
    W3dString name_24;
} W3dProps80241898;

void w3d_props_set_string_80241898(Ptr32<W3dProps80241898> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_1c.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_1c.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241900(Ptr32<W3dProps80241898> props)
{
    return &props->name_1c;
}

void w3d_props_set_string_80241908(Ptr32<W3dProps80241898> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_24.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_24.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241970(Ptr32<W3dProps80241898> props)
{
    return &props->name_24;
}

void w3d_props_set_string_80241978(Ptr32<W3dProps80241898> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_20.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_20.data = value->data;
}

Ptr32<W3dString> w3d_props_field_802419e0(Ptr32<W3dProps80241898> props)
{
    return &props->name_20;
}

typedef struct W3dProps802419e8 {
    unsigned char unknown_00[0x1c];
    W3dString name_1c;
    W3dString name_20;
} W3dProps802419e8;

void w3d_props_set_string_802419e8(Ptr32<W3dProps802419e8> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_20.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_20.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241a50(Ptr32<W3dProps802419e8> props)
{
    return &props->name_20;
}

void w3d_props_set_string_80241a58(Ptr32<W3dProps802419e8> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_1c.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_1c.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241ac0(Ptr32<W3dProps802419e8> props)
{
    return &props->name_1c;
}

}


