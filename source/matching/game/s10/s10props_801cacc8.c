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

extern int lbl_804b050c;
extern S10PropertyInfo lbl_8045d728;
extern char lbl_803ad854[];
extern char lbl_8045e004[];
extern char lbl_803fe630[];
void * fn_801eff8c(void *, S10PropertyInfo *);
extern int lbl_804b0510;
extern S10PropertyInfo lbl_8045d73c;
extern char lbl_803add0c[];
extern char lbl_803fe654[];
extern int lbl_804b0514;
extern S10PropertyInfo lbl_8045d750;
extern char lbl_803add18[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S10PropertyInfo *);
extern int lbl_804b0518;
extern S10PropertyInfo lbl_8045d764;
extern char lbl_803adccc[];
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801cacc8(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b050c) {
        S10PropertyInfo *target = &lbl_8045d728;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad854;
        info.size = 32;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe630;
        *target = info;
        lbl_804b050c = 1;
    }
    fn_801eff8c(object, &lbl_8045d728);
    if (!lbl_804b0510) {
        S10PropertyInfo *target = &lbl_8045d73c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803add0c;
        info.size = 28;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe654;
        *target = info;
        lbl_804b0510 = 1;
    }
    fn_801eff8c(object, &lbl_8045d73c);
    if (!lbl_804b0514) {
        S10PropertyInfo *target = &lbl_8045d750;
        memset(&info, 0, sizeof info);
        info.name = lbl_803add18;
        info.size = 40;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0514 = 1;
    }
    fn_801efd98(object, &lbl_8045d750);
    if (!lbl_804b0518) {
        S10PropertyInfo *target = &lbl_8045d764;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adccc;
        info.size = 36;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0518 = 1;
    }
    fn_801efd98(object, &lbl_8045d764);
    fn_801e8d9c(object);
    return 0;
}
