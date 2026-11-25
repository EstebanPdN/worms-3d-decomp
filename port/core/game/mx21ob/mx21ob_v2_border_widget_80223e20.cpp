#include "w3d_ptr.h"
#line 1 "mx21ob_v2_border_widget_80223e20.cpp"
// Border-named widget constructor at 0x80223e20. Version 2 (unique family types). Class and member names are
// structural; the "border" reading of the "FE.Brd.%s" name pattern is
// inferred.
#include "mx21ob_fe_widget_v2.h"

// The name pattern text is pooled as the original's 0x803b76e4 (unit-owned).
struct Mx21obFeBorderWidget : Mx21obFeWidget {
    Mx21obFeString text116 __attribute__((aligned(__alignof__(Mx21obFeWidget))));        // +116, starts as the shared empty string
    Mx21obFeString text120;        // +120, starts as the shared empty string
    int value124;                  // +124, starts as 2
    Mx21obFeString name128;        // +128, starts as "FE.Brd.%s"
    Mx21obFeString text132;        // +132, starts as the shared empty string
    Mx21obFeString text136;        // +136, starts as the shared empty string
    Mx21obFeString text140;        // +140, starts as the shared empty string
    Mx21obFeString text144;        // +144, starts as the shared empty string
    Mx21obFeString text148;        // +148, starts as the shared empty string
    Mx21obFeString text152;        // +152, starts as the shared empty string
    Mx21obFeBorderWidget(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN20Mx21obFeBorderWidget5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx21obFeWidget::slot0(); } };

Mx21obFeBorderWidget::Mx21obFeBorderWidget(unsigned short id)
    : Mx21obFeWidget(id),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      value124(2),
      name128("FE.Brd.%s"),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      text140(w3d_empty_string_804b06a0[0]),
      text144(w3d_empty_string_804b06a0[0]),
      text148(w3d_empty_string_804b06a0[0]),
      text152(w3d_empty_string_804b06a0[0])
{ W3D_SET_VPTR(this->Mx21obFeWidget::w3d_vptr_Mx21obFeRoot, w3d_vt___vt_20Mx21obFeBorderWidget, "__vt_20Mx21obFeBorderWidget"); 
}


