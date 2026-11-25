/* Registered engine object types (0x80247300..0x80247834).
 *
 * Same per-type boilerplate as d_typeobj_a..c. The script-registration
 * routines here only declare properties from static tables and finish the
 * type. The callee roles (property, member, link) are inferred from which
 * routine each table is passed to, not from their contents.
 */
#include "d_types.h"

extern "C" {

void * w3d_script_add_prop_801ec52c(void *state, void *prop);
void * w3d_script_add_member_801eb674(void *state, void *prop);
void * w3d_script_add_link_801ebf38(void *state, void *prop);
void w3d_script_finish_type_801e8d9c(void *state);

/* Type registered at 0x80367ba8: 0xac-byte objects. */
/* Derived from the 0xa8-byte type registered at 0x80367a28 (d_typeobj_c). */
typedef struct W3dType80247300 {
    W3dObjectBase base;
    unsigned char unknown_14[0xa8 - 0x14];
    int value_a8;
} W3dType80247300;

extern void *w3d_vtable_8041b310[];
W3dObjectBase *w3d_type_construct_80246f1c(W3dObjectBase *object, unsigned int type_id);
void w3d_type_destroy_80247000(W3dObjectBase *object, int flags);
extern unsigned char w3d_script_prop_803c3c90[];

extern W3dTypeList w3d_type_list_80367ba8;
W3dType80247300 *w3d_type_construct_802473b8(W3dType80247300 *object, unsigned int type_id);

W3dTypeList *w3d_type_list_80247300(void)
{
    return &w3d_type_list_80367ba8;
}

W3dType80247300 *w3d_type_create_8024730c(void)
{
    W3dType80247300 *object = w3d_type_construct_802473b8((W3dType80247300 *)w3d_object_alloc_801ea70c(0xac),
        w3d_type_list_80367ba8.type_id);
    w3d_state_register(&w3d_type_list_80367ba8, object ? &object->base.references : 0);
    w3d_type_list_80367ba8.count++;
    return object;
}

void w3d_type_unlink_80247374(W3dType80247300 *object)
{
    w3d_owner_list_remove(&w3d_type_list_80367ba8, &object->base.references);
    w3d_type_list_80367ba8.count--;
}

W3dType80247300 *w3d_type_construct_802473b8(W3dType80247300 *object, unsigned int type_id)
{
    w3d_type_construct_80246f1c(&object->base, type_id);
    object->base.vtbl = w3d_vtable_8041b310;
    object->value_a8 = 0;
    return object;
}

void w3d_type_destroy_802473fc(W3dType80247300 *object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b310;
    w3d_type_destroy_80247000(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

int w3d_type_register_8024744c(void *state)
{
    w3d_script_add_member_801eb674(state, w3d_script_prop_803c3c90);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}


/* Type registered at 0x80367bf8: 0x34-byte objects. */
typedef struct W3dType8024748c {
    W3dObjectBase base;
    float values_14[7];
    int value_30;
} W3dType8024748c;

extern void *w3d_vtable_8041b2e8[];
extern const float w3d_f32_803c3cd8[];
extern unsigned char w3d_script_prop_803c3ce8[];
extern unsigned char w3d_script_prop_803c3d1c[];
extern unsigned char w3d_script_prop_803c3d44[];
extern unsigned char w3d_script_prop_803c3d6c[];
extern unsigned char w3d_script_prop_803c3d94[];
extern unsigned char w3d_script_prop_803c3dc8[];
extern unsigned char w3d_script_prop_803c3df0[];
extern unsigned char w3d_script_prop_803c3e2c[];

extern W3dTypeList w3d_type_list_80367bf8;
W3dType8024748c *w3d_type_construct_80247544(W3dType8024748c *object, unsigned int type_id);

W3dTypeList *w3d_type_list_8024748c(void)
{
    return &w3d_type_list_80367bf8;
}

W3dType8024748c *w3d_type_create_80247498(void)
{
    W3dType8024748c *object = w3d_type_construct_80247544((W3dType8024748c *)w3d_object_alloc_801ea70c(0x34),
        w3d_type_list_80367bf8.type_id);
    w3d_state_register(&w3d_type_list_80367bf8, object ? &object->base.references : 0);
    w3d_type_list_80367bf8.count++;
    return object;
}

void w3d_type_unlink_80247500(W3dType8024748c *object)
{
    w3d_owner_list_remove(&w3d_type_list_80367bf8, &object->base.references);
    w3d_type_list_80367bf8.count--;
}

W3dType8024748c *w3d_type_construct_80247544(W3dType8024748c *object, unsigned int type_id)
{
    float zero;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    zero = w3d_f32_803c3cd8[0];
    object->base.vtbl = w3d_vtable_8041b2e8;
    object->values_14[0] = zero;
    object->values_14[1] = zero;
    object->values_14[2] = zero;
    object->values_14[3] = zero;
    object->values_14[4] = zero;
    object->values_14[5] = zero;
    object->values_14[6] = zero;
    object->value_30 = 0;
    return object;
}

void w3d_type_destroy_802475ac(W3dType8024748c *object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b2e8;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

int w3d_type_register_802475fc(void *state)
{
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3ce8);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3d1c);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3d44);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3d6c);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3d94);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3dc8);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c3df0);
    w3d_script_add_member_801eb674(state, w3d_script_prop_803c3e2c);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}


/* Type registered at 0x80367c48: 0x18-byte objects. */
typedef struct W3dType802476ac {
    W3dObjectBase base;
    int value_14;
} W3dType802476ac;

extern void *w3d_vtable_8041b2c0[];
extern unsigned char w3d_script_prop_803c3e68[];

extern W3dTypeList w3d_type_list_80367c48;
W3dType802476ac *w3d_type_construct_80247764(W3dType802476ac *object, unsigned int type_id);

W3dTypeList *w3d_type_list_802476ac(void)
{
    return &w3d_type_list_80367c48;
}

W3dType802476ac *w3d_type_create_802476b8(void)
{
    W3dType802476ac *object = w3d_type_construct_80247764((W3dType802476ac *)w3d_object_alloc_801ea70c(0x18),
        w3d_type_list_80367c48.type_id);
    w3d_state_register(&w3d_type_list_80367c48, object ? &object->base.references : 0);
    w3d_type_list_80367c48.count++;
    return object;
}

void w3d_type_unlink_80247720(W3dType802476ac *object)
{
    w3d_owner_list_remove(&w3d_type_list_80367c48, &object->base.references);
    w3d_type_list_80367c48.count--;
}

W3dType802476ac *w3d_type_construct_80247764(W3dType802476ac *object, unsigned int type_id)
{
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    object->base.vtbl = w3d_vtable_8041b2c0;
    object->value_14 = 0;
    return object;
}

void w3d_type_destroy_802477a8(W3dType802476ac *object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b2c0;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

int w3d_type_register_802477f8(void *state)
{
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3e68);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}


}
