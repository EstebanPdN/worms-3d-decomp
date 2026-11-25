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

extern "C" const Cx13aVec3 *read_80178ec4(void *);
extern "C" float read_80178df0(void *);
extern const float threshold_8039e1f0[];
extern "C" void w3d_cx13a_follow_target_80131610(void *self){
 Cx13aVec3 delta;
 switch(FIELD(self,int,116)){
 case 0:case 1:return;
 case 2:delta=read_80178ec4(FIELD(self,void *,144))->minus(FIELD(self,Cx13aVec3,60));if(delta.dot(delta)<threshold_8039e1f0[0]){FIELD(self,int,116)=0;FIELD(self,Cx13aVec3,60)=*read_80178ec4(FIELD(self,void *,144));return;}break;
 case 3:delta=read_80178ec4(FIELD(self,void *,140))->minus(FIELD(self,Cx13aVec3,60));if(delta.dot(delta)<threshold_8039e1f0[0]){FIELD(self,int,116)=1;FIELD(self,Cx13aVec3,60)=*read_80178ec4(FIELD(self,void *,140));return;}break;
 }
 delta.multiply(read_80178df0(FIELD(self,void *,132)));FIELD(self,Cx13aVec3,60).add(delta);
}
