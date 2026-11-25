/* Method on the secondary base subobject (this - 4, null-checked). */
typedef int (*S20HandlerL)(char *, char *);
extern void fn_801a9b10(char *);
extern void fn_801a9c9c(char *);

int w3d_s20_dispatch_with_guard_801aace0(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int saved = *(int *)(base + 324);
    int result;
    if (saved == 0) {
        unsigned char first;
        unsigned char second;
        char *entry;
        fn_801a9b10(base);
        second = *(unsigned char *)(item + 25);
        first = *(unsigned char *)(item + 24);
        *(unsigned char *)(base + 305) = first;
        *(unsigned char *)(base + 304) = second;
        entry = *(char **)(base + 288) + second * 16;
        if (*(int *)(entry + 12) == 3) {
            char *sub;
            char *target;
            *(int *)(base + 324) = 1;
            sub = base + 4;
            target = *(char **)(item + 20);
            result = ((S20HandlerL)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
            *(int *)(base + 324) = saved;
        } else {
            char *target = *(char **)(item + 20);
            char *sub = base + 4;
            result = ((S20HandlerL)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        }
        fn_801a9c9c(base);
    } else {
        char *target = *(char **)(item + 20);
        char *sub = base + 4;
        result = ((S20HandlerL)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    return result;
}
