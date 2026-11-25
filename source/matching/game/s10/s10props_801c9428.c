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

extern int lbl_804b04d8;
extern S10PropertyInfo lbl_8045d624;
extern char lbl_803ad844[];
extern char lbl_8045e004[];
extern char lbl_803fe624[];
void * fn_801eff8c(void *, S10PropertyInfo *);
extern int lbl_804b04dc;
extern S10PropertyInfo lbl_8045d638;
extern char lbl_803ad854[];
extern char lbl_803fe630[];
void fn_801e8d9c(void *);
int w3d_s10_register_properties_801c9428(void *object)
{
    S10PropertyInfo info;
    if (!lbl_804b04d8) {
        S10PropertyInfo *target = &lbl_8045d624;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad844;
        info.size = 32;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe624;
        *target = info;
        lbl_804b04d8 = 1;
    }
    fn_801eff8c(object, &lbl_8045d624);
    if (!lbl_804b04dc) {
        S10PropertyInfo *target = &lbl_8045d638;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad854;
        info.size = 28;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe630;
        *target = info;
        lbl_804b04dc = 1;
    }
    fn_801eff8c(object, &lbl_8045d638);
    fn_801e8d9c(object);
    return 0;
}
