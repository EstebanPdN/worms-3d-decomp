#include "w3d_ptr.h"
#line 1 "cx7b_script_flag_set_8027a934.cpp"
// Observed fields: Lua state +32; cached state +40. Names are inferred.
struct Cx7bScriptFlag { char unknown00[32]; Ptr32<void> lua; int unknown24; int state; };
extern "C" void fn_802cd2e0(int, int);
extern "C" void w3d_cx7b_script_flag_set_8027a934(Ptr32<Cx7bScriptFlag> self,int state) {
 Ptr32<void> lua; int value;
 switch(state) { case 0: lua=self->lua; value=1; break; case 1: lua=self->lua; value=0; break; default: return; }
 fn_802cd2e0((int)w3d::H(lua),value); self->state=state;
}


