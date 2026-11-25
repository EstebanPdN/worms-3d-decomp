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


extern int lbl_804b0834;
extern Cc19bPropertyInfo lbl_80464c20;
extern char lbl_803bb86c[];
extern char lbl_8045e004[];
extern char lbl_80400bfc[];
void * fn_801eff8c(void *, Cc19bPropertyInfo *);
extern char lbl_803bb884[];
void * fn_801ecc6c(void *, char *);
extern char lbl_803bb8b8[];
void * fn_801ebf38(void *, char *);
extern char lbl_803bb8e0[];
extern char lbl_803bb914[];
extern char lbl_803bb94c[];
extern char lbl_803bb984[];
extern char lbl_803bb9b4[];
extern char lbl_803bb9ec[];
extern char lbl_803bba24[];
extern char lbl_803bba58[];
void fn_801e8d9c(void *);
int w3d_cc19b_register_properties_8023ad28(void *object)
{
    if (!lbl_804b0834) {
        Cc19bPropertyInfo *target = &lbl_80464c20;
        Cc19bPropertyInfo info;
        info.name = lbl_803bb86c;
        info.size = 60;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_80400bfc;
        *target = info;
        lbl_804b0834 = 1;
    }
    fn_801eff8c(object, &lbl_80464c20);
    fn_801ecc6c(object, lbl_803bb884);
    fn_801ebf38(object, lbl_803bb8b8);
    fn_801ebf38(object, lbl_803bb8e0);
    fn_801ebf38(object, lbl_803bb914);
    fn_801ebf38(object, lbl_803bb94c);
    fn_801ebf38(object, lbl_803bb984);
    fn_801ebf38(object, lbl_803bb9b4);
    fn_801ebf38(object, lbl_803bb9ec);
    fn_801ebf38(object, lbl_803bba24);
    fn_801ebf38(object, lbl_803bba58);
    fn_801e8d9c(object);
    return 0;
}
}
