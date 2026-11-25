#include "w3d_ptr.h"
#line 1 "k5a_vec_offset_8001bbb0.cpp"
struct K5aVec3
{
    float x, y, z;
    K5aVec3() {}
    K5aVec3(float a, float b, float c) { x = a; y = b; z = c; }
    K5aVec3(const K5aVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    K5aVec3 plus(const K5aVec3 &o) const { K5aVec3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
extern "C" const float w3d_f32_8036b074[];
extern "C" const float w3d_f32_8036b078[];

extern "C" K5aVec3 k5a_vec_offset_8001bbb0(Ptr32<const K5aVec3> in)
{
    K5aVec3 off(w3d_f32_8036b074[0], w3d_f32_8036b078[0], w3d_f32_8036b074[0]);
    return in->plus(off);
}


