#include "w3d_ptr.h"
#line 1 "cx12b_crc_table_initialize_8021d70c.cpp"

extern "C" unsigned int transform_8021d7b0(Ptr32<void>,unsigned int,int);
extern "C" unsigned int table_804a98f8[];
inline void initialize(Ptr32<void> self,unsigned int polynomial){
 for(int index=0;index<=255;++index){table_804a98f8[index]=transform_8021d7b0(self,index,8)<<24;for(int bit=8;bit;--bit){unsigned int x=table_804a98f8[index];unsigned int next=x<<1;if((int)x<0)next^=polynomial;table_804a98f8[index]=next;}table_804a98f8[index]=transform_8021d7b0(self,table_804a98f8[index],32);}
}


extern "C" void w3d_cx12b_crc_table_initialize_8021d70c(Ptr32<void> self){initialize(self,0x04c11db7);}



