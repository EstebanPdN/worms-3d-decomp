/* Slot-table lookups, a reference replacement and a counted destructor. */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_80177eb0(char *, void *, unsigned short *);
extern int *fn_80179170(void *);
extern int fn_80343744(int);
extern int *fn_80178f54(void *);
extern int fn_80343df4(int);

int w3d_s20_query_int_80176b2c(char *self, int key, int *out) {
    unsigned short index;
    int result;
    if (fn_80177eb0(self, key, &index) >= 0) {
        int *value = fn_80179170(fn_80343744(((int *)*(void **)(self + 24))[index]));
        *out = *value;
        result = 0;
    } else {
        result = 0x80004005;
    }
    return result;
}

int w3d_s20_query_int_80176c68(char *self, int key, int *out) {
    unsigned short index;
    int result;
    if (fn_80177eb0(self, key, &index) >= 0) {
        int *value = fn_80178f54(fn_80343df4(((int *)*(void **)(self + 24))[index]));
        *out = *value;
        result = 0;
    } else {
        result = 0x80004005;
    }
    return result;
}

void w3d_s20_replace_owned_801784e4(char *self, S20Object *value) {
    S20Object *current = *(S20Object **)self;
    if (current != value) {
        if (current != 0) {
            ((void (*)(S20Object *))current->vtable[16])(current);
            if (*(int *)self != 0) {
                *(int *)self = 0;
                *(int *)(self + 4) = 0;
            }
        }
        *(S20Object **)self = value;
    }
}

extern int fn_801799d4(char *, int);
extern char lbl_80412e20[];
extern int lbl_804ab69c;

int w3d_s20_destruct_counted_80188ab8(char *self, int flags) {
    int count = lbl_804ab69c;
    S20Object *held = *(S20Object **)(self + 168);
    *(char **)self = lbl_80412e20;
    lbl_804ab69c = count - 1;
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    return fn_801799d4(self, flags);
}
