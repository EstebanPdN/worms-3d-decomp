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

extern int lbl_804b0400;
extern S10PropertyInfo lbl_8045d1ec;
extern char lbl_803abe00[];
extern char lbl_8045e584[];
void * fn_801f2614(void *, S10PropertyInfo *);
extern int lbl_804b0404;
extern S10PropertyInfo lbl_8045d200;
extern char lbl_803abe10[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S10PropertyInfo *);
extern int lbl_804b0408;
extern S10PropertyInfo lbl_8045d214;
extern char lbl_803abe24[];
extern char lbl_8045ed94[];
void * fn_801efff0(void *, S10PropertyInfo *);
extern int lbl_804b040c;
extern S10PropertyInfo lbl_8045d228;
extern char lbl_803abe30[];
extern int lbl_804b0410;
extern S10PropertyInfo lbl_8045d23c;
extern char lbl_803abe40[];
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801bec54(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b0400) {
        S10PropertyInfo *target = &lbl_8045d1ec;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abe00;
        info.size = 52;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e584;
        *target = info;
        lbl_804b0400 = 1;
    }
    fn_801f2614(object, &lbl_8045d1ec);
    if (!lbl_804b0404) {
        S10PropertyInfo *target = &lbl_8045d200;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abe10;
        info.size = 60;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0404 = 1;
    }
    fn_801efd34(object, &lbl_8045d200);
    if (!lbl_804b0408) {
        S10PropertyInfo *target = &lbl_8045d214;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abe24;
        info.size = 56;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b0408 = 1;
    }
    fn_801efff0(object, &lbl_8045d214);
    if (!lbl_804b040c) {
        S10PropertyInfo *target = &lbl_8045d228;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abe30;
        info.size = 48;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e584;
        *target = info;
        lbl_804b040c = 1;
    }
    fn_801f2614(object, &lbl_8045d228);
    if (!lbl_804b0410) {
        S10PropertyInfo *target = &lbl_8045d23c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abe40;
        info.size = 44;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045e584;
        *target = info;
        lbl_804b0410 = 1;
    }
    fn_801f2614(object, &lbl_8045d23c);
    fn_801e8d9c(object);
    return 0;
}
