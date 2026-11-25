// Slider widget constructor at 0x80220200. Version 2 (unique family types). Class and member names are
// structural; the "slider" reading comes from the "A.U.Slider" text and the
// "FE.Font" name, so it is inferred.
#include "mx21ob_fe_widget_v2.h"

// The texts and the 8.0f literal are pooled in this order, which is the
// original's 0x803b6408..0x803b641f (unit-owned).
struct Mx21obFeSlider : Mx21obFeButton {
    float value152;                // +152, starts as 8.0f
    Mx21obFeString font156;        // +156, starts as "FE.Font"
    Mx21obFeString style160;       // +160, starts as "A.U.Slider"
    Mx21obFeString text164;        // +164, starts as the shared empty string
    Mx21obFeString text168;        // +168, starts as the shared empty string
    int value172;                  // +172, starts as 0
    Mx21obFeSlider(unsigned short id);
    void slot0();
};

Mx21obFeSlider::Mx21obFeSlider(unsigned short id)
    : Mx21obFeButton(id),
      value152(8.0f),
      font156("FE.Font"),
      style160("A.U.Slider"),
      text164(w3d_empty_string_804b06a0[0]),
      text168(w3d_empty_string_804b06a0[0]),
      value172(0)
{
}
