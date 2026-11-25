/* Lua binding helpers. */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_802ddd14(void *, int, int, char *);
extern char lbl_803a991c[];

int w3d_s20_load_script_8019e1a8(char *self, int a, int b) {
    return fn_802ddd14(*(void **)(self + 20), a, b, lbl_803a991c) != 0 ? 0x80004005 : 0;
}

extern int *fn_8019e68c(char *, int);
extern int fn_801ea470(void *);

int w3d_s20_apply_user_value_8019f9ec(char *self) {
    int *value = fn_8019e68c(self, 1);
    int converted = fn_801ea470(*value);
    S20Object *target = *(S20Object **)(*(char **)(self + 88) + 36);
    ((void (*)(S20Object *, int))target->vtable[7])(target, converted);
    return 1;
}

extern void *fn_802cde08(void *, int);
typedef struct S20Record { char pad[4]; unsigned short half; unsigned char byte; } S20Record;
typedef struct S20Holder { S20Record *record; } S20Holder;
extern S20Holder *lbl_804ab728;
extern int fn_801ef174(int, int, int, void *);

int w3d_s20_forward_user_values_8019e7e8(void *L) {
    int first = *(int *)fn_802cde08(L, 1);
    int second = *(int *)fn_802cde08(L, -1);
    S20Record *record = lbl_804ab728->record;
    fn_801ef174(first, record->half, record->byte, second);
    return 0;
}

int w3d_s20_query_object_8019dd80(char *self, char *object, int *out) {
    int local;
    char *sub = object + 4;
    S20Object *first = *(S20Object **)object;
    int status = ((int (*)(S20Object *, char *, int, int *))first->vtable[5])(first, sub, 16384, &local);
    *out = local;
    if (status < 0)
        return 0;
    return local != 0 ? (int)sub : 0;
}
