// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx13aVec3 {
 float x,y,z;
 Cx13aVec3() {}
 Cx13aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx13aVec3(const Cx13aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx13aVec3 scaled(float k) const {Cx13aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx13aVec3 plus(const Cx13aVec3 &o) const {Cx13aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx13aVec3 minus(const Cx13aVec3 &o) const {Cx13aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx13aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx13aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

extern "C" Cx13aVec3 read_80026720(void *),read_80026668(void *);
extern "C" void w3d_cx13a_refresh_transform_800261d4(void *self){
 FIELD(self,Cx13aVec3,0x30)=read_80026720(self);FIELD(self,Cx13aVec3,0x24)=read_80026668(self);
 VCALL(FIELD(self,void *,0x40),void (*)(void *,Cx13aVec3 *,int),0x4c)(FIELD(self,void *,0x40),&FIELD(self,Cx13aVec3,0x24),0);
 VCALL(FIELD(self,void *,0x40),void (*)(void *,Cx13aVec3 *,int),0x50)(FIELD(self,void *,0x40),&FIELD(self,Cx13aVec3,0x30),0);
}
