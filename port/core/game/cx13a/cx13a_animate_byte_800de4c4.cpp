#include "w3d_ptr.h"
#line 1 "cx13a_animate_byte_800de4c4.cpp"
// Observed PPC32 fields and pointer arithmetic; semantic names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern "C" void w3d_cx13a_animate_byte_800de4c4(Ptr32<void> self,unsigned now,Ptr32<unsigned char> out,Ptr32<void> parameters,unsigned limit){
 float elapsed=(float)(now-FIELD(self,unsigned,100));if(limit){if(FIELD(parameters,unsigned short,0x18c)==0)*out=FIELD(parameters,unsigned char,0x1e4);
 else{unsigned frame=FIELD(self,unsigned char,0x69)+(unsigned)(elapsed/(float)FIELD(self,int,0x60));*out=FIELD(parameters,unsigned char,0x1e4)+frame%(unsigned)(int)FIELD(parameters,signed char,0x1ec);}if(*out<=limit)return;}*out=(unsigned char)limit;
}


