#include "w3d_ptr.h"
#line 1 "d24a_commentary_draw_80044410.cpp"
/* Draw commentary (0x80044410): when the commentary is enabled (+252) picks one
 * of ten "Comment.Draw.*" string properties (0x800fc2b0) from a random number
 * (0x8015ff5c, modulo 10; cases 1/2 and 4/5 use the same name) and plays it
 * (0x80043134) with a copy of the resulting string. Field and type names are
 * inferred from the original instructions. Strings are external views of
 * original data; the unit owns no data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<String>);
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<const char> text;
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
struct Commentary {
    char unknown00[252];
    int enabled;               /* +252 */
};
extern "C" unsigned w3d_random_8015ff5c(Ptr32<Commentary>);
extern "C" int w3d_string_property_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" void w3d_commentary_play_80043134(Ptr32<Commentary>, String, int);
extern "C" char w3d_string_80374eac[]; /* "Comment.Draw.1" */
extern "C" char w3d_string_80374ebc[];
extern "C" char w3d_string_80374ecc[];
extern "C" char w3d_string_80374edc[];
extern "C" char w3d_string_80374eec[];
extern "C" char w3d_string_80374efc[];
extern "C" char w3d_string_80374f0c[];
extern "C" char w3d_string_80374f1c[];

extern "C" void w3d_d24a_commentary_draw_80044410(Ptr32<Commentary> self)
{
    if (self->enabled) {
        Ptr32<const char> text;
        switch (w3d_random_8015ff5c(self) % 10) {
        case 0: {
            PropertyKey key;
            key.name = w3d_string_80374eac;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 1: {
            PropertyKey key;
            key.name = w3d_string_80374ebc;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 2: {
            PropertyKey key;
            key.name = w3d_string_80374ebc;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 3: {
            PropertyKey key;
            key.name = w3d_string_80374ecc;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 4: {
            PropertyKey key;
            key.name = w3d_string_80374edc;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 5: {
            PropertyKey key;
            key.name = w3d_string_80374edc;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 6: {
            PropertyKey key;
            key.name = w3d_string_80374eec;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 7: {
            PropertyKey key;
            key.name = w3d_string_80374efc;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 8: {
            PropertyKey key;
            key.name = w3d_string_80374f0c;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        case 9: {
            PropertyKey key;
            key.name = w3d_string_80374f1c;
            w3d_string_property_800fc2b0(&key, &text);
            break;
        }
        }
        String name(text);
        w3d_commentary_play_80043134(self, name, 0);
    }
}


