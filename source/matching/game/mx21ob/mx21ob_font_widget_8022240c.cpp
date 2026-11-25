// Font-bearing widget constructor at 0x8022240c. Class and member names are
// structural; the font reading comes from the "FE.Font" name only.
#include "mx21ob_widget.h"

// The original shares one copy of the "FE.Font" text with 0x80220200. That
// copy is owned by unit mx21ob_slider_80220200, so it is referenced here as
// an external object instead of a second literal.
extern const char w3d_text_fe_font_803b6408[];

// Four unsigned bytes set by an inline constructor. The original stores byte
// 0, then 3, 1, 2 (scheduler order); the RGBA reading is inferred from the
// size, grouping and the all-0xff start value.
struct Mx21obColour {
    unsigned char r, g, b, a;
    Mx21obColour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
        : r(red), g(green), b(blue), a(alpha) {}
};

// The float starts as the literal 0.0f; the compiler pools it, and the pool
// word is the original's 0x803b6c9c (unit-owned data, value 0).
struct Mx21obFontWidget : Mx21obWidget {
    Mx21obColour colour116;        // +116, starts as 0xff in every byte
    float value120;                // +120, starts as 0.0f
    int value124;                  // +124, starts as 4
    int value128;                  // +128, starts as 1
    Mx15obString text132;          // +132, starts as the shared empty string
    Mx15obString text136;          // +136, starts as the shared empty string
    Mx15obString font140;          // +140, starts as "FE.Font"
    int value144;                  // +144, starts as 0
    int value148;                  // +148, starts as 0
    int value152;                  // +152, starts as 0
    Mx21obFontWidget(unsigned short id);
    void slot0();
};

Mx21obFontWidget::Mx21obFontWidget(unsigned short id)
    : Mx21obWidget(id),
      colour116(255, 255, 255, 255),
      value120(0.0f),
      value124(4),
      value128(1),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      font140(w3d_text_fe_font_803b6408),
      value144(0),
      value148(0),
      value152(0)
{
}
