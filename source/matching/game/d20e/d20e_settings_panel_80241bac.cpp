// Front-end settings panel constructor (Worms 3D GameCube PAL, 0x80241bac).
//
// Runs the tagged property base constructor 0x801ea0ec with the caller's
// 16-bit id, installs the panel table 0x8041b540, zeroes seven vectors at
// +20..+92, copy-constructs strings at +108/+140/+152 from the shared empty
// string 0x804b06a0 (retaining it), initializes the remaining int, float,
// short and byte members up to +282 (several byte flags start as 1, the ints
// at +188 and +256 as 1, everything else as 0), then calls the refresh
// routine 0x802487c4 on the new object.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The tagged base is declared as an opaque
// out-of-line constructor; the table slot is declared, not defined, so the
// table stays an external object. Built with -mps-float (one saved FPR in a
// non-leaf function). The string header returned by 0x80341884 is declared
// as a structure holding the 16-bit reference count.
struct D20eTaggedRoot {
    virtual void slot0();
};

struct D20eTagged : D20eTaggedRoot {
    unsigned char unknown[16];     // +4..+19, initialized by 0x801ea0ec
    D20eTagged(unsigned short id);
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

struct D20eVec3 {
    float x, y, z;
    D20eVec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct D20eSettingsPanel : D20eTagged {
    D20eVec3 vec20;
    D20eVec3 vec32;
    D20eVec3 vec44;
    D20eVec3 vec56;
    D20eVec3 vec68;
    D20eVec3 vec80;
    D20eVec3 vec92;
    int value104;
    D20eString text108;
    int value112;
    float value116;
    int value120;
    float value124;
    int value128;
    int value132;
    int value136;
    D20eString text140;
    float value144;
    float value148;
    D20eString text152;
    int value156;
    int value160;
    int value164;
    short value168;
    short value170;
    unsigned char byte172;
    unsigned char byte173;
    unsigned char byte174;
    unsigned char byte175;
    unsigned char byte176;
    unsigned char byte177;
    unsigned char byte178;
    unsigned char byte179;
    int value180;
    int value184;
    int value188;
    int value192;
    int value196;
    int value200;
    int value204;
    int value208;
    unsigned char byte212;
    unsigned char byte213;
    int value216;
    int value220;
    unsigned char byte224;
    unsigned char byte225;
    unsigned char byte226;
    unsigned char byte227;
    unsigned char byte228;
    unsigned char byte229;
    unsigned char byte230;
    unsigned char byte231;
    unsigned char byte232;
    unsigned char byte233;
    unsigned char byte234;
    unsigned char byte235;
    unsigned char byte236;
    unsigned char byte237;
    unsigned char byte238;
    unsigned char byte239;
    unsigned char byte240;
    unsigned char byte241;
    unsigned char byte242;
    unsigned char byte243;
    unsigned char byte244;
    unsigned char byte245;
    unsigned char byte246;
    int value248;
    unsigned char byte252;
    int value256;
    int value260;
    unsigned char byte264;
    unsigned char byte265;
    unsigned char byte266;
    unsigned char byte267;
    unsigned char byte268;
    unsigned char byte269;
    unsigned char byte270;
    unsigned char byte271;
    unsigned char byte272;
    unsigned char byte273;
    unsigned char byte274;
    unsigned char byte275;
    unsigned char byte276;
    unsigned char byte277;
    unsigned char byte278;
    unsigned char byte279;
    unsigned char byte280;
    unsigned char byte281;
    unsigned char byte282;
    D20eSettingsPanel(unsigned short id);
    void slot0();
    void refresh_802487c4();
};

D20eSettingsPanel::D20eSettingsPanel(unsigned short id)
    : D20eTagged(id),
      vec20(0, 0, 0),
      vec32(0, 0, 0),
      vec44(0, 0, 0),
      vec56(0, 0, 0),
      vec68(0, 0, 0),
      vec80(0, 0, 0),
      vec92(0, 0, 0),
      value104(0),
      text108(w3d_empty_string_804b06a0[0]),
      value112(0),
      value116(0),
      value120(0),
      value124(0),
      value128(0),
      value132(0),
      value136(0),
      text140(w3d_empty_string_804b06a0[0]),
      value144(0),
      value148(0),
      text152(w3d_empty_string_804b06a0[0]),
      value156(0),
      value160(0),
      value164(0),
      value168(0),
      value170(0),
      byte172(1),
      byte173(1),
      byte174(1),
      byte175(1),
      byte176(1),
      byte177(1),
      byte178(1),
      byte179(1),
      value180(0),
      value184(0),
      value188(1),
      value192(0),
      value196(0),
      value200(0),
      value204(0),
      value208(0),
      byte212(0),
      byte213(0),
      value216(0),
      value220(0),
      byte224(1),
      byte225(1),
      byte226(1),
      byte227(1),
      byte228(1),
      byte229(1),
      byte230(1),
      byte231(1),
      byte232(1),
      byte233(1),
      byte234(1),
      byte235(1),
      byte236(1),
      byte237(1),
      byte238(1),
      byte239(1),
      byte240(1),
      byte241(1),
      byte242(1),
      byte243(1),
      byte244(1),
      byte245(1),
      byte246(1),
      value248(0),
      byte252(1),
      value256(1),
      value260(0),
      byte264(1),
      byte265(1),
      byte266(1),
      byte267(1),
      byte268(1),
      byte269(1),
      byte270(1),
      byte271(1),
      byte272(1),
      byte273(1),
      byte274(1),
      byte275(1),
      byte276(1),
      byte277(1),
      byte278(1),
      byte279(1),
      byte280(1),
      byte281(1),
      byte282(1)
{
    refresh_802487c4();
}
