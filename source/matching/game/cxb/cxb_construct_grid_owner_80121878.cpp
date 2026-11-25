// Observed construction sequence; original class identity is unknown.
// Empty loops preserve original compiler-emitted initialization loops.
// Offsets denote a partial object view, not a recovered complete class.
extern "C" void *fn_8015fef0(void*);
extern "C" void *fn_803426b8(void*);
extern "C" void fn_80343740(void*);
extern char lbl_80410b18[];
#define F(p,t,o) (*(t*)((char*)(p)+(o)))
extern "C" void *cxb_construct_grid_owner_80121878(void *p) {
 fn_8015fef0(p);
 F(p,int,32)=0; F(p,int,36)=0; F(p,int,44)=0; F(p,int,48)=0;
 F(p,void*,0)=lbl_80410b18;
 fn_803426b8((char*)p+52);
 F(p,int,56)=0; F(p,int,100)=0; F(p,int,104)=0;
 for(int i=0;i<20;i++) {}
 F(p,int,368)=0;
 for(int i=20;i--;){for(int j=2;j--;) {}}
 for(int i=20;i--;){for(int j=2;j--;) {}}
 fn_80343740((char*)p+1448);
 return p;
}
