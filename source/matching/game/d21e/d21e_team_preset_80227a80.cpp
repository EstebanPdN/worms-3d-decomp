// Team preset constructor (Worms 3D GameCube PAL, 0x80227a80).
//
// Derived team object: runs the team constructor 0x80227398 (recovered in
// mx24ob_team_setup_80227398) with the caller's 16-bit id, installs the
// table 0x8041a140 and zeroes +68 and +72; then, like the base, opens six
// entries of the string array (0x80231f14), formats "Worm 1".."Worm 6"
// (0x803b506c) into a local string (default constructor 0x803426b8,
// formatter 0x8020c510) and assigns each with reference counting, and
// appends the retained result of the service lookup 0x8020b680 (key
// 0x80419ea8) to the object array (0x80231fd0). Returns this.
//
// The type views repeat the base unit's declarations (partial views; the
// base constructor stays out of line). The derived table slots are declared,
// not defined, so the table stays an external original object. Built with
// -fvtable-thunks like the base unit (4-byte table entries, retain/release
// through slots +12/+16).
extern "C" {
void w3d_string_from_text(void *string, const char *text);
void w3d_string_base_init(void *string);
unsigned short *w3d_string_header(void *string);
void w3d_string_format(void *string, const char *format, ...);
void w3d_string_base_finish(void *string);
void w3d_string_release(void *string);
void w3d_string_release_header(void *header);
}

// Polymorphic reference-counted root. Table slot +8 is 0x801ea0a4 (it
// forwards two arguments to a query; their meaning is unknown), +12 retains,
// +16 releases and +20 returns a per-class address (read as a type
// descriptor). Slots are declared, not defined, so tables stay external.
struct D21eObject {
    virtual int query(void *first, void *second);
    virtual unsigned short retain();
    virtual unsigned short release();
    virtual void *type();
};

// The tagged base is constructed out of line by 0x801ea0ec with the caller's
// 16-bit id; its 16 bytes after the table pointer are not described here.
struct D21eTagged : D21eObject {
    unsigned char unknown[16];     // +4..+19, initialized by 0x801ea0ec
    D21eTagged(unsigned short id);
};

// Four-byte shared engine string: a pointer to text whose 16-bit reference
// count sits 6 bytes before it. The default constructor is the out-of-line
// 0x803426b8; construction from C text goes through 0x8020bb54. The copy
// constructor makes the type addressable, so locals of it take an 8-byte
// aligned stack slot as in the original frame.
struct D21eString {
    char *text;
    D21eString();
    D21eString(const char *source) { w3d_string_from_text(this, source); }
    D21eString(const D21eString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
    ~D21eString() { w3d_string_base_finish(this); w3d_string_release(this); }
    D21eString &operator=(const D21eString &other)
    {
        char *incoming = other.text;
        ++*(unsigned short *)(incoming - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned int count = *(unsigned short *)(old - 6) - 1;
        *(unsigned short *)(old - 6) = count;
        if (!(unsigned short)count)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};

// Retaining pointer to a root object (retain on copy, release on exit).
struct D21eHandle {
    D21eObject *object;
    D21eHandle(D21eObject *p) : object(p) { if (p) p->retain(); }
    D21eHandle(const D21eHandle &other) : object(other.object) { if (object) object->retain(); }
    ~D21eHandle() { if (object) object->release(); }
};

// Shared empty array stores (small data) that new arrays start from.
extern D21eObject *w3d_default_store_804b05ac;
extern D21eObject *w3d_default_store_804b05b0;
// "Worm %d", pooled with another unit's texts (0x803b506c); referenced, not owned.
extern const char w3d_text_worm_number_803b506c[];
// Argument of the service lookup 0x8020b680 (meaning unknown).
extern char w3d_service_key_80419ea8[];

struct D21eTeam;
// Writable access to the string array at +56 (0x80231f14), and append to the
// object array at +52 (0x80231fd0).
extern "C" D21eString *w3d_cc18b_array_write_80231f14(D21eTeam *owner, unsigned int count, unsigned int flags, unsigned int *previous);
extern "C" void w3d_auto_80231fd0(D21eTeam *owner, D21eObject *item);
extern "C" D21eObject *w3d_s10_service_forward_8020b680(void *key);

// 68 bytes; table 0x8041a168.
struct D21eTeam : D21eTagged {
    D21eString text20;           // +20, starts as ""
    D21eString style24;          // +24, starts as "Classic"
    D21eString text28;           // +28, starts as "0"
    int value32;                   // +32..+48, start as 0
    int value36;
    int value40;
    int value44;
    int value48;
    D21eHandle items52;          // +52, object array store (from 0x804b05ac)
    D21eHandle names56;          // +56, string array store (from 0x804b05b0)
    D21eString name60;           // +60, starts as "TeamName"
    int value64;                   // +64, starts as 0
    D21eTeam(unsigned short id);   // 0x80227398, out of line
    unsigned short release();      // table slot +16: 0x8022e970
    void *type();                  // table slot +20: 0x802272e0
};


struct D21eTeamPreset : D21eTeam {
    int value68;                   // +68, starts as 0
    int value72;                   // +72, starts as 0
    D21eTeamPreset(unsigned short id);
    unsigned short release();
    void *type();
};

D21eTeamPreset::D21eTeamPreset(unsigned short id)
    : D21eTeam(id), value68(0), value72(0)
{
    D21eString *names = w3d_cc18b_array_write_80231f14(this, 6, 0, 0);
    D21eString number;
    for (int i = 0; i < 6; i++) {
        w3d_string_format(&number, w3d_text_worm_number_803b506c, i + 1);
        names[i] = number;
    }
    D21eHandle item(w3d_s10_service_forward_8020b680(w3d_service_key_80419ea8));
    w3d_auto_80231fd0(this, item.object);
}
