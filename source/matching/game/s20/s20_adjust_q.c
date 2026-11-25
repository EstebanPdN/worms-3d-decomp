/* Render-state method on the secondary base subobject (this - 4, null-checked). */
typedef int (*S20HandlerR)(char *, char *);
extern int fn_801a2bf4(void *, char *, int);
extern void fn_8030b014(int, int, int, int, int);
extern void fn_8030b09c(int, int, int, int, int, int);
extern void fn_8016c014(char *, int);
extern void fn_8016c07c(char *, int);
extern void fn_803080a4(int);
extern void fn_8030b648(int);
extern void fn_8030b4ac(int, int, int, int);
extern void fn_8016c1f4(char *);

int w3d_s20_apply_two_textures_8016a72c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record = *(char **)(item + 28);
    char *first = *(char **)(item + 36);
    char *second = *(char **)(item + 32);
    fn_801a2bf4(*(int *)(base + 116), record + 32, *(int *)(record + 24));
    *(int *)(base + 216) = 0;
    if (first != 0) {
        char *sub = base + 4;
        ((S20HandlerR)(*(void ***)(sub + 24))[*(unsigned short *)(first + 6)])(sub, first);
        ((S20HandlerR)(*(void ***)(sub + 24))[*(unsigned short *)(second + 6)])(sub, second);
        fn_8030b014(1, 15, 8, 12, 0);
        fn_8030b09c(1, 0, 0, 0, 1, 0);
        fn_8016c014(base, 0);
        fn_8016c07c(base, 1);
        fn_803080a4(*(unsigned char *)(base + 219));
        fn_8030b648(*(unsigned char *)(base + 219));
        fn_8030b4ac(1, 1, 1, 255);
    } else {
        fn_8016c1f4(base);
    }
    return 0;
}
