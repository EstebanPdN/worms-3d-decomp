#include "w3d_ptr.h"
#line 1 "cx7b_land_time_refresh_80269dd0.cpp"
struct Cx7bLandTimeOwner { char unknown00[496]; int ready; };
extern "C" char text_803cb980[];
extern "C" int fn_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>);
extern "C" void fn_8026c008(Ptr32<Cx7bLandTimeOwner>,int);
extern "C" void fn_8026b9bc(Ptr32<Cx7bLandTimeOwner>);
extern "C" int w3d_cx7b_land_time_refresh_80269dd0(Ptr32<void>, Ptr32<Cx7bLandTimeOwner> owner) {
 if(owner->ready==0) { Ptr32<const char> name=text_803cb980; int time; fn_800fc230(&name,&time); fn_8026c008(owner,1); fn_8026b9bc(owner); } return 0;
}


