#include "w3d_ptr.h"
#line 1 "d_typeobj_e.cpp"
/* Registered engine object types (0x80247838..0x80248194).
 *
 * Same per-type boilerplate as d_typeobj_a..d. One type opens two
 * ten-element record arrays in its constructor and clears them; one resets
 * its fields through a separate reset routine (0x80249104). The lazy
 * static-descriptor registrations (0x80247a44, 0x80248198) are not included.
 */
#include "d_types.h"

extern "C" {

extern Ptr32<W3dRefIface> w3d_shared_iface_804b05a8;
extern Ptr32<W3dRefIface> w3d_shared_iface_804b05b0;

Ptr32<void> w3d_script_add_link_801ebf38(Ptr32<void> state, Ptr32<void> prop);
void w3d_script_finish_type_801e8d9c(Ptr32<void> state);

static inline void w3d_iface_release(Ptr32<W3dRefIface> object)
{
    if (object)
        object->vtbl->release(object);
}

/* Type registered at 0x80367c98: 0x1c-byte objects. */
typedef struct W3dType80247838 {
    W3dObjectBase base;
    Ptr32<W3dRefIface> object_14;
    Ptr32<W3dRefIface> object_18;
} W3dType80247838;

extern Ptr32<void> w3d_vtable_8041b298[];
/* Open two record arrays for writing (count, flags, previous-count out). */
Ptr32<int> w3d_array_write_8024b8dc(Ptr32<W3dType80247838> object, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous);
Ptr32<int> w3d_array_write_8024b998(Ptr32<W3dType80247838> object, unsigned int count, unsigned int flags,
    Ptr32<unsigned int> previous);

extern W3dTypeList w3d_type_list_80367c98;
Ptr32<W3dType80247838> w3d_type_construct_802478f0(Ptr32<W3dType80247838> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80247838(void)
{
    return &w3d_type_list_80367c98;
}

Ptr32<W3dType80247838> w3d_type_create_80247844(void)
{
    Ptr32<W3dType80247838> object = w3d_type_construct_802478f0((Ptr32<W3dType80247838>)w3d_object_alloc_801ea70c(0x1c),
        w3d_type_list_80367c98.type_id);
    w3d_state_register(&w3d_type_list_80367c98, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367c98.count++;
    return object;
}

void w3d_type_unlink_802478ac(Ptr32<W3dType80247838> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367c98, &object->base.references);
    w3d_type_list_80367c98.count--;
}

Ptr32<W3dType80247838> w3d_type_construct_802478f0(Ptr32<W3dType80247838> object, unsigned int type_id)
{
    Ptr32<W3dRefIface> shared;
    Ptr32<int> first; Ptr32<int> second;
    int i;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05a8;
    object->base.vtbl = w3d_vtable_8041b298;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    shared = w3d_shared_iface_804b05a8;
    object->object_18 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    first = w3d_array_write_8024b8dc(object, 10, 0, 0);
    second = w3d_array_write_8024b998(object, 10, 0, 0);
    for (i = 0; i < 10; i++) {
        first[i] = 0;
        second[i] = 0;
    }
    return object;
}

void w3d_type_destroy_802479b8(Ptr32<W3dType80247838> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b298;
    w3d_iface_release(object->object_18);
    w3d_iface_release(object->object_14);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367ce8: 0x18-byte objects. */
typedef struct W3dType80247ba0 {
    W3dObjectBase base;
    int value_14;
} W3dType80247ba0;

extern Ptr32<void> w3d_vtable_8041b270[];
extern unsigned char w3d_script_prop_803c3ed0[];

extern W3dTypeList w3d_type_list_80367ce8;
Ptr32<W3dType80247ba0> w3d_type_construct_80247c58(Ptr32<W3dType80247ba0> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80247ba0(void)
{
    return &w3d_type_list_80367ce8;
}

Ptr32<W3dType80247ba0> w3d_type_create_80247bac(void)
{
    Ptr32<W3dType80247ba0> object = w3d_type_construct_80247c58((Ptr32<W3dType80247ba0>)w3d_object_alloc_801ea70c(0x18),
        w3d_type_list_80367ce8.type_id);
    w3d_state_register(&w3d_type_list_80367ce8, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367ce8.count++;
    return object;
}

void w3d_type_unlink_80247c14(Ptr32<W3dType80247ba0> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367ce8, &object->base.references);
    w3d_type_list_80367ce8.count--;
}

Ptr32<W3dType80247ba0> w3d_type_construct_80247c58(Ptr32<W3dType80247ba0> object, unsigned int type_id)
{
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    object->base.vtbl = w3d_vtable_8041b270;
    object->value_14 = 0;
    return object;
}

void w3d_type_destroy_80247c9c(Ptr32<W3dType80247ba0> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b270;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

int w3d_type_register_80247cec(Ptr32<void> state)
{
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3ed0);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}


/* Type registered at 0x80367d38: 0x44-byte objects. */
typedef struct W3dType80247d2c {
    W3dObjectBase base;
    int values_14[12];
} W3dType80247d2c;

extern Ptr32<void> w3d_vtable_8041b248[];
void w3d_type_reset_80249104(Ptr32<W3dType80247d2c> object);

extern W3dTypeList w3d_type_list_80367d38;
Ptr32<W3dType80247d2c> w3d_type_construct_80247de4(Ptr32<W3dType80247d2c> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80247d2c(void)
{
    return &w3d_type_list_80367d38;
}

Ptr32<W3dType80247d2c> w3d_type_create_80247d38(void)
{
    Ptr32<W3dType80247d2c> object = w3d_type_construct_80247de4((Ptr32<W3dType80247d2c>)w3d_object_alloc_801ea70c(0x44),
        w3d_type_list_80367d38.type_id);
    w3d_state_register(&w3d_type_list_80367d38, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367d38.count++;
    return object;
}

void w3d_type_unlink_80247da0(Ptr32<W3dType80247d2c> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367d38, &object->base.references);
    w3d_type_list_80367d38.count--;
}

Ptr32<W3dType80247d2c> w3d_type_construct_80247de4(Ptr32<W3dType80247d2c> object, unsigned int type_id)
{
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    object->base.vtbl = w3d_vtable_8041b248;
    object->values_14[0] = 0;
    object->values_14[1] = 0;
    object->values_14[2] = 0;
    object->values_14[3] = 0;
    object->values_14[4] = 0;
    object->values_14[5] = 0;
    object->values_14[6] = 0;
    object->values_14[7] = 0;
    object->values_14[8] = 0;
    object->values_14[9] = 0;
    object->values_14[10] = 0;
    object->values_14[11] = 0;
    w3d_type_reset_80249104(object);
    return object;
}

void w3d_type_destroy_80247e5c(Ptr32<W3dType80247d2c> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b248;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

extern unsigned char w3d_script_prop_803c3f1c[];
extern unsigned char w3d_script_prop_803c3f54[];
extern unsigned char w3d_script_prop_803c3f88[];
extern unsigned char w3d_script_prop_803c3fbc[];
extern unsigned char w3d_script_prop_803c3ff4[];
extern unsigned char w3d_script_prop_803c402c[];
extern unsigned char w3d_script_prop_803c4064[];
extern unsigned char w3d_script_prop_803c409c[];
extern unsigned char w3d_script_prop_803c40d4[];
extern unsigned char w3d_script_prop_803c4108[];
extern unsigned char w3d_script_prop_803c4140[];
extern unsigned char w3d_script_prop_803c4178[];

int w3d_type_register_80247eac(Ptr32<void> state)
{
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3f1c);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3f54);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3f88);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3fbc);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c3ff4);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c402c);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c4064);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c409c);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c40d4);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c4108);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c4140);
    w3d_script_add_link_801ebf38(state, w3d_script_prop_803c4178);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}


/* Type registered at 0x80367d88: 0x20-byte objects. */
typedef struct W3dType80247f9c {
    W3dObjectBase base;
    Ptr32<W3dRefIface> object_14;
    Ptr32<W3dRefIface> object_18;
    Ptr32<W3dRefIface> object_1c;
} W3dType80247f9c;

extern Ptr32<void> w3d_vtable_8041b220[];

extern W3dTypeList w3d_type_list_80367d88;
Ptr32<W3dType80247f9c> w3d_type_construct_80248054(Ptr32<W3dType80247f9c> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80247f9c(void)
{
    return &w3d_type_list_80367d88;
}

Ptr32<W3dType80247f9c> w3d_type_create_80247fa8(void)
{
    Ptr32<W3dType80247f9c> object = w3d_type_construct_80248054((Ptr32<W3dType80247f9c>)w3d_object_alloc_801ea70c(0x20),
        w3d_type_list_80367d88.type_id);
    w3d_state_register(&w3d_type_list_80367d88, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367d88.count++;
    return object;
}

void w3d_type_unlink_80248010(Ptr32<W3dType80247f9c> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367d88, &object->base.references);
    w3d_type_list_80367d88.count--;
}

Ptr32<W3dType80247f9c> w3d_type_construct_80248054(Ptr32<W3dType80247f9c> object, unsigned int type_id)
{
    Ptr32<W3dRefIface> shared;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05a8;
    object->base.vtbl = w3d_vtable_8041b220;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    shared = w3d_shared_iface_804b05b0;
    object->object_18 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    shared = w3d_shared_iface_804b05b0;
    object->object_1c = shared;
    if (shared)
        shared->vtbl->retain(shared);
    return object;
}

void w3d_type_destroy_802480f0(Ptr32<W3dType80247f9c> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b220;
    w3d_iface_release(object->object_1c);
    w3d_iface_release(object->object_18);
    w3d_iface_release(object->object_14);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


}


