/* Pool entry acquisition through a held reference. */
typedef struct S20Object { void **vtable; } S20Object;
extern char *fn_801ef048(char *, int, int, int);

int w3d_s20_store_byte_value_80173f88(char *self, int value) {
    S20Object *volatile held;
    if (*(unsigned char *)value != *(unsigned char *)(self + 132)) {
        S20Object *current;
        char *base;
        char *list;
        char *pool;
        char *entry;
        int count;
        *(unsigned char *)(self + 132) = *(unsigned char *)value;
        current = *(S20Object **)(*(char **)(self + 128) + 48);
        held = current;
        if (current != 0)
            ((void (*)(S20Object *))current->vtable[3])(current);
        base = (char *)held;
        pool = *(char **)(base + 100);
        list = base + 100;
        count = *(int *)(pool + 24);
        if (*(unsigned short *)(pool + 4) == 1) {
            *(unsigned short *)(pool + 28) += 1;
            entry = pool + 32;
        } else {
            entry = fn_801ef048(list, count, 1, 2);
        }
        entry[*(int *)(self + 124)] = *(unsigned char *)(self + 132);
        {
            S20Object *tail = held;
            if (tail != 0)
                ((void (*)(S20Object *))tail->vtable[4])(tail);
        }
    }
    return 0;
}
