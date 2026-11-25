// Second button-style widget constructor at 0x80221e8c. Version 2 (unique family types). Class and member
// names are structural; the "button" reading comes from the "FE.Button.%s"
// name pattern, so it is inferred.
#include "mx21ob_fe_widget_v2.h"

// The shared name text is an external object declared in the header.

struct Mx21obFeButtonAlt : Mx21obFeWidget {
    int value116;                  // +116, starts as 1
    Mx21obFeString text120;        // +120, starts as the shared empty string
    Mx21obFeString text124;        // +124, starts as the shared empty string
    Mx21obFeString name128;        // +128, starts as "FE.Button.%s"
    Mx21obFeString text132;        // +132, starts as the shared empty string
    Mx21obFeString text136;        // +136, starts as the shared empty string
    int value140;                  // +140, starts as 1
    int value144;                  // +144, starts as 1
    int value148;                  // +148, starts as 0
    Mx21obFeButtonAlt(unsigned short id);
    void slot0();
};

Mx21obFeButtonAlt::Mx21obFeButtonAlt(unsigned short id)
    : Mx21obFeWidget(id),
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
