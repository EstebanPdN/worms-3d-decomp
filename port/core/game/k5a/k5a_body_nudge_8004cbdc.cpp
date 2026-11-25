#include "w3d_ptr.h"
#line 1 "k5a_body_nudge_8004cbdc.cpp"
struct K5aVec3
{
    float x, y, z;
    K5aVec3(float a, float b, float c) { x = a; y = b; z = c; }
    K5aVec3(const K5aVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    K5aVec3 scaled(float k) const { K5aVec3 r(x * k, y * k, z * k); return r; }
    void add(const K5aVec3 &o) { x += o.x; y += o.y; z += o.z; }
};
struct K5aBody { char pad0[52]; K5aVec3 pos; char pad1[36]; int cleared; char pad2[12]; int pending; };

extern "C" void k5a_body_nudge_8004cbdc(Ptr32<K5aBody> self, Ptr32<const K5aVec3> dir, float scale)
{
    if (self->pending != 0) {
        self->pos.add(dir->scaled(scale));
        self->cleared = 0;
    }
}


