// Abstract service interface whose six slots are all pure in the original
// table at 0x804111a0 (two header words, then six 4-byte entries bound to the
// pure-virtual trap 0x802f4440). `#pragma interface` keeps this table out of
// the unit: the original copy remains an external object, ownership pending.
// Slot meanings are unknown; names are structural.
#pragma interface
struct Mx14oaServiceB {
    void w3d_r_slot0()  __asm__(W3D_SYM("_ZN14Mx14oaServiceB5slot0Ev"));
    void w3d_r_slot1()  __asm__(W3D_SYM("_ZN14Mx14oaServiceB5slot1Ev"));
    void w3d_r_slot2()  __asm__(W3D_SYM("_ZN14Mx14oaServiceB5slot2Ev"));
    void w3d_r_slot3()  __asm__(W3D_SYM("_ZN14Mx14oaServiceB5slot3Ev"));
    void w3d_r_slot4()  __asm__(W3D_SYM("_ZN14Mx14oaServiceB5slot4Ev"));
    void w3d_r_slot5()  __asm__(W3D_SYM("_ZN14Mx14oaServiceB5slot5Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 7))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Mx14oaServiceB;  Mx14oaServiceB() { W3D_SET_VPTR(this->w3d_vptr_Mx14oaServiceB, w3d_vt___vt_14Mx14oaServiceB, "__vt_14Mx14oaServiceB"); } };
