#include "w3d_ptr.h"
#line 1 "s4_spinner.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (void)>> vtable; };
struct S4Config { unsigned char pad[8]; unsigned char flags; char w3d_tag_rest[3]; unsigned char pad12[120]; Ptr32<char> enter; unsigned char pad136[24]; Ptr32<char> tick; };
struct S4Spinner {
    Ptr32<void> vtable; unsigned char pad4[24],base[12]; Ptr32<S4Config> config;
    unsigned char pad44[96]; int enabled; unsigned char pad144[32]; int active;
    unsigned char pad180[28]; Ptr32<Ptr32<void (void)>> secondary; Ptr32<void> texts[3]; Ptr32<S4Object> label; Ptr32<S4Object> color; Ptr32<S4Object> children[3];
    Ptr32<S4Object> o244; Ptr32<S4Object> o248; Ptr32<S4Object> o252; Ptr32<S4Object> o256; Ptr32<S4Object> o260; Ptr32<S4Object> o264; Ptr32<S4Object> o268; Ptr32<S4Object> o272; Ptr32<S4Object> o276; Ptr32<S4Object> current;
    int busy; unsigned int value; int up,down; unsigned int repeat,nextRepeat,limit; int editing;
};
struct S4Input { unsigned char pad[96]; unsigned int restBits:24; unsigned int editing:1; unsigned int padBits:7; };
extern Ptr32<S4Input> w3d_input_804aac54;
void w3d_spinner_base_step_802b0668(Ptr32<void>);
void w3d_spinner_base_reset_802b0fec(Ptr32<void>);
void w3d_selection_name_802b1258(Ptr32<const char>);
void w3d_selection_activate_802b0990(Ptr32<void>,int);
void w3d_spinner_refresh_8028c290(Ptr32<S4Spinner>);
void w3d_spinner_visibility_8028c160(Ptr32<S4Spinner>);
void w3d_text_destroy_8025e0c4(Ptr32<void>,int);
Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
Ptr32<void> w3d_constructor_native_cast(Ptr32<void>);
unsigned int w3d_auto_80178c48(Ptr32<void>);
unsigned int w3d_auto_80178d1c(Ptr32<void>);
int w3d_int_store_80178c54(Ptr32<void>,Ptr32<unsigned int>);
int w3d_float_store_80178d28(Ptr32<void>,Ptr32<unsigned int>);
void w3d_s4_spinner_increment(Ptr32<S4Spinner>,unsigned int,int);
void w3d_s4_spinner_decrement(Ptr32<S4Spinner>,unsigned int,int);
void w3d_spinner_update_controls_8028c64c(Ptr32<S4Spinner>);
void w3d_s4_spinner_clear_texts(Ptr32<S4Spinner>);
unsigned int w3d_s4_spinner_read_value(Ptr32<S4Spinner>);
void w3d_s4_spinner_write_value(Ptr32<S4Spinner>);
int w3d_s4_spinner_repeat_step(Ptr32<S4Spinner> self)
{
    w3d_spinner_base_step_802b0668(self->base);
    if(self->editing) {
        if(self->repeat<=4) {
            if(self->nextRepeat<=7) self->nextRepeat=8;
            else --self->nextRepeat;
            self->repeat=self->nextRepeat;
            if(self->up) w3d_s4_spinner_increment(self,1,1);
            else w3d_s4_spinner_decrement(self,1,1);
        } else --self->repeat;
    }
    return 0;
}
void w3d_s4_spinner_reset(Ptr32<S4Spinner> self)
{
    register int zero=0;
    w3d_spinner_base_reset_802b0fec(self->base);
    if(self->o276) ((Ptr32<void (Ptr32<S4Object>)>)self->o276->vtable[4])(self->o276);
    self->editing=zero;
    *(Ptr32<int>)&self->o276=zero;
    w3d_input_804aac54->editing=zero;
    w3d_s4_spinner_clear_texts(self);
}
void w3d_s4_spinner_set_active(Ptr32<S4Spinner> self,int active)
{
    if(self->active!=active) {
        if(active) {
            Ptr32<S4Config> config=self->config;
            if(*(Ptr32<unsigned short>)(config->enter-4) && ((config->flags^4)&4) && self->enabled)
                w3d_selection_name_802b1258(config->enter);
        } else {
            self->editing=active;
            w3d_input_804aac54->editing=active;
        }
    }
    w3d_selection_activate_802b0990(self->base,active);
    w3d_spinner_update_controls_8028c64c(self);
    w3d_spinner_visibility_8028c160(self);
}
void w3d_s4_spinner_increment(Ptr32<S4Spinner> self,unsigned int amount,int)
{
    unsigned int old=self->value;
    Ptr32<char> tick=self->config->tick;
    if(*(Ptr32<unsigned short>)(tick-4)) ((Ptr32<void (Ptr32<void>, Ptr32<char>)>)self->secondary[7])(self->base,tick);
    unsigned int next=self->value+amount;
    unsigned int max=self->limit-1;
    if(next>max) self->value=max; else self->value=next;
    if(self->value==old) self->value=0;
    w3d_spinner_refresh_8028c290(self);
    if(old!=self->value) w3d_s4_spinner_write_value(self);
}
void w3d_s4_spinner_decrement(Ptr32<S4Spinner> self,unsigned int amount,int)
{
    unsigned int old=self->value;
    Ptr32<char> tick=self->config->tick;
    if(*(Ptr32<unsigned short>)(tick-4)) ((Ptr32<void (Ptr32<void>, Ptr32<char>)>)self->secondary[7])(self->base,tick);
    if(amount>self->value) self->value=self->limit-1;
    else self->value-=amount;
    w3d_spinner_refresh_8028c290(self);
    if(old!=self->value) w3d_s4_spinner_write_value(self);
}
// Deferred: boolean register allocation differs after two attempts.
#if 0
void w3d_spinner_update_controls_8028c64c(S4Spinner *self)
{
    int editing=self->editing;
    register int active=self->active;
    int arrows=(editing!=0)&(active!=0);
    int text=((editing^1)&active)!=0;
    *(int *)((char *)self->o252+16)=text;
    *(int *)((char *)self->o256+16)=text;
    *(int *)((char *)self->o272+16)=arrows;
}
#endif
void w3d_s4_spinner_set_editing(Ptr32<S4Spinner> self,int editing)
{
    if(editing!=self->editing) {
        self->editing=editing;
        w3d_input_804aac54->editing=editing;
        self->repeat=25; self->nextRepeat=25;
        w3d_spinner_update_controls_8028c64c(self);
        if(!editing) {self->up=editing;self->down=editing;}
    }
}
int w3d_s4_spinner_value_changed(Ptr32<void>,Ptr32<S4Spinner> self)
{
    if(self->busy) return 0;
    w3d_s4_spinner_read_value(self);w3d_spinner_refresh_8028c290(self);
    return 0;
}
unsigned int w3d_s4_spinner_read_value(Ptr32<S4Spinner> self)
{
    unsigned int value;
    if(self->current) {
        int kind=((Ptr32<int (Ptr32<S4Object>)>)self->current->vtable[6])(self->current);
        switch(kind) {
        case 0: value=w3d_auto_80178c48(w3d_empty_803426b4(self->current));break;
        case 1: value=w3d_auto_80178d1c(w3d_constructor_native_cast(self->current));break;
        }
        unsigned int max=self->limit-1;
        if(value>max) value=max;
        self->value=value;
    }
    return self->value;
}
void w3d_s4_spinner_write_value(Ptr32<S4Spinner> self)
{
    self->busy=1;
    if(self->current) {
        int kind=((Ptr32<int (Ptr32<S4Object>)>)self->current->vtable[6])(self->current);
        switch(kind) {
        case 0: w3d_int_store_80178c54(w3d_empty_803426b4(self->current),&self->value);break;
        case 1: w3d_float_store_80178d28(w3d_constructor_native_cast(self->current),&self->value);break;
        }
    }
    self->busy=0;
}
void w3d_s4_spinner_clear_texts(Ptr32<S4Spinner> self)
{
    Ptr32<Ptr32<void>> entry=self->texts;
    unsigned int i=0;
    register int zero=0;
    do {
        Ptr32<void> text=*entry;
        ++i;
        if(text) {w3d_text_destroy_8025e0c4(text,3);*entry=(Ptr32<void>)w3d::G(zero);}
        ++entry;
    } while(i<=2);
}
}


