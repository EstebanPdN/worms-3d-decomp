/* Message creation, counted unregistration and small constructors. */
typedef struct S20Msg { short id; short pad; void *table; } S20Msg;
extern S20Msg *fn_801613f0(void *, int);
extern void *lbl_804b1754;
extern char lbl_8040db38[];

S20Msg *w3d_s20_make_message_800fb9e0(unsigned short *self) {
    S20Msg *message = fn_801613f0(lbl_804b1754, 8);
    unsigned short id = *self;
    message->table = lbl_8040db38;
    message->id = id;
    return message;
}

extern void fn_801656bc(char *);
extern void fn_8017b8f4(char *);
extern void fn_8020fd2c(char *, char *);
typedef struct S20List { char pad[34]; unsigned short count; } S20List;
extern S20List lbl_804552b0;
extern S20List lbl_80457014;

void w3d_s20_unregister_801655b0(char *self) {
    fn_801656bc(self);
    fn_8020fd2c((char *)&lbl_804552b0, self + 4);
    lbl_804552b0.count -= 1;
}

void w3d_s20_unregister_8017b7e8(char *self) {
    fn_8017b8f4(self);
    fn_8020fd2c((char *)&lbl_80457014, self + 4);
    lbl_80457014.count -= 1;
}

extern void fn_80308be8(int);
extern int lbl_803a54f4[];

int w3d_s20_select_entry_8016a570(char *self, char *item) {
    int index = *(int *)(item + 24);
    if (index == 0)
        fn_80308be8(0);
    else
        fn_80308be8(lbl_803a54f4[index]);
    return 0;
}

typedef struct S20FlagRec { char pad[20]; unsigned int low : 16; unsigned int flag : 1; unsigned int rest : 15; } S20FlagRec;
extern S20FlagRec *fn_8019a2a8(char *, int);

int w3d_s20_set_record_flag_80199fa4(char *self, int key, int value) {
    S20FlagRec *record = fn_8019a2a8(self, key);
    if (record == 0)
        return 0;
    record->flag = value;
    return 1;
}

typedef struct S20Pair2 { int a; int b; } S20Pair2;
extern int fn_801b529c(char *, void *);
extern char lbl_80415320[];

char *w3d_s20_construct_pair_801bc394(char *self, void * arg_r4) {
    fn_801b529c(self, arg_r4);
    *(long long *)(self + 24) = 0;
    *(char **)self = lbl_80415320;
    return self;
}
