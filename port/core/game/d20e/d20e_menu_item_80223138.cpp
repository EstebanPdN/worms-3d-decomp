#include "w3d_ptr.h"
#line 1 "d20e_menu_item_80223138.cpp"
// Front-end menu item constructor (Worms 3D GameCube PAL, 0x80223138).
//
// Runs the widget base constructor 0x8021ef08 with the caller's 16-bit id,
// installs the item table 0x8041a410, builds two strings from the text
// "A.MenuDown" through the out-of-line string constructor 0x8020bb54, sets
// the floats at +116..+140 (0, 0, 25, 16, 100) and the ints at +144/+148
// (3, 1), copy-constructs five string members at +152..+168 from the shared
// empty string 0x804b06a0 (retaining it) and sets the ints at +172..+180
// (0, 1, 0), in member order.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The widget base (admitted separately as d19e) is
// declared here as an opaque out-of-line constructor; the table slot is
// declared, not defined, so the table stays an external object. Built with
// -mps-float (one saved FPR in a non-leaf function). The previous drafts
// (build/f8c/trials/ctorcombined404_*.cpp) wrote the body as stores through
// a plain pointer; written as a real member-initialized constructor the
// string member addresses take the original saved registers, and the text
// and float literals form the original 28-byte literal pool.
struct D20eWidgetRoot {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN14D20eWidgetRoot5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D20eWidgetRoot, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D20eWidgetRoot; };

struct D20eWidget : D20eWidgetRoot {
    unsigned char body[112] __attribute__((aligned(__alignof__(D20eWidgetRoot))));       // +4..+115, initialized by 0x8021ef08
    D20eWidget(unsigned short id);
};

extern "C" void w3d_string_base_init(Ptr32<void> string);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);

// Four-byte shared engine string. The text constructor is out of line
// (0x8020bb54); copying retains the shared text through the 16-bit reference
// count returned by the header accessor.
struct D20eString {
    Ptr32<char> text;
    template <class W3dU> D20eString(Ptr32<W3dU> w3d_p) : D20eString((const char *)w3d_p.get()) {}
 D20eString(const char *text);
    D20eString(const D20eString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern D20eString w3d_empty_string_804b06a0[];   // shared empty string

struct D20eMenuItem : D20eWidget {
    float value116 __attribute__((aligned(__alignof__(D20eWidget))));
    D20eString text120, text124;
    float value128, value132, value136, value140;
    int value144, value148;
    D20eString text152, text156, text160, text164, text168;
    int value172, value176, value180;
    D20eMenuItem(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN12D20eMenuItem5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->D20eWidget::slot0(); } };
D20eMenuItem::D20eMenuItem(unsigned short id)
    : D20eWidget(id),
      value116(0),
      text120("A.MenuDown"), text124("A.MenuDown"),
      value128(0), value132(25), value136(16), value140(100),
      value144(3), value148(1),
      text152(w3d_empty_string_804b06a0[0]), text156(w3d_empty_string_804b06a0[0]),
      text160(w3d_empty_string_804b06a0[0]), text164(w3d_empty_string_804b06a0[0]),
      text168(w3d_empty_string_804b06a0[0]),
      value172(0), value176(1), value180(0)
{ W3D_SET_VPTR(this->D20eWidget::w3d_vptr_D20eWidgetRoot, w3d_vt___vt_12D20eMenuItem, "__vt_12D20eMenuItem"); 
}


