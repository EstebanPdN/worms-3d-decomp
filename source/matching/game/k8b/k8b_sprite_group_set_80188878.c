typedef struct K8bIface { void (**vtable)(struct K8bIface *); } K8bIface;
typedef struct K8bSource { int (**vtable)(struct K8bSource *, K8bIface **, const char *); } K8bSource;
extern int w3d_s20_describe_fields_80190538(char *self, K8bSource *source);

int w3d_k8b_sprite_group_set_80188878(char *self, K8bSource *source)
{
    int status = w3d_s20_describe_fields_80190538(self, source);
    if (status >= 0) {
        K8bIface *found = 0;
        K8bIface *group;
        K8bIface *old;
        source->vtable[8](source, &found, "SpriteSetGroup");
        group = found;
        if (group)
            group->vtable[3](group);
        old = *(K8bIface **)(self + 52);
        if (old)
            old->vtable[4](old);
        *(K8bIface **)(self + 52) = group;
        if (found)
            found->vtable[4](found);
        status = (int)0x80004001;
    }
    return status;
}
