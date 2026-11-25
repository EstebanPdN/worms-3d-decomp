// External GC32 views. Mask bits select registry entries; collision semantics are inferred.
struct Sol11aVector { float x,y,z; Sol11aVector(const Sol11aVector &v) { float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c; } };
struct Sol11aMaskState { unsigned char external_prefix[128]; unsigned mask[1]; };
struct Sol11aRegistry { void **begin,**end; };
extern Sol11aRegistry registry_8043bb64[];
extern void *result_804ae5dc;
extern "C" void *identity_80342a78(void *);
extern "C" int set_80178d28(void *,const int *);
extern "C" void prepare_800bd53c(Sol11aMaskState *,const Sol11aVector *,float);
extern "C" int test_800b1410(void *,Sol11aVector,float);
extern "C" int sol11a_masked_sphere_800bdb5c(Sol11aMaskState *self,const Sol11aVector *position,float radius) {
 int zero=0;
 set_80178d28(identity_80342a78(result_804ae5dc),&zero);
 prepare_800bd53c(self,position,radius);
 void **end=registry_8043bb64->end;
 unsigned bit=1;
 unsigned *mask=self->mask;
 for(void **entry=registry_8043bb64->begin;entry!=end;++entry) {
  if((*mask&bit) && test_800b1410(*entry,*position,radius))return 1;
  bit<<=1;
  if(!bit){bit=1;++mask;}
 }
 return 0;
}
