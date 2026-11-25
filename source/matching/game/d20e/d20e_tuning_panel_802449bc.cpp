// Front-end tuning panel constructor (Worms 3D GameCube PAL, 0x802449bc).
//
// Runs the tagged property base constructor 0x801ea0ec with the caller's
// 16-bit id, installs the panel table 0x8041b428, initializes the float
// members from +20 to +480 with their default values (the unit's literal
// pool, in first-use order), copy-constructs strings at +144/+172/+244 from
// the shared empty string 0x804b06a0 (retaining it), sets the ints at
// +484..+496 to 1 and then calls 0x8021d0fc on the new object.
//
// Class and member names are structural; offsets and values are observed
// from the original instructions and literal pool. The tagged base is
// declared as an opaque out-of-line constructor; the table slot is declared,
// not defined, so the table stays an external object. Built with -mps-float
// (non-leaf function saving eight FPRs). The string header returned by
// 0x80341884 is declared as a structure holding the 16-bit reference count.
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

struct D20eTuningPanel : D20eTagged {
    float value20;
    float value24;
    float value28;
    float value32;
    float value36;
    float value40;
    float value44;
    float value48;
    float value52;
    float value56;
    float value60;
    float value64;
    float value68;
    float value72;
    float value76;
    float value80;
    float value84;
    float value88;
    float value92;
    float value96;
    float value100;
    float value104;
    float value108;
    float value112;
    float value116;
    float value120;
    float value124;
    float value128;
    float value132;
    float value136;
    float value140;
    D20eString text144;
    float value148;
    float value152;
    float value156;
    float value160;
    float value164;
    float value168;
    D20eString text172;
    float value176;
    float value180;
    float value184;
    float value188;
    float value192;
    float value196;
    float value200;
    float value204;
    float value208;
    float value212;
    float value216;
    float value220;
    float value224;
    float value228;
    float value232;
    float value236;
    float value240;
    D20eString text244;
    float value248;
    float value252;
    float value256;
    float value260;
    float value264;
    float value268;
    float value272;
    float value276;
    float value280;
    float value284;
    float value288;
    float value292;
    float value296;
    float value300;
    float value304;
    float value308;
    float value312;
    float value316;
    float value320;
    float value324;
    float value328;
    float value332;
    float value336;
    float value340;
    float value344;
    float value348;
    float value352;
    float value356;
    float value360;
    float value364;
    float value368;
    float value372;
    float value376;
    float value380;
    float value384;
    float value388;
    float value392;
    float value396;
    float value400;
    float value404;
    float value408;
    float value412;
    float value416;
    float value420;
    float value424;
    float value428;
    float value432;
    float value436;
    float value440;
    float value444;
    float value448;
    float value452;
    float value456;
    float value460;
    float value464;
    float value468;
    float value472;
    float value476;
    float value480;
    int value484;
    int value488;
    int value492;
    int value496;
    D20eTuningPanel(unsigned short id);
    void slot0();
    void update_8021d0fc();
};

D20eTuningPanel::D20eTuningPanel(unsigned short id)
    : D20eTagged(id),
      value20(0.2f),
      value24(0.0f),
      value28(100000.0f),
      value32(10.0f),
      value36(2.0f),
      value40(10.0f),
      value44(1.0f),
      value48(3.0f),
      value52(0.05f),
      value56(0.1f),
      value60(0.2f),
      value64(0.2f),
      value68(1.0f),
      value72(2.0f),
      value76(10.0f),
      value80(1.5f),
      value84(200.0f),
      value88(4.0f),
      value92(1.0f),
      value96(2.0f),
      value100(1.0f),
      value104(0.02f),
      value108(2.0f),
      value112(0.5f),
      value116(0.08f),
      value120(0.04f),
      value124(1000.0f),
      value128(0.0f),
      value132(10000.0f),
      value136(20.0f),
      value140(0.0f),
      text144(w3d_empty_string_804b06a0[0]),
      value148(0.0f),
      value152(0.98f),
      value156(0.0f),
      value160(1.0f),
      value164(0.1f),
      value168(1.0f),
      text172(w3d_empty_string_804b06a0[0]),
      value176(1.0f),
      value180(200.0f),
      value184(1.0f),
      value188(10.0f),
      value192(1.0f),
      value196(25.0f),
      value200(1.0f),
      value204(1.0f),
      value208(3.0f),
      value212(1.0f),
      value216(1.0f),
      value220(15000.0f),
      value224(100.0f),
      value228(100.0f),
      value232(0.0f),
      value236(1.0f),
      value240(10.0f),
      text244(w3d_empty_string_804b06a0[0]),
      value248(1.0f),
      value252(1.0f),
      value256(1.0f),
      value260(1.0f),
      value264(1.0f),
      value268(1.0f),
      value272(1.0f),
      value276(1.0f),
      value280(1.0f),
      value284(1.0f),
      value288(1.0f),
      value292(1.0f),
      value296(1.0f),
      value300(1.0f),
      value304(1.0f),
      value308(1.0f),
      value312(1.0f),
      value316(1.0f),
      value320(1.0f),
      value324(1.0f),
      value328(4.0f),
      value332(1.6f),
      value336(50.0f),
      value340(1.0f),
      value344(1.0f),
      value348(1.0f),
      value352(1.0f),
      value356(1.0f),
      value360(1.0f),
      value364(1.0f),
      value368(1.0f),
      value372(1.0f),
      value376(1.0f),
      value380(1.0f),
      value384(1.0f),
      value388(1.0f),
      value392(1.0f),
      value396(1.0f),
      value400(1.0f),
      value404(1.0f),
      value408(1.0f),
      value412(1.0f),
      value416(1.0f),
      value420(1.0f),
      value424(1.0f),
      value428(1.0f),
      value432(1.0f),
      value436(1.0f),
      value440(1.0f),
      value444(1.0f),
      value448(1.0f),
      value452(1.0f),
      value456(1.0f),
      value460(1.0f),
      value464(1.0f),
      value468(1.0f),
      value472(1.0f),
      value476(1.5f),
      value480(1.0f),
      value484(1),
      value488(1),
      value492(1),
      value496(1)
{
    update_8021d0fc();
}
