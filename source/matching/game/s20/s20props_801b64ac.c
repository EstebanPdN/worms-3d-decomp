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

extern char lbl_803ab128[];
void * fn_801ecc6c(void *, char *);
extern int lbl_804b0378;
extern S20PropertyInfo lbl_8045cf44;
extern char lbl_803ab14c[];
extern char lbl_8045ed94[];
void * fn_801efff0(void *, S20PropertyInfo *);
extern int lbl_804b037c;
extern S20PropertyInfo lbl_8045cf58;
extern char lbl_803ab0f8[];
extern char lbl_8045e1dc[];
void * fn_801f2164(void *, S20PropertyInfo *);
extern int lbl_804b0380;
extern S20PropertyInfo lbl_8045cf6c;
extern char lbl_803ab154[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S20PropertyInfo *);
extern int lbl_804b0384;
extern S20PropertyInfo lbl_8045cf80;
extern char lbl_803ab160[];
extern char lbl_8045e29c[];
void * fn_801f2420(void *, S20PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801b64ac(void *object)
{
    S20PropertyInfo info;
    fn_801ecc6c(object, lbl_803ab128);
    if (!lbl_804b0378) {
        S20PropertyInfo *target = &lbl_8045cf44;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab14c;
        info.size = 72;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b0378 = 1;
    }
    fn_801efff0(object, &lbl_8045cf44);
    if (!lbl_804b037c) {
        S20PropertyInfo *target = &lbl_8045cf58;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f8;
        info.size = 64;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e1dc;
        *target = info;
        lbl_804b037c = 1;
    }
    fn_801f2164(object, &lbl_8045cf58);
    if (!lbl_804b0380) {
        S20PropertyInfo *target = &lbl_8045cf6c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab154;
        info.size = 80;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0380 = 1;
    }
    fn_801efd98(object, &lbl_8045cf6c);
    if (!lbl_804b0384) {
        S20PropertyInfo *target = &lbl_8045cf80;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab160;
        info.size = 68;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e29c;
        *target = info;
        lbl_804b0384 = 1;
    }
    fn_801f2420(object, &lbl_8045cf80);
    fn_801e8d9c(object);
    return 0;
}
