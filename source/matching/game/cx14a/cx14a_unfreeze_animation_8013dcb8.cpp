// PPC32 offsets and interface slots are observed; descriptive names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))

extern "C" void *resolve_80164fc8(unsigned);extern "C" void release_800a4cd0(void *);
extern "C" int play_801359ec(void *,unsigned,const char *,void *,float,float,float);
extern const char *name_804ab1e0,*name_804ab1e4,*name_804ab1e8;extern const float rate_8039fb68[],zero_8039fb6c[];
extern "C" void w3d_cx14a_unfreeze_animation_8013dcb8(void *self,unsigned flags){void *object=resolve_80164fc8(FIELD(self,unsigned,152));if(!object){FIELD(self,unsigned,152)=~0U;return;}release_800a4cd0(object);FIELD(self,unsigned,152)=~0U;switch(FIELD(self,int,160)){case 0:play_801359ec(self,flags,name_804ab1e0,(char *)self+472,rate_8039fb68[0],zero_8039fb6c[0],zero_8039fb6c[0]);break;case 1:play_801359ec(self,flags,name_804ab1e4,(char *)self+472,rate_8039fb68[0],zero_8039fb6c[0],zero_8039fb6c[0]);break;case 2:play_801359ec(self,flags,name_804ab1e8,(char *)self+472,rate_8039fb68[0],zero_8039fb6c[0],zero_8039fb6c[0]);break;}}
