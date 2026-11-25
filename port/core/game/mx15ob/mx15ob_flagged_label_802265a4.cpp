#include "w3d_ptr.h"
#line 1 "mx15ob_flagged_label_802265a4.cpp"
// Flagged label constructor at 0x802265a4. Class and member names are inferred;
// offsets are observed from the original instructions.
//
// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; the slot is declared, not defined, so the
// label table 0x8041a258 stays an external object (ownership pending).
struct Mx15obRoot {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN10Mx15obRoot5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx15obRoot, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Mx15obRoot; };

struct Mx15obTagged : Mx15obRoot {
    unsigned char unknown[16] __attribute__((aligned(__alignof__(Mx15obRoot))));     // +4..+19, initialized by 0x801ea0ec
    Mx15obTagged(unsigned short id);
};

extern "C" void w3d_string_base_init(Ptr32<void> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);

// Four-byte shared engine string. Copying retains the shared text through the
// 16-bit reference count returned by the header accessor.
struct Mx15obString {
    Ptr32<char> text;
    Mx15obString(const Mx15obString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern Mx15obString w3d_empty_string_804b06a0[];   // shared empty string

struct Mx15obFlaggedLabel : Mx15obTagged {
    int kind __attribute__((aligned(__alignof__(Mx15obTagged))));                      // +20, always 1 here
    Mx15obString name;             // +24, starts as the shared empty string
    int enabled;                   // +28, starts set
    Mx15obFlaggedLabel(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN18Mx15obFlaggedLabel5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx15obTagged::slot0(); } };

Mx15obFlaggedLabel::Mx15obFlaggedLabel(unsigned short id)
    : Mx15obTagged(id), kind(1), name(w3d_empty_string_804b06a0[0]), enabled(1)
{ W3D_SET_VPTR(this->Mx15obTagged::w3d_vptr_Mx15obRoot, w3d_vt___vt_18Mx15obFlaggedLabel, "__vt_18Mx15obFlaggedLabel"); 
}


