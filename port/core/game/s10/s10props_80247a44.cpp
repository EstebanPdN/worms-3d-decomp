#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_80247a44.c"
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

extern int lbl_804b0884;
extern S10PropertyInfo lbl_80464db0;
extern char lbl_803c3e9c[];
extern char lbl_8045ed10[];
Ptr32<void> fn_801efcd0(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0888;
extern S10PropertyInfo lbl_80464dc4;
extern char lbl_803c3ea8[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_80247a44(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b0884) {
        Ptr32<S10PropertyInfo> target = &lbl_80464db0;
        memset(&info, 0, sizeof info);
        info.name = lbl_803c3e9c;
        info.size = 24;
        info.type = 9;
        info.descriptor = lbl_8045ed10;
        *target = info;
        lbl_804b0884 = 1;
    }
    fn_801efcd0(object, &lbl_80464db0);
    if (!lbl_804b0888) {
        Ptr32<S10PropertyInfo> target = &lbl_80464dc4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803c3ea8;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045ed10;
        *target = info;
        lbl_804b0888 = 1;
    }
    fn_801efcd0(object, &lbl_80464dc4);
    fn_801e8d9c(object);
    return 0;
}

}
