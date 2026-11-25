#include "w3d_ptr.h"
#line 1 "cc25a_vector_scaled_offsets_8001c134.cpp"
// Original 0x8001c134: offset a point with two scaled vectors; semantic role inferred.
struct cc25a_Vector1c134 {float x,y,z;
 cc25a_Vector1c134(){}
 cc25a_Vector1c134(const cc25a_Vector1c134&v){x=v.x;y=v.y;z=v.z;}
 cc25a_Vector1c134(float a,float b,float c){x=a;y=b;z=c;}
 cc25a_Vector1c134 operator*(float s)const{return cc25a_Vector1c134(x*s,y*s,z*s);}
 cc25a_Vector1c134& operator=(const cc25a_Vector1c134&v){x=v.x;y=v.y;z=v.z;return *this;}
 void operator+=(const cc25a_Vector1c134&v){x+=v.x;y+=v.y;z+=v.z;}
};
extern float cc25a_drop_8036b0a4[],cc25a_scale_8036b0a8[],cc25a_factor_8036b0ac[],cc25a_bias_8036b0b0[];
extern "C" cc25a_Vector1c134 cc25a_vector_scaled_offsets_8001c134(Ptr32<const cc25a_Vector1c134> origin,Ptr32<const cc25a_Vector1c134> first,Ptr32<const cc25a_Vector1c134> second,float amount){
 cc25a_Vector1c134 point(*origin);
 point.y-=29.0f;
 cc25a_Vector1c134 delta;
 cc25a_Vector1c134 firstScaled=*first*21.0f;delta=firstScaled;point+=delta;
 cc25a_Vector1c134 secondScaled=*second*(amount*4.0f+7.0f);delta=secondScaled;point+=delta;
 return point;
}


