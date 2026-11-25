// Four-string widget constructor at 0x80220668. Version 2 (unique family types). Class and member names are
// structural; offsets are observed from the original instructions.
#include "mx21ob_fe_widget_v2.h"

// Extends the 116-byte widget base with 4 shared strings; the table
// 0x8041a578 stays an external object (slots declared, not defined).
struct Mx21obFeStringQuad : Mx21obFeWidget {
    Mx21obFeString text116;        // +116, starts as the shared empty string
    Mx21obFeString text120;        // +120, starts as the shared empty string
    Mx21obFeString text124;        // +124, starts as the shared empty string
    Mx21obFeString text128;        // +128, starts as the shared empty string
    Mx21obFeStringQuad(unsigned short id);
    void slot0();
};

Mx21obFeStringQuad::Mx21obFeStringQuad(unsigned short id)
    : Mx21obFeWidget(id),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      text124(w3d_empty_string_804b06a0[0]),
      text128(w3d_empty_string_804b06a0[0])
{
}
