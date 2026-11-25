// Button widget constructor at 0x8021fd28. Class and member names are
// structural; the "button" reading comes from the "FE.Button.%s" name pattern
// and the neighbouring "MenuButtonDesc" text, so it is inferred.
#include "mx21ob_widget.h"

// The float starts as the literal 0.0f; the compiler pools it after the name
// pattern text, which is the original's 0x803b61f8..0x803b620b (unit-owned).
struct Mx21obButton : Mx21obWidget {
    float value116;                // +116, starts as 0.0f
    int value120;                  // +120, starts as 1
    Mx15obString name124;          // +124, starts as "FE.Button.%s"
    Mx15obString text128;          // +128, starts as the shared empty string
    Mx15obString text132;          // +132, starts as the shared empty string
    Mx15obString text136;          // +136, starts as the shared empty string
    int value140;                  // +140, starts as 0
    int value144;                  // +144, starts as 1
    int value148;                  // +148, starts as 0
    Mx21obButton(unsigned short id);
    void slot0();
};

Mx21obButton::Mx21obButton(unsigned short id)
    : Mx21obWidget(id),
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
