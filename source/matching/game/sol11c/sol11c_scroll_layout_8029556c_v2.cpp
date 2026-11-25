// External UI and resource fields are borrowed GameCube ABI views.
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
struct Vec3 {float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}};
typedef void(*SetVector)(void*,const Vec3*,int);
inline void position(void* p,const Vec3& v){MEMBER(p,SetVector*,0)[19](p,&v,0);}
inline void dimensions(void* p,const Vec3& v){MEMBER(p,SetVector*,0)[21](p,&v,0);}
extern "C" void string_base_init_8020c5c0(void*),string_base_finish_8020c5c4(void*),string_release_80341588(void*);
extern "C" unsigned short* string_header_80341884(void*);
struct Text {char* p;Text(const Text& s){string_base_init_8020c5c0(this);p=s.p;++*string_header_80341884(this);}~Text(){string_base_finish_8020c5c4(this);string_release_80341588(this);}};
extern const float half_803d07c0[],depth_803d07c4[],edge_803d07c8[],edge2_803d07cc[],extent_803d07d0[],zero_803d07d4[],divisor_803d07d8[],padding_803d07dc[];
extern "C" void update_geometry_802962f8(void*),finish_layout_802958d8(void*);
extern "C" void* acquire_slot_80263cfc(Text,unsigned,float);
extern "C" void store_alpha_80173f88(void*,const unsigned char*);
extern "C" void sol11c_scroll_layout_8029556c(void* self){
 Vec3 v;
 if((MEMBER(self,int,60)!=0)&(MEMBER(self,int,56)!=0)){
  v.z=depth_803d07c4[0];float half=half_803d07c0[0];
  v.x=MEMBER(self,float,160);v.y=MEMBER(self,float,164);
  float d=depth_803d07c4[0];MEMBER(self,float,52)=MEMBER(self,float,48);
  float radius=v.y*half;
  dimensions(MEMBER(self,void*,132),v);
  v.set(MEMBER(self,float,160),MEMBER(self,float,164),d);dimensions(MEMBER(self,void*,136),v);
  float edge=edge_803d07c8[0];
  v.set(MEMBER(self,float,160),edge,d);dimensions(MEMBER(self,void*,144),v);
  v.set(MEMBER(self,float,160),edge,d);dimensions(MEMBER(self,void*,152),v);
  v.set(MEMBER(self,float,160),edge2_803d07cc[0],d);dimensions(MEMBER(self,void*,148),v);
  float z=zero_803d07d4[0],extent=extent_803d07d0[0];
  v.set(z,MEMBER(self,float,52)*extent-radius,z);position(MEMBER(self,void*,132),v);
  v.set(z,z-MEMBER(self,float,52)*extent+radius,z);position(MEMBER(self,void*,136),v);
  float divisor=divisor_803d07d8[0];
  v.set(MEMBER(self,float,168)/divisor,MEMBER(self,float,160),d);dimensions(MEMBER(self,void*,140),v);
  v.set(z,MEMBER(self,float,52)*extent-MEMBER(self,float,160)-radius,z);position(MEMBER(self,void*,140),v);
  MEMBER(self,float,52)-=radius*padding_803d07dc[0];
  update_geometry_802962f8(self);
  float total=MEMBER(self,float,52)*extent+radius;
  MEMBER(self,void*,180)=acquire_slot_80263cfc(MEMBER(self,Text,176),~0u,total+total);
  v.set(z,z,z);position(MEMBER(self,void*,128),v);
  v.set(MEMBER(self,float,168)/divisor,MEMBER(self,float,52)*extent+radius,d);dimensions(MEMBER(self,void*,128),v);
  store_alpha_80173f88(MEMBER(self,void*,128),(unsigned char*)self+183);
  finish_layout_802958d8(self);
 }
}
