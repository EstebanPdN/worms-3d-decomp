/* Reports changes in the card read state. */
extern "C" {
extern int w3d_last_state_804abc40;
void w3d_report_802fb7ac(const char *,...);
void w3d_panic_802fb82c(const char *,int,const char *,...);
extern const char w3d_str_803d6cc4[],w3d_str_803d7034[];
extern const char w3d_str_803d6e4c[];
extern const char w3d_str_803d6e6c[];
extern const char w3d_str_803d6e88[];
extern const char w3d_str_803d6ea8[];
extern const char w3d_str_803d6ecc[];
extern const char w3d_str_803d6ee8[];
extern const char w3d_str_803d6f0c[];
extern const char w3d_str_803d6f2c[];
extern const char w3d_str_803d6f4c[];
extern const char w3d_str_803d6f64[];
extern const char w3d_str_803d6f80[];
extern const char w3d_str_803d6f9c[];
extern const char w3d_str_803d6fb4[];
extern const char w3d_str_803d6fd8[];
extern const char w3d_str_803d6ff8[];
extern const char w3d_str_803d7014[];
void w3d_s4_card_read_report(int state)
{
    if(state!=w3d_last_state_804abc40) {
        w3d_last_state_804abc40=state;
        switch(state) {
        case 192:w3d_report_802fb7ac(w3d_str_803d6e4c);break;
        case 193:w3d_report_802fb7ac(w3d_str_803d6e6c);break;
        case -34:w3d_report_802fb7ac(w3d_str_803d6e88);break;
        case 194:w3d_report_802fb7ac(w3d_str_803d6ea8);break;
        case 195:w3d_report_802fb7ac(w3d_str_803d6ecc);break;
        case 196:w3d_report_802fb7ac(w3d_str_803d6ee8);break;
        case 197:w3d_report_802fb7ac(w3d_str_803d6f0c);break;
        case 198:w3d_report_802fb7ac(w3d_str_803d6f2c);break;
        case 1:w3d_report_802fb7ac(w3d_str_803d6f4c);break;
        case 3:w3d_report_802fb7ac(w3d_str_803d6f64);break;
        case 2:w3d_report_802fb7ac(w3d_str_803d6f80);break;
        case 0:w3d_report_802fb7ac(w3d_str_803d6f9c);break;
        case -38:w3d_report_802fb7ac(w3d_str_803d6fb4);break;
        case -39:w3d_report_802fb7ac(w3d_str_803d6fd8);break;
        case -37:w3d_report_802fb7ac(w3d_str_803d6ff8);break;
        case -36:w3d_report_802fb7ac(w3d_str_803d7014);break;
        default:w3d_panic_802fb82c(w3d_str_803d6cc4,684,w3d_str_803d7034);break;
        }
    }
}
}
