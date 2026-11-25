// Border-named widget constructor at 0x80223e20. Class and member names are
// structural; the "border" reading of the "FE.Brd.%s" name pattern is
// inferred.
#include "mx21ob_widget.h"

// The name pattern text is pooled as the original's 0x803b76e4 (unit-owned).
struct Mx21obBorderWidget : Mx21obWidget {
    Mx15obString text116;          // +116, starts as the shared empty string
    Mx15obString text120;          // +120, starts as the shared empty string
    int value124;                  // +124, starts as 2
    Mx15obString name128;          // +128, starts as "FE.Brd.%s"
    Mx15obString text132;          // +132, starts as the shared empty string
    Mx15obString text136;          // +136, starts as the shared empty string
    Mx15obString text140;          // +140, starts as the shared empty string
    Mx15obString text144;          // +144, starts as the shared empty string
    Mx15obString text148;          // +148, starts as the shared empty string
    Mx15obString text152;          // +152, starts as the shared empty string
    Mx21obBorderWidget(unsigned short id);
    void slot0();
};

Mx21obBorderWidget::Mx21obBorderWidget(unsigned short id)
    : Mx21obWidget(id),
      text116(w3d_empty_string_804b06a0[0]),
      text120(w3d_empty_string_804b06a0[0]),
      value124(2),
      name128("FE.Brd.%s"),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      text140(w3d_empty_string_804b06a0[0]),
      text144(w3d_empty_string_804b06a0[0]),
      text148(w3d_empty_string_804b06a0[0]),
      text152(w3d_empty_string_804b06a0[0])
{
}
