#include "w3d_ptr.h"
#line 1 "d26f_percentage_button_edit_page_80272968.cpp"
// GWMP8P rev0 0x80272968. Debug editor page: prints title and object fields,
// including colour through its property reader, to the text sink; final
// reads through an inline accessor.
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
struct D26fVec { float v[3]; };
struct D26fButton;
struct D26fButtonTable { Ptr32<void> s0[5]; Ptr32<Ptr32<void> (Ptr32<D26fButton>)> type_info; };
struct D26fButton {
    Ptr32<D26fButtonTable> vt;
    char pad4[120];
    Ptr32<const char> border_resource;
    Ptr32<const char> selected_message;
    Ptr32<const char> highlighted_message;
    Ptr32<const char> gfx_resource_name;
    char pad140[12];
    float border_size;
    Ptr32<const char> fontresource_name;
    Ptr32<const char> going_up_sound;
    Ptr32<const char> limit_resource_name;
    Ptr32<const char> data_resource_name;
    int gfx_expands;
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
extern char lbl_803cc0d8[], lbl_803cc864[], lbl_803cc86c[], lbl_803cc8b4[], lbl_803cc900[], lbl_803cc918[], lbl_803cc930[], lbl_803cc950[], lbl_803cc970[], lbl_803cc990[], lbl_803cc9b0[], lbl_803cc9d0[], lbl_803cc9f0[], lbl_803cca10[], lbl_803cca30[], lbl_803cca50[], lbl_803cca70[];
extern "C" void d26f_percentage_button_edit_page_80272968(Ptr32<D26fEditor> self) {
    w3d_cx7b_script_flag_set_8027a934(self, 1);
    D26fText_803426b8 text;
    w3d_s21_repeat_request_802cd220(&text);
    w3d_auto_802cd128(&text);
    self->mode = 4;
    w3d_auto_802cbf2c(&text, lbl_803cc900, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc918, 7);
    w3d_auto_802cbf2c(&text, lbl_803cc0d8, 9);
    Ptr32<D26fButton> target = self->target;
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc930, 9);
    w3d_auto_802cbf2c(&text, target->gfx_resource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc950, 9);
    w3d_auto_802cbf2c(&text, target->limit_resource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc970, 9);
    w3d_auto_802cbf2c(&text, target->data_resource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc990, 9);
    w3d_auto_802cbf2c(&text, target->fontresource_name, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc9b0, 9);
    w3d_auto_802cbf2c(&text, target->highlighted_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc9d0, 9);
    w3d_auto_802cbf2c(&text, target->selected_message, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc9f0, 9);
    w3d_auto_802cbf2c(&text, target->border_resource, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cca10, 9);
    D26fText_803426b8 colour;
    D26fTextStream stream(colour);
    Ptr32<D26fProperty> property = w3d_s21_vector_get_801e9db8(target->vt->type_info(target), 24);
    property->vt->read(property, &stream.descriptor, target);
    w3d_auto_802cbf2c(&text, colour.c_str(), 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cca30, 9);
    w3d_auto_802cbf2c(&text, target->gfx_expands == 1 ? lbl_803cc864 : lbl_803cc86c, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cca50, 9);
    w3d_auto_802cbf2c(&text, target->going_up_sound, 9);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cca70, 9);
    w3d_auto_802cbfa4(&text, target->border_size, 9);
    w3d_s21_append_position_802cd26c(&text, 0, 24);
    w3d_cc32b_append_lines_v2_802cc0ac(&text, lbl_803cc8b4, 7);
    w3d_s21_sink_write_indexed_802cbdf8((int)w3d::H(self->sink), text.c_str(), 9);
}


