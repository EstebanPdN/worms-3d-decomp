#include "w3d_ptr.h"
#line 1 "cc36a_transform_cache_800b8cf0.cpp"

// Original 800b8cf0: compose two transforms and cache the inverse.
// Matrices are observed twelve-word values; the translation subobject has a
// native constructor. No complete owner class or sizeof claim is made.
struct cc36a_Vector_80343740 { float x,y,z; cc36a_Vector_80343740(); };
struct cc36a_Transform { float basis[9]; cc36a_Vector_80343740 translation; };
struct cc36a_TransformSet { cc36a_Transform first,second,third,fourth,fifth,sixth; };
struct cc36a_ActorView { Ptr32<void> vtable; Ptr32<cc36a_TransformSet> transforms; };
extern "C" void cc36a_combine_801f740c(Ptr32<cc36a_Transform>,Ptr32<const cc36a_Transform>,Ptr32<const cc36a_Transform>);
extern "C" int cc36a_inverse_801f76e0(Ptr32<cc36a_Transform>,Ptr32<const cc36a_Transform>);
extern "C" void cc36a_transform_cache_800b8cf0(Ptr32<cc36a_ActorView> self,Ptr32<const cc36a_Transform> input){
 cc36a_Transform value;
 cc36a_combine_801f740c(&value,&self->transforms->third,input);
 self->transforms->sixth=value;
 cc36a_combine_801f740c(&value,&self->transforms->second,input);
 self->transforms->fourth=value;
 cc36a_inverse_801f76e0(&value,&self->transforms->sixth);
 self->transforms->fifth=value;
}


