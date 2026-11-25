/* Method on the secondary base subobject (this - 4, null-checked). */
typedef void (*S20HandlerM)(char *, char *);

int w3d_s20_collect_item_modes_801d58d0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int zero = 0;
    int first;
    int second;
    int mode;
    char *target;
    *(int *)(base + 44) = zero;
    target = *(char **)(item + 52);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerM)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    first = *(int *)(base + 44);
    *(int *)(base + 44) = zero;
    target = *(char **)(item + 48);
    if (target != 0) {
        char *sub = base + 4;
        ((S20HandlerM)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    second = *(int *)(base + 44);
    mode = 0;
    if (first == 1 || second == 1)
        mode = 1;
    else if (first == 2 || second == 2)
        mode = 2;
    if (*(int *)(base + 48) != 0)
        *(unsigned int *)(item + 56) = (*(unsigned int *)(item + 56) & ~6u) | 2;
    else
        *(unsigned int *)(item + 56) = (*(unsigned int *)(item + 56) & ~6u) | (mode << 1);
    return 0;
}
