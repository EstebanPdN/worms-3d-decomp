// Inferred registration structure; observed GameCube 32-bit layout.
struct DefaultVector {
    float x, y, z;

    DefaultVector(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct VectorBinding {
    unsigned header[2];
    DefaultVector value;
};

typedef char VectorSize[sizeof(DefaultVector) == 12 ? 1 : -1];
typedef char ValueOffset[(unsigned)&((VectorBinding*)0)->value == 8 ? 1 : -1];

extern "C" {
void* sol35e4a_register_bits_801ebf38(void*, const void*);
void* sol35e4a_register_int_801eb834(void*, const void*);
void* sol35e4a_register_scalar_801ec52c(void*, const void*);
void* sol35e4a_register_value_801ec0f8(void*, const void*);
VectorBinding* sol35e4a_register_vector_801f0210(void*, const void*);
void sol35e4a_finish_801e8d9c(void*);

extern const unsigned char sol35e4a_desc_803c3580[];
extern const unsigned char sol35e4a_desc_803c35b4[];
extern const unsigned char sol35e4a_desc_803c35ec[];
extern const unsigned char sol35e4a_desc_803c3624[];
extern const unsigned char sol35e4a_desc_803c3658[];
extern const unsigned char sol35e4a_desc_803c3690[];
extern const unsigned char sol35e4a_desc_803c36c8[];
extern const unsigned char sol35e4a_desc_803c3700[];
extern const unsigned char sol35e4a_desc_803c3738[];
extern const unsigned char sol35e4a_desc_803c3770[];
extern const unsigned char sol35e4a_desc_803c37a4[];
extern const unsigned char sol35e4a_desc_803c37dc[];
extern const unsigned char sol35e4a_desc_803c3814[];
extern const unsigned char sol35e4a_desc_803c3848[];
extern const unsigned char sol35e4a_desc_803c387c[];
extern const unsigned char sol35e4a_desc_803c38a4[];
extern const unsigned char sol35e4a_desc_803c38d8[];
extern const unsigned char sol35e4a_desc_803c390c[];
extern const unsigned char sol35e4a_desc_803c3940[];
extern const unsigned char sol35e4a_desc_803c3974[];
extern const unsigned char sol35e4a_desc_803c39ac[];
extern const unsigned char sol35e4a_desc_803c39e4[];
extern const unsigned char sol35e4a_desc_803c3a18[];
extern const unsigned char sol35e4a_desc_803c3a50[];
extern const unsigned char sol35e4a_desc_803c3a88[];
extern const unsigned char sol35e4a_desc_803c3ac4[];
extern const unsigned char sol35e4a_desc_803c3afc[];
extern const unsigned char sol35e4a_desc_803c3b30[];
extern const unsigned char sol35e4a_desc_803c3b68[];
extern const unsigned char sol35e4a_desc_803c3b9c[];
extern const unsigned char sol35e4a_desc_803c3bd4[];
extern const unsigned char sol35e4a_desc_803c3c08[];
extern const unsigned char sol35e4a_desc_803c3c38[];
extern const float sol35e4a_default_803c3c5c[];

int sol35e4a_motion_descriptors_80247050(void* owner) {
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3580);
    sol35e4a_register_value_801ec0f8(owner, sol35e4a_desc_803c35b4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c35ec);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3624);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3658);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3690);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c36c8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3700);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3738);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3770);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c37a4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c37dc);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3814);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3848);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c387c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c38a4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c38d8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c390c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3940);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3974);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c39ac);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c39e4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3a18);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3a50);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3a88);
    sol35e4a_register_bits_801ebf38(owner, sol35e4a_desc_803c3ac4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3afc);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3b30);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3b68);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3b9c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c3bd4);
    sol35e4a_register_vector_801f0210(owner, sol35e4a_desc_803c3c08)->value =
        DefaultVector(0.0f, 0.0f, 0.0f);
    sol35e4a_register_vector_801f0210(owner, sol35e4a_desc_803c3c38)->value =
        DefaultVector(0.0f, 0.0f, 0.0f);
    sol35e4a_finish_801e8d9c(owner);
    return 0;
}
}
