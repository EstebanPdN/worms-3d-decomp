#include "w3d_ptr.h"
#line 1 "sol35e5a_color_descriptors_8024645c.cpp"
// Inferred color descriptor registration and observed shared-string lifetimes.
struct SharedString;
extern "C" void sol35e5a_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> sol35e5a_string_header_80341884(Ptr32<SharedString>);
extern "C" void sol35e5a_string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void sol35e5a_string_release_80341588(Ptr32<SharedString>);
extern "C" void sol35e5a_release_header_8020bb2c(Ptr32<unsigned short>);

struct SharedString {
    Ptr32<char> text;

    // A real external C++ constructor preserves the observed call lifetime.

    SharedString(const SharedString &other) {
        sol35e5a_string_init_8020c5c0(this);
        text = other.text;
        ++*sol35e5a_string_header_80341884(this);
    }

    ~SharedString() {
        sol35e5a_string_finish_8020c5c4(this);
        sol35e5a_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            sol35e5a_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString sol35e5a_empty_804b06a0[];
// Four observed byte channels, with a word copy at the binding boundary.
union Color {
    struct Channels { unsigned char alpha; unsigned char blue; unsigned char green; unsigned char red; } channels;
    unsigned word;

    Color(unsigned char red, unsigned char green,
          unsigned char blue, unsigned char alpha) {
        channels.red = red;
        channels.green = green;
        channels.blue = blue;
        channels.alpha = alpha;
    }
};

struct ColorBinding {
    unsigned header[2];
    Color value;
};

typedef char ColorSize[sizeof(Color) == 4 ? 1 : -1];
typedef char ColorOffset[__builtin_offsetof(ColorBinding,value) == 8 ? 1 : -1];

extern "C" {
Ptr32<ColorBinding> sol35e5a_register_color_801f15e0(Ptr32<void>, Ptr32<const void>);
Ptr32<StringBinding> sol35e5a_register_string_801ed24c(Ptr32<void>, Ptr32<const void>);
Ptr32<void> sol35e5a_register_scalar_801ec52c(Ptr32<void>, Ptr32<const void>);
void sol35e5a_finish_801e8d9c(Ptr32<void>);
extern const unsigned char sol35e5a_desc_803c2bd4[];
extern const unsigned char sol35e5a_desc_803c2c08[];
extern const unsigned char sol35e5a_desc_803c2c40[];
extern const unsigned char sol35e5a_desc_803c2c74[];
extern const unsigned char sol35e5a_desc_803c2ca8[];
extern const unsigned char sol35e5a_desc_803c2ce0[];
extern const unsigned char sol35e5a_desc_803c2d18[];
extern const unsigned char sol35e5a_desc_803c2d50[];
extern const unsigned char sol35e5a_desc_803c2d88[];
extern const unsigned char sol35e5a_desc_803c2dbc[];
extern const unsigned char sol35e5a_desc_803c2df4[];
extern const unsigned char sol35e5a_desc_803c2e28[];
extern const unsigned char sol35e5a_desc_803c2e60[];
extern const unsigned char sol35e5a_desc_803c2e94[];
extern const unsigned char sol35e5a_desc_803c2ec8[];
extern const unsigned char sol35e5a_desc_803c2f00[];
extern const unsigned char sol35e5a_desc_803c2f38[];
extern const unsigned char sol35e5a_desc_803c2f70[];
extern const unsigned char sol35e5a_desc_803c2fa8[];
extern const unsigned char sol35e5a_desc_803c2fdc[];
extern const unsigned char sol35e5a_desc_803c3018[];
extern const unsigned char sol35e5a_desc_803c3054[];
extern const unsigned char sol35e5a_desc_803c3090[];
extern const unsigned char sol35e5a_desc_803c30cc[];
extern const unsigned char sol35e5a_desc_803c3104[];
extern const unsigned char sol35e5a_desc_803c3138[];
extern const unsigned char sol35e5a_desc_803c316c[];
extern const unsigned char sol35e5a_desc_803c31a4[];
extern const unsigned char sol35e5a_desc_803c31d8[];
extern const unsigned char sol35e5a_desc_803c320c[];
extern const unsigned char sol35e5a_desc_803c3244[];
extern const unsigned char sol35e5a_desc_803c3280[];
extern const unsigned char sol35e5a_desc_803c32bc[];
extern const unsigned char sol35e5a_desc_803c32f8[];
extern const unsigned char sol35e5a_desc_803c3334[];
extern const unsigned char sol35e5a_desc_803c3370[];

int sol35e5a_color_descriptors_8024645c(Ptr32<void> owner) {
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2bd4)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2c08)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2c40)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2c74)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2ca8)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2ce0)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2d18)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2d50)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2d88)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2dbc)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2df4)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2e28)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2e60)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2e94)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2ec8)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2f00)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2f38)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2f70)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2fa8)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c2fdc)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c3018)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c3054)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c3090)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c30cc)->value = Color(0, 0, 0, 0);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c3104)->value = Color(0, 0, 0, 0);
    sol35e5a_register_string_801ed24c(owner, sol35e5a_desc_803c3138)->value =
        SharedString(sol35e5a_empty_804b06a0[0]);
    sol35e5a_register_string_801ed24c(owner, sol35e5a_desc_803c316c)->value =
        SharedString(sol35e5a_empty_804b06a0[0]);
    sol35e5a_register_string_801ed24c(owner, sol35e5a_desc_803c31a4)->value =
        SharedString(sol35e5a_empty_804b06a0[0]);
    sol35e5a_register_string_801ed24c(owner, sol35e5a_desc_803c31d8)->value =
        SharedString(sol35e5a_empty_804b06a0[0]);
    sol35e5a_register_color_801f15e0(owner, sol35e5a_desc_803c320c)->value = Color(0, 0, 0, 0);
    sol35e5a_register_scalar_801ec52c(owner, sol35e5a_desc_803c3244);
    sol35e5a_register_scalar_801ec52c(owner, sol35e5a_desc_803c3280);
    sol35e5a_register_scalar_801ec52c(owner, sol35e5a_desc_803c32bc);
    sol35e5a_register_scalar_801ec52c(owner, sol35e5a_desc_803c32f8);
    sol35e5a_register_scalar_801ec52c(owner, sol35e5a_desc_803c3334);
    sol35e5a_register_scalar_801ec52c(owner, sol35e5a_desc_803c3370);
    sol35e5a_finish_801e8d9c(owner);
    return 0;
}
}

typedef char StringSize[sizeof(SharedString) == 4 ? 1 : -1];
typedef char StringOffset[__builtin_offsetof(StringBinding,value) == 8 ? 1 : -1];


