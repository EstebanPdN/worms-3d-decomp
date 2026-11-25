#include "w3d_ptr.h"
#line 1 "d_typeobj_b.cpp"
/* Registered engine object types (0x80242d40..0x80244d60).
 *
 * Same per-type boilerplate as d_typeobj_a: registry getter, create, unlink,
 * constructor, deleting destructor, plus a script-registration routine that
 * lazily fills a static type descriptor ("ScriptNames", "EffectNames", ...)
 * and hands it to the binder. Purposes of the types are mostly unknown.
 */
#include "d_types.h"

extern "C" {

Ptr32<void> memset(Ptr32<void> destination, ...);

/* Static script type descriptor, filled on first registration. */
typedef struct W3dScriptTypeDesc {
    Ptr32<const char> name;
    unsigned short value_04;
    unsigned char unknown_06;
    unsigned char kind;
    Ptr32<void> table;
    unsigned char unknown_0c[0x14 - 0x0c];
} W3dScriptTypeDesc;

void w3d_script_bind_type_801efff0(Ptr32<void> state, Ptr32<W3dScriptTypeDesc> desc);
void w3d_script_finish_type_801e8d9c(Ptr32<void> state);

extern W3dScriptTypeDesc w3d_script_desc_80464d10;
extern int w3d_script_desc_ready_804b0864;
extern Ptr32<W3dRefIface> w3d_shared_iface_804b05b0;
extern const char w3d_str_803beb58[];
extern unsigned char w3d_script_table_8045ed94[];

#if 0 /* 0x80242d40: closest attempt differs in constant scheduling (7 words) */
int w3d_type_register_80242d40(void *state)
{
    if (!w3d_script_desc_ready_804b0864) {
        W3dScriptTypeDesc desc;
        W3dScriptTypeDesc *temp = &desc;
        memset(temp, 0, sizeof(desc));
        desc.name = w3d_str_803beb58;
        desc.value_04 = 20;
        desc.kind = 9;
        desc.table = w3d_script_table_8045ed94;
        w3d_script_desc_80464d10 = *temp;
        w3d_script_desc_ready_804b0864 = 1;
    }
    w3d_script_bind_type_801efff0(state, &w3d_script_desc_80464d10);
    w3d_script_finish_type_801e8d9c(state);
    return 0;
}
#endif

/* Type registered at 0x80367838: 0x1f0-byte objects. */
typedef struct W3dType80242e04 {
    W3dObjectBase base;
    unsigned char unknown_14[0x8c - 0x14];
    Ptr32<W3dRefIface> object_8c;
    unsigned char unknown_90[0x114 - 0x90];
    Ptr32<W3dRefIface> object_114;
    unsigned char unknown_118[0x128 - 0x118];
    W3dString name_128;
    unsigned char unknown_12c[0x134 - 0x12c];
    W3dString name_134;
    W3dString name_138;
    unsigned char unknown_13c[0x148 - 0x13c];
    W3dString name_148;
    Ptr32<W3dRefIface> object_14c;
    W3dString name_150;
    W3dString name_154;
    unsigned char unknown_158[0x1f0 - 0x158];
} W3dType80242e04;

extern Ptr32<void> w3d_vtable_8041b4c8[];

static inline void w3d_iface_release(Ptr32<W3dRefIface> object)
{
    if (object)
        object->vtbl->release(object);
}

extern W3dTypeList w3d_type_list_80367838;
Ptr32<W3dType80242e04> w3d_type_construct_80242ebc(Ptr32<W3dType80242e04> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80242e04(void)
{
    return &w3d_type_list_80367838;
}

Ptr32<W3dType80242e04> w3d_type_create_80242e10(void)
{
    Ptr32<W3dType80242e04> object = w3d_type_construct_80242ebc((Ptr32<W3dType80242e04>)w3d_object_alloc_801ea70c(0x1f0),
        w3d_type_list_80367838.type_id);
    w3d_state_register(&w3d_type_list_80367838, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367838.count++;
    return object;
}

void w3d_type_unlink_80242e78(Ptr32<W3dType80242e04> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367838, &object->base.references);
    w3d_type_list_80367838.count--;
}

void w3d_type_destroy_802432a8(Ptr32<W3dType80242e04> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b4c8;
    w3d_string_destroy(&object->name_154);
    w3d_string_destroy(&object->name_150);
    w3d_iface_release(object->object_14c);
    w3d_string_destroy(&object->name_148);
    w3d_string_destroy(&object->name_138);
    w3d_string_destroy(&object->name_134);
    w3d_string_destroy(&object->name_128);
    w3d_iface_release(object->object_114);
    w3d_iface_release(object->object_8c);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367888: 0x220-byte objects. */
/* Derived from the type at 0x80242e04 (its constructor/destructor run first/last). */
typedef struct W3dType802441bc {
    W3dType80242e04 base;
    W3dVector3 vector_1f0;
    int value_1fc;
    float value_200;
    float value_204;
    float value_208;
    float value_20c;
    float value_210;
    unsigned short value_214;
    unsigned short value_216;
    unsigned char flag_218;
    unsigned char flag_219;
    unsigned char unknown_21a[2];
    int value_21c;
} W3dType802441bc;

extern Ptr32<void> w3d_vtable_8041b4a0[];
extern const float w3d_f32_803c023c[];
Ptr32<W3dType80242e04> w3d_type_construct_80242ebc(Ptr32<W3dType80242e04> object, unsigned int type_id);

static inline void w3d_vector_fill(Ptr32<W3dVector3> vector, float value)
{
    vector->x = value;
    vector->y = value;
    vector->z = value;
}

extern W3dTypeList w3d_type_list_80367888;
Ptr32<W3dType802441bc> w3d_type_construct_80244274(Ptr32<W3dType802441bc> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_802441bc(void)
{
    return &w3d_type_list_80367888;
}

Ptr32<W3dType802441bc> w3d_type_create_802441c8(void)
{
    Ptr32<W3dType802441bc> object = w3d_type_construct_80244274((Ptr32<W3dType802441bc>)w3d_object_alloc_801ea70c(0x220),
        w3d_type_list_80367888.type_id);
    w3d_state_register(&w3d_type_list_80367888, object ? w3d::R(&object->base.base.references) : 0);
    w3d_type_list_80367888.count++;
    return object;
}

void w3d_type_unlink_80244230(Ptr32<W3dType802441bc> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367888, &object->base.base.references);
    w3d_type_list_80367888.count--;
}

Ptr32<W3dType802441bc> w3d_type_construct_80244274(Ptr32<W3dType802441bc> object, unsigned int type_id)
{
    float zero;
    w3d_type_construct_80242ebc(&object->base, type_id);
    zero = w3d_f32_803c023c[0];
    object->base.base.vtbl = w3d_vtable_8041b4a0;
    w3d_vector_fill(&object->vector_1f0, zero);
    object->value_1fc = 0;
    object->value_200 = zero;
    object->value_204 = zero;
    object->value_208 = zero;
    object->value_20c = zero;
    object->value_214 = 0;
    object->value_216 = 0;
    object->flag_218 = 0;
    object->value_210 = zero;
    object->flag_219 = 0;
    object->value_21c = 0;
    return object;
}

void w3d_type_destroy_802442fc(Ptr32<W3dType802441bc> object, int flags)
{
    object->base.base.vtbl = w3d_vtable_8041b4a0;
    w3d_type_destroy_802432a8(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x803678d8: 0x18-byte objects. */
typedef struct W3dType80244474 {
    W3dObjectBase base;
    Ptr32<W3dRefIface> object_14;
} W3dType80244474;

extern Ptr32<void> w3d_vtable_8041b478[];

extern W3dTypeList w3d_type_list_803678d8;
Ptr32<W3dType80244474> w3d_type_construct_8024452c(Ptr32<W3dType80244474> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80244474(void)
{
    return &w3d_type_list_803678d8;
}

Ptr32<W3dType80244474> w3d_type_create_80244480(void)
{
    Ptr32<W3dType80244474> object = w3d_type_construct_8024452c((Ptr32<W3dType80244474>)w3d_object_alloc_801ea70c(0x18),
        w3d_type_list_803678d8.type_id);
    w3d_state_register(&w3d_type_list_803678d8, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_803678d8.count++;
    return object;
}

void w3d_type_unlink_802444e8(Ptr32<W3dType80244474> object)
{
    w3d_owner_list_remove(&w3d_type_list_803678d8, &object->base.references);
    w3d_type_list_803678d8.count--;
}

Ptr32<W3dType80244474> w3d_type_construct_8024452c(Ptr32<W3dType80244474> object, unsigned int type_id)
{
    Ptr32<W3dRefIface> shared;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05b0;
    object->base.vtbl = w3d_vtable_8041b478;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    return object;
}

void w3d_type_destroy_80244588(Ptr32<W3dType80244474> object, int flags)
{
    Ptr32<W3dRefIface> shared;
    object->base.vtbl = w3d_vtable_8041b478;
    shared = object->object_14;
    if (shared)
        shared->vtbl->release(shared);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367928: 0x18-byte objects. */
typedef struct W3dType802446bc {
    W3dObjectBase base;
    Ptr32<W3dRefIface> object_14;
} W3dType802446bc;

extern Ptr32<void> w3d_vtable_8041b450[];

extern W3dTypeList w3d_type_list_80367928;
Ptr32<W3dType802446bc> w3d_type_construct_80244774(Ptr32<W3dType802446bc> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_802446bc(void)
{
    return &w3d_type_list_80367928;
}

Ptr32<W3dType802446bc> w3d_type_create_802446c8(void)
{
    Ptr32<W3dType802446bc> object = w3d_type_construct_80244774((Ptr32<W3dType802446bc>)w3d_object_alloc_801ea70c(0x18),
        w3d_type_list_80367928.type_id);
    w3d_state_register(&w3d_type_list_80367928, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367928.count++;
    return object;
}

void w3d_type_unlink_80244730(Ptr32<W3dType802446bc> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367928, &object->base.references);
    w3d_type_list_80367928.count--;
}

Ptr32<W3dType802446bc> w3d_type_construct_80244774(Ptr32<W3dType802446bc> object, unsigned int type_id)
{
    Ptr32<W3dRefIface> shared;
    w3d_object_base_construct_801ea0ec(&object->base, type_id);
    shared = w3d_shared_iface_804b05b0;
    object->base.vtbl = w3d_vtable_8041b450;
    object->object_14 = shared;
    if (shared)
        shared->vtbl->retain(shared);
    return object;
}

void w3d_type_destroy_802447d0(Ptr32<W3dType802446bc> object, int flags)
{
    Ptr32<W3dRefIface> shared;
    object->base.vtbl = w3d_vtable_8041b450;
    shared = object->object_14;
    if (shared)
        shared->vtbl->release(shared);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


/* Type registered at 0x80367978: 0x1f4-byte objects. */
typedef struct W3dType80244904 {
    W3dObjectBase base;
    unsigned char unknown_14[0x90 - 0x14];
    W3dString name_90;
    unsigned char unknown_94[0xac - 0x94];
    W3dString name_ac;
    unsigned char unknown_b0[0xf4 - 0xb0];
    W3dString name_f4;
    unsigned char unknown_f8[0x1f4 - 0xf8];
} W3dType80244904;

extern Ptr32<void> w3d_vtable_8041b428[];

extern W3dTypeList w3d_type_list_80367978;
Ptr32<W3dType80244904> w3d_type_construct_802449bc(Ptr32<W3dType80244904> object, unsigned int type_id);

Ptr32<W3dTypeList> w3d_type_list_80244904(void)
{
    return &w3d_type_list_80367978;
}

Ptr32<W3dType80244904> w3d_type_create_80244910(void)
{
    Ptr32<W3dType80244904> object = w3d_type_construct_802449bc((Ptr32<W3dType80244904>)w3d_object_alloc_801ea70c(0x1f4),
        w3d_type_list_80367978.type_id);
    w3d_state_register(&w3d_type_list_80367978, object ? w3d::R(&object->base.references) : 0);
    w3d_type_list_80367978.count++;
    return object;
}

void w3d_type_unlink_80244978(Ptr32<W3dType80244904> object)
{
    w3d_owner_list_remove(&w3d_type_list_80367978, &object->base.references);
    w3d_type_list_80367978.count--;
}

void w3d_type_destroy_80244d60(Ptr32<W3dType80244904> object, int flags)
{
    object->base.vtbl = w3d_vtable_8041b428;
    w3d_string_destroy(&object->name_f4);
    w3d_string_destroy(&object->name_ac);
    w3d_string_destroy(&object->name_90);
    w3d_object_base_destroy_801ea138(&object->base, 0);
    if (flags & 1)
        w3d_object_free_801ea740(object);
}


}


