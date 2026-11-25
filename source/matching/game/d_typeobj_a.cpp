/* Registered engine object types (0x80241af4..0x80242d3c).
 *
 * Each type has a registry (W3dTypeList) and the same boilerplate: return the
 * registry, create (allocate, construct with the registry's type id, link it,
 * count it), unlink (remove, uncount), then the constructor and the deleting
 * destructor. Purposes of the types are unknown; names use addresses.
 */
#include "d_types.h"

extern "C" {

/* Type at 0x80241af4: 0x11c-byte objects, three string members. */
typedef struct W3dType80241af4 {
    W3dObjectBase base;
    unsigned char unknown_14[0x6c - 0x14];
    W3dString name_6c;
    unsigned char unknown_70[0x8c - 0x70];
    W3dString name_8c;
    unsigned char unknown_90[0x98 - 0x90];
    W3dString name_98;
    unsigned char unknown_9c[0x11c - 0x9c];
} W3dType80241af4;

extern W3dTypeList w3d_type_list_80367748;
extern void *w3d_vtable_8041b540[];
W3dType80241af4 *w3d_type_construct_80241bac(void *storage, unsigned int type_id);

W3dTypeList *w3d_type_list_80241af4(void)
{
    return &w3d_type_list_80367748;
}

W3dType80241af4 *w3d_type_create_80241b00(void)
{
    W3dType80241af4 *object = w3d_type_construct_80241bac(w3d_object_alloc_801ea70c(0x11c),
        w3d_type_list_80367748.type_id);
    w3d_state_register(&w3d_type_list_80367748, object ? &object->base.references : 0);
    w3d_type_list_80367748.count++;
    return object;
}

void w3d_type_unlink_80241b68(W3dType80241af4 *object)
{
    w3d_owner_list_remove(&w3d_type_list_80367748, &object->base.references);
    w3d_type_list_80367748.count--;
}

void w3d_type_destroy_80241e4c(W3dType80241af4 *object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b540;
    w3d_string_destroy(&object->name_98);
    w3d_string_destroy(&object->name_8c);
    w3d_string_destroy(&object->name_6c);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

/* Type at 0x80242780: 0x4c-byte objects with two string members. */
typedef struct W3dType80242780 {
    W3dObjectBase base;
    W3dString name_14;
    int value_18;
    W3dString name_1c;
    int value_20;
    unsigned char flag_24;
    unsigned char unknown_25[3];
    int value_28;
    int value_2c;
    unsigned char flag_30;
    unsigned char flag_31;
    unsigned char flag_32;
    unsigned char unknown_33;
    int value_34;
    int value_38;
    unsigned char flag_3c;
    unsigned char unknown_3d[3];
    int value_40;
    unsigned char flag_44;
    unsigned char flag_45;
    unsigned char unknown_46[2];
    int value_48;
} W3dType80242780;

extern W3dTypeList w3d_type_list_80367798;
extern void *w3d_vtable_8041b518[];

W3dTypeList *w3d_type_list_80242780(void)
{
    return &w3d_type_list_80367798;
}

W3dType80242780 *w3d_type_construct_80242838(W3dType80242780 *object, unsigned int type_id);

W3dType80242780 *w3d_type_create_8024278c(void)
{
    W3dType80242780 *object = w3d_type_construct_80242838(
        (W3dType80242780 *)w3d_object_alloc_801ea70c(0x4c), w3d_type_list_80367798.type_id);
    w3d_state_register(&w3d_type_list_80367798, object ? &object->base.references : 0);
    w3d_type_list_80367798.count++;
    return object;
}

void w3d_type_unlink_802427f4(W3dType80242780 *object)
{
    w3d_owner_list_remove(&w3d_type_list_80367798, &object->base.references);
    w3d_type_list_80367798.count--;
}

W3dType80242780 *w3d_type_construct_80242838(W3dType80242780 *object, unsigned int type_id)
{
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    object->base.vtbl = w3d_vtable_8041b518;
    w3d_string_init_empty(&object->name_14);
    object->value_18 = 0;
    w3d_string_init_empty(&object->name_1c);
    object->value_20 = 0;
    object->flag_24 = 0;
    object->value_28 = 0;
    object->value_2c = 0;
    object->flag_30 = 0;
    object->flag_31 = 0;
    object->flag_32 = 0;
    object->value_34 = 0;
    object->value_38 = 0;
    object->flag_3c = 0;
    object->value_40 = 0;
    object->flag_44 = 0;
    object->flag_45 = 0;
    object->value_48 = 0;
    return object;
}

void w3d_type_destroy_80242910(W3dType80242780 *object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b518;
    w3d_string_destroy(&object->name_1c);
    w3d_string_destroy(&object->name_14);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

/* Type at 0x80242bbc: 0x18-byte objects holding one shared interface. */
typedef struct W3dType80242bbc {
    W3dObjectBase base;
    W3dRefIface *object_14;
} W3dType80242bbc;

extern W3dTypeList w3d_type_list_803677e8;
extern void *w3d_vtable_8041b4f0[];
extern W3dRefIface *w3d_shared_iface_804b05b0;

W3dTypeList *w3d_type_list_80242bbc(void)
{
    return &w3d_type_list_803677e8;
}

W3dType80242bbc *w3d_type_construct_80242c74(W3dType80242bbc *object, unsigned int type_id);

W3dType80242bbc *w3d_type_create_80242bc8(void)
{
    W3dType80242bbc *object = w3d_type_construct_80242c74(
        (W3dType80242bbc *)w3d_object_alloc_801ea70c(0x18), w3d_type_list_803677e8.type_id);
    w3d_state_register(&w3d_type_list_803677e8, object ? &object->base.references : 0);
    w3d_type_list_803677e8.count++;
    return object;
}

void w3d_type_unlink_80242c30(W3dType80242bbc *object)
{
    w3d_owner_list_remove(&w3d_type_list_803677e8, &object->base.references);
    w3d_type_list_803677e8.count--;
}

W3dType80242bbc *w3d_type_construct_80242c74(W3dType80242bbc *object, unsigned int type_id)
{
    W3dRefIface *shared;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05b0;
    object->base.vtbl = w3d_vtable_8041b4f0;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    return object;
}

void w3d_type_destroy_80242cd0(W3dType80242bbc *object, int flags)
{
    W3dRefIface *shared;
    object->base.vtbl = w3d_vtable_8041b4f0;
    shared = object->object_14;
    if (shared)
        shared->vtbl->release(shared);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

}
