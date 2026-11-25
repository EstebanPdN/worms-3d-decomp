#include "w3d_ptr.h"
#line 1 "d24a_commentary_death_800455bc.cpp"
/* Worm death commentary (0x800455bc): counts the call in +256; when the
 * commentary is enabled (+252) takes the name (+140) of the worm's team
 * (0x800a830c, 0x800fc6dc), picks one of 39 "Comment.LandDeath.*" format strings
 * (0x800fc2b0) from a random number modulo 39 (0x8015ff5c), formats the name into
 * it (0x8020c510), plays the result (0x80043134) and notifies 0x80046228 with
 * byte +213 of the team record. Field and type names are inferred from the
 * original instructions. Strings are external views of original data; the unit
 * owns no data. */
struct StringHeader { unsigned short references; };
struct String;
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" void w3d_string_release_header_8020bb2c(Ptr32<void>);
struct String {
    Ptr32<const char> text;
    String();
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
    Ptr32<unsigned short> header() const { return (Ptr32<unsigned short>)(text - 6); }
    static void release(Ptr32<unsigned short> h) { if (--*h == 0) w3d_string_release_header_8020bb2c(h); }
    String &operator=(const String &x) {
        ++*x.header();
        release(header());
        text = x.text;
        return *this;
    }
};
struct PropertyKey { Ptr32<const char> name; };
struct TeamRecord {
    char unknown00[140];
    String name;               /* +140 */
    char unknown144[69];
    unsigned char index;       /* +213 */
};
struct Commentary {
    char unknown00[252];
    int enabled;               /* +252 */
    int calls;                 /* +256 */
};
struct Worm;
extern "C" int w3d_worm_team_800a830c(Ptr32<Worm>);
extern "C" Ptr32<TeamRecord> w3d_team_record_800fc6dc(int);
extern "C" unsigned w3d_random_8015ff5c(Ptr32<Commentary>);
extern "C" int w3d_string_property_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" void w3d_string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_commentary_play_80043134(Ptr32<Commentary>, String, int);
extern "C" void w3d_commentary_notify_80046228(Ptr32<Commentary>, unsigned char);
extern "C" char w3d_string_80375424[];
extern "C" char w3d_string_80375438[];
extern "C" char w3d_string_8037544c[];
extern "C" char w3d_string_80375460[];
extern "C" char w3d_string_80375474[];
extern "C" char w3d_string_80375488[];
extern "C" char w3d_string_8037549c[];
extern "C" char w3d_string_803754b0[];
extern "C" char w3d_string_803754c4[];
extern "C" char w3d_string_803754d8[];
extern "C" char w3d_string_803754f0[];
extern "C" char w3d_string_80375508[];
extern "C" char w3d_string_80375520[];
extern "C" char w3d_string_80375538[];
extern "C" char w3d_string_80375550[];
extern "C" char w3d_string_80375568[];
extern "C" char w3d_string_80375580[];
extern "C" char w3d_string_80375598[];
extern "C" char w3d_string_803755b0[];
extern "C" char w3d_string_803755c8[];
extern "C" char w3d_string_803755e0[];
extern "C" char w3d_string_803755f8[];
extern "C" char w3d_string_80375610[];
extern "C" char w3d_string_80375628[];
extern "C" char w3d_string_80375640[];
extern "C" char w3d_string_80375658[];
extern "C" char w3d_string_80375670[];
extern "C" char w3d_string_80375688[];
extern "C" char w3d_string_803756a0[];
extern "C" char w3d_string_803756b8[];
extern "C" char w3d_string_803756d0[];
extern "C" char w3d_string_803756e8[];
extern "C" char w3d_string_80375700[];
extern "C" char w3d_string_80375718[];
extern "C" char w3d_string_80375730[];
extern "C" char w3d_string_80375748[];
extern "C" char w3d_string_80375760[];
extern "C" char w3d_string_80375778[];
extern "C" char w3d_string_80375790[];

extern "C" void w3d_d24a_commentary_death_800455bc(Ptr32<Commentary> self, Ptr32<Worm> worm)
{
    self->calls++;
    if (self->enabled) {
        String name;
        Ptr32<TeamRecord> team = w3d_team_record_800fc6dc(w3d_worm_team_800a830c(worm));
        name = team->name;
        Ptr32<const char> format;
        int pick = w3d_random_8015ff5c(self) % 39;
        switch (pick) {
        case 0: {
            PropertyKey key;
            key.name = w3d_string_80375424;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 1: {
            PropertyKey key;
            key.name = w3d_string_80375438;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 2: {
            PropertyKey key;
            key.name = w3d_string_8037544c;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 3: {
            PropertyKey key;
            key.name = w3d_string_80375460;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 4: {
            PropertyKey key;
            key.name = w3d_string_80375474;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 5: {
            PropertyKey key;
            key.name = w3d_string_80375488;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 6: {
            PropertyKey key;
            key.name = w3d_string_8037549c;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 7: {
            PropertyKey key;
            key.name = w3d_string_803754b0;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 8: {
            PropertyKey key;
            key.name = w3d_string_803754c4;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 9: {
            PropertyKey key;
            key.name = w3d_string_803754d8;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 10: {
            PropertyKey key;
            key.name = w3d_string_803754f0;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 11: {
            PropertyKey key;
            key.name = w3d_string_80375508;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 12: {
            PropertyKey key;
            key.name = w3d_string_80375520;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 13: {
            PropertyKey key;
            key.name = w3d_string_80375538;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 14: {
            PropertyKey key;
            key.name = w3d_string_80375550;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 15: {
            PropertyKey key;
            key.name = w3d_string_80375568;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 16: {
            PropertyKey key;
            key.name = w3d_string_80375580;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 17: {
            PropertyKey key;
            key.name = w3d_string_80375598;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 18: {
            PropertyKey key;
            key.name = w3d_string_803755b0;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 19: {
            PropertyKey key;
            key.name = w3d_string_803755c8;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 20: {
            PropertyKey key;
            key.name = w3d_string_803755e0;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 21: {
            PropertyKey key;
            key.name = w3d_string_803755f8;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 22: {
            PropertyKey key;
            key.name = w3d_string_80375610;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 23: {
            PropertyKey key;
            key.name = w3d_string_80375628;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 24: {
            PropertyKey key;
            key.name = w3d_string_80375640;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 25: {
            PropertyKey key;
            key.name = w3d_string_80375658;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 26: {
            PropertyKey key;
            key.name = w3d_string_80375670;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 27: {
            PropertyKey key;
            key.name = w3d_string_80375688;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 28: {
            PropertyKey key;
            key.name = w3d_string_803756a0;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 29: {
            PropertyKey key;
            key.name = w3d_string_803756b8;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 30: {
            PropertyKey key;
            key.name = w3d_string_803756d0;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 31: {
            PropertyKey key;
            key.name = w3d_string_803756e8;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 32: {
            PropertyKey key;
            key.name = w3d_string_80375700;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 33: {
            PropertyKey key;
            key.name = w3d_string_80375718;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 34: {
            PropertyKey key;
            key.name = w3d_string_80375730;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 35: {
            PropertyKey key;
            key.name = w3d_string_80375748;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 36: {
            PropertyKey key;
            key.name = w3d_string_80375760;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 37: {
            PropertyKey key;
            key.name = w3d_string_80375778;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        case 38: {
            PropertyKey key;
            key.name = w3d_string_80375790;
            w3d_string_property_800fc2b0(&key, &format);
            break;
        }
        }
        String text;
        w3d_string_format_8020c510(&text, format, w3d::VA(name.text));
        w3d_commentary_play_80043134(self, text, 0);
        w3d_commentary_notify_80046228(self, w3d_team_record_800fc6dc(w3d_worm_team_800a830c(worm))->index);
    }
}


