#include "w3d_ptr.h"
#line 1 "cx13b_sphere_bounds_801f5724.cpp"
// PPC32 vectors are twelve bytes; bounds contain lower and upper vectors.
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}};struct Box{Vec3 lower,upper;};

struct Sphere{Vec3 center;float radius;};extern "C" const float zero_803b15b4[];extern "C" const Box empty_8045e690;
extern "C" void w3d_cx13b_sphere_bounds_801f5724(Ptr32<Box> out,Ptr32<const Sphere> s){if(s->radius<zero_803b15b4[0]){*out=empty_8045e690;return;}out->lower.x=s->center.x-s->radius;out->upper.x=s->center.x+s->radius;out->lower.y=s->center.y-s->radius;out->upper.y=s->center.y+s->radius;out->lower.z=s->center.z-s->radius;out->upper.z=s->center.z+s->radius;}



