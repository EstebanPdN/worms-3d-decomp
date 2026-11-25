// Original 0x802b8260. Inferred strip hit test and event forwarding.
// An inline inner query preserves the distinct guarded return paths.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}void add(const Vec3 &v){x+=v.x;y+=v.y;z+=v.z;}};
struct Carrier {char pad[20];Vec3 extent;};
struct Related {char pad[32];Vec3 offset,extent;};
struct Owner {char pad00[40];Carrier *carrier;char pad2c[96];int active;char pad90[44];int mode;char padc0[28];float width;char pade0[60];Related *related;int subactive,ready;char pad128[120];float extra;};
extern "C" void fn_802b22e4(Vec3 *,void *);
extern int state_804abb4c;
extern "C" float fn_80178df0(void *);
extern "C" bool fn_802bc7c0(void *,float,float,void *,void *);
extern float shift_803d80a4[],gain_803d80a8[],gain_803d80ac[];
inline bool inner(Owner *self,float x,float y,int a,int b) {
 {
  Vec3 pos;fn_802b22e4(&pos,(char*)self+28);
  Vec3 size=self->carrier->extent;Vec3 spare;
  float value=fn_80178df0(*(void **)((char*)self+268));
  float top=pos.y-size.y;
  float expanded=(top-(self->extra+self->extra))+shift_803d80a4[0];
  float gain=gain_803d80a8[0];
  float left=(pos.x-size.x)+self->width*gain;
  float right;
  if(self->subactive)right=(pos.x+size.x)-value*gain_803d80ac[0];
  else right=(pos.x+size.x)-value*gain;
  if(x>=left && x<=right && y>=expanded && y<=top)
   return fn_802bc7c0(self->related,x,y,(void *)a,(void *)b);
 }
 return false;
}

extern "C" bool w3d_hit_strip_forward_802b8260(Owner*self,float x,float y,int a,int b){bool result=false;if(self->ready)result=inner(self,x,y,a,b);return result;}
