/* Interface and range layouts are inferred from the original instructions. */
typedef struct Interface { void **vtable; } Interface;
typedef struct Range { char *begin; char *end; } Range;
extern void *lbl_8040ddf8[];
extern Interface *lbl_804aca48;
extern Range lbl_804200a4[];
extern int lbl_804aa7d4;
extern void fn_801628ec(void *, int);
void tterra_a28_cleanup_80022c6c(void **self, int flags) {
    char *p;
    *self = lbl_8040ddf8;
    if (lbl_804aca48) {
        Interface *obj = lbl_804aca48;
        ((void (*)(Interface *))obj->vtable[4])(obj);
    }
    lbl_804aca48 = 0;
    for (p = lbl_804200a4->begin; p != lbl_804200a4->end; p += 4) { }
    lbl_804aa7d4 = 0;
    fn_801628ec(self, flags);
}
