// PPC32 byte offsets, four-byte pointer slots and three-float vectors are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx12aVec3 {
 float x,y,z;
 Cx12aVec3() {}
 Cx12aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx12aVec3(const Cx12aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx12aVec3 scaled(float k) const {Cx12aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx12aVec3 plus(const Cx12aVec3 &o) const {Cx12aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx12aVec3 minus(const Cx12aVec3 &o) const {Cx12aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx12aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx12aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

struct Cx12aTransform {Cx12aVec3 x,y,z,position;};extern "C" void initialize_80343740(Cx12aVec3 *);
extern "C" void w3d_cx12a_forward_positions_8002e59c(void *self){
 Cx12aTransform transform;initialize_80343740(&transform.position);
 VCALL(FIELD(self,void *,0x20),int (*)(void *,Cx12aTransform *),0x7c)(FIELD(self,void *,0x20),&transform);
 Cx12aVec3 position;position=transform.position;VCALL(FIELD(self,void *,0x58),int (*)(void *,int,const Cx12aVec3 *),0x38)(FIELD(self,void *,0x58),3,&position);
 VCALL(FIELD(self,void *,0x24),int (*)(void *,Cx12aTransform *),0x7c)(FIELD(self,void *,0x24),&transform);
 position=transform.position;VCALL(FIELD(self,void *,0x5c),int (*)(void *,int,const Cx12aVec3 *),0x38)(FIELD(self,void *,0x5c),3,&position);
}
