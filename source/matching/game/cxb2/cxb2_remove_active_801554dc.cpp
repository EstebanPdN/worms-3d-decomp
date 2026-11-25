// Original class names and borrow-tag meaning remain unknown.
// Automatic borrow lifetime reproduces the observed destructor call and stack layout.
extern const char lbl_803a27ac[];
extern "C" int fn_800fc1f0(const char **,int*);
extern "C" void *fn_800fc6dc(int);
extern "C" void *fn_800fc82c(unsigned,void*);
extern "C" void fn_801565e4(void*,unsigned);

#define F(p,t,o) (*(t*)((char*)(p)+(o)))
struct Cxb2Borrow_80178474 {unsigned value,tag; Cxb2Borrow_80178474():value(0),tag(0xe3a8) {} ~Cxb2Borrow_80178474(); };
extern "C" void cxb2_remove_active_801554dc(void *self) {
 const char *key=lbl_803a27ac;
 int index;
 fn_800fc1f0(&key,&index);
 if(index!=-1) {
  unsigned id=F(fn_800fc6dc(index),unsigned char,213);
  Cxb2Borrow_80178474 h;
  F(fn_800fc82c(id,&h),int,44)=1;
  fn_801565e4(self,id);

 }
}
