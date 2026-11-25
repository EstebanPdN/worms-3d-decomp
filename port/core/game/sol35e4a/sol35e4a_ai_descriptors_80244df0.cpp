#include "w3d_ptr.h"
#line 1 "sol35e4a_ai_descriptors_80244df0.cpp"
// Inferred team descriptor registration and observed shared-string lifetimes.
struct SharedString;
extern "C" void sol35e4a_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> sol35e4a_string_header_80341884(Ptr32<SharedString>);
extern "C" void sol35e4a_string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void sol35e4a_string_release_80341588(Ptr32<SharedString>);
extern "C" void sol35e4a_release_header_8020bb2c(Ptr32<unsigned short>);

struct SharedString {
    Ptr32<char> text;

    // Copy construction preserves the observed external retain boundary.

    SharedString(const SharedString &other) {
        sol35e4a_string_init_8020c5c0(this);
        text = other.text;
        ++*sol35e4a_string_header_80341884(this);
    }

    ~SharedString() {
        sol35e4a_string_finish_8020c5c4(this);
        sol35e4a_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            sol35e4a_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString sol35e4a_empty_804b06a0[];
extern "C" {
Ptr32<StringBinding> sol35e4a_register_string_801ed24c(Ptr32<void>, Ptr32<const void>);
Ptr32<void> sol35e4a_register_scalar_801ec52c(Ptr32<void>, Ptr32<const void>);
Ptr32<void> sol35e4a_register_bool_801eb674(Ptr32<void>, Ptr32<const void>);
void sol35e4a_finish_801e8d9c(Ptr32<void>);
extern const unsigned char sol35e4a_desc_803c0630[];
extern const unsigned char sol35e4a_desc_803c066c[];
extern const unsigned char sol35e4a_desc_803c06a8[];
extern const unsigned char sol35e4a_desc_803c06e8[];
extern const unsigned char sol35e4a_desc_803c0728[];
extern const unsigned char sol35e4a_desc_803c0768[];
extern const unsigned char sol35e4a_desc_803c07ac[];
extern const unsigned char sol35e4a_desc_803c07ec[];
extern const unsigned char sol35e4a_desc_803c0824[];
extern const unsigned char sol35e4a_desc_803c0870[];
extern const unsigned char sol35e4a_desc_803c08b8[];
extern const unsigned char sol35e4a_desc_803c08f4[];
extern const unsigned char sol35e4a_desc_803c0934[];
extern const unsigned char sol35e4a_desc_803c0978[];
extern const unsigned char sol35e4a_desc_803c09c0[];
extern const unsigned char sol35e4a_desc_803c0a0c[];
extern const unsigned char sol35e4a_desc_803c0a4c[];
extern const unsigned char sol35e4a_desc_803c0a88[];
extern const unsigned char sol35e4a_desc_803c0ac0[];
extern const unsigned char sol35e4a_desc_803c0b04[];
extern const unsigned char sol35e4a_desc_803c0b3c[];
extern const unsigned char sol35e4a_desc_803c0b74[];
extern const unsigned char sol35e4a_desc_803c0bb8[];
extern const unsigned char sol35e4a_desc_803c0bf8[];
extern const unsigned char sol35e4a_desc_803c0c3c[];
extern const unsigned char sol35e4a_desc_803c0c84[];
extern const unsigned char sol35e4a_desc_803c0cd0[];
extern const unsigned char sol35e4a_desc_803c0d14[];
extern const unsigned char sol35e4a_desc_803c0d54[];
extern const unsigned char sol35e4a_desc_803c0d8c[];
extern const unsigned char sol35e4a_desc_803c0dcc[];
extern const unsigned char sol35e4a_desc_803c0e0c[];
extern const unsigned char sol35e4a_desc_803c0e4c[];
extern const unsigned char sol35e4a_desc_803c0e90[];
extern const unsigned char sol35e4a_desc_803c0ed4[];
extern const unsigned char sol35e4a_desc_803c0f10[];
extern const unsigned char sol35e4a_desc_803c0f4c[];
extern const unsigned char sol35e4a_desc_803c0f94[];
extern const unsigned char sol35e4a_desc_803c0fd4[];
extern const unsigned char sol35e4a_desc_803c1014[];
extern const unsigned char sol35e4a_desc_803c1060[];
extern const unsigned char sol35e4a_desc_803c10ac[];
extern const unsigned char sol35e4a_desc_803c10f8[];
extern const unsigned char sol35e4a_desc_803c113c[];
extern const unsigned char sol35e4a_desc_803c1188[];
extern const unsigned char sol35e4a_desc_803c11cc[];
extern const unsigned char sol35e4a_desc_803c1208[];
extern const unsigned char sol35e4a_desc_803c1240[];
extern const unsigned char sol35e4a_desc_803c1284[];
extern const unsigned char sol35e4a_desc_803c12cc[];
extern const unsigned char sol35e4a_desc_803c1304[];
extern const unsigned char sol35e4a_desc_803c1348[];
extern const unsigned char sol35e4a_desc_803c138c[];
extern const unsigned char sol35e4a_desc_803c13d0[];
extern const unsigned char sol35e4a_desc_803c140c[];
extern const unsigned char sol35e4a_desc_803c1450[];
extern const unsigned char sol35e4a_desc_803c1494[];
extern const unsigned char sol35e4a_desc_803c14d8[];
extern const unsigned char sol35e4a_desc_803c151c[];
extern const unsigned char sol35e4a_desc_803c1560[];
extern const unsigned char sol35e4a_desc_803c159c[];
extern const unsigned char sol35e4a_desc_803c15d4[];
extern const unsigned char sol35e4a_desc_803c161c[];
extern const unsigned char sol35e4a_desc_803c1668[];
extern const unsigned char sol35e4a_desc_803c169c[];
extern const unsigned char sol35e4a_desc_803c16d0[];
extern const unsigned char sol35e4a_desc_803c170c[];
extern const unsigned char sol35e4a_desc_803c1744[];
extern const unsigned char sol35e4a_desc_803c177c[];
extern const unsigned char sol35e4a_desc_803c17b8[];
extern const unsigned char sol35e4a_desc_803c17f0[];
extern const unsigned char sol35e4a_desc_803c1828[];
extern const unsigned char sol35e4a_desc_803c185c[];
extern const unsigned char sol35e4a_desc_803c188c[];
extern const unsigned char sol35e4a_desc_803c18c4[];
extern const unsigned char sol35e4a_desc_803c18f8[];
extern const unsigned char sol35e4a_desc_803c1930[];
extern const unsigned char sol35e4a_desc_803c1968[];
extern const unsigned char sol35e4a_desc_803c19a4[];
extern const unsigned char sol35e4a_desc_803c19d8[];
extern const unsigned char sol35e4a_desc_803c1a14[];
extern const unsigned char sol35e4a_desc_803c1a4c[];
extern const unsigned char sol35e4a_desc_803c1a80[];
extern const unsigned char sol35e4a_desc_803c1ab8[];
extern const unsigned char sol35e4a_desc_803c1af0[];
extern const unsigned char sol35e4a_desc_803c1b28[];
extern const unsigned char sol35e4a_desc_803c1b60[];
extern const unsigned char sol35e4a_desc_803c1b94[];
extern const unsigned char sol35e4a_desc_803c1bcc[];
extern const unsigned char sol35e4a_desc_803c1c08[];
extern const unsigned char sol35e4a_desc_803c1c40[];
extern const unsigned char sol35e4a_desc_803c1c78[];
extern const unsigned char sol35e4a_desc_803c1cb0[];
extern const unsigned char sol35e4a_desc_803c1ce8[];
extern const unsigned char sol35e4a_desc_803c1d1c[];
extern const unsigned char sol35e4a_desc_803c1d54[];
extern const unsigned char sol35e4a_desc_803c1d8c[];
extern const unsigned char sol35e4a_desc_803c1dc4[];
extern const unsigned char sol35e4a_desc_803c1e00[];
extern const unsigned char sol35e4a_desc_803c1e38[];
extern const unsigned char sol35e4a_desc_803c1e70[];
extern const unsigned char sol35e4a_desc_803c1ea8[];
extern const unsigned char sol35e4a_desc_803c1ee0[];
extern const unsigned char sol35e4a_desc_803c1f14[];
extern const unsigned char sol35e4a_desc_803c1f48[];
extern const unsigned char sol35e4a_desc_803c1f80[];
extern const unsigned char sol35e4a_desc_803c1fb8[];
extern const unsigned char sol35e4a_desc_803c1fec[];
extern const unsigned char sol35e4a_desc_803c2024[];
extern const unsigned char sol35e4a_desc_803c2060[];
extern const unsigned char sol35e4a_desc_803c209c[];
extern const unsigned char sol35e4a_desc_803c20d4[];
extern const unsigned char sol35e4a_desc_803c210c[];
extern const unsigned char sol35e4a_desc_803c2144[];
extern const unsigned char sol35e4a_desc_803c2178[];
extern const unsigned char sol35e4a_desc_803c21b8[];
extern const unsigned char sol35e4a_desc_803c21f4[];
extern const unsigned char sol35e4a_desc_803c2230[];
extern const unsigned char sol35e4a_desc_803c2268[];
extern const unsigned char sol35e4a_desc_803c22a4[];

int sol35e4a_ai_descriptors_80244df0(Ptr32<void> owner) {
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0630);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c066c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c06a8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c06e8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0728);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0768);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c07ac);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c07ec);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0824);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0870);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c08b8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c08f4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0934);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0978);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c09c0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0a0c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0a4c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0a88);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0ac0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0b04);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0b3c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0b74);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0bb8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0bf8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0c3c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0c84);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0cd0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0d14);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0d54);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0d8c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0dcc);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0e0c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0e4c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0e90);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0ed4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0f10);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0f4c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0f94);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c0fd4);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803c1014);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1060);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c10ac);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c10f8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c113c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1188);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c11cc);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c1208)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1240);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1284);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803c12cc);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1304);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1348);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803c138c);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803c13d0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c140c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1450);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1494);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c14d8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c151c);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c1560)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c159c)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c15d4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c161c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1668);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c169c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c16d0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c170c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1744);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c177c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c17b8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c17f0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1828);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c185c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c188c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c18c4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c18f8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1930);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1968);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c19a4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c19d8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1a14);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1a4c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1a80);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1ab8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1af0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1b28);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1b60);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1b94);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1bcc);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1c08);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1c40);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1c78);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1cb0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1ce8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1d1c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1d54);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1d8c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1dc4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1e00);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1e38);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1e70);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1ea8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1ee0);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1f14);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1f48);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1f80);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1fb8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c1fec);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c2024);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c2060);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c209c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c20d4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c210c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c2144);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c2178);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c21b8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c21f4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c2230);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c2268);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c22a4);
    sol35e4a_finish_801e8d9c(owner);
    return 0;
}
}

typedef char StringSize[sizeof(SharedString) == 4 ? 1 : -1];
typedef char StringValueOffset[__builtin_offsetof(StringBinding,value) == 8 ? 1 : -1];


