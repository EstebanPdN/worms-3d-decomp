#include "w3d_ptr.h"
#line 1 "d18e_vector_property_reset_801bce74.cpp"
// Vector-property reset helpers (Worms 3D GameCube PAL, 0x801bce74 family).
//
// Each helper looks up two three-float vector properties on the object by
// their static descriptors (name pointer at +0: "RotatePivot"/"ScalePivot",
// "RotateAxis"/"JointOrientation", "PlaneXAxis"/"PlaneYAxis"), stores a
// vector built from the descriptor-adjacent float constant (0.0f in the DOL)
// into the value at +8 of each returned binding, then calls the object's
// refresh routine 0x801e8d9c and reports success.
//
// The binding view is partial: only the twelve-byte value at +8 is used.
// The first vector is built with the inline constructor and assigned
// directly; the second is filled member by member through a pointer and
// passed to the binding's inline set(const D18eVec3 &) member. That pairing
// reproduces the original's mixed register/stack-relative copies.
// Built with -mps-float (paired-single FPR save area, parent decision d15).

struct D18eVec3 {
    float x, y, z;
    D18eVec3() {}
    D18eVec3(float a, float b, float c) { x = a; y = b; z = c; }
};

struct D18eVecBinding {
    unsigned prefix[2];
    D18eVec3 value;
    void set(const D18eVec3 &v) { value = v; }
};

struct D18ePropertyDescriptor;

extern "C" Ptr32<D18eVecBinding> fn_801f0504(Ptr32<void> object, Ptr32<const D18ePropertyDescriptor> descriptor);
extern "C" Ptr32<D18eVecBinding> fn_801f0210(Ptr32<void> object, Ptr32<const D18ePropertyDescriptor> descriptor);
extern "C" void fn_801e8d9c(Ptr32<void> object);

extern "C" const D18ePropertyDescriptor key_803ab9f8, key_803aba28;
extern "C" const D18ePropertyDescriptor key_803aba70, key_803abaa8;
extern "C" const D18ePropertyDescriptor key_803ac5f0, key_803ac620;
extern "C" const float value_803aba4c[];
extern "C" const float value_803abacc[];
extern "C" const float value_803ac644[];

extern "C" int w3d_d18e_reset_pivots_801bce74(Ptr32<void> object)
{
    Ptr32<D18eVecBinding> rotate = fn_801f0504(object, &key_803ab9f8);
    float v = value_803aba4c[0];
    D18eVec3 a(v, v, v);
    rotate->value = a;
    Ptr32<D18eVecBinding> scale = fn_801f0504(object, &key_803aba28);
    D18eVec3 b;
    Ptr32<D18eVec3> q = &b;
    q->x = v;
    q->y = v;
    q->z = v;
    scale->set(b);
    fn_801e8d9c(object);
    return 0;
}

extern "C" int w3d_d18e_reset_joint_axes_801bd0a0(Ptr32<void> object)
{
    Ptr32<D18eVecBinding> axis = fn_801f0210(object, &key_803aba70);
    float v = value_803abacc[0];
    D18eVec3 a(v, v, v);
    axis->value = a;
    Ptr32<D18eVecBinding> orientation = fn_801f0210(object, &key_803abaa8);
    D18eVec3 b;
    Ptr32<D18eVec3> q = &b;
    q->x = v;
    q->y = v;
    q->z = v;
    orientation->set(b);
    fn_801e8d9c(object);
    return 0;
}

extern "C" int w3d_d18e_reset_plane_axes_801c16ec(Ptr32<void> object)
{
    Ptr32<D18eVecBinding> xaxis = fn_801f0210(object, &key_803ac5f0);
    float v = value_803ac644[0];
    D18eVec3 a(v, v, v);
    xaxis->value = a;
    Ptr32<D18eVecBinding> yaxis = fn_801f0210(object, &key_803ac620);
    D18eVec3 b;
    Ptr32<D18eVec3> q = &b;
    q->x = v;
    q->y = v;
    q->z = v;
    yaxis->set(b);
    fn_801e8d9c(object);
    return 0;
}


