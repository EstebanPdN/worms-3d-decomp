/* Methods that run on the secondary base subobject of an object (this - 4, null-checked). */
typedef struct S20Temp { int words[6]; } S20Temp;
typedef void (*S20SlotPut)(void *, char *);
extern void fn_801f5c1c(S20Temp *, char *, int);
extern void fn_801f57d4(S20Temp *, char *, int, char *);
extern void fn_801f5970(S20Temp *, char *, int, int);

int w3d_s20_dispatch_temp_801a5cb0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    S20Temp temp;
    char *record = *(char **)(item + 24);
    char *tp = (char *)&temp;
    fn_801f5c1c((S20Temp *)tp, record + 32, *(int *)(record + 24));
    ((S20SlotPut)*(void **)(*(char **)base + 76))(base, tp);
    return 0;
}

int w3d_s20_dispatch_temp_801a5d18(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    S20Temp temp;
    char *record = *(char **)(item + 20);
    char *tp = (char *)&temp;
    fn_801f57d4((S20Temp *)tp, record + 32, *(int *)(record + 24), item + 24);
    ((S20SlotPut)*(void **)(*(char **)base + 76))(base, tp);
    return 0;
}

int w3d_s20_dispatch_temp_801a5d88(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    S20Temp temp;
    char *record = *(char **)(item + 20);
    char *tp = (char *)&temp;
    fn_801f5970((S20Temp *)tp, record + 32, *(int *)(record + 24), *(unsigned char *)(item + 24));
    ((S20SlotPut)*(void **)(*(char **)base + 76))(base, tp);
    return 0;
}

int w3d_s20_attach_record_80168e28(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record = *(char **)(item + 24);
    int link = *(int *)(record + 24);
    char *range = record + 32;
    if (range == 0)
        return 0;
    *(int *)(base + 188) = link;
    if (link != 0) {
        *(char **)(base + 160) = range;
        *(unsigned int *)(base + 180) |= 0x40000000;
    } else {
        *(int *)(base + 160) = link;
        *(unsigned int *)(base + 180) &= ~0x40000000u;
    }
    *(unsigned int *)(base + 180) &= 0x7fffffff;
    *(int *)(base + 292) = 0;
    return 0;
}

extern int fn_801a4874(char *, char *);
extern int fn_801a3ba0(char *, char *);
extern int fn_801a3d90(char *, char *);
extern int fn_801aa79c(char *, char *);
typedef void (*S20Handler)(char *, char *);

int w3d_s20_apply_item_mode_801d5730(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int result;
    *(int *)(base + 44) = 0;
    result = fn_801a4874(self, item);
    if (*(int *)(base + 48) != 0)
        *(unsigned int *)(item + 88) = (*(unsigned int *)(item + 88) & ~6u) | 2;
    else
        *(unsigned int *)(item + 88) = (*(unsigned int *)(item + 88) & ~6u) | (*(int *)(base + 44) << 1);
    return result;
}

int w3d_s20_apply_item_mode_801d567c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int result;
    *(int *)(base + 44) = 0;
    result = fn_801a3ba0(self, item);
    if (result >= 0) {
        if (*(int *)(base + 48) != 0)
            *(unsigned int *)(item + 24) = (*(unsigned int *)(item + 24) & ~6u) | 2;
        else
            *(unsigned int *)(item + 24) = (*(unsigned int *)(item + 24) & ~6u) | (*(int *)(base + 44) << 1);
    }
    return result;
}

int w3d_s20_apply_item_mode_801d59d0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int result;
    *(int *)(base + 44) = 0;
    result = fn_801a3d90(self, item);
    if (result >= 0) {
        if (*(int *)(base + 48) != 0)
            *(unsigned int *)(item + 24) = (*(unsigned int *)(item + 24) & ~6u) | 2;
        else
            *(unsigned int *)(item + 24) = (*(unsigned int *)(item + 24) & ~6u) | (*(int *)(base +

 44) << 1);
    }
    return result;
}

int w3d_s20_handle_item_target_801aaee8(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *target = *(char **)(item + 48);
    if (target != 0) {
        int saved = *(int *)(base + 44);
        char *sub = base + 4;
        *(int *)(base + 44) = 0;
        ((S20Handler)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        *(int *)(base + 44) = saved;
    }
    return fn_801aa79c(self, item);
}
