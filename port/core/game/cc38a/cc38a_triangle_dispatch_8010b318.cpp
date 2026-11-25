#include "w3d_ptr.h"
#line 1 "cc38a_triangle_dispatch_8010b318.cpp"

// Triangle dispatch with observed unsigned index and mask domains. Partial
// renderer view separates the two byte lookup tables from unknown storage.
struct cc38a_Renderer {unsigned char unknown[680];Ptr32<unsigned int> vertexFlags;unsigned char gap684[84];unsigned char tableLow[256];unsigned char gap1024[512];unsigned char tableHigh[1];};
extern "C" void cc38a_prepare_8010ad24(Ptr32<cc38a_Renderer>,unsigned short,unsigned short,unsigned short,int);
extern "C" void cc38a_low_8010b118(Ptr32<cc38a_Renderer>,unsigned short,unsigned short,unsigned short,unsigned char,int);
extern "C" void cc38a_high_8010b198(Ptr32<cc38a_Renderer>,unsigned short,unsigned short,unsigned short,unsigned char,int);
extern "C" void cc38a_triangle_dispatch_8010b318(Ptr32<cc38a_Renderer> self,unsigned code,unsigned a,unsigned b,unsigned c,Ptr32<void> data){
 cc38a_prepare_8010ad24(self,a,b,c,(int)w3d::H(data));
 if((self->vertexFlags[a]&0xff00)<0xfd01 || (self->vertexFlags[b]&0xff00)<0xfd01 || (self->vertexFlags[c]&0xff00)<0xfd01)
  cc38a_low_8010b118(self,a,b,c,self->tableLow[(unsigned char)code],(int)w3d::H(data));
 if((self->vertexFlags[a]&0xff00)==0 && (self->vertexFlags[b]&0xff00)==0 && (self->vertexFlags[c]&0xff00)==0)return;
 cc38a_high_8010b198(self,a,b,c,self->tableHigh[code>>8],(int)w3d::H(data));
}


