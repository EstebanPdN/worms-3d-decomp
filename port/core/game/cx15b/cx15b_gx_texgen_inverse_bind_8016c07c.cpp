#include "w3d_ptr.h"
#line 1 "cx15b_gx_texgen_inverse_bind_8016c07c.cpp"
// Inferred engine names. Layout offsets and PPC32 four-byte pointers follow original effective addresses.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" {int inverse_80302da0(Ptr32<void>,Ptr32<void>);void load_8030c0c8(Ptr32<void>,u32,int);void texgen_80307e24(int,int,int,u32,int,u32);extern u32 object_803a56b0[],context_803a56d0[];extern Ptr32<void> global_804b1884;}
struct Matrix{float v[12];};
static inline void apply(Ptr32<void> self,int index,u32 offset,u32 modes){if((*(Ptr32<int>)w3d::G((modes+offset)))!=2){Matrix temp;inverse_80302da0((Ptr32<char>)self+236,&temp);u32 object=object_803a56b0[index];load_8030c0c8(&temp,object,0);u32 context=context_803a56d0[index];load_8030c0c8((Ptr32<char>)global_804b1884+920,context,0);texgen_80307e24(index,0,1,object,1,context);FIELD(self,u32,304)=0;(*(Ptr32<int>)w3d::G((modes+offset)))=2;}}
extern "C" void w3d_cx15b_gx_texgen_inverse_bind_8016c07c(Ptr32<void> self,int index){apply(self,index,index*4,(u32)w3d::H(self)+328);}




