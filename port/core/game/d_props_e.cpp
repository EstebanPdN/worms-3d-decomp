#include "w3d_ptr.h"
#line 1 "d_props_e.cpp"
/* Property accessors of data-driven engine records (0x80241334..0x802416b8).
 *
 * Plain field getters/setters, reference-counted string fields, interface
 * pointers (retain new via vtable +0x0c, release old via +0x10) and in-place
 * vector/matrix values copied by assignment. Each struct covers one observed
 * accessor block. The block from 0x802413a0 likely belongs to the 0x11c-byte
 * object created at 0x80241b00 (offsets up to 0x110 fit inside it).
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80241334 {
    unsigned char unknown_00[0x1c];
    Ptr32<W3dRefIface> object_1c;
} W3dProps80241334;

void w3d_props_set_object_80241334(Ptr32<W3dProps80241334> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_1c;
    props->object_1c = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80241398(Ptr32<W3dProps80241334> props)
{
    return props->object_1c;
}

typedef struct W3dProps802413a0 {
    unsigned char unknown_00[0x1c];
    W3dMatrix44 matrix_1c;
    unsigned char unknown_5c[0x80 - 0x5c];
    W3dVector3 vector_80;
    W3dVector3 vector_8c;
    W3dVector3 vector_98;
    W3dVector3 vector_a4;
    W3dVector3 vector_b0;
    W3dVector3 vector_bc;
    W3dVector3 vector_c8;
    W3dVector3 vector_d4;
    unsigned char unknown_e0[0x100 - 0xe0];
    W3dString name_100;
    W3dString name_104;
    Ptr32<W3dRefIface> object_108;
    int value_10c;
    int value_110;
} W3dProps802413a0;

void w3d_props_set_i32_802413a0(Ptr32<W3dProps802413a0> props, int value)
{
    props->value_110 = value;
}

int w3d_props_get_i32_802413a8(Ptr32<W3dProps802413a0> props)
{
    return props->value_110;
}

void w3d_props_set_i32_802413b0(Ptr32<W3dProps802413a0> props, int value)
{
    props->value_10c = value;
}

int w3d_props_get_i32_802413b8(Ptr32<W3dProps802413a0> props)
{
    return props->value_10c;
}

void w3d_props_set_object_802413c0(Ptr32<W3dProps802413a0> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_108;
    props->object_108 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80241424(Ptr32<W3dProps802413a0> props)
{
    return props->object_108;
}

void w3d_props_set_string_8024142c(Ptr32<W3dProps802413a0> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_104.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_104.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241494(Ptr32<W3dProps802413a0> props)
{
    return &props->name_104;
}

void w3d_props_set_mat44_8024149c(Ptr32<W3dProps802413a0> props, Ptr32<const W3dMatrix44> value)
{
    props->matrix_1c = *value;
}

Ptr32<W3dMatrix44> w3d_props_field_80241508(Ptr32<W3dProps802413a0> props)
{
    return &props->matrix_1c;
}

void w3d_props_set_string_80241510(Ptr32<W3dProps802413a0> props, Ptr32<W3dString> value)
{
    Ptr32<W3dStringHeader> old;
    ++((Ptr32<W3dStringHeader>)(value->data - 6))->references;
    old = (Ptr32<W3dStringHeader>)(props->name_100.data - 6);
    if (--old->references == 0) w3d_string_release_header(old);
    props->name_100.data = value->data;
}

Ptr32<W3dString> w3d_props_field_80241578(Ptr32<W3dProps802413a0> props)
{
    return &props->name_100;
}

void w3d_props_set_vec3_80241580(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_d4 = *value;
}

Ptr32<W3dVector3> w3d_props_field_802415a0(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_d4;
}

void w3d_props_set_vec3_802415a8(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_c8 = *value;
}

Ptr32<W3dVector3> w3d_props_field_802415c8(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_c8;
}

void w3d_props_set_vec3_802415d0(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_bc = *value;
}

Ptr32<W3dVector3> w3d_props_field_802415f0(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_bc;
}

void w3d_props_set_vec3_802415f8(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_b0 = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241618(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_b0;
}

void w3d_props_set_vec3_80241620(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_a4 = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241640(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_a4;
}

void w3d_props_set_vec3_80241648(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_98 = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241668(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_98;
}

void w3d_props_set_vec3_80241670(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_8c = *value;
}

Ptr32<W3dVector3> w3d_props_field_80241690(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_8c;
}

void w3d_props_set_vec3_80241698(Ptr32<W3dProps802413a0> props, Ptr32<const W3dVector3> value)
{
    props->vector_80 = *value;
}

Ptr32<W3dVector3> w3d_props_field_802416b8(Ptr32<W3dProps802413a0> props)
{
    return &props->vector_80;
}

}


