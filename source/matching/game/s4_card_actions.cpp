extern "C" {
struct S4Object { void (**vtable)(); };
struct S4CardRecord { float x,y,z; int state,unknown; };
struct S4Card {
    void (**vtable)(); unsigned char pad4[24]; int channel; void *buffer;
    unsigned char payload[84],controller[568]; int selected,unknown692,bufferSize,slot,state,unknown708;
    S4CardRecord records[8]; S4Object *first[8],*second[5],*held; int status;
    S4Object *o932,*o936,*o940,*o944,*o948,*o952; int recordCount,unknown960,unknown964;
    void *listing; const char *modeText,*slotText,*blocksText; S4Object *o984,*o988;
    unsigned char pad992[24]; unsigned int flags;
};
extern void *w3d_ui_handles_804aaabc;
extern int w3d_card_generation_804abb5c;
extern const float w3d_f32_803cfa44[];
extern const char w3d_str_803cfa48[],w3d_str_803cfa6c[];
void w3d_handles_set_enabled_8006ee88(void *,int);
void w3d_card_clear_resources_8028aab0(void *);
void w3d_card_prepare_8028a4a8(void *);
int w3d_auto_802aba18(void *,int);
void w3d_card_encode_80288bc8(void *,void *,void *);
void w3d_report_802fb7ac(const char *,...);
void w3d_set_name_800fc110(const char **,void *,int,int);
void w3d_s4_card_reset(S4Card *self)
{
    int zero=0;
    S4Object **entry=self->first;
    int remaining=8;
    w3d_handles_set_enabled_8006ee88(w3d_ui_handles_804aaabc,1);
    w3d_card_clear_resources_8028aab0(self);
    w3d_card_prepare_8028a4a8(self);
    self->flags &= ~0x04000000U;
    do {
        if(*entry) ((void (*)(S4Object *))(*entry)->vtable[4])(*entry);
        *entry=(S4Object *)zero; ++entry;
    } while(--remaining);
    zero=0; entry=self->second; int remaining2=5;
    do {
        if(*entry) ((void (*)(S4Object *))(*entry)->vtable[4])(*entry);
        *entry=(S4Object *)zero; ++entry;
    } while(--remaining2);
    if(self->held) ((void (*)(S4Object *))self->held->vtable[4])(self->held);
    self->status=-1;
    self->held=(S4Object *)remaining2; self->recordCount=remaining2; self->unknown960=remaining2;
    self->listing=(void *)remaining2;
}
S4CardRecord *w3d_s4_card_add_record(S4Card *self)
{
    S4CardRecord *record=&self->records[self->recordCount];
    record->x=w3d_f32_803cfa44[0]; record->y=w3d_f32_803cfa44[0]; record->z=w3d_f32_803cfa44[0];
    record->state=0;
    ++self->recordCount;
    return record;
}
void w3d_s4_card_set_name(void *,const char *name,void *destination)
{
    w3d_set_name_800fc110(&name,destination,255,5);
}
void w3d_s4_card_check_boot(S4Card *self)
{
    if(!(self->flags&0x02000000)) {
        w3d_auto_802aba18(self->controller,1);
        self->channel=-1;
        self->flags|=0x02000000;
    }
}
// Deferred: two argument-setup words differ after two attempts.
#if 0
void w3d_s4_card_begin_save(S4Card *self)
{
    w3d_report_802fb7ac(w3d_str_803cfa48);
    ++w3d_card_generation_804abb5c;
    w3d_card_prepare_8028a4a8(self);
    w3d_card_encode_80288bc8(self,self->buffer,self->payload);
    w3d_auto_802aba18((char *)self+120,3);
    self->channel=-1;
    ((void (*)(S4Card *,int))self->vtable[8])(self,0);
}
#endif
void w3d_s4_card_begin_load(S4Card *self)
{
    w3d_report_802fb7ac(w3d_str_803cfa6c);
    ++w3d_card_generation_804abb5c;
    w3d_card_prepare_8028a4a8(self);
    self->flags |= 0x10000000;
    w3d_auto_802aba18(self->controller,2);
    self->channel=-1;
}
}
