#include "w3d_ptr.h"
#line 1 "cx16b_audio_owner_destroy_801db2a4.cpp"
/* Original counted-interface and member cleanup. Offsets and calling flags
   are observed; semantic owner name is inferred from adjacent audio methods. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
struct Cx16bAudioHeld { Ptr32<Ptr32<void>> vtable; };
struct Cx16bAudioRecord16 { unsigned words[4]; };
extern "C" {
extern char lbl_804168c0[],lbl_80416970[];
extern Ptr32<void> lbl_804ab80c;
Ptr32<void> fn_801dc6d8(Ptr32<void>);
void fn_80331a40();
void fn_801de574(Ptr32<void>,int);
void fn_80210abc(Ptr32<void>,int);
void fn_801daf5c(Ptr32<void>,int);
void fn_802134fc(Ptr32<void>);
void fn_80210990(Ptr32<void>,int);
void fn_801fe1f8(Ptr32<void>);
}
static inline void cx16b_audio_release(Ptr32<Cx16bAudioHeld> held){if(held)((Ptr32<void (Ptr32<Cx16bAudioHeld>)>)held->vtable[4])(held);}
extern "C" void w3d_cx16b_audio_owner_destroy_801db2a4(Ptr32<char> self,int flags)
{
    FIELD(self,char *,0)=lbl_804168c0;
    fn_801dc6d8(self);
    unsigned index=0;
    if(index<FIELD(self,unsigned,48)){
        Ptr32<char> list=self+48;
        Ptr32<void> zero=0;
        unsigned offset=0;
        do{
            Ptr32<Ptr32<Cx16bAudioHeld>> items=FIELD(list,Cx16bAudioHeld **,8);
            Ptr32<Ptr32<Cx16bAudioHeld>> slot=(Ptr32<Ptr32<Cx16bAudioHeld>>)w3d::G((offset+(unsigned)w3d::H(items)));
            cx16b_audio_release(*slot);
            *slot=(Ptr32<Cx16bAudioHeld>)zero;
            ++index;offset+=4;
        }while(index<FIELD(self,unsigned,48));
    }
    {
        Ptr32<void> zero=0;
        cx16b_audio_release(FIELD(self,Cx16bAudioHeld *,172));
        FIELD(self,void *,172)=zero;
        fn_80331a40();
        Ptr32<Cx16bAudioHeld> held=FIELD(self,Cx16bAudioHeld *,172);
        FIELD(self,void *,176)=zero;
        lbl_804ab80c=zero;
        cx16b_audio_release(held);
    }
    fn_801de574(self+124,2);
    {
        Ptr32<char> records=self+60;
        fn_80210abc(self+76,2);
        Ptr32<char> list=self+48;
        Ptr32<Cx16bAudioRecord16> end=FIELD(records,Cx16bAudioRecord16 *,4);
        Ptr32<char> other=self+36;
        Ptr32<Cx16bAudioRecord16> begin=FIELD(self,Cx16bAudioRecord16 *,60);
        Ptr32<char> base=self+4;
        for(Ptr32<Cx16bAudioRecord16> p=begin;p!=end;++p)fn_801daf5c(p,2);
        if(FIELD(records,void *,0))fn_802134fc(FIELD(records,void *,0));
        fn_80210abc(list,2);
        fn_80210abc(other,2);
        FIELD(self,char *,0)=lbl_80416970;
        fn_80210990(base,0);
    }
    if(flags&1)fn_801fe1f8(self);
}


