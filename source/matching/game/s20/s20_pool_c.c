/* Pool entry acquisition through a held reference, then a typed store. */
typedef struct S20Object { void **vtable; } S20Object;
extern char *fn_801ef048(char *, int, int, int);

int w3d_s20_store_flag_byte_80173d38(char *self) {
    S20Object *volatile held;
    S20Object *current = *(S20Object **)(*(char **)(self + 128) + 48);
    char *base;
    char *list;
    char *pool;
    char *entry;
    int count;
    held = current;
    if (current != 0)
        ((void (*)(S20Object *))current->vtable[3])(current);
    base = (char *)held;
    pool = *(char **)(base + 96);
    list = base + 96;
    count = *(int *)(pool + 24);
    if (*(unsigned short *)(pool + 4) == 1) {
        *(unsigned short *)(pool + 28) += 1;
        entry = pool + 32;
    } else {
        entry = fn_801ef048(list, count, 1, 2);
    }
    {
        unsigned int flags = *(unsigned int *)(self + 8);
        int index = *(int *)(self + 124);
        entry[index] = flags & 1;
    }
    {
        S20Object *tail = held;
        if (tail != 0)
            ((void (*)(S20Object *))tail->vtable[4])(tail);
    }
    return 0;
}
