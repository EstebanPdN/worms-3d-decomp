// Abstract root whose six slots are all pure in the original table at
// 0x80411ea0 (two header words, six entries bound to the pure-virtual trap
// 0x802f4440). `#pragma interface` keeps this table out of the unit: the
// original copy stays an external object, ownership pending. Slot meanings
// are unknown; names are structural.
#pragma interface
struct Mx17oaScreenRoot {
    void w3d_r_slot0()  __asm__(W3D_SYM("_ZN16Mx17oaScreenRoot5slot0Ev"));
    void w3d_r_slot1()  __asm__(W3D_SYM("_ZN16Mx17oaScreenRoot5slot1Ev"));
    void w3d_r_slot2()  __asm__(W3D_SYM("_ZN16Mx17oaScreenRoot5slot2Ev"));
    void w3d_r_slot3()  __asm__(W3D_SYM("_ZN16Mx17oaScreenRoot5slot3Ev"));
    void w3d_r_slot4()  __asm__(W3D_SYM("_ZN16Mx17oaScreenRoot5slot4Ev"));
    void w3d_r_slot5()  __asm__(W3D_SYM("_ZN16Mx17oaScreenRoot5slot5Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx17oaScreenRoot, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx17oaScreenRoot, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx17oaScreenRoot, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx17oaScreenRoot, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx17oaScreenRoot, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx17oaScreenRoot, 7))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Mx17oaScreenRoot;  Mx17oaScreenRoot() { W3D_SET_VPTR(this->w3d_vptr_Mx17oaScreenRoot, w3d_vt___vt_16Mx17oaScreenRoot, "__vt_16Mx17oaScreenRoot"); } };
