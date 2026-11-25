#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10props_801c9428.c"
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

extern int lbl_804b04d8;
extern S10PropertyInfo lbl_8045d624;
extern char lbl_803ad844[];
extern char lbl_8045e004[];
extern char lbl_803fe624[];
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern int lbl_804b04dc;
extern S10PropertyInfo lbl_8045d638;
extern char lbl_803ad854[];
extern char lbl_803fe630[];
void fn_801e8d9c(Ptr32<void>);
int w3d_s10_register_properties_801c9428(Ptr32<void> object)
{
    S10PropertyInfo info;
    if (!lbl_804b04d8) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d624;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad844;
        info.size = 32;
        info.elementType = 2;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe624;
        *target = info;
        lbl_804b04d8 = 1;
    }
    fn_801eff8c(object, &lbl_8045d624);
    if (!lbl_804b04dc) {
        Ptr32<S10PropertyInfo> target = &lbl_8045d638;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ad854;
        info.size = 28;
        info.elementType = 3;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe630;
        *target = info;
        lbl_804b04dc = 1;
    }
    fn_801eff8c(object, &lbl_8045d638);
    fn_801e8d9c(object);
    return 0;
}

}
