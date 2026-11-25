#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void *FUN_801613f0(void *, int);
extern void *w3d_auto_8003a264(void *, int, int);
extern int w3d_message_post_current(void *);
extern void *lbl_804b1754;
extern int lbl_804b17a0;

void s19_post_selected_800de7f0(void *self)
{
    int flag;
    if (FIELD(self, int, 176) != -1) {
        w3d_message_post_current(w3d_auto_8003a264(FUN_801613f0(lbl_804b1754, 12), FIELD(self, int, 176), FIELD(self, int, 180)));
        flag = lbl_804b17a0;
        if (flag == 0)
            FIELD(self, char, 104) = flag;
    }
}
