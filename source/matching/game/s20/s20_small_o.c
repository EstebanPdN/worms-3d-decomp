/* Virtual calls on the object resolved from a stored handle. */
typedef struct S20Object { void **vtable; } S20Object;
extern S20Object *fn_80164fc8(int);

int w3d_s20_call_handle_object_800e95e0(char *self, int arg) {
    S20Object *object = fn_80164fc8(*(int *)(self + 192));
    return ((int (*)(S20Object *, int, char *))object->vtable[12])(object, arg, self + 72);
}

int w3d_s20_call_handle_object_800e962c(char *self, int arg) {
    S20Object *object = fn_80164fc8(*(int *)(self + 192));
    return ((int (*)(S20Object *, int, char *))object->vtable[13])(object, arg, self + 84);
}
