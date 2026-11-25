// Inferred descriptor registration at 0x8024434c, GC32 ABI.
struct Sol35e3DefaultVector {
    float x, y, z;
    Sol35e3DefaultVector(float value) : x(value), y(value), z(value) {}
};
struct Sol35e3VectorBinding {
    unsigned unknown00[2];
    Sol35e3DefaultVector value;
};
extern "C" {
void* sol35e3_register_u16_801ebbb8(void*, const void*);
void* sol35e3_register_scalar_801ec52c(void*, const void*);
void* sol35e3_register_bool_801eb674(void*, const void*);
void* sol35e3_register_int_801eb834(void*, const void*);
void* sol35e3_register_kind_801ece2c(void*, const void*);
Sol35e3VectorBinding* sol35e3_register_vector_801f0210(void*, const void*);
void sol35e3_finish_descriptors_801e8d9c(void*);
extern const unsigned char sol35e3_desc_803c0254[], sol35e3_desc_803c0298[];
extern const unsigned char sol35e3_desc_803c02d8[], sol35e3_desc_803c0300[];
extern const unsigned char sol35e3_desc_803c0328[], sol35e3_desc_803c036c[];
extern const unsigned char sol35e3_desc_803c03b0[], sol35e3_desc_803c03fc[];
extern const unsigned char sol35e3_desc_803c0448[], sol35e3_desc_803c0498[];
extern const unsigned char sol35e3_desc_803c04e4[], sol35e3_desc_803c0524[];
extern const float sol35e3_default_803c054c[];
int sol35e3_collision_descriptors_8024434c(void* owner) {
    sol35e3_register_u16_801ebbb8(owner, sol35e3_desc_803c0254);
    sol35e3_register_u16_801ebbb8(owner, sol35e3_desc_803c0298);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c02d8);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c0300);
    sol35e3_register_vector_801f0210(owner, sol35e3_desc_803c0328)->value = Sol35e3DefaultVector(sol35e3_default_803c054c[0]);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c036c);
    sol35e3_register_bool_801eb674(owner, sol35e3_desc_803c03b0);
    sol35e3_register_int_801eb834(owner, sol35e3_desc_803c03fc);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c0448);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c0498);
    sol35e3_register_int_801eb834(owner, sol35e3_desc_803c04e4);
    sol35e3_register_kind_801ece2c(owner, sol35e3_desc_803c0524);
    sol35e3_finish_descriptors_801e8d9c(owner);
    return 0;
}
}

typedef char Sol35e3VectorSize[sizeof(Sol35e3DefaultVector) == 12 ? 1 : -1];
typedef char Sol35e3ValueOffset[(unsigned)&((Sol35e3VectorBinding*)0)->value == 8 ? 1 : -1];
