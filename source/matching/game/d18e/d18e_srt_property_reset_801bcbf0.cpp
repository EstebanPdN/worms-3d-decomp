// Translate/Rotate/Scale property reset (Worms 3D GameCube PAL, 0x801bcbf0).
//
// Looks up the object's Translate, Rotate and Scale three-float vector
// properties (static descriptors with the name pointer at +0), stores
// (0,0,0) into Translate and Rotate and (1,1,1) into Scale (constants
// 0x803ab9d0 = 0.0f, 0x803ab9d4 = 1.0f), registers the RotateOrder member
// property, calls the refresh routine 0x801e8d9c and reports success.
//
// The binding view is partial: only the twelve-byte value at +8 is used.
// Same construction as the 0x801bce74 family: the first vector uses the
// inline constructor and direct assignment, later vectors are filled through
// a pointer and passed to the binding's inline set(const D18eSrtVec3 &).
// Built with -mps-float.

struct D18eSrtVec3 {
    float x, y, z;
    D18eSrtVec3() {}
    D18eSrtVec3(float a, float b, float c) { x = a; y = b; z = c; }
};

struct D18eSrtBinding {
    unsigned prefix[2];
    D18eSrtVec3 value;
    void set(const D18eSrtVec3 &v) { value = v; }
};

struct D18eSrtDescriptor;

extern "C" D18eSrtBinding *fn_801f0210(void *object, const D18eSrtDescriptor *descriptor);
extern "C" void * fn_801ece2c(void *object, const D18eSrtDescriptor *descriptor);
extern "C" void fn_801e8d9c(void *object);

extern "C" const D18eSrtDescriptor key_803ab934, key_803ab960, key_803ab984, key_803ab9a8;
extern "C" const float value_803ab9d0[];
extern "C" const float value_803ab9d4[];

extern "C" int w3d_d18e_reset_srt_801bcbf0(void *object)
{
    D18eSrtBinding *translate = fn_801f0210(object, &key_803ab934);
    float zero = value_803ab9d0[0];
    D18eSrtVec3 a(zero, zero, zero);
    translate->value = a;
    D18eSrtBinding *rotate = fn_801f0210(object, &key_803ab960);
    D18eSrtVec3 b;
    D18eSrtVec3 *q = &b;
    q->x = zero;
    q->y = zero;
    q->z = zero;
    rotate->set(b);
    D18eSrtBinding *scale = fn_801f0210(object, &key_803ab984);
    float one = value_803ab9d4[0];
    D18eSrtVec3 c;
    D18eSrtVec3 *r = &c;
    r->x = one;
    r->y = one;
    r->z = one;
    scale->set(c);
    fn_801ece2c(object, &key_803ab9a8);
    fn_801e8d9c(object);
    return 0;
}
