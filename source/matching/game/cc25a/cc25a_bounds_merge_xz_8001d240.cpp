// Original 0x8001d240: merge X/Z bounds when overlap passes an ordered tolerance test.
// Reference-return min/max preserve original operand choice on unordered values.
struct cc25a_Bounds1d240 {unsigned int unknown0;float minX,minY,minZ,maxX,maxY,maxZ;};
inline const float& cc25a_min1d240(const float&a,const float&b){return b<a?b:a;}
inline const float& cc25a_max1d240(const float&a,const float&b){return a<b?b:a;}
// Original decoded float tolerance; independently matched as owned literal.
extern "C" int cc25a_bounds_merge_xz_8001d240(cc25a_Bounds1d240 *a,const cc25a_Bounds1d240 *b){
 float x=cc25a_max1d240(a->minX,b->minX);
 float z=cc25a_max1d240(a->minZ,b->minZ);
 float xx=cc25a_min1d240(a->maxX,b->maxX);
 float zz=cc25a_min1d240(a->maxZ,b->maxZ);
 if(x>=xx+40.0f || z>=zz+40.0f)return 0;
 a->minX=cc25a_min1d240(a->minX,b->minX);
 a->minZ=cc25a_min1d240(a->minZ,b->minZ);
 a->maxX=cc25a_max1d240(a->maxX,b->maxX);
 a->maxZ=cc25a_max1d240(a->maxZ,b->maxZ);
 return 1;
}
