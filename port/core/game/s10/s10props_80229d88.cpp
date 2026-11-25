#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_80229d88.c"
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

extern int lbl_804b07fc;
extern S10PropertyInfo lbl_80464af4;
extern char lbl_803b9528[];
extern char lbl_8045e004[];
extern char lbl_804007f0[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b0800;
extern S10PropertyInfo lbl_80464b08;
extern char lbl_803b9530[];
extern char lbl_804007fc[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_80229d88(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b07fc) {
        Ptr32<S10PropertyInfo> target = &lbl_80464af4;
        memset(&info, 0, sizeof info);
        info.name = lbl_803b9528;
        info.size = 24;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_804007f0;
        *target = info;
        lbl_804b07fc = 1;
    }
    fn_801eff8c(object, &lbl_80464af4);
    if (!lbl_804b0800) {
        Ptr32<S10PropertyInfo> target = &lbl_80464b08;
        memset(&info, 0, sizeof info);
        info.name = lbl_803b9530;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_804007fc;
        *target = info;
        lbl_804b0800 = 1;
    }
    fn_801eff8c(object, &lbl_80464b08);
    fn_801e8d9c(object);
    return 0;
}

}
