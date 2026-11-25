#include "w3d_ptr.h"
#line 1 "f1p_hit_expanded_802b6af0.cpp"
// Original 0x802b6af0; panel bounds and names are inferred.
// The external fallback declaration reflects this caller's promoted FP arguments;
// complete cross-module semantic types and portable ABI integration remain pending.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}void add(const Vec3 &v){x+=v.x;y+=v.y;z+=v.z;}};
struct Carrier {char pad[20];Vec3 extent;};
struct Related {char pad[32];Vec3 offset,extent;};
struct Owner {char pad00[40];Ptr32<Carrier> carrier;char pad2c[96];int active;char pad90[44];int mode;char padc0[28];float width;char pade0[60];Ptr32<Related> related;int subactive,ready;char pad128[120];float extra;};
extern "C" Ptr32<void> fn_802b22e4(Ptr32<Vec3>,Ptr32<void>);
extern int state_804abb4c;
extern "C" int fn_802b15e0(Ptr32<void>,double,double);
extern float value_803d800c[],value_803d8010[],value_803d8014[];
extern "C" int w3d_hit_expanded_802b6af0(Ptr32<Owner> self,float x,float y) {
 if(self->active) {
  if(!self->mode)return fn_802b15e0((Ptr32<char>)self+28,x,y);
  float width=self->width;
  Vec3 pos;fn_802b22e4(&pos,(Ptr32<char>)self+28);
  Vec3 size=self->carrier->extent;
  Vec3 spare;volatile char reserved[8];
  Ptr32<Related> related=self->related;
  float bottom=pos.y+size.y;
  float oldtop=pos.y-size.y;
  float top=oldtop;
  if(related)top=(oldtop-(self->extra+self->extra))+value_803d800c[0];
  float left=pos.x-size.x,right=pos.x+size.x;
  if(y<oldtop && related) {
   float inset=width*value_803d8010[0];left+=inset;
   if(self->subactive)inset=width*value_803d8014[0];
   right-=inset;
  }
  if(x>=left && x<=right && y>=top && y<=bottom)return 1;
 }
 return 0;
}


