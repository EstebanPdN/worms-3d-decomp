#include "w3d_ptr.h"
#line 1 "f8b_launch_vector_8000d374.cpp"
// Inferred body/velocity layout. Equality compares vector component bit patterns.
extern "C" float sqrt_802e82c0(float);
struct F8LaunchVec {float x,y,z; F8LaunchVec(){} F8LaunchVec(float a,float b,float c):x(a),y(b),z(c){} F8LaunchVec(const F8LaunchVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;} F8LaunchVec operator-(const F8LaunchVec&o)const{F8LaunchVec r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;} bool operator==(const F8LaunchVec&o)const{return ((Ptr32<const int>)&o)[0]==((Ptr32<const int>)this)[0]&&((Ptr32<const int>)&o)[1]==((Ptr32<const int>)this)[1]&&((Ptr32<const int>)&o)[2]==((Ptr32<const int>)this)[2];} float norm2()const{return x*x+y*y+z*z;} void scale(float k){x*=k;y*=k;z*=k;} void normalize(){scale(1.0f/sqrt_802e82c0(norm2()));}};
extern const F8LaunchVec center_8041d3a0[];extern const float speed_80369e64[];
struct F8LaunchBody{char pad[24];F8LaunchVec position,velocity;};
extern "C" int f8b_launch_vector_8000d374(Ptr32<F8LaunchBody> s){s->velocity=s->position-center_8041d3a0[0];if(s->velocity==F8LaunchVec(0,0,0))s->velocity=F8LaunchVec(0,1,0);s->velocity.normalize();s->velocity.y+=1.0f;float length=sqrt_802e82c0(s->velocity.norm2());float speed=speed_80369e64[0];s->velocity.scale(1.0f/length);s->velocity.scale(speed);return 1;}


