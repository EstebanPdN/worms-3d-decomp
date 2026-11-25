typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Owner20 { char pad[20]; S20Object *provider; } S20Owner20;
int w3d_s20_x_80166404(S20Owner20 *self, char *key, int index) {
    S20Object *provider = self->provider;
    char *sub = key ? key + 4 : 0;
    char *table = ((char *(*)(S20Object *, char *))provider->vtable[13])(provider, sub);
    return table == 0 ? 0 : *(int *)(table + 16 + index * 4);
}
