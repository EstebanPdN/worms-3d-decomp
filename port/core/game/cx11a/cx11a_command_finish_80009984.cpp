#include "w3d_ptr.h"
#line 1 "cx11a_command_finish_80009984.cpp"
// PPC32 context has float settings at +0x48/+0xe8. The command slot is cleared after release.
struct Cx11aSettings {unsigned char unknown00[0x48];float first;unsigned char unknown4c[0x9c];float second;};extern Ptr32<Cx11aSettings> settings_804aa6d8;extern int mode_804aa58c,ticks_804aa574;
extern const float divisor_803695b0[],multiplier_803695b4[];
extern "C" void append_80008d84(int),release_800089c8(Ptr32<void>);
extern "C" void w3d_cx11a_command_finish_80009984(Ptr32<Ptr32<void>> slot,int append){if(append){if(mode_804aa58c==0)append_80008d84((int)((settings_804aa6d8->first-(float)ticks_804aa574/divisor_803695b0[0])*multiplier_803695b4[0]));else append_80008d84((int)((settings_804aa6d8->second-(float)ticks_804aa574/divisor_803695b0[0])*multiplier_803695b4[0]));}release_800089c8(*slot);*slot=0;}


