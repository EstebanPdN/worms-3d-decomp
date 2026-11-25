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

extern char lbl_803ac824[];
void * fn_801ec52c(void *, char *);
extern char lbl_803ac858[];
extern char lbl_803ac888[];
extern int lbl_804b04a0;
extern S20PropertyInfo lbl_8045d50c;
extern char lbl_803ab6bc[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S20PropertyInfo *);
extern int lbl_804b04a4;
extern S20PropertyInfo lbl_8045d520;
extern char lbl_803ac8b0[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S20PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801c3454(void *object)
{
    S20PropertyInfo info;
    fn_801ec52c(object, lbl_803ac824);
    fn_801ec52c(object, lbl_803ac858);
    fn_801ec52c(object, lbl_803ac888);
    if (!lbl_804b04a0) {
        S20PropertyInfo *target = &lbl_8045d50c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab6bc;
        info.size = 60;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b04a0 = 1;
    }
    fn_801efd98(object, &lbl_8045d50c);
    if (!lbl_804b04a4) {
        S20PropertyInfo *target = &lbl_8045d520;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac8b0;
        info.size = 44;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b04a4 = 1;
    }
    fn_801efec4(object, &lbl_8045d520);
    fn_801e8d9c(object);
    return 0;
}
