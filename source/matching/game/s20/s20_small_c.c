/* Small forwarding wrappers. */
extern char *fn_8019a2a8(char *, int);
extern void fn_800fde98(void *, int);
extern void fn_800fdf58(void *, int);
extern void *lbl_804aaf64;
extern void fn_8016f650(int);
extern int lbl_803a54e4[];
extern int fn_801720fc(char *, int);

int w3d_s20_has_record_80199f38(char *self, int key) {
    if (fn_8019a2a8(self, key) != 0)
        return 1;
    return 0;
}

void w3d_s20_notify_global_800fde64(int value) {
    if (lbl_804aaf64 != 0)
        fn_800fde98(lbl_804aaf64, value);
}

void w3d_s20_notify_global_800fdf24(int value) {
    if (lbl_804aaf64 != 0)
        fn_800fdf58(lbl_804aaf64, value);
}

int w3d_s20_forward_table_entry_8016a538(char *self, char *item) {
    fn_8016f650(lbl_803a54e4[*(int *)(item + 24)]);
    return 0;
}

int w3d_s20_get_selected_80172050(char *self, void * arg_r4) {
    int index = fn_801720fc(self, arg_r4);
    return *(int *)(*(char **)(self + 60) + index * 4);
}
