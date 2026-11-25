// Observed partial layout, resource handles and callback protocol; roles inferred.
#define F(p,T,o) (*(T*)((char*)(p)+(o)))
typedef void (*F10aTextboxRef_8026e98c)(void*);
struct F10aTextboxHeld_8026e98c{
 F10aTextboxHeld_8026e98c(const F10aTextboxHeld_8026e98c &);void*p;F10aTextboxHeld_8026e98c():p(0){}~F10aTextboxHeld_8026e98c(){if(p)F(p,F10aTextboxRef_8026e98c*,0)[4](p);}void assign(void*next){if(next)F(next,F10aTextboxRef_8026e98c*,0)[3](next);if(p)F(p,F10aTextboxRef_8026e98c*,0)[4](p);p=next;}};
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short *fn_80341884(void*);
struct F10aTextboxText_8026e98c{char*p;F10aTextboxText_8026e98c(const F10aTextboxText_8026e98c&s){fn_8020c5c0(this);p=s.p;unsigned short*h=fn_80341884(this);++*h;}~F10aTextboxText_8026e98c(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10aTextboxKey_8026e98c{const char*p;};
extern "C" void *fn_80165254();
extern "C" void fn_802b0b84(void*,void*,unsigned);
extern "C" int fn_800fc1b0(F10aTextboxKey_8026e98c*,F10aTextboxHeld_8026e98c*),fn_800fd62c(void*,void*,void*,void*);
extern "C" void *fn_80342a74(void*),*fn_80343df4(void*);
extern "C" float fn_80178df0(void*);
extern "C" void fn_8020c510(void*,const char*,...),fn_8026ed00(void*),fn_8026f528(void*),fn_8026f9d0(void*);
extern "C" int fn_8026fb88(void *, void *);
extern const char border_803cbe08[],shadow_803cbe1c[],background_803cbe2c[],error_803cbe6c[];
extern const float automatic_803cbe90[];
extern "C" void w3d_f10a_setup_textbox_8026e98c(void*self){
 fn_802b0b84((char*)self+28,self,F(fn_80165254(),unsigned,52));
 F10aTextboxHeld_8026e98c unused,resource;void*context=F(self,void*,40);
 F10aTextboxKey_8026e98c border={border_803cbe08};fn_800fc1b0(&border,&resource);F(self,float,252)=fn_80178df0(fn_80342a74(resource.p));if(F(context,float,116)!=automatic_803cbe90[0])F(self,float,252)=F(context,float,116);F(self,F10aTextboxHeld_8026e98c,272).assign(fn_80342a74(resource.p));
 F10aTextboxKey_8026e98c shadow={shadow_803cbe1c};fn_800fc1b0(&shadow,&resource);F(self,F10aTextboxHeld_8026e98c,276).assign(fn_80342a74(resource.p));
 F10aTextboxKey_8026e98c background={background_803cbe2c};fn_800fc1b0(&background,&resource);F(self,F10aTextboxHeld_8026e98c,280).assign(fn_80343df4(resource.p));F(self,int,176)=0;
 F10aTextboxText_8026e98c *name=(F10aTextboxText_8026e98c*)((char*)context+140);
 if(*(unsigned short*)(name->p-4)){
 F10aTextboxKey_8026e98c data;data.p=F(context,const char*,140);
 if(fn_800fc1b0(&data,&F(self,F10aTextboxHeld_8026e98c,284))<0){F(self,F10aTextboxHeld_8026e98c,284).assign(0);{F10aTextboxText_8026e98c copy(*name);}fn_8020c510((char*)self+108,error_803cbe6c,name->p);}
 else fn_800fd62c(name,(void*)fn_8026fb88,self,(char*)self+212);
 }
 fn_8026ed00(self);fn_8026f528(self);F(self,int,296)=1;fn_8026f9d0(self);
}
