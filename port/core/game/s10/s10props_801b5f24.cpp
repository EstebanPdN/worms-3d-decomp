#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_801b5f24.c"
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

extern int lbl_804b0364;
extern S10PropertyInfo lbl_8045cee0;
extern char lbl_803ab0e0[];
extern char lbl_8045e2cc[];
Ptr32<void> fn_801f2358(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0368;
extern S10PropertyInfo lbl_8045cef4;
extern char lbl_803ab0f0[];
extern char lbl_8045ed7c[];
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b036c;
extern S10PropertyInfo lbl_8045cf08;
extern char lbl_803ab0f8[];
extern char lbl_8045e1dc[];
Ptr32<void> fn_801f2164(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0370;
extern S10PropertyInfo lbl_8045cf1c;
extern char lbl_803ab100[];
extern int lbl_804b0374;
extern S10PropertyInfo lbl_8045cf30;
extern char lbl_803ab108[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_801b5f24(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b0364) {
        Ptr32<S10PropertyInfo> target = &lbl_8045cee0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0e0;
        info.size = 68;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e2cc;
        *target = info;
        lbl_804b0364 = 1;
    }
    fn_801f2358(object, &lbl_8045cee0);
    if (!lbl_804b0368) {
        Ptr32<S10PropertyInfo> target = &lbl_8045cef4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f0;
        info.size = 80;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0368 = 1;
    }
    fn_801efec4(object, &lbl_8045cef4);
    if (!lbl_804b036c) {
        Ptr32<S10PropertyInfo> target = &lbl_8045cf08;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f8;
        info.size = 64;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e1dc;
        *target = info;
        lbl_804b036c = 1;
    }
    fn_801f2164(object, &lbl_8045cf08);
    if (!lbl_804b0370) {
        Ptr32<S10PropertyInfo> target = &lbl_8045cf1c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab100;
        info.size = 76;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0370 = 1;
    }
    fn_801efec4(object, &lbl_8045cf1c);
    if (!lbl_804b0374) {
        Ptr32<S10PropertyInfo> target = &lbl_8045cf30;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab108;
        info.size = 72;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0374 = 1;
    }
    fn_801efec4(object, &lbl_8045cf30);
    fn_801e8d9c(object);
    return 0;
}

}
