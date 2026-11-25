// Button widget constructor at 0x8021fd28 (version 2, unique family types).
// Class and member names are structural; the "button" reading comes from the
// "FE.Button.%s" name pattern and the neighbouring "MenuButtonDesc" text, so
// it is inferred.
#include "mx21ob_fe_widget_v2.h"

// The name pattern literal (shared in the original with 0x80221e8c and
// 0x80224670) and the 0.0f literal are pooled in this order, which is the
// original's 0x803b61f8..0x803b620b (unit-owned).

Mx21obFeButton::Mx21obFeButton(unsigned short id)
    : Mx21obFeWidget(id),
      value116(0.0f),
      value120(1),
      name124("FE.Button.%s"),
      text128(w3d_empty_string_804b06a0[0]),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      value140(0),
      value144(1),
      value148(0)
{
}
