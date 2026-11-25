#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern void *FUN_801613f0(void *, int);
extern void *w3d_auto_8003a264(void *, int, int);
extern int w3d_message_post_current(void *);
extern void *lbl_804b1754;
extern int lbl_804b17a0;

int s19_post_message_8003ef88(void *self)
{
    w3d_message_post_current(w3d_auto_8003a264(FUN_801613f0(lbl_804b1754, 12), FIELD(self, int, 76), FIELD(self, int, 80)));
    return lbl_804b17a0 == 0;
}
