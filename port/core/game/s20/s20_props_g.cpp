#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_props_g.c"
/* Registration with a descriptor block and a struct default copied from a global. */
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

extern int lbl_804b0414;
extern S20PropertyInfo lbl_8045d250;
extern char lbl_803ac3a8[];
extern char lbl_8045e004[];
extern char lbl_803fe588[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S20PropertyInfo>);
extern char lbl_803ac3bc[];
Ptr32<char> fn_801f0d2c(Ptr32<void>, Ptr32<char>);
typedef struct S20Block64 { int words[16]; } S20Block64;
extern S20Block64 lbl_8045e708;
void fn_801e8d9c(Ptr32<void>);
int w3d_s20_register_properties_801c04f8(Ptr32<void> object)
{
    S20PropertyInfo info;
    if (!lbl_804b0414) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d250;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac3a8;
        info.size = 84;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe588;
        *target = info;
        lbl_804b0414 = 1;
    }
    fn_801eff8c(object, &lbl_8045d250);
    {
        Ptr32<char> property = fn_801f0d2c(object, lbl_803ac3bc);
        *(Ptr32<S20Block64>)(property + 8) = lbl_8045e708;
    }
    fn_801e8d9c(object);
    return 0;
}

}
