// Shared declarations for the front-end widget family whose base constructor
// is 0x8021ef08. Class and member names are structural; offsets are observed
// from the original instructions.
#ifndef MX21OB_WIDGET_H
#define MX21OB_WIDGET_H

// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; slots are declared, not defined, so every
// table stays an external object (ownership pending).
struct Mx15obRoot {
    virtual void slot0();
};

struct Mx15obTagged : Mx15obRoot {
    unsigned char unknown[16];     // +4..+19, initialized by 0x801ea0ec
    Mx15obTagged(unsigned short id);
};

extern "C" void w3d_string_base_init(void *string);
extern "C" unsigned short *w3d_string_header(void *string);
extern "C" void w3d_string_from_text(void *string, const char *text);

// Four-byte shared engine string. Copying retains the shared text through the
// 16-bit reference count returned by the header accessor; construction from
// C text goes through 0x8020bb54.
struct Mx15obString {
    char *text;
    Mx15obString(const Mx15obString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
    Mx15obString(const char *source)
    {
        w3d_string_from_text(this, source);
    }
};

extern Mx15obString w3d_empty_string_804b06a0[];   // shared empty string

struct Mx21obVec3 {
    float x, y, z;
};

// Common widget base, 116 bytes. Its constructor 0x8021ef08 is not part of
// this header's units (external original-address binding): it sets vec20 to
// (50, 50, 0) and vec32 to zero, fifteen strings to the shared empty string,
// value64 to 0.0f, both trailing ints to 0, and clears bit 0x04 of the byte
// at +11.
struct Mx21obWidget : Mx15obTagged {
    Mx21obVec3 vec20;              // +20
    Mx21obVec3 vec32;              // +32
    Mx15obString text44;           // +44
    Mx15obString text48;           // +48
    Mx15obString text52;           // +52
    Mx15obString text56;           // +56
    Mx15obString text60;           // +60
    float value64;                 // +64
    Mx15obString text68;           // +68
    Mx15obString text72;           // +72
    Mx15obString text76;           // +76
    Mx15obString text80;           // +80
    Mx15obString text84;           // +84
    Mx15obString text88;           // +88
    Mx15obString text92;           // +92
    Mx15obString text96;           // +96
    Mx15obString text100;          // +100
    Mx15obString text104;          // +104
    int value108;                  // +108
    int value112;                  // +112
    Mx21obWidget(unsigned short id);
    void slot0();
};

#endif
