/* Repeated target dispatch on the secondary base subobject (this - 4, null-checked). */
typedef int (*S20HandlerY)(char *, char *);
extern void fn_8016a0a4(char *);

int w3d_s20_dispatch_until_done_801689e4(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int result;
    *(int *)(base + 152) = 0;
    result = 0;
    do {
        char *target = *(char **)(item + 52);
        if (target != 0)
            result = ((S20HandlerY)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
        fn_8016a0a4(base);
        target = *(char **)(item + 48);
        if (target != 0)
            ((S20HandlerY)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
        *(int *)(base + 152) += 1;
    } while (result == 1);
    return 0;
}
