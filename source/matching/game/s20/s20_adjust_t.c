/* Render-state method on the secondary base subobject (this - 4, null-checked). */
typedef int (*S20HandlerT)(char *, char *);
extern int fn_801a2bf4(void *, char *, int);
extern void fn_8030af88(int, int);
extern void fn_8016c014(char *, int);
extern void fn_8016c130(char *, int, int, float, float, float);
extern void fn_803080a4(int);
extern void fn_8030b648(int);
extern void fn_8030b4ac(int, int, int, int);
extern void fn_8016c1f4(char *);
extern float lbl_803a5568[];

int w3d_s20_apply_two_ranges_8016ab0c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record = *(char **)(item + 48);
    char *first = *(char **)(item + 52);
    char *second = *(char **)(item + 56);
    fn_801a2bf4(*(int *)(base + 116), record + 32, *(int *)(record + 24));
    *(int *)(base + 216) = 0;
    if (first != 0) {
        char *sub = base + 4;
        ((S20HandlerT)(*(void ***)(sub + 24))[*(unsigned short *)(first + 6)])(sub, first);
        ((S20HandlerT)(*(void ***)(sub + 24))[*(unsigned short *)(second + 6)])(sub, second);
        fn_8030af88(1, 0);
        fn_8016c014(base, 0);
        fn_8016c130(base, 0, 4, lbl_803a5568[0], *(float *)(item + 44), *(float *)(item + 40));
        fn_8016c130(base, 1, 4, *(float *)(item + 28), *(float *)(item + 36), *(float *)(item + 32));
        fn_803080a4(*(unsigned char *)(base + 219));
        fn_8030b648(*(unsigned char *)(base + 219));
        fn_8030b4ac(1, 1, 0, 255);
    } else {
        fn_8016c1f4(base);
    }
    return 0;
}
