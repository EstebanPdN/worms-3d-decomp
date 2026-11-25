/* Render-state methods on the secondary base subobject (this - 4, null-checked). */
typedef void (*S20HandlerQ)(char *, char *);
typedef struct S20Globals { char pad[5268]; unsigned int flags; } S20Globals;
extern S20Globals *lbl_804b1884;
extern int fn_801a2bf4(void *, char *, int);
extern void fn_8030ae60(int);
extern void fn_8016c014(char *, int);
extern void fn_801a3190(void *, int, char *);
extern void fn_803080a4(int);
extern void fn_8016803c(S20Globals *, int);
extern int fn_801a314c(void *, int);
extern void fn_801a3164(void *, int);
extern void fn_8016804c(S20Globals *, int);
extern void fn_8030ae84(int);
extern void fn_8030b648(int);

int w3d_s20_apply_texture_80168af0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record;
    char *entry;
    char *texture;
    ((void (*)(char *, char *))(*(void ***)base)[17])(base, item);
    record = *(char **)(item + 32);
    {
        int zero = 0;
        int device = *(int *)(base + 116);
        int count = *(int *)(record + 24);
        *(int *)(base + 216) = zero;
        fn_801a2bf4(device, record + 32, count);
    }
    {
        char *list = *(char **)(item + 28) + 32;
        unsigned int slot = *(unsigned char *)(base + 212);
        entry = ((char **)list)[slot];
    }
    texture = *(char **)(entry + 36);
    if (texture != 0) {
        fn_8030ae60(0);
        fn_8016c014(base, 0);
        fn_801a3190(*(int *)(base + 116), *(int *)(base + 216), texture);
        fn_803080a4(*(unsigned char *)(base + 219));
        fn_8016803c(lbl_804b1884, 32);
        lbl_804b1884->flags |= 0x20000000;
    } else {
        fn_801a314c(*(int *)(base + 116), 0);
        fn_801a3164(*(int *)(base + 116), 0);
        fn_8016804c(lbl_804b1884, 32);
    }
    fn_8030ae84(0);
    fn_8030b648(1);
    *(int *)(base + 216) = 0;
    return 0;
}
