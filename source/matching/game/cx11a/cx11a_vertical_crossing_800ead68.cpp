// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx11aVec3 {
 float x,y,z;
 Cx11aVec3() {}
 Cx11aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx11aVec3(const Cx11aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx11aVec3 scaled(float k) const {Cx11aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx11aVec3 plus(const Cx11aVec3 &o) const {Cx11aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx11aVec3 minus(const Cx11aVec3 &o) const {Cx11aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx11aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx11aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

extern const float step_8038b3fc[];
extern "C" int w3d_cx11a_vertical_crossing_800ead68(void *unused,const Cx11aVec3 *position,const Cx11aVec3 *velocity,float plane){float factor=step_8038b3fc[0];Cx11aVec3 p(*position);Cx11aVec3 q=position->plus(velocity->scaled(factor));int result=0;if(p.y>plane&&q.y<=plane)result=1;return result;}
