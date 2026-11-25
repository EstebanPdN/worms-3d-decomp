/* Counted destructor, guarded forwards and an indexed lookup through a virtual call. */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_801858fc(char *, int);
extern char lbl_80412068[];
extern int lbl_804ab580;

int w3d_s20_destruct_counted_80172b64(char *self, int flags) {
    int count = lbl_804ab580;
    S20Object *held = *(S20Object **)(self + 128);
    *(char **)self = lbl_80412068;
    lbl_804ab580 = count - 1;
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    return fn_801858fc(self, flags);
}
