#include "w3d_ptr.h"
#line 1 "f1p_hit_simple_802b9cf4.cpp"
// Original 0x802b9cf4. Vector/panel interpretation inferred from observed accesses.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}void add(const Vec3 &v){x+=v.x;y+=v.y;z+=v.z;}};
struct Carrier {char pad[20];Vec3 extent;};
struct Related {char pad[32];Vec3 offset,extent;};
struct Owner {char pad00[40];Ptr32<Carrier> carrier;char pad2c[96];int active;char pad90[44];int mode;char padc0[28];float width;char pade0[60];Ptr32<Related> related;int subactive,ready;char pad128[120];float extra;};
extern "C" Ptr32<void> fn_802b22e4(Ptr32<Vec3>,Ptr32<void>);
extern int state_804abb4c;
extern "C" int w3d_hit_simple_802b9cf4(Ptr32<Owner> self,float x,float y) {
 if(self->active && self->ready) {
  if(!self->mode && state_804abb4c==1)return 0;
  Vec3 pos;fn_802b22e4(&pos,(Ptr32<char>)self+28);
  Vec3 size=self->carrier->extent;
  Vec3 spare;
  float right=pos.x+size.x; float left=pos.x-size.x; float bottom=pos.y+size.y; float top=pos.y-size.y;
  if(x>=left && x<=right && y>=top && y<=bottom)return 1;
 }
 return 0;
}


