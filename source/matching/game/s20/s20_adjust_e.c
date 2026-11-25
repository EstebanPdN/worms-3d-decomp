/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { void **vtable; } S20Object;
typedef void (*S20Handler)(char *, char *);
typedef void (*S20Notify)(S20Object *, char *);
extern int fn_801ab98c(char *, char *);

int w3d_s20_remap_and_dispatch_801aba00(char *self, char *item) {
    int result = fn_801ab98c(self, item);
    if (result < 0)
        return result;
    {
        char *base = self ? self - 4 : 0;
        char *target = *(char **)(item + 60);
        if (target != 0) {
            char *sub = base + 4;
            ((S20Handler)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        }
        if (*(int *)(base + 80) != 0) {
            S20Object *owner = *(S20Object **)(base + 44);
            ((S20Notify)owner->vtable[6])(owner, item);
        }
    }
    return 0;
}

extern int fn_8016b488(char *, char *);

int w3d_s20_apply_link_8016b5a0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record = *(char **)(item + 92);
    char *link = *(char **)(record + 20);
    if (link != 0) {
        *(int *)(base + 292) = *(int *)(link + 8);
        if (*(int *)(link + 8) != 0)
            *(unsigned int *)(base + 180) |= 0x80000000;
    } else {
        char *sub = base + 4;
        ((S20Handler)(*(void ***)(sub + 24))[*(unsigned short *)(record + 6)])(sub, record);
    }
    return fn_8016b488(base ? base + 4 : 0, item);
}
