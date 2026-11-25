#include "w3d_ptr.h"
#line 1 "d_props_b.cpp"
/* Property accessors of data-driven engine records (0x80240698..0x80240780).
 *
 * Plain field getters/setters, reference-counted string fields and
 * interface-pointer fields. Records are split where an offset is reused with
 * a different type, so each struct covers one observed accessor block, not a
 * known class. Interface setters retain the new object (vtable +0x0c) before
 * releasing the previous one (vtable +0x10).
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80240698 {
    unsigned char unknown_00[0x28];
    int value_28;
    int value_2c;
    int value_30;
    int value_34;
    int value_38;
    int value_3c;
    int value_40;
    W3dString name_44;
    int value_48;
} W3dProps80240698;

void w3d_props_set_string_80240698(Ptr32<W3dProps80240698> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_44.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_44.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80240700(Ptr32<W3dProps80240698> props)
{
    return &props->name_44;
}

void w3d_props_set_i32_80240708(Ptr32<W3dProps80240698> props, int value)
{
    props->value_40 = value;
}

int w3d_props_get_i32_80240710(Ptr32<W3dProps80240698> props)
{
    return props->value_40;
}

void w3d_props_set_i32_80240718(Ptr32<W3dProps80240698> props, int value)
{
    props->value_3c = value;
}

int w3d_props_get_i32_80240720(Ptr32<W3dProps80240698> props)
{
    return props->value_3c;
}

void w3d_props_set_i32_80240728(Ptr32<W3dProps80240698> props, int value)
{
    props->value_38 = value;
}

int w3d_props_get_i32_80240730(Ptr32<W3dProps80240698> props)
{
    return props->value_38;
}

void w3d_props_set_i32_80240738(Ptr32<W3dProps80240698> props, int value)
{
    props->value_34 = value;
}

int w3d_props_get_i32_80240740(Ptr32<W3dProps80240698> props)
{
    return props->value_34;
}

void w3d_props_set_i32_80240748(Ptr32<W3dProps80240698> props, int value)
{
    props->value_30 = value;
}

int w3d_props_get_i32_80240750(Ptr32<W3dProps80240698> props)
{
    return props->value_30;
}

void w3d_props_set_i32_80240758(Ptr32<W3dProps80240698> props, int value)
{
    props->value_2c = value;
}

int w3d_props_get_i32_80240760(Ptr32<W3dProps80240698> props)
{
    return props->value_2c;
}

void w3d_props_set_i32_80240768(Ptr32<W3dProps80240698> props, int value)
{
    props->value_48 = value;
}

int w3d_props_get_i32_80240770(Ptr32<W3dProps80240698> props)
{
    return props->value_48;
}

void w3d_props_set_i32_80240778(Ptr32<W3dProps80240698> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240780(Ptr32<W3dProps80240698> props)
{
    return props->value_28;
}

}


