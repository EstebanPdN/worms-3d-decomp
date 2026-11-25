#include "w3d_ptr.h"
#line 1 "cx7a_grid_probe_named_8001f1d8.cpp"

// For a valid index, copy its vector and probe with height +0x68 plus tuning.
// A nonzero probe result triggers an update, receiving that result in r4.
struct Cx7aVec3 {float x,y,z;Cx7aVec3(const Cx7aVec3 &o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;} };
struct Cx7aGrid {unsigned char unknown[104];float height;};
extern const float tuning_8036b8ac[];
extern "C" Ptr32<const Cx7aVec3> vector_80015588(int);
extern "C" int probe_8001f30c(Ptr32<Cx7aGrid>,Ptr32<const Cx7aVec3>,float);
extern "C" int update_8001f904(Ptr32<Cx7aGrid>,Ptr32<void>);
extern "C" void w3d_cx7a_grid_probe_named_8001f1d8(Ptr32<Cx7aGrid> self,int index) {if(index!=-1) {Cx7aVec3 value(*vector_80015588(index));int result=probe_8001f30c(self,&value,self->height+tuning_8036b8ac[0]);if(result) update_8001f904(self,(Ptr32<void>)w3d::G(result));}}


