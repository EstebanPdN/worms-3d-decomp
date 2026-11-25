/* Shared observed shapes for worker-b units (0x80180000..0x801e0000).
 * Only offsets that the disassembly touches are described.
 */
#ifndef B_TYPES_H
#define B_TYPES_H

extern "C" {

/* Engine byte string: one pointer to the text after a 6-byte header. */
typedef struct W3dString { char *data; } W3dString;

W3dString *w3d_string_from_text(W3dString *string, const char *text);
W3dString *w3d_string_default(W3dString *string);
void w3d_string_base_init(W3dString *string);
void w3d_string_base_finish(W3dString *string);
void w3d_string_release(W3dString *string);

/* Reference-counted interface objects with 4-byte virtual slots.
 * Slots 0 and 4 hold the vtable header; +0x0c adds and +0x10 drops a
 * reference. Other slots are named by offset where their role is unclear.
 */
typedef struct W3dObject W3dObject;
typedef struct W3dObjectVtbl {
    void *header_00;
    void *header_04;
    int (*query_08)(W3dObject *self);
    int (*add_ref)(W3dObject *self);
    int (*release)(W3dObject *self);
    struct W3dClassInfo *(*get_class)(W3dObject *self);
    int (*slot_18)(W3dObject *self);
    int (*slot_1c)(W3dObject *self);
    int (*set_value_20)(W3dObject *self, const void *key, W3dObject *value, W3dString *name);
    int (*slot_24)(W3dObject *self);
    int (*slot_28)(W3dObject *self);
    int (*slot_2c)(W3dObject *self);
    int (*slot_30)(W3dObject *self);
    int (*slot_34)(W3dObject *self);
    int (*get_value_38)(W3dObject *self, const void *key, int index, W3dObject **out);
} W3dObjectVtbl;
struct W3dObject { W3dObjectVtbl *vt; };

/* Static run-time class record; +0x14 links to the parent class and the
 * root links to itself.
 */
typedef struct W3dClassInfo {
    unsigned char unknown_00[0x14];
    struct W3dClassInfo *parent;
} W3dClassInfo;

static inline int w3d_class_is_a(W3dClassInfo *info, W3dClassInfo *target)
{
    while (info != target) {
        if (info == info->parent)
            return 0;
        info = info->parent;
    }
    return 1;
}

/* The class record is fetched before the target address is formed. */
#define W3D_OBJECT_IS_A(object, target) \
    w3d_class_is_a((object)->vt->get_class(object), &(target))

}

/* Inline reference holder: null or add_ref on construction, release on
 * destruction. Matches the inlined smart-pointer sequences in the original.
 */
struct W3dRef {
    W3dObject *p;
    W3dRef() : p(0) {}
    W3dRef(W3dObject *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~W3dRef() { if (p) p->vt->release(p); }
};

/* Local string finished on scope exit. The original reserves an 8-byte,
 * 8-aligned stack slot for it; only the first word is observed.
 */
struct W3dLocalString {
    W3dString s;
    int unknown_04;
    ~W3dLocalString() { w3d_string_base_finish(&s); w3d_string_release(&s); }
};

#endif
