#include "w3d_ptr.h"
#line 1 "cc19b_register_properties_8024eb00.cpp"
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


extern int lbl_804b08e0;
extern Cc19bPropertyInfo lbl_80464f7c;
extern char lbl_803c5140[];
extern char lbl_8045ed94[];
Ptr32<void> fn_801efff0(Ptr32<void>, Ptr32<Cc19bPropertyInfo>);
extern int lbl_804b08e4;
extern Cc19bPropertyInfo lbl_80464f90;
extern char lbl_803c553c[];
extern char lbl_8045ed4c[];
Ptr32<void> fn_801efdfc(Ptr32<void>, Ptr32<Cc19bPropertyInfo>);
extern int lbl_804b08e8;
extern Cc19bPropertyInfo lbl_80464fa4;
extern char lbl_803c5550[];
extern char lbl_8045ed10[];
Ptr32<void> fn_801efcd0(Ptr32<void>, Ptr32<Cc19bPropertyInfo>);
extern int lbl_804b08ec;
extern Cc19bPropertyInfo lbl_80464fb8;
extern char lbl_803c555c[];
extern char lbl_8045e004[];
extern char lbl_803fe4c4[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<Cc19bPropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
int w3d_cc19b_register_properties_8024eb00(Ptr32<void> object)
{
    if (!lbl_804b08e0) {
        Ptr32<Cc19bPropertyInfo> target = &lbl_80464f7c;
        Cc19bPropertyInfo info;
        info.name = lbl_803c5140;
        info.size = 52;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b08e0 = 1;
    }
    fn_801efff0(object, &lbl_80464f7c);
    if (!lbl_804b08e4) {
        Ptr32<Cc19bPropertyInfo> target = &lbl_80464f90;
        Cc19bPropertyInfo info;
        info.name = lbl_803c553c;
        info.size = 48;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed4c;
        *target = info;
        lbl_804b08e4 = 1;
    }
    fn_801efdfc(object, &lbl_80464f90);
    if (!lbl_804b08e8) {
        Ptr32<Cc19bPropertyInfo> target = &lbl_80464fa4;
        Cc19bPropertyInfo info;
        info.name = lbl_803c5550;
        info.size = 56;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed10;
        *target = info;
        lbl_804b08e8 = 1;
    }
    fn_801efcd0(object, &lbl_80464fa4);
    if (!lbl_804b08ec) {
        Ptr32<Cc19bPropertyInfo> target = &lbl_80464fb8;
        Cc19bPropertyInfo info;
        info.name = lbl_803c555c;
        info.size = 44;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe4c4;
        *target = info;
        lbl_804b08ec = 1;
    }
    fn_801eff8c(object, &lbl_80464fb8);
    fn_801e8d9c(object);
    return 0;
}
}


