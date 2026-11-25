// Observed float outputs and word flags use PPC32 small-data access; constants are far arrays.
extern const float constant_8037cf44[];
extern const float constant_8037cf48[];
extern volatile unsigned int flags_804addec;
extern volatile float output_804adb38;
extern volatile unsigned int flags_804addf0;
extern volatile float output_804adb3c;
extern volatile unsigned int flags_804addf4;
extern volatile float output_804adb40;
extern volatile unsigned int flags_804addf8;
extern volatile float output_804adb44;
extern volatile unsigned int flags_804addfc;
extern volatile float output_804adb48;
extern volatile unsigned int flags_804ade00;
extern volatile float output_804adb4c;
extern volatile unsigned int flags_804ade04;
extern volatile float output_804adb50;
extern volatile unsigned int flags_804ade08;
extern volatile float output_804adb54;
extern "C" void w3d_cx10a_flag_scales_80086160(){
output_804adb38=(flags_804addec&0xee)==0?constant_8037cf44[0]:constant_8037cf48[0];
output_804adb3c=(flags_804addf0&0xdd)==0?constant_8037cf44[0]:constant_8037cf48[0];
output_804adb40=(flags_804addf4&0xbb)==0?constant_8037cf44[0]:constant_8037cf48[0];
output_804adb44=(flags_804addf8&0x77)==0?constant_8037cf44[0]:constant_8037cf48[0];
output_804adb48=(flags_804addfc&0xee)==0?constant_8037cf44[0]:constant_8037cf48[0];
output_804adb4c=(flags_804ade00&0xdd)==0?constant_8037cf44[0]:constant_8037cf48[0];
output_804adb50=(flags_804ade04&0xbb)==0?constant_8037cf44[0]:constant_8037cf48[0];
if((flags_804ade08&0x77)==0){output_804adb54=constant_8037cf44[0];return;}output_804adb54=constant_8037cf48[0];return;
}
