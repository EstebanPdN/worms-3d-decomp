#include "w3d_ptr.h"
#line 1 "s4_card_save.cpp"
/* Observed card-save state machine, file operations, and user prompts. */
extern "C" {
#define FIELD(p,t,o) (*(w3d::slot_t<t> *)w3d::AG((char *)w3d::AG(p)+(o)))
struct SaveFile { char name[32]; unsigned size; Ptr32<void> buffer; };
struct SaveGuide { int channel; int input; Ptr32<SaveFile> file; int state; char temporary[32]; char info[20]; int newNumber; char status[108]; char original[32]; char oldInfo[20]; int oldNumber; int created; };
void w3d_report_802fb7ac(Ptr32<const char>,...);
void w3d_panic_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);
Ptr32<char> strcpy(Ptr32<char>,Ptr32<const char>);
Ptr32<void> w3d_format_802ec254(Ptr32<char>,Ptr32<const char>,...);
unsigned w3d_checksum_802ad978(Ptr32<void>,unsigned);
void w3d_cache_flush_802fa988(Ptr32<void>,unsigned);
int w3d_card_open_803177b0(int,Ptr32<const char>,Ptr32<void>);
int w3d_card_create_80317c78(int,Ptr32<const char>,unsigned,Ptr32<void>);
int w3d_card_status_803188c0(int,int,Ptr32<void>);
int w3d_card_write_80318468(Ptr32<void>,Ptr32<void>,unsigned,int);
int w3d_card_close_803178cc(Ptr32<void>);
int w3d_card_delete_80318680(int,int);
int w3d_card_rename_80318d8c(int,Ptr32<const char>,Ptr32<const char>);
void w3d_fn_802ad0d4(Ptr32<SaveGuide>);
void w3d_fn_802ad6b8(int);
extern const char w3d_str_803d7054[],w3d_str_803d706c[],w3d_str_803d70b8[],w3d_str_803d70c0[],w3d_str_803d70d4[],w3d_str_803d70ec[],w3d_str_803d7100[],w3d_str_803d7118[],w3d_str_803d712c[],w3d_str_803d7140[];
extern const char w3d_str_803d7154[],w3d_str_803d7180[],w3d_str_803d71a8[],w3d_str_803d71d0[],w3d_str_803d71f8[];
void w3d_s4_card_save_begin(Ptr32<SaveGuide> self)
{
    register Ptr32<char> original=self->original;
    strcpy(original,(Ptr32<char>)self->file);
    w3d_format_802ec254(self->temporary,w3d_str_803d70b8,33,w3d::VA(original));
    self->oldNumber=-1;
    self->newNumber=-1;
    Ptr32<void> buffer=self->file->buffer;
    unsigned size=self->file->size;
    unsigned sum=FIELD(buffer,unsigned,8)+FIELD(buffer,unsigned,4);
    FIELD(buffer,unsigned,0)=0;
    unsigned amount=size;
    if(sum<=size) amount=sum;
    FIELD(buffer,unsigned,0)=w3d_checksum_802ad978(buffer,amount);
    w3d_cache_flush_802fa988(buffer,size);
    self->state=225;
    self->created=1;
}
void w3d_s4_card_save_open(Ptr32<SaveGuide> self)
{
    int result=w3d_card_open_803177b0(self->channel,self->original,self->oldInfo);
    w3d_report_802fb7ac(w3d_str_803d70c0,result);
    if(result==0) self->oldNumber=FIELD(self,int,216);
    else if(result==-4) self->oldNumber=-1;
    switch(result) {
    case -1:self->state=225;break;
    case -4:self->state=-55;break;
    case 0:self->state=-59;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_create(Ptr32<SaveGuide> self)
{
    int result=w3d_card_create_80317c78(self->channel,self->temporary,self->file->size,self->info);
    w3d_report_802fb7ac(w3d_str_803d70ec,result);
    if(result==0) self->newNumber=FIELD(self,int,52);
    switch(result) {
    case -1:self->state=226;break;
    case 0:self->state=227;break;
    case -8:case -9:self->created=0;self->state=234;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_status(Ptr32<SaveGuide> self)
{
    int result;
    if(self->created) result=w3d_card_status_803188c0(self->channel,self->newNumber,self->status);
    else result=w3d_card_status_803188c0(self->channel,self->oldNumber,self->status);
    w3d_report_802fb7ac(w3d_str_803d7100,result);
    switch(result) {
    case -1:self->state=227;break;
    case 0:if(self->created) self->state=228;else self->state=234;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_write_new(Ptr32<SaveGuide> self)
{
    int result=w3d_card_write_80318468(self->info,self->file->buffer,self->file->size,0);
    w3d_report_802fb7ac(w3d_str_803d7118,result);
    switch(result) {
    case -1:self->state=228;break;
    case 0:self->state=229;break;
    case -5:self->state=-56;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_write_old(Ptr32<SaveGuide> self)
{
    int result=w3d_card_write_80318468(self->oldInfo,self->file->buffer,self->file->size,0);
    w3d_report_802fb7ac(w3d_str_803d7118,result);
    switch(result) {
    case -1:self->state=234;break;
    case 0:self->state=229;break;
    case -5:self->state=-56;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_close_new(Ptr32<SaveGuide> self)
{
    int result=w3d_card_close_803178cc(self->info);
    w3d_report_802fb7ac(w3d_str_803d712c,result);
    switch(result) {
    case -1:self->state=230;break;
    case 0:self->state=231;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_delete_old(Ptr32<SaveGuide> self)
{
    int result;
    if(self->oldNumber==-1) result=0;
    else result=w3d_card_delete_80318680(self->channel,self->oldNumber);
    switch(result) {
    case -1:self->state=231;break;
    case 0:self->state=232;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_rename(Ptr32<SaveGuide> self)
{
    int result=w3d_card_rename_80318d8c(self->channel,self->temporary,self->original);
    w3d_report_802fb7ac(w3d_str_803d7140,result);
    switch(result) {
    case -1:self->state=232;break;
    case 0:self->state=233;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_close_old(Ptr32<SaveGuide> self)
{
    int result;
    if(self->oldNumber==-1) result=0;
    else result=w3d_card_close_803178cc(self->oldInfo);
    w3d_report_802fb7ac(w3d_str_803d712c,result);
    switch(result) {
    case -1:self->state=233;break;
    case 0:self->state=-58;break;
    default:w3d_report_802fb7ac(w3d_str_803d70d4,result);self->state=0;break;
    }
}
void w3d_s4_card_save_overwrite_message(Ptr32<SaveGuide> self)
{
    switch(self->input) {
    case 1:self->state=-55;break;
    case 2:self->state=1;break;
    case 0:self->state=-59;break;
    default:w3d_panic_802fb82c(w3d_str_803d7054,805,w3d_str_803d7154);break;
    }
}
void w3d_s4_card_save_done_message(Ptr32<SaveGuide> self)
{
    switch(self->input) {
    case 1:self->state=1;break;
    case 0:self->state=-58;break;
    default:w3d_panic_802fb82c(w3d_str_803d7054,833,w3d_str_803d7180);break;
    }
}
void w3d_s4_card_save_ready_message(Ptr32<SaveGuide> self)
{
    switch(self->input) {
    case 1:self->state=226;break;
    case 0:self->state=-55;break;
    default:w3d_panic_802fb82c(w3d_str_803d7054,861,w3d_str_803d71a8);break;
    }
}
void w3d_s4_card_save_failed_message(Ptr32<SaveGuide> self)
{
    switch(self->input) {
    case 1:self->state=2;break;
    case 0:self->state=-57;break;
    default:w3d_panic_802fb82c(w3d_str_803d7054,889,w3d_str_803d71d0);break;
    }
}
void w3d_s4_card_save_damaged_message(Ptr32<SaveGuide> self)
{
    switch(self->input) {
    case 4:self->state=0;break;
    case 3:self->state=2;break;
    case 0:self->state=-56;break;
    default:w3d_panic_802fb82c(w3d_str_803d7054,923,w3d_str_803d71f8);break;
    }
}
int w3d_s4_card_save_step(Ptr32<SaveGuide> self)
{
    w3d_fn_802ad6b8(self->state);
    switch(self->state) {
    case 224:w3d_s4_card_save_begin(self);return -1;
    case 225:w3d_s4_card_save_open(self);return -1;
    case -55:w3d_s4_card_save_ready_message(self);return -55;
    case 226:w3d_s4_card_save_create(self);return -2;
    case 227:w3d_s4_card_save_status(self);return -2;
    case 228:w3d_s4_card_save_write_new(self);return -2;
    case 229:w3d_fn_802ad0d4(self);return -2;
    case 230:w3d_s4_card_save_close_new(self);return -2;
    case 231:w3d_s4_card_save_delete_old(self);return -2;
    case 232:w3d_s4_card_save_rename(self);return -2;
    case 234:w3d_s4_card_save_write_old(self);return -2;
    case 233:w3d_s4_card_save_close_old(self);return -2;
    case 1:self->state=224;return 1;
    case 2:self->state=224;return 2;
    case 0:self->state=224;return 0;
    case -59:w3d_s4_card_save_overwrite_message(self);return -59;
    case -58:w3d_s4_card_save_done_message(self);return -58;
    case -57:w3d_s4_card_save_failed_message(self);return -57;
    case -56:w3d_s4_card_save_damaged_message(self);return -56;
    default:w3d_panic_802fb82c(w3d_str_803d7054,200,w3d_str_803d706c);return 0;
    }
}
}


