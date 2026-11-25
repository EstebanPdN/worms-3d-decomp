// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern void *context_804b1788;
extern "C" unsigned launch_800e5ca4(void *,const char *,int,float);
extern "C" void w3d_cx12a_bind_effect_8009d6d4(void *self,void *params,void *position){
 const char *name=FIELD(params,const char *,0x118);
 if(FIELD(name,unsigned short,-4)!=0&&FIELD(self,int,0x6c)!=1)FIELD(self,unsigned,0x78)=launch_800e5ca4(position,name,0,FIELD(params,float,0xf4));
 const char *other=FIELD(params,const char *,0x108);
 if(FIELD(other,unsigned short,-4)!=0&&FIELD(context_804b1788,void *,0x6c)){
 if(FIELD(self,void *,0x44)){VCALL(FIELD(self,void *,0x44),void (*)(void *),0x18)(FIELD(self,void *,0x44));if(FIELD(self,void *,0x44))VCALL(FIELD(self,void *,0x44),void (*)(void *),0x10)(FIELD(self,void *,0x44));FIELD(self,void *,0x44)=0;}
 void *svc=FIELD(context_804b1788,void *,0x6c);VCALL(svc,int (*)(void *,const char *,void **),0x5c)(svc,FIELD(params,const char *,0x108),&FIELD(self,void *,0x44));
 void *effect=FIELD(self,void *,0x44);VCALL(effect,int (*)(void *,int,void *),0x38)(effect,3,position);
 effect=FIELD(self,void *,0x44);VCALL(effect,void (*)(void *),0x14)(effect);
 }
}
