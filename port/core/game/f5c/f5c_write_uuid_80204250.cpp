#include "w3d_ptr.h"
#line 1 "f5c_write_uuid_80204250.cpp"
struct Uuid{unsigned a;unsigned short b,c;unsigned d,e;};extern "C" int fn_802047e0(Ptr32<void>,Ptr32<const void>,unsigned);inline unsigned swap32(unsigned w){return w;}inline unsigned short swap16(unsigned short w){return w;}extern "C" void f5c_write_uuid_80204250(Ptr32<void> self,Ptr32<const Uuid> in){Uuid out(*in);unsigned w=out.a;out.a= w;unsigned b=out.b,c=out.c;out.b= b;out.c= c;fn_802047e0(self,&out,16);}

