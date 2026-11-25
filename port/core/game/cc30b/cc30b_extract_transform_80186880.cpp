#include "w3d_ptr.h"
#line 1 "cc30b_extract_transform_80186880.cpp"
// Inferred transform extraction. Source views cover observed offsets and copy extent.
typedef unsigned int cc30b_u32;
extern "C" void fn_80343740(Ptr32<void>);
struct cc30b_Vector_80343740 {float x,y,z;cc30b_Vector_80343740(){fn_80343740(this);}
};
struct cc30b_Transform_80186880 {float rotation[9];cc30b_Vector_80343740 position;};
struct cc30b_Node_80186880;
struct cc30b_NodeVtable_80186880 {Ptr32<void> slots[7];Ptr32<int (Ptr32<cc30b_Node_80186880>)> has_parent;};
struct cc30b_Node_80186880 {Ptr32<cc30b_NodeVtable_80186880> vtable;cc30b_u32 gap[2];cc30b_Vector_80343740 position;float angles[3];float scale[3];cc30b_u32 gap30[2];cc30b_Transform_80186880 parent;};
extern "C" void fn_801a3eb0(Ptr32<float>,int,Ptr32<cc30b_Transform_80186880>);
extern "C" void fn_801f6448(Ptr32<cc30b_Transform_80186880>,float,float,float);
extern "C" void fn_801f740c(Ptr32<cc30b_Transform_80186880>,Ptr32<cc30b_Transform_80186880>,Ptr32<cc30b_Transform_80186880>);
extern "C" int w3d_cc30b_extract_transform_80186880(Ptr32<cc30b_Node_80186880> self,Ptr32<cc30b_Transform_80186880> out){
 cc30b_Transform_80186880 transform;
 fn_801a3eb0(self->angles,0,&transform);
 fn_801f6448(&transform,self->scale[0],self->scale[1],self->scale[2]);
 transform.position=self->position;
 if(self->vtable->has_parent(self)==0)*out=transform;
 else fn_801f740c(out,&transform,&self->parent);
 return 0;
}


