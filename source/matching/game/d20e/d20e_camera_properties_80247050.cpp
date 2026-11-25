// Camera property registration (Worms 3D GameCube PAL, 0x80247050).
//
// Registers the camera tuning properties of its owner in order: scalar
// bindings (0x801ec52c) for AntiGimScale and DefaultHeight..OccZoomOutSpeed
// and PosUpdateSpeed..ZoomOffsetDist, the value binding DblHitThres
// (0x801ec0f8), the bit binding TimeBeforeZoomOut (0x801ebf38), then the
// vector bindings TailOffset and HeadOffset (0x801f0210), both reset to the
// constant at 0x803c3c5c (0.0f) in all components; calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers in the original data; descriptor layouts stay external.
//
// Derived from the never-proved draft sol35e4a_motion_descriptors_80247050
// (v3). The second vector is filled through a pointer and copied with an
// inline set(const DefaultVector &) (d18e vector recipe), which gives the
// original frame-relative loads. Built with -mps-float (one saved FPR in a
// non-leaf function). Observed GameCube 32-bit layout.
struct DefaultVector {
    float x, y, z;

    DefaultVector() {}
    DefaultVector(float value) : x(value), y(value), z(value) {}
};

struct VectorBinding {
    unsigned header[2];
    DefaultVector value;
    void set(const DefaultVector &v) { value = v; }
};

typedef char VectorSize[sizeof(DefaultVector) == 12 ? 1 : -1];
typedef char ValueOffset[(unsigned)&((VectorBinding*)0)->value == 8 ? 1 : -1];

extern "C" {
void* d20e_register_bits_801ebf38(void*, const void*);
void* d20e_register_int_801eb834(void*, const void*);
void* d20e_register_scalar_801ec52c(void*, const void*);
void* d20e_register_value_801ec0f8(void*, const void*);
VectorBinding* d20e_register_vector_801f0210(void*, const void*);
void d20e_finish_801e8d9c(void*);

extern const unsigned char d20e_desc_803c3580[];   // AntiGimScale
extern const unsigned char d20e_desc_803c35b4[];   // DblHitThres
extern const unsigned char d20e_desc_803c35ec[];   // DefaultHeight
extern const unsigned char d20e_desc_803c3624[];   // DistFromObject
extern const unsigned char d20e_desc_803c3658[];   // HeightSpeed
extern const unsigned char d20e_desc_803c3690[];   // LkAboveSpdScale
extern const unsigned char d20e_desc_803c36c8[];   // LookAboveObject
extern const unsigned char d20e_desc_803c3700[];   // LookAheadScale
extern const unsigned char d20e_desc_803c3738[];   // LookAheadSpeed
extern const unsigned char d20e_desc_803c3770[];   // LookUpdateSpeed
extern const unsigned char d20e_desc_803c37a4[];   // MaxHeight
extern const unsigned char d20e_desc_803c37dc[];   // MaxLkAheadDist
extern const unsigned char d20e_desc_803c3814[];   // MaxLookAboveObj
extern const unsigned char d20e_desc_803c3848[];   // MinHeight
extern const unsigned char d20e_desc_803c387c[];   // MinLookAt
extern const unsigned char d20e_desc_803c38a4[];   // MinPosition
extern const unsigned char d20e_desc_803c38d8[];   // MinZoomDist
extern const unsigned char d20e_desc_803c390c[];   // MouseXSpeed
extern const unsigned char d20e_desc_803c3940[];   // MouseYSpeed
extern const unsigned char d20e_desc_803c3974[];   // OccDestSize
extern const unsigned char d20e_desc_803c39ac[];   // OccHeightSpeed
extern const unsigned char d20e_desc_803c39e4[];   // OcclusionSize
extern const unsigned char d20e_desc_803c3a18[];   // OccYawSpeed
extern const unsigned char d20e_desc_803c3a50[];   // OccZoomInSpeed
extern const unsigned char d20e_desc_803c3a88[];   // OccZoomOutSpeed
extern const unsigned char d20e_desc_803c3ac4[];   // TimeBeforeZoomOut
extern const unsigned char d20e_desc_803c3afc[];   // PosUpdateSpeed
extern const unsigned char d20e_desc_803c3b30[];   // StartYaw
extern const unsigned char d20e_desc_803c3b68[];   // UpUpdateSpeed
extern const unsigned char d20e_desc_803c3b9c[];   // YawSpeed
extern const unsigned char d20e_desc_803c3bd4[];   // ZoomOffsetDist
extern const unsigned char d20e_desc_803c3c08[];   // TailOffset
extern const unsigned char d20e_desc_803c3c38[];   // HeadOffset
extern const float d20e_default_803c3c5c[];

int w3d_d20e_register_camera_properties_80247050(void* owner) {
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3580);
    d20e_register_value_801ec0f8(owner, d20e_desc_803c35b4);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c35ec);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3624);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3658);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3690);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c36c8);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3700);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3738);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3770);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c37a4);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c37dc);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3814);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3848);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c387c);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c38a4);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c38d8);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c390c);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3940);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3974);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c39ac);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c39e4);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3a18);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3a50);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3a88);
    d20e_register_bits_801ebf38(owner, d20e_desc_803c3ac4);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3afc);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3b30);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3b68);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3b9c);
    d20e_register_scalar_801ec52c(owner, d20e_desc_803c3bd4);
    VectorBinding* binding1 = d20e_register_vector_801f0210(owner, d20e_desc_803c3c08);
    const float default_value = d20e_default_803c3c5c[0];
    const DefaultVector& vector1 = DefaultVector(default_value);
    binding1->value = vector1;
    VectorBinding* binding2 = d20e_register_vector_801f0210(owner, d20e_desc_803c3c38);
    DefaultVector vector2;
    DefaultVector *fill = &vector2;
    fill->x = default_value;
    fill->y = default_value;
    fill->z = default_value;
    binding2->set(vector2);
    d20e_finish_801e8d9c(owner);
    return 0;
}
}
