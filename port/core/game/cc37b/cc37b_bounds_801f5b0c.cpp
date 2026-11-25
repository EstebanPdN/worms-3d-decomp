#include "w3d_ptr.h"
#line 1 "cc37b_bounds_801f5b0c.cpp"
// DOL literals 803b15d4/803b15d8 decode to 7f7fffff/ff7fffff.
// These eight source-owned data bytes lie outside the worker text range and
// require parent ownership review. Original NaN comparison behavior retained.
// Inferred axis-aligned bounds over packed points. Native Vec3 locals preserve
// constructor and aggregate-copy lifetimes; this is not the full original type.
struct cc37b_Vec3 {
 float x,y,z;
 inline cc37b_Vec3(float a,float b,float c) { x=a; y=b; z=c; }
};
struct cc37b_Point {float x,y,z;};
struct cc37b_Box {cc37b_Vec3 lower,upper;};
extern "C" void w3d_cc37b_bounds_801f5b0c(Ptr32<cc37b_Box> out,Ptr32<const cc37b_Point> points,int count) {
 cc37b_Vec3 lower(3.4028234663852886e38f,3.4028234663852886e38f,3.4028234663852886e38f);
 cc37b_Vec3 upper(-3.4028234663852886e38f,-3.4028234663852886e38f,-3.4028234663852886e38f);
 if(count>0) do {
  float x=points->x; if(x<lower.x) lower.x=x;
  float y=points->y; if(y<lower.y) lower.y=y;
  float z=points->z; if(z<lower.z) lower.z=z;
  if(x>upper.x) upper.x=x;
  if(y>upper.y) upper.y=y;
  if(z>upper.z) upper.z=z;
  ++points;
 } while(--count);
 out->lower=lower; out->upper=upper;
}


