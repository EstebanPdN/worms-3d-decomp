/* Shared observed layouts for worker-d recovered units (0x80240000..0x802a0000).
 * Names are inferred from behavior; no original symbols survive.
 */
#ifndef W3D_D_TYPES_H
#define W3D_D_TYPES_H

extern "C" {

/* Reference-counted string: data points 6 bytes past this header. */
typedef struct W3dStringHeader {
    unsigned short references;
    unsigned short length;
    unsigned short capacity;
} W3dStringHeader;

typedef struct W3dString {
    Ptr32<char> data;
} W3dString;

void w3d_string_release_header(Ptr32<W3dStringHeader> header);
void w3d_string_base_init(Ptr32<W3dString> string);
void w3d_string_base_finish(Ptr32<W3dString> string);
void w3d_string_release(Ptr32<W3dString> string);
Ptr32<W3dStringHeader> w3d_string_header(Ptr32<W3dString> string);

/* Opaque shared empty string; addressed absolutely, never via small data. */
typedef struct W3dSharedString W3dSharedString;
extern W3dSharedString w3d_string_shared_empty;

/* Inline string member constructor: share the empty string. */
static inline void w3d_string_init_empty(Ptr32<W3dString> string)
{
    w3d_string_base_init(string);
    string->data = ((Ptr32<W3dString>)&w3d_string_shared_empty)->data;
    ++w3d_string_header(string)->references;
}

/* Inline string member destructor. */
static inline void w3d_string_destroy(Ptr32<W3dString> string)
{
    w3d_string_base_finish(string);
    w3d_string_release(string);
}

/* Reference-counted interface with a table of 4-byte function pointers:
 * +0x0c retain, +0x10 release (observed through blrl calls).
 */
typedef struct W3dRefIface W3dRefIface;
typedef struct W3dRefIfaceVtbl {
    Ptr32<void> unknown_00[3];
    Ptr32<void (Ptr32<W3dRefIface>)> retain;
    Ptr32<void (Ptr32<W3dRefIface>)> release;
} W3dRefIfaceVtbl;
struct W3dRefIface {
    Ptr32<W3dRefIfaceVtbl> vtbl;
};

/* Plain value records copied by assignment (observed as word moves). */
typedef struct W3dVector3 {
    float x, y, z;
} W3dVector3;

typedef struct W3dMatrix44 {
    float m[4][4];
} W3dMatrix44;

/* Per-type registry of live engine objects. The type id is the top 10 bits
 * of the word at +0x20; the live count is the u16 at +0x22.
 */
typedef struct W3dTypeList {
    unsigned char unknown_00[0x20];
    unsigned short count;
    unsigned short :6; unsigned short type_id:10;
} W3dTypeList;

void w3d_state_register(Ptr32<W3dTypeList> list, Ptr32<void> link);
void w3d_owner_list_remove(Ptr32<W3dTypeList> list, Ptr32<void> link);
Ptr32<void> w3d_object_alloc_801ea70c(unsigned int size);
void w3d_object_free_801ea740(Ptr32<void> object);

/* Common base of registered engine objects: vtable, then the registry link
 * (u16 reference count at +0x04, type id at +0x06, list links at +0x0c/+0x10).
 */
typedef struct W3dObjectBase {
    Ptr32<void> vtbl;
    unsigned short references;
    unsigned short type_id;
    unsigned char unknown_08[0x14 - 0x08];
} W3dObjectBase;

Ptr32<W3dObjectBase> w3d_object_base_construct_801ea0ec(Ptr32<W3dObjectBase> object, unsigned int type_id);
void w3d_object_base_destroy_801ea138(Ptr32<W3dObjectBase> object, int flags);

/* Objects with a u16 reference count at +0x04. */
typedef struct W3dCounted {
    unsigned char unknown_00[4];
    unsigned short references;
} W3dCounted;

}

#endif
