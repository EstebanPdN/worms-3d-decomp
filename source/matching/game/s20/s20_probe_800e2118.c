/* Look up a named entry through a temporary shared string, then notify an object. */
typedef struct S20Object { void **vtable; } S20Object;
typedef struct W3dString { char *text; } W3dString;
extern void fn_8020bb54(W3dString *, char *);
extern void fn_8015adf4(W3dString *, char *, int);
extern void fn_8020c5c4(W3dString *);
extern void fn_80341588(W3dString *);
extern char lbl_80389efc[];

void w3d_s20_bind_named_entry_800e2118(char *self, S20Object *object, int *value, int extended) {
    W3dString name;
    W3dString *temp;
    unsigned int flags;
    fn_8020bb54(temp = &name, lbl_80389efc);
    fn_8015adf4(&name, self + 300, 255);
    fn_8020c5c4(temp);
    fn_80341588(temp);
    ((void (*)(S20Object *, int, int))object->vtable[23])(object, *(int *)(self + 300), *value);
    flags = *(unsigned int *)(self + 180);
    *(unsigned int *)(self + 180) = flags | 16;
    if (extended != 0)
        *(unsigned int *)(self + 180) = flags | 48;
}
