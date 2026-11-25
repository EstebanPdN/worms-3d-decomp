#include "w3d_ptr.h"
#line 1 "d21e_team_preset_80227a80.cpp"
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
void w3d_string_from_text(Ptr32<void> string, Ptr32<const char> text);
void w3d_string_base_init(Ptr32<void> string);
Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);
void w3d_string_format(Ptr32<void> string, Ptr32<const char> format, ...);
void w3d_string_base_finish(Ptr32<void> string);
void w3d_string_release(Ptr32<void> string);
void w3d_string_release_header(Ptr32<void> header);
}

// Polymorphic reference-counted root. Table slot +8 is 0x801ea0a4 (it
// forwards two arguments to a query; their meaning is unknown), +12 retains,
// +16 releases and +20 returns a per-class address (read as a type
// descriptor). Slots are declared, not defined, so tables stay external.
struct D21eObject {
    int w3d_r_query(Ptr32<void> first, Ptr32<void> second) __asm__(W3D_SYM("_ZN10D21eObject5queryEPvS0_"));
    unsigned short w3d_r_retain() __asm__(W3D_SYM("_ZN10D21eObject6retainEv"));
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN10D21eObject7releaseEv"));
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN10D21eObject4typeEv"));
 __attribute__((always_inline)) inline int query(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_D21eObject, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline unsigned short retain() { return ((unsigned short (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D21eObject, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned short release() { return ((unsigned short (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D21eObject, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<void> type() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D21eObject, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D21eObject; };

// The tagged base is constructed out of line by 0x801ea0ec with the caller's
// 16-bit id; its 16 bytes after the table pointer are not described here.
struct D21eTagged : D21eObject {
    unsigned char unknown[16] __attribute__((aligned(__alignof__(D21eObject))));     // +4..+19, initialized by 0x801ea0ec
    D21eTagged(unsigned short id);
};

// Four-byte shared engine string: a pointer to text whose 16-bit reference
// count sits 6 bytes before it. The default constructor is the out-of-line
// 0x803426b8; construction from C text goes through 0x8020bb54. The copy
// constructor makes the type addressable, so locals of it take an 8-byte
// aligned stack slot as in the original frame.
struct D21eString {
    Ptr32<char> text;
    D21eString();
    template <class W3dU> D21eString(Ptr32<W3dU> w3d_p) : D21eString((const char *)w3d_p.get()) {}
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
        Ptr32<char> incoming = other.text;
        ++*(Ptr32<unsigned short>)(incoming - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned int count = *(Ptr32<unsigned short>)(old - 6) - 1;
        *(Ptr32<unsigned short>)(old - 6) = count;
        if (!(unsigned short)count)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};

// Retaining pointer to a root object (retain on copy, release on exit).
struct D21eHandle {
    Ptr32<D21eObject> object;
    template <class W3dU> D21eHandle(Ptr32<W3dU> w3d_p) : D21eHandle((D21eObject *)w3d_p.get()) {}
 D21eHandle(D21eObject *p) : object(p) { if (p) p->retain(); }
    D21eHandle(const D21eHandle &other) : object(other.object) { if (object) object->retain(); }
    ~D21eHandle() { if (object) object->release(); }
};

// Shared empty array stores (small data) that new arrays start from.
extern Ptr32<D21eObject> w3d_default_store_804b05ac;
extern Ptr32<D21eObject> w3d_default_store_804b05b0;
// "Worm %d", pooled with another unit's texts (0x803b506c); referenced, not owned.
extern const char w3d_text_worm_number_803b506c[];
// Argument of the service lookup 0x8020b680 (meaning unknown).
extern char w3d_service_key_80419ea8[];

struct D21eTeam;
// Writable access to the string array at +56 (0x80231f14), and append to the
// object array at +52 (0x80231fd0).
extern "C" Ptr32<D21eString> w3d_cc18b_array_write_80231f14(Ptr32<D21eTeam> owner, unsigned int count, unsigned int flags, Ptr32<unsigned int> previous);
extern "C" void w3d_auto_80231fd0(Ptr32<D21eTeam> owner, Ptr32<D21eObject> item);
extern "C" Ptr32<D21eObject> w3d_s10_service_forward_8020b680(Ptr32<void> key);

// 68 bytes; table 0x8041a168.
struct D21eTeam : D21eTagged {
    D21eString text20 __attribute__((aligned(__alignof__(D21eTagged))));           // +20, starts as ""
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
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN8D21eTeam7releaseEv"));      // table slot +16: 0x8022e970
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN8D21eTeam4typeEv"));                  // table slot +20: 0x802272e0
 __attribute__((always_inline)) inline unsigned short release() { return this->D21eTagged::release(); }  __attribute__((always_inline)) inline Ptr32<void> type() { return this->D21eTagged::type(); } };


struct D21eTeamPreset : D21eTeam {
    int value68 __attribute__((aligned(__alignof__(D21eTeam))));                   // +68, starts as 0
    int value72;                   // +72, starts as 0
    D21eTeamPreset(unsigned short id);
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN14D21eTeamPreset7releaseEv"));
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN14D21eTeamPreset4typeEv"));
 __attribute__((always_inline)) inline unsigned short release() { return this->D21eTeam::release(); }  __attribute__((always_inline)) inline Ptr32<void> type() { return this->D21eTeam::type(); } };

D21eTeamPreset::D21eTeamPreset(unsigned short id)
    : D21eTeam(id), value68(0), value72(0)
{ W3D_SET_VPTR(this->D21eTeam::w3d_vptr_D21eObject, w3d_vt___vt_14D21eTeamPreset, "__vt_14D21eTeamPreset"); 
    Ptr32<D21eString> names = w3d_cc18b_array_write_80231f14(this, 6, 0, 0);
    D21eString number;
    for (int i = 0; i < 6; i++) {
        w3d_string_format(&number, w3d_text_worm_number_803b506c, i + 1);
        names[i] = number;
    }
    D21eHandle item(w3d_s10_service_forward_8020b680(w3d_service_key_80419ea8));
    w3d_auto_80231fd0(this, item.object);
}


