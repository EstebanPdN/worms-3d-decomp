#include "w3d_ptr.h"
#line 1 "s8hand_800a3fa0.cpp"
struct s8_PropertyName { Ptr32<const char> text; };
extern "C" int fn_800fc230(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern "C" int fn_800fc43c(Ptr32<Ptr32<const char>>, int);
extern char lbl_80380d24[], lbl_80380d34[];
extern "C" void s8_show_flags_800a3fa0() {
    Ptr32<const char> name; int showName;
    Ptr32<const char> health; int showHealth;
    Ptr32<const char> nameOut; Ptr32<const char> healthOut;
    name = lbl_80380d24;
    fn_800fc230(&name,&showName);
    health = lbl_80380d34;
    fn_800fc230(&health,&showHealth);
    nameOut = lbl_80380d24;
    unsigned next = showName + (showHealth << 1) + 1;
    int nextName = next & 1;
    showHealth = (next >> 1) & 1;
    showName = nextName;
    fn_800fc43c(&nameOut,nextName);
    healthOut = lbl_80380d34;
    fn_800fc43c(&healthOut,showHealth);
}


