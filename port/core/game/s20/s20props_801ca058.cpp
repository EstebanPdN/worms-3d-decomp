#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801ca058.c"
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

extern char lbl_803adb34[];
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<char>);
extern char lbl_803adb58[];
extern int lbl_804b04ec;
extern S20PropertyInfo lbl_8045d688;
extern char lbl_803ad854[];
extern char lbl_8045e004[];
extern char lbl_803fe630[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern char lbl_803adb88[];
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<char>);
extern char lbl_803adbbc[];
extern char lbl_803adbf4[];
extern char lbl_803adc2c[];
extern char lbl_803adc60[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801ca058(Ptr32<void> object)
{
    S20PropertyInfo info;
    fn_801ecc6c(object, lbl_803adb34);
    fn_801ecc6c(object, lbl_803adb58);
    if (!lbl_804b04ec) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d688;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad854;
        info.size = 48;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe630;
        *target = info;
        lbl_804b04ec = 1;
    }
    fn_801eff8c(object, &lbl_8045d688);
    fn_801ec52c(object, lbl_803adb88);
    fn_801ec52c(object, lbl_803adbbc);
    fn_801ec52c(object, lbl_803adbf4);
    fn_801ec52c(object, lbl_803adc2c);
    fn_801ec52c(object, lbl_803adc60);
    fn_801e8d9c(object);
    return 0;
}

}
