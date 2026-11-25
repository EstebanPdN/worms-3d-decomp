/* Shared observed layouts for worker-g recovered units (0x800c0000..0x80120000).
 * Names are inferred from behavior; no original symbols survive.
 */
#ifndef W3D_G_TYPES_H
#define W3D_G_TYPES_H

extern "C" {

/* Reference-counted interface with a table of 4-byte function pointers:
 * +0x0c retain, +0x10 release (observed through blrl calls).
 */
typedef struct W3dGIface W3dGIface;
typedef struct W3dGIfaceVtbl {
    void *unknown_00[3];
    void (*retain)(W3dGIface *object);
    void (*release)(W3dGIface *object);
} W3dGIfaceVtbl;
struct W3dGIface {
    W3dGIfaceVtbl *vtbl;
};

/* Plain three-float record copied by assignment (observed as word moves). */
typedef struct W3dGVec3 {
    float x, y, z;
} W3dGVec3;

/* Engine message: u16 identifier first (64 = attach, 66 = detach observed). */
typedef struct W3dGMessage {
    unsigned short id;
} W3dGMessage;

/* Message name resolved lazily to an identifier. */
typedef struct W3dGCachedMessage {
    unsigned int value;
    const char *name;
} W3dGCachedMessage;

unsigned int w3d_cached_message_id(W3dGCachedMessage *message, int force);
W3dGCachedMessage *w3d_cached_message_name_init(W3dGCachedMessage *message, const char *name);
int w3d_message_post_current(void *message);
unsigned int w3d_constructor_lookup_name(const void *name, void *output);
void *w3d_heap_allocate_entry_a(unsigned int size);

}

#endif
