#include "w3d_ptr.h"
#line 1 "sol35e4a_team_descriptors_8024298c.cpp"
// Inferred team descriptor registration and observed shared-string lifetimes.
struct SharedString;
extern "C" void sol35e4a_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> sol35e4a_string_header_80341884(Ptr32<SharedString>);
extern "C" void sol35e4a_string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void sol35e4a_string_release_80341588(Ptr32<SharedString>);
extern "C" void sol35e4a_release_header_8020bb2c(Ptr32<unsigned short>);

struct SharedString {
    Ptr32<char> text;

    // A real external C++ constructor preserves the observed call lifetime.

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
Ptr32<void> sol35e4a_register_bool_801eb674(Ptr32<void>, Ptr32<const void>);
Ptr32<void> sol35e4a_register_u8_801eb834(Ptr32<void>, Ptr32<const void>);
Ptr32<void> sol35e4a_register_u32_801ebf38(Ptr32<void>, Ptr32<const void>);
void sol35e4a_finish_801e8d9c(Ptr32<void>);
extern const unsigned char sol35e4a_desc_803be7d0[];
extern const unsigned char sol35e4a_desc_803be7f4[];
extern const unsigned char sol35e4a_desc_803be82c[];
extern const unsigned char sol35e4a_desc_803be860[];
extern const unsigned char sol35e4a_desc_803be898[];
extern const unsigned char sol35e4a_desc_803be8cc[];
extern const unsigned char sol35e4a_desc_803be908[];
extern const unsigned char sol35e4a_desc_803be940[];
extern const unsigned char sol35e4a_desc_803be974[];
extern const unsigned char sol35e4a_desc_803be9a8[];
extern const unsigned char sol35e4a_desc_803be9e0[];
extern const unsigned char sol35e4a_desc_803bea14[];
extern const unsigned char sol35e4a_desc_803bea48[];
extern const unsigned char sol35e4a_desc_803bea7c[];
extern const unsigned char sol35e4a_desc_803beab4[];
extern const unsigned char sol35e4a_desc_803beae4[];
extern const unsigned char sol35e4a_desc_803beb14[];

int sol35e4a_team_descriptors_8024298c(Ptr32<void> owner) {
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803be7d0)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803be7f4);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803be82c);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803be860);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803be898);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803be8cc);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803be908);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803be940);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803be974);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803be9a8);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803be9e0);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803bea14);
    sol35e4a_register_u32_801ebf38(owner, sol35e4a_desc_803bea48);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803bea7c)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803beab4);
    sol35e4a_register_u8_801eb834(owner, sol35e4a_desc_803beae4);
    sol35e4a_register_bool_801eb674(owner, sol35e4a_desc_803beb14);
    sol35e4a_finish_801e8d9c(owner);
    return 0;
}
}

typedef char StringSize[sizeof(SharedString) == 4 ? 1 : -1];
typedef char StringValueOffset[__builtin_offsetof(StringBinding,value) == 8 ? 1 : -1];


