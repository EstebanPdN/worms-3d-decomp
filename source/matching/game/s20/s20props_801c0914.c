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

extern int lbl_804b0418;
extern S20PropertyInfo lbl_8045d264;
extern char lbl_803ac3ec[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S20PropertyInfo *);
extern int lbl_804b041c;
extern S20PropertyInfo lbl_8045d278;
extern char lbl_803ab160[];
extern char lbl_8045e2b4[];
void * fn_801f23bc(void *, S20PropertyInfo *);
extern int lbl_804b0420;
extern S20PropertyInfo lbl_8045d28c;
extern char lbl_803ab108[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S20PropertyInfo *);
extern int lbl_804b0424;
extern S20PropertyInfo lbl_8045d2a0;
extern char lbl_803ac3f8[];
extern char lbl_8045e47c[];
void * fn_801f25b0(void *, S20PropertyInfo *);
extern int lbl_804b0428;
extern S20PropertyInfo lbl_8045d2b4;
extern char lbl_803ab0f8[];
extern char lbl_8045e23c[];
void * fn_801f2100(void *, S20PropertyInfo *);
extern int lbl_804b042c;
extern S20PropertyInfo lbl_8045d2c8;
extern char lbl_803abf88[];
extern char lbl_803ac410[];
void * fn_801ebf38(void *, char *);
extern char lbl_803ac438[];
extern char lbl_803ac478[];
extern char lbl_803ac4ac[];
void * fn_801eb834(void *, char *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801c0914(void *object)
{
    S20PropertyInfo info;
    if (!lbl_804b0418) {
        S20PropertyInfo *target = &lbl_8045d264;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3ec;
        info.size = 100;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0418 = 1;
    }
    fn_801efd34(object, &lbl_8045d264);
    if (!lbl_804b041c) {
        S20PropertyInfo *target = &lbl_8045d278;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab160;
        info.size = 64;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b041c = 1;
    }
    fn_801f23bc(object, &lbl_8045d278);
    if (!lbl_804b0420) {
        S20PropertyInfo *target = &lbl_8045d28c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab108;
        info.size = 88;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0420 = 1;
    }
    fn_801efec4(object, &lbl_8045d28c);
    if (!lbl_804b0424) {
        S20PropertyInfo *target = &lbl_8045d2a0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3f8;
        info.size = 68;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e47c;
        *target = info;
        lbl_804b0424 = 1;
    }
    fn_801f25b0(object, &lbl_8045d2a0);
    if (!lbl_804b0428) {
        S20PropertyInfo *target = &lbl_8045d2b4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f8;
        info.size = 84;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e23c;
        *target = info;
        lbl_804b0428 = 1;
    }
    fn_801f2100(object, &lbl_8045d2b4);
    if (!lbl_804b042c) {
        S20PropertyInfo *target = &lbl_8045d2c8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abf88;
        info.size = 96;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b042c = 1;
    }
    fn_801efd34(object, &lbl_8045d2c8);
    fn_801ebf38(object, lbl_803ac410);
    fn_801ebf38(object, lbl_803ac438);
    fn_801ebf38(object, lbl_803ac478);
    fn_801eb834(object, lbl_803ac4ac);
    fn_801e8d9c(object);
    return 0;
}
