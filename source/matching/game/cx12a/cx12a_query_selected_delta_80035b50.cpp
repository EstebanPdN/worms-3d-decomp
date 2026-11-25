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

extern "C" unsigned query_800b0788(const Cx12aVec3 *,const Cx12aVec3 *);
extern "C" unsigned w3d_cx12a_query_selected_delta_80035b50(void *self,const Cx12aVec3 *point){
 unsigned result=0;void *entry=*(void **)((char *)FIELD(self,void *,0x13c)+(FIELD(self,int,0x138)<<2));
 if(entry){Cx12aVec3 start(FIELD(entry,Cx12aVec3,4));Cx12aVec3 delta=point->minus(start);result=query_800b0788(&start,&delta)^1;}return result;
}
