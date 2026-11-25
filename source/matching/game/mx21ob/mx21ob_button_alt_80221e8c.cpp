// Second button-style widget constructor at 0x80221e8c. Class and member
// names are structural; the "button" reading comes from the "FE.Button.%s"
// name pattern, so it is inferred.
#include "mx21ob_widget.h"

// The original shares one copy of the "FE.Button.%s" text with 0x8021fd28.
// That copy is owned by unit mx21ob_button_8021fd28, so it is referenced here
// as an external object instead of a second literal.
extern const char w3d_text_fe_button_pattern_803b61f8[];

struct Mx21obButtonAlt : Mx21obWidget {
    int value116;                  // +116, starts as 1
    Mx15obString text120;          // +120, starts as the shared empty string
    Mx15obString text124;          // +124, starts as the shared empty string
    Mx15obString name128;          // +128, starts as "FE.Button.%s"
    Mx15obString text132;          // +132, starts as the shared empty string
    Mx15obString text136;          // +136, starts as the shared empty string
    int value140;                  // +140, starts as 1
    int value144;                  // +144, starts as 1
    int value148;                  // +148, starts as 0
    Mx21obButtonAlt(unsigned short id);
    void slot0();
};

Mx21obButtonAlt::Mx21obButtonAlt(unsigned short id)
    : Mx21obWidget(id),
      value116(1),
      text120(w3d_empty_string_804b06a0[0]),
      text124(w3d_empty_string_804b06a0[0]),
      name128(w3d_text_fe_button_pattern_803b61f8),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      value140(1),
      value144(1),
      value148(0)
{
}
