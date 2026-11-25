// Sixteen trailing frame bytes have unknown original purpose.
// Inferred vector layout and direction-to-angle conversion.
struct F7BackAngleVec{float x,y,z;F7BackAngleVec(){}F7BackAngleVec(const F7BackAngleVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}float norm2()const{return x*x+y*y+z*z;}void scale(float k){x*=k;y*=k;z*=k;}};
extern const F7BackAngleVec default_8045e788[];extern const float zero_8038000c[],one_80380010[],turn_80380014[];extern "C" float sqrt_802e82c0(float),acos_802e7c30(float);
extern "C" F7BackAngleVec f7b_direction_angles_8009b070(void*,const F7BackAngleVec*v){F7BackAngleVec q=*v;F7BackAngleVec out=default_8045e788[0];float zero=0.0f;float n=q.norm2();if(n>zero){q.scale(1.0f/sqrt_802e82c0(n));F7BackAngleVec planar;planar=q;planar.y=zero;float pn=planar.norm2();if(pn>zero){planar.scale(1.0f/sqrt_802e82c0(pn));float yaw=-acos_802e7c30(planar.x);if(q.z>zero)yaw=turn_80380014[0]-yaw;out.y=yaw;}out.x=-acos_802e7c30(q.y);}out.y+=turn_80380014[0];return out;}
