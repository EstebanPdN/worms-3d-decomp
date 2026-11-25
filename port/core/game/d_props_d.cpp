#include "w3d_ptr.h"
#line 1 "d_props_d.cpp"
/* Property accessors of data-driven engine records (0x80240930..0x80240bdc).
 *
 * Plain field getters/setters, reference-counted string fields and
 * interface-pointer fields. Records are split where an offset is reused with
 * a different type, so each struct covers one observed accessor block, not a
 * known class. Interface setters retain the new object (vtable +0x0c) before
 * releasing the previous one (vtable +0x10).
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80240930 {
    unsigned char unknown_00[0x14];
    int value_14;
    int value_18;
    int value_1c;
    int value_20;
    int value_24;
    int value_28;
    unsigned char unknown_2c[0x30 - 0x2c];
    Ptr32<W3dRefIface> object_30;
    Ptr32<W3dRefIface> object_34;
    Ptr32<W3dRefIface> object_38;
    Ptr32<W3dRefIface> object_3c;
    Ptr32<W3dRefIface> object_40;
    int value_44;
    int value_48;
} W3dProps80240930;

void w3d_props_set_object_80240930(Ptr32<W3dProps80240930> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_40;
    props->object_40 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80240994(Ptr32<W3dProps80240930> props)
{
    return props->object_40;
}

void w3d_props_set_object_8024099c(Ptr32<W3dProps80240930> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_3c;
    props->object_3c = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80240a00(Ptr32<W3dProps80240930> props)
{
    return props->object_3c;
}

void w3d_props_set_object_80240a08(Ptr32<W3dProps80240930> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_38;
    props->object_38 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80240a6c(Ptr32<W3dProps80240930> props)
{
    return props->object_38;
}

void w3d_props_set_object_80240a74(Ptr32<W3dProps80240930> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_34;
    props->object_34 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80240ad8(Ptr32<W3dProps80240930> props)
{
    return props->object_34;
}

void w3d_props_set_object_80240ae0(Ptr32<W3dProps80240930> props, Ptr32<W3dRefIface> object)
{
    Ptr32<W3dRefIface> old = props->object_30;
    props->object_30 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

Ptr32<W3dRefIface> w3d_props_get_object_80240b44(Ptr32<W3dProps80240930> props)
{
    return props->object_30;
}

void w3d_props_set_i32_80240b4c(Ptr32<W3dProps80240930> props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240b54(Ptr32<W3dProps80240930> props)
{
    return props->value_28;
}

void w3d_props_set_i32_80240b5c(Ptr32<W3dProps80240930> props, int value)
{
    props->value_48 = value;
}

int w3d_props_get_i32_80240b64(Ptr32<W3dProps80240930> props)
{
    return props->value_48;
}

void w3d_props_set_i32_80240b6c(Ptr32<W3dProps80240930> props, int value)
{
    props->value_24 = value;
}

int w3d_props_get_i32_80240b74(Ptr32<W3dProps80240930> props)
{
    return props->value_24;
}

void w3d_props_set_i32_80240b7c(Ptr32<W3dProps80240930> props, int value)
{
    props->value_20 = value;
}

int w3d_props_get_i32_80240b84(Ptr32<W3dProps80240930> props)
{
    return props->value_20;
}

void w3d_props_set_i32_80240b8c(Ptr32<W3dProps80240930> props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_80240b94(Ptr32<W3dProps80240930> props)
{
    return props->value_1c;
}

void w3d_props_set_i32_80240b9c(Ptr32<W3dProps80240930> props, int value)
{
    props->value_44 = value;
}

int w3d_props_get_i32_80240ba4(Ptr32<W3dProps80240930> props)
{
    return props->value_44;
}

void w3d_props_set_i32_80240bac(Ptr32<W3dProps80240930> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240bb4(Ptr32<W3dProps80240930> props)
{
    return props->value_18;
}

void w3d_props_set_i32_80240bbc(Ptr32<W3dProps80240930> props, int value)
{
    props->value_14 = value;
}

int w3d_props_get_i32_80240bc4(Ptr32<W3dProps80240930> props)
{
    return props->value_14;
}

typedef struct W3dProps80240bcc {
    unsigned char unknown_00[0x14];
    int value_14;
    int value_18;
} W3dProps80240bcc;

int w3d_props_get_i32_80240bcc(Ptr32<W3dProps80240bcc> props)
{
    return props->value_14;
}

void w3d_props_set_i32_80240bd4(Ptr32<W3dProps80240bcc> props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240bdc(Ptr32<W3dProps80240bcc> props)
{
    return props->value_18;
}

}


