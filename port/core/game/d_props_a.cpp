#include "w3d_ptr.h"
#line 1 "d_props_a.cpp"
/* Property accessors of data-driven engine records (0x80240468..0x80240690).
 *
 * Plain field getters/setters, reference-counted string fields and
 * interface-pointer fields. Records are split where an offset is reused with
 * a different type, so each struct covers one observed accessor block, not a
 * known class. Interface setters retain the new object (vtable +0x0c) before
 * releasing the previous one (vtable +0x10).
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80240468 {
    unsigned char unknown_00[0x14];
    unsigned short value_14;
    unsigned char unknown_16[0x18 - 0x16];
    W3dString name_18;
    int value_1c;
} W3dProps80240468;

void w3d_props_set_u16_80240468(Ptr32<W3dProps80240468> props, unsigned short value)
{
    props->value_14 = value;
}

unsigned short w3d_props_get_u16_80240470(Ptr32<W3dProps80240468> props)
{
    return props->value_14;
}

void w3d_props_set_i32_80240478(Ptr32<W3dProps80240468> props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_80240480(Ptr32<W3dProps80240468> props)
{
    return props->value_1c;
}

void w3d_props_set_string_80240488(Ptr32<W3dProps80240468> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_18.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_18.data = value->data;
}

Ptr32<W3dString> w3d_props_field_802404f0(Ptr32<W3dProps80240468> props)
{
    return &props->name_18;
}

typedef struct W3dProps802404f8 {
    unsigned char unknown_00[0x18];
    W3dString name_18;
} W3dProps802404f8;

void w3d_props_set_string_802404f8(Ptr32<W3dProps802404f8> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_18.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_18.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80240560(Ptr32<W3dProps802404f8> props)
{
    return &props->name_18;
}

typedef struct W3dProps80240568 {
    unsigned char unknown_00[0x18];
    unsigned short value_18;
} W3dProps80240568;

void w3d_props_set_u16_80240568(Ptr32<W3dProps80240568> props, unsigned short value)
{
    props->value_18 = value;
}

unsigned short w3d_props_get_u16_80240570(Ptr32<W3dProps80240568> props)
{
    return props->value_18;
}

typedef struct W3dProps80240578 {
    unsigned char unknown_00[0x18];
    int value_18;
} W3dProps80240578;

void w3d_props_set_i32_80240578(Ptr32<W3dProps80240578> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240580(Ptr32<W3dProps80240578> props)
{
    return props->value_18;
}

typedef struct W3dProps80240588 {
    unsigned char unknown_00[0x18];
    int value_18;
    int value_1c;
} W3dProps80240588;

void w3d_props_set_i32_80240588(Ptr32<W3dProps80240588> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240590(Ptr32<W3dProps80240588> props)
{
    return props->value_18;
}

void w3d_props_set_i32_80240598(Ptr32<W3dProps80240588> props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_802405a0(Ptr32<W3dProps80240588> props)
{
    return props->value_1c;
}

typedef struct W3dProps802405a8 {
    unsigned char unknown_00[0x18];
    int value_18;
    int value_1c;
    W3dString name_20;
    int value_24;
} W3dProps802405a8;

void w3d_props_set_i32_802405a8(Ptr32<W3dProps802405a8> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_802405b0(Ptr32<W3dProps802405a8> props)
{
    return props->value_18;
}

void w3d_props_set_i32_802405b8(Ptr32<W3dProps802405a8> props, int value)
{
    props->value_24 = value;
}

int w3d_props_get_i32_802405c0(Ptr32<W3dProps802405a8> props)
{
    return props->value_24;
}

void w3d_props_set_string_802405c8(Ptr32<W3dProps802405a8> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_20.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_20.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80240630(Ptr32<W3dProps802405a8> props)
{
    return &props->name_20;
}

void w3d_props_set_i32_80240638(Ptr32<W3dProps802405a8> props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_80240640(Ptr32<W3dProps802405a8> props)
{
    return props->value_1c;
}

typedef struct W3dProps80240648 {
    unsigned char unknown_00[0x18];
    int value_18;
    unsigned char unknown_1c[0x28 - 0x1c];
    int value_28;
} W3dProps80240648;

void w3d_props_set_i32_80240648(Ptr32<W3dProps80240648> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240650(Ptr32<W3dProps80240648> props)
{
    return props->value_18;
}

void w3d_props_set_i32_80240658(Ptr32<W3dProps80240648> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240660(Ptr32<W3dProps80240648> props)
{
    return props->value_28;
}

typedef struct W3dProps80240668 {
    unsigned char unknown_00[0x28];
    int value_28;
} W3dProps80240668;

void w3d_props_set_i32_80240668(Ptr32<W3dProps80240668> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240670(Ptr32<W3dProps80240668> props)
{
    return props->value_28;
}

typedef struct W3dProps80240678 {
    unsigned char unknown_00[0x28];
    int value_28;
} W3dProps80240678;

void w3d_props_set_i32_80240678(Ptr32<W3dProps80240678> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240680(Ptr32<W3dProps80240678> props)
{
    return props->value_28;
}

typedef struct W3dProps80240688 {
    unsigned char unknown_00[0x28];
    int value_28;
} W3dProps80240688;

void w3d_props_set_i32_80240688(Ptr32<W3dProps80240688> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240690(Ptr32<W3dProps80240688> props)
{
    return props->value_28;
}

}


