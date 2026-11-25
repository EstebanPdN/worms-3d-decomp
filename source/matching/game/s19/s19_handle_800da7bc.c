#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void *w3d_s20_lookup_handle_object_80164fc8(int);
int s19_handle_value_800da7bc(void *self)
{
    int result;
    void *object;
    if (FIELD(self, int, 28) == -1) {
        result = -1;
    } else {
        object = w3d_s20_lookup_handle_object_80164fc8(FIELD(self, int, 28));
        if (object) {
            result = FIELD(object, int, 164);
        } else {
            FIELD(self, int, 28) = -1;
            result = -1;
        }
    }
    return result;
}
