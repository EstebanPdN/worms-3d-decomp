// Inferred registration structure; observed GameCube 32-bit layout.
struct DefaultVector {
    float x, y, z;

    DefaultVector(float value) : x(value), y(value), z(value) {}
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

extern const unsigned char sol35e4a_desc_803c5628[];
extern const unsigned char sol35e4a_desc_803c5650[];
extern const unsigned char sol35e4a_desc_803c567c[];
extern const unsigned char sol35e4a_desc_803c56a0[];
extern const float sol35e4a_default_803c56c4[];

int sol35e4a_transform_descriptors_8024f6fc(void* owner) {
    sol35e4a_register_bits_801ebf38(owner, sol35e4a_desc_803c5628);
    VectorBinding* binding1 = sol35e4a_register_vector_801f0210(owner, sol35e4a_desc_803c5650);
    const float default_value = sol35e4a_default_803c56c4[0];
    const DefaultVector& vector1 = DefaultVector(default_value);
    binding1->value = vector1;
    VectorBinding* binding2 = sol35e4a_register_vector_801f0210(owner, sol35e4a_desc_803c567c);
    const DefaultVector& vector2 = DefaultVector(default_value);
    binding2->value = vector2;
    VectorBinding* binding3 = sol35e4a_register_vector_801f0210(owner, sol35e4a_desc_803c56a0);
    const DefaultVector& vector3 = DefaultVector(default_value);
    binding3->value = vector3;
    sol35e4a_finish_801e8d9c(owner);
    return 0;
}
}
