/* Method on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Slot48 { void **vtable; char pad[44]; S20Object *child; } S20Slot48;
typedef void (*S20HandlerU)(char *, char *);
extern int fn_801ad590(char *, char *);
extern void fn_801ace68(char *, char *);
extern void fn_801ad060(char *);

int w3d_s20_commit_target_801ad644(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *target = *(char **)(item + 48);
    if (target != 0) {
        char *sub = base + 4;
        int zero = 0;
        int result;
        S20Slot48 *volatile held;
        *(int *)(base + 92) = zero;
        *(char **)(sub + 20) = item;
        fn_801ace68(base, item);
        result = ((int (*)(char *, char *))(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
        fn_801ad060(base);
        {
            S20Slot48 *current = *(S20Slot48 **)(base + 96);
            held = current;
            if (current != 0)
                ((void (*)(S20Slot48 *))current->vtable[3])(current);
        }
        if (*(int *)(base + 92) != 0) {
            S20Object *old;
            S20Slot48 *slot = held;
            if (slot != 0) {
                old = slot->child;
                slot->child = (S20Object *)zero;
            } else {
                old = *(S20Object **)(item + 48);
                *(S20Object **)(item + 48) = (S20Object *)slot;
            }
            if (old != 0)
                ((void (*)(S20Object *))old->vtable[4])(old);
            *(int *)(base + 92) = 0;
        }
        {
            S20Slot48 *tail = held;
            if (tail != 0)
                ((void (*)(S20Slot48 *))tail->vtable[4])(tail);
        }
        return result;
    }
    return fn_801ad590(base ? base + 4 : 0, item);
}
