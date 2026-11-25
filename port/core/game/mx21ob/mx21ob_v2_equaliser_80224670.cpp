#include "w3d_ptr.h"
#line 1 "mx21ob_v2_equaliser_80224670.cpp"
// Graphic-equaliser widget constructor at 0x80224670. Version 2 (unique family types). Class and member names
// are structural; the equaliser reading comes from the neighbouring
// "WeaponGraphicEqualiserDesc" text, so it is inferred.
#include "mx21ob_fe_widget_v2.h"

// The shared name text is an external object declared in the header.

// The literals 65.0f and 30.0f are pooled in first-use order, which is the
// original's 0x803b78bc..0x803b78c3 (unit-owned).
struct Mx21obFeEqualiser : Mx21obFeWidget {
    Mx21obFeString text116 __attribute__((aligned(__alignof__(Mx21obFeWidget))));        // +116, starts as the shared empty string
    Mx21obFeString text120;        // +120, starts as the shared empty string
    float value124;                // +124, starts as 65.0f
    float value128;                // +128, starts as 30.0f
    int value132;                  // +132, starts as 1
    Mx21obFeString name136;        // +136, starts as "FE.Button.%s"
    Mx21obFeString text140;        // +140, starts as the shared empty string
    Mx21obFeString text144;        // +144, starts as the shared empty string
    Mx21obFeString text148;        // +148, starts as the shared empty string
    int value152;                  // +152, starts as 1
    int value156;                  // +156, starts as 0
    Mx21obFeEqualiser(unsigned short id);
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN17Mx21obFeEqualiser5slot0Ev"));
 __attribute__((always_inline)) inline void slot0() { this->Mx21obFeWidget::slot0(); } };

Mx21obFeEqualiser::Mx21obFeEqualiser(unsigned short id)
    : Mx21obFeWidget(id),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      value124(65.0f),
      value128(30.0f),
      value132(1),
      name136(w3d_text_fe_button_pattern_803b61f8),
      text140(w3d_empty_string_804b06a0[0]),
      text144(w3d_empty_string_804b06a0[0]),
      text148(w3d_empty_string_804b06a0[0]),
      value152(1),
      value156(0)
{ W3D_SET_VPTR(this->Mx21obFeWidget::w3d_vptr_Mx21obFeRoot, w3d_vt___vt_17Mx21obFeEqualiser, "__vt_17Mx21obFeEqualiser"); 
}


