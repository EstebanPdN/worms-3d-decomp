/* Deleting destructor of a listed object that frees four buffers. */
extern void fn_80210990(char *, int);
extern void fn_801fe1f8(char *);
extern void fn_802134fc(void *);
extern char *lbl_804ab750;
extern char lbl_80413a00[];
extern char lbl_80411ac0[];

void w3d_s20_destroy_listed_801a2668(char *self, int flags) {
    char *current = lbl_804ab750;
    char *previous;
    void *buffer;
    *(char **)self = lbl_80413a00;
    previous = 0;
    while (current != 0 && current != self) {
        previous = current;
        current = *(char **)(previous + 32);
    }
    if (previous == 0)
        lbl_804ab750 = *(char **)(self + 32);
    else
        *(char **)(previous + 32) = *(char **)(self + 32);
    buffer = *(void **)(self + 72);
    *(int *)(self + 32) = 0;
    *(int *)(self + 20) = 0;
    if (buffer != 0)
        fn_802134fc(buffer);
    if (*(void **)(self + 60) != 0)
        fn_802134fc(*(void **)(self + 60));
    if (*(void **)(self + 48) != 0)
        fn_802134fc(*(void **)(self + 48));
    if (*(void **)(self + 36) != 0)
        fn_802134fc(*(void **)(self + 36));
    *(char **)self = lbl_80411ac0;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}
