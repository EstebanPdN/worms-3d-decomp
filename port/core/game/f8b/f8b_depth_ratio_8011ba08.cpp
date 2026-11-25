#include "w3d_ptr.h"
#line 1 "f8b_depth_ratio_8011ba08.cpp"
// Twenty-four trailing frame bytes have unknown original purpose.
// Inferred camera-relative depth ratio; all external interfaces and roles are provisional.
extern "C" float sqrt_802e82c0(float),read_80178df0(Ptr32<void>);
struct F8DepthVec{float x,y,z;F8DepthVec(){}F8DepthVec(const F8DepthVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}F8DepthVec operator-(const F8DepthVec&o)const{F8DepthVec r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}float norm2()const{return x*x+y*y+z*z;}void scale(float k){x*=k;y*=k;z*=k;}float dot(const F8DepthVec&o)const{return x*o.x+y*o.y+z*o.z;}};
struct F8DepthInterface{Ptr32<Ptr32<void>> vtable;};struct F8DepthContext{char p[48];Ptr32<F8DepthInterface> camera;};extern Ptr32<F8DepthContext> context_804b1788;
struct F8DepthOwner{char p[52];F8DepthVec position;char p2[12];Ptr32<void> upper;Ptr32<void> lower;};
extern "C" float f8b_depth_ratio_8011ba08(Ptr32<F8DepthOwner> s){Ptr32<F8DepthInterface> c=context_804b1788->camera;F8DepthVec target=*((Ptr32<Ptr32<const F8DepthVec> (Ptr32<F8DepthInterface>)>)c->vtable[15])(c);c=context_804b1788->camera;F8DepthVec origin=*((Ptr32<Ptr32<const F8DepthVec> (Ptr32<F8DepthInterface>)>)c->vtable[14])(c);F8DepthVec direction=target-origin;float zero=0.0f;if(direction.norm2()==zero)return zero;direction.scale(1.0f/sqrt_802e82c0(direction.norm2()));F8DepthVec offset=s->position-origin;float length=sqrt_802e82c0(offset.norm2());if(length==zero)return zero;offset.scale(1.0f/sqrt_802e82c0(offset.norm2()));float depth=length*offset.dot(direction);float upper=read_80178df0(s->upper);float lower=read_80178df0(s->lower);float result=1.0f;if(depth>upper)result=depth/upper;else if(depth<lower)result=depth/lower;return result;}


