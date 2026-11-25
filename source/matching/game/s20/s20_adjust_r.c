/* Method on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Holder96 { char pad[96]; S20Object *current; } S20Holder96;
typedef void (*S20HandlerS)(char *, char *);
extern char *fn_801ad108(char *, char *);

int w3d_s20_replace_current_801adc14(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *target = *(char **)(item + 80);
    if (target != 0) {
        S20Object *saved;
        char *sub;
        char *other;
        S20Object *previous;
        S20Object *kept;
        if (((S20Holder96 *)base)->current != 0)
            ((void (*)(S20Object *))((S20Holder96 *)base)->current->vtable[4])(((S20Holder96 *)base)->current);
        *(int *)(base + 96) = 0;
        sub = base + 4;
        ((S20HandlerS)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        saved = ((S20Holder96 *)base)->current;
        if (saved != 0) {
            other = fn_801ad108(base, item);
            previous = *(S20Object **)(other + 80);
            *(S20Object **)(other + 80) = saved;
            ((void (*)(S20Object *))saved->vtable[3])(saved);
            if (previous != 0)
                ((void (*)(S20Object *))previous->vtable[4])(previous);
            kept = (S20Object *)other;
            if (kept != 0)
                ((void (*)(S20Object *))kept->vtable[3])(kept);
            if (((S20Holder96 *)base)->current != 0)
                ((void (*)(S20Object *))((S20Holder96 *)base)->current->vtable[4])(((S20Holder96 *)base)->current);
            *(S20Object **)(base + 96) = kept;
        }
    }
    return 0;
}
