#include "w3d_ptr.h"
#line 1 "cx13a_trigger_defaults_8008c154.cpp"
// PPC32 observed offsets, inferred semantic names.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern "C" int set_800fc550(Ptr32<Ptr32<const char>>,Ptr32<const char>),set_800fc3b0(Ptr32<Ptr32<const char>>,int),set_800fc4c8(Ptr32<Ptr32<const char>>,float);
extern const char key_8037deb8[],value_8037dec8[],key_8037ded8[],key_8037dee8[],key_8037def8[],key_8037df0c[],key_8037df20[],key_8037df34[],key_8037df48[],key_8037df60[],key_8037df78[],key_8037df90[];
extern const float radius_8037dfa4[];
extern "C" void w3d_cx13a_trigger_defaults_8008c154(){
 Ptr32<const char> a=key_8037deb8;set_800fc550(&a,value_8037dec8);Ptr32<const char> b=key_8037ded8;set_800fc3b0(&b,-1);Ptr32<const char> c=key_8037dee8;set_800fc4c8(&c,radius_8037dfa4[0]);Ptr32<const char> d=key_8037def8;set_800fc3b0(&d,1);Ptr32<const char> e=key_8037df0c;set_800fc3b0(&e,-1);Ptr32<const char> f=key_8037df20;set_800fc3b0(&f,-1);Ptr32<const char> g=key_8037df34;set_800fc3b0(&g,-1);Ptr32<const char> h=key_8037df48;set_800fc3b0(&h,2000);Ptr32<const char> i=key_8037df60;set_800fc3b0(&i,2000);Ptr32<const char> j=key_8037df78;set_800fc3b0(&j,0);Ptr32<const char> k=key_8037df90;set_800fc3b0(&k,0);
}


