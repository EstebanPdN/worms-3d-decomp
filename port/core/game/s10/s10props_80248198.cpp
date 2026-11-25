#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_80248198.c"
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

extern int lbl_804b088c;
extern S10PropertyInfo lbl_80464dd8;
extern char lbl_803c41b8[];
extern char lbl_8045ed94[];
Ptr32<void> fn_801efff0(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0890;
extern S10PropertyInfo lbl_80464dec;
extern char lbl_803c41c0[];
extern int lbl_804b0894;
extern S10PropertyInfo lbl_80464e00;
extern char lbl_803c41cc[];
extern char lbl_8045e23c[];
Ptr32<void> fn_801f2100(Ptr32<void>, Ptr32<S10PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_80248198(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b088c) {
        Ptr32<S10PropertyInfo> target = &lbl_80464dd8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803c41b8;
        info.size = 28;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b088c = 1;
    }
    fn_801efff0(object, &lbl_80464dd8);
    if (!lbl_804b0890) {
        Ptr32<S10PropertyInfo> target = &lbl_80464dec;
        memset(&info, 0, sizeof info);
        info.name = lbl_803c41c0;
        info.size = 24;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed94;
        *target = info;
        lbl_804b0890 = 1;
    }
    fn_801efff0(object, &lbl_80464dec);
    if (!lbl_804b0894) {
        Ptr32<S10PropertyInfo> target = &lbl_80464e00;
        memset(&info, 0, sizeof info);
        info.name = lbl_803c41cc;
        info.size = 20;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e23c;
        *target = info;
        lbl_804b0894 = 1;
    }
    fn_801f2100(object, &lbl_80464e00);
    fn_801e8d9c(object);
    return 0;
}

}
