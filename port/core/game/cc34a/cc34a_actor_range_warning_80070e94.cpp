#include "w3d_ptr.h"
#line 1 "cc34a_actor_range_warning_80070e94.cpp"
// Observed actor range warning fields; raw sign-bit clearing is intentional.
struct cc34a_Actor_80070e94 { unsigned char p0[40]; float distance; unsigned char p44[40]; unsigned int deadline; unsigned char p88[104]; Ptr32<void> context; unsigned char p196[160]; unsigned int originalDeadline; Ptr32<void> text; };
struct cc34a_Config_80070e94 { unsigned char unknown[640]; float rate; };
struct cc34a_Cache_80070e94 { unsigned int words[2]; };
struct cc34a_Message_80070e94 { unsigned short id; unsigned short unknown; Ptr32<void> type; };
union cc34a_Float_80070e94 { unsigned int bits; float value; };
inline float cc34a_magnitude_80070e94(float value) { *(Ptr32<unsigned int>)&value &= 0x7fffffffU; return value; }
extern "C" {
Ptr32<void> cc34a_context_80341584(Ptr32<void>);
Ptr32<cc34a_Config_80070e94> cc34a_config_801797b4(Ptr32<void>);
Ptr32<void> cc34a_text_80343744(Ptr32<void>);
int cc34a_settext_801790bc(Ptr32<void>,Ptr32<const char>);
Ptr32<void> cc34a_alloc_801613f0(Ptr32<void>,unsigned int);
unsigned int cc34a_id_8015f5a0(Ptr32<cc34a_Cache_80070e94>,int);
int cc34a_post_8016239c(Ptr32<void>);
Ptr32<void> cc34a_init_80125fdc(Ptr32<void>,unsigned short,unsigned int);
int cc34a_send_8015fc58(Ptr32<cc34a_Actor_80070e94>,Ptr32<void>);
extern float cc34a_limit_804aafac;
extern float cc34a_constants_8037ca58[];
extern float cc34a_margin_8037ca5c[];
extern char cc34a_string_8037ca48[];
extern unsigned char cc34a_type_8040db38[];
extern Ptr32<void> cc34a_pool_804b1754;
extern cc34a_Cache_80070e94 cc34a_cache_804ad944,cc34a_cache_804ad94c;
void cc34a_actor_range_warning_80070e94(Ptr32<cc34a_Actor_80070e94> self,unsigned int now) {Ptr32<cc34a_Config_80070e94> config=cc34a_config_801797b4((Ptr32<void>)cc34a_context_80341584(self->context));
 if(config->rate*5000.0f+cc34a_magnitude_80070e94(self->distance) < cc34a_limit_804aafac-100.0f) {
  if(self->deadline!=self->originalDeadline) {
   self->deadline=self->originalDeadline;
   Ptr32<void> p=cc34a_alloc_801613f0(cc34a_pool_804b1754,12);
   unsigned short id=cc34a_id_8015f5a0(&cc34a_cache_804ad944,1);
   cc34a_send_8015fc58(self,cc34a_init_80125fdc(p,id,self->deadline));
  }
 } else if(self->deadline==self->originalDeadline) {
  cc34a_settext_801790bc(cc34a_text_80343744(self->text),cc34a_string_8037ca48);
  Ptr32<cc34a_Message_80070e94> p=(Ptr32<cc34a_Message_80070e94>)cc34a_alloc_801613f0(cc34a_pool_804b1754,8);
  p->id=cc34a_id_8015f5a0(&cc34a_cache_804ad94c,1);p->type=cc34a_type_8040db38;cc34a_post_8016239c(p);
  self->deadline=now+5000;
  Ptr32<void> q=cc34a_alloc_801613f0(cc34a_pool_804b1754,12);
  unsigned short id=cc34a_id_8015f5a0(&cc34a_cache_804ad944,1);
  cc34a_send_8015fc58(self,cc34a_init_80125fdc(q,id,self->deadline));
 }
}
}


