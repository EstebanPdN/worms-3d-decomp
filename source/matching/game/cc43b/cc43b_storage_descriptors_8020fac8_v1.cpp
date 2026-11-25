extern "C" void *__builtin_memset(void *, int, unsigned int);
// Partial descriptor is exactly the three observed words; external arrays are
// unowned original storage. Full original types and lifetime remain unknown.
struct cc43b_Descriptor {
    void *kind;
    unsigned int bytes, active;
    inline void initialize(void *type, unsigned int size, unsigned int enabled) {
        __builtin_memset(this,0,12);
        kind=type; bytes=size; active=enabled;
    }
};
extern cc43b_Descriptor cc43b_descriptors_80463bbc[];
extern unsigned int cc43b_descriptors_ready_804b06b4;
extern unsigned char cc43b_kind_a_8040c980[], cc43b_kind_b_8040c990[];
extern "C" cc43b_Descriptor *cc43b_storage_descriptors_8020fac8() {
    if (!cc43b_descriptors_ready_804b06b4) {
        cc43b_descriptors_80463bbc[0].initialize(cc43b_kind_a_8040c980,12,1);
        cc43b_descriptors_80463bbc[1].initialize(cc43b_kind_b_8040c990,12,1);
        __builtin_memset(&cc43b_descriptors_80463bbc[2],0,12);
        cc43b_descriptors_ready_804b06b4=1;
    }
    return cc43b_descriptors_80463bbc;
}
