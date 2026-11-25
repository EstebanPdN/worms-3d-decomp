#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801c0914.c"
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

extern int lbl_804b0418;
extern S20PropertyInfo lbl_8045d264;
extern char lbl_803ac3ec[];
extern char lbl_8045ed1c[];
Ptr32<void> fn_801efd34(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b041c;
extern S20PropertyInfo lbl_8045d278;
extern char lbl_803ab160[];
extern char lbl_8045e2b4[];
Ptr32<void> fn_801f23bc(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0420;
extern S20PropertyInfo lbl_8045d28c;
extern char lbl_803ab108[];
extern char lbl_8045ed7c[];
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0424;
extern S20PropertyInfo lbl_8045d2a0;
extern char lbl_803ac3f8[];
extern char lbl_8045e47c[];
Ptr32<void> fn_801f25b0(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b0428;
extern S20PropertyInfo lbl_8045d2b4;
extern char lbl_803ab0f8[];
extern char lbl_8045e23c[];
Ptr32<void> fn_801f2100(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b042c;
extern S20PropertyInfo lbl_8045d2c8;
extern char lbl_803abf88[];
extern char lbl_803ac410[];
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<char>);
extern char lbl_803ac438[];
extern char lbl_803ac478[];
extern char lbl_803ac4ac[];
Ptr32<void> fn_801eb834(Ptr32<void>, Ptr32<char>);
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801c0914(Ptr32<void> object)
{
    S20PropertyInfo info;
    if (!lbl_804b0418) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d264;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3ec;
        info.size = 100;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0418 = 1;
    }
    fn_801efd34(object, &lbl_8045d264);
    if (!lbl_804b041c) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d278;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab160;
        info.size = 64;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b041c = 1;
    }
    fn_801f23bc(object, &lbl_8045d278);
    if (!lbl_804b0420) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d28c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab108;
        info.size = 88;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b0420 = 1;
    }
    fn_801efec4(object, &lbl_8045d28c);
    if (!lbl_804b0424) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d2a0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3f8;
        info.size = 68;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045e47c;
        *target = info;
        lbl_804b0424 = 1;
    }
    fn_801f25b0(object, &lbl_8045d2a0);
    if (!lbl_804b0428) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d2b4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab0f8;
        info.size = 84;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045e23c;
        *target = info;
        lbl_804b0428 = 1;
    }
    fn_801f2100(object, &lbl_8045d2b4);
    if (!lbl_804b042c) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d2c8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803abf88;
        info.size = 96;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b042c = 1;
    }
    fn_801efd34(object, &lbl_8045d2c8);
    fn_801ebf38(object, lbl_803ac410);
    fn_801ebf38(object, lbl_803ac438);
    fn_801ebf38(object, lbl_803ac478);
    fn_801eb834(object, lbl_803ac4ac);
    fn_801e8d9c(object);
    return 0;
}

}
