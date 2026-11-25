#include "w3d_ptr.h"
#line 1 "cx16b_descriptor_defaults_8018a218.cpp"
/* Observed field updates; four-byte colors have an inline component writer
   to preserve their original subobject pointer arithmetic and store order. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
extern "C" void fn_8020bd38(Ptr32<void>,Ptr32<const char>);
struct Cx16bColor { unsigned char x,y,z,w; inline void set(int a,int b,int c,int d){x=a;y=b;z=c;w=d;} };
extern "C" int w3d_cx16b_descriptor_defaults_8018a218(Ptr32<void> self,Ptr32<const void> input)
{
    fn_8020bd38((Ptr32<char>)self+20,FIELD(input,const char *,0));
    FIELD(self,unsigned char,27)=FIELD(input,unsigned char,4);
    FIELD(self,unsigned char,26)=FIELD(input,unsigned char,5);
    FIELD(self,unsigned,24)&=0xffff7fffU;
    FIELD(self,unsigned short,60)=FIELD(input,unsigned short,12);
    unsigned value=FIELD(input,unsigned,8);
    FIELD(self,unsigned,68)=0;
    FIELD(self,unsigned,64)=value;
    float b=FIELD(input,float,16),a=FIELD(input,float,20);
    FIELD(self,float,44)=b;
    FIELD(self,float,48)=a;
    FIELD(self,Cx16bColor,52).set(-1,-1,-1,-1);
    FIELD(self,Cx16bColor,56).set(0,0,0,-1);
    return 0;
}


