#include "w3d_ptr.h"
#line 1 "cx8b_quaternion_alias_apply_801a56b8.cpp"

struct Cx8bQuaternion { float x,y,z,w;
 Cx8bQuaternion(const Cx8bQuaternion &other) { float a=other.x,b=other.y,c=other.z,d=other.w;x=a;y=b;z=c;w=d; }
};
struct Cx8bQuaternionOwner { char unknown00[44]; Cx8bQuaternion rotation; };
extern "C" void fn_801f506c(Ptr32<Cx8bQuaternion>,Ptr32<const void>,Ptr32<const Cx8bQuaternion>);
extern "C" int w3d_cx8b_quaternion_alias_apply_801a56b8(Ptr32<Cx8bQuaternionOwner> self,Ptr32<Cx8bQuaternion> input,Ptr32<const void> operation) {
 if(input==&self->rotation) { Cx8bQuaternion copy(*input);fn_801f506c(input,operation,&copy); }
 else fn_801f506c(&self->rotation,operation,input);
 return 0;
}



