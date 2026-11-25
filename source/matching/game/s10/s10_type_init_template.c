typedef void (*S10TypeMethod)(void);
typedef struct S10TypeInfo {
    void *unknown;
    const char *name;
    S10TypeMethod create;
    S10TypeMethod destroy;
    int size;
    void *parent;
} S10TypeInfo;
extern S10TypeInfo lbl_8045cdfc;
extern char lbl_803a9b68[], lbl_8045cea4[];
extern void fn_801a118c(void), fn_801a1220(void);
extern void fn_80200af8(S10TypeInfo *);
void w3d_s10_initialize_type_801a17e4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        S10TypeInfo *type = &lbl_8045cdfc;
        type->name = lbl_803a9b68;
        type->create = fn_801a118c;
        type->destroy = fn_801a1220;
        type->size = 32;
        type->parent = lbl_8045cea4;
        fn_80200af8(type);
    }
}
