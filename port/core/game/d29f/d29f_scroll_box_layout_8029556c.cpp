#include "w3d_ptr.h"
#line 1 "d29f_scroll_box_layout_8029556c.cpp"
// GWMP8P rev0 0x8029556c. Lays out a frontend scroll box when it is both
// ready and shown: sizes and positions its parts from the box width, height
// and depth, moves the scroll position, stops the old sound, picks a dynamic
// slot and places the text. Field names are inferred; the unit owns no data.
struct Vec3 {
    float x, y, z;
    Vec3 &Set(float a, float b, float c) { Ptr32<Vec3> p = this; x = a; p->y = b; p->z = c; return *this; }
};
struct Part { Ptr32<Ptr32<void>> table; };
inline void SetSize(Ptr32<Part> part, const Vec3 &v) { ((Ptr32<void (Ptr32<Part>, Ptr32<const Vec3>, int)>)part->table[21])(part, &v, 0); }
inline void SetPos(Ptr32<Part> part, const Vec3 &v) { ((Ptr32<void (Ptr32<Part>, Ptr32<const Vec3>, int)>)part->table[19])(part, &v, 0); }
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>);
struct String {
    Ptr32<char> text;
    String(const String &);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
inline String::String(const String &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
struct Box {
    char pad0[48];
    float target;
    float position;
    int ready;
    int shown;
    char pad1[128 - 64];
    Ptr32<Part> text; Ptr32<Part> top; Ptr32<Part> middle; Ptr32<Part> thumb; Ptr32<Part> upper; Ptr32<Part> lower; Ptr32<Part> arrow;
    char pad2[160 - 156];
    float width, height, depth;
    char pad3[176 - 172];
    String sound;
    union {
        int slot;
        w3d::be_array<unsigned char, 4> bytes;
    };
};
extern float lbl_803d07c0[], lbl_803d07c4[], lbl_803d07c8[], lbl_803d07cc[], lbl_803d07d0[], lbl_803d07d4[], lbl_803d07d8[], lbl_803d07dc[];
extern "C" void w3d_s4_box_stop_sound(Ptr32<Box>);
extern "C" int w3d_d20e_dynamic_slot_80263cfc(String, int, float);
extern "C" int w3d_s20_store_byte_value_80173f88(Ptr32<Part>, Ptr32<unsigned char>);
extern "C" void fn_802958d8(Ptr32<Box>);
inline float Twice(float v) { return v + v; }
extern "C" void d29f_scroll_box_layout_8029556c(Ptr32<Box> self) {
    if ((self->shown != 0) & (self->ready != 0)) {
        Vec3 v;
        float h = self->height;
        float z = lbl_803d07c4[0];
        float half = h * lbl_803d07c0[0];
        self->position = self->target;
        SetSize(self->top, v.Set(self->width, h, z));
        SetSize(self->middle, v.Set(self->width, self->height, z));
        float c = lbl_803d07c8[0];
        SetSize(self->upper, v.Set(self->width, c, z));
        SetSize(self->arrow, v.Set(self->width, c, z));
        SetSize(self->lower, v.Set(self->width, lbl_803d07cc[0], z));
        float zero = lbl_803d07d4[0];
        float scale = lbl_803d07d0[0];
        SetPos(self->top, v.Set(zero, self->position * scale - half, zero));
        SetPos(self->middle, v.Set(zero, zero - self->position * scale + half, zero));
        float ratio = lbl_803d07d8[0];
        SetSize(self->thumb, v.Set(self->depth / ratio, self->width, z));
        SetPos(self->thumb, v.Set(zero, self->position * scale - self->width - half, zero));
        self->position -= half * lbl_803d07dc[0];
        w3d_s4_box_stop_sound(self);
        self->slot = w3d_d20e_dynamic_slot_80263cfc(self->sound, -1, Twice(self->position * scale + half));
        SetPos(self->text, v.Set(zero, zero, zero));
        SetSize(self->text, v.Set(self->depth / ratio, self->position * scale + half, z));
        w3d_s20_store_byte_value_80173f88(self->text, &self->bytes[3]);
        fn_802958d8(self);
    }
}


