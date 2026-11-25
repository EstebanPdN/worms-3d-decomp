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

extern int lbl_804b04c0;
extern S10PropertyInfo lbl_8045d5ac;
extern char lbl_803aca2c[];
extern char lbl_8045ed94[];
void * fn_801efff0(void *, S10PropertyInfo *);
extern int lbl_804b04c4;
extern S10PropertyInfo lbl_8045d5c0;
extern char lbl_803aca34[];
extern char lbl_8045ed4c[];
void * fn_801efdfc(void *, S10PropertyInfo *);
extern int lbl_804b04c8;
extern S10PropertyInfo lbl_8045d5d4;
extern char lbl_803aca3c[];
extern char lbl_8045e2b4[];
void * fn_801f23bc(void *, S10PropertyInfo *);
extern int lbl_804b04cc;
extern S10PropertyInfo lbl_8045d5e8;
extern char lbl_803aca40[];
extern char lbl_8045e494[];
void * fn_801f254c(void *, S10PropertyInfo *);
extern int lbl_804b04d0;
extern S10PropertyInfo lbl_8045d5fc;
extern char lbl_803aca44[];
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801c4450(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b04c0) {
        S10PropertyInfo *target = &lbl_8045d5ac;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca2c;
        info.size = 36;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b04c0 = 1;
    }
    fn_801efff0(object, &lbl_8045d5ac);
    if (!lbl_804b04c4) {
        S10PropertyInfo *target = &lbl_8045d5c0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca34;
        info.size = 32;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b04c4 = 1;
    }
    fn_801efdfc(object, &lbl_8045d5c0);
    if (!lbl_804b04c8) {
        S10PropertyInfo *target = &lbl_8045d5d4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca3c;
        info.size = 24;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b04c8 = 1;
    }
    fn_801f23bc(object, &lbl_8045d5d4);
    if (!lbl_804b04cc) {
        S10PropertyInfo *target = &lbl_8045d5e8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca40;
        info.size = 20;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e494;
        *target = info;
        lbl_804b04cc = 1;
    }
    fn_801f254c(object, &lbl_8045d5e8);
    if (!lbl_804b04d0) {
        S10PropertyInfo *target = &lbl_8045d5fc;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca44;
        info.size = 28;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b04d0 = 1;
    }
    fn_801efdfc(object, &lbl_8045d5fc);
    fn_801e8d9c(object);
    return 0;
}
