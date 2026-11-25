// Eleven-string widget constructor at 0x80221174. Version 2 (unique family types). Class and member names are
// structural; offsets are observed from the original instructions.
#include "mx21ob_fe_widget_v2.h"

// Extends the 116-byte widget base with 11 shared strings; the table
// 0x8041a500 stays an external object (slots declared, not defined).
struct Mx21obFeStringSet : Mx21obFeWidget {
    Mx21obFeString text116;        // +116, starts as the shared empty string
    Mx21obFeString text120;        // +120, starts as the shared empty string
    Mx21obFeString text124;        // +124, starts as the shared empty string
    Mx21obFeString text128;        // +128, starts as the shared empty string
    Mx21obFeString text132;        // +132, starts as the shared empty string
    Mx21obFeString text136;        // +136, starts as the shared empty string
    Mx21obFeString text140;        // +140, starts as the shared empty string
    Mx21obFeString text144;        // +144, starts as the shared empty string
    Mx21obFeString text148;        // +148, starts as the shared empty string
    Mx21obFeString text152;        // +152, starts as the shared empty string
    Mx21obFeString text156;        // +156, starts as the shared empty string
    Mx21obFeStringSet(unsigned short id);
    void slot0();
};

Mx21obFeStringSet::Mx21obFeStringSet(unsigned short id)
    : Mx21obFeWidget(id),
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
