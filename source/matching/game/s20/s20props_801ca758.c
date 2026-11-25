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

extern char lbl_803adca8[];
void * fn_801ecc6c(void *, char *);
extern int lbl_804b04f8;
extern S20PropertyInfo lbl_8045d6c4;
extern char lbl_803adccc[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S20PropertyInfo *);
extern int lbl_804b04fc;
extern S20PropertyInfo lbl_8045d6d8;
extern char lbl_803adc88[];
extern char lbl_8045e29c[];
void * fn_801f2420(void *, S20PropertyInfo *);
extern int lbl_804b0500;
extern S20PropertyInfo lbl_8045d6ec;
extern char lbl_803adc94[];
extern char lbl_8045e47c[];
void * fn_801f25b0(void *, S20PropertyInfo *);
extern int lbl_804b0504;
extern S20PropertyInfo lbl_8045d700;
extern char lbl_803adcdc[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S20PropertyInfo *);
extern int lbl_804b0508;
extern S20PropertyInfo lbl_8045d714;
extern char lbl_803adcec[];
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801ca758(void *object)
{
    S20PropertyInfo info;
    fn_801ecc6c(object, lbl_803adca8);
    if (!lbl_804b04f8) {
        S20PropertyInfo *target = &lbl_8045d6c4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adccc;
        info.size = 40;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b04f8 = 1;
    }
    fn_801efd98(object, &lbl_8045d6c4);
    if (!lbl_804b04fc) {
        S20PropertyInfo *target = &lbl_8045d6d8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adc88;
        info.size = 32;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e29c;
        *target = info;
        lbl_804b04fc = 1;
    }
    fn_801f2420(object, &lbl_8045d6d8);
    if (!lbl_804b0500) {
        S20PropertyInfo *target = &lbl_8045d6ec;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adc94;
        info.size = 28;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e47c;
        *target = info;
        lbl_804b0500 = 1;
    }
    fn_801f25b0(object, &lbl_8045d6ec);
    if (!lbl_804b0504) {
        S20PropertyInfo *target = &lbl_8045d700;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adcdc;
        info.size = 48;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0504 = 1;
    }
    fn_801efd34(object, &lbl_8045d700);
    if (!lbl_804b0508) {
        S20PropertyInfo *target = &lbl_8045d714;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adcec;
        info.size = 44;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0508 = 1;
    }
    fn_801efd34(object, &lbl_8045d714);
    fn_801e8d9c(object);
    return 0;
}
