#include "w3d_ptr.h"
#line 1 "registry_80368bd8.cpp"
/* Reference-counted type with the global registry list at 0x80368bd8
 * (0x802c5c24..0x802c5d3c). Same shape as shared_object_list: the u16
 * reference count at +0x04 doubles as the list link, the list keeps a u16
 * live count at +0x22, instances are 0x54 bytes. The list getter at
 * 0x802c5c18 is admitted as w3d_card_guide_get. Constructor and deleting
 * destructor stay external.
 */
extern "C" {

typedef struct W3dRegistryList {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dRegistryList;

typedef struct W3dRegistryObject {
    unsigned char unknown_00[4];
    unsigned short references;
} W3dRegistryObject;

extern W3dRegistryList w3d_registry_list_80368bd8;
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
Ptr32<W3dRegistryObject> w3d_registry_object_construct_802c5d3c(Ptr32<void> storage);
void w3d_registry_object_destroy_802c5e10(Ptr32<W3dRegistryObject> object, int flags);
void w3d_state_register(Ptr32<W3dRegistryList> list, Ptr32<void> link);
void w3d_owner_list_remove(Ptr32<W3dRegistryList> list, Ptr32<void> link);

void w3d_registry_80368bd8_unlink(Ptr32<W3dRegistryObject> object)
{
    w3d_owner_list_remove(&w3d_registry_list_80368bd8, &object->references);
    w3d_registry_list_80368bd8.count--;
}

Ptr32<W3dRegistryObject> w3d_registry_80368bd8_create(void)
{
    Ptr32<W3dRegistryObject> object = w3d_registry_object_construct_802c5d3c(w3d_heap_allocate_entry_a(0x54));
    w3d_state_register(&w3d_registry_list_80368bd8, object ? w3d::R(&object->references) : 0);
    w3d_registry_list_80368bd8.count++;
    return object;
}

unsigned short w3d_registry_80368bd8_release(Ptr32<W3dRegistryObject> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_registry_80368bd8_unlink(object);
        if (object)
            w3d_registry_object_destroy_802c5e10(object, 3);
    }
    return remaining;
}

unsigned short w3d_registry_80368bd8_retain(Ptr32<W3dRegistryObject> object)
{
    return object->references++;
}

}


