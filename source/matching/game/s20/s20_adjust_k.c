/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Block16 { int words[4]; } S20Block16;
typedef void (*S20HandlerK)(char *, char *);
extern char lbl_8045e63c[];
extern int fn_801a572c(char *, char *);

int w3d_s20_refresh_item_block_801a5a6c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(item + 40) == 0) {
        ((void (*)(char *, char *))(*(void ***)base)[17])(base, item + 20);
        return 0;
    }
    {
        char *target;
        S20Block16 *block;
        ((void (*)(char *, char *))(*(void ***)base)[17])(base, lbl_8045e63c);
        target = *(char **)(item + 48);
        if (target != 0) {
            char *sub = base + 4;
            ((S20HandlerK)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        }
        block = ((S20Block16 *(*)(char *))(*(void ***)base)[16])(base);
        *(S20Block16 *)(item + 20) = *block;
        if (*(unsigned int *)(base + 88) & 2)
            *(int *)(item + 40) = 0;
    }
    return 0;
}

int w3d_s20_refresh_item_block_801a58d0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(item + 40) == 0) {
        ((void (*)(char *, char *))(*(void ***)base)[17])(base, item + 20);
        return 0;
    }
    {
        char *target = *(char **)(item + 48);
        char *sub;
        S20Block16 *block;
        if (target == 0)
            return fn_801a572c(self, item);
        sub = base + 4;
        *(char **)(sub + 20) = item;
        ((S20HandlerK)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        block = ((S20Block16 *(*)(char *))(*(void ***)base)[16])(base);
        *(S20Block16 *)(item + 20) = *block;
        if (*(unsigned int *)(base + 88) & 8)
            *(int *)(item + 40) = 0;
    }
    return 0;
}
