#include "w3d_ptr.h"
#line 1 "mx14oa_file_owner_b_8015be3c.cpp"
// Engine file owner (singleton at 0x804b17ec). Names and member meanings are
// inferred; offsets are observed. The matching destructor and the slot reads
// are in s3_runtime_integration.c.
#include "mx14oa_file_owner_b_8015be3c_base.h"

extern "C" void w3d_string_default(Ptr32<void> string);
extern "C" void w3d_setting_80206920(Ptr32<const char> key, Ptr32<int> value);
extern "C" void w3d_register_owner_80165594(Ptr32<void> owner);
extern const char w3d_str_run_from_cd_803a4348[];   // "PS2.RunFromCdRom"

// Four-byte engine string; the default constructor is out of line.
struct Mx14oaTextB {
    Ptr32<char> data;
    Mx14oaTextB() { w3d_string_default(this); }
};

// Tagged link at +4: the second word packs a 24-bit pointer above an 8-bit
// kind tag. The static node getter 0x8020b208 shows the same pair of stores
// (kind byte, then the pointer field inserted with rlwimi). The first word is
// left untouched here.
struct Mx14oaTaggedLinkB {
    Ptr32<void> target;
    unsigned int kind:8; unsigned int pointer:24;
    Mx14oaTaggedLinkB(unsigned char tag) { kind = tag; pointer = 0; }
};

// Base node: adds no virtual functions, so it shares the service table.
struct Mx14oaNodeB : Mx14oaServiceB {
    Mx14oaTaggedLinkB link __attribute__((aligned(__alignof__(Mx14oaServiceB))));
    Mx14oaNodeB() : link(2) { W3D_SET_VPTR(this->Mx14oaServiceB::w3d_vptr_Mx14oaServiceB, w3d_vt___vt_11Mx14oaNodeB, "__vt_11Mx14oaNodeB"); }
};

// Retained interface (released through slot 4 by the destructor).
struct Mx14oaInterfaceB;

struct Mx14oaFileOwnerB : Mx14oaNodeB {
    Mx14oaTextB path __attribute__((aligned(__alignof__(Mx14oaNodeB))));              // +12
    Ptr32<Mx14oaInterfaceB> files;       // +16
    Ptr32<Mx14oaInterfaceB> archives;    // +20
    int from_cd;                   // +24
    Mx14oaFileOwnerB();
    // Ten slots of table 0x80411168 (0x8015bdf4 0x8015bdec 0x8015bde4
    // 0x8015c154 0x8015c2a4 0x8015c2f8 0x8015bdcc 0x8015c114 0x8015c144
    // 0x8015c14c); defined elsewhere, so the table stays external.
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot0Ev")); void w3d_r_slot1() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot1Ev")); void w3d_r_slot2() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot2Ev")); void w3d_r_slot3() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot3Ev")); void w3d_r_slot4() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot4Ev")); void w3d_r_slot5() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot5Ev"));
    void w3d_r_slot6() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot6Ev")); void w3d_r_slot7() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot7Ev")); void w3d_r_slot8() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot8Ev")); void w3d_r_slot9() __asm__(W3D_SYM("_ZN16Mx14oaFileOwnerB5slot9Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx14oaNodeB::slot0(); }  __attribute__((always_inline)) inline void slot1() { this->Mx14oaNodeB::slot1(); }  __attribute__((always_inline)) inline void slot2() { this->Mx14oaNodeB::slot2(); }  __attribute__((always_inline)) inline void slot3() { this->Mx14oaNodeB::slot3(); }  __attribute__((always_inline)) inline void slot4() { this->Mx14oaNodeB::slot4(); }  __attribute__((always_inline)) inline void slot5() { this->Mx14oaNodeB::slot5(); }  __attribute__((always_inline)) inline void slot6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx14oaServiceB, 11))(w3d::h2g(this)); } };

extern Ptr32<Mx14oaFileOwnerB> w3d_file_owner_804b17ec;

Mx14oaFileOwnerB::Mx14oaFileOwnerB()
{ W3D_SET_VPTR(this->Mx14oaNodeB::w3d_vptr_Mx14oaServiceB, w3d_vt___vt_16Mx14oaFileOwnerB, "__vt_16Mx14oaFileOwnerB"); 
    files = 0;
    archives = 0;
    int setting = 0;
    w3d_setting_80206920(w3d_str_run_from_cd_803a4348, &setting);
    int result = setting;
    if (result)
        result = 1;
    from_cd = result;
    w3d_file_owner_804b17ec = this;
    w3d_register_owner_80165594(this);
}


