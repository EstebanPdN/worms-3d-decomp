// Shared declarations for the front-end widget family whose base constructor
// is 0x8021ef08 (version 2). Every type here has a name unique to this
// family, so units that include this header can be linked with the rest of
// the recovered source without conflicting class definitions. Class and
// member names are structural; offsets are observed from the original
// instructions. Version 1 (mx21ob_widget.h) is superseded and not admitted.
#ifndef MX21OB_FE_WIDGET_V2_H
#define MX21OB_FE_WIDGET_V2_H

// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; slots are declared, not defined, so every
// table stays an external object (ownership pending).
struct Mx21obFeRoot {
    virtual void slot0();
};

struct Mx21obFeTagged : Mx21obFeRoot {
    unsigned char unknown[16];     // +4..+19, initialized by 0x801ea0ec
    Mx21obFeTagged(unsigned short id);
};

extern "C" void w3d_string_base_init(void *string);
extern "C" unsigned short *w3d_string_header(void *string);
extern "C" void w3d_string_from_text(void *string, const char *text);

// Four-byte shared engine string. Copying retains the shared text through the
// 16-bit reference count returned by the header accessor; construction from
// C text goes through 0x8020bb54.
struct Mx21obFeString {
    char *text;
    Mx21obFeString(const Mx21obFeString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
    Mx21obFeString(const char *source)
    {
        w3d_string_from_text(this, source);
    }
};

extern Mx21obFeString w3d_empty_string_804b06a0[];   // shared empty string

struct Mx21obFeVec3 {
    float x, y, z;
};

// Common widget base, 116 bytes. Its constructor 0x8021ef08 is not recovered
// (external original-address binding): it sets vec20 to (50, 50, 0) and
// vec32 to zero, fifteen strings to the shared empty string, value64 to
// 0.0f, both trailing ints to 0, and clears bit 0x04 of the byte at +11.
struct Mx21obFeWidget : Mx21obFeTagged {
    Mx21obFeVec3 vec20;            // +20
    Mx21obFeVec3 vec32;            // +32
    Mx21obFeString text44;         // +44
    Mx21obFeString text48;         // +48
    Mx21obFeString text52;         // +52
    Mx21obFeString text56;         // +56
    Mx21obFeString text60;         // +60
    float value64;                 // +64
    Mx21obFeString text68;         // +68
    Mx21obFeString text72;         // +72
    Mx21obFeString text76;         // +76
    Mx21obFeString text80;         // +80
    Mx21obFeString text84;         // +84
    Mx21obFeString text88;         // +88
    Mx21obFeString text92;         // +92
    Mx21obFeString text96;         // +96
    Mx21obFeString text100;        // +100
    Mx21obFeString text104;        // +104
    int value108;                  // +108
    int value112;                  // +112
    Mx21obFeWidget(unsigned short id);
    void slot0();
};

// Button widget, 152 bytes; constructor 0x8021fd28. The "button" reading
// comes from the "FE.Button.%s" name pattern, so it is inferred.
struct Mx21obFeButton : Mx21obFeWidget {
    float value116;                // +116, starts as 0.0f
    int value120;                  // +120, starts as 1
    Mx21obFeString name124;        // +124, starts as "FE.Button.%s"
    Mx21obFeString text128;        // +128, starts as the shared empty string
    Mx21obFeString text132;        // +132, starts as the shared empty string
    Mx21obFeString text136;        // +136, starts as the shared empty string
    int value140;                  // +140, starts as 0
    int value144;                  // +144, starts as 1
    int value148;                  // +148, starts as 0
    Mx21obFeButton(unsigned short id);
    void slot0();
};

// Four unsigned bytes set by an inline constructor. The original stores byte
// 0, then 3, 1, 2 (scheduler order); the RGBA reading is inferred.
struct Mx21obFeColour {
    unsigned char r, g, b, a;
    Mx21obFeColour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
        : r(red), g(green), b(blue), a(alpha) {}
};

// Font-bearing widget, 156 bytes; constructor 0x8022240c (not recovered:
// near miss). The font reading comes from the "FE.Font" name only.
struct Mx21obFeFontWidget : Mx21obFeWidget {
    Mx21obFeColour colour116;      // +116, starts as 0xff in every byte
    float value120;                // +120, starts as 0.0f
    int value124;                  // +124, starts as 4
    int value128;                  // +128, starts as 1
    Mx21obFeString text132;        // +132, starts as the shared empty string
    Mx21obFeString text136;        // +136, starts as the shared empty string
    Mx21obFeString font140;        // +140, starts as "FE.Font"
    int value144;                  // +144, starts as 0
    int value148;                  // +148, starts as 0
    int value152;                  // +152, starts as 0
    Mx21obFeFontWidget(unsigned short id);
    void slot0();
};

// Shared texts: the original keeps one copy of each, used by several
// constructors. One unit pools each copy as a string literal and owns its
// bytes (a named definition changes the pool order, see
// build/mx21ob/mx21ob_v2_button_8021fd28-build.log); the other units refer to
// the copy as these external objects, bound by original address. Portability
// limitation: no unit defines these names, so a whole-source link must
// provide them.
extern const char w3d_text_fe_button_pattern_803b61f8[];   // "FE.Button.%s", owned by mx21ob_v2_button_8021fd28
extern const char w3d_text_fe_font_803b6408[];             // "FE.Font", owned by mx21ob_v2_slider_80220200

#endif
