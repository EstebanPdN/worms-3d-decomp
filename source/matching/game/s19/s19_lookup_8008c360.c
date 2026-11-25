#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void *w3d_s20_lookup_handle_object_80164fc8(int);
void *s19_lookup_slot_8008c360(void *self, int i)
{
    void *result = 0;
    void *object = w3d_s20_lookup_handle_object_80164fc8(*(int *)((char *)FIELD(self, void *, 296) + (i << 2)));
    if (object)
        result = object;
    return result;
}
