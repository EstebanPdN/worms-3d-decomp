// Colour style record constructor at 0x802460a0. Class and member names are structural;
// offsets are observed from the original instructions.
//
// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; the slot is declared, not defined, so the
// table 0x8041b388 stays an external object (ownership pending).
struct Mx15obRoot {
    virtual void slot0();
};

struct Mx15obTagged : Mx15obRoot {
    unsigned char unknown[16];     // +4..+19, initialized by 0x801ea0ec
    Mx15obTagged(unsigned short id);
};

extern "C" void w3d_string_base_init(void *string);
extern "C" unsigned short *w3d_string_header(void *string);

// Four-byte shared engine string. Copying retains the shared text through the
// 16-bit reference count returned by the header accessor.
struct Mx15obString {
    char *text;
    Mx15obString(const Mx15obString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern Mx15obString w3d_empty_string_804b06a0[];   // shared empty string

// Four unsigned bytes cleared by an inline default constructor. The original
// stores byte 0, then 3, 1, 2 (scheduler order); the meaning as an RGBA
// colour is inferred from the size and grouping only.
struct Mx17obColour {
    unsigned char r, g, b, a;
    Mx17obColour() : r(0), g(0), b(0), a(0) {}
};

// The float members start as the literal 0.0f; the compiler pools it, and the
// pool word is the original's 0x803c2bbc (unit-owned data, value 0).
struct Mx17obColourStyle : Mx15obTagged {
    Mx17obColour colour20;          // +20, cleared
    Mx17obColour colour24;          // +24, cleared
    Mx17obColour colour28;          // +28, cleared
    Mx17obColour colour32;          // +32, cleared
    Mx17obColour colour36;          // +36, cleared
    Mx17obColour colour40;          // +40, cleared
    Mx17obColour colour44;          // +44, cleared
    Mx17obColour colour48;          // +48, cleared
    Mx17obColour colour52;          // +52, cleared
    Mx17obColour colour56;          // +56, cleared
    Mx17obColour colour60;          // +60, cleared
    Mx17obColour colour64;          // +64, cleared
    Mx17obColour colour68;          // +68, cleared
    Mx17obColour colour72;          // +72, cleared
    Mx17obColour colour76;          // +76, cleared
    Mx17obColour colour80;          // +80, cleared
    Mx17obColour colour84;          // +84, cleared
    float value88;                 // +88, starts as 0.0f
    Mx17obColour colour92;          // +92, cleared
    Mx17obColour colour96;          // +96, cleared
    float value100;                // +100, starts as 0.0f
    float value104;                // +104, starts as 0.0f
    float value108;                // +108, starts as 0.0f
    float value112;                // +112, starts as 0.0f
    float value116;                // +116, starts as 0.0f
    Mx17obColour colour120;         // +120, cleared
    Mx15obString text124;         // +124, starts as the shared empty string
    Mx15obString text128;         // +128, starts as the shared empty string
    Mx15obString text132;         // +132, starts as the shared empty string
    Mx15obString text136;         // +136, starts as the shared empty string
    Mx17obColour colour140;         // +140, cleared
    Mx17obColour colour144;         // +144, cleared
    Mx17obColour colour148;         // +148, cleared
    Mx17obColour colour152;         // +152, cleared
    Mx17obColour colour156;         // +156, cleared
    Mx17obColour colour160;         // +160, cleared
    Mx17obColourStyle(unsigned short id);
    void slot0();
};

Mx17obColourStyle::Mx17obColourStyle(unsigned short id)
    : Mx15obTagged(id),
      colour20(),
      colour24(),
      colour28(),
      colour32(),
      colour36(),
      colour40(),
      colour44(),
      colour48(),
      colour52(),
      colour56(),
      colour60(),
      colour64(),
      colour68(),
      colour72(),
      colour76(),
      colour80(),
      colour84(),
      value88(0.0f),
      colour92(),
      colour96(),
      value100(0.0f),
      value104(0.0f),
      value108(0.0f),
      value112(0.0f),
      value116(0.0f),
      colour120(),
      text124(w3d_empty_string_804b06a0[0]),
      text128(w3d_empty_string_804b06a0[0]),
      text132(w3d_empty_string_804b06a0[0]),
      text136(w3d_empty_string_804b06a0[0]),
      colour140(),
      colour144(),
      colour148(),
      colour152(),
      colour156(),
      colour160()
{
}
