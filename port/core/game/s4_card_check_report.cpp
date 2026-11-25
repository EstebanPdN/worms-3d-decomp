#include "w3d_ptr.h"
#line 1 "s4_card_check_report.cpp"
/* Reports changes in the card-file recovery-check state. */
extern "C" {
extern int w3d_last_state_804abc50;
void w3d_report_802fb7ac(Ptr32<const char>,...);
void w3d_panic_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);
extern const char w3d_str_803d74e4[],w3d_str_803d7818[];
extern const char w3d_str_803d7630[];
extern const char w3d_str_803d7650[];
extern const char w3d_str_803d7674[];
extern const char w3d_str_803d7698[];
extern const char w3d_str_803d76bc[];
extern const char w3d_str_803d76e0[];
extern const char w3d_str_803d7704[];
extern const char w3d_str_803d772c[];
extern const char w3d_str_803d774c[];
extern const char w3d_str_803d7768[];
extern const char w3d_str_803d7784[];
extern const char w3d_str_803d779c[];
extern const char w3d_str_803d77b4[];
extern const char w3d_str_803d77d4[];
extern const char w3d_str_803d77f8[];
void w3d_s4_card_check_report(int state)
{
    if(state!=w3d_last_state_804abc50) {
        w3d_last_state_804abc50=state;
        switch(state) {
        case 208:w3d_report_802fb7ac(w3d_str_803d7630);break;
        case 209:w3d_report_802fb7ac(w3d_str_803d7650);break;
        case 210:w3d_report_802fb7ac(w3d_str_803d7674);break;
        case 211:w3d_report_802fb7ac(w3d_str_803d7698);break;
        case 214:w3d_report_802fb7ac(w3d_str_803d76bc);break;
        case 212:w3d_report_802fb7ac(w3d_str_803d76e0);break;
        case 213:w3d_report_802fb7ac(w3d_str_803d7704);break;
        case 215:w3d_report_802fb7ac(w3d_str_803d772c);break;
        case 4:w3d_report_802fb7ac(w3d_str_803d774c);break;
        case 2:w3d_report_802fb7ac(w3d_str_803d7768);break;
        case 1:w3d_report_802fb7ac(w3d_str_803d7784);break;
        case 0:w3d_report_802fb7ac(w3d_str_803d779c);break;
        case -27:w3d_report_802fb7ac(w3d_str_803d77b4);break;
        case -29:w3d_report_802fb7ac(w3d_str_803d77d4);break;
        case -28:w3d_report_802fb7ac(w3d_str_803d77f8);break;
        default:w3d_panic_802fb82c(w3d_str_803d74e4,714,w3d_str_803d7818);break;
        }
    }
}
}


