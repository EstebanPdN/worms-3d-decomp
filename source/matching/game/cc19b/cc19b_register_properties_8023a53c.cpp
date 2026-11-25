// Observed lazy property descriptors: explicit field widths and native zeroing constructor.
extern "C" {
extern "C" void *memset(...);
typedef struct Cc19bPropertyInfo {
    Cc19bPropertyInfo() { memset(this, 0, sizeof(*this)); }
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *descriptor;
    void *extra;
    int reserved16;
} Cc19bPropertyInfo;


extern char lbl_803bb558[];
void * fn_801ebf38(void *, char *);
extern int lbl_804b0830;
extern Cc19bPropertyInfo lbl_80464c0c;
extern char lbl_803bb580[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, Cc19bPropertyInfo *);
void fn_801e8d9c(void *);
int w3d_cc19b_register_properties_8023a53c(void *object)
{
    fn_801ebf38(object, lbl_803bb558);
    if (!lbl_804b0830) {
        Cc19bPropertyInfo *target = &lbl_80464c0c;
        Cc19bPropertyInfo info;
        info.name = lbl_803bb580;
        info.size = 44;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0830 = 1;
    }
    fn_801efd34(object, &lbl_80464c0c);
    fn_801e8d9c(object);
    return 0;
}
}
