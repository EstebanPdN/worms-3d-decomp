/* Message posting helpers. */
typedef struct S20Msg { short id; short pad; void *table; } S20Msg;
extern S20Msg *fn_801613f0(void *, int);
extern short fn_8015f5a0(void *, int);
extern unsigned int fn_8015fc58(char *, S20Msg *);
extern void fn_8015884c(char *);
extern void *lbl_804b1754;
extern char lbl_804afe70;
extern char lbl_8040db38[];

void w3d_s20_reset_with_message_80156190(char *self) {
    S20Msg *message = fn_801613f0(lbl_804b1754, 8);
    int *slot;
    int zero;
    int i;
    {
        short id = fn_8015f5a0(&lbl_804afe70, 1);
        message->id = id;
        message->table = lbl_8040db38;
    }
    fn_8015fc58(self, message);
    fn_8015884c(self);
    zero = 0;
    slot = (int *)(self + 312);
    for (i = 16; i != zero; i--) {
        *slot = -1;
        slot++;
    }
}
