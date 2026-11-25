// Front-end view panel constructor (Worms 3D GameCube PAL, 0x80242ebc).
//
// Runs the tagged property base constructor 0x801ea0ec with the caller's
// 16-bit id, installs the panel table 0x8041b4c8 and initializes the members
// from +20 to +493 in declaration order: seventeen zero vectors, zero float,
// int, short and byte members, six strings copy-constructed from the shared
// empty string 0x804b06a0 (retaining it), and three references to shared
// objects (+140 and +276 from the global pointer 0x804b05a8, +332 from
// 0x804b05b0), each retained through the fourth slot of its table when
// non-null.
//
// Class and member names are structural; offsets are observed from the
// original instructions. The tagged base is declared as an opaque
// out-of-line constructor; the table slot is declared, not defined, so the
// table stays an external object. Built with -mps-float (one saved FPR in a
// non-leaf function). The shared object globals are plain pointers and the
// string header is a structure: GCC 2.95 then reads 0x804b05b0 before the
// preceding reference-count store, as the original does.
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

// Reference-counted shared object; the fourth table slot retains it.
struct D20eShared;

struct D20eSharedTable {
    void *slot0;
    void *slot4;
    void *slot8;
    void (*retain)(D20eShared *object);
};

struct D20eShared {
    D20eSharedTable *table;
};

struct D20eRef {
    D20eShared *object;
    D20eRef(D20eShared *shared) : object(shared)
    {
        if (object)
            object->table->retain(object);
    }
};

extern D20eShared *w3d_shared_object_804b05a8;
extern D20eShared *w3d_shared_object_804b05b0;

struct D20eViewPanel : D20eTagged {
    D20eVec3 vec20;
    D20eVec3 vec32;
    D20eVec3 vec44;
    D20eVec3 vec56;
    D20eVec3 vec68;
    D20eVec3 vec80;
    D20eVec3 vec92;
    D20eVec3 vec104;
    D20eVec3 vec116;
    D20eVec3 vec128;
    D20eRef ref140;
    D20eVec3 vec144;
    D20eVec3 vec156;
    D20eVec3 vec168;
    D20eVec3 vec180;
    D20eVec3 vec192;
    D20eVec3 vec204;
    D20eVec3 vec216;
    float value228;
    float value232;
    float value236;
    float value240;
    float value244;
    float value248;
    float value252;
    float value256;
    float value260;
    float value264;
    float value268;
    float value272;
    D20eRef ref276;
    float value280;
    float value284;
    float value288;
    float value292;
    D20eString text296;
    float value300;
    int value304;
    D20eString text308;
    D20eString text312;
    float value316;
    int value320;
    float value324;
    D20eString text328;
    D20eRef ref332;
    D20eString text336;
    D20eString text340;
    float value344;
    int value348;
    float value352;
    float value356;
    float value360;
    float value364;
    float value368;
    float value372;
    float value376;
    int value380;
    float value384;
    short value388;
    short value390;
    short value392;
    short value394;
    short value396;
    short value398;
    short value400;
    short value402;
    short value404;
    short value406;
    short value408;
    short value410;
    short value412;
    short value414;
    short value416;
    short value418;
    short value420;
    short value422;
    short value424;
    unsigned char byte426;
    int value428;
    int value432;
    int value436;
    int value440;
    int value444;
    int value448;
    int value452;
    int value456;
    int value460;
    int value464;
    int value468;
    int value472;
    unsigned char byte476;
    int value480;
    unsigned char byte484;
    unsigned char byte485;
    int value488;
    unsigned char byte492;
    unsigned char byte493;
    D20eViewPanel(unsigned short id);
    void slot0();
};

D20eViewPanel::D20eViewPanel(unsigned short id)
    : D20eTagged(id),
      vec20(0, 0, 0),
      vec32(0, 0, 0),
      vec44(0, 0, 0),
      vec56(0, 0, 0),
      vec68(0, 0, 0),
      vec80(0, 0, 0),
      vec92(0, 0, 0),
      vec104(0, 0, 0),
      vec116(0, 0, 0),
      vec128(0, 0, 0),
      ref140(w3d_shared_object_804b05a8),
      vec144(0, 0, 0),
      vec156(0, 0, 0),
      vec168(0, 0, 0),
      vec180(0, 0, 0),
      vec192(0, 0, 0),
      vec204(0, 0, 0),
      vec216(0, 0, 0),
      value228(0),
      value232(0),
      value236(0),
      value240(0),
      value244(0),
      value248(0),
      value252(0),
      value256(0),
      value260(0),
      value264(0),
      value268(0),
      value272(0),
      ref276(w3d_shared_object_804b05a8),
      value280(0),
      value284(0),
      value288(0),
      value292(0),
      text296(w3d_empty_string_804b06a0[0]),
      value300(0),
      value304(0),
      text308(w3d_empty_string_804b06a0[0]),
      text312(w3d_empty_string_804b06a0[0]),
      value316(0),
      value320(0),
      value324(0),
      text328(w3d_empty_string_804b06a0[0]),
      ref332(w3d_shared_object_804b05b0),
      text336(w3d_empty_string_804b06a0[0]),
      text340(w3d_empty_string_804b06a0[0]),
      value344(0),
      value348(0),
      value352(0),
      value356(0),
      value360(0),
      value364(0),
      value368(0),
      value372(0),
      value376(0),
      value380(0),
      value384(0),
      value388(0),
      value390(0),
      value392(0),
      value394(0),
      value396(0),
      value398(0),
      value400(0),
      value402(0),
      value404(0),
      value406(0),
      value408(0),
      value410(0),
      value412(0),
      value414(0),
      value416(0),
      value418(0),
      value420(0),
      value422(0),
      value424(0),
      byte426(0),
      value428(0),
      value432(0),
      value436(0),
      value440(0),
      value444(0),
      value448(0),
      value452(0),
      value456(0),
      value460(0),
      value464(0),
      value468(0),
      value472(0),
      byte476(0),
      value480(0),
      byte484(0),
      byte485(0),
      value488(0),
      byte492(0),
      byte493(0)
{
}
