#include "w3d_ptr.h"
#line 1 "cx10a_direction_scales_80085ff8.cpp"
// Observed byte enable at +0x1e1; small-data flags and float outputs.
struct Cx10aFlagOwner {unsigned char unknown00[0x1e1];unsigned char enabled;};
extern const float constant_8037cf34[];
extern const float constant_8037cf38[];
extern const float constant_8037cf3c[];
extern const float constant_8037cf40[];
extern volatile unsigned int flags_804addec;
extern volatile unsigned int flags_804addfc;
extern volatile unsigned int flags_804addf8;
extern volatile unsigned int flags_804ade08;
extern volatile float output_804adaf4;
extern volatile float output_804adaf8;
extern volatile float output_804adafc;
extern volatile float output_804adb00;
extern volatile float output_804adb04;
extern volatile float output_804adb08;
extern volatile float output_804adb0c;
extern volatile float output_804adb10;
extern "C" void w3d_cx10a_direction_scales_80085ff8(Ptr32<Cx10aFlagOwner> self){
if(!self->enabled){
output_804adb0c=constant_8037cf34[0];output_804adb10=constant_8037cf38[0];
output_804adaf4=constant_8037cf34[0];output_804adaf8=constant_8037cf38[0];
output_804adafc=constant_8037cf34[0];output_804adb00=constant_8037cf38[0];
output_804adb04=constant_8037cf34[0];output_804adb08=constant_8037cf38[0];
return;}
output_804adafc=(flags_804addec&0x44)?constant_8037cf34[0]:constant_8037cf3c[0];
output_804adb0c=(flags_804addfc&0x44)?constant_8037cf34[0]:constant_8037cf3c[0];
output_804adaf4=(flags_804addec&0x22)?constant_8037cf34[0]:constant_8037cf3c[0];
output_804adb04=(flags_804addfc&0x22)?constant_8037cf34[0]:constant_8037cf3c[0];
output_804adb00=(flags_804addf8&0x22)?constant_8037cf38[0]:constant_8037cf40[0];
output_804adb10=(flags_804ade08&0x22)?constant_8037cf38[0]:constant_8037cf40[0];
output_804adaf8=(flags_804addf8&0x44)?constant_8037cf38[0]:constant_8037cf40[0];
if((flags_804ade08&0x44)){output_804adb08=constant_8037cf38[0];return;}output_804adb08=constant_8037cf40[0];return;
}


