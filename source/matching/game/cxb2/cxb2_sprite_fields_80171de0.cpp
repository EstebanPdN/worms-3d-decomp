// External object views only; names inferred from witnessed property strings.
// Both old-slot branches assign the new value, including an initially null slot.
#define F(p,t,o) (*(t*)((char*)(p)+(o)))
extern "C" int fn_80190538(void*,void*);
extern const char lbl_803a66c0[],lbl_803a66a8[],lbl_803a66b4[];
typedef void (*Ref)(void*);
typedef int (*Read)(void*,void*,const char*);
extern "C" int cxb2_sprite_fields_80171de0(void *self,void *reader) {
 int result=fn_80190538(self,reader);
 if(result>=0) {
  void *temp=0;
  F(F(reader,void*,0),Read,32)(reader,&temp,lbl_803a66c0);
  void *p=temp;
  if(p)F(F(p,void*,0),Ref,12)(p);
  void *old=F(self,void*,76);
  if(old) { F(F(old,void*,0),Ref,16)(old); F(self,void*,76)=p; }
  else { F(self,void*,76)=p; }
  F(F(reader,void*,0),Read,120)(reader,(char*)self+44,lbl_803a66a8);
  F(F(reader,void*,0),Read,120)(reader,(char*)self+46,lbl_803a66b4);
  if(temp)F(F(temp,void*,0),Ref,16)(temp);
  result=0;
 }
 return result;
}
