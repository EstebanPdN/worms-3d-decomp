#include "w3d_ptr.h"
#line 1 "mx21ob_v2_slider_80220200.cpp"
// Slider widget constructor at 0x80220200. Version 2 (unique family types). Class and member names are
// structural; the "slider" reading comes from the "A.U.Slider" text and the
// "FE.Font" name, so it is inferred.
#include "mx21ob_fe_widget_v2.h"

// The texts and the 8.0f literal are pooled in this order, which is the
// original's 0x803b6408..0x803b641f (unit-owned).
struct Mx21obFeSlider : Mx21obFeButton {
    float value152 __attribute__((aligned(__alignof__(Mx21obFeButton))));                // +152, starts as 8.0f
    Mx21obFeString font156;        // +156, starts as "FE.Font"
    Mx21obFeString style160;       // +160, starts as "A.U.Slider"
    Mx21obFeString text164;        // +164, starts as the shared empty string
    Mx21obFeString text168;        // +168, starts as the shared empty string
    int value172;                  // +172, starts as 0
    Mx21obFeSlider(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN14Mx21obFeSlider5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx21obFeButton::slot0(); } };

Mx21obFeSlider::Mx21obFeSlider(unsigned short id)
    : Mx21obFeButton(id),
      value152(8.0f),
      font156("FE.Font"),
      style160("A.U.Slider"),
      text164(w3d_empty_string_804b06a0[0]),
      text168(w3d_empty_string_804b06a0[0]),
      value172(0)
{ W3D_SET_VPTR(this->Mx21obFeButton::w3d_vptr_Mx21obFeRoot, w3d_vt___vt_14Mx21obFeSlider, "__vt_14Mx21obFeSlider"); 
}


