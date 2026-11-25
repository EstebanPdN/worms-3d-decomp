// Original 0x8001c250: offset a point with two scaled vectors; semantic role inferred.
struct cc25a_Vector1c250 {float x,y,z;
 cc25a_Vector1c250(){}
 cc25a_Vector1c250(const cc25a_Vector1c250&v){x=v.x;y=v.y;z=v.z;}
 cc25a_Vector1c250(float a,float b,float c){x=a;y=b;z=c;}
 cc25a_Vector1c250 operator*(float s)const{return cc25a_Vector1c250(x*s,y*s,z*s);}
 cc25a_Vector1c250& operator=(const cc25a_Vector1c250&v){x=v.x;y=v.y;z=v.z;return *this;}
 void operator+=(const cc25a_Vector1c250&v){x+=v.x;y+=v.y;z+=v.z;}
};
extern float cc25a_drop_8036b0b4[],cc25a_scale_8036b0b8[],cc25a_factor_8036b0bc[],cc25a_bias_8036b0c0[];
extern "C" cc25a_Vector1c250 cc25a_vector_scaled_offsets_8001c250(const cc25a_Vector1c250 *origin,const cc25a_Vector1c250 *first,const cc25a_Vector1c250 *second,float amount){
 cc25a_Vector1c250 point(*origin);
 point.y-=517.5f;
 cc25a_Vector1c250 delta;
 cc25a_Vector1c250 firstScaled=*first*68.0f;delta=firstScaled;point+=delta;
 cc25a_Vector1c250 secondScaled=*second*(amount*14.0f+17.5f);delta=secondScaled;point+=delta;
 return point;
}
