#include "w3d_ptr.h"
#line 1 "mx24ob_team_setup_80227398.cpp"
// Constructor at 0x80227398 for a reference-counted settings object that
// holds a "TeamName"/"Classic" record and six "Worm %d" names. Class and
// member names are structural; the team reading comes from the texts only.
// Offsets are observed from the original instructions. Every type here has a
// name unique to this unit.

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
struct Mx24obObject {
    int w3d_r_query(Ptr32<void> first, Ptr32<void> second) __asm__(W3D_SYM("_ZN12Mx24obObject5queryEPvS0_"));
    unsigned short w3d_r_retain() __asm__(W3D_SYM("_ZN12Mx24obObject6retainEv"));
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN12Mx24obObject7releaseEv"));
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN12Mx24obObject4typeEv"));
 __attribute__((always_inline)) inline int query(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Mx24obObject, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline unsigned short retain() { return ((unsigned short (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx24obObject, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned short release() { return ((unsigned short (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx24obObject, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<void> type() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx24obObject, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Mx24obObject; };

// The tagged base is constructed out of line by 0x801ea0ec with the caller's
// 16-bit id; its 16 bytes after the table pointer are not described here.
struct Mx24obTagged : Mx24obObject {
    unsigned char unknown[16] __attribute__((aligned(__alignof__(Mx24obObject))));     // +4..+19, initialized by 0x801ea0ec
    Mx24obTagged(unsigned short id);
};

// Four-byte shared engine string: a pointer to text whose 16-bit reference
// count sits 6 bytes before it. The default constructor is the out-of-line
// 0x803426b8; construction from C text goes through 0x8020bb54. The copy
// constructor makes the type addressable, so locals of it take an 8-byte
// aligned stack slot as in the original frame.
struct Mx24obString {
    Ptr32<char> text;
    Mx24obString();
    template <class W3dU> Mx24obString(Ptr32<W3dU> w3d_p) : Mx24obString((const char *)w3d_p.get()) {}
 Mx24obString(const char *source) { w3d_string_from_text(this, source); }
    Mx24obString(const Mx24obString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
    ~Mx24obString() { w3d_string_base_finish(this); w3d_string_release(this); }
    Mx24obString &operator=(const Mx24obString &other)
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
struct Mx24obHandle {
    Ptr32<Mx24obObject> object;
    template <class W3dU> Mx24obHandle(Ptr32<W3dU> w3d_p) : Mx24obHandle((Mx24obObject *)w3d_p.get()) {}
 Mx24obHandle(Mx24obObject *p) : object(p) { if (p) p->retain(); }
    Mx24obHandle(const Mx24obHandle &other) : object(other.object) { if (object) object->retain(); }
    ~Mx24obHandle() { if (object) object->release(); }
};

// Shared empty array stores (small data) that new arrays start from.
extern Ptr32<Mx24obObject> w3d_default_store_804b05ac;
extern Ptr32<Mx24obObject> w3d_default_store_804b05b0;
// "Worm %d", pooled with another unit's texts (0x803b506c); referenced, not owned.
extern const char w3d_text_worm_number_803b506c[];
// Argument of the service lookup 0x8020b680 (meaning unknown).
extern char w3d_service_key_80419ea8[];

struct Mx24obTeam;
// Writable access to the string array at +56 (0x80231f14), and append to the
// object array at +52 (0x80231fd0).
extern "C" Ptr32<Mx24obString> w3d_cc18b_array_write_80231f14(Ptr32<Mx24obTeam> owner, unsigned int count, unsigned int flags, Ptr32<unsigned int> previous);
extern "C" void w3d_auto_80231fd0(Ptr32<Mx24obTeam> owner, Ptr32<Mx24obObject> item);
extern "C" Ptr32<Mx24obObject> w3d_s10_service_forward_8020b680(Ptr32<void> key);

// 68 bytes; table 0x8041a168.
struct Mx24obTeam : Mx24obTagged {
    Mx24obString text20 __attribute__((aligned(__alignof__(Mx24obTagged))));           // +20, starts as ""
    Mx24obString style24;          // +24, starts as "Classic"
    Mx24obString text28;           // +28, starts as "0"
    int value32;                   // +32..+48, start as 0
    int value36;
    int value40;
    int value44;
    int value48;
    Mx24obHandle items52;          // +52, object array store (from 0x804b05ac)
    Mx24obHandle names56;          // +56, string array store (from 0x804b05b0)
    Mx24obString name60;           // +60, starts as "TeamName"
    int value64;                   // +64, starts as 0
    Mx24obTeam(unsigned short id);
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN10Mx24obTeam7releaseEv"));      // table slot +16: 0x8022e970
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN10Mx24obTeam4typeEv"));                  // table slot +20: 0x802272e0
 __attribute__((always_inline)) inline unsigned short release() { return this->Mx24obTagged::release(); }  __attribute__((always_inline)) inline Ptr32<void> type() { return this->Mx24obTagged::type(); } };

Mx24obTeam::Mx24obTeam(unsigned short id)
    : Mx24obTagged(id),
      text20(""),
      style24("Classic"),
      text28("0"),
      value32(0),
      value36(0),
      value40(0),
      value44(0),
      value48(0),
      items52(w3d_default_store_804b05ac),
      names56(w3d_default_store_804b05b0),
      name60("TeamName"),
      value64(0)
{ W3D_SET_VPTR(this->Mx24obTagged::w3d_vptr_Mx24obObject, w3d_vt___vt_10Mx24obTeam, "__vt_10Mx24obTeam"); 
    Ptr32<Mx24obString> names = w3d_cc18b_array_write_80231f14(this, 6, 0, 0);
    Mx24obString number;
    for (int i = 0; i < 6; i++) {
        w3d_string_format(&number, w3d_text_worm_number_803b506c, i + 1);
        names[i] = number;
    }
    Mx24obHandle item(w3d_s10_service_forward_8020b680(w3d_service_key_80419ea8));
    w3d_auto_80231fd0(this, item.object);
}


