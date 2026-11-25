#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_800154e0.c"
extern void w3d_auto_800fc230(Ptr32<Ptr32<const char>>, Ptr32<int>);
struct S19Rec { char pad0[196]; int mode; };
extern Ptr32<struct S19Rec> s8_index_query_800fc6dc(int);

int s19_artillery_mode_800154e0(int index) {
    Ptr32<const char> name = "GameLogic.ArtilleryMode";
    int value;
    w3d_auto_800fc230(&name, &value);
    if (value != 0)
        return 0;
    return s8_index_query_800fc6dc(index)->mode ^ 1;
}

}
