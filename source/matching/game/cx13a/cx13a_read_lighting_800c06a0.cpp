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

extern "C" int query_800fc2f0(const char **,Cx13aVec3 *);extern const char key_80382f94[];
extern Cx13aVec3 light_8043c3b8[],negative_8043c3ac[],first_8043c3d0[],second_8043c3c4[];
extern "C" void *cast_80342fa4(void *);extern "C" const Cx13aVec3 *read_80178ec4(void *);
inline Cx13aVec3 cx13a_negate(const Cx13aVec3 &v){Cx13aVec3 r;r.x=-v.x;r.y=-v.y;r.z=-v.z;return r;}
extern "C" void w3d_cx13a_read_lighting_800c06a0(void *self){
 const char *key=key_80382f94;query_800fc2f0(&key,light_8043c3b8);negative_8043c3ac[0]=cx13a_negate(light_8043c3b8[0]);
 Cx13aVec3 a;a=*read_80178ec4(cast_80342fa4(FIELD(self,void *,0x1c)));first_8043c3d0[0].set(a.x,a.y,a.z);
 a=*read_80178ec4(cast_80342fa4(FIELD(self,void *,0x20)));second_8043c3c4[0].set(a.x,a.y,a.z);
}
