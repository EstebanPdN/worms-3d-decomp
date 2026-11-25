/* Property accessors of a registered engine type (0x80249590..0x802496f8).
 *
 * These accessors cover the 0x11c-byte engine type registered at 0x80367748
 * (constructed by 0x80241bac): plain fields, reference-counted strings,
 * in-place vectors and signed byte flags. Each struct covers one observed
 * accessor block; field meanings are unknown.
 */
#include "d_types.h"

extern "C" {

typedef struct W3dProps80249590 {
    unsigned char unknown_00[0x90];
    float value_90;
    unsigned char unknown_94[0xac - 0x94];
    signed char value_ac;
    signed char value_ad;
    signed char value_ae;
    signed char value_af;
    signed char value_b0;
    signed char value_b1;
    signed char value_b2;
    signed char value_b3;
    int value_b4;
    unsigned char unknown_b8[0xec - 0xb8];
    signed char value_ec;
    unsigned char unknown_ed[0xef - 0xed];
    signed char value_ef;
    signed char value_f0;
    unsigned char unknown_f1[0xf2 - 0xf1];
    signed char value_f2;
    signed char value_f3;
    signed char value_f4;
    signed char value_f5;
    signed char value_f6;
    unsigned char unknown_f7[0x10a - 0xf7];
    signed char value_10a;
} W3dProps80249590;

void w3d_props_set_f32_80249590(W3dProps80249590 *props, float value)
{
    props->value_90 = value;
}

float w3d_props_get_f32_80249598(W3dProps80249590 *props)
{
    return props->value_90;
}

void w3d_props_set_i32_802495a0(W3dProps80249590 *props, int value)
{
    props->value_b4 = value;
}

int w3d_props_get_i32_802495a8(W3dProps80249590 *props)
{
    return props->value_b4;
}

void w3d_props_set_s8_802495b0(W3dProps80249590 *props, signed char value)
{
    props->value_b3 = value;
}

signed char w3d_props_get_s8_802495b8(W3dProps80249590 *props)
{
    return props->value_b3;
}

void w3d_props_set_s8_802495c4(W3dProps80249590 *props, signed char value)
{
    props->value_b2 = value;
}

signed char w3d_props_get_s8_802495cc(W3dProps80249590 *props)
{
    return props->value_b2;
}

void w3d_props_set_s8_802495d8(W3dProps80249590 *props, signed char value)
{
    props->value_ac = value;
}

signed char w3d_props_get_s8_802495e0(W3dProps80249590 *props)
{
    return props->value_ac;
}

void w3d_props_set_s8_802495ec(W3dProps80249590 *props, signed char value)
{
    props->value_b0 = value;
}

signed char w3d_props_get_s8_802495f4(W3dProps80249590 *props)
{
    return props->value_b0;
}

void w3d_props_set_s8_80249600(W3dProps80249590 *props, signed char value)
{
    props->value_af = value;
}

signed char w3d_props_get_s8_80249608(W3dProps80249590 *props)
{
    return props->value_af;
}

void w3d_props_set_s8_80249614(W3dProps80249590 *props, signed char value)
{
    props->value_ae = value;
}

signed char w3d_props_get_s8_8024961c(W3dProps80249590 *props)
{
    return props->value_ae;
}

void w3d_props_set_s8_80249628(W3dProps80249590 *props, signed char value)
{
    props->value_ad = value;
}

signed char w3d_props_get_s8_80249630(W3dProps80249590 *props)
{
    return props->value_ad;
}

void w3d_props_set_s8_8024963c(W3dProps80249590 *props, signed char value)
{
    props->value_b1 = value;
}

signed char w3d_props_get_s8_80249644(W3dProps80249590 *props)
{
    return props->value_b1;
}

void w3d_props_set_s8_80249650(W3dProps80249590 *props, signed char value)
{
    props->value_f6 = value;
}

signed char w3d_props_get_s8_80249658(W3dProps80249590 *props)
{
    return props->value_f6;
}

void w3d_props_set_s8_80249664(W3dProps80249590 *props, signed char value)
{
    props->value_ec = value;
}

signed char w3d_props_get_s8_8024966c(W3dProps80249590 *props)
{
    return props->value_ec;
}

void w3d_props_set_s8_80249678(W3dProps80249590 *props, signed char value)
{
    props->value_f5 = value;
}

signed char w3d_props_get_s8_80249680(W3dProps80249590 *props)
{
    return props->value_f5;
}

void w3d_props_set_s8_8024968c(W3dProps80249590 *props, signed char value)
{
    props->value_f4 = value;
}

signed char w3d_props_get_s8_80249694(W3dProps80249590 *props)
{
    return props->value_f4;
}

void w3d_props_set_s8_802496a0(W3dProps80249590 *props, signed char value)
{
    props->value_f3 = value;
}

signed char w3d_props_get_s8_802496a8(W3dProps80249590 *props)
{
    return props->value_f3;
}

void w3d_props_set_s8_802496b4(W3dProps80249590 *props, signed char value)
{
    props->value_f2 = value;
}

signed char w3d_props_get_s8_802496bc(W3dProps80249590 *props)
{
    return props->value_f2;
}

void w3d_props_set_s8_802496c8(W3dProps80249590 *props, signed char value)
{
    props->value_10a = value;
}

signed char w3d_props_get_s8_802496d0(W3dProps80249590 *props)
{
    return props->value_10a;
}

void w3d_props_set_s8_802496dc(W3dProps80249590 *props, signed char value)
{
    props->value_f0 = value;
}

signed char w3d_props_get_s8_802496e4(W3dProps80249590 *props)
{
    return props->value_f0;
}

void w3d_props_set_s8_802496f0(W3dProps80249590 *props, signed char value)
{
    props->value_ef = value;
}

signed char w3d_props_get_s8_802496f8(W3dProps80249590 *props)
{
    return props->value_ef;
}

}
