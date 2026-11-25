#include "w3d_ptr.h"
#line 1 "s4_card_icons.cpp"
extern "C" {
struct S4Card { unsigned char pad[32]; Ptr32<void> buffer; unsigned char payload[660]; int bufferSize,slot,state; };
struct S4Cache { unsigned char data[8]; };
extern S4Cache w3d_cache_804b0c2c,w3d_cache_804b0c34,w3d_cache_804b0c3c;
extern int w3d_slot_804abb5c;
extern unsigned char w3d_card_callbacks_80466900[];
int w3d_cached_message_id(Ptr32<void>,int);
int w3d_subscribe_80162024(Ptr32<void>,Ptr32<unsigned short>,Ptr32<void>);
void w3d_card_platform_init_80314794(void);
Ptr32<void> w3d_aligned_allocate(int,int);
void w3d_aligned_release(Ptr32<void>);
void w3d_card_encode_80288bc8(Ptr32<void>,Ptr32<void>,Ptr32<void>);
void w3d_card_state_init_802ab990(Ptr32<void>,int,Ptr32<void>,Ptr32<void>);
void w3d_card_begin_8028a570(Ptr32<void>);
void w3d_s4_card_initialize(Ptr32<S4Card> self)
{
    unsigned short a,b,c;
    self->state=1;
    Ptr32<void> payload=self->payload;
    a=w3d_cached_message_id(&w3d_cache_804b0c2c,1);
    w3d_subscribe_80162024(self,&a,(Ptr32<char>)self+944);
    b=w3d_cached_message_id(&w3d_cache_804b0c34,1);
    w3d_subscribe_80162024(self,&b,(Ptr32<char>)self+948);
    c=w3d_cached_message_id(&w3d_cache_804b0c3c,1);
    w3d_subscribe_80162024(self,&c,(Ptr32<char>)self+952);
    w3d_card_platform_init_80314794();
    Ptr32<void> buffer=w3d_aligned_allocate(self->bufferSize,32);
    self->buffer=buffer;
    w3d_card_encode_80288bc8(self,buffer,payload);
    w3d_card_state_init_802ab990((Ptr32<char>)self+120,0,payload,w3d_card_callbacks_80466900);
    w3d_card_begin_8028a570(self);
    self->slot=w3d_slot_804abb5c;
}
void w3d_s4_card_release_buffer(Ptr32<S4Card> self)
{
    if(self->buffer) w3d_aligned_release(self->buffer);
}
void w3d_resource_scope_enter_8015aee8(int);
void w3d_resource_scope_leave_8015af24(int);
void w3d_card_copy_icon_80289088(Ptr32<void>,Ptr32<const char>,Ptr32<void>);
void w3d_flush_data_802fa988(Ptr32<void>,int);
extern const char w3d_str_803cf9c4[],w3d_str_803cf9d0[],w3d_str_803cf9dc[],w3d_str_803cf9e8[];
void w3d_s4_card_copy_icons(Ptr32<void> self,Ptr32<char> output)
{
    Ptr32<char> next=output+2048;
    w3d_resource_scope_enter_8015aee8(2);
    w3d_card_copy_icon_80289088(self,w3d_str_803cf9c4,output);
    w3d_card_copy_icon_80289088(self,w3d_str_803cf9d0,next);
    next+=2048;
    w3d_card_copy_icon_80289088(self,w3d_str_803cf9dc,next);
    w3d_card_copy_icon_80289088(self,w3d_str_803cf9e8,next+2048);
    w3d_flush_data_802fa988(output,8192);
    w3d_resource_scope_leave_8015af24(2);
}
struct S4Error { int code; unsigned char pad[52]; };
extern S4Error w3d_error_table_80401340[];
// Deferred: three table-address setup words differ after two attempts.
#if 0
S4Error *w3d_s4_card_find_error(void *,int code)
{
    S4Error *current=w3d_error_table_80401340;
    if(current->code!=-128) {
        unsigned int offset=0;
        do {
            if(*(int *)((char *)w3d_error_table_80401340+offset)==code) return current;
            offset+=56; ++current;
        } while(*(int *)((char *)w3d_error_table_80401340+offset)!=-128);
    }
    return 0;
}
#endif
}


