// Front-end font label constructor (Worms 3D GameCube PAL, 0x8022240c).
//
// Runs the widget base constructor 0x8021ef08 with the caller's 16-bit id,
// installs the label table 0x8041a488, sets the colour bytes at +116 to 0xff,
// the float at +120 to 0, the ints at +124/+128 to 4 and 1, copy-constructs
// two strings at +132/+136 from the shared empty string 0x804b06a0 (retaining
// it), builds the font name at +140 from the text "FE.Font" (0x803b6408)
// through the out-of-line string constructor 0x8020bb54, and zeroes the ints
// at +144..+152, in member order.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The widget base (admitted separately as d19e) is
// declared here as an opaque out-of-line constructor; the table slot is
// declared, not defined, so the table stays an external object. The font
// text stays an external object (it is not in this constructor's literal
// pool); the 0.0f literal is owned.
struct D20eWidgetRoot {
    virtual void slot0();
};

struct D20eWidget : D20eWidgetRoot {
    unsigned char body[112];       // +4..+115, initialized by 0x8021ef08
    D20eWidget(unsigned short id);
};

extern "C" void w3d_string_base_init(void *string);
extern "C" unsigned short *w3d_string_header(void *string);

// Four-byte shared engine string. The text constructor is out of line
// (0x8020bb54); copying retains the shared text through the 16-bit reference
// count returned by the header accessor.
struct D20eString {
    char *text;
    D20eString(const char *text);
    D20eString(const D20eString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern D20eString w3d_empty_string_804b06a0[];   // shared empty string

extern const char lbl_803b6408[];
struct D20eColour {
    unsigned char r, g, b, a;
    D20eColour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_)
        : r(r_), g(g_), b(b_), a(a_) {}
};
struct D20eFontLabel : D20eWidget {
    D20eColour colour116;
    float value120;
    int value124, value128;
    D20eString text132, text136, text140;
    int value144, value148, value152;
    D20eFontLabel(unsigned short id);
    void slot0();
};
D20eFontLabel::D20eFontLabel(unsigned short id)
    : D20eWidget(id),
      colour116(255, 255, 255, 255),
      value120(0.0f),
      value124(4), value128(1),
      text132(w3d_empty_string_804b06a0[0]), text136(w3d_empty_string_804b06a0[0]),
      text140(lbl_803b6408),
      value144(0), value148(0), value152(0)
{
}
