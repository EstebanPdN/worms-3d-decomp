struct K8bDesc { char pad0[20]; struct K8bDesc *parent; };
struct K8bIface { struct K8bDesc *(**vtable)(struct K8bIface *); };
struct K8bArray {
    void **vtable;
    unsigned short references;
    char pad6[14];
    unsigned int capacity;
    unsigned int count;
    unsigned short locks;
    char pad30[2];
    struct K8bIface *data[1];
};
extern void w3d_k5b_iface_array_field_set_801ef2ec(char *object, int offset, int unused, struct K8bIface *item, int index);
extern void w3d_k5b_iface_array_field_append_801ef174(char *object, int offset, int unused, struct K8bIface *item);

static inline int k8b_derives(struct K8bDesc *desc, struct K8bDesc *key)
{
    while (desc != key) {
        struct K8bDesc *parent = desc->parent;
        if (desc == parent)
            return 0;
        desc = parent;
    }
    return 1;
}

int w3d_k8b_iface_add_801b14e8(char *self, struct K8bIface *item)
{
    struct K8bArray *array = *(struct K8bArray **)(self + 32);
    unsigned int count = array->count;
    struct K8bIface **cursor = array->data;
    unsigned int i = 0;
    struct K8bDesc *key = item->vtable[5](item);
    (*(struct K8bArray **)(self + 32))->locks++;
    for (; i < count; i++) {
        struct K8bIface *entry = *cursor++;
        if (k8b_derives(entry->vtable[5](entry), key)) {
            w3d_k5b_iface_array_field_set_801ef2ec(self, 32, 2, item, i);
            return 1;
        }
    }
    w3d_k5b_iface_array_field_append_801ef174(self, 32, 2, item);
    return 0;
}
