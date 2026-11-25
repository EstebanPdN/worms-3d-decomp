/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef void (*S20Handler)(char *, char *);

int w3d_s20_dispatch_two_targets_80166a70(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(base + 52) != 0) {
        char *target = *(char **)(item + 52);
        if (target != 0) {
            char *sub = base + 4;
            ((S20Handler)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        }
    }
    if (*(int *)(base + 56) != 0) {
        char *target = *(char **)(item + 48);
        if (target != 0) {
            char *sub = base + 4;
            ((S20Handler)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        }
    }
    return 0;
}
