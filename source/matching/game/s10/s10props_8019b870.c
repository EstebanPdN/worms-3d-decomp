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

extern int lbl_804b0300;
extern S10PropertyInfo lbl_8045cd34;
extern char lbl_803a96b4[];
extern char lbl_8045ed94[];
void * fn_801efff0(void *, S10PropertyInfo *);
extern int lbl_804b0304;
extern S10PropertyInfo lbl_8045cd48;
extern char lbl_803a96c0[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S10PropertyInfo *);
extern int lbl_804b0308;
extern S10PropertyInfo lbl_8045cd5c;
extern char lbl_803a96c8[];
extern int lbl_804b030c;
extern S10PropertyInfo lbl_8045cd70;
extern char lbl_803a96d4[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S10PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s10_register_properties_8019b870(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b0300) {
        S10PropertyInfo *target = &lbl_8045cd34;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a96b4;
        info.size = 20;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b0300 = 1;
    }
    fn_801efff0(object, &lbl_8045cd34);
    if (!lbl_804b0304) {
        S10PropertyInfo *target = &lbl_8045cd48;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a96c0;
        info.size = 32;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0304 = 1;
    }
    fn_801efd34(object, &lbl_8045cd48);
    if (!lbl_804b0308) {
        S10PropertyInfo *target = &lbl_8045cd5c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a96c8;
        info.size = 28;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0308 = 1;
    }
    fn_801efd34(object, &lbl_8045cd5c);
    if (!lbl_804b030c) {
        S10PropertyInfo *target = &lbl_8045cd70;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a96d4;
        info.size = 24;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b030c = 1;
    }
    fn_801efd98(object, &lbl_8045cd70);
    fn_801e8d9c(object);
    return 0;
}
