#include "w3d_ptr.h"
#line 1 "cc19b_register_properties_8023b0ec.cpp"
// Observed lazy property descriptors: explicit field widths and native zeroing constructor.
extern "C" {
extern "C" Ptr32<void> memset(...);
typedef struct Cc19bPropertyInfo {
    Cc19bPropertyInfo() { memset(w3d::VA(this), 0, sizeof(*this)); }
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int reserved16;
} Cc19bPropertyInfo;


extern char lbl_803bba80[];
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<char>);
extern char lbl_803bbab0[];
extern char lbl_803bbae8[];
extern char lbl_803bbb20[];
extern char lbl_803bbb58[];
extern int lbl_804b0838;
extern Cc19bPropertyInfo lbl_80464c34;
extern char lbl_803bbb7c[];
extern char lbl_8045e004[];
extern char lbl_80400c2c[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<Cc19bPropertyInfo>);
extern char lbl_803bbba4[];
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<char>);
extern char lbl_803bbbd4[];
Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<char>);
extern char lbl_803bbc10[];
extern char lbl_803bbc50[];
extern char lbl_803bbc8c[];
extern char lbl_803bbcc0[];
extern char lbl_803bbcf4[];
Ptr32<void> fn_801ec0f8(Ptr32<void>, Ptr32<char>);
extern char lbl_803bbd2c[];
void fn_801e8d9c(Ptr32<void>);
int w3d_cc19b_register_properties_8023b0ec(Ptr32<void> object)
{
    fn_801ecc6c(object, lbl_803bba80);
    fn_801ecc6c(object, lbl_803bbab0);
    fn_801ecc6c(object, lbl_803bbae8);
    fn_801ecc6c(object, lbl_803bbb20);
    fn_801ecc6c(object, lbl_803bbb58);
    if (!lbl_804b0838) {
        Ptr32<Cc19bPropertyInfo> target = &lbl_80464c34;
        Cc19bPropertyInfo info;
        info.name = lbl_803bbb7c;
        info.size = 44;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_80400c2c;
        *target = info;
        lbl_804b0838 = 1;
    }
    fn_801eff8c(object, &lbl_80464c34);
    fn_801ebf38(object, lbl_803bbba4);
    fn_801eb674(object, lbl_803bbbd4);
    fn_801ebf38(object, lbl_803bbc10);
    fn_801ebf38(object, lbl_803bbc50);
    fn_801ebf38(object, lbl_803bbc8c);
    fn_801eb674(object, lbl_803bbcc0);
    fn_801ec0f8(object, lbl_803bbcf4);
    fn_801ec0f8(object, lbl_803bbd2c);
    fn_801e8d9c(object);
    return 0;
}
}


