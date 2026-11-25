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


extern int lbl_804b08c0;
extern Cc19bPropertyInfo lbl_80464edc;
extern char lbl_803c4ff4[];
extern char lbl_8045ed1c[];
void * fn_801efd34(void *, Cc19bPropertyInfo *);
extern int lbl_804b08c4;
extern Cc19bPropertyInfo lbl_80464ef0;
extern char lbl_803c5008[];
extern char lbl_803c5028[];
void * fn_801ecc6c(void *, char *);
extern int lbl_804b08c8;
extern Cc19bPropertyInfo lbl_80464f04;
extern char lbl_803c504c[];
extern char lbl_8045ed34[];
void * fn_801efd98(void *, Cc19bPropertyInfo *);
extern char lbl_803c5070[];
void * fn_801ebbb8(void *, char *);
extern char lbl_803c50a8[];
void fn_801e8d9c(void *);
int w3d_cc19b_register_properties_8024d658(void *object)
{
    if (!lbl_804b08c0) {
        Cc19bPropertyInfo *target = &lbl_80464edc;
        Cc19bPropertyInfo info;
        info.name = lbl_803c4ff4;
        info.size = 480;
        info.elementType = 42;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b08c0 = 1;
    }
    fn_801efd34(object, &lbl_80464edc);
    if (!lbl_804b08c4) {
        Cc19bPropertyInfo *target = &lbl_80464ef0;
        Cc19bPropertyInfo info;
        info.name = lbl_803c5008;
        info.size = 476;
        info.elementType = 43;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b08c4 = 1;
    }
    fn_801efd34(object, &lbl_80464ef0);
    fn_801ecc6c(object, lbl_803c5028);
    if (!lbl_804b08c8) {
        Cc19bPropertyInfo *target = &lbl_80464f04;
        Cc19bPropertyInfo info;
        info.name = lbl_803c504c;
        info.size = 472;
        info.elementType = 45;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b08c8 = 1;
    }
    fn_801efd98(object, &lbl_80464f04);
    fn_801ebbb8(object, lbl_803c5070);
    fn_801ebbb8(object, lbl_803c50a8);
    fn_801e8d9c(object);
    return 0;
}
}
