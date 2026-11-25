/* Observed memory-card command initialization and probe transitions. */
extern "C" {
#define FIELD(p,t,o) (*(t *)((char *)(p)+(o)))
void w3d_fn_802ad924(void *);
void memset(void *,int,...);
int w3d_auto_802abfdc(int);
int w3d_card_guide_step(void *);
void w3d_fn_802abd94(void *);
void w3d_auto_802abedc(void *);
void w3d_auto_802abf58(void *);
void w3d_panic_802fb82c(const char *,int,const char *,...);
extern const char w3d_str_803d6c64[],w3d_str_803d6c7c[];
void w3d_s4_memguide_initialize(void *self,int channel,void *file,void *buffer)
{
    w3d_fn_802ad924(self);
    FIELD(self,int,4)=160;
    FIELD(self,int,0)=channel;
    FIELD(self,unsigned,12)=0xdeadf00dU;
    FIELD(self,int,20)=0;
    FIELD(self,void *,16)=file;
    FIELD(file,unsigned char,82)=0;
    memset(buffer,0,40960);
    FIELD(self,void *,40)=buffer;
}
#if 0 /* Initial field store scheduling differs after two checks. */
void w3d_s4_memguide_setup_command(void *self)
{
    int channel=FIELD(self,int,0);
    void *file=FIELD(self,void *,16);
    int command=FIELD(self,int,20);
    FIELD(self,int,36)=176;
    FIELD(self,int,64)=208;
    FIELD(self,int,168)=0;
    FIELD(self,int,188)=224;
    FIELD(self,int,428)=192;
    FIELD(self,int,8)=-1;
    FIELD(self,int,24)=channel;
    FIELD(self,int,52)=channel;
    FIELD(self,void *,56)=file;
    FIELD(self,int,176)=channel;
    FIELD(self,void *,184)=file;
    FIELD(self,int,416)=channel;
    FIELD(self,void *,420)=file;
    switch(command) {
    case 1: FIELD(self,int,4)=161;break;
    case 3: FIELD(self,int,4)=163;break;
    case 2: FIELD(self,int,4)=164;break;
    case 0: FIELD(self,int,4)=160;break;
    }
}
#endif
void w3d_s4_memguide_probe_step(void *self)
{
    int status=w3d_card_guide_step((char *)self+24);
    FIELD(self,int,8)=status;
    switch(status) {
    case 1:
        FIELD(self,int,12)=w3d_auto_802abfdc(FIELD(self,int,0));
        if(FIELD(self,int,20)==2) FIELD(self,int,4)=164;
        else FIELD(self,int,4)=162;
        break;
    case 2:
        if(FIELD(self,int,20)==2) {
            FIELD(self,int,4)=164;
            FIELD(self,int,428)=-36;
        } else if(FIELD(self,int,20)==3) {
            FIELD(self,int,4)=163;
            FIELD(self,int,188)=-57;
        } else FIELD(self,int,4)=status;
        break;
    }
}
#if 0 /* Return-value branch lowering differs after two checks. */
int w3d_s4_memguide_dispatch(void *self,int command)
{
    int serial=w3d_auto_802abfdc(FIELD(self,int,0));
    int prior=FIELD(self,int,12);
    if(prior!=(int)0xdeadf00dU && serial!=prior) FIELD(self,int,12)=serial;
    int state=FIELD(self,int,4);
    FIELD(self,int,28)=command;
    FIELD(self,int,60)=command;
    FIELD(self,int,424)=command;
    FIELD(self,int,180)=command;
    switch(state) {
    case 160:w3d_s4_memguide_setup_command(self);break;
    case 161:w3d_s4_memguide_probe_step(self);break;
    case 162:w3d_fn_802abd94(self);break;
    case 163:w3d_auto_802abedc(self);break;
    case 164:w3d_auto_802abf58(self);break;
    case 1:FIELD(self,int,4)=160;FIELD(self,int,20)=0;return 1;
    case 3:FIELD(self,int,4)=160;FIELD(self,int,20)=0;return 3;
    case 4:FIELD(self,int,4)=160;FIELD(self,int,20)=0;return 4;
    case 0:FIELD(self,int,20)=0;FIELD(self,int,4)=160;return 0;
    case 2:FIELD(self,int,20)=0;FIELD(self,int,4)=161;FIELD(self,int,12)=0;return 2;
    default:w3d_panic_802fb82c(w3d_str_803d6c64,264,w3d_str_803d6c7c);return 0;
    }
    int result=FIELD(self,int,8);
    int answer=-1;
    if(result<0) answer=result;
    return answer;
}
#endif
}
