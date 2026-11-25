#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801c9d00.c"
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

extern char lbl_803ad91c[];
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<char>);
extern char lbl_803ad954[];
extern char lbl_803ad978[];
extern char lbl_803ad9ac[];
extern char lbl_803ad9e0[];
extern int lbl_804b04e8;
extern S20PropertyInfo lbl_8045d674;
extern char lbl_803ad854[];
extern char lbl_8045e004[];
extern char lbl_803fe630[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern char lbl_803ada10[];
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<char>);
extern char lbl_803ada44[];
extern char lbl_803ada78[];
extern char lbl_803adab0[];
extern char lbl_803adae8[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801c9d00(Ptr32<void> object)
{
    S20PropertyInfo info;
    fn_801ecc6c(object, lbl_803ad91c);
    fn_801ecc6c(object, lbl_803ad954);
    fn_801ecc6c(object, lbl_803ad978);
    fn_801ecc6c(object, lbl_803ad9ac);
    fn_801ecc6c(object, lbl_803ad9e0);
    if (!lbl_804b04e8) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d674;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad854;
        info.size = 48;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe630;
        *target = info;
        lbl_804b04e8 = 1;
    }
    fn_801eff8c(object, &lbl_8045d674);
    fn_801ec52c(object, lbl_803ada10);
    fn_801ec52c(object, lbl_803ada44);
    fn_801ec52c(object, lbl_803ada78);
    fn_801ec52c(object, lbl_803adab0);
    fn_801ec52c(object, lbl_803adae8);
    fn_801e8d9c(object);
    return 0;
}

}
