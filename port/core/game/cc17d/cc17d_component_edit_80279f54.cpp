#include "w3d_ptr.h"
#line 1 "cc17d_component_edit_80279f54.cpp"
// cc17d: component editors (0x80279f54 colour bytes, 0x80279dc0 vector).
// Observed: the editor holds the edited object at +92 and a property key at
// +96 (field located as in cc17d_prop_edit_8027a2c4), a component index at
// +44 (vector) / +48 (colour) and an output sink at +32.  After storing, a
// default string is passed through 0x802cd26c / 0x802cc0ac (with the original
// blank literal at 0x803ce688 and 7) / 0x802cd26c, written to the sink with
// 9, and 0x8027a934 is called with 1 (inferred: refresh of the edit line).
struct Cc17dObject { Ptr32<Ptr32<void>> methods; };
struct Cc17dField { unsigned char reserved[4]; unsigned short offset; };
struct Cc17dFieldRef { Ptr32<Cc17dField> field; };
struct Cc17dEditor {
    unsigned char reserved[32];
    Ptr32<void> sink;                        // +32
    unsigned char pad24[8];
    int vector_component;              // +44
    int color_component;               // +48
    unsigned char pad34[40];
    Ptr32<Cc17dObject> receiver;             // +92
    int key;                           // +96
};
struct Cc17dColor { unsigned char c[4]; };
struct Cc17dVec3 { float x, y, z; };
extern "C" {
int atol(Ptr32<const char>);
double atof(Ptr32<const char>);
Ptr32<Cc17dFieldRef> w3d_s21_vector_get_801e9db8(Ptr32<void>, int);
void w3d_auto_8027a98c(Ptr32<Cc17dEditor>);
Ptr32<void> w3d_string_default(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_s21_append_position_802cd26c(Ptr32<void>, int, int);
void fn_802cc0ac(Ptr32<void>, Ptr32<const char>, int);
void w3d_s21_sink_write_indexed_802cbdf8(int, Ptr32<const char>, int);
void w3d_cx7b_script_flag_set_8027a934(Ptr32<Cc17dEditor>, int);
}
extern "C" const char w3d_str_803ce688[];
struct Cc17dText {
    Ptr32<const char> text;
    int unknown;
    Cc17dText() { w3d_string_default(this); }
    ~Cc17dText() { w3d_string_base_finish(this); w3d_string_release(this); }
    void position(int a, int b) { w3d_s21_append_position_802cd26c(this, a, b); }
    void pad(Ptr32<const char> s, int n) { fn_802cc0ac(this, s, n); }
};
#define CC17D_TYPE(o) (((void *(*)(Cc17dObject *))(o)->methods[5])(o))
#define CC17D_FIELD(T, o, ref) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(o) + (ref)->field->offset))
static inline void cc17d_show_line(Ptr32<Cc17dEditor> self)
{
    Cc17dText line;
    line.position(0, 10);
    line.pad(w3d_str_803ce688, 7);
    line.position(0, 10);
    w3d_s21_sink_write_indexed_802cbdf8((int)w3d::H(self->sink), line.text, 9);
    w3d_cx7b_script_flag_set_8027a934(self, 1);
}
static inline void cc17d_store_color(Ptr32<Cc17dEditor> self, const Cc17dColor &color)
{
    Ptr32<Cc17dObject> receiver = self->receiver;
    Ptr32<Cc17dFieldRef> ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
    Ptr32<Ptr32<Cc17dObject>> slot = &receiver;
    CC17D_FIELD(Cc17dColor, *slot, ref) = color;
}
extern "C" void w3d_cc17d_color_edit_80279f54(Ptr32<Cc17dEditor> self, Ptr32<const char> text)
{
    if (*text) {
        Ptr32<Cc17dObject> receiver = self->receiver;
        Ptr32<Cc17dFieldRef> ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Ptr32<Ptr32<Cc17dObject>> slot = &receiver;
        Cc17dColor color = CC17D_FIELD(Cc17dColor, *slot, ref);
        switch (self->color_component) {
        case 0: color.c[0] = atol(text); break;
        case 2: color.c[2] = atol(text); break;
        case 1: color.c[1] = atol(text); break;
        case 3: color.c[3] = atol(text); break;
        }
        cc17d_store_color(self, color);
        cc17d_show_line(self);
    }
    w3d_auto_8027a98c(self);
}


