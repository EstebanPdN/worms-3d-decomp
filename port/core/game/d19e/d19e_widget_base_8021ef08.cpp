#include "w3d_ptr.h"
#line 1 "d19e_widget_base_8021ef08.cpp"
// Front-end widget base constructor (Worms 3D GameCube PAL, 0x8021ef08).
//
// Common base of the front-end widget family (button 0x8021fd28, alternate
// button 0x80221e8c, font widget 0x8022240c, ...), 116 bytes. Runs the tagged
// property base constructor 0x801ea0ec with the caller's 16-bit id, installs
// the widget table, sets vec20 to (50, 50, 0) and vec32 to zero, copies the
// shared empty string 0x804b06a0 into fifteen string members (retaining it
// each time), sets value64 to 0.0f and both trailing ints to 0, then clears
// bit 0x04 of the link flag byte at +11.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The table slot is declared, not defined, so the
// table stays an external object. Built with -mps-float (the constructor
// keeps the fpmem frame slot of that translation unit).

struct D19eWidgetRoot {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN14D19eWidgetRoot5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D19eWidgetRoot, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D19eWidgetRoot; };

// Registry link at +4: 16-bit reference count, 16-bit id, then a flag word
// whose lowest byte (+11) is set by 0x801ea0ec.
struct D19eWidgetLink {
    unsigned short references;     // +4
    unsigned short id;             // +6
    unsigned char flags;           // PPC +11, anfitrión +8
    unsigned char unknown8[3];
    void clearFlag() { flags &= ~4; }
};

struct D19eWidgetTagged : D19eWidgetRoot, D19eWidgetLink {
    int list12 __attribute__((aligned(__alignof__(D19eWidgetRoot)), aligned(__alignof__(D19eWidgetLink))));                    // +12
    int list16;                    // +16
    D19eWidgetTagged(unsigned short id);   // 0x801ea0ec
};

extern "C" void w3d_string_base_init(Ptr32<void> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);

// Four-byte shared engine string; copying retains the shared text through
// the 16-bit reference count returned by the header accessor.
struct D19eWidgetString {
    Ptr32<char> text;
    D19eWidgetString(const D19eWidgetString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern D19eWidgetString w3d_empty_string_804b06a0[];   // shared empty string

struct D19eWidgetVec3 {
    float x, y, z;
    D19eWidgetVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct D19eWidget : D19eWidgetTagged {
    D19eWidgetVec3 vec20 __attribute__((aligned(__alignof__(D19eWidgetTagged))));          // +20
    D19eWidgetVec3 vec32;          // +32
    D19eWidgetString text44;       // +44
    D19eWidgetString text48;       // +48
    D19eWidgetString text52;       // +52
    D19eWidgetString text56;       // +56
    D19eWidgetString text60;       // +60
    float value64;                 // +64
    D19eWidgetString text68;       // +68
    D19eWidgetString text72;       // +72
    D19eWidgetString text76;       // +76
    D19eWidgetString text80;       // +80
    D19eWidgetString text84;       // +84
    D19eWidgetString text88;       // +88
    D19eWidgetString text92;       // +92
    D19eWidgetString text96;       // +96
    D19eWidgetString text100;      // +100
    D19eWidgetString text104;      // +104
    int value108;                  // +108
    int value112;                  // +112
    D19eWidget(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN10D19eWidget5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->D19eWidgetTagged::slot0(); } };

D19eWidget::D19eWidget(unsigned short id)
    : D19eWidgetTagged(id),
      vec20(50.0f, 50.0f, 0.0f),
      vec32(0.0f, 0.0f, 0.0f),
      text44(w3d_empty_string_804b06a0[0]),
      text48(w3d_empty_string_804b06a0[0]),
      text52(w3d_empty_string_804b06a0[0]),
      text56(w3d_empty_string_804b06a0[0]),
      text60(w3d_empty_string_804b06a0[0]),
      value64(0.0f),
      text68(w3d_empty_string_804b06a0[0]),
      text72(w3d_empty_string_804b06a0[0]),
      text76(w3d_empty_string_804b06a0[0]),
      text80(w3d_empty_string_804b06a0[0]),
      text84(w3d_empty_string_804b06a0[0]),
      text88(w3d_empty_string_804b06a0[0]),
      text92(w3d_empty_string_804b06a0[0]),
      text96(w3d_empty_string_804b06a0[0]),
      text100(w3d_empty_string_804b06a0[0]),
      text104(w3d_empty_string_804b06a0[0]),
      value108(0),
      value112(0)
{ W3D_SET_VPTR(this->D19eWidgetTagged::w3d_vptr_D19eWidgetRoot, w3d_vt___vt_10D19eWidget, "__vt_10D19eWidget"); 
    clearFlag();
}


