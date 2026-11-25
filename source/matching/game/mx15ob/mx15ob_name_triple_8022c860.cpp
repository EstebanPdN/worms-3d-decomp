// Three-name record constructor at 0x8022c860. Class and member names are inferred;
// offsets are observed from the original instructions.
//
// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; the slot is declared, not defined, so the
// record table 0x80419fd8 stays an external object (ownership pending).
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

struct Mx15obNameTriple : Mx15obTagged {
    Mx15obString first;            // +20
    Mx15obString second;           // +24
    Mx15obString third;            // +28
    int value;                     // +32, starts cleared
    Mx15obNameTriple(unsigned short id);
    void slot0();
};

Mx15obNameTriple::Mx15obNameTriple(unsigned short id)
    : Mx15obTagged(id), first(w3d_empty_string_804b06a0[0]),
      second(w3d_empty_string_804b06a0[0]), third(w3d_empty_string_804b06a0[0]), value(0)
{
}
