
// Original 800c1a14 activates low gravity once, posts notifications and emits
// its position effect. Partial views and inferred names; original externals
// remain unowned. Float constants independently decoded from original DOL.
struct cc36a_Gravity {unsigned char unknown[36];int active;};
struct cc36a_Vector {float x,y,z;};
struct cc36a_Message {unsigned short key,reserved;void* type;};
extern const float cc36a_default_8038308c[],cc36a_scale_80383090[];
extern const char cc36a_on_8038304c[],cc36a_multiplier_80383060[],cc36a_effect_80383078[];
extern unsigned char cc36a_type_8040db38[];
extern unsigned int cc36a_cache_804ae684[2],cc36a_cache_804ae694[2];
extern void* cc36a_pool_804b1754;
extern "C" {
int cc36a_read_800fc270(const char**,float*);
int cc36a_assign_800fc4c8(const char**,float);
void* cc36a_allocate_801613f0(void*,unsigned int);
unsigned int cc36a_key_8015f5a0(void*,int);
int cc36a_post_8016239c(void*);
void* cc36a_initialize_80125fdc(void*,unsigned short,unsigned int);
void cc36a_position_800c1b20(cc36a_Vector*,cc36a_Gravity*);
unsigned int cc36a_effect_call_800e5ca4(cc36a_Vector*,const char*,int,float);
void cc36a_finish_8015fd1c(cc36a_Gravity*);
void cc36a_low_gravity_800c1a14(cc36a_Gravity* self){
 if(!self->active){
  cc36a_Vector position;
  self->active=1;
  const char* on=cc36a_on_8038304c;
  float value=cc36a_default_8038308c[0];
  cc36a_read_800fc270(&on,&value);
  const char* multiplier=cc36a_multiplier_80383060;
  cc36a_assign_800fc4c8(&multiplier,value);
  cc36a_Message* message=(cc36a_Message*)cc36a_allocate_801613f0(cc36a_pool_804b1754,8);
  message->key=cc36a_key_8015f5a0(cc36a_cache_804ae684,1);message->type=cc36a_type_8040db38;
  cc36a_post_8016239c(message);
  void* next=cc36a_allocate_801613f0(cc36a_pool_804b1754,12);
  unsigned short key=cc36a_key_8015f5a0(cc36a_cache_804ae694,1);
  cc36a_post_8016239c(cc36a_initialize_80125fdc(next,key,44));
  cc36a_position_800c1b20(&position,self);
  cc36a_effect_call_800e5ca4(&position,cc36a_effect_80383078,0,cc36a_scale_80383090[0]);
  cc36a_finish_8015fd1c(self);
 }
}
}
