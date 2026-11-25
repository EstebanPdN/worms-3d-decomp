#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_801c4068.c"
/* Literal fields and addresses derived from the original registration blocks. */
typedef struct S10PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int reserved16;
} S10PropertyInfo;
Ptr32<void> memset(Ptr32<void>, int, unsigned int);

extern int lbl_804b04b8;
extern S10PropertyInfo lbl_8045d584;
extern char lbl_803aca0c[];
extern char lbl_8045e004[];
extern char lbl_803fe5a0[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b04bc;
extern S10PropertyInfo lbl_8045d598;
extern char lbl_803aca14[];
extern char lbl_803fe5ac[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_801c4068(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b04b8) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d584;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca0c;
        info.size = 24;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe5a0;
        *target = info;
        lbl_804b04b8 = 1;
    }
    fn_801eff8c(object, &lbl_8045d584);
    if (!lbl_804b04bc) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d598;
        memset(&info, 0, sizeof info);
        info.name = lbl_803aca14;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe5ac;
        *target = info;
        lbl_804b04bc = 1;
    }
    fn_801eff8c(object, &lbl_8045d598);
    fn_801e8d9c(object);
    return 0;
}

}
