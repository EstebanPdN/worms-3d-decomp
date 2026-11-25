#include "w3d_ptr.h"
#line 1 "d26f_list_box_edit_page_80274a4c.cpp"
// GWMP8P rev0 0x80274a4c. Debug editor page for a list control: prints
// fields, colour, a boolean pair, the item background type by switch, and
// item metrics; final reads through an inline accessor.
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
struct D26fText_803426b8 {
    Ptr32<char> text;
    D26fText_803426b8();
    D26fText_803426b8(const D26fText_803426b8 &);
    Ptr32<const char> c_str() const { return text; }
    ~D26fText_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" void w3d_tagged_construct_8020d318(Ptr32<void>, Ptr32<D26fText_803426b8>);
extern "C" void w3d_dtor_node_8020d36c(Ptr32<void>, int);
extern "C" unsigned short w3d_registry_retain_8020d2b8(Ptr32<void>);
struct D26fReader;
struct D26fReaderTable { Ptr32<void> s0[3]; Ptr32<void (Ptr32<D26fReader>)> retain; Ptr32<void (Ptr32<D26fReader>)> release; };
struct D26fReader {
    Ptr32<D26fReaderTable> vt;
    unsigned words[6];
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
    float border_size;
    float item_height;
    int item_background_type;
    char pad128[4];
    Ptr32<const char> item_selected_message;
    Ptr32<const char> item_highlight_message;
    Ptr32<const char> game_data_id;
    char pad144[4];
    int auto_scroll;
    char pad152[4];
    int scrollbar_tab_expanding;
    int scrollbar_always_visible;
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
extern "C" void w3d_auto_802cbfa4(Ptr32<D26fText_803426b8>, float, int);
extern char lbl_803cc0d8[], lbl_803cc864[], lbl_803cc86c[], lbl_803cc8b4[], lbl_803cd40c[], lbl_803cd420[], lbl_803cd434[], lbl_803cd45c[], lbl_803cd47c[], lbl_803cd49c[], lbl_803cd4bc[], lbl_803cd4dc[], lbl_803cd4fc[], lbl_803cd51c[], lbl_803cd544[], lbl_803cd564[], lbl_803cd56c[], lbl_803cd574[], lbl_803cd588[], lbl_803cd590[], lbl_803cd5b0[], lbl_803cd5d0[];
extern "C" void d26f_list_box_edit_page_80274a4c(Ptr32<D26fEditor> self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 14;
    w3d_auto_802cbf2c(&text, lbl_803cd40c, 7);
    w3d_auto_802cbf2c(&text, lbl_803cd420, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc0d8, 9);
    Ptr32<D26fButton> target = self->target;
    w3d_auto_802cbf2c(&text, lbl_803cd434, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd45c, 9);
    w3d_auto_802cbf2c(&text, target->game_data_id, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd47c, 9);
    w3d_auto_802cbf2c(&text, target->item_highlight_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd49c, 9);
    w3d_auto_802cbf2c(&text, target->item_selected_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd4bc, 9);
    D26fText_803426b8 colour;
    D26fTextStream stream(colour);
    Ptr32<D26fProperty> property = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 24);
    property->vt->read(property, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd4dc, 9);
    w3d_auto_802cbf2c(&text, target->scrollbar_always_visible == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd4fc, 9);
    w3d_auto_802cbf2c(&text, target->scrollbar_tab_expanding == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_auto_802cbf2c(&text, lbl_803cd51c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd544, 9);
    switch (target->item_background_type) {
    case 0:
        w3d_auto_802cbf2c(&text, lbl_803cd564, 9);
        break;
    case 1:
        w3d_auto_802cbf2c(&text, lbl_803cd56c, 9);
        break;
    case 2:
        w3d_auto_802cbf2c(&text, lbl_803cd574, 9);
        break;
    case 3:
        w3d_auto_802cbf2c(&text, lbl_803cd588, 9);
        break;
    }
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd590, 9);
    w3d_auto_802cbfa4(&text, target->item_height, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd5b0, 9);
    w3d_auto_802cbfa4(&text, target->border_size, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cd5d0, 9);
    w3d_auto_802cbf2c(&text, target->auto_scroll == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_s21_append_position_802cd26c(&text, 0, 24);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc8b4, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)w3d::H(self->sink), text.c_str(), 9);
}


