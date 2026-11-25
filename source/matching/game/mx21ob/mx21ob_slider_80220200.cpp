// Slider widget constructor at 0x80220200. Class and member names are
// structural; the "slider" reading comes from the "A.U.Slider" text and the
// "FE.Font" name, so it is inferred.
#include "mx21ob_widget.h"

// Button widget, 152 bytes; its constructor is 0x8021fd28 (unit
// mx21ob_button_8021fd28), bound here by original address.
struct Mx21obButton : Mx21obWidget {
    float value116;                // +116
    int value120;                  // +120
    Mx15obString name124;          // +124
    Mx15obString text128;          // +128
    Mx15obString text132;          // +132
    Mx15obString text136;          // +136
    int value140;                  // +140
    int value144;                  // +144
    int value148;                  // +148
    Mx21obButton(unsigned short id);
    void slot0();
};

// The texts and the 8.0f literal are pooled in this order, which is the
// original's 0x803b6408..0x803b641f (unit-owned).
struct Mx21obSlider : Mx21obButton {
    float value152;                // +152, starts as 8.0f
    Mx15obString font156;          // +156, starts as "FE.Font"
    Mx15obString style160;         // +160, starts as "A.U.Slider"
    Mx15obString text164;          // +164, starts as the shared empty string
    Mx15obString text168;          // +168, starts as the shared empty string
    int value172;                  // +172, starts as 0
    Mx21obSlider(unsigned short id);
    void slot0();
};

Mx21obSlider::Mx21obSlider(unsigned short id)
    : Mx21obButton(id),
      value152(8.0f),
      font156("FE.Font"),
      style160("A.U.Slider"),
      text164(w3d_empty_string_804b06a0[0]),
      text168(w3d_empty_string_804b06a0[0]),
      value172(0)
{
}
