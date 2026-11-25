// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx10aVec3 {
 float x,y,z;
 Cx10aVec3() {}
 Cx10aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx10aVec3(const Cx10aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx10aVec3 scaled(float k) const {Cx10aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx10aVec3 plus(const Cx10aVec3 &o) const {Cx10aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx10aVec3 minus(const Cx10aVec3 &o) const {Cx10aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx10aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx10aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

struct Cx10aMotion {unsigned char unknown00[0x28];Cx10aVec3 velocity;unsigned char unknown34[0x20];int dirty;};
extern const float zero_80374678[],one_8037467c[],scale_80374680[];
extern "C" float root_802e82c0(float);
extern "C" void w3d_cx10a_planar_impulse_8003ebdc(Cx10aMotion *self,const Cx10aVec3 *input){
 Cx10aVec3 v(*input);v.y=zero_80374678[0];
 if(v.dot(v)==zero_80374678[0])v.set(zero_80374678[0],one_8037467c[0],zero_80374678[0]);
 v.multiply(one_8037467c[0]/root_802e82c0(v.dot(v)));
 v.multiply(scale_80374680[0]);self->velocity.add(v);self->dirty=1;
}
