extern int fn_80181598(char *, int, int *);
extern int fn_80181884(char *, int, float, float);

int w3d_s20_forward_found_80181814(char *self, int key, float a, float b) {
    int found;
    if (fn_80181598(self, key, &found) < 0)
        return 0x80004005;
    return fn_80181884(self, found, a, b);
}

typedef struct S20Object { void **vtable; } S20Object;
extern int fn_80342a78(int);
extern int fn_80178d1c(int);
extern void fn_8015fb2c(char *, int);

int w3d_s20_toggle_mode_8012bd08(char *self, int arg) {
    int state = fn_80178d1c(fn_80342a78(*(int *)(self + 32)));
    S20Object *object = *(S20Object **)(self + 28);
    void **table = object->vtable;
    int mode = 1;
    if (state == 2)
        mode = 0;
    ((void (*)(S20Object *, int))table[22])(object, mode);
    fn_8015fb2c(self, arg);
    return 0;
}
