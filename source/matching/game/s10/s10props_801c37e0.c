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

extern int lbl_804b04a8;
extern S10PropertyInfo lbl_8045d534;
extern char lbl_803ac8cc[];
extern char lbl_8045e2b4[];
void * fn_801f23bc(void *, S10PropertyInfo *);
extern int lbl_804b04ac;
extern S10PropertyInfo lbl_8045d548;
extern char lbl_803ac8dc[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S10PropertyInfo *);
extern int lbl_804b04b0;
extern S10PropertyInfo lbl_8045d55c;
extern char lbl_803ac8e8[];
extern char lbl_8045e004[];
extern char lbl_803fe594[];
void * fn_801eff8c(void *, S10PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801c37e0(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b04a8) {
        S10PropertyInfo *target = &lbl_8045d534;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac8cc;
        info.size = 20;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b04a8 = 1;
    }
    fn_801f23bc(object, &lbl_8045d534);
    if (!lbl_804b04ac) {
        S10PropertyInfo *target = &lbl_8045d548;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac8dc;
        info.size = 28;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b04ac = 1;
    }
    fn_801efec4(object, &lbl_8045d548);
    if (!lbl_804b04b0) {
        S10PropertyInfo *target = &lbl_8045d55c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac8e8;
        info.size = 24;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe594;
        *target = info;
        lbl_804b04b0 = 1;
    }
    fn_801eff8c(object, &lbl_8045d55c);
    fn_801e8d9c(object);
    return 0;
}
