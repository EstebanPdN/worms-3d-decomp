#include "w3d_ptr.h"
#line 1 "s1_session_modes.cpp"
/* Observed session mode requests and frontend messages. */
extern "C" {
union W3dS1ModeFlags {unsigned int raw;struct {unsigned int tail:6; unsigned int second:1; unsigned int first:1; unsigned int unused:24;} bits;};
struct W3dS1ModeContext {char unknown[188];W3dS1ModeFlags flags;};
struct W3dS1ModeMessage {unsigned short id,reserved;Ptr32<void> vtable;};
extern Ptr32<W3dS1ModeContext> w3d_context_804b1788;
extern Ptr32<void> w3d_queue_804b1754; extern Ptr32<void> w3d_manager_804b178c;
extern unsigned char w3d_type_8040fa58[],w3d_vtable_8040db38[];
extern unsigned int w3d_message_804ad7a4,w3d_message_804ad7b4,w3d_message_804ad7bc,w3d_message_804ad7c4,w3d_message_804ad754,w3d_message_804ad74c,w3d_message_804ad7ac;
extern const char w3d_str_8037bb14[],w3d_str_8037bd3c[],w3d_str_8037bb04[],w3d_str_8037bb18[],w3d_str_8037bb28[];
Ptr32<void> w3d_fn_8020b680(Ptr32<void>);
int w3d_fn_80164514(Ptr32<void>,Ptr32<void>,unsigned int);
Ptr32<W3dS1ModeMessage> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
int w3d_message_post_current(Ptr32<void>);
Ptr32<void> w3d_message_string_init(Ptr32<void>,unsigned short,Ptr32<const char>);
void w3d_fn_8006ab48(Ptr32<void>,unsigned int,unsigned int,int,int);
void w3d_fn_800a7ea0(void);
void w3d_fn_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
static inline void mode_create(Ptr32<unsigned int> self)
{
    self[60]|=0x02000000;
    Ptr32<void> type=w3d_fn_8020b680(w3d_type_8040fa58);
    w3d_fn_80164514(w3d_manager_804b178c,type,self[5]);
}
static inline void mode_post(Ptr32<unsigned int> id)
{
    Ptr32<W3dS1ModeMessage> message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);message->vtable=w3d_vtable_8040db38;
    w3d_message_post_current(message);
}
void w3d_fn_8006b53c(Ptr32<unsigned int> self)
{
    W3dS1ModeFlags flags=w3d_context_804b1788->flags;
    if(!flags.bits.first)goto fallback;
    if(!flags.bits.second)goto fallback;
    mode_create(self);mode_post(&w3d_message_804ad7a4);goto finish;
fallback:w3d_fn_8006ab48(self,2,1,0,0);
finish:
    self[52]=1;
}
void w3d_fn_8006b5fc(Ptr32<unsigned int> self)
{
    W3dS1ModeFlags flags=w3d_context_804b1788->flags;
    if(!flags.bits.first)goto fallback;
    if(!flags.bits.second)goto fallback;
    mode_create(self);mode_post(&w3d_message_804ad7b4);goto finish;
fallback:w3d_fn_8006ab48(self,5,1,0,0);
finish:
    self[52]=2;
}
void w3d_fn_8006b6bc(Ptr32<unsigned int> self)
{
    W3dS1ModeFlags flags=w3d_context_804b1788->flags;
    if(!flags.bits.first)goto fallback;
    if(!flags.bits.second)goto fallback;
    mode_create(self);mode_post(&w3d_message_804ad7bc);goto finish;
fallback:w3d_fn_8006ab48(self,5,1,0,0);
finish:
    self[52]=3;
}
void w3d_fn_8006b77c(Ptr32<unsigned int> self)
{
    if(w3d_context_804b1788->flags.raw&64) {
        mode_create(self);mode_post(&w3d_message_804ad7c4);w3d_fn_800a7ea0();
        Ptr32<void> first=w3d_fn_801613f0(w3d_queue_804b1754,12);
        unsigned short id1=w3d_cached_message_id(&w3d_message_804ad754,1);
        w3d_message_post_current(w3d_message_string_init(first,id1,w3d_str_8037bb14));
        Ptr32<void> second=w3d_fn_801613f0(w3d_queue_804b1754,12);
        unsigned short id2=w3d_cached_message_id(&w3d_message_804ad74c,1);
        w3d_message_post_current(w3d_message_string_init(second,id2,w3d_str_8037bd3c));
    } else w3d_fn_8006ab48(self,9,1,0,0);
    self[52]=8;
}
static inline Ptr32<Ptr32<const char>> mode_read(Ptr32<Ptr32<const char>> key,Ptr32<Ptr32<const char>> value) {w3d_fn_800fc2b0(key,value);return value;}
#if 0 /* Excluded: two saved registers and pointer setup remain different after four attempts. */
void w3d_fn_8006b8a0(unsigned int *self)
{
    const char *first,*name,*second,*third;
    const char **first_key=&first;
    int found=0;name=0;
    first=w3d_str_8037bb04;
    const char **value=mode_read(first_key,&name);
    if(name && *name)found=1;
    second=w3d_str_8037bb18;w3d_fn_800fc2b0(&second,value);
    if(name && *name)found=1;
    third=w3d_str_8037bb28;w3d_fn_800fc2b0(&third,value);
    if(name && *name)found=1;
    if((w3d_context_804b1788->flags.raw&64) && found) {mode_create(self);mode_post(&w3d_message_804ad7ac);}
    else w3d_fn_8006ab48(self,6,1,0,0);
    self[52]=9;
}
#endif
}


