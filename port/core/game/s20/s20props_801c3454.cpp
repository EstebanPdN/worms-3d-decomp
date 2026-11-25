#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801c3454.c"
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

extern char lbl_803ac824[];
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<char>);
extern char lbl_803ac858[];
extern char lbl_803ac888[];
extern int lbl_804b04a0;
extern S20PropertyInfo lbl_8045d50c;
extern char lbl_803ab6bc[];
extern char lbl_8045ed34[];
Ptr32<void> fn_801efd98(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern int lbl_804b04a4;
extern S20PropertyInfo lbl_8045d520;
extern char lbl_803ac8b0[];
extern char lbl_8045ed7c[];
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S20PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801c3454(Ptr32<void> object)
{
    S20PropertyInfo info;
    fn_801ec52c(object, lbl_803ac824);
    fn_801ec52c(object, lbl_803ac858);
    fn_801ec52c(object, lbl_803ac888);
    if (!lbl_804b04a0) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d50c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab6bc;
        info.size = 60;
        info.elementType = 6;
        info.type = 9;
        info.descriptor = lbl_8045ed34;
        *target = info;
        lbl_804b04a0 = 1;
    }
    fn_801efd98(object, &lbl_8045d50c);
    if (!lbl_804b04a4) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d520;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac8b0;
        info.size = 44;
        info.elementType = 7;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b04a4 = 1;
    }
    fn_801efec4(object, &lbl_8045d520);
    fn_801e8d9c(object);
    return 0;
}

}
