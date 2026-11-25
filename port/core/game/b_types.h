/* Shared observed shapes for worker-b units (0x80180000..0x801e0000).
 * Only offsets that the disassembly touches are described.
 */
#ifndef B_TYPES_H
#define B_TYPES_H

extern "C" {

/* Engine byte string: one pointer to the text after a 6-byte header. */
typedef struct W3dString { Ptr32<char> data; } W3dString;

Ptr32<W3dString> w3d_string_from_text(Ptr32<W3dString> string, Ptr32<const char> text);
Ptr32<W3dString> w3d_string_default(Ptr32<W3dString> string);
void w3d_string_base_init(Ptr32<W3dString> string);
void w3d_string_base_finish(Ptr32<W3dString> string);
void w3d_string_release(Ptr32<W3dString> string);

/* Reference-counted interface objects with 4-byte virtual slots.
 * Slots 0 and 4 hold the vtable header; +0x0c adds and +0x10 drops a
 * reference. Other slots are named by offset where their role is unclear.
 */
typedef struct W3dObject W3dObject;
typedef struct W3dObjectVtbl {
    Ptr32<void> header_00;
    Ptr32<void> header_04;
    Ptr32<int (Ptr32<W3dObject>)> query_08;
    Ptr32<int (Ptr32<W3dObject>)> add_ref;
    Ptr32<int (Ptr32<W3dObject>)> release;
    Ptr32<Ptr32<struct W3dClassInfo> (Ptr32<W3dObject>)> get_class;
    Ptr32<int (Ptr32<W3dObject>)> slot_18;
    Ptr32<int (Ptr32<W3dObject>)> slot_1c;
    Ptr32<int (Ptr32<W3dObject>, Ptr32<const void>, Ptr32<W3dObject>, Ptr32<W3dString>)> set_value_20;
    Ptr32<int (Ptr32<W3dObject>)> slot_24;
    Ptr32<int (Ptr32<W3dObject>)> slot_28;
    Ptr32<int (Ptr32<W3dObject>)> slot_2c;
    Ptr32<int (Ptr32<W3dObject>)> slot_30;
    Ptr32<int (Ptr32<W3dObject>)> slot_34;
    Ptr32<int (Ptr32<W3dObject>, Ptr32<const void>, int, Ptr32<Ptr32<W3dObject>>)> get_value_38;
} W3dObjectVtbl;
struct W3dObject { Ptr32<W3dObjectVtbl> vt; };

/* Static run-time class record; +0x14 links to the parent class and the
 * root links to itself.
 */
typedef struct W3dClassInfo {
    unsigned char unknown_00[0x14];
    Ptr32<struct W3dClassInfo> parent;
} W3dClassInfo;

static inline int w3d_class_is_a(Ptr32<W3dClassInfo> info, Ptr32<W3dClassInfo> target)
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
    Ptr32<W3dObject> p;
    W3dRef() : p(0) {}
    template <class W3dU> W3dRef(Ptr32<W3dU> w3d_p) : W3dRef((W3dObject *)w3d_p.get()) {}
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
