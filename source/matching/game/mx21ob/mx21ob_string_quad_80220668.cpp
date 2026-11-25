// Four-string widget constructor at 0x80220668. Class and member names are
// structural; offsets are observed from the original instructions.
#include "mx21ob_widget.h"

// Extends the 116-byte widget base with 4 shared strings; the table
// 0x8041a578 stays an external object (slots declared, not defined).
struct Mx21obStringQuad : Mx21obWidget {
    Mx15obString text116;       // +116, starts as the shared empty string
    Mx15obString text120;       // +120, starts as the shared empty string
    Mx15obString text124;       // +124, starts as the shared empty string
    Mx15obString text128;       // +128, starts as the shared empty string
    Mx21obStringQuad(unsigned short id);
    void slot0();
};

Mx21obStringQuad::Mx21obStringQuad(unsigned short id)
    : Mx21obWidget(id),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      text124(w3d_empty_string_804b06a0[0]),
      text128(w3d_empty_string_804b06a0[0])
{
}
