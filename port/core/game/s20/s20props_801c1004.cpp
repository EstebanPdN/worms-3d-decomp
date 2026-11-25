#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801c1004.c"
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

extern int lbl_804b0430;
extern S20PropertyInfo lbl_8045d2dc;
extern char lbl_803ac3ec[];
extern char lbl_8045ed1c[];
Ptr32<void> fn_801efd34(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern char lbl_803ac4f0[];
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<char>);
extern int lbl_804b0434;
extern S20PropertyInfo lbl_8045d2f0;
extern char lbl_803ab160[];
extern char lbl_8045e2b4[];
Ptr32<void> fn_801f23bc(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0438;
extern S20PropertyInfo lbl_8045d304;
extern char lbl_803ab108[];
extern char lbl_8045ed7c[];
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b043c;
extern S20PropertyInfo lbl_8045d318;
extern char lbl_803ac3f8[];
extern char lbl_8045e494[];
Ptr32<void> fn_801f254c(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0440;
extern S20PropertyInfo lbl_8045d32c;
extern char lbl_803ab0f8[];
extern char lbl_8045e23c[];
Ptr32<void> fn_801f2100(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0444;
extern S20PropertyInfo lbl_8045d340;
extern char lbl_803abf88[];
extern char lbl_803ac514[];
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<char>);
extern char lbl_803ac53c[];
extern char lbl_803ac564[];
extern char lbl_803ac58c[];
Ptr32<void> fn_801eb834(Ptr32<void>, Ptr32<char>);
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801c1004(Ptr32<void> object)
{
    S20PropertyInfo info;
    if (!lbl_804b0430) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d2dc;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3ec;
        info.size = 104;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0430 = 1;
    }
    fn_801efd34(object, &lbl_8045d2dc);
    fn_801ecc6c(object, lbl_803ac4f0);
    if (!lbl_804b0434) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d2f0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab160;
        info.size = 68;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b0434 = 1;
    }
    fn_801f23bc(object, &lbl_8045d2f0);
    if (!lbl_804b0438) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d304;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab108;
        info.size = 88;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0438 = 1;
    }
    fn_801efec4(object, &lbl_8045d304);
    if (!lbl_804b043c) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d318;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3f8;
        info.size = 64;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e494;
        *target = info;
        lbl_804b043c = 1;
    }
    fn_801f254c(object, &lbl_8045d318);
    if (!lbl_804b0440) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d32c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f8;
        info.size = 84;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045e23c;
        *target = info;
        lbl_804b0440 = 1;
    }
    fn_801f2100(object, &lbl_8045d32c);
    if (!lbl_804b0444) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d340;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abf88;
        info.size = 100;
        info.elementType = 8;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0444 = 1;
    }
    fn_801efd34(object, &lbl_8045d340);
    fn_801ebf38(object, lbl_803ac514);
    fn_801ebf38(object, lbl_803ac53c);
    fn_801ebf38(object, lbl_803ac564);
    fn_801eb834(object, lbl_803ac58c);
    fn_801e8d9c(object);
    return 0;
}

}
