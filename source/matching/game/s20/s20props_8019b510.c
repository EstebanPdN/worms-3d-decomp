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

extern char lbl_803a9578[];
void * fn_801eb674(void *, char *);
extern char lbl_803a95ac[];
extern char lbl_803a95e0[];
extern char lbl_803a9614[];
extern char lbl_803a9648[];
void * fn_801ece2c(void *, char *);
extern char lbl_803a9680[];
extern int lbl_804b02fc;
extern S20PropertyInfo lbl_8045cd20;
extern char lbl_803a96a8[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S20PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_8019b510(void *object)
{
    S20PropertyInfo info;
    fn_801eb674(object, lbl_803a9578);
    fn_801eb674(object, lbl_803a95ac);
    fn_801eb674(object, lbl_803a95e0);
    fn_801eb674(object, lbl_803a9614);
    fn_801ece2c(object, lbl_803a9648);
    fn_801ece2c(object, lbl_803a9680);
    if (!lbl_804b02fc) {
        S20PropertyInfo *target = &lbl_8045cd20;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a96a8;
        info.size = 20;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b02fc = 1;
    }
    fn_801efec4(object, &lbl_8045cd20);
    fn_801e8d9c(object);
    return 0;
}
