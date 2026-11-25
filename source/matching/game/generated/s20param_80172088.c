/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Small forwarding wrappers. */
extern char *fn_8019a2a8(char *, int);
extern void fn_800fde98(void *, int);
extern void fn_800fdf58(void *, int);
extern void *lbl_804aaf64;
extern void fn_8016f650(int);
extern int lbl_803a54e4[];
extern int fn_801720fc(char *, int);

int w3d_s20_get_selected_80172088(char *self, void * arg_r4) {
    int index = fn_801720fc(self, arg_r4);
    return *(int *)(*(char **)(self + 72) + index * 4);
}
