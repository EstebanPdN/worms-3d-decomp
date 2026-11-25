#include "w3d_ptr.h"
#line 1 "s4_card_check.cpp"
/* Observed card-save recovery checks and space-related prompts. */
extern "C" {
struct CheckFile { char name[32]; int size; };
struct CheckGuide { int channel; Ptr32<CheckFile> file; int input; int state; char pad[28]; char temporary[32]; int tempNumber; char original[32]; int oldNumber; int hasSpace; int checkSpace; };
struct CheckInfo { int channel; int number; char pad[12]; };
struct CheckStatus { char pad[32]; unsigned size; char gap[20]; unsigned offset; char tail[48]; };
void w3d_report_802fb7ac(Ptr32<const char>,...);
void w3d_panic_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);
Ptr32<char> strcpy(Ptr32<char>,Ptr32<const char>);
Ptr32<void> w3d_format_802ec254(Ptr32<char>,Ptr32<const char>,...);
int w3d_card_open_803177b0(int,Ptr32<const char>,Ptr32<CheckInfo>);
int w3d_card_status_803188c0(int,int,Ptr32<CheckStatus>);
int w3d_card_delete_80318680(int,int);
int w3d_card_rename_80318d8c(int,Ptr32<const char>,Ptr32<const char>);
int w3d_card_free_8031499c(int,Ptr32<int>,Ptr32<int>);
void w3d_fn_802ae2dc(int);
extern const char w3d_str_803d74e4[],w3d_str_803d74fc[],w3d_str_803d7524[],w3d_str_803d752c[],w3d_str_803d7540[],w3d_str_803d7558[],w3d_str_803d7570[],w3d_str_803d7588[],w3d_str_803d759c[];
extern const char w3d_str_803d75b4[],w3d_str_803d75dc[],w3d_str_803d7604[];
void w3d_s4_card_check_begin(Ptr32<CheckGuide> self)
{
    register Ptr32<char> original=self->original;
    strcpy(original,(Ptr32<char>)self->file);
    w3d_format_802ec254(self->temporary,w3d_str_803d7524,33,w3d::VA(original));
    self->state=209;
}
void w3d_s4_card_check_open_old(Ptr32<CheckGuide> self)
{
    CheckInfo info;
    int result=w3d_card_open_803177b0(self->channel,self->original,&info);
    self->oldNumber=result==0 ? info.number:-1;
    w3d_report_802fb7ac(w3d_str_803d752c,result);
    switch(result) {
    case -1:self->state=209;break;
    case -4:case 0:self->state=210;break;
    default:w3d_report_802fb7ac(w3d_str_803d7540,result);self->state=0;break;
    }
}
void w3d_s4_card_check_open_temp(Ptr32<CheckGuide> self)
{
    CheckInfo info;
    int result=w3d_card_open_803177b0(self->channel,self->temporary,&info);
    self->tempNumber=result==0 ? info.number:-1;
    w3d_report_802fb7ac(w3d_str_803d752c,result);
    switch(result) {
    case -1:self->state=210;break;
    case 0:self->state=211;break;
    case -4:
        if(self->tempNumber==-1 && self->oldNumber==-1) self->state=215;
        else self->state=1;
        break;
    default:w3d_report_802fb7ac(w3d_str_803d7540,result);self->state=0;break;
    }
}
void w3d_s4_card_check_status(Ptr32<CheckGuide> self)
{
    CheckStatus status;
    int result=w3d_card_status_803188c0(self->channel,self->tempNumber,&status);
    w3d_report_802fb7ac(w3d_str_803d7558,result);
    switch(result) {
    case -1:self->state=211;break;
    case 0:if(status.offset<=status.size-64) self->state=212;else self->state=214;break;
    default:w3d_report_802fb7ac(w3d_str_803d7540,result);self->state=0;break;
    }
}
void w3d_s4_card_check_delete_old(Ptr32<CheckGuide> self)
{
    int result;
    if(self->oldNumber==-1) result=0;
    else result=w3d_card_delete_80318680(self->channel,self->oldNumber);
    w3d_report_802fb7ac(w3d_str_803d7570,result);
    switch(result) {
    case -1:self->state=212;break;
    case 0:self->state=213;break;
    default:w3d_report_802fb7ac(w3d_str_803d7540,result);self->state=0;break;
    }
}
void w3d_s4_card_check_restore(Ptr32<CheckGuide> self)
{
    int result=w3d_card_rename_80318d8c(self->channel,self->temporary,self->original);
    if(result==0) self->oldNumber=self->tempNumber;
    w3d_report_802fb7ac(w3d_str_803d7588,result);
    switch(result) {
    case -1:self->state=213;break;
    case 0:self->state=1;break;
    default:w3d_report_802fb7ac(w3d_str_803d7540,result);self->state=0;break;
    }
}
void w3d_s4_card_check_delete_temp(Ptr32<CheckGuide> self)
{
    int result;
    if(self->tempNumber==-1) result=0;
    else result=w3d_card_delete_80318680(self->channel,self->tempNumber);
    w3d_report_802fb7ac(w3d_str_803d7570,result);
    switch(result) {
    case -1:self->state=214;break;
    case 0:self->state=1;break;
    default:w3d_report_802fb7ac(w3d_str_803d7540,result);self->state=0;break;
    }
}
void w3d_s4_card_check_space(Ptr32<CheckGuide> self)
{
    int bytes,files;
    if(self->checkSpace==0) {self->state=1;return;}
    int result=w3d_card_free_8031499c(self->channel,&bytes,&files);
    int required=self->file->size;
    w3d_report_802fb7ac(w3d_str_803d759c,result);
    if(result==-3) goto unexpected;
    if(result<=-3) goto unexpected;
    if(result==-1) goto retry;
    if(result==0) goto ready;
    goto unexpected;
retry:
    self->state=215;return;
ready:
    if(files>0 && bytes>=required) self->state=1;
    else if(self->hasSpace) self->state=-28;
    else self->state=-29;
    return;
unexpected:
    w3d_report_802fb7ac(w3d_str_803d7540,result);
    self->state=0;
}
void w3d_s4_card_check_delete_message(Ptr32<CheckGuide> self)
{
    switch(self->input) {
    case 1:self->state=214;break;
    case 0:self->state=-27;break;
    default:w3d_panic_802fb82c(w3d_str_803d74e4,572,w3d_str_803d75b4);break;
    }
}
void w3d_s4_card_check_space_message(Ptr32<CheckGuide> self)
{
    switch(self->input) {
    case 3:self->state=2;break;
    case 4:self->state=208;break;
    case 5:self->state=4;break;
    case 0:self->state=-28;break;
    default:w3d_panic_802fb82c(w3d_str_803d74e4,606,w3d_str_803d75dc);break;
    }
}
void w3d_s4_card_check_initial_space_message(Ptr32<CheckGuide> self)
{
    switch(self->input) {
    case 3:self->state=2;break;
    case 4:self->state=208;break;
    case 5:self->state=4;break;
    case 0:self->state=-29;break;
    default:w3d_panic_802fb82c(w3d_str_803d74e4,640,w3d_str_803d7604);break;
    }
}
int w3d_s4_card_check_step(Ptr32<CheckGuide> self,int checkSpace)
{
    self->checkSpace=checkSpace;
    w3d_fn_802ae2dc(self->state);
    switch(self->state) {
    case 208:w3d_s4_card_check_begin(self);return -1;
    case 209:w3d_s4_card_check_open_old(self);return -1;
    case 210:w3d_s4_card_check_open_temp(self);return -1;
    case 211:w3d_s4_card_check_status(self);return -1;
    case 212:w3d_s4_card_check_delete_old(self);return -1;
    case 213:w3d_s4_card_check_restore(self);return -1;
    case 214:w3d_s4_card_check_delete_temp(self);return -1;
    case 215:w3d_s4_card_check_space(self);return -1;
    case -27:w3d_s4_card_check_delete_message(self);return -27;
    case -29:w3d_s4_card_check_initial_space_message(self);return -29;
    case -28:w3d_s4_card_check_space_message(self);return -28;
    case 4:self->state=208;return 4;
    case 1:{int number=self->oldNumber;self->state=208;if(number==-1) return 3;return 1;}
    case 2:self->state=208;return 2;
    case 0:self->state=208;return 0;
    default:w3d_panic_802fb82c(w3d_str_803d74e4,161,w3d_str_803d74fc);return 0;
    }
}
}


