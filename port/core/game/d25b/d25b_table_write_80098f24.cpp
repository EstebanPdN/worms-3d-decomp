#include "w3d_ptr.h"
#line 1 "d25b_table_write_80098f24.cpp"
/* Character-table write (0x80098f24): builds a string (0x803426b8, 0x802cd220,
 * 0x802cd128), appends every entry of the null-terminated table 0x803f4b50
 * (0x802cbf2c, 7), writes the text to the sink at +32 (0x802cbdf8, 9) and clears
 * +36 and +40. Field and type names are inferred; the table is an external view. */
struct String {
    Ptr32<char> text;
    String();
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
extern "C" void w3d_repeat_request_802cd220(Ptr32<String>);
extern "C" void w3d_string_op_802cd128(Ptr32<String>);
extern "C" void w3d_append_802cbf2c(Ptr32<String>, Ptr32<const char>, int);
extern "C" void w3d_sink_write_802cbdf8(int, Ptr32<char>, int);
extern Ptr32<const char> w3d_table_803f4b50[];
struct Owner { char unknown00[32]; Ptr32<void> sink; int a; int b; };
extern "C" void w3d_d25b_table_write_80098f24(Ptr32<Owner> self)
{
    String text;
    w3d_repeat_request_802cd220(&text);
    w3d_string_op_802cd128(&text);
    int i = 0;
    while (w3d_table_803f4b50[i]) { w3d_append_802cbf2c(&text, w3d_table_803f4b50[i], 7); i++; }
    w3d_sink_write_802cbdf8((int)w3d::H(self->sink), text.text, 9);
    self->b = 0;
    self->a = 0;
}


