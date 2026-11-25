#include "w3d_ptr.h"
#line 1 "d24a_commentary_kills_800468dc.cpp"
/* Kill commentary (0x800468dc): takes and clears the kill counter (+256); when
 * the commentary is enabled (+252), the counter is not zero and the active worm
 * index (+128, 0x803426b4, 0x80178c48) is a valid player, discounts one kill if
 * word +220 of that player's record is 0, then picks a "Comment.<n>Kill.*"
 * string (0x800fc2b0) from a random number (0x8015ff5c) by the number of kills.
 * A string containing "%s" (0x80374f74) is formatted with the record's
 * name (0x8020c510) before being played (0x80043134). Field and type names are
 * inferred from the original instructions. Strings are external views of
 * original data; the unit owns no data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<const char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct PropertyKey { Ptr32<const char> name; };
struct Object;
struct PlayerRecord {
    char unknown00[140];
    Ptr32<const char> name;          /* +140 */
    char unknown144[76];
    int unknown220;            /* +220 */
};
struct Commentary {
    char unknown00[128];
    Ptr32<Object> activeWormIndex;   /* +128 */
    char unknown132[120];
    int enabled;               /* +252 */
    int kills;                 /* +256 */
};
extern "C" Ptr32<Object> w3d_identity_803426b4(Ptr32<Object>);
extern "C" unsigned w3d_object_int_80178c48(Ptr32<Object>);
extern "C" Ptr32<PlayerRecord> w3d_player_record_800fc6dc(unsigned);
extern "C" unsigned w3d_random_8015ff5c(Ptr32<Commentary>);
extern "C" int w3d_string_property_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>);
extern "C" void w3d_string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_commentary_play_80043134(Ptr32<Commentary>, String, int);
extern "C" char w3d_string_80374f74[];
extern "C" char w3d_string_80375be8[];
extern "C" char w3d_string_80375bf8[];
extern "C" char w3d_string_80375c08[];
extern "C" char w3d_string_80375c18[];
extern "C" char w3d_string_80375c28[];
extern "C" char w3d_string_80375c38[];
extern "C" char w3d_string_80375c48[];
extern "C" char w3d_string_80375c58[];
extern "C" char w3d_string_80375c68[];
extern "C" char w3d_string_80375c78[];
extern "C" char w3d_string_80375c88[];
extern "C" char w3d_string_80375c98[];
extern "C" char w3d_string_80375ca8[];
extern "C" char w3d_string_80375cb8[];
extern "C" char w3d_string_80375cc8[];
extern "C" char w3d_string_80375cd8[];
extern "C" char w3d_string_80375ce8[];
extern "C" char w3d_string_80375cf8[];
extern "C" char w3d_string_80375d08[];
extern "C" char w3d_string_80375d18[];
extern "C" char w3d_string_80375d28[];
extern "C" char w3d_string_80375d38[];
extern "C" char w3d_string_80375d48[];
extern "C" char w3d_string_80375d58[];
extern "C" char w3d_string_80375d68[];
extern "C" char w3d_string_80375d78[];
extern "C" char w3d_string_80375d88[];
extern "C" char w3d_string_80375d98[];
extern "C" char w3d_string_80375dac[];
extern "C" char w3d_string_80375dc0[];
extern "C" char w3d_string_80375dd0[];
extern "C" char w3d_string_80375de0[];
extern "C" char w3d_string_80375df0[];
extern "C" char w3d_string_80375e00[];
extern "C" char w3d_string_80375e10[];
extern "C" char w3d_string_80375e20[];
extern "C" char w3d_string_80375e30[];
extern "C" char w3d_string_80375e40[];
extern "C" char w3d_string_80375e50[];
extern "C" char w3d_string_80375e60[];
extern "C" char w3d_string_80375e70[];
extern "C" char w3d_string_80375e80[];
extern "C" char w3d_string_80375e90[];
extern "C" char w3d_string_80375ea0[];
extern "C" char w3d_string_80375eb0[];
extern "C" char w3d_string_80375ec0[];
extern "C" char w3d_string_80375ed0[];
extern "C" char w3d_string_80375ee0[];
extern "C" char w3d_string_80375ef0[];
extern "C" char w3d_string_80375f00[];
extern "C" char w3d_string_80375f10[];
extern "C" char w3d_string_80375f20[];
extern "C" char w3d_string_80375f30[];
extern "C" char w3d_string_80375f40[];
extern "C" char w3d_string_80375f50[];
extern "C" char w3d_string_80375f60[];
extern "C" char w3d_string_80375f70[];
extern "C" char w3d_string_80375f80[];
extern "C" char w3d_string_80375f90[];
extern "C" char w3d_string_80375fa0[];
extern "C" char w3d_string_80375fb0[];
extern "C" char w3d_string_80375fc0[];
extern "C" char w3d_string_80375fd0[];
extern "C" char w3d_string_80375fe0[];
extern "C" char w3d_string_80375ff0[];
extern "C" char w3d_string_80376000[];
extern "C" char w3d_string_80376010[];
extern "C" char w3d_string_80376020[];
extern "C" char w3d_string_80376030[];
extern "C" char w3d_string_80376040[];
extern "C" char w3d_string_80376050[];
extern "C" char w3d_string_80376060[];
extern "C" char w3d_string_80376070[];
extern "C" char w3d_string_80376080[];
extern "C" char w3d_string_80376090[];
extern "C" char w3d_string_803760a0[];
extern "C" char w3d_string_803760b0[];
extern "C" char w3d_string_803760c4[];
extern "C" char w3d_string_803760d8[];
extern "C" char w3d_string_803760ec[];
extern "C" char w3d_string_80376100[];
extern "C" char w3d_string_80376114[];
extern "C" char w3d_string_80376128[];
extern "C" char w3d_string_8037613c[];
extern "C" char w3d_string_80376150[];
extern "C" char w3d_string_80376164[];
extern "C" char w3d_string_80376178[];
extern "C" char w3d_string_8037618c[];
extern "C" char w3d_string_803761a0[];
extern "C" char w3d_string_803761b4[];
extern "C" char w3d_string_803761c8[];
extern "C" char w3d_string_803761dc[];
extern "C" char w3d_string_803761f0[];
extern "C" char w3d_string_80376204[];
extern "C" char w3d_string_80376218[];
extern "C" char w3d_string_8037622c[];
extern "C" char w3d_string_80376240[];
extern "C" char w3d_string_80376254[];
extern "C" char w3d_string_80376268[];
extern "C" char w3d_string_8037627c[];
extern "C" char w3d_string_80376290[];
extern "C" char w3d_string_803762a4[];
extern "C" char w3d_string_803762b8[];

extern "C" void w3d_d24a_commentary_kills_800468dc(Ptr32<Commentary> self)
{
    int enabled = self->enabled;
    int kills = self->kills;
    self->kills = 0;
    if (enabled && kills) {
        unsigned index = w3d_object_int_80178c48(w3d_identity_803426b4(self->activeWormIndex));
        if (index <= 15) {
            Ptr32<PlayerRecord> record = w3d_player_record_800fc6dc(index);
            if (record->unknown220 == 0) kills--;
            if (kills > 0) {
                Ptr32<const char> text = 0;
                switch (kills) {
        case 1:
            switch (w3d_random_8015ff5c(self) % 18) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375be8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375bf8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375c08;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375c18;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375c28;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80375c38;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 6: {
                PropertyKey key;
                key.name = w3d_string_80375c48;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 7: {
                PropertyKey key;
                key.name = w3d_string_80375c58;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 8: {
                PropertyKey key;
                key.name = w3d_string_80375c68;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 9: {
                PropertyKey key;
                key.name = w3d_string_80375c78;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 10: {
                PropertyKey key;
                key.name = w3d_string_80375c88;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 11: {
                PropertyKey key;
                key.name = w3d_string_80375c98;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 12: {
                PropertyKey key;
                key.name = w3d_string_80375ca8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 13: {
                PropertyKey key;
                key.name = w3d_string_80375cb8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 14: {
                PropertyKey key;
                key.name = w3d_string_80375cc8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 15: {
                PropertyKey key;
                key.name = w3d_string_80375cd8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 16: {
                PropertyKey key;
                key.name = w3d_string_80375ce8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 17: {
                PropertyKey key;
                key.name = w3d_string_80375cf8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 2:
            switch (w3d_random_8015ff5c(self) % 11) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375d08;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375d18;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375d28;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375d38;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375d48;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80375d58;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 6: {
                PropertyKey key;
                key.name = w3d_string_80375d68;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 7: {
                PropertyKey key;
                key.name = w3d_string_80375d78;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 8: {
                PropertyKey key;
                key.name = w3d_string_80375d88;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 9: {
                PropertyKey key;
                key.name = w3d_string_80375d98;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 10: {
                PropertyKey key;
                key.name = w3d_string_80375dac;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 3:
            switch (w3d_random_8015ff5c(self) % 9) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375dc0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375dd0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375de0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375df0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375e00;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80375e10;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 6: {
                PropertyKey key;
                key.name = w3d_string_80375e20;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 7: {
                PropertyKey key;
                key.name = w3d_string_80375e30;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 8: {
                PropertyKey key;
                key.name = w3d_string_80375e40;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 4:
            switch (w3d_random_8015ff5c(self) % 5) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375e50;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375e60;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375e70;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375e80;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375e90;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 5:
            switch (w3d_random_8015ff5c(self) % 6) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375ea0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375eb0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375ec0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375ed0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375ee0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80375ef0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 6:
            switch (w3d_random_8015ff5c(self) % 8) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375f00;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375f10;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375f20;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375f30;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375f40;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80375f50;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 6: {
                PropertyKey key;
                key.name = w3d_string_80375f60;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 7: {
                PropertyKey key;
                key.name = w3d_string_80375f70;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 7:
            switch (w3d_random_8015ff5c(self) % 5) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375f80;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375f90;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375fa0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80375fb0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80375fc0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 8:
            switch (w3d_random_8015ff5c(self) % 6) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80375fd0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80375fe0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80375ff0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80376000;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80376010;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80376020;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 9:
            switch (w3d_random_8015ff5c(self) % 8) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80376030;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80376040;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80376050;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80376060;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80376070;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80376080;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 6: {
                PropertyKey key;
                key.name = w3d_string_80376090;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 7: {
                PropertyKey key;
                key.name = w3d_string_803760a0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 10:
            switch (w3d_random_8015ff5c(self) % 4) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_803760b0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_803760c4;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_803760d8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_803760ec;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 11:
            switch (w3d_random_8015ff5c(self) % 6) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80376100;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80376114;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80376128;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_8037613c;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80376150;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 5: {
                PropertyKey key;
                key.name = w3d_string_80376164;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 12:
            switch (w3d_random_8015ff5c(self) % 4) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80376178;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_8037618c;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_803761a0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_803761b4;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 13:
            switch (w3d_random_8015ff5c(self) % 3) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_803761c8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_803761dc;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_803761f0;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 14:
            switch (w3d_random_8015ff5c(self) % 5) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80376204;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_80376218;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_8037622c;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_80376240;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_80376254;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
        case 15:
            switch (w3d_random_8015ff5c(self) % 5) {
            case 0: {
                PropertyKey key;
                key.name = w3d_string_80376268;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 1: {
                PropertyKey key;
                key.name = w3d_string_8037627c;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 2: {
                PropertyKey key;
                key.name = w3d_string_80376290;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 3: {
                PropertyKey key;
                key.name = w3d_string_803762a4;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            case 4: {
                PropertyKey key;
                key.name = w3d_string_803762b8;
                w3d_string_property_800fc2b0(&key, &text);
                break;
            }
            }
            break;
                }
                if (strstr(text, w3d_string_80374f74)) {
                    String formatted;
                    w3d_string_format_8020c510(&formatted, text, w3d::VA(record->name));
                    w3d_commentary_play_80043134(self, formatted, 0);
                } else {
                    w3d_commentary_play_80043134(self, String(text), 0);
                }
            }
        }
    }
}


