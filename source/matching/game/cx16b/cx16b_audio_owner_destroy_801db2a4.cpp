/* Original counted-interface and member cleanup. Offsets and calling flags
   are observed; semantic owner name is inferred from adjacent audio methods. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct Cx16bAudioHeld { void **vtable; };
struct Cx16bAudioRecord16 { unsigned words[4]; };
extern "C" {
extern char lbl_804168c0[],lbl_80416970[];
extern void *lbl_804ab80c;
void * fn_801dc6d8(void *);
void fn_80331a40();
void fn_801de574(void *,int);
void fn_80210abc(void *,int);
void fn_801daf5c(void *,int);
void fn_802134fc(void *);
void fn_80210990(void *,int);
void fn_801fe1f8(void *);
}
static inline void cx16b_audio_release(Cx16bAudioHeld *held){if(held)((void(*)(Cx16bAudioHeld *))held->vtable[4])(held);}
extern "C" void w3d_cx16b_audio_owner_destroy_801db2a4(char *self,int flags)
{
    FIELD(self,char *,0)=lbl_804168c0;
    fn_801dc6d8(self);
    unsigned index=0;
    if(index<FIELD(self,unsigned,48)){
        char *list=self+48;
        void *zero=0;
        unsigned offset=0;
        do{
            Cx16bAudioHeld **items=FIELD(list,Cx16bAudioHeld **,8);
            Cx16bAudioHeld **slot=(Cx16bAudioHeld **)(offset+(unsigned)items);
            cx16b_audio_release(*slot);
            *slot=(Cx16bAudioHeld *)zero;
            ++index;offset+=4;
        }while(index<FIELD(self,unsigned,48));
    }
    {
        void *zero=0;
        cx16b_audio_release(FIELD(self,Cx16bAudioHeld *,172));
        FIELD(self,void *,172)=zero;
        fn_80331a40();
        Cx16bAudioHeld *held=FIELD(self,Cx16bAudioHeld *,172);
        FIELD(self,void *,176)=zero;
        lbl_804ab80c=zero;
        cx16b_audio_release(held);
    }
    fn_801de574(self+124,2);
    {
        char *records=self+60;
        fn_80210abc(self+76,2);
        char *list=self+48;
        Cx16bAudioRecord16 *end=FIELD(records,Cx16bAudioRecord16 *,4);
        char *other=self+36;
        Cx16bAudioRecord16 *begin=FIELD(self,Cx16bAudioRecord16 *,60);
        char *base=self+4;
        for(Cx16bAudioRecord16 *p=begin;p!=end;++p)fn_801daf5c(p,2);
        if(FIELD(records,void *,0))fn_802134fc(FIELD(records,void *,0));
        fn_80210abc(list,2);
        fn_80210abc(other,2);
        FIELD(self,char *,0)=lbl_80416970;
        fn_80210990(base,0);
    }
    if(flags&1)fn_801fe1f8(self);
}
