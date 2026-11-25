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

extern "C" float root_802e82c0(float);extern const float zero_8038957c[],one_80389580[];
extern "C" void w3d_cx11a_planar_basis_800d9b70(void *unused,const Cx11aVec3 *input,Cx11aVec3 *out){float squared=input->x*input->x+input->z*input->z;if(squared==zero_8038957c[0])*out=Cx11aVec3(one_80389580[0],zero_8038957c[0],zero_8038957c[0]);else{float inverse=one_80389580[0]/root_802e82c0(squared);*out=Cx11aVec3(-input->x*input->y,squared,-input->y*input->z).scaled(inverse);}}
