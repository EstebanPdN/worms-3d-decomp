// Bounds/shape property reset (Worms 3D GameCube PAL, 0x801c3da8).
//
// Looks up the object's Min and Max three-float vector properties (static
// descriptors with the name pointer at +0), stores the constant at
// 0x803ac9f8 (0.0f) into all three components of each, registers the
// ShapeCount, ShapeIndex, Left and Right typed properties, calls the refresh
// routine 0x801e8d9c and reports success.
//
// The binding view is partial: only the twelve-byte value at +8 is used.
// Same construction as the 0x801bce74 family: the first vector uses the
// inline constructor and direct assignment, the second is filled through a
// pointer and passed to the binding's inline set(const D18eBoundsVec3 &).
// Built with -mps-float.

struct D18eBoundsVec3 {
    float x, y, z;
    D18eBoundsVec3() {}
    D18eBoundsVec3(float a, float b, float c) { x = a; y = b; z = c; }
};

struct D18eBoundsBinding {
    unsigned prefix[2];
    D18eBoundsVec3 value;
    void set(const D18eBoundsVec3 &v) { value = v; }
};

struct D18eBoundsDescriptor;

extern "C" D18eBoundsBinding *fn_801f0504(void *object, const D18eBoundsDescriptor *descriptor);
extern "C" void * fn_801ebbb8(void *object, const D18eBoundsDescriptor *descriptor);
extern "C" void fn_801e8d9c(void *object);

extern "C" const D18eBoundsDescriptor key_803ac900, key_803ac924, key_803ac948;
extern "C" const D18eBoundsDescriptor key_803ac970, key_803ac9a0, key_803ac9d0;
extern "C" const float value_803ac9f8[];

extern "C" int w3d_d18e_reset_bounds_801c3da8(void *object)
{
    D18eBoundsBinding *minimum = fn_801f0504(object, &key_803ac900);
    float v = value_803ac9f8[0];
    D18eBoundsVec3 a(v, v, v);
    minimum->value = a;
    D18eBoundsBinding *maximum = fn_801f0504(object, &key_803ac924);
    D18eBoundsVec3 b;
    D18eBoundsVec3 *q = &b;
    q->x = v;
    q->y = v;
    q->z = v;
    maximum->set(b);
    fn_801ebbb8(object, &key_803ac948);
    fn_801ebbb8(object, &key_803ac970);
    fn_801ebbb8(object, &key_803ac9a0);
    fn_801ebbb8(object, &key_803ac9d0);
    fn_801e8d9c(object);
    return 0;
}
