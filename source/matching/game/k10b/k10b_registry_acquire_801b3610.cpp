// Partial view of a named-object registry. Looks a name up in the local item
// array; a hit is retained through its interface and returned. A miss asks
// the parent resolver (when there is one) and, on success, tells the registry
// through its virtual hook. Result codes are the 0x80070057 (bad argument) and
// 0x80004005 (no parent) values used by the original.
struct K10bItem_801b3610;
struct K10bItemVtable_801b3610 {
    void *slots0[3];
    void (*retain)(K10bItem_801b3610 *self);
};
struct K10bItem_801b3610 {
    K10bItemVtable_801b3610 *vtable;
};

struct K10bResolver_801b3610;
struct K10bResolverVtable_801b3610 {
    void *slots0[5];
    int (*resolve)(K10bResolver_801b3610 *self, const char *name, K10bItem_801b3610 **out);
};
struct K10bResolver_801b3610 {
    K10bResolverVtable_801b3610 *vtable;
};

struct K10bRegistry_801b3610;
struct K10bRegistryVtable_801b3610 {
    void *slots0[6];
    void (*added)(K10bRegistry_801b3610 *self, const char *name, K10bItem_801b3610 *item);
};
struct K10bRegistry_801b3610 {
    K10bRegistryVtable_801b3610 *vtable;
    char unknown4[16];
    K10bResolver_801b3610 *parent;
    char unknown18[20];
    K10bItem_801b3610 **items;
};

extern "C" {
int fn_801b4060(K10bRegistry_801b3610 *self, const char *name);

int w3d_k10b_registry_acquire_801b3610(K10bRegistry_801b3610 *self, const char *name, K10bItem_801b3610 **out) {
    if (!out || !name) return 0x80070057;
    *out = 0;
    int index = fn_801b4060(self, name);
    if (index != -1) {
        K10bItem_801b3610 *item = *(K10bItem_801b3610 **)((char *)self->items + (index << 2));
        *out = item;
        item->vtable->retain(item);
        return 0;
    }
    if (self->parent) {
        int result = self->parent->vtable->resolve(self->parent, name, out);
        if (result >= 0) self->vtable->added(self, name, *out);
        return result;
    }
    return 0x80004005;
}
}
