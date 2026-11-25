#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20props_801bb74c.c"
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

extern char lbl_803ab678[];
Ptr32<void> fn_801ebbb8(Ptr32<void>, Ptr32<char>);
extern int lbl_804b03e0;
extern S20PropertyInfo lbl_8045d14c;
extern char lbl_803ab6a0[];
extern char lbl_8045ed7c[];
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<S20PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801bb74c(Ptr32<void> object)
{
    S20PropertyInfo info;
    fn_801ebbb8(object, lbl_803ab678);
    if (!lbl_804b03e0) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d14c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab6a0;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed7c;
        *target = info;
        lbl_804b03e0 = 1;
    }
    fn_801efec4(object, &lbl_8045d14c);
    fn_801e8d9c(object);
    return 0;
}

}
