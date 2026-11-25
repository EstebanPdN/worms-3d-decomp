#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_801b9a18.c"
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

extern int lbl_804b03b0;
extern S10PropertyInfo lbl_8045d05c;
extern char lbl_803ab45c[];
extern char lbl_8045e2cc[];
Ptr32<void> fn_801f2358(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b03b4;
extern S10PropertyInfo lbl_8045d070;
extern char lbl_803ab524[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_801b9a18(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b03b0) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d05c;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab45c;
        info.size = 24;
        info.type = 9;
        info.descriptor = lbl_8045e2cc;
        *target = info;
        lbl_804b03b0 = 1;
    }
    fn_801f2358(object, &lbl_8045d05c);
    if (!lbl_804b03b4) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d070;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ab524;
        info.size = 20;
        info.elementType = 1;
        info.type = 13;
        info.descriptor = lbl_8045e2cc;
        *target = info;
        lbl_804b03b4 = 1;
    }
    fn_801f2358(object, &lbl_8045d070);
    fn_801e8d9c(object);
    return 0;
}

}
