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

extern char lbl_803a80fc[];
void * fn_801eb834(void *, char *);
extern int lbl_804b0284;
extern S20PropertyInfo lbl_804597bc;
extern char lbl_803a8124[];
extern char lbl_8045e004[];
extern char lbl_803fe470[];
void * fn_801eff8c(void *, S20PropertyInfo *);
extern int lbl_804b0288;
extern S20PropertyInfo lbl_804597d0;
extern char lbl_803a8134[];
extern char lbl_803fe47c[];
extern int lbl_804b028c;
extern S20PropertyInfo lbl_804597e4;
extern char lbl_803a8144[];
extern char lbl_803fe488[];
extern int lbl_804b0290;
extern S20PropertyInfo lbl_804597f8;
extern char lbl_803a8154[];
extern char lbl_803fe494[];
extern int lbl_804b0294;
extern S20PropertyInfo lbl_8045980c;
extern char lbl_803a8164[];
extern char lbl_803fe4a0[];
extern int lbl_804b0298;
extern S20PropertyInfo lbl_80459820;
extern char lbl_803a8174[];
extern char lbl_803fe4ac[];
extern int lbl_804b029c;
extern S20PropertyInfo lbl_80459834;
extern char lbl_803a8188[];
extern int lbl_804b02a0;
extern S20PropertyInfo lbl_80459848;
extern char lbl_803a81a0[];
extern char lbl_803fe4b8[];
void fn_801e8d9c(void *);
int w3d_s20_register_properties_8018f370(void *object)
{
    S20PropertyInfo info;
    fn_801eb834(object, lbl_803a80fc);
    if (!lbl_804b0284) {
        S20PropertyInfo *target = &lbl_804597bc;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8124;
        info.size = 48;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe470;
        *target = info;
        lbl_804b0284 = 1;
    }
    fn_801eff8c(object, &lbl_804597bc);
    if (!lbl_804b0288) {
        S20PropertyInfo *target = &lbl_804597d0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8134;
        info.size = 44;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe47c;
        *target = info;
        lbl_804b0288 = 1;
    }
    fn_801eff8c(object, &lbl_804597d0);
    if (!lbl_804b028c) {
        S20PropertyInfo *target = &lbl_804597e4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8144;
        info.size = 40;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe488;
        *target = info;
        lbl_804b028c = 1;
    }
    fn_801eff8c(object, &lbl_804597e4);
    if (!lbl_804b0290) {
        S20PropertyInfo *target = &lbl_804597f8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8154;
        info.size = 36;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe494;
        *target = info;
        lbl_804b0290 = 1;
    }
    fn_801eff8c(object, &lbl_804597f8);
    if (!lbl_804b0294) {
        S20PropertyInfo *target = &lbl_8045980c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8164;
        info.size = 32;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe4a0;
        *target = info;
        lbl_804b0294 = 1;
    }
    fn_801eff8c(object, &lbl_8045980c);
    if (!lbl_804b0298) {
        S20PropertyInfo *target = &lbl_80459820;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8174;
        info.size = 28;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe4ac;
        *target = info;
        lbl_804b0298 = 1;
    }
    fn_801eff8c(object, &lbl_80459820);
    if (!lbl_804b029c) {
        S20PropertyInfo *target = &lbl_80459834;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a8188;
        info.size = 24;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe4ac;
        *target = info;
        lbl_804b029c = 1;
    }
    fn_801eff8c(object, &lbl_80459834);
    if (!lbl_804b02a0) {
        S20PropertyInfo *target = &lbl_80459848;
        memset(&info, 0, sizeof info);
        info.name = lbl_803a81a0;
        info.size = 20;
        info.elementType = 8;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe4b8;
        *target = info;
        lbl_804b02a0 = 1;
    }
    fn_801eff8c(object, &lbl_80459848);
    fn_801e8d9c(object);
    return 0;
}
