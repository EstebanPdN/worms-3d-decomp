#include "w3d_ptr.h"
#line 1 "k10a_menu_page_setup_80098fc8.cpp"
// Appears to build a menu page line: it composes a request string from three
// text pieces (the third repeated nineteen times), writes it to the menu's sink
// at index 9, clears and sets the menu state fields and refreshes the page.
extern "C" Ptr32<void> w3d_string_default(Ptr32<void> string);
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);
struct K10aString
{
    Ptr32<char> text;
    unsigned int storage;
    K10aString() {}
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K10aMenu
{
    char pad0[32];
    Ptr32<void> sink;              // +32
    int first;               // +36
    int mode;                // +40
    int second;              // +44
};
extern Ptr32<const char> w3d_pieces_803f4b90[];
extern "C" void w3d_s21_repeat_request_802cd220(Ptr32<K10aString> line);
extern "C" void w3d_auto_802cd128(Ptr32<K10aString> line);
extern "C" void w3d_auto_802cbf2c(Ptr32<K10aString> line, Ptr32<const char> piece, int mode);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(int sink, Ptr32<char> text, int index);
extern "C" void fn_800994b4(Ptr32<K10aMenu> self);
extern "C" void fn_800990a4(Ptr32<K10aMenu> self);
extern "C" void w3d_show_options_line_80099998(Ptr32<K10aMenu> self);
extern "C" void w3d_k10a_menu_page_setup_80098fc8(Ptr32<K10aMenu> self)
{
    K10aString line;
    w3d_string_default(&line);
    w3d_s21_repeat_request_802cd220(&line);
    w3d_auto_802cd128(&line);
    w3d_auto_802cbf2c(&line, w3d_pieces_803f4b90[0], 2);
    w3d_auto_802cbf2c(&line, w3d_pieces_803f4b90[1], 2);
    for (unsigned int i = 0; i < 19; i++)
        w3d_auto_802cbf2c(&line, w3d_pieces_803f4b90[2], 2);
    w3d_s21_sink_write_indexed_802cbdf8((int)w3d::H(self->sink), line.text, 9);
    fn_800994b4(self);
    self->mode = 1;
    self->second = 0;
    self->first = 0;
    fn_800990a4(self);
    w3d_show_options_line_80099998(self);
}


