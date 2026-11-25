// PPC32 layout: all offsets below are observed; action and field names are inferred.
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

extern "C" const Cx12aVec3 *read_80178ec4(void *);
extern "C" void w3d_cx12a_apply_five_vectors_800246e4(void *self){
 Cx12aVec3 a(*read_80178ec4(FIELD(self,void *,0x48)));
 Cx12aVec3 b(*read_80178ec4(FIELD(self,void *,0x40)));
 Cx12aVec3 c(*read_80178ec4(FIELD(self,void *,0x44)));
 Cx12aVec3 d(*read_80178ec4(FIELD(self,void *,0x4c)));
 Cx12aVec3 e(*read_80178ec4(FIELD(self,void *,0x64)));
 VCALL(FIELD(self,void *,0x1c),void (*)(void *,const Cx12aVec3 *,int),0x54)(FIELD(self,void *,0x1c),&a,0);
 VCALL(FIELD(self,void *,0x24),void (*)(void *,const Cx12aVec3 *,int),0x54)(FIELD(self,void *,0x24),&b,0);
 VCALL(FIELD(self,void *,0x20),void (*)(void *,const Cx12aVec3 *,int),0x54)(FIELD(self,void *,0x20),&c,0);
 VCALL(FIELD(self,void *,0x28),void (*)(void *,const Cx12aVec3 *,int),0x54)(FIELD(self,void *,0x28),&d,0);
 VCALL(FIELD(self,void *,0x2c),void (*)(void *,const Cx12aVec3 *,int),0x54)(FIELD(self,void *,0x2c),&e,0);
}
