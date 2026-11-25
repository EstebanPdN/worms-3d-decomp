#include "w3d_ptr.h"
#line 1 "mx21ob_v2_font_panel_80224cd4.cpp"
// Font widget extension constructor at 0x80224cd4 (version 2, unique family
// types). Class and member names are structural; offsets are observed from
// the original instructions.
#include "mx21ob_fe_widget_v2.h"

// Extends the 156-byte font-bearing widget, whose constructor 0x8022240c is
// bound by original address (not recovered).
struct Mx21obFeFontPanel : Mx21obFeFontWidget {
    Mx21obFeString text156 __attribute__((aligned(__alignof__(Mx21obFeFontWidget))));        // +156, starts as the shared empty string
    int value160;                  // +160, starts as 0
    int value164;                  // +164, starts as 0
    Mx21obFeString text168;        // +168, starts as the shared empty string
    Mx21obFeString text172;        // +172, starts as the shared empty string
    Mx21obFeString text176;        // +176, starts as the shared empty string
    Mx21obFeString text180;        // +180, starts as the shared empty string
    int value184;                  // +184, starts as 0
    Mx21obFeFontPanel(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN17Mx21obFeFontPanel5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx21obFeFontWidget::slot0(); } };

Mx21obFeFontPanel::Mx21obFeFontPanel(unsigned short id)
    : Mx21obFeFontWidget(id),
      text156(w3d_empty_string_804b06a0[0]),
      value160(0),
      value164(0),
      text168(w3d_empty_string_804b06a0[0]),
      text172(w3d_empty_string_804b06a0[0]),
      text176(w3d_empty_string_804b06a0[0]),
      text180(w3d_empty_string_804b06a0[0]),
      value184(0)
{ W3D_SET_VPTR(this->Mx21obFeFontWidget::w3d_vptr_Mx21obFeRoot, w3d_vt___vt_17Mx21obFeFontPanel, "__vt_17Mx21obFeFontPanel"); 
}


