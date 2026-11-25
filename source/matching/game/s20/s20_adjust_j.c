/* Method on the secondary base subobject (this - 4, null-checked). */
typedef void (*S20HandlerJ)(char *, char *);
extern int *fn_801d0858(char *, int *);
extern int fn_801a2bf4(void *, char *, int);
extern void fn_8030ae60(int);
extern void fn_8016c014(char *, int);
extern void fn_803080a4(int);
extern void fn_8016c1f4(char *);
extern void fn_8030ae84(int);
extern void fn_8030b648(int);

int w3d_s20_apply_record_8016c240(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record = *(char **)(item + 28);
    int count;
    char *range;
    char *target = 0;
    int found;
    int *result;
    count = *(int *)(record + 24);
    range = record + 32;
    result = fn_801d0858(item, &found);
    if (found != 0)
        target = *(char **)result;
    fn_801a2bf4(*(int *)(base + 116), range, count);
    {
        int zero = 0;
        *(int *)(base + 216) = zero;
        *(unsigned char *)(base + 220) = zero;
        fn_8030ae60(zero);
    }
    if (target != 0) {
        char *sub;
        fn_8016c014(base, 0);
        sub = base + 4;
        ((S20HandlerJ)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        fn_803080a4(*(unsigned char *)(base + 219));
    } else {
        fn_8016c1f4(base);
    }
    fn_8030ae84(0);
    fn_8030b648(1);
    return 0;
}
