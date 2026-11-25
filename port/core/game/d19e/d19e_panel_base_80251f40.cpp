#include "w3d_ptr.h"
#line 1 "d19e_panel_base_80251f40.cpp"
// Front-end panel constructor (Worms 3D GameCube PAL, 0x80251f40).
//
// Runs the tagged property base constructor 0x801ea0ec with the caller's
// 16-bit id, installs the panel table 0x8041bab8, zeroes the vectors at +20
// and +32, copy-constructs 22 string members from the shared empty string
// 0x804b06a0 (retaining it), and zeroes the ints/floats at +52..+68, the two
// flag bytes at +152/+153 and the ints at +156/+160, in member order.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The table slot is declared, not defined, so the
// table stays an external object. Built with -mps-float (frame keeps the
// fpmem slot of that translation unit). Derived from draft
// build/mx17ob/t/t51A.cpp.
//
// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown.
struct D19ePanelRoot {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN13D19ePanelRoot5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D19ePanelRoot, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D19ePanelRoot; };

struct D19ePanelTagged : D19ePanelRoot {
    unsigned char unknown[16] __attribute__((aligned(__alignof__(D19ePanelRoot))));     // +4..+19, initialized by 0x801ea0ec
    D19ePanelTagged(unsigned short id);
};

extern "C" void w3d_string_base_init(Ptr32<void> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);

// Four-byte shared engine string. Copying retains the shared text through the
// 16-bit reference count returned by the header accessor.
struct D19ePanelString {
    Ptr32<char> text;
    D19ePanelString(const D19ePanelString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern D19ePanelString w3d_empty_string_804b06a0[];   // shared empty string

struct D19ePanelVec3 {
    float x, y, z;
    D19ePanelVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct D19ePanel : D19ePanelTagged {
    D19ePanelVec3 vec20 __attribute__((aligned(__alignof__(D19ePanelTagged))));
    D19ePanelVec3 vec32;
    D19ePanelString text44;
    D19ePanelString text48;
    int value52;
    int value56;
    float value60;
    float value64;
    int value68;
    D19ePanelString text72;
    D19ePanelString text76;
    D19ePanelString text80;
    D19ePanelString text84;
    D19ePanelString text88;
    D19ePanelString text92;
    D19ePanelString text96;
    D19ePanelString text100;
    D19ePanelString text104;
    D19ePanelString text108;
    D19ePanelString text112;
    D19ePanelString text116;
    D19ePanelString text120;
    D19ePanelString text124;
    D19ePanelString text128;
    D19ePanelString text132;
    D19ePanelString text136;
    D19ePanelString text140;
    D19ePanelString text144;
    D19ePanelString text148;
    unsigned char flag152;
    unsigned char flag153;
    int value156;
    int value160;
    D19ePanel(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN9D19ePanel5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->D19ePanelTagged::slot0(); } };

D19ePanel::D19ePanel(unsigned short id)
    : D19ePanelTagged(id),
      vec20(0, 0, 0),
      vec32(0, 0, 0),
      text44(w3d_empty_string_804b06a0[0]),
      text48(w3d_empty_string_804b06a0[0]),
      value52(0),
      value56(0),
      value60(0),
      value64(0),
      value68(0),
      text72(w3d_empty_string_804b06a0[0]),
      text76(w3d_empty_string_804b06a0[0]),
      text80(w3d_empty_string_804b06a0[0]),
      text84(w3d_empty_string_804b06a0[0]),
      text88(w3d_empty_string_804b06a0[0]),
      text92(w3d_empty_string_804b06a0[0]),
      text96(w3d_empty_string_804b06a0[0]),
      text100(w3d_empty_string_804b06a0[0]),
      text104(w3d_empty_string_804b06a0[0]),
      text108(w3d_empty_string_804b06a0[0]),
      text112(w3d_empty_string_804b06a0[0]),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      text124(w3d_empty_string_804b06a0[0]),
      text128(w3d_empty_string_804b06a0[0]),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      text140(w3d_empty_string_804b06a0[0]),
      text144(w3d_empty_string_804b06a0[0]),
      text148(w3d_empty_string_804b06a0[0]),
      flag152(0),
      flag153(0),
      value156(0),
      value160(0)
{ W3D_SET_VPTR(this->D19ePanelTagged::w3d_vptr_D19ePanelRoot, w3d_vt___vt_9D19ePanel, "__vt_9D19ePanel"); 
}


