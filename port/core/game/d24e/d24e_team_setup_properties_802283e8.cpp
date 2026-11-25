#include "w3d_ptr.h"
#line 1 "d24e_team_setup_properties_802283e8.cpp"
// Team setup property registration (Worms 3D GameCube PAL, 0x802283e8).
//
// In call order: registers NumberOfTeams (0x801ebf38); registers AllyToStart
// (0x801ec0f8); registers AllyTeam0 (0x801ec0f8); registers AllyTeam1
// (0x801ec0f8); registers AllyTeam2 (0x801ec0f8); registers AllyTeam3
// (0x801ec0f8); sets the T1_Name string binding (0x801ed24c) to a temporary
// string made from "TeamName1" (0x803b8468, constructor 0x8020bb54); sets
// the T1_Player string binding (0x801ed24c) to a temporary string made from
// "" (0x803b8198, constructor 0x8020bb54); registers T1_NumOfWorms
// (0x801ebf38); sets the T1_W1_Name string binding (0x801ed24c) to a
// temporary string made from "T1 Worm 1" (0x803b8530, constructor
// 0x8020bb54); sets the T1_W2_Name string binding (0x801ed24c) to a
// temporary string made from "T1 Worm 2" (0x803b8450, constructor
// 0x8020bb54); sets the T1_W3_Name string binding (0x801ed24c) to a
// temporary string made from "T1 Worm 3" (0x803b8444, constructor
// 0x8020bb54); sets the T1_W4_Name string binding (0x801ed24c) to a
// temporary string made from "T1 Worm 4" (0x803b8438, constructor
// 0x8020bb54); sets the T1_W5_Name string binding (0x801ed24c) to a
// temporary string made from "T1 Worm 5" (0x803b842c, constructor
// 0x8020bb54); sets the T1_W6_Name string binding (0x801ed24c) to a
// temporary string made from "T1 Worm 6" (0x803b8420, constructor
// 0x8020bb54); registers T1_Skill (0x801ec0f8); registers T1_Grave
// (0x801ec0f8); registers T1_SWeapon (0x801ec0f8); sets the T1_Flag string
// binding (0x801ed24c) to a temporary string made from "FlagUk" (0x803b8474,
// constructor 0x8020bb54); sets the T1_Speech string binding (0x801ed24c) to
// a temporary string made from "Classic" (0x803b819c, constructor
// 0x8020bb54); registers T1_IsLocal (0x801eb674); registers T1_AlliedGroup
// (0x801ebf38); registers T1_FirstWorm (0x801ec0f8); sets the T2_Name string
// binding (0x801ed24c) to a temporary string made from "TeamName2"
// (0x803b84c4, constructor 0x8020bb54); sets the T2_Player string binding
// (0x801ed24c) to a temporary string made from "" (0x803b8198, constructor
// 0x8020bb54); registers T2_NumOfWorms (0x801ebf38); sets the T2_W1_Name
// string binding (0x801ed24c) to a temporary string made from "T2 Worm 1"
// (0x803b84b8, constructor 0x8020bb54); sets the T2_W2_Name string binding
// (0x801ed24c) to a temporary string made from "T2 Worm 2" (0x803b84ac,
// constructor 0x8020bb54); sets the T2_W3_Name string binding (0x801ed24c)
// to a temporary string made from "T2 Worm 3" (0x803b84d0, constructor
// 0x8020bb54); sets the T2_W4_Name string binding (0x801ed24c) to a
// temporary string made from "T2 Worm 4" (0x803b8494, constructor
// 0x8020bb54); sets the T2_W5_Name string binding (0x801ed24c) to a
// temporary string made from "T2 Worm 5" (0x803b8488, constructor
// 0x8020bb54); sets the T2_W6_Name string binding (0x801ed24c) to a
// temporary string made from "T2 Worm 6" (0x803b847c, constructor
// 0x8020bb54); registers T2_Skill (0x801ec0f8); registers T2_Grave
// (0x801ec0f8); registers T2_SWeapon (0x801ec0f8); sets the T2_Flag string
// binding (0x801ed24c) to a temporary string made from "FlagUk" (0x803b8474,
// constructor 0x8020bb54); sets the T2_Speech string binding (0x801ed24c) to
// a temporary string made from "Classic" (0x803b819c, constructor
// 0x8020bb54); registers T2_IsLocal (0x801eb674); registers T2_AlliedGroup
// (0x801ebf38); registers T2_FirstWorm (0x801ec0f8); sets the T3_Name string
// binding (0x801ed24c) to a temporary string made from "TeamName3"
// (0x803b8518, constructor 0x8020bb54); sets the T3_Player string binding
// (0x801ed24c) to a temporary string made from "" (0x803b8198, constructor
// 0x8020bb54); registers T3_NumOfWorms (0x801ebf38); sets the T3_W1_Name
// string binding (0x801ed24c) to a temporary string made from "T3 Worm 1"
// (0x803b850c, constructor 0x8020bb54); sets the T3_W2_Name string binding
// (0x801ed24c) to a temporary string made from "T3 Worm 2" (0x803b8500,
// constructor 0x8020bb54); sets the T3_W3_Name string binding (0x801ed24c)
// to a temporary string made from "T3 Worm 3" (0x803b84f4, constructor
// 0x8020bb54); sets the T3_W4_Name string binding (0x801ed24c) to a
// temporary string made from "T3 Worm 4" (0x803b84a0, constructor
// 0x8020bb54); sets the T3_W5_Name string binding (0x801ed24c) to a
// temporary string made from "T3 Worm 5" (0x803b84e8, constructor
// 0x8020bb54); sets the T3_W6_Name string binding (0x801ed24c) to a
// temporary string made from "T3 Worm 6" (0x803b84dc, constructor
// 0x8020bb54); registers T3_Skill (0x801ec0f8); registers T3_Grave
// (0x801ec0f8); registers T3_SWeapon (0x801ec0f8); sets the T3_Flag string
// binding (0x801ed24c) to a temporary string made from "FlagUk" (0x803b8474,
// constructor 0x8020bb54); sets the T3_Speech string binding (0x801ed24c) to
// a temporary string made from "Classic" (0x803b819c, constructor
// 0x8020bb54); registers T3_IsLocal (0x801eb674); registers T3_AlliedGroup
// (0x801ebf38); registers T3_FirstWorm (0x801ec0f8); sets the T4_Name string
// binding (0x801ed24c) to a temporary string made from "TeamName4"
// (0x803b856c, constructor 0x8020bb54); sets the T4_Player string binding
// (0x801ed24c) to a temporary string made from "" (0x803b8198, constructor
// 0x8020bb54); registers T4_NumOfWorms (0x801ebf38); sets the T4_W1_Name
// string binding (0x801ed24c) to a temporary string made from "T4 Worm 1"
// (0x803b8560, constructor 0x8020bb54); sets the T4_W2_Name string binding
// (0x801ed24c) to a temporary string made from "T4 Worm 2" (0x803b8554,
// constructor 0x8020bb54); sets the T4_W3_Name string binding (0x801ed24c)
// to a temporary string made from "T4 Worm 3" (0x803b8548, constructor
// 0x8020bb54); sets the T4_W4_Name string binding (0x801ed24c) to a
// temporary string made from "T4 Worm 4" (0x803b853c, constructor
// 0x8020bb54); sets the T4_W5_Name string binding (0x801ed24c) to a
// temporary string made from "T4 Worm 5" (0x803b845c, constructor
// 0x8020bb54); sets the T4_W6_Name string binding (0x801ed24c) to a
// temporary string made from "T4 Worm 6" (0x803b8524, constructor
// 0x8020bb54); registers T4_Skill (0x801ec0f8); registers T4_Grave
// (0x801ec0f8); registers T4_SWeapon (0x801ec0f8); sets the T4_Flag string
// binding (0x801ed24c) to a temporary string made from "FlagUk" (0x803b8474,
// constructor 0x8020bb54); sets the T4_Speech string binding (0x801ed24c) to
// a temporary string made from "Classic" (0x803b819c, constructor
// 0x8020bb54); registers T4_IsLocal (0x801eb674); registers T4_AlliedGroup
// (0x801ebf38); registers T4_FirstWorm (0x801ec0f8); then calls the refresh
// routine 0x801e8d9c and returns 0. Names are read from the descriptors'
// name pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. T1 to T4 team records with per-worm
// names.  No saved FPR, no extra compiler options.
extern "C" Ptr32<void> memset(...);
struct String_8020bb54;
extern "C" void d20e_string_init_8020c5c0(Ptr32<String_8020bb54>);
extern "C" Ptr32<unsigned short> d20e_string_header_80341884(Ptr32<String_8020bb54>);
extern "C" void d20e_string_finish_8020c5c4(Ptr32<String_8020bb54>);
extern "C" void d20e_string_release_80341588(Ptr32<String_8020bb54>);
extern "C" void d20e_release_header_8020bb2c(Ptr32<unsigned short>);

struct String_8020bb54 {
    Ptr32<char> text;

    // Copy constructor: initializes the shared string and takes a
    // reference on the source text (16-bit header counter).
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);

    String_8020bb54(const String_8020bb54 &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }

    ~String_8020bb54() {
        d20e_string_finish_8020c5c4(this);
        d20e_string_release_80341588(this);
    }

    String_8020bb54 &operator=(const String_8020bb54 &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            d20e_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }

    // Takes its value by copy, so the temporary is built at the call.
    void set(String_8020bb54 v) { *this = v; }
};

struct StringBinding {
    unsigned header[2];
    String_8020bb54 value;
};

extern String_8020bb54 d20e_empty_804b06a0[];
struct Vec3 { float x, y, z; };
struct VectorBinding {
    unsigned header[2];
    Vec3 value;
    void set(const Vec3 &v) { value = v; }
};
struct Vec2 { float x, y; };
struct Vec2Binding {
    unsigned header[2];
    Vec2 value;
    void set(const Vec2 &v) { value = v; }
};
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
};
struct ColourBinding {
    unsigned header[2];
    Colour value;
};
struct PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> typeObject;
    Ptr32<const void> member;
    int unknown16;
    void clear() { memset(w3d::VA(this), 0, sizeof(*this)); }
};
extern "C" {
Ptr32<StringBinding> fn_801ed24c(Ptr32<void>, Ptr32<const void>);
Ptr32<VectorBinding> fn_801f0210(Ptr32<void>, Ptr32<const void>);
Ptr32<Vec2Binding> fn_801f00f0(Ptr32<void>, Ptr32<const void>);
Ptr32<ColourBinding> fn_801f15e0(Ptr32<void>, Ptr32<const void>);
void fn_801eb834(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<const void>);
void fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801ec0f8(Ptr32<void>, Ptr32<const void>);
extern const unsigned char desc_803b8588[];  // NumberOfTeams
extern const unsigned char desc_803b85bc[];  // AllyToStart
extern const unsigned char desc_803b85f0[];  // AllyTeam0
extern const unsigned char desc_803b8624[];  // AllyTeam1
extern const unsigned char desc_803b8658[];  // AllyTeam2
extern const unsigned char desc_803b868c[];  // AllyTeam3
extern const unsigned char desc_803b86bc[];  // T1_Name
extern const unsigned char desc_803b86ec[];  // T1_Player
extern const unsigned char desc_803b8720[];  // T1_NumOfWorms
extern const unsigned char desc_803b8754[];  // T1_W1_Name
extern const unsigned char desc_803b8784[];  // T1_W2_Name
extern const unsigned char desc_803b87b4[];  // T1_W3_Name
extern const unsigned char desc_803b87e4[];  // T1_W4_Name
extern const unsigned char desc_803b8814[];  // T1_W5_Name
extern const unsigned char desc_803b8844[];  // T1_W6_Name
extern const unsigned char desc_803b8874[];  // T1_Skill
extern const unsigned char desc_803b88a8[];  // T1_Grave
extern const unsigned char desc_803b88dc[];  // T1_SWeapon
extern const unsigned char desc_803b890c[];  // T1_Flag
extern const unsigned char desc_803b893c[];  // T1_Speech
extern const unsigned char desc_803b896c[];  // T1_IsLocal
extern const unsigned char desc_803b89a4[];  // T1_AlliedGroup
extern const unsigned char desc_803b89dc[];  // T1_FirstWorm
extern const unsigned char desc_803b8a0c[];  // T2_Name
extern const unsigned char desc_803b8a3c[];  // T2_Player
extern const unsigned char desc_803b8a70[];  // T2_NumOfWorms
extern const unsigned char desc_803b8aa4[];  // T2_W1_Name
extern const unsigned char desc_803b8ad4[];  // T2_W2_Name
extern const unsigned char desc_803b8b04[];  // T2_W3_Name
extern const unsigned char desc_803b8b34[];  // T2_W4_Name
extern const unsigned char desc_803b8b64[];  // T2_W5_Name
extern const unsigned char desc_803b8b94[];  // T2_W6_Name
extern const unsigned char desc_803b8bc4[];  // T2_Skill
extern const unsigned char desc_803b8bf8[];  // T2_Grave
extern const unsigned char desc_803b8c2c[];  // T2_SWeapon
extern const unsigned char desc_803b8c5c[];  // T2_Flag
extern const unsigned char desc_803b8c8c[];  // T2_Speech
extern const unsigned char desc_803b8cbc[];  // T2_IsLocal
extern const unsigned char desc_803b8cf4[];  // T2_AlliedGroup
extern const unsigned char desc_803b8d2c[];  // T2_FirstWorm
extern const unsigned char desc_803b8d5c[];  // T3_Name
extern const unsigned char desc_803b8d8c[];  // T3_Player
extern const unsigned char desc_803b8dc0[];  // T3_NumOfWorms
extern const unsigned char desc_803b8df4[];  // T3_W1_Name
extern const unsigned char desc_803b8e24[];  // T3_W2_Name
extern const unsigned char desc_803b8e54[];  // T3_W3_Name
extern const unsigned char desc_803b8e84[];  // T3_W4_Name
extern const unsigned char desc_803b8eb4[];  // T3_W5_Name
extern const unsigned char desc_803b8ee4[];  // T3_W6_Name
extern const unsigned char desc_803b8f14[];  // T3_Skill
extern const unsigned char desc_803b8f48[];  // T3_Grave
extern const unsigned char desc_803b8f7c[];  // T3_SWeapon
extern const unsigned char desc_803b8fac[];  // T3_Flag
extern const unsigned char desc_803b8fdc[];  // T3_Speech
extern const unsigned char desc_803b900c[];  // T3_IsLocal
extern const unsigned char desc_803b9044[];  // T3_AlliedGroup
extern const unsigned char desc_803b907c[];  // T3_FirstWorm
extern const unsigned char desc_803b90ac[];  // T4_Name
extern const unsigned char desc_803b90dc[];  // T4_Player
extern const unsigned char desc_803b9110[];  // T4_NumOfWorms
extern const unsigned char desc_803b9144[];  // T4_W1_Name
extern const unsigned char desc_803b9174[];  // T4_W2_Name
extern const unsigned char desc_803b91a4[];  // T4_W3_Name
extern const unsigned char desc_803b91d4[];  // T4_W4_Name
extern const unsigned char desc_803b9204[];  // T4_W5_Name
extern const unsigned char desc_803b9234[];  // T4_W6_Name
extern const unsigned char desc_803b9264[];  // T4_Skill
extern const unsigned char desc_803b9298[];  // T4_Grave
extern const unsigned char desc_803b92cc[];  // T4_SWeapon
extern const unsigned char desc_803b92fc[];  // T4_Flag
extern const unsigned char desc_803b932c[];  // T4_Speech
extern const unsigned char desc_803b935c[];  // T4_IsLocal
extern const unsigned char desc_803b9394[];  // T4_AlliedGroup
extern const unsigned char desc_803b93cc[];  // T4_FirstWorm
extern const char lit_803b8198[];  // ""
extern const char lit_803b819c[];  // "Classic"
extern const char lit_803b8420[];  // "T1 Worm 6"
extern const char lit_803b842c[];  // "T1 Worm 5"
extern const char lit_803b8438[];  // "T1 Worm 4"
extern const char lit_803b8444[];  // "T1 Worm 3"
extern const char lit_803b8450[];  // "T1 Worm 2"
extern const char lit_803b845c[];  // "T4 Worm 5"
extern const char lit_803b8468[];  // "TeamName1"
extern const char lit_803b8474[];  // "FlagUk"
extern const char lit_803b847c[];  // "T2 Worm 6"
extern const char lit_803b8488[];  // "T2 Worm 5"
extern const char lit_803b8494[];  // "T2 Worm 4"
extern const char lit_803b84a0[];  // "T3 Worm 4"
extern const char lit_803b84ac[];  // "T2 Worm 2"
extern const char lit_803b84b8[];  // "T2 Worm 1"
extern const char lit_803b84c4[];  // "TeamName2"
extern const char lit_803b84d0[];  // "T2 Worm 3"
extern const char lit_803b84dc[];  // "T3 Worm 6"
extern const char lit_803b84e8[];  // "T3 Worm 5"
extern const char lit_803b84f4[];  // "T3 Worm 3"
extern const char lit_803b8500[];  // "T3 Worm 2"
extern const char lit_803b850c[];  // "T3 Worm 1"
extern const char lit_803b8518[];  // "TeamName3"
extern const char lit_803b8524[];  // "T4 Worm 6"
extern const char lit_803b8530[];  // "T1 Worm 1"
extern const char lit_803b853c[];  // "T4 Worm 4"
extern const char lit_803b8548[];  // "T4 Worm 3"
extern const char lit_803b8554[];  // "T4 Worm 2"
extern const char lit_803b8560[];  // "T4 Worm 1"
extern const char lit_803b856c[];  // "TeamName4"
extern "C" int w3d_d24e_register_team_setup_properties_802283e8(Ptr32<void> owner) {
    fn_801ebf38(owner, desc_803b8588);
    fn_801ec0f8(owner, desc_803b85bc);
    fn_801ec0f8(owner, desc_803b85f0);
    fn_801ec0f8(owner, desc_803b8624);
    fn_801ec0f8(owner, desc_803b8658);
    fn_801ec0f8(owner, desc_803b868c);
    fn_801ed24c(owner, desc_803b86bc)->value.set(lit_803b8468);
    fn_801ed24c(owner, desc_803b86ec)->value.set(lit_803b8198);
    fn_801ebf38(owner, desc_803b8720);
    fn_801ed24c(owner, desc_803b8754)->value.set(lit_803b8530);
    fn_801ed24c(owner, desc_803b8784)->value.set(lit_803b8450);
    fn_801ed24c(owner, desc_803b87b4)->value.set(lit_803b8444);
    fn_801ed24c(owner, desc_803b87e4)->value.set(lit_803b8438);
    fn_801ed24c(owner, desc_803b8814)->value.set(lit_803b842c);
    fn_801ed24c(owner, desc_803b8844)->value.set(lit_803b8420);
    fn_801ec0f8(owner, desc_803b8874);
    fn_801ec0f8(owner, desc_803b88a8);
    fn_801ec0f8(owner, desc_803b88dc);
    fn_801ed24c(owner, desc_803b890c)->value.set(lit_803b8474);
    fn_801ed24c(owner, desc_803b893c)->value.set(lit_803b819c);
    fn_801eb674(owner, desc_803b896c);
    fn_801ebf38(owner, desc_803b89a4);
    fn_801ec0f8(owner, desc_803b89dc);
    fn_801ed24c(owner, desc_803b8a0c)->value.set(lit_803b84c4);
    fn_801ed24c(owner, desc_803b8a3c)->value.set(lit_803b8198);
    fn_801ebf38(owner, desc_803b8a70);
    fn_801ed24c(owner, desc_803b8aa4)->value.set(lit_803b84b8);
    fn_801ed24c(owner, desc_803b8ad4)->value.set(lit_803b84ac);
    fn_801ed24c(owner, desc_803b8b04)->value.set(lit_803b84d0);
    fn_801ed24c(owner, desc_803b8b34)->value.set(lit_803b8494);
    fn_801ed24c(owner, desc_803b8b64)->value.set(lit_803b8488);
    fn_801ed24c(owner, desc_803b8b94)->value.set(lit_803b847c);
    fn_801ec0f8(owner, desc_803b8bc4);
    fn_801ec0f8(owner, desc_803b8bf8);
    fn_801ec0f8(owner, desc_803b8c2c);
    fn_801ed24c(owner, desc_803b8c5c)->value.set(lit_803b8474);
    fn_801ed24c(owner, desc_803b8c8c)->value.set(lit_803b819c);
    fn_801eb674(owner, desc_803b8cbc);
    fn_801ebf38(owner, desc_803b8cf4);
    fn_801ec0f8(owner, desc_803b8d2c);
    fn_801ed24c(owner, desc_803b8d5c)->value.set(lit_803b8518);
    fn_801ed24c(owner, desc_803b8d8c)->value.set(lit_803b8198);
    fn_801ebf38(owner, desc_803b8dc0);
    fn_801ed24c(owner, desc_803b8df4)->value.set(lit_803b850c);
    fn_801ed24c(owner, desc_803b8e24)->value.set(lit_803b8500);
    fn_801ed24c(owner, desc_803b8e54)->value.set(lit_803b84f4);
    fn_801ed24c(owner, desc_803b8e84)->value.set(lit_803b84a0);
    fn_801ed24c(owner, desc_803b8eb4)->value.set(lit_803b84e8);
    fn_801ed24c(owner, desc_803b8ee4)->value.set(lit_803b84dc);
    fn_801ec0f8(owner, desc_803b8f14);
    fn_801ec0f8(owner, desc_803b8f48);
    fn_801ec0f8(owner, desc_803b8f7c);
    fn_801ed24c(owner, desc_803b8fac)->value.set(lit_803b8474);
    fn_801ed24c(owner, desc_803b8fdc)->value.set(lit_803b819c);
    fn_801eb674(owner, desc_803b900c);
    fn_801ebf38(owner, desc_803b9044);
    fn_801ec0f8(owner, desc_803b907c);
    fn_801ed24c(owner, desc_803b90ac)->value.set(lit_803b856c);
    fn_801ed24c(owner, desc_803b90dc)->value.set(lit_803b8198);
    fn_801ebf38(owner, desc_803b9110);
    fn_801ed24c(owner, desc_803b9144)->value.set(lit_803b8560);
    fn_801ed24c(owner, desc_803b9174)->value.set(lit_803b8554);
    fn_801ed24c(owner, desc_803b91a4)->value.set(lit_803b8548);
    fn_801ed24c(owner, desc_803b91d4)->value.set(lit_803b853c);
    fn_801ed24c(owner, desc_803b9204)->value.set(lit_803b845c);
    fn_801ed24c(owner, desc_803b9234)->value.set(lit_803b8524);
    fn_801ec0f8(owner, desc_803b9264);
    fn_801ec0f8(owner, desc_803b9298);
    fn_801ec0f8(owner, desc_803b92cc);
    fn_801ed24c(owner, desc_803b92fc)->value.set(lit_803b8474);
    fn_801ed24c(owner, desc_803b932c)->value.set(lit_803b819c);
    fn_801eb674(owner, desc_803b935c);
    fn_801ebf38(owner, desc_803b9394);
    fn_801ec0f8(owner, desc_803b93cc);
    fn_801e8d9c(owner);
    return 0;
}


