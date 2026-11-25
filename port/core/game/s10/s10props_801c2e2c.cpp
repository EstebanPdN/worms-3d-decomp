#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_801c2e2c.c"
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

extern int lbl_804b0484;
extern S10PropertyInfo lbl_8045d480;
extern char lbl_803ac7b4[];
extern char lbl_8045e2b4[];
Ptr32<void> fn_801f23bc(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0488;
extern S10PropertyInfo lbl_8045d494;
extern char lbl_803ac7c4[];
extern char lbl_8045e494[];
Ptr32<void> fn_801f254c(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b048c;
extern S10PropertyInfo lbl_8045d4a8;
extern char lbl_803ac7d4[];
extern char lbl_8045ed7c[];
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0490;
extern S10PropertyInfo lbl_8045d4bc;
extern char lbl_803ac7e0[];
extern char lbl_8045ed34[];
Ptr32<void> fn_801efd98(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0494;
extern S10PropertyInfo lbl_8045d4d0;
extern char lbl_803ac7f0[];
extern char lbl_8045ed1c[];
Ptr32<void> fn_801efd34(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0498;
extern S10PropertyInfo lbl_8045d4e4;
extern char lbl_803ac7fc[];
extern int lbl_804b049c;
extern S10PropertyInfo lbl_8045d4f8;
extern char lbl_803ac808[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_801c2e2c(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b0484) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d480;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7b4;
        info.size = 24;
        info.type = 9;
        info.descriptor = lbl_8045e2b4;
        *target = info;
        lbl_804b0484 = 1;
    }
    fn_801f23bc(object, &lbl_8045d480);
    if (!lbl_804b0488) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d494;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7c4;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e494;
        *target = info;
        lbl_804b0488 = 1;
    }
    fn_801f254c(object, &lbl_8045d494);
    if (!lbl_804b048c) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d4a8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7d4;
        info.size = 32;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b048c = 1;
    }
    fn_801efec4(object, &lbl_8045d4a8);
    if (!lbl_804b0490) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d4bc;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7e0;
        info.size = 40;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0490 = 1;
    }
    fn_801efd98(object, &lbl_8045d4bc);
    if (!lbl_804b0494) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d4d0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7f0;
        info.size = 44;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045ed1c;
        *target = info;
        lbl_804b0494 = 1;
    }
    fn_801efd34(object, &lbl_8045d4d0);
    if (!lbl_804b0498) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d4e4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac7fc;
        info.size = 36;
        info.elementType = 5;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b0498 = 1;
    }
    fn_801efd98(object, &lbl_8045d4e4);
    if (!lbl_804b049c) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d4f8;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac808;
        info.size = 28;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b049c = 1;
    }
    fn_801efec4(object, &lbl_8045d4f8);
    fn_801e8d9c(object);
    return 0;
}

}
