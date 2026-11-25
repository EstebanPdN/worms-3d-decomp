// DOL literals 803b15dc/803b15e0 decode to 7f7fffff/ff7fffff.
// These eight source-owned data bytes lie outside the worker text range and
// require parent ownership review. Original NaN comparison behavior retained.
// Inferred axis-aligned bounds over four-float-stride points. Native Vec3 locals preserve
// constructor and aggregate-copy lifetimes; this is not the full original type.
struct cc37b_StridedVec3 {
 float x,y,z;
 inline cc37b_StridedVec3(float a,float b,float c) { x=a; y=b; z=c; }
};
struct cc37b_StridedPoint {float x,y,z,unusedW;};
struct cc37b_StridedBox {cc37b_StridedVec3 lower,upper;};
extern "C" void w3d_cc37b_bounds_801f5c1c(cc37b_StridedBox* out,const cc37b_StridedPoint* points,int count) {
 cc37b_StridedVec3 lower(3.4028234663852886e38f,3.4028234663852886e38f,3.4028234663852886e38f);
 cc37b_StridedVec3 upper(-3.4028234663852886e38f,-3.4028234663852886e38f,-3.4028234663852886e38f);
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
