// Observed lazy descriptor constructor and legacy crclr call ABI, GC32.
// The variadic declaration models the original unprototyped memset call;
// exactly three integer/pointer arguments are supplied and consumed.
extern "C" void* memset(...);
struct Sol35e3PropertyInfo {
    Sol35e3PropertyInfo() { memset(this, 0, sizeof(*this)); }
    const char* name;
    unsigned short size;
    unsigned char element_type;
    unsigned char type;
    const void* descriptor;
    const void* extra;
    unsigned unknown16;
};
extern "C" {
void* sol35e3_register_bool_801eb674(void*, const void*);
void* sol35e3_register_scalar_801ec52c(void*, const void*);
void* sol35e3_register_array_801eff8c(void*, const Sol35e3PropertyInfo*);
void sol35e3_finish_descriptors_801e8d9c(void*);
extern const unsigned char sol35e3_desc_803c23d4[], sol35e3_desc_803c2408[], sol35e3_desc_803c243c[];
extern const char sol35e3_name_803c2464[];
extern const unsigned char sol35e3_type_8045e004[], sol35e3_extra_803f4540[];
extern unsigned sol35e3_guard_804b087c;
extern Sol35e3PropertyInfo sol35e3_cache_80464d88;
int sol35e3_lens_descriptors_80245ac8(void* owner) {
    sol35e3_register_bool_801eb674(owner, sol35e3_desc_803c23d4);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c2408);
    sol35e3_register_scalar_801ec52c(owner, sol35e3_desc_803c243c);
    if (!sol35e3_guard_804b087c) {
        Sol35e3PropertyInfo* target = &sol35e3_cache_80464d88;
        Sol35e3PropertyInfo info;
        info.name = sol35e3_name_803c2464;
        info.size = 20;
        info.element_type = 3;
        info.type = 9;
        info.descriptor = sol35e3_type_8045e004;
        info.extra = sol35e3_extra_803f4540;
        *target = info;
        sol35e3_guard_804b087c = 1;
    }
    sol35e3_register_array_801eff8c(owner, &sol35e3_cache_80464d88);
    sol35e3_finish_descriptors_801e8d9c(owner);
    return 0;
}
}
