struct K2bInterface { void **vtable; };
struct K2bTable { unsigned char pad0[24]; struct K2bInterface **entries; };
extern int w3d_table_find_80177eb0(struct K2bTable *self, void *key, unsigned short *slot);
int w3d_k2b_table_acquire_80176664(struct K2bTable *self, int key, struct K2bInterface **out)
{
    unsigned short slot;
    int status = w3d_table_find_80177eb0(self, key, &slot);
    if (status < 0) {
        if (*out)
            ((void (*)(struct K2bInterface *))(*out)->vtable[4])(*out);
        *out = 0;
        return status;
    } else {
        unsigned int index = slot;
        struct K2bInterface **entries = self->entries;
        if (entries[index])
            ((void (*)(struct K2bInterface *))entries[index]->vtable[3])(entries[index]);
        if (*out)
            ((void (*)(struct K2bInterface *))(*out)->vtable[4])(*out);
        *out = entries[index];
        return 0;
    }
}
// desc: Appears to look up a table slot, retain its interface and replace the caller's held interface, or clear it on failure.
