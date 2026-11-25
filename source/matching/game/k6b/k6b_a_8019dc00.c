struct K6bIface { void **vtable; };
struct K6bIfaceVector {
    unsigned int count;
    unsigned int capacity;
    struct K6bIface **data;
};
struct K6bScriptHost {
    char head[24];
    struct K6bIfaceVector objects;
};
extern void fn_80210d54(struct K6bIfaceVector *vector, unsigned int size);
int w3d_k6b_script_host_add_object_8019dc00(struct K6bScriptHost *self, struct K6bIface *item)
{
    struct K6bIfaceVector *objects = &self->objects;
    char *data;
    unsigned int offset;
    fn_80210d54(objects, self->objects.count + 1);
    offset = self->objects.count << 2;
    data = (char *)objects->data;
    if (item != 0)
        ((void (*)(struct K6bIface *))item->vtable[3])(item);
    {
        struct K6bIface *old = *(struct K6bIface **)(data + offset);
        if (old != 0)
            ((void (*)(struct K6bIface *))old->vtable[4])(old);
    }
    *(struct K6bIface **)(data + offset) = item;
    self->objects.count++;
    ((void (*)(struct K6bIface *, struct K6bScriptHost *))item->vtable[6])(item, self);
    return 0;
}
// desc: w3d_k6b_script_host_add_object_8019dc00: Appears to grow the object vector at +24, store the retained object in the new slot (releasing any old one), bump the count and attach the object to the host.
