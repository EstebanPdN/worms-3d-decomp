/* Sound playback helpers that bind two named resources then start a sound. */
extern int fn_800fc43c(char **, int);
extern int fn_800fc550(char **, int);
extern void fn_800356e0(void *, char *, float, float);
extern int fn_80035714(void *, char *, float);
extern char lbl_8038b634[];
extern char lbl_8038b640[];
extern char lbl_8038b658[];
extern char lbl_8038b664[];
extern char lbl_8038b674[];
extern float lbl_8038b660[];
extern float lbl_8038b66c[];
extern float lbl_8038b670[];
extern float lbl_8038b67c[];
extern int lbl_804aa8c8;

void w3d_s20_play_sound_pair_800edc28(char *self) {
    char *first;
    char *second;
    int handle;
    first = lbl_8038b634;
    handle = *(int *)(self + 20);
    fn_800fc550(&first, *(int *)(self + 304));
    second = lbl_8038b640;
    fn_800fc43c(&second, handle);
    fn_800356e0(lbl_804aa8c8, lbl_8038b658, lbl_8038b660[0], lbl_8038b660[0]);
}

void w3d_s20_play_sound_pair_800edca0(char *self) {
    char *first;
    char *second;
    int handle;
    first = lbl_8038b634;
    handle = *(int *)(self + 20);
    fn_800fc550(&first, *(int *)(self + 304));
    second = lbl_8038b640;
    fn_800fc43c(&second, handle);
    fn_800356e0(lbl_804aa8c8, lbl_8038b664, lbl_8038b66c[0], lbl_8038b670[0]);
}

void w3d_s20_play_sound_single_800edd1c(char *self) {
    char *first;
    char *second;
    int handle;
    first = lbl_8038b634;
    handle = *(int *)(self + 20);
    fn_800fc550(&first, *(int *)(self + 304));
    second = lbl_8038b640;
    fn_800fc43c(&second, handle);
    fn_80035714(lbl_804aa8c8, lbl_8038b674, lbl_8038b67c[0]);
}
