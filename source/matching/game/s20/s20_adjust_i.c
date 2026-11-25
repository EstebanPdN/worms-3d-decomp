/* Method on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Block24 { int words[6]; } S20Block24;
typedef void (*S20HandlerI)(char *, char *);

int w3d_s20_refresh_item_block_801a5b60(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(item + 44) == 0) {
        ((void (*)(char *, char *))(*(void ***)base)[19])(base, item + 20);
        return 0;
    }
    {
        char *target = *(char **)(item + 80);
        S20Block24 *block;
        if (target != 0) {
            char *sub = base + 4;
            ((S20HandlerI)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        }
        block = ((S20Block24 *(*)(char *))(*(void ***)base)[18])(base);
        *(S20Block24 *)(item + 20) = *block;
        if (*(unsigned int *)(base + 88) & 1)
            *(int *)(item + 44) = 0;
    }
    return 0;
}
