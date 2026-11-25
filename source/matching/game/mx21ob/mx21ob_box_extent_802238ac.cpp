// Box widget constructor at 0x802238ac. Class and member names are
// structural; the "box" reading comes from the neighbouring
// "LandscapeBoxDesc" text, so it is inferred.
#include "mx21ob_widget.h"

// Three floats set by an inline constructor; the original addresses y and z
// through the member's own address. The vector reading is inferred.
struct Mx21obVec3Init {
    float x, y, z;
    Mx21obVec3Init(float a, float b, float c) : x(a), y(b), z(c) {}
};

// The literals 20.0f and 0.0f are pooled in first-use order, which is the
// original's 0x803b7584..0x803b758b (unit-owned).
struct Mx21obBoxExtent : Mx21obWidget {
    Mx21obVec3Init size116;        // +116, starts as (20, 20, 0)
    Mx21obVec3Init offset128;      // +128, starts as zero
    int value140;                  // +140, starts as 1
    Mx15obString text144;          // +144, starts as the shared empty string
    Mx15obString text148;          // +148, starts as the shared empty string
    Mx15obString text152;          // +152, starts as the shared empty string
    Mx15obString text156;          // +156, starts as the shared empty string
    Mx21obBoxExtent(unsigned short id);
    void slot0();
};

Mx21obBoxExtent::Mx21obBoxExtent(unsigned short id)
    : Mx21obWidget(id),
      size116(20.0f, 20.0f, 0.0f),
      offset128(0.0f, 0.0f, 0.0f),
      value140(1),
      text144(w3d_empty_string_804b06a0[0]),
      text148(w3d_empty_string_804b06a0[0]),
      text152(w3d_empty_string_804b06a0[0]),
      text156(w3d_empty_string_804b06a0[0])
{
}
