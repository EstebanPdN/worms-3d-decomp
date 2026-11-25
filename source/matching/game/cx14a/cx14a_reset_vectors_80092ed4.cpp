// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx14aVec3 {
 float x,y,z;
 Cx14aVec3() {}
 Cx14aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx14aVec3(const Cx14aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx14aVec3 scaled(float k) const {Cx14aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx14aVec3 plus(const Cx14aVec3 &o) const {Cx14aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx14aVec3 minus(const Cx14aVec3 &o) const {Cx14aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx14aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx14aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};



extern "C" const Cx14aVec3 *read_80178ec4(void *);extern "C" void refresh_800d2f64(void *);extern const float zero_8037e90c[];
extern "C" void w3d_cx14a_reset_vectors_80092ed4(void *self){FIELD(self,Cx14aVec3,140)=*read_80178ec4(FIELD(self,void *,208));const Cx14aVec3 *source=read_80178ec4(FIELD(self,void *,212));float zero=zero_8037e90c[0];FIELD(self,Cx14aVec3,164)=*source;FIELD(self,Cx14aVec3,152).set(zero,zero,zero);refresh_800d2f64(self);}
