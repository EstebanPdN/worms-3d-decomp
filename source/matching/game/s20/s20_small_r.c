/* Slot flags, owner forwards, indexed float lookup and a Lua check. */
extern void fn_80307e24(int, int, int, int, int, int);

void w3d_s20_enable_slot_flag_8016c014(char *self, int index) {
    int offset = index * 4;
    char *table = self + 328;
    if (*(int *)(table + offset) != 1) {
        *(int *)(self + 304) = 0;
        fn_80307e24(index, 1, 4, 60, 0, 125);
        *(int *)(table + offset) = 1;
    }
}

extern void fn_801ef380(char *, int, int, int, int);
extern void fn_801ef174(char *, int, int, char *);

int w3d_s20_forward_owner_801750f4(char *self, char *item) {
    char *owner = *(char **)(self + 120);
    int value = *(int *)(*(char **)(owner + 44) + 24);
    if (value != 0)
        fn_801ef380(owner, 44, 3, 0, value);
    fn_801ef174(*(char **)(self + 120), 44, 3, item);
    return 0;
}

extern int fn_80177eb0(char *, void *, unsigned short *);
extern int fn_80342a74(int);
extern float fn_80178df0(void *);

int w3d_s20_get_float_80176a44(char *self, int key, float *out) {
    unsigned short index;
    if (fn_80177eb0(self, key, &index) < 0)
        return 0x80004005;
    *out = fn_80178df0(fn_80342a74(*(int *)(*(char **)(self + 24) + index * 4)));
    return 0;
}

extern void fn_802cd99c(void *, int);
extern void fn_802ce264(void *, int);
extern int fn_802cda44(void *, int);
extern int fn_8019eed4(void *, char *, int);
extern char lbl_803a99f8[];

int w3d_s20_check_lua_function_8019f838(void *L) {
    fn_802cd99c(L, 2);
    fn_802ce264(L, -10002);
    if (fn_802cda44(L, -1) != 0)
        return 1;
    return fn_8019eed4(L, lbl_803a99f8, 0);
}
