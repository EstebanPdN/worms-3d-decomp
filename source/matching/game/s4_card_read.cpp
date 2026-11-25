/* Observed card-file read operations and user-message transitions. */
extern "C" {
struct ReadFile { char name[32]; unsigned size; void *buffer; char pad[42]; unsigned char complete; };
struct ReadGuide { int channel; ReadFile *file; int input; int state; char info[20]; char status[108]; int number; int erase; };
struct ReadHeader { unsigned crc; int size; int extra; };
void w3d_report_802fb7ac(const char *,...);
void w3d_panic_802fb82c(const char *,int,const char *,...);
int w3d_card_open_803177b0(int,const char *,void *);
int w3d_card_status_803188c0(int,int,void *);
int w3d_card_read_803180ec(void *,void *,unsigned,int);
int w3d_card_close_803178cc(void *);
int w3d_card_delete_80318680(int,int);
void w3d_cache_invalidate_802fa95c(void *,unsigned);
int w3d_crc_check_802ad9c0(void *,unsigned,unsigned);
extern const char w3d_str_803d6cc4[],w3d_str_803d6d04[],w3d_str_803d6d18[],w3d_str_803d6d30[],w3d_str_803d6d48[],w3d_str_803d6d5c[],w3d_str_803d6d70[];
extern const char w3d_str_803d6d88[],w3d_str_803d6db4[],w3d_str_803d6ddc[],w3d_str_803d6e00[],w3d_str_803d6e28[];
void w3d_s4_card_read_open(ReadGuide *self)
{
    int result=w3d_card_open_803177b0(self->channel,(char *)self->file,self->info);
    w3d_report_802fb7ac(w3d_str_803d6d04,result);
    if(result==0) self->number=*(int *)((char *)self+20);
    else if(result==-4) self->number=-1;
    int state;
    switch(result) {
    case -4:state=-39;break;
    case -1:state=193;break;
    case 0:state=194;break;
    default:w3d_report_802fb7ac(w3d_str_803d6d18,result);state=0;break;
    }
    self->state=state;
}
void w3d_s4_card_read_status(ReadGuide *self)
{
    int result=w3d_card_status_803188c0(self->channel,self->number,self->status);
    w3d_report_802fb7ac(w3d_str_803d6d30,result);
    int state;
    switch(result) {
    case -1:state=194;break;
    case 0:state=195;break;
    default:w3d_report_802fb7ac(w3d_str_803d6d18,result);state=0;break;
    }
    self->state=state;
}
void w3d_s4_card_read_transfer(ReadGuide *self)
{
    int result=w3d_card_read_803180ec(self->info,self->file->buffer,self->file->size,0);
    w3d_report_802fb7ac(w3d_str_803d6d48,result);
    if(result==0) w3d_cache_invalidate_802fa95c(self->file->buffer,self->file->size);
    int state;
    switch(result) {
    case -1:state=195;break;
    case 0:state=196;break;
    default:w3d_report_802fb7ac(w3d_str_803d6d18,result);state=0;break;
    }
    self->state=state;
}
void w3d_s4_card_read_crc(ReadGuide *self)
{
    ReadHeader *header=(ReadHeader *)self->file->buffer;
    unsigned size=self->file->size;
    unsigned crc=header->crc;
    header->crc=0;
    int valid;
    if(header->size<=0 || header->extra<=0 || (unsigned)(header->size+header->extra)>size) valid=0;
    else valid=w3d_crc_check_802ad9c0(header,header->size+header->extra,crc);
    self->state=valid ? 197 : -38;
}
void w3d_s4_card_read_close(ReadGuide *self)
{
    int result=w3d_card_close_803178cc(self->info);
    if(result==0) self->file->complete=1;
    w3d_report_802fb7ac(w3d_str_803d6d5c,result);
    int state;
    switch(result) {
    case -1:state=197;break;
    case 0:state=-37;break;
    default:w3d_report_802fb7ac(w3d_str_803d6d18,result);state=0;break;
    }
    self->state=state;
}
void w3d_s4_card_read_delete(ReadGuide *self)
{
    int result=w3d_card_delete_80318680(self->channel,self->number);
    w3d_report_802fb7ac(w3d_str_803d6d70,result);
    switch(result) {
    case -1:self->state=198;break;
    case 0:
        if(self->erase==1) self->state=3;
        else self->state=-37;
        break;
    default:w3d_report_802fb7ac(w3d_str_803d6d18,result);self->state=0;break;
    }
}
void w3d_s4_card_read_corrupt_message(ReadGuide *self)
{
    switch(self->input) {
    case 1:self->erase=1;self->state=198;break;
    case 0:self->state=-38;break;
    default:w3d_panic_802fb82c(w3d_str_803d6cc4,497,w3d_str_803d6d88);break;
    }
}
void w3d_s4_card_read_missing_message(ReadGuide *self)
{
    switch(self->input) {
    case 1:self->state=3;break;
    case 4:self->state=192;break;
    case 0:self->state=-39;break;
    default:w3d_panic_802fb82c(w3d_str_803d6cc4,527,w3d_str_803d6db4);break;
    }
}
void w3d_s4_card_read_done_message(ReadGuide *self)
{
    switch(self->input) {
    case 1:self->state=1;break;
    case 0:self->state=-37;break;
    default:w3d_panic_802fb82c(w3d_str_803d6cc4,553,w3d_str_803d6ddc);break;
    }
}
void w3d_s4_card_read_failed_message(ReadGuide *self)
{
    switch(self->input) {
    case 1:self->state=2;break;
    case 0:self->state=-36;break;
    default:w3d_panic_802fb82c(w3d_str_803d6cc4,579,w3d_str_803d6e00);break;
    }
}
void w3d_s4_card_read_ready_message(ReadGuide *self)
{
    switch(self->input) {
    case 1:self->state=193;break;
    case 0:self->state=-34;break;
    default:w3d_panic_802fb82c(w3d_str_803d6cc4,605,w3d_str_803d6e28);break;
    }
}
}
