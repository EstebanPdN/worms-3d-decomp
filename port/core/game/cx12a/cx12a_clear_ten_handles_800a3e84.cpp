#include "w3d_ptr.h"
#line 1 "cx12a_clear_ten_handles_800a3e84.cpp"
// PPC32 offsets and four-byte pointer slots are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern "C" Ptr32<void> lookup_80164fc8(unsigned);extern "C" void destroy_8015fd1c(Ptr32<void>);
extern "C" void w3d_cx12a_clear_ten_handles_800a3e84(Ptr32<void> self){
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x20));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x24));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x28));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x2c));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x30));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x34));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x38));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x3c));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x40));if(object)destroy_8015fd1c(object);}
 {Ptr32<void> object=lookup_80164fc8(FIELD(self,unsigned,0x44));if(object)destroy_8015fd1c(object);}
 FIELD(self,unsigned,0x20)=~0u;
 FIELD(self,unsigned,0x24)=~0u;
 FIELD(self,unsigned,0x28)=~0u;
 FIELD(self,unsigned,0x2c)=~0u;
 FIELD(self,unsigned,0x30)=~0u;
 FIELD(self,unsigned,0x34)=~0u;
 FIELD(self,unsigned,0x38)=~0u;
 FIELD(self,unsigned,0x3c)=~0u;
 FIELD(self,unsigned,0x40)=~0u;
 FIELD(self,unsigned,0x44)=~0u;
}


