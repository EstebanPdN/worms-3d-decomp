// Inferred owner and vector views; offsets and operations verified against original instructions.
struct Vec3 {float x,y,z;Vec3(){}Vec3(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}void add(const Vec3 &v){x+=v.x;y+=v.y;z+=v.z;}};
struct Carrier {char pad[20];Vec3 extent;};
struct Related {char pad[32];Vec3 offset,extent;};
struct Owner {char pad00[40];Carrier *carrier;char pad2c[96];int active;char pad90[44];int mode;char padc0[28];float width;char pade0[60];Related *related;int subactive,ready;char pad128[120];float extra;};
extern "C" void fn_802b22e4(Vec3 *,void *);
extern "C" float fn_80178df0(void *);
extern "C" bool fn_802bc7c0(void *,float,float,void *,void *);
extern float scale_803cbf24[];
inline bool inner(Owner *self,float x,float y,int a,int b) {
 {
  Vec3 pos;fn_802b22e4(&pos,(char*)self+28);
  Vec3 size=self->carrier->extent;
  Vec3 spare;
  float extent=fn_80178df0(*(void **)((char*)self+272));
  if(self->ready)extent*=scale_803cbf24[0];
  float inset=*(float *)((char*)self+252);
  if(x>=(pos.x-size.x)+inset && x<=(pos.x+size.x)-extent && y>=(pos.y-size.y)+inset && y<=(pos.y+size.y)-inset)
   return fn_802bc7c0((void*)self->subactive,x,y,(void *)a,(void *)b);
 }
 return 0;
}

extern "C" bool w3d_f3a_hit_inner_8026f820(Owner *self,float x,float y,int a,int b) { bool result=false; if(*(int *)((char*)self+296))result=inner(self,x,y,a,b); return result; }
