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

extern int lbl_804b0448;
extern S20PropertyInfo lbl_8045d354;
extern char lbl_803ac3ec[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, S20PropertyInfo *);
extern int lbl_804b044c;
extern S20PropertyInfo lbl_8045d368;
extern char lbl_803ab160[];
extern char lbl_8045e2b4[];
void * fn_801f23bc(void *, S20PropertyInfo *);
extern int lbl_804b0450;
extern S20PropertyInfo lbl_8045d37c;
extern char lbl_803ab108[];
extern char lbl_8045ed7c[];
void * fn_801efec4(void *, S20PropertyInfo *);
extern int lbl_804b0454;
extern S20PropertyInfo lbl_8045d390;
extern char lbl_803ac3f8[];
extern char lbl_8045e47c[];
void * fn_801f25b0(void *, S20PropertyInfo *);
extern int lbl_804b0458;
extern S20PropertyInfo lbl_8045d3a4;
extern char lbl_803ab0f8[];
extern char lbl_8045e23c[];
void * fn_801f2100(void *, S20PropertyInfo *);
extern int lbl_804b045c;
extern S20PropertyInfo lbl_8045d3b8;
extern char lbl_803abf88[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S20PropertyInfo *);
extern char lbl_803ac65c[];
void * fn_801eb834(void *, char *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801c1a6c(void *object)
{
    S20PropertyInfo info;
    if (!lbl_804b0448) {
        S20PropertyInfo *target = &lbl_8045d354;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3ec;
        info.size = 80;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0448 = 1;
    }
    fn_801efd98(object, &lbl_8045d354);
    if (!lbl_804b044c) {
        S20PropertyInfo *target = &lbl_8045d368;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab160;
        info.size = 64;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b044c = 1;
    }
    fn_801f23bc(object, &lbl_8045d368);
    if (!lbl_804b0450) {
        S20PropertyInfo *target = &lbl_8045d37c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab108;
        info.size = 76;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0450 = 1;
    }
    fn_801efec4(object, &lbl_8045d37c);
    if (!lbl_804b0454) {
        S20PropertyInfo *target = &lbl_8045d390;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3f8;
        info.size = 68;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e47c;
        *target = info;
        lbl_804b0454 = 1;
    }
    fn_801f25b0(object, &lbl_8045d390);
    if (!lbl_804b0458) {
        S20PropertyInfo *target = &lbl_8045d3a4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f8;
        info.size = 72;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e23c;
        *target = info;
        lbl_804b0458 = 1;
    }
    fn_801f2100(object, &lbl_8045d3a4);
    if (!lbl_804b045c) {
        S20PropertyInfo *target = &lbl_8045d3b8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abf88;
        info.size = 88;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b045c = 1;
    }
    fn_801efd34(object, &lbl_8045d3b8);
    fn_801eb834(object, lbl_803ac65c);
    fn_801e8d9c(object);
    return 0;
}
