/* Observed card-save reporting and CRC table operations. */
extern "C" {
extern int w3d_last_state_804abc48;
extern unsigned w3d_crc_table_80471980[];
void w3d_report_802fb7ac(const char *,...);
void w3d_panic_802fb82c(const char *,int,const char *,...);
extern const char w3d_str_803d7054[],w3d_str_803d7474[],w3d_str_803d7494[];
extern const char w3d_str_803d7224[];
extern const char w3d_str_803d7244[];
extern const char w3d_str_803d7268[];
extern const char w3d_str_803d728c[];
extern const char w3d_str_803d72b0[];
extern const char w3d_str_803d72d4[];
extern const char w3d_str_803d72f8[];
extern const char w3d_str_803d731c[];
extern const char w3d_str_803d7340[];
extern const char w3d_str_803d7360[];
extern const char w3d_str_803d7384[];
extern const char w3d_str_803d73a8[];
extern const char w3d_str_803d73c0[];
extern const char w3d_str_803d73dc[];
extern const char w3d_str_803d73f4[];
extern const char w3d_str_803d7418[];
extern const char w3d_str_803d7434[];
extern const char w3d_str_803d7454[];
void w3d_s4_card_save_report(int state)
{
    if(state!=w3d_last_state_804abc48) {
        w3d_last_state_804abc48=state;
        switch(state) {
        case 224:
            w3d_report_802fb7ac(w3d_str_803d7224);break;
        case 225:
            w3d_report_802fb7ac(w3d_str_803d7244);break;
        case 226:
            w3d_report_802fb7ac(w3d_str_803d7268);break;
        case 227:
            w3d_report_802fb7ac(w3d_str_803d728c);break;
        case 228:
            w3d_report_802fb7ac(w3d_str_803d72b0);break;
        case 229:
            w3d_report_802fb7ac(w3d_str_803d72d4);break;
        case 230:
            w3d_report_802fb7ac(w3d_str_803d72f8);break;
        case 231:
            w3d_report_802fb7ac(w3d_str_803d731c);break;
        case 232:
            w3d_report_802fb7ac(w3d_str_803d7340);break;
        case 233:
            w3d_report_802fb7ac(w3d_str_803d7360);break;
        case 234:
            w3d_report_802fb7ac(w3d_str_803d7384);break;
        case 1:
            w3d_report_802fb7ac(w3d_str_803d73a8);break;
        case 2:
            w3d_report_802fb7ac(w3d_str_803d73c0);break;
        case 0:
            w3d_report_802fb7ac(w3d_str_803d73dc);break;
        case -59:
            w3d_report_802fb7ac(w3d_str_803d73f4);break;
        case -58:
            w3d_report_802fb7ac(w3d_str_803d7418);break;
        case -57:w3d_report_802fb7ac(w3d_str_803d7434);break;
        case -56:w3d_report_802fb7ac(w3d_str_803d7434);break;
        case -55:
            w3d_report_802fb7ac(w3d_str_803d7454);break;
        default:w3d_panic_802fb82c(w3d_str_803d7054,1007,w3d_str_803d7474);break;
        }
    }
}
void w3d_s4_crc_initialize(void)
{
    unsigned i=0;
    do {
        int value=i<<24;
        int bits=8;
        do {
            if(value<0) value=(value<<1)^0x04c11db7;
            else value<<=1;
        } while(--bits);
        w3d_crc_table_80471980[i++]=value;
    } while(i<=255);
}
unsigned w3d_s4_crc_compute(const unsigned char *data,unsigned size)
{
    unsigned crc=0;
    unsigned i=0;
    if(i<size) {
        do {
            unsigned char value=data[i];
            crc=(crc<<8)^w3d_crc_table_80471980[value^(crc>>24)];
            ++i;
        } while(i<size);
    }
    return crc;
}
#if 0 /* The success return is hoisted ahead of the comparison branch. */
int w3d_s4_crc_verify(const unsigned char *data,unsigned size,unsigned saved)
{
    unsigned crc=w3d_s4_crc_compute(data,size);
    if(saved==crc) goto matched;
    w3d_report_802fb7ac(w3d_str_803d7494,saved,crc);
    return 0;
matched:
    return 1;
}
#endif
}
