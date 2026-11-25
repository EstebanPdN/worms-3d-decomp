#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801ca758.c"
/* Literal fields and addresses derived from the original registration blocks. */
typedef struct S20PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int reserved16;
} S20PropertyInfo;
Ptr32<void> memset(Ptr32<void>, int, unsigned int);

extern char lbl_803adca8[];
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<char>);
extern int lbl_804b04f8;
extern S20PropertyInfo lbl_8045d6c4;
extern char lbl_803adccc[];
extern char lbl_8045ed34[];
Ptr32<void> fn_801efd98(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b04fc;
extern S20PropertyInfo lbl_8045d6d8;
extern char lbl_803adc88[];
extern char lbl_8045e29c[];
Ptr32<void> fn_801f2420(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0500;
extern S20PropertyInfo lbl_8045d6ec;
extern char lbl_803adc94[];
extern char lbl_8045e47c[];
Ptr32<void> fn_801f25b0(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0504;
extern S20PropertyInfo lbl_8045d700;
extern char lbl_803adcdc[];
extern char lbl_8045ed1c[];
Ptr32<void> fn_801efd34(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0508;
extern S20PropertyInfo lbl_8045d714;
extern char lbl_803adcec[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801ca758(Ptr32<void> object)
{
    S20PropertyInfo info;
    fn_801ecc6c(object, lbl_803adca8);
    if (!lbl_804b04f8) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d6c4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adccc;
        info.size = 40;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b04f8 = 1;
    }
    fn_801efd98(object, &lbl_8045d6c4);
    if (!lbl_804b04fc) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d6d8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adc88;
        info.size = 32;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e29c;
        *target = info;
        lbl_804b04fc = 1;
    }
    fn_801f2420(object, &lbl_8045d6d8);
    if (!lbl_804b0500) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d6ec;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adc94;
        info.size = 28;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e47c;
        *target = info;
        lbl_804b0500 = 1;
    }
    fn_801f25b0(object, &lbl_8045d6ec);
    if (!lbl_804b0504) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d700;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adcdc;
        info.size = 48;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0504 = 1;
    }
    fn_801efd34(object, &lbl_8045d700);
    if (!lbl_804b0508) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d714;
        memset(&info, 0, sizeof info);
        info.name = lbl_803adcec;
        info.size = 44;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0508 = 1;
    }
    fn_801efd34(object, &lbl_8045d714);
    fn_801e8d9c(object);
    return 0;
}

}
