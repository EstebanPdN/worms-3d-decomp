#include "w3d_ptr.h"
#line 1 "d26f_menu_list_edit_page_80275320.cpp"
// GWMP8P rev0 0x80275320. Debug editor page for a menu list control: prints
// fields and colours through the colour stream, formats an RGBA colour,
// writes to the sink, then flushes and rewrites the menu list header.
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
extern "C" void w3d_string_release_header(Ptr32<void>);
struct D26fText_803426b8 {
    Ptr32<char> text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
    Ptr32<const char> c_str() const { return text; }
    D26fText_803426b8 &operator=(const D26fText_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_tagged_construct_8020d318(Ptr32<void>, Ptr32<D26fText_803426b8>);
extern "C" void w3d_dtor_node_8020d36c(Ptr32<void>, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(Ptr32<void>);
struct D26fReader;
extern "C" int w3d_auto_8020d4b8(Ptr32<D26fReader>, int, int, Ptr32<int>);
extern D26fText_803426b8 lbl_804b06a0[];
struct D26fReaderTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<D26fReader>)> retain; Ptr32<void (Ptr32<D26fReader>)> release; };
struct D26fReader {
    Ptr32<D26fReaderTable> vt;
    unsigned words[4];
    Ptr32<D26fText_803426b8> buffer;
    unsigned size;
    D26fReader(D26fText_803426b8 &t) { w3d_tagged_construct_8020d318(this, &t); }
    ~D26fReader() { w3d_dtor_node_8020d36c(this, 2); }
};
struct D26fDescriptor {
    Ptr32<D26fReader> p;
    unsigned int tail:11; unsigned int format:5; unsigned int size:8; unsigned int flag:1; unsigned int type:7;
    D26fDescriptor(const D26fDescriptor &);
    D26fDescriptor(D26fReader &r) : p(&r) {
        if (p) p->vt->retain(p);
        type = 10;
        flag = 0;
        size = 0;
        format = 6;
        w3d_registry_retain_8020d2b8(&r);
    }
    ~D26fDescriptor() { if (p) p->vt->release(p); }
};
struct D26fTextStream {
    D26fReader reader;
    D26fDescriptor descriptor;
    D26fTextStream(D26fText_803426b8 &t) : reader(t), descriptor(reader) {}
};
struct D26fProperty;
struct D26fPropertyTable { Ptr32<void> s0[5]; Ptr32<void (Ptr32<D26fProperty>, Ptr32<D26fDescriptor>, Ptr32<void>)> read; };
struct D26fProperty { Ptr32<void> w0; Ptr32<D26fPropertyTable> vt; };
struct D26fRgba { unsigned char r, g, b, a; };
struct D26fVec { float v[3]; };
struct D26fButton;
struct D26fButtonTable { Ptr32<void> s0[5]; Ptr32<Ptr32<void> (Ptr32<D26fButton>)> type_info; };
struct D26fButton {
    Ptr32<D26fButtonTable> vt;
    char pad4[112];
    D26fRgba text_colour;
    float border_width;
    char pad124[12];
    Ptr32<const char> text_game_data_id;
    Ptr32<const char> resource_name;
    char pad144[12];
    Ptr32<const char> invalid_characters;
    int max_pixel_width;
    int max_chars;
    Ptr32<const char> someone_typing_message;
    Ptr32<const char> return_pressed_message;
    Ptr32<const char> selected_message;
    Ptr32<const char> highlighted_message;
    int password_box;
};
struct D26fEditor { char pad0[32]; Ptr32<void> sink; int mode; char pad40[52]; Ptr32<D26fButton> target; };
extern "C" void w3d_cx7b_script_flag_set_8027a934(Ptr32<D26fEditor>, int);
extern "C" void w3d_s21_repeat_request_802cd220(Ptr32<D26fText_803426b8>);
extern "C" void w3d_auto_802cd128(Ptr32<D26fText_803426b8>);
extern "C" void w3d_auto_802cbf2c(Ptr32<D26fText_803426b8>, Ptr32<const char>, int);
extern "C" void w3d_cc32b_append_lines_v2_802cc0ac(Ptr32<D26fText_803426b8>, Ptr32<const char>, int);
extern "C" void w3d_s21_append_position_802cd26c(Ptr32<D26fText_803426b8>, int, int);
extern "C" void w3d_s21_sink_write_indexed_802cbdf8(int, Ptr32<const char>, int);
extern "C" Ptr32<D26fProperty> w3d_s21_vector_get_801e9db8(Ptr32<void>, int);
extern "C" void w3d_auto_802cbf68(Ptr32<D26fText_803426b8>, int, int);
extern "C" void w3d_auto_802cbfa4(Ptr32<D26fText_803426b8>, float, int);
extern "C" void w3d_r25b_sink_write_v3_802cbe9c(int, Ptr32<const char>, int);
extern "C" void w3d_auto_802cd07c(int);
extern "C" int w3d_string_format(Ptr32<D26fText_803426b8>, Ptr32<const char>, ...);
extern char lbl_803cc0d8[], lbl_803cc7a4[], lbl_803cc864[], lbl_803cc86c[], lbl_803cc8b4[], lbl_803ccbb8[], lbl_803ccf30[], lbl_803cd22c[], lbl_803cd24c[], lbl_803cd26c[], lbl_803cd7e4[], lbl_803cd7f8[], lbl_803cd818[], lbl_803cd838[], lbl_803cd858[], lbl_803cd878[], lbl_803cd898[], lbl_803cd8b8[], lbl_803cd8d8[], lbl_803cd8f8[], lbl_803cd918[], lbl_803cd938[];
extern "C" void d26f_menu_list_edit_page_80275320(Ptr32<D26fEditor> self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 11;
    w3d_auto_802cbf2c(&text, lbl_803cd7e4, 7);
    w3d_auto_802cbf2c(&text, lbl_803ccf30, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc0d8, 9);
    Ptr32<D26fButton> target = self->target;
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc7a4, 9);
    w3d_auto_802cbf2c(&text, target->resource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd22c, 9);
    w3d_auto_802cbf2c(&text, target->text_game_data_id, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd24c, 9);
    D26fText_803426b8 colour;
    D26fTextStream stream(colour);
    Ptr32<D26fProperty> property = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 23);
    property->vt->read(property, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd26c, 9);
    w3d_auto_8020d4b8(&stream.reader, 0, 0, 0);
    *stream.reader.buffer = lbl_804b06a0[0];
    Ptr32<D26fProperty> property2 = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 24);
    property2->vt->read(property2, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd7f8, 9);
    w3d_auto_802cbf2c(&text, target->highlighted_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd818, 9);
    w3d_auto_802cbf2c(&text, target->selected_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd838, 9);
    w3d_auto_802cbf2c(&text, target->return_pressed_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd858, 9);
    w3d_auto_802cbf2c(&text, target->someone_typing_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd878, 9);
    w3d_auto_802cbf68(&text, target->max_chars, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd898, 9);
    w3d_auto_802cbf68(&text, target->max_pixel_width, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd8b8, 9);
    w3d_auto_802cbf2c(&text, target->password_box == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd8d8, 9);
    w3d_auto_802cbfa4(&text, target->border_width, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd8f8, 9);
    Ptr32<const D26fRgba> c = &target->text_colour;
    w3d_string_format(&colour, lbl_803ccbb8, c->r, c->g, c->b, c->a);
    /*FORMAT*/
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd918, 9);
    w3d_auto_802cbf2c(&text, target->invalid_characters, 9);
    w3d_s21_append_position_802cd26c(&text, 0, 24);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc8b4, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)w3d::H(self->sink), text.c_str(), 9);
    w3d_auto_802cd07c((int)w3d::H(self->sink));
    self->mode = 11;
    w3d_r25b_sink_write_v3_802cbe9c((int)w3d::H(self->sink), lbl_803cd938, 7);
}


