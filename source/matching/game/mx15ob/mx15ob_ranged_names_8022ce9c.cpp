// Ranged name record constructor at 0x8022ce9c. Class and member names are structural;
// offsets are observed from the original instructions.
//
// The tagged property base is constructed out of line by 0x801ea0ec, which
// takes the caller's 16-bit id unchanged in r4 and stores it at +6. Its table
// pointer sits at offset 0, so the base derives from a data-less polymorphic
// root. Slot meanings are unknown; the slot is declared, not defined, so the
// table 0x80419f88 stays an external object (ownership pending).
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

extern const float lbl_803ba748[];    // original constant, external object
extern const float lbl_803ba74c[];    // original constant, external object

struct Mx15obRangedNames : Mx15obTagged {
    float value20;                 // +20, starts as the constant at 0x803ba748
    float value24;                 // +24, starts as the constant at 0x803ba74c
    Mx15obString text28;            // +28, starts as the shared empty string
    int value32;                   // +32, starts as 0
    Mx15obString text36;            // +36, starts as the shared empty string
    Mx15obString text40;            // +40, starts as the shared empty string
    int value44;                   // +44, starts as 0
    Mx15obString text48;            // +48, starts as the shared empty string
    Mx15obString text52;            // +52, starts as the shared empty string
    Mx15obString text56;            // +56, starts as the shared empty string
    Mx15obString text60;            // +60, starts as the shared empty string
    Mx15obString text64;            // +64, starts as the shared empty string
    Mx15obString text68;            // +68, starts as the shared empty string
    Mx15obString text72;            // +72, starts as the shared empty string
    int value76;                   // +76, starts as 1
    Mx15obRangedNames(unsigned short id);
    void slot0();
};

Mx15obRangedNames::Mx15obRangedNames(unsigned short id)
    : Mx15obTagged(id),
      value20(lbl_803ba748[0]),
      value24(lbl_803ba74c[0]),
      text28(w3d_empty_string_804b06a0[0]),
      value32(0),
      text36(w3d_empty_string_804b06a0[0]),
      text40(w3d_empty_string_804b06a0[0]),
      value44(0),
      text48(w3d_empty_string_804b06a0[0]),
      text52(w3d_empty_string_804b06a0[0]),
      text56(w3d_empty_string_804b06a0[0]),
      text60(w3d_empty_string_804b06a0[0]),
      text64(w3d_empty_string_804b06a0[0]),
      text68(w3d_empty_string_804b06a0[0]),
      text72(w3d_empty_string_804b06a0[0]),
      value76(1)
{
}
