// Flight panel subclass constructor (Worms 3D GameCube PAL, 0x802555b0).
//
// Runs the base constructor 0x80255120 with the caller's 16-bit id, installs
// the subclass table 0x8041ba18, copy-constructs seven strings at +580..+604
// from the shared empty string 0x804b06a0 (retaining it), and zeroes the
// floats at +608/+612 and +620..+668 and the int at +616, in member order.
//
// Class and member names are structural ("flight" follows an earlier
// draft's naming and is unconfirmed); offsets are observed from the original
// instructions. The base is declared as an opaque out-of-line constructor;
// the table slot is declared, not defined, so the table stays an external
// object. The string header returned by 0x80341884 is declared as a
// structure holding the 16-bit reference count.
struct D20eFlightBaseRoot {
    virtual void slot0();
};

struct D20eFlightBase : D20eFlightBaseRoot {
    unsigned char unknown[576];    // +4..+579, initialized by 0x80255120
    D20eFlightBase(unsigned short id);
};

struct D20eStringHeader {
    unsigned short references;
};

extern "C" void w3d_string_base_init(void *string);
extern "C" D20eStringHeader *w3d_string_header(void *string);

// Four-byte shared engine string. Copying retains the shared text through the
// reference count in the header returned by the accessor.
struct D20eString {
    char *text;
    D20eString(const D20eString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++w3d_string_header(this)->references;
    }
};

extern D20eString w3d_empty_string_804b06a0[];   // shared empty string

struct D20eFlightPanel : D20eFlightBase {
    D20eString text580;
    D20eString text584;
    D20eString text588;
    D20eString text592;
    D20eString text596;
    D20eString text600;
    D20eString text604;
    float value608;
    float value612;
    int value616;
    float value620;
    float value624;
    float value628;
    float value632;
    float value636;
    float value640;
    float value644;
    float value648;
    float value652;
    float value656;
    float value660;
    float value664;
    float value668;
    D20eFlightPanel(unsigned short id);
    void slot0();
};

D20eFlightPanel::D20eFlightPanel(unsigned short id)
    : D20eFlightBase(id),
      text580(w3d_empty_string_804b06a0[0]),
      text584(w3d_empty_string_804b06a0[0]),
      text588(w3d_empty_string_804b06a0[0]),
      text592(w3d_empty_string_804b06a0[0]),
      text596(w3d_empty_string_804b06a0[0]),
      text600(w3d_empty_string_804b06a0[0]),
      text604(w3d_empty_string_804b06a0[0]),
      value608(0),
      value612(0),
      value616(0),
      value620(0),
      value624(0),
      value628(0),
      value632(0),
      value636(0),
      value640(0),
      value644(0),
      value648(0),
      value652(0),
      value656(0),
      value660(0),
      value664(0),
      value668(0)
{
}
