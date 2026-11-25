/* Reference-counted type with the global registry list at 0x80368bd8
 * (0x802c5c24..0x802c5d3c). Same shape as shared_object_list: the u16
 * reference count at +0x04 doubles as the list link, the list keeps a u16
 * live count at +0x22, instances are 0x54 bytes. The list getter at
 * 0x802c5c18 is admitted as w3d_card_guide_get. Constructor and deleting
 * destructor stay external.
 */
extern "C" {

typedef struct W3dRegistryList {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dRegistryList;

typedef struct W3dRegistryObject {
    unsigned char unknown_00[4];
    unsigned short references;
} W3dRegistryObject;

extern W3dRegistryList w3d_registry_list_80368bd8;
void *w3d_heap_allocate_entry_a(unsigned int size);
W3dRegistryObject *w3d_registry_object_construct_802c5d3c(void *storage);
void w3d_registry_object_destroy_802c5e10(W3dRegistryObject *object, int flags);
void w3d_state_register(W3dRegistryList *list, void *link);
void w3d_owner_list_remove(W3dRegistryList *list, void *link);

void w3d_registry_80368bd8_unlink(W3dRegistryObject *object)
{
    w3d_owner_list_remove(&w3d_registry_list_80368bd8, &object->references);
    w3d_registry_list_80368bd8.count--;
}

W3dRegistryObject *w3d_registry_80368bd8_create(void)
{
    W3dRegistryObject *object = w3d_registry_object_construct_802c5d3c(w3d_heap_allocate_entry_a(0x54));
    w3d_state_register(&w3d_registry_list_80368bd8, object ? &object->references : 0);
    w3d_registry_list_80368bd8.count++;
    return object;
}

unsigned short w3d_registry_80368bd8_release(W3dRegistryObject *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_registry_80368bd8_unlink(object);
        if (object)
            w3d_registry_object_destroy_802c5e10(object, 3);
    }
    return remaining;
}

unsigned short w3d_registry_80368bd8_retain(W3dRegistryObject *object)
{
    return object->references++;
}

}
