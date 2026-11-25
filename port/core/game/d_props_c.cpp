#include "w3d_ptr.h"
#line 1 "d_props_c.cpp"
/* Property accessors of data-driven engine records (0x80240788..0x80240928).
 *
 * Plain field getters/setters, reference-counted string fields and
 * interface-pointer fields. Records are split where an offset is reused with
 * a different type, so each struct covers one observed accessor block, not a
 * known class. Interface setters retain the new object (vtable +0x0c) before
 * releasing the previous one (vtable +0x10).
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80240788 {
    unsigned char unknown_00[0x14];
    int value_14;
    int value_18;
    int value_1c;
    int value_20;
    Ptr32<W3dRefIface> object_24;
    int value_28;
    int value_2c;
    int value_30;
    int value_34;
    Ptr32<W3dRefIface> object_38;
} W3dProps80240788;

void w3d_props_set_object_80240788(Ptr32<W3dProps80240788> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_24;
    props->object_24 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_802407ec(Ptr32<W3dProps80240788> props)
{
    return props->object_24;
}

void w3d_props_set_i32_802407f4(Ptr32<W3dProps80240788> props, int value)
{
    props->value_20 = value;
}

int w3d_props_get_i32_802407fc(Ptr32<W3dProps80240788> props)
{
    return props->value_20;
}

void w3d_props_set_i32_80240804(Ptr32<W3dProps80240788> props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_8024080c(Ptr32<W3dProps80240788> props)
{
    return props->value_1c;
}

void w3d_props_set_i32_80240814(Ptr32<W3dProps80240788> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_8024081c(Ptr32<W3dProps80240788> props)
{
    return props->value_18;
}

void w3d_props_set_i32_80240824(Ptr32<W3dProps80240788> props, int value)
{
    props->value_14 = value;
}

int w3d_props_get_i32_8024082c(Ptr32<W3dProps80240788> props)
{
    return props->value_14;
}

void w3d_props_set_object_80240834(Ptr32<W3dProps80240788> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_38;
    props->object_38 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80240898(Ptr32<W3dProps80240788> props)
{
    return props->object_38;
}

void w3d_props_set_i32_802408a0(Ptr32<W3dProps80240788> props, int value)
{
    props->value_34 = value;
}

int w3d_props_get_i32_802408a8(Ptr32<W3dProps80240788> props)
{
    return props->value_34;
}

void w3d_props_set_i32_802408b0(Ptr32<W3dProps80240788> props, int value)
{
    props->value_30 = value;
}

int w3d_props_get_i32_802408b8(Ptr32<W3dProps80240788> props)
{
    return props->value_30;
}

void w3d_props_set_i32_802408c0(Ptr32<W3dProps80240788> props, int value)
{
    props->value_2c = value;
}

int w3d_props_get_i32_802408c8(Ptr32<W3dProps80240788> props)
{
    return props->value_2c;
}

void w3d_props_set_i32_802408d0(Ptr32<W3dProps80240788> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_802408d8(Ptr32<W3dProps80240788> props)
{
    return props->value_28;
}

typedef struct W3dProps802408e0 {
    unsigned char unknown_00[0x14];
    int value_14;
    int value_18;
    int value_1c;
    int value_20;
    int value_24;
} W3dProps802408e0;

void w3d_props_set_i32_802408e0(Ptr32<W3dProps802408e0> props, int value)
{
    props->value_24 = value;
}

int w3d_props_get_i32_802408e8(Ptr32<W3dProps802408e0> props)
{
    return props->value_24;
}

void w3d_props_set_i32_802408f0(Ptr32<W3dProps802408e0> props, int value)
{
    props->value_20 = value;
}

int w3d_props_get_i32_802408f8(Ptr32<W3dProps802408e0> props)
{
    return props->value_20;
}

void w3d_props_set_i32_80240900(Ptr32<W3dProps802408e0> props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_80240908(Ptr32<W3dProps802408e0> props)
{
    return props->value_1c;
}

void w3d_props_set_i32_80240910(Ptr32<W3dProps802408e0> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240918(Ptr32<W3dProps802408e0> props)
{
    return props->value_18;
}

void w3d_props_set_i32_80240920(Ptr32<W3dProps802408e0> props, int value)
{
    props->value_14 = value;
}

int w3d_props_get_i32_80240928(Ptr32<W3dProps802408e0> props)
{
    return props->value_14;
}

}


