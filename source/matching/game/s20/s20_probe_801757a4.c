/* Deleting destructor of an object owning buffers and an array of released objects. */
typedef struct S20Object { void **vtable; } S20Object;
extern void fn_80210990(char *, int);
extern void fn_801fe1f8(char *);
extern void fn_801fe240(void *);
extern void fn_802134fc(void *);
extern void fn_801758e8(char *);
extern int lbl_804ab5c4;
extern char lbl_80412250[];
extern char lbl_80412318[];

void w3d_s20_destroy_pool_801757a4(char *self, int flags) {
    char *header;
    void *buffer;
    char *array;
    char *raw;
    *(char **)self = lbl_80412250;
    fn_801758e8(self);
    buffer = *(void **)(self + 2096);
    lbl_804ab5c4 = 0;
    if (buffer != 0)
        fn_801fe240(buffer);
    raw = *(char **)(self + 24);
    header = self + 4;
    array = raw;
    if (raw != 0) {
        S20Object **end = (S20Object **)(array + *(int *)(array - 8) * 4);
        if ((char *)array != (char *)end) {
            do {
                S20Object *element;
                end--;
                element = *end;
                if (element != 0)
                    ((void (*)(S20Object *))element->vtable[4])(element);
                raw = *(char **)(self + 24);
                array = raw;
            } while ((char *)array != (char *)end);
        }
        fn_801fe240(array - 8);
    }
    if (*(void **)(self + 2104) != 0)
        fn_802134fc(*(void **)(self + 2104));
    if (*(void **)(self + 28) != 0)
        fn_802134fc(*(void **)(self + 28));
    *(char **)self = lbl_80412318;
    fn_80210990(header, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}
