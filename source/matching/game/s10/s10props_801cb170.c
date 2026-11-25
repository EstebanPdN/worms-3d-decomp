/* Literal fields and addresses derived from the original registration blocks. */
typedef struct S10PropertyInfo {
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} S10PropertyInfo;
void *memset();

extern int lbl_804b051c;
extern S10PropertyInfo lbl_8045d778;
extern char lbl_803add34[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S10PropertyInfo *);
extern int lbl_804b0520;
extern S10PropertyInfo lbl_8045d78c;
extern char lbl_803add40[];
extern char lbl_8045ed4c[];
void * fn_801efdfc(void *, S10PropertyInfo *);
extern int lbl_804b0524;
extern S10PropertyInfo lbl_8045d7a0;
extern char lbl_803add50[];
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801cb170(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b051c) {
        S10PropertyInfo *target = &lbl_8045d778;
        memset(&info, 0, sizeof info);
        info.name = lbl_803add34;
        info.size = 28;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b051c = 1;
    }
    fn_801efd98(object, &lbl_8045d778);
    if (!lbl_804b0520) {
        S10PropertyInfo *target = &lbl_8045d78c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803add40;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b0520 = 1;
    }
    fn_801efdfc(object, &lbl_8045d78c);
    if (!lbl_804b0524) {
        S10PropertyInfo *target = &lbl_8045d7a0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803add50;
        info.size = 24;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0524 = 1;
    }
    fn_801efd98(object, &lbl_8045d7a0);
    fn_801e8d9c(object);
    return 0;
}
