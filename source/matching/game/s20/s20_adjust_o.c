/* Method on the secondary base subobject (this - 4, null-checked). */
typedef void (*S20HandlerP)(char *, char *);

int w3d_s20_dispatch_item_fields_8016b488(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *target;
    *(int *)(base + 284) = 0;
    *(int *)(base + 288) = 0;
    target = *(char **)(item + 64);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerP)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    } else {
        *(char **)(base + 124) = target;
    }
    target = *(char **)(item + 80);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerP)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    target = *(char **)(item + 72);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerP)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    target = *(char **)(item + 68);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerP)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    target = *(char **)(item + 76);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerP)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    return 0;
}
