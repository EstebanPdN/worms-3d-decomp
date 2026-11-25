#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_object_apply_vector_800dfe20.c"
typedef struct K4aVec3 { float x, y, z; } K4aVec3;
typedef struct K4aObject { char pad0[72]; float y_value; char pad1[40]; float x_value; } K4aObject;
extern const float w3d_f32_80389ce8[];
extern Ptr32<K4aObject> w3d_auto_800dfdf4(Ptr32<void> self);
extern void FUN_801a3eb0(Ptr32<K4aVec3> v, int a, Ptr32<void> b);

Ptr32<K4aObject> k4a_object_apply_vector_800dfe20(Ptr32<void> self, int arg)
{
    Ptr32<K4aObject> obj = w3d_auto_800dfdf4(self);
    K4aVec3 v;
    v.x = -obj->x_value;
    v.y = obj->y_value;
    v.z = w3d_f32_80389ce8[0];
    FUN_801a3eb0(&v, 0, w3d::G(arg));
    return obj;
}

}
