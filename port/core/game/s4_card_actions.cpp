#include "w3d_ptr.h"
#line 1 "s4_card_actions.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (void)>> vtable; };
struct S4CardRecord { float x,y,z; int state,unknown; };
struct S4Card {
    Ptr32<Ptr32<void (void)>> vtable; unsigned char pad4[24]; int channel; Ptr32<void> buffer;
    unsigned char payload[84],controller[568]; int selected,unknown692,bufferSize,slot,state,unknown708;
    S4CardRecord records[8]; Ptr32<S4Object> first[8]; Ptr32<S4Object> second[5]; Ptr32<S4Object> held; int status;
    Ptr32<S4Object> o932; Ptr32<S4Object> o936; Ptr32<S4Object> o940; Ptr32<S4Object> o944; Ptr32<S4Object> o948; Ptr32<S4Object> o952; int recordCount,unknown960,unknown964;
    Ptr32<void> listing; Ptr32<const char> modeText; Ptr32<const char> slotText; Ptr32<const char> blocksText; Ptr32<S4Object> o984; Ptr32<S4Object> o988;
    unsigned char pad992[24]; unsigned int flags;
};
extern Ptr32<void> w3d_ui_handles_804aaabc;
extern int w3d_card_generation_804abb5c;
extern const float w3d_f32_803cfa44[];
extern const char w3d_str_803cfa48[],w3d_str_803cfa6c[];
void w3d_handles_set_enabled_8006ee88(Ptr32<void>,int);
void w3d_card_clear_resources_8028aab0(Ptr32<void>);
void w3d_card_prepare_8028a4a8(Ptr32<void>);
int w3d_auto_802aba18(Ptr32<void>,int);
void w3d_card_encode_80288bc8(Ptr32<void>,Ptr32<void>,Ptr32<void>);
void w3d_report_802fb7ac(Ptr32<const char>,...);
void w3d_set_name_800fc110(Ptr32<Ptr32<const char>>,Ptr32<void>,int,int);
void w3d_s4_card_reset(Ptr32<S4Card> self)
{
    int zero=0;
    Ptr32<Ptr32<S4Object>> entry=self->first;
    int remaining=8;
    w3d_handles_set_enabled_8006ee88(w3d_ui_handles_804aaabc,1);
    w3d_card_clear_resources_8028aab0(self);
    w3d_card_prepare_8028a4a8(self);
    self->flags &= ~0x04000000U;
    do {
        if(*entry) ((Ptr32<void (Ptr32<S4Object>)>)(*entry)->vtable[4])(*entry);
        *entry=(Ptr32<S4Object>)w3d::G(zero); ++entry;
    } while(--remaining);
    zero=0; entry=self->second; int remaining2=5;
    do {
        if(*entry) ((Ptr32<void (Ptr32<S4Object>)>)(*entry)->vtable[4])(*entry);
        *entry=(Ptr32<S4Object>)w3d::G(zero); ++entry;
    } while(--remaining2);
    if(self->held) ((Ptr32<void (Ptr32<S4Object>)>)self->held->vtable[4])(self->held);
    self->status=-1;
    self->held=(Ptr32<S4Object>)w3d::G(remaining2); self->recordCount=remaining2; self->unknown960=remaining2;
    self->listing=(Ptr32<void>)w3d::G(remaining2);
}
Ptr32<S4CardRecord> w3d_s4_card_add_record(Ptr32<S4Card> self)
{
    Ptr32<S4CardRecord> record=&self->records[self->recordCount];
    record->x=w3d_f32_803cfa44[0]; record->y=w3d_f32_803cfa44[0]; record->z=w3d_f32_803cfa44[0];
    record->state=0;
    ++self->recordCount;
    return record;
}
void w3d_s4_card_set_name(Ptr32<void>,Ptr32<const char> name,Ptr32<void> destination)
{
    w3d_set_name_800fc110(&name,destination,255,5);
}
void w3d_s4_card_check_boot(Ptr32<S4Card> self)
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
void w3d_s4_card_begin_load(Ptr32<S4Card> self)
{
    w3d_report_802fb7ac(w3d_str_803cfa6c);
    ++w3d_card_generation_804abb5c;
    w3d_card_prepare_8028a4a8(self);
    self->flags |= 0x10000000;
    w3d_auto_802aba18(self->controller,2);
    self->channel=-1;
}
}


