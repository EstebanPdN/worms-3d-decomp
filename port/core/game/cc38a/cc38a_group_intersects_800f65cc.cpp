#include "w3d_ptr.h"
#line 1 "cc38a_group_intersects_800f65cc.cpp"

// Nested collision query over two dynamic arrays. Array end/begin differences
// are signed pointer differences converted to the original unsigned count.
struct cc38a_Bounds;
struct cc38a_Array {Ptr32<Ptr32<cc38a_Bounds>> begin;Ptr32<Ptr32<cc38a_Bounds>> end;Ptr32<Ptr32<cc38a_Bounds>> capacity;unsigned size()const{return end-begin;} Ptr32<cc38a_Bounds> at(unsigned i)const{return *(Ptr32<Ptr32<cc38a_Bounds>>)((Ptr32<char>)begin+(i<<2));} };
struct cc38a_Group {unsigned char unknown[16];cc38a_Array bounds;};
extern "C" int cc38a_intersects_800c59cc(Ptr32<cc38a_Bounds>,Ptr32<cc38a_Bounds>);
extern "C" int cc38a_group_intersects_800f65cc(Ptr32<void> context,Ptr32<cc38a_Group> a,Ptr32<cc38a_Group> b){
 for(unsigned i=0;i<a->bounds.size();++i)
  for(unsigned j=0;j<b->bounds.size();++j)
   if(cc38a_intersects_800c59cc(a->bounds.at(i),b->bounds.at(j)))return 1;
 return 0;
}


