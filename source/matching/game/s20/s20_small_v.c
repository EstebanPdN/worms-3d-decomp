/* Slot release loops, pending flush, name lookups and a pooled destructor. */
typedef struct S20Object { void **vtable; } S20Object;

extern void fn_80209920(void *, int);
extern void fn_80167018(char *);
extern int lbl_804b00dc;

void w3d_s20_flush_pending_80167094(char *self) {
    unsigned int i = 0;
    if (i < *(unsigned int *)(self + 5256)) {
        int *slot = (int *)(self + 1160);
        do {
            int value = *slot;
            i++;
            slot++;
            fn_80209920(&lbl_804b00dc, value);
        } while (i < *(unsigned int *)(self + 5256));
    }
    if (*(int *)(self + 5256) != 0)
        fn_80167018(self);
    *(int *)(self + 5256) = 0;
}

extern void fn_800e77dc(char *);
extern void fn_8015a39c(char *, int);
extern int lbl_804b0044;
extern char lbl_80410138[];

void w3d_s20_destroy_pooled_800e7344(char *self, int flags) {
    *(char **)(self + 72) = lbl_80410138;
    fn_800e77dc(self);
    if (*(S20Object **)(self + 84) != 0)
        ((void (*)(S20Object *))(*(S20Object **)(self + 84))->vtable[4])(*(S20Object **)(self + 84));
    fn_8015a39c(self, 0);
    if (flags & 1)
        fn_80209920(&lbl_804b0044, (int)self);
}

extern int fn_800e5cf0(int, char *, char *, int, int);
extern char lbl_8039fc00[];
extern char lbl_8039fc08[];
extern char lbl_8039fc1c[];
extern char lbl_8039fc24[];

void w3d_s20_bind_names_8013e35c(char *self) {
    if (*(int *)(self + 168) != 0) {
        *(int *)(self + 560) = fn_800e5cf0(*(int *)(self + 168), lbl_8039fc00, lbl_8039fc08, -1, 0);
        *(int *)(self + 564) = fn_800e5cf0(*(int *)(self + 168), lbl_8039fc1c, lbl_8039fc24, -1, 0);
    }
}
