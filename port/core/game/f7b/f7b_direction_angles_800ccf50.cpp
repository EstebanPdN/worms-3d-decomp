#include "w3d_ptr.h"
#line 1 "f7b_direction_angles_800ccf50.cpp"
// Sixteen trailing frame bytes have unknown original purpose.
// Inferred vector layout and direction-to-angle conversion.
struct F7AngleVec{float x,y,z;F7AngleVec(){}F7AngleVec(const F7AngleVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}float norm2()const{return x*x+y*y+z*z;}void scale(float k){x*=k;y*=k;z*=k;}};
extern const F7AngleVec default_8045e788[];extern const float zero_80387e18[],one_80387e1c[],turn_80387e20[];extern "C" float sqrt_802e82c0(float),acos_802e7c30(float);
extern "C" F7AngleVec f7b_direction_angles_800ccf50(Ptr32<void>,Ptr32<const F7AngleVec> v){F7AngleVec q=*v;F7AngleVec out=default_8045e788[0];float zero=0.0f;float n=q.norm2();if(n>zero){q.scale(1.0f/sqrt_802e82c0(n));F7AngleVec planar;planar=q;planar.y=zero;float pn=planar.norm2();if(pn>zero){planar.scale(1.0f/sqrt_802e82c0(pn));float yaw=-acos_802e7c30(planar.x);if(q.z>zero)yaw=turn_80387e20[0]-yaw;out.y=yaw;}out.x=acos_802e7c30(q.y);}return out;}


