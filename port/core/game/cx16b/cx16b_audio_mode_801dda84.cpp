#include "w3d_ptr.h"
#line 1 "cx16b_audio_mode_801dda84.cpp"
/* Mode meanings are witnessed by the original diagnostic strings. */
struct Cx16bAudioMode { char unknown[88]; int mode; };
extern "C" {
extern const char str_803b0214[],str_803b0230[],str_803b0250[];
void fn_802fb7ac(Ptr32<const char>,...);
void fn_80322a5c(int);
void fn_802ff7b0(int);
int w3d_cx16b_audio_mode_801dda84(Ptr32<Cx16bAudioMode> self,int mode)
{
    switch(mode){
    case 0:fn_802fb7ac(str_803b0214);fn_80322a5c(0);fn_802ff7b0(0);break;
    case 1:fn_802fb7ac(str_803b0230);fn_80322a5c(1);fn_802ff7b0(1);break;
    case 2:fn_802fb7ac(str_803b0250);fn_80322a5c(2);fn_802ff7b0(1);break;
    }
    self->mode=mode;
    return 0;
}
}


