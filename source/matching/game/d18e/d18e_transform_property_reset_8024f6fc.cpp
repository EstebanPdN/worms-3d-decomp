// Transform-property reset helpers (Worms 3D GameCube PAL, 0x8024f6fc pair).
//
// Both helpers register the object's Position, Size and Orientation
// three-float vector properties (static descriptors with the name pointer
// at +0) and store a vector built from the adjacent float constant (0.0f in
// the DOL) into the value at +8 of each returned binding. 0x8024f6fc first
// adds the "Flags" link descriptor; 0x8024f990 registers the "Type" typed
// property afterwards. Both then call the refresh routine 0x801e8d9c and
// report success.
//
// The binding view is partial: only the twelve-byte value at +8 is used.
// As in the 0x801bce74 family, the first vector is built with the inline
// constructor and assigned directly; later vectors are filled member by
// member through a pointer and passed to the binding's inline
// set(const D18eTransformVec3 &) member. Built with -mps-float.

struct D18eTransformVec3 {
    float x, y, z;
    D18eTransformVec3() {}
    D18eTransformVec3(float a, float b, float c) { x = a; y = b; z = c; }
};

struct D18eTransformBinding {
    unsigned prefix[2];
    D18eTransformVec3 value;
    void set(const D18eTransformVec3 &v) { value = v; }
};

struct D18eTransformDescriptor;

extern "C" void * fn_801ebf38(void *object, const D18eTransformDescriptor *descriptor);
extern "C" void * fn_801eb834(void *object, const D18eTransformDescriptor *descriptor);
extern "C" D18eTransformBinding *fn_801f0210(void *object, const D18eTransformDescriptor *descriptor);
extern "C" void fn_801e8d9c(void *object);

extern "C" const D18eTransformDescriptor key_803c5628, key_803c5650, key_803c567c, key_803c56a0;
extern "C" const D18eTransformDescriptor key_803c56cc, key_803c56f0, key_803c5714, key_803c5740;
extern "C" const float value_803c56c4[];
extern "C" const float value_803c5768[];

extern "C" int w3d_d18e_reset_flagged_transform_8024f6fc(void *object)
{
    fn_801ebf38(object, &key_803c5628);
    D18eTransformBinding *position = fn_801f0210(object, &key_803c5650);
    float v = value_803c56c4[0];
    D18eTransformVec3 a(v, v, v);
    position->value = a;
    D18eTransformBinding *size = fn_801f0210(object, &key_803c567c);
    D18eTransformVec3 b;
    D18eTransformVec3 *q = &b;
    q->x = v;
    q->y = v;
    q->z = v;
    size->set(b);
    D18eTransformBinding *orientation = fn_801f0210(object, &key_803c56a0);
    D18eTransformVec3 c;
    D18eTransformVec3 *r = &c;
    r->x = v;
    r->y = v;
    r->z = v;
    orientation->set(c);
    fn_801e8d9c(object);
    return 0;
}

extern "C" int w3d_d18e_reset_typed_transform_8024f990(void *object)
{
    D18eTransformBinding *position = fn_801f0210(object, &key_803c56cc);
    float v = value_803c5768[0];
    D18eTransformVec3 a(v, v, v);
    position->value = a;
    D18eTransformBinding *size = fn_801f0210(object, &key_803c56f0);
    D18eTransformVec3 b;
    D18eTransformVec3 *q = &b;
    q->x = v;
    q->y = v;
    q->z = v;
    size->set(b);
    D18eTransformBinding *orientation = fn_801f0210(object, &key_803c5714);
    D18eTransformVec3 c;
    D18eTransformVec3 *r = &c;
    r->x = v;
    r->y = v;
    r->z = v;
    orientation->set(c);
    fn_801eb834(object, &key_803c5740);
    fn_801e8d9c(object);
    return 0;
}
