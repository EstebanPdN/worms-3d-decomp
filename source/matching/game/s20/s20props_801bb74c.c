/* Literal fields and addresses derived from the original registration blocks. */
typedef struct S20PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S20PropertyInfo;
void *memset();

extern char lbl_803ab678[];
void * fn_801ebbb8(void *, char *);
extern int lbl_804b03e0;
extern S20PropertyInfo lbl_8045d14c;
extern char lbl_803ab6a0[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S20PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801bb74c(void *object)
{
    S20PropertyInfo info;
    fn_801ebbb8(object, lbl_803ab678);
    if (!lbl_804b03e0) {
        S20PropertyInfo *target = &lbl_8045d14c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab6a0;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b03e0 = 1;
    }
    fn_801efec4(object, &lbl_8045d14c);
    fn_801e8d9c(object);
    return 0;
}
