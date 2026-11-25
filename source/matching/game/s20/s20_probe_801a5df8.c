/* Method on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Color { float r; float g; float b; float a; } S20Color;
typedef void (*S20HandlerT)(char *, char *);
extern int fn_801a572c(char *, char *);
extern char lbl_8045e62c[];

int w3d_s20_apply_override_801a5df8(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int status = fn_801a572c(self, item);
    if (status < 0)
        return status;
    {
        char *target = *(char **)(item + 48);
        if (target != 0) {
            int kind = *(int *)(target + 40);
            if (kind == 1) {
                S20Color saved;
                S20Color *current;
                unsigned int flags;
                current = ((S20Color *(*)(char *))(*(void ***)base)[16])(base);
                saved.r = current->r;
                saved.b = current->b;
                saved.g = current->g;
                saved.a = current->a;
                flags = ((unsigned int (*)(char *))(*(void ***)base)[15])(base);
                ((void (*)(char *, unsigned int))(*(void ***)base)[14])(base, flags | 8);
                ((void (*)(char *, char *))(*(void ***)base)[17])(base, lbl_8045e62c);
                *(int *)(base + 84) = *(volatile int *)&kind;
                {
                    char *sub = base + 4;
                    unsigned short slot = *(unsigned short *)(target + 6);
                    ((S20HandlerT)(*(void ***)(sub + 24))[slot])(sub, target);
                }
                ((void (*)(char *, S20Color *))(*(void ***)base)[17])(base, &saved);
                *(int *)(base + 84) = 0;
                ((void (*)(char *, unsigned int))(*(void ***)base)[14])(base, flags);
            }
        }
    }
    return 0;
}
