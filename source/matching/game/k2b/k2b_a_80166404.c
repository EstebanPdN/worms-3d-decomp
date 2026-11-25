struct K2bService { void **vtable; };
struct K2bHolder { unsigned char pad0[20]; struct K2bService *service; };
struct K2bTable { unsigned char pad0[16]; int entries[1]; };
int w3d_k2b_service_lookup_entry_80166404(struct K2bHolder *self, char *key, int index)
{
    struct K2bService *service = self->service;
    struct K2bTable *table = ((struct K2bTable *(*)(struct K2bService *, char *))service->vtable[13])(service, key ? key + 4 : 0);
    if (table != 0) {
        return table->entries[index];
    }
    return 0;
}
// desc: Appears to ask a held service for a table keyed by the object's secondary base and return one of its entries.
