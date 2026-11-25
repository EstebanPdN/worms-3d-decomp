// Eleven-string widget constructor at 0x80221174. Class and member names are
// structural; offsets are observed from the original instructions.
#include "mx21ob_widget.h"

// Extends the 116-byte widget base with 11 shared strings; the table
// 0x8041a500 stays an external object (slots declared, not defined).
struct Mx21obStringSet : Mx21obWidget {
    Mx15obString text116;       // +116, starts as the shared empty string
    Mx15obString text120;       // +120, starts as the shared empty string
    Mx15obString text124;       // +124, starts as the shared empty string
    Mx15obString text128;       // +128, starts as the shared empty string
    Mx15obString text132;       // +132, starts as the shared empty string
    Mx15obString text136;       // +136, starts as the shared empty string
    Mx15obString text140;       // +140, starts as the shared empty string
    Mx15obString text144;       // +144, starts as the shared empty string
    Mx15obString text148;       // +148, starts as the shared empty string
    Mx15obString text152;       // +152, starts as the shared empty string
    Mx15obString text156;       // +156, starts as the shared empty string
    Mx21obStringSet(unsigned short id);
    void slot0();
};

Mx21obStringSet::Mx21obStringSet(unsigned short id)
    : Mx21obWidget(id),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      text124(w3d_empty_string_804b06a0[0]),
      text128(w3d_empty_string_804b06a0[0]),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      text140(w3d_empty_string_804b06a0[0]),
      text144(w3d_empty_string_804b06a0[0]),
      text148(w3d_empty_string_804b06a0[0]),
      text152(w3d_empty_string_804b06a0[0]),
      text156(w3d_empty_string_804b06a0[0])
{
}
