// Graphic-equaliser widget constructor at 0x80224670. Class and member names
// are structural; the equaliser reading comes from the neighbouring
// "WeaponGraphicEqualiserDesc" text, so it is inferred.
#include "mx21ob_widget.h"

// The original shares one copy of the "FE.Button.%s" text with 0x8021fd28.
// That copy is owned by unit mx21ob_button_8021fd28, so it is referenced here
// as an external object instead of a second literal.
extern const char w3d_text_fe_button_pattern_803b61f8[];

// The literals 65.0f and 30.0f are pooled in first-use order, which is the
// original's 0x803b78bc..0x803b78c3 (unit-owned).
struct Mx21obEqualiser : Mx21obWidget {
    Mx15obString text116;          // +116, starts as the shared empty string
    Mx15obString text120;          // +120, starts as the shared empty string
    float value124;                // +124, starts as 65.0f
    float value128;                // +128, starts as 30.0f
    int value132;                  // +132, starts as 1
    Mx15obString name136;          // +136, starts as "FE.Button.%s"
    Mx15obString text140;          // +140, starts as the shared empty string
    Mx15obString text144;          // +144, starts as the shared empty string
    Mx15obString text148;          // +148, starts as the shared empty string
    int value152;                  // +152, starts as 1
    int value156;                  // +156, starts as 0
    Mx21obEqualiser(unsigned short id);
    void slot0();
};

Mx21obEqualiser::Mx21obEqualiser(unsigned short id)
    : Mx21obWidget(id),
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
{
}
