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
    char *data;
} W3dString;

void w3d_string_release_header(W3dStringHeader *header);
void w3d_string_base_init(W3dString *string);
void w3d_string_base_finish(W3dString *string);
void w3d_string_release(W3dString *string);
W3dStringHeader *w3d_string_header(W3dString *string);

/* Opaque shared empty string; addressed absolutely, never via small data. */
typedef struct W3dSharedString W3dSharedString;
extern W3dSharedString w3d_string_shared_empty;

/* Inline string member constructor: share the empty string. */
static inline void w3d_string_init_empty(W3dString *string)
{
    w3d_string_base_init(string);
    string->data = ((W3dString *)&w3d_string_shared_empty)->data;
    ++w3d_string_header(string)->references;
}

/* Inline string member destructor. */
static inline void w3d_string_destroy(W3dString *string)
{
    w3d_string_base_finish(string);
    w3d_string_release(string);
}

/* Reference-counted interface with a table of 4-byte function pointers:
 * +0x0c retain, +0x10 release (observed through blrl calls).
 */
typedef struct W3dRefIface W3dRefIface;
typedef struct W3dRefIfaceVtbl {
    void *unknown_00[3];
    void (*retain)(W3dRefIface *object);
    void (*release)(W3dRefIface *object);
} W3dRefIfaceVtbl;
struct W3dRefIface {
    W3dRefIfaceVtbl *vtbl;
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
    unsigned int type_id : 10;
    unsigned short count;
} W3dTypeList;

void w3d_state_register(W3dTypeList *list, void *link);
void w3d_owner_list_remove(W3dTypeList *list, void *link);
void *w3d_object_alloc_801ea70c(unsigned int size);
void w3d_object_free_801ea740(void *object);

/* Common base of registered engine objects: vtable, then the registry link
 * (u16 reference count at +0x04, type id at +0x06, list links at +0x0c/+0x10).
 */
typedef struct W3dObjectBase {
    void *vtbl;
    unsigned short references;
    unsigned short type_id;
    unsigned char unknown_08[0x14 - 0x08];
} W3dObjectBase;

W3dObjectBase *w3d_object_base_construct_801ea0ec(W3dObjectBase *object, unsigned int type_id);
void w3d_object_base_destroy_801ea138(W3dObjectBase *object, int flags);

/* Objects with a u16 reference count at +0x04. */
typedef struct W3dCounted {
    unsigned char unknown_00[4];
    unsigned short references;
} W3dCounted;

}

#endif
