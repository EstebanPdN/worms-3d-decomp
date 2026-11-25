#include "w3d_ptr.h"
#line 1 "f_component_inline.cpp"
/* Component type with inline construction and destruction (0x800af330..0x800af4fc).
 *
 * Names are inferred from behavior; no original symbols survive. This type
 * follows the shared component shape (registry list at 0x803608a0 with its
 * u16 count at +0x22, u16 reference count at +4), but its constructor and
 * destructor only install the vtable at 0x8040f760, so they are expanded
 * inside create and release. The base class constructor is 0x800d78ec, its
 * destructor 0x800d797c and its message handler 0x800d7d7c. The update hook
 * reads a resource handle at +0xc0 and an active flag at +0x78.
 */
extern "C" {

typedef struct W3dSharedList {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dSharedList;

typedef struct W3dMessage {
    unsigned short id;
} W3dMessage;

typedef struct W3dInlineComponent {
    Ptr32<const void> vtable;
    unsigned short references;
    unsigned char unknown_006[0x78 - 0x06];
    int active;
    unsigned char unknown_07c[0xc0 - 0x7c];
    Ptr32<void> resource;
} W3dInlineComponent;

extern W3dSharedList w3d_component_list_803608a0;
extern Ptr32<const void> w3d_component_vtable_8040f760[];

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
int w3d_base_construct_800d78ec(Ptr32<void> object);
void w3d_base_destroy_800d797c(Ptr32<void> object, int flags);
int w3d_base_handle_message_800d7d7c(Ptr32<void> object, Ptr32<W3dMessage> message);
void w3d_component_start_800afccc(Ptr32<void> object);
Ptr32<void> w3d_empty_80341584(Ptr32<void> resource);
int w3d_resource_touch_801797b4(Ptr32<void> resource);
void w3d_component_refresh_800ecb20(Ptr32<W3dInlineComponent> object);
void w3d_component_apply_800af6b4(Ptr32<W3dInlineComponent> object, Ptr32<void> value);
void w3d_component_stop_800af4f8(Ptr32<void> object);

Ptr32<W3dSharedList> w3d_component_list_get_800af330(void)
{
    return &w3d_component_list_803608a0;
}

void w3d_component_unlink_800af33c(Ptr32<W3dInlineComponent> object)
{
    w3d_owner_list_remove(&w3d_component_list_803608a0, &object->references);
    w3d_component_list_803608a0.count--;
}

Ptr32<W3dInlineComponent> w3d_component_create_800af380(void)
{
    Ptr32<W3dInlineComponent> object = (Ptr32<W3dInlineComponent>)w3d_heap_allocate_entry_a(392);
    w3d_base_construct_800d78ec(object);
    object->vtable = w3d_component_vtable_8040f760;
    w3d_state_register(&w3d_component_list_803608a0, object ? w3d::R(&object->references) : 0);
    w3d_component_list_803608a0.count++;
    return object;
}

unsigned short w3d_component_release_800af3f0(Ptr32<W3dInlineComponent> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_component_unlink_800af33c(object);
        if (object) {
            object->vtable = w3d_component_vtable_8040f760;
            w3d_base_destroy_800d797c(object, 3);
        }
    }
    return remaining;
}

unsigned short w3d_component_retain_800af458(Ptr32<W3dInlineComponent> object)
{
    return object->references++;
}

int w3d_component_handle_message_800af470(Ptr32<W3dInlineComponent> object, Ptr32<W3dMessage> message)
{
    switch (message->id) {
    case 64:
        if (w3d_base_handle_message_800d7d7c(object, message) >= 0) {
            w3d_component_start_800afccc(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_component_stop_800af4f8(object);
        break;
    }
    return w3d_base_handle_message_800d7d7c(object, message);
}

void w3d_component_stop_800af4f8(Ptr32<void> object)
{
}

void w3d_component_update_800af4fc(Ptr32<W3dInlineComponent> object, int unused, unsigned long long flags,
                                   int reserved, int value)
{
    w3d_resource_touch_801797b4(w3d_empty_80341584(object->resource));
    if (object->active) {
        w3d_component_refresh_800ecb20(object);
    } else {
        int blocked = (flags & 38) != 0;
        if (!blocked)
            w3d_component_apply_800af6b4(object, (Ptr32<void>)w3d::G(value));
    }
}

}


