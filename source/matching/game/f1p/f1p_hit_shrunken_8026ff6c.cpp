// Original 0x8026ff6c. Panel layout, margins and names inferred.
// The fallback declaration reflects this caller's promoted FP arguments.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}void add(const Vec3 &v){x+=v.x;y+=v.y;z+=v.z;}};
struct Carrier {char pad[20];Vec3 extent;};
struct Related {char pad[32];Vec3 offset,extent;};
struct Owner {char pad00[40];Carrier *carrier;char pad2c[96];int active;char pad90[44];int mode;char padc0[28];float width;char pade0[60];Related *related;int subactive,ready;char pad128[120];float extra;};
extern "C" void * fn_802b22e4(Vec3 *,void *);
extern int state_804abb4c;
extern "C" int fn_802b15e0(void *,double,double);
extern float scale_803cbf44[];
extern "C" int w3d_hit_shrunken_8026ff6c(Owner *self,float x,float y) {
 if(self->active) {
  if(!self->mode)return fn_802b15e0((char*)self+28,x,y);
  float inset=*(float *)((char*)self+252);
  Vec3 pos;fn_802b22e4(&pos,(char*)self+28);
  Vec3 size=self->carrier->extent;
  Vec3 spare;volatile char reserved[8];
  size.y-=inset;
  if(self->ready) {
   float part=inset*scale_803cbf44[0];
   size.x-=(inset+part);pos.x-=part;
  } else size.x-=inset;
  if(x>=pos.x-size.x && x<=pos.x+size.x && y>=pos.y-size.y && y<=pos.y+size.y)return 1;
 }
 return 0;
}
