#include "w3d_ptr.h"
#line 1 "d20e_panel_subclass_8025693c.cpp"
// Front-end panel subclass constructor (Worms 3D GameCube PAL, 0x8025693c).
//
// Runs the panel base constructor 0x80251f40 with the caller's 16-bit id,
// installs the subclass table 0x8041b9c8, zeroes the vectors at +164 and
// +176 and the floats at +188..+212, copy-constructs four string members at
// +216..+228 from the shared empty string 0x804b06a0 (retaining it), then
// zeroes the floats at +232..+240 and the ints at +244..+256, in member order.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The panel base (admitted separately as d19e) is
// declared here as an opaque out-of-line constructor; the table slot is
// declared, not defined, so the table stays an external object. Built with
// -mps-float (one saved FPR in a non-leaf function). The previous drafts
// (build/f7c/trials/ctor348_*.cpp) wrote the body as stores through a plain
// pointer; written as a real member-initialized constructor the string
// member addresses take the original saved registers.
struct D20ePanelRoot {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN13D20ePanelRoot5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D20ePanelRoot, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D20ePanelRoot; };

struct D20ePanel : D20ePanelRoot {
    unsigned char body[160] __attribute__((aligned(__alignof__(D20ePanelRoot))));       // +4..+163, initialized by 0x80251f40
    D20ePanel(unsigned short id);
};

extern "C" void w3d_string_base_init(Ptr32<void> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);

// Four-byte shared engine string. Copying retains the shared text through the
// 16-bit reference count returned by the header accessor.
struct D20eString {
    Ptr32<char> text;
    D20eString(const D20eString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern D20eString w3d_empty_string_804b06a0[];   // shared empty string

struct D20eVec3 {
    float x, y, z;
    D20eVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct D20ePanelSubclass : D20ePanel {
    D20eVec3 vec164 __attribute__((aligned(__alignof__(D20ePanel))));
    D20eVec3 vec176;
    float value188, value192, value196, value200, value204, value208, value212;
    D20eString text216, text220, text224, text228;
    float value232, value236, value240;
    int value244, value248, value252, value256;
    D20ePanelSubclass(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN17D20ePanelSubclass5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->D20ePanel::slot0(); } };
D20ePanelSubclass::D20ePanelSubclass(unsigned short id)
    : D20ePanel(id),
      vec164(0, 0, 0),
      vec176(0, 0, 0),
      value188(0), value192(0), value196(0),
      value200(0), value204(0), value208(0),
      value212(0),
      text216(w3d_empty_string_804b06a0[0]), text220(w3d_empty_string_804b06a0[0]),
      text224(w3d_empty_string_804b06a0[0]), text228(w3d_empty_string_804b06a0[0]),
      value232(0), value236(0), value240(0),
      value244(0), value248(0), value252(0), value256(0)
{ W3D_SET_VPTR(this->D20ePanel::w3d_vptr_D20ePanelRoot, w3d_vt___vt_17D20ePanelSubclass, "__vt_17D20ePanelSubclass"); 
}


