#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_desc_a.c"
/* Registration with a once-initialized property descriptor. */
typedef struct S20PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int unknown;
} S20PropertyInfo;
extern S20PropertyInfo lbl_8045d660;
extern int lbl_804b04e4;
extern char lbl_803ad89c[];
extern char lbl_803ad8d4[];
extern char lbl_803ad854[];
extern char lbl_8045e004[];
extern char lbl_803fe630[];
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<char>);
int fn_801eff8c(Ptr32<void>, Ptr32<S20PropertyInfo>);
int fn_801e8d9c(Ptr32<void>);

int w3d_s20_register_attributes_801c99c8(Ptr32<void> self)
{
    fn_801ecc6c(self, lbl_803ad89c);
    fn_801ecc6c(self, lbl_803ad8d4);
    if (!lbl_804b04e4) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d660;
        S20PropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad854;
        info.size = 28;
        info.elementType = 4;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe630;
        *target = info;
        lbl_804b04e4 = 1;
    }
    fn_801eff8c(self, &lbl_8045d660);
    fn_801e8d9c(self);
    return 0;
}

}
