// The table count and descriptor offsets are observed; names are structural.
struct Cc18aDescriptor { void *vtable; unsigned int word4,word8; void *handlers; };
extern "C" unsigned int lbl_80456f14[];
extern "C" Cc18aDescriptor lbl_80457014;
extern "C" char lbl_803e8a1c[],lbl_80419598[],lbl_80411ad8[];
extern "C" void fn_8017b834();
extern "C" void *fn_8020fbd0(void *,void *,void *,void *,int,int);
static inline void initialize(Cc18aDescriptor *p) {
  fn_8020fbd0(p,lbl_803e8a1c,p,(void *)fn_8017b834,7,0);
  p->handlers=lbl_80419598;
  p->vtable=lbl_80411ad8;
}
extern "C" void w3d_cc18a_resource_sinit_8017e974(int init,int priority) {
 if(priority==0xffff && init) {
  unsigned int *p=lbl_80456f14;
  for(int i=64;i!=0;--i) *p++=0;
  initialize(&lbl_80457014);
 }
}
