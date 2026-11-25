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

extern char lbl_803ae960[];
void * fn_801ebf38(void *, char *);
extern char lbl_803ae994[];
void * fn_801eb834(void *, char *);
extern char lbl_803ae9bc[];
extern char lbl_803ae9e4[];
void * fn_801ece2c(void *, char *);
extern int lbl_804b0534;
extern S20PropertyInfo lbl_8045d7f0;
extern char lbl_803ae8e4[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, S20PropertyInfo *);
void fn_801e8d9c(void *);
int w3d_s20_register_properties_801cde2c(void *object)
{
    S20PropertyInfo info;
    fn_801ebf38(object, lbl_803ae960);
    fn_801eb834(object, lbl_803ae994);
    fn_801eb834(object, lbl_803ae9bc);
    fn_801ece2c(object, lbl_803ae9e4);
    if (!lbl_804b0534) {
        S20PropertyInfo *target = &lbl_8045d7f0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ae8e4;
        info.size = 28;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0534 = 1;
    }
    fn_801efd34(object, &lbl_8045d7f0);
    fn_801e8d9c(object);
    return 0;
}
