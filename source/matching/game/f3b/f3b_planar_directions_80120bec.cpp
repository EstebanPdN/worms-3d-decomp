// Observed vector operations and partial layouts; semantic roles are inferred. Any unused frame reservation has unknown original purpose.
extern const float zero_8039b6dc[],one_8039b6e0[];extern "C" float sqrt_802e82c0(float);
struct Vec3{float x,y,z;float length2()const{return x*x+y*y+z*z;}void normalize(){float f=one_8039b6e0[0]/sqrt_802e82c0(length2());x*=f;y*=f;z*=f;}};
extern "C" void f3b_planar_directions_80120bec(void*,const Vec3*fallback,Vec3*a,Vec3*b,Vec3*outA,Vec3*outB){a->y=0.0f;if(a->length2()>0.0f){*outA=*a;outA->normalize();}else *outA=*fallback;b->y=0.0f;if(b->length2()>0.0f){*outB=*b;outB->normalize();}else *outB=*outA;}
