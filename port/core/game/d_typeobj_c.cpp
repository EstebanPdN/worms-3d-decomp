#include "w3d_ptr.h"
#line 1 "d_typeobj_c.cpp"
/* Registered engine object types (0x80245704..0x8024704c).
 *
 * Same per-type boilerplate as d_typeobj_a/b, plus constructors that load
 * float defaults from absolute constants, and one script-registration routine
 * that declares the type's properties (one of them a colour defaulting to
 * opaque white). Purposes of the types are unknown; names use addresses.
 */
#include "d_types.h"

extern "C" {

/* Four-byte colour, filled channel by channel through an inline helper. */
typedef struct W3dColor {
    unsigned char r, g, b, a;
} W3dColor;

static inline void w3d_color_fill(Ptr32<W3dColor> color, unsigned char value)
{
    color->r = value;
    color->g = value;
    color->b = value;
    color->a = value;
}

static inline void w3d_vector_fill(Ptr32<W3dVector3> vector, float value)
{
    vector->x = value;
    vector->y = value;
    vector->z = value;
}

/* Script property entry returned by the colour-property declaration call. */
typedef struct W3dScriptColorProp {
    unsigned char unknown_00[8];
    W3dColor value;
} W3dScriptColorProp;

Ptr32<void> w3d_script_add_prop_801ec52c(Ptr32<void> state, Ptr32<void> prop);
Ptr32<void> w3d_script_add_prop_801ece2c(Ptr32<void> state, Ptr32<void> prop);
Ptr32<W3dScriptColorProp> w3d_script_add_color_801f15e0(Ptr32<void> state, Ptr32<void> prop);
void w3d_script_finish_type_801e8d9c(Ptr32<void> state);

/* Type registered at 0x803679c8: 0x28-byte objects. */
typedef struct W3dType80245704 {
    W3dObjectBase base;
    int value_14;
    W3dColor color_18;
    W3dVector3 vector_1c;
} W3dType80245704;

extern Ptr32<void> w3d_vtable_8041b400[];
extern const float w3d_f32_803c22cc[];
extern const float w3d_f32_803c22d0[];
extern const float w3d_f32_803c22d4[];

extern W3dTypeList w3d_type_list_803679c8;
Ptr32<W3dType80245704> w3d_type_construct_802457bc(Ptr32<W3dType80245704> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80245704(void)
{
    return &w3d_type_list_803679c8;
}

Ptr32<W3dType80245704> w3d_type_create_80245710(void)
{
    Ptr32<W3dType80245704> object = w3d_type_construct_802457bc((Ptr32<W3dType80245704>)w3d_object_alloc_801ea70c(0x28),
        w3d_type_list_803679c8.type_id);
    w3d_state_register(&w3d_type_list_803679c8, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_803679c8.count++;
    return object;
}

void w3d_type_unlink_80245778(Ptr32<W3dType80245704> object)
{
    w3d_owner_list_remove(&w3d_type_list_803679c8, &object->base.references);
    w3d_type_list_803679c8.count--;
}

Ptr32<W3dType80245704> w3d_type_construct_802457bc(Ptr32<W3dType80245704> object, unsigned int type_id)
{
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    object->base.vtbl = w3d_vtable_8041b400;
    object->value_14 = 0;
    w3d_color_fill(&object->color_18, 255);
    object->vector_1c.x = w3d_f32_803c22cc[0];
    object->vector_1c.y = w3d_f32_803c22d0[0];
    object->vector_1c.z = w3d_f32_803c22d4[0];
    return object;
}

void w3d_type_destroy_8024583c(Ptr32<W3dType80245704> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b400;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}

extern unsigned char w3d_script_prop_803c22d8[];
extern unsigned char w3d_script_prop_803c2308[];
extern unsigned char w3d_script_prop_803c2338[];
extern unsigned char w3d_script_prop_803c2368[];
extern unsigned char w3d_script_prop_803c2394[];

int w3d_type_register_8024588c(Ptr32<void> state)
{
    Ptr32<W3dScriptColorProp> color;
    W3dColor value;
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c22d8);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c2308);
    w3d_script_add_prop_801ec52c(state, w3d_script_prop_803c2338);
    color = w3d_script_add_color_801f15e0(state, w3d_script_prop_803c2368);
    w3d_color_fill(&value, 255);
    color->value = value;
    w3d_script_add_prop_801ece2c(state, w3d_script_prop_803c2394);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}


/* Type registered at 0x80367a18: 0x24-byte objects. */
typedef struct W3dType8024592c {
    W3dObjectBase base;
    Ptr32<W3dRefIface> object_14;
    float value_18;
    float value_1c;
    int value_20;
} W3dType8024592c;

extern Ptr32<void> w3d_vtable_8041b3d8[];
extern Ptr32<W3dRefIface> w3d_shared_iface_804b05ac;
extern const float w3d_f32_803c23d0[];

extern W3dTypeList w3d_type_list_80367a18;
Ptr32<W3dType8024592c> w3d_type_construct_802459e4(Ptr32<W3dType8024592c> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_8024592c(void)
{
    return &w3d_type_list_80367a18;
}

Ptr32<W3dType8024592c> w3d_type_create_80245938(void)
{
    Ptr32<W3dType8024592c> object = w3d_type_construct_802459e4((Ptr32<W3dType8024592c>)w3d_object_alloc_801ea70c(0x24),
        w3d_type_list_80367a18.type_id);
    w3d_state_register(&w3d_type_list_80367a18, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367a18.count++;
    return object;
}

void w3d_type_unlink_802459a0(Ptr32<W3dType8024592c> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367a18, &object->base.references);
    w3d_type_list_80367a18.count--;
}

Ptr32<W3dType8024592c> w3d_type_construct_802459e4(Ptr32<W3dType8024592c> object, unsigned int type_id)
{
    Ptr32<W3dRefIface> shared;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05ac;
    object->base.vtbl = w3d_vtable_8041b3d8;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    object->value_18 = w3d_f32_803c23d0[0];
    object->value_1c = w3d_f32_803c23d0[0];
    object->value_20 = 0;
    return object;
}

void w3d_type_destroy_80245a58(Ptr32<W3dType8024592c> object, int flags)
{
    Ptr32<W3dRefIface> shared;
    object->base.vtbl = w3d_vtable_8041b3d8;
    shared = object->object_14;
    if (shared)
        shared->vtbl->release(shared);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367a68: 0x98-byte objects. */
typedef struct W3dType80245bcc {
    W3dObjectBase base;
    float value_14;
    float values_18[4];
    int words_28[28];
} W3dType80245bcc;

extern Ptr32<void> w3d_vtable_8041b3b0[];
extern const float w3d_f32_803c2484[];
extern const float w3d_f32_803c2488[];

extern W3dTypeList w3d_type_list_80367a68;
Ptr32<W3dType80245bcc> w3d_type_construct_80245c84(Ptr32<W3dType80245bcc> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80245bcc(void)
{
    return &w3d_type_list_80367a68;
}

Ptr32<W3dType80245bcc> w3d_type_create_80245bd8(void)
{
    Ptr32<W3dType80245bcc> object = w3d_type_construct_80245c84((Ptr32<W3dType80245bcc>)w3d_object_alloc_801ea70c(0x98),
        w3d_type_list_80367a68.type_id);
    w3d_state_register(&w3d_type_list_80367a68, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367a68.count++;
    return object;
}

void w3d_type_unlink_80245c40(Ptr32<W3dType80245bcc> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367a68, &object->base.references);
    w3d_type_list_80367a68.count--;
}

Ptr32<W3dType80245bcc> w3d_type_construct_80245c84(Ptr32<W3dType80245bcc> object, unsigned int type_id)
{
    float zero, one;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    one = w3d_f32_803c2484[0];
    zero = w3d_f32_803c2488[0];
    object->base.vtbl = w3d_vtable_8041b3b0;
    object->value_14 = one;
    object->values_18[0] = zero;
    object->values_18[1] = zero;
    object->values_18[2] = zero;
    object->values_18[3] = zero;
    object->words_28[0] = 0;
    object->words_28[1] = 0;
    object->words_28[2] = 0;
    object->words_28[3] = 0;
    object->words_28[4] = 0;
    object->words_28[5] = 0;
    object->words_28[6] = 0;
    object->words_28[7] = 0;
    object->words_28[8] = 0;
    object->words_28[9] = 0;
    object->words_28[10] = 0;
    object->words_28[11] = 0;
    object->words_28[12] = 0;
    object->words_28[13] = 0;
    object->words_28[14] = 0;
    object->words_28[15] = 0;
    object->words_28[16] = 0;
    object->words_28[17] = 0;
    object->words_28[18] = 0;
    object->words_28[19] = 0;
    object->words_28[20] = 0;
    object->words_28[21] = 0;
    object->words_28[22] = 0;
    object->words_28[23] = 0;
    object->words_28[24] = 0;
    object->words_28[25] = 0;
    object->words_28[26] = 0;
    object->words_28[27] = 0;
    return object;
}

void w3d_type_destroy_80245d58(Ptr32<W3dType80245bcc> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b3b0;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367ab8: 0xa4-byte objects. */
typedef struct W3dType80245fe8 {
    W3dObjectBase base;
    unsigned char unknown_14[0x7c - 0x14];
    W3dString name_7c;
    W3dString name_80;
    W3dString name_84;
    W3dString name_88;
    unsigned char unknown_8c[0xa4 - 0x8c];
} W3dType80245fe8;

extern Ptr32<void> w3d_vtable_8041b388[];

extern W3dTypeList w3d_type_list_80367ab8;
Ptr32<W3dType80245fe8> w3d_type_construct_802460a0(Ptr32<W3dType80245fe8> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80245fe8(void)
{
    return &w3d_type_list_80367ab8;
}

Ptr32<W3dType80245fe8> w3d_type_create_80245ff4(void)
{
    Ptr32<W3dType80245fe8> object = w3d_type_construct_802460a0((Ptr32<W3dType80245fe8>)w3d_object_alloc_801ea70c(0xa4),
        w3d_type_list_80367ab8.type_id);
    w3d_state_register(&w3d_type_list_80367ab8, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367ab8.count++;
    return object;
}

void w3d_type_unlink_8024605c(Ptr32<W3dType80245fe8> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367ab8, &object->base.references);
    w3d_type_list_80367ab8.count--;
}

void w3d_type_destroy_802463b8(Ptr32<W3dType80245fe8> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b388;
    w3d_string_destroy(&object->name_88);
    w3d_string_destroy(&object->name_84);
    w3d_string_destroy(&object->name_80);
    w3d_string_destroy(&object->name_7c);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367b08: 0x34-byte objects. */
typedef struct W3dType80246b80 {
    W3dObjectBase base;
    Ptr32<W3dRefIface> object_14;
    int value_18;
    float values_1c[6];
} W3dType80246b80;

extern Ptr32<void> w3d_vtable_8041b360[];
extern Ptr32<W3dRefIface> w3d_shared_iface_804b05a8;
extern const float w3d_f32_803c33b0[];

extern W3dTypeList w3d_type_list_80367b08;
Ptr32<W3dType80246b80> w3d_type_construct_80246c38(Ptr32<W3dType80246b80> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80246b80(void)
{
    return &w3d_type_list_80367b08;
}

Ptr32<W3dType80246b80> w3d_type_create_80246b8c(void)
{
    Ptr32<W3dType80246b80> object = w3d_type_construct_80246c38((Ptr32<W3dType80246b80>)w3d_object_alloc_801ea70c(0x34),
        w3d_type_list_80367b08.type_id);
    w3d_state_register(&w3d_type_list_80367b08, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367b08.count++;
    return object;
}

void w3d_type_unlink_80246bf4(Ptr32<W3dType80246b80> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367b08, &object->base.references);
    w3d_type_list_80367b08.count--;
}

Ptr32<W3dType80246b80> w3d_type_construct_80246c38(Ptr32<W3dType80246b80> object, unsigned int type_id)
{
    Ptr32<W3dRefIface> shared;
    float zero;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05a8;
    object->base.vtbl = w3d_vtable_8041b360;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    zero = w3d_f32_803c33b0[0];
    object->value_18 = 0;
    object->values_1c[0] = zero;
    object->values_1c[1] = zero;
    object->values_1c[2] = zero;
    object->values_1c[3] = zero;
    object->values_1c[4] = zero;
    object->values_1c[5] = zero;
    return object;
}

void w3d_type_destroy_80246cbc(Ptr32<W3dType80246b80> object, int flags)
{
    Ptr32<W3dRefIface> shared;
    object->base.vtbl = w3d_vtable_8041b360;
    shared = object->object_14;
    if (shared)
        shared->vtbl->release(shared);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367b58: 0xa8-byte objects. */
typedef struct W3dType80246e64 {
    W3dObjectBase base;
    W3dVector3 vector_14;
    W3dVector3 vector_20;
    float values_2c[14];
    int value_64;
    float values_68[8];
    int value_88;
    float values_8c[7];
} W3dType80246e64;

extern Ptr32<void> w3d_vtable_8041b338[];
extern const float w3d_f32_803c356c[];

extern W3dTypeList w3d_type_list_80367b58;
Ptr32<W3dType80246e64> w3d_type_construct_80246f1c(Ptr32<W3dType80246e64> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80246e64(void)
{
    return &w3d_type_list_80367b58;
}

Ptr32<W3dType80246e64> w3d_type_create_80246e70(void)
{
    Ptr32<W3dType80246e64> object = w3d_type_construct_80246f1c((Ptr32<W3dType80246e64>)w3d_object_alloc_801ea70c(0xa8),
        w3d_type_list_80367b58.type_id);
    w3d_state_register(&w3d_type_list_80367b58, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367b58.count++;
    return object;
}

void w3d_type_unlink_80246ed8(Ptr32<W3dType80246e64> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367b58, &object->base.references);
    w3d_type_list_80367b58.count--;
}

Ptr32<W3dType80246e64> w3d_type_construct_80246f1c(Ptr32<W3dType80246e64> object, unsigned int type_id)
{
    float zero;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    zero = w3d_f32_803c356c[0];
    object->base.vtbl = w3d_vtable_8041b338;
    w3d_vector_fill(&object->vector_14, zero);
    w3d_vector_fill(&object->vector_20, zero);
    object->values_2c[0] = zero;
    object->values_2c[1] = zero;
    object->values_2c[2] = zero;
    object->values_2c[3] = zero;
    object->values_2c[4] = zero;
    object->values_2c[5] = zero;
    object->values_2c[6] = zero;
    object->values_2c[7] = zero;
    object->values_2c[8] = zero;
    object->values_2c[9] = zero;
    object->values_2c[10] = zero;
    object->values_2c[11] = zero;
    object->values_2c[12] = zero;
    object->values_2c[13] = zero;
    object->value_64 = 0;
    object->values_68[0] = zero;
    object->values_68[1] = zero;
    object->value_88 = 0;
    object->values_68[2] = zero;
    object->values_68[3] = zero;
    object->values_68[4] = zero;
    object->values_68[5] = zero;
    object->values_68[6] = zero;
    object->values_68[7] = zero;
    object->values_8c[0] = zero;
    object->values_8c[1] = zero;
    object->values_8c[2] = zero;
    object->values_8c[3] = zero;
    object->values_8c[4] = zero;
    object->values_8c[5] = zero;
    object->values_8c[6] = zero;
    return object;
}

void w3d_type_destroy_80247000(Ptr32<W3dType80246e64> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b338;
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


}


