#include "w3d_ptr.h"
#line 1 "mx15ob_named_slots_802366b4.cpp"
// Named slot record constructor at 0x802366b4. Class and member names are structural;
// offsets are observed from the original instructions.
//
// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; the slot is declared, not defined, so the
// table 0x8041a810 stays an external object (ownership pending).
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

struct Mx15obNamedSlots : Mx15obTagged {
    int value20 __attribute__((aligned(__alignof__(Mx15obTagged))));                   // +20, starts as 0
    int value24;                   // +24, starts as 0
    Mx15obString text28;            // +28, starts as the shared empty string
    int value32;                   // +32, starts as 0
    int value36;                   // +36, starts as 0
    int value40;                   // +40, starts as 0
    Mx15obString text44;            // +44, starts as the shared empty string
    Mx15obString text48;            // +48, starts as the shared empty string
    Mx15obString text52;            // +52, starts as the shared empty string
    int value56;                   // +56, starts as 0
    int value60;                   // +60, starts as 0
    int value64;                   // +64, starts as 0
    int value68;                   // +68, starts as 0
    Mx15obNamedSlots(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN16Mx15obNamedSlots5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx15obTagged::slot0(); } };

Mx15obNamedSlots::Mx15obNamedSlots(unsigned short id)
    : Mx15obTagged(id),
      value20(0),
      value24(0),
      text28(w3d_empty_string_804b06a0[0]),
      value32(0),
      value36(0),
      value40(0),
      text44(w3d_empty_string_804b06a0[0]),
      text48(w3d_empty_string_804b06a0[0]),
      text52(w3d_empty_string_804b06a0[0]),
      value56(0),
      value60(0),
      value64(0),
      value68(0)
{ W3D_SET_VPTR(this->Mx15obTagged::w3d_vptr_Mx15obRoot, w3d_vt___vt_16Mx15obNamedSlots, "__vt_16Mx15obNamedSlots"); 
}


