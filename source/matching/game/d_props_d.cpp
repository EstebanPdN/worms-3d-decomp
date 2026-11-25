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
    W3dRefIface *object_30;
    W3dRefIface *object_34;
    W3dRefIface *object_38;
    W3dRefIface *object_3c;
    W3dRefIface *object_40;
    int value_44;
    int value_48;
} W3dProps80240930;

void w3d_props_set_object_80240930(W3dProps80240930 *props, W3dRefIface *object)
{
    W3dRefIface *old = props->object_40;
    props->object_40 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

W3dRefIface *w3d_props_get_object_80240994(W3dProps80240930 *props)
{
    return props->object_40;
}

void w3d_props_set_object_8024099c(W3dProps80240930 *props, W3dRefIface *object)
{
    W3dRefIface *old = props->object_3c;
    props->object_3c = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

W3dRefIface *w3d_props_get_object_80240a00(W3dProps80240930 *props)
{
    return props->object_3c;
}

void w3d_props_set_object_80240a08(W3dProps80240930 *props, W3dRefIface *object)
{
    W3dRefIface *old = props->object_38;
    props->object_38 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

W3dRefIface *w3d_props_get_object_80240a6c(W3dProps80240930 *props)
{
    return props->object_38;
}

void w3d_props_set_object_80240a74(W3dProps80240930 *props, W3dRefIface *object)
{
    W3dRefIface *old = props->object_34;
    props->object_34 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

W3dRefIface *w3d_props_get_object_80240ad8(W3dProps80240930 *props)
{
    return props->object_34;
}

void w3d_props_set_object_80240ae0(W3dProps80240930 *props, W3dRefIface *object)
{
    W3dRefIface *old = props->object_30;
    props->object_30 = object;
    if (object) object->vtbl->retain(object);
    if (old) old->vtbl->release(old);
}

W3dRefIface *w3d_props_get_object_80240b44(W3dProps80240930 *props)
{
    return props->object_30;
}

void w3d_props_set_i32_80240b4c(W3dProps80240930 *props, int value)
{
    props->value_28 = value;
}

int w3d_props_get_i32_80240b54(W3dProps80240930 *props)
{
    return props->value_28;
}

void w3d_props_set_i32_80240b5c(W3dProps80240930 *props, int value)
{
    props->value_48 = value;
}

int w3d_props_get_i32_80240b64(W3dProps80240930 *props)
{
    return props->value_48;
}

void w3d_props_set_i32_80240b6c(W3dProps80240930 *props, int value)
{
    props->value_24 = value;
}

int w3d_props_get_i32_80240b74(W3dProps80240930 *props)
{
    return props->value_24;
}

void w3d_props_set_i32_80240b7c(W3dProps80240930 *props, int value)
{
    props->value_20 = value;
}

int w3d_props_get_i32_80240b84(W3dProps80240930 *props)
{
    return props->value_20;
}

void w3d_props_set_i32_80240b8c(W3dProps80240930 *props, int value)
{
    props->value_1c = value;
}

int w3d_props_get_i32_80240b94(W3dProps80240930 *props)
{
    return props->value_1c;
}

void w3d_props_set_i32_80240b9c(W3dProps80240930 *props, int value)
{
    props->value_44 = value;
}

int w3d_props_get_i32_80240ba4(W3dProps80240930 *props)
{
    return props->value_44;
}

void w3d_props_set_i32_80240bac(W3dProps80240930 *props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240bb4(W3dProps80240930 *props)
{
    return props->value_18;
}

void w3d_props_set_i32_80240bbc(W3dProps80240930 *props, int value)
{
    props->value_14 = value;
}

int w3d_props_get_i32_80240bc4(W3dProps80240930 *props)
{
    return props->value_14;
}

typedef struct W3dProps80240bcc {
    unsigned char unknown_00[0x14];
    int value_14;
    int value_18;
} W3dProps80240bcc;

int w3d_props_get_i32_80240bcc(W3dProps80240bcc *props)
{
    return props->value_14;
}

void w3d_props_set_i32_80240bd4(W3dProps80240bcc *props, int value)
{
    props->value_18 = value;
}

int w3d_props_get_i32_80240bdc(W3dProps80240bcc *props)
{
    return props->value_18;
}

}
