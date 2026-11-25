#include "w3d_ptr.h"
#line 1 "d20e_timer_widget_reset_80223a78.cpp"
// Property reset routine of a front-end widget with a timer (Worms 3D
// GameCube PAL, 0x80223a78).
//
// Resets the string properties LumpFileId, HighlightedMessage,
// SelectedMessage and ChangedRenderState (entry helper 0x801ed24c) to the
// shared empty string 0x804b06a0 through a temporary copy, registers the
// BorderColour member binding (0x801ece2c), sets the TimerPosition vector
// (0x801f0210) to (0, 0, 0) and TimerScale to (20, 20, 0) using the
// constants 0x803b76c8 (0.0f) and 0x803b76cc (20.0f), calls the refresh
// routine 0x801e8d9c and returns 0. Descriptor names are read from the
// descriptors' name pointers in the original data.
//
// Derived from the never-proved draft w3d_d20e_reset_timer_widget_80223a78.cpp (string
// half unchanged). Both vectors are filled through a pointer and copied with
// an inline set(const Vec3 &), which gives the original separate stack
// temporaries and frame-relative loads. Built with -mps-float (one saved FPR
// in a non-leaf function).
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> d20e_string_header_80341884(Ptr32<SharedString>);
extern "C" void d20e_string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void d20e_string_release_80341588(Ptr32<SharedString>);
extern "C" void d20e_release_header_8020bb2c(Ptr32<unsigned short>);

struct SharedString {
    Ptr32<char> text;

    // A real external C++ constructor preserves the observed call lifetime.

    SharedString(const SharedString &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }

    ~SharedString() {
        d20e_string_finish_8020c5c4(this);
        d20e_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
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
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString d20e_empty_804b06a0[];
struct Vec3 { float x, y, z; };
struct VectorBinding {
    unsigned header[2];
    Vec3 value;
    void set(const Vec3 &v) { value = v; }
};
extern "C" {
Ptr32<StringBinding> fn_801ed24c(Ptr32<void>, Ptr32<const void>);
Ptr32<VectorBinding> fn_801f0210(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ece2c(Ptr32<void>, Ptr32<const void>);
void fn_801e8d9c(Ptr32<void>);
}
extern float constant_803b76c8[], constant_803b76cc[];
extern const unsigned char desc_803b7598[];   // LumpFileId
extern const unsigned char desc_803b75bc[];   // HighlightedMessage
extern const unsigned char desc_803b75e0[];   // SelectedMessage
extern const unsigned char desc_803b7618[];   // ChangedRenderState
extern const unsigned char desc_803b763c[];   // BorderColour
extern const unsigned char desc_803b7674[];   // TimerPosition
extern const unsigned char desc_803b76a4[];   // TimerScale
extern "C" int w3d_d20e_reset_timer_widget_80223a78(Ptr32<void> owner) {
    fn_801ed24c(owner, desc_803b7598)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b75bc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b75e0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7618)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ece2c(owner, desc_803b763c);
    Ptr32<VectorBinding> first = fn_801f0210(owner, desc_803b7674);
    float zero = constant_803b76c8[0];
    Vec3 a;
    Ptr32<Vec3> p = &a;
    p->x = zero;
    p->y = zero;
    p->z = zero;
    first->set(a);
    Ptr32<VectorBinding> second = fn_801f0210(owner, desc_803b76a4);
    float twenty = constant_803b76cc[0];
    Vec3 b;
    Ptr32<Vec3> q = &b;
    q->x = twenty;
    q->y = twenty;
    q->z = zero;
    second->set(b);
    fn_801e8d9c(owner);
    return 0;
}


