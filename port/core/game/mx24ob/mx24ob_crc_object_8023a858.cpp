#include "w3d_ptr.h"
#line 1 "mx24ob_crc_object_8023a858.cpp"
// Constructor at 0x8023a858 for a tagged object whose body prepares the
// CRC-32 table (0x8021d70c, polynomial 0x04c11db7). Class and member names
// are structural; offsets are observed from the original instructions. Every
// type here has a name unique to this unit.

extern "C" {
void w3d_string_base_init(Ptr32<void> string);
Ptr32<unsigned short> w3d_string_header(Ptr32<void> string);
}

// Polymorphic reference-counted root. Table slot +8 is 0x801ea0a4 (it
// forwards two arguments to a query; their meaning is unknown), +12 retains,
// +16 releases and +20 returns a per-class address (read as a type
// descriptor). Slots are declared, not defined, so tables stay external.
struct Mx24obCrcRoot {
    int w3d_r_query(Ptr32<void> first, Ptr32<void> second) __asm__(W3D_SYM("_ZN13Mx24obCrcRoot5queryEPvS0_"));
    unsigned short w3d_r_retain() __asm__(W3D_SYM("_ZN13Mx24obCrcRoot6retainEv"));
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN13Mx24obCrcRoot7releaseEv"));
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN13Mx24obCrcRoot4typeEv"));
 __attribute__((always_inline)) inline int query(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Mx24obCrcRoot, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline unsigned short retain() { return ((unsigned short (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx24obCrcRoot, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned short release() { return ((unsigned short (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx24obCrcRoot, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<void> type() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mx24obCrcRoot, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Mx24obCrcRoot; };

// The tagged base is constructed out of line by 0x801ea0ec with the caller's
// 16-bit id; its 16 bytes after the table pointer are not described here.
struct Mx24obCrcTagged : Mx24obCrcRoot {
    unsigned char unknown[16] __attribute__((aligned(__alignof__(Mx24obCrcRoot))));     // +4..+19, initialized by 0x801ea0ec
    Mx24obCrcTagged(unsigned short id);
};

// Four-byte shared engine string; copying retains the shared text through the
// 16-bit reference count returned by 0x80341884.
struct Mx24obCrcString {
    Ptr32<char> text;
    Mx24obCrcString(const Mx24obCrcString &other)
    {
        w3d_string_base_init(this);
        text = other.text;
        ++*w3d_string_header(this);
    }
};

extern Mx24obCrcString w3d_empty_string_804b06a0[];   // shared empty string

// 24-byte member object constructed out of line by 0x80207fec (it installs
// the tables 0x80419268 then 0x80419238); its fields are not described here.
struct Mx24obCrcNode {
    unsigned char unknown[24];
    Mx24obCrcNode();
};

struct Mx24obCrcObject;
// Out-of-line accessors of the int at +72 (0x80240770 reads it, 0x80240768
// writes it) and the setter 0x80240824 (its field is not observed here).
extern "C" int w3d_props_get_i32_80240770(Ptr32<Mx24obCrcObject> self);
extern "C" void w3d_props_set_i32_80240768(Ptr32<Mx24obCrcObject> self, int value);
extern "C" void w3d_props_set_i32_80240824(Ptr32<Mx24obCrcObject> self, int value);
extern "C" void w3d_cx12b_crc_table_initialize_8021d70c(Ptr32<Mx24obCrcObject> self);

// At least 100 bytes; table 0x8041ae50.
struct Mx24obCrcObject : Mx24obCrcTagged {
    int value20 __attribute__((aligned(__alignof__(Mx24obCrcTagged))));                   // +20..+64, start as 0
    int value24;
    int value28;
    int value32;
    int value36;
    int value40;
    int value44;
    int value48;
    int value52;
    int value56;
    int value60;
    int value64;
    Mx24obCrcString text68;        // +68, starts as the shared empty string
    int value72;                   // +72, starts as 0
    Mx24obCrcNode node76;          // +76
    Mx24obCrcObject(unsigned short id);
    unsigned short w3d_r_release() __asm__(W3D_SYM("_ZN15Mx24obCrcObject7releaseEv"));      // table slot +16: 0x8023ec60
    Ptr32<void> w3d_r_type() __asm__(W3D_SYM("_ZN15Mx24obCrcObject4typeEv"));                  // table slot +20: 0x8023a7a0
 __attribute__((always_inline)) inline unsigned short release() { return this->Mx24obCrcTagged::release(); }  __attribute__((always_inline)) inline Ptr32<void> type() { return this->Mx24obCrcTagged::type(); } };

Mx24obCrcObject::Mx24obCrcObject(unsigned short id)
    : Mx24obCrcTagged(id),
      value20(0),
      value24(0),
      value28(0),
      value32(0),
      value36(0),
      value40(0),
      value44(0),
      value48(0),
      value52(0),
      value56(0),
      value60(0),
      value64(0),
      text68(w3d_empty_string_804b06a0[0]),
      value72(0)
{ W3D_SET_VPTR(this->Mx24obCrcTagged::w3d_vptr_Mx24obCrcRoot, w3d_vt___vt_15Mx24obCrcObject, "__vt_15Mx24obCrcObject"); 
    if (w3d_props_get_i32_80240770(this) == 0)
        w3d_cx12b_crc_table_initialize_8021d70c(this);
    w3d_props_set_i32_80240768(this, 1);
    w3d_props_set_i32_80240824(this, 4096);
}


