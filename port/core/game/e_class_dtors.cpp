#include "w3d_ptr.h"
#line 1 "e_class_dtors.cpp"
/* Compiler-shaped deleting destructors and small caches (0x803415c8..0x80342a74).
 *
 * Names are inferred from behavior; no original symbols survive. Most bodies
 * are the deleting-destructor shape: run the base destructor with flag 0 and
 * free the storage through 0x80015264 when bit 0 of the flags is set. The
 * four cached lookups keep a {key, value} pair in small data (key 60 means
 * empty), translate the object's key at +0x14 through the table at 0x803eb63c
 * and resolve it with 0x800fc330.
 */
extern "C" {

typedef struct W3dPointerVector {
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
    Ptr32<Ptr32<void>> capacity;
} W3dPointerVector;

typedef struct W3dKeyedObject {
    unsigned char unknown_00[0x14];
    int key;
} W3dKeyedObject;

typedef struct W3dMemberHolder {
    unsigned char unknown_00[0x68];
    unsigned char member[4];
} W3dMemberHolder;

extern int w3d_cached_key_804aa690;
extern int w3d_cached_value_804aa694;
extern int w3d_cached_key_804aa698;
extern int w3d_cached_value_804aa69c;
extern int w3d_cached_key_804aa6a0;
extern int w3d_cached_value_804aa6a4;
extern int w3d_cached_key_804aa6a8;
extern int w3d_cached_value_804aa6ac;
extern const unsigned int w3d_name_table_803eb63c[];

void w3d_operator_delete_80015264(Ptr32<void> object);
void w3d_object_base_destroy_80006388(Ptr32<void> object, int flags);
void w3d_object_base_destroy_8000a20c(Ptr32<void> object, int flags);
void w3d_object_base_destroy_80017304(Ptr32<void> object, int flags);
void w3d_object_base_destroy_80021468(Ptr32<void> object, int flags);
void w3d_class_destroy_80015d18(Ptr32<void> object, int flags);
void w3d_actor_method_member_destroy(Ptr32<void> member, int flags);
Ptr32<void> w3d_name_resolve_800fc330(Ptr32<unsigned int> name, Ptr32<int> value);

void w3d_class_destroy_803415c8(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034160c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341650(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

int w3d_cached_name_lookup_80341694(Ptr32<W3dKeyedObject> object, int reset)
{
    if (reset) {
        w3d_cached_key_804aa690 = 60;
        w3d_cached_value_804aa694 = 0;
        return 0;
    }
    if (object->key != w3d_cached_key_804aa690) {
        unsigned int name;
        int value;
        w3d_cached_key_804aa690 = object->key;
        name = w3d_name_table_803eb63c[object->key];
        w3d_name_resolve_800fc330(&name, &value);
        w3d_cached_value_804aa694 = value;
    }
    return w3d_cached_value_804aa694;
}

int w3d_cached_name_lookup_80341710(Ptr32<W3dKeyedObject> object, int reset)
{
    if (reset) {
        w3d_cached_key_804aa698 = 60;
        w3d_cached_value_804aa69c = 0;
        return 0;
    }
    if (object->key != w3d_cached_key_804aa698) {
        unsigned int name;
        int value;
        w3d_cached_key_804aa698 = object->key;
        name = w3d_name_table_803eb63c[object->key];
        w3d_name_resolve_800fc330(&name, &value);
        w3d_cached_value_804aa69c = value;
    }
    return w3d_cached_value_804aa69c;
}

int w3d_cached_name_lookup_8034178c(Ptr32<W3dKeyedObject> object, int reset)
{
    if (reset) {
        w3d_cached_key_804aa6a0 = 60;
        w3d_cached_value_804aa6a4 = 0;
        return 0;
    }
    if (object->key != w3d_cached_key_804aa6a0) {
        unsigned int name;
        int value;
        w3d_cached_key_804aa6a0 = object->key;
        name = w3d_name_table_803eb63c[object->key];
        w3d_name_resolve_800fc330(&name, &value);
        w3d_cached_value_804aa6a4 = value;
    }
    return w3d_cached_value_804aa6a4;
}

int w3d_cached_name_lookup_80341808(Ptr32<W3dKeyedObject> object, int reset)
{
    if (reset) {
        w3d_cached_key_804aa6a8 = 60;
        w3d_cached_value_804aa6ac = 0;
        return 0;
    }
    if (object->key != w3d_cached_key_804aa6a8) {
        unsigned int name;
        int value;
        w3d_cached_key_804aa6a8 = object->key;
        name = w3d_name_table_803eb63c[object->key];
        w3d_name_resolve_800fc330(&name, &value);
        w3d_cached_value_804aa6ac = value;
    }
    return w3d_cached_value_804aa6ac;
}

void w3d_class_destroy_80341890(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803418d4(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341918(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034195c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803419a0(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803419e4(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341a28(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341a6c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341ab0(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341af4(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341b38(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341b7c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341bc0(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341c04(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341c48(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341c8c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341cd0(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341d14(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341d58(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341d9c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341de0(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341e24(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341e68(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341eac(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341ef0(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341f34(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341f78(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80341fbc(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342000(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342044(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342088(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803420cc(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342110(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342154(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342198(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803421dc(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342220(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342264(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803422a8(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803422ec(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342330(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342374(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803423b8(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803423fc(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342440(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342484(Ptr32<W3dMemberHolder> object, int flags)
{
    w3d_actor_method_member_destroy(object->member, 2);
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803424d8(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034251c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342560(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803425a4(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803425e8(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034262c(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_8000a20c(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342670(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_empty_803426b4(void)
{
}

void w3d_vector_destroy_80342730(Ptr32<W3dPointerVector> vector)
{
    while (vector->begin != vector->end) {
        Ptr32<Ptr32<void>> end = vector->end;
        Ptr32<void> object = *--end;
        vector->end = end;
        if (object)
            w3d_class_destroy_80015d18(object, 3);
    }
}

void w3d_class_destroy_80342788(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803427cc(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342810(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342854(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342898(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803428dc(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80017304(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342920(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80017304(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342964(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80017304(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803429a8(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80017304(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803429ec(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342a30(Ptr32<void> object, int flags)
{
    w3d_object_base_destroy_80006388(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_empty_80342a74(void)
{
}

}


